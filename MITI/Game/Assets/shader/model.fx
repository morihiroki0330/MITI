/*!
 * @brief	シンプルなモデルシェーダー。
 */


////////////////////////////////////////////////
// 定数バッファ。
////////////////////////////////////////////////
//モデル用の定数バッファ
cbuffer ModelCb : register(b0)
{
	float4x4 mWorld;
	float4x4 mView;
	float4x4 mProj;
	
};

cbuffer DirectionLightCb : register(b1)
{
	//ディレクションライト
	float3 DirectionLight;
	float3 DirectionLight_C;

	//ポイントライト
	float3 Point_P;
	float3 Point_C;
	float  Point_R;

	//スポットライト
	float3 Spot_P;
	float3 Spot_C;
	float Spot_R;
	float3 Spot_D;
	float Spot_A;

	//半球ライト
	float3 Ground_C;
	float3 Sky_C;
	float3 Ground_N;

	//共通
	float3 eye_P;
	float3 ambientlight;
}

//関数
float3 CalcLambertDiffuse(float3 DirectionLight, float3 DirectionLight_C, float3 normal);
float3 CalcPhongSpecular(float3 DirectionLight, float3 DirectionLight_C, float3 worldPos, float3 normal);
////////////////////////////////////////////////
// 構造体
////////////////////////////////////////////////
//スキニング用の頂点データをひとまとめ。
struct SSkinVSIn{
	int4  Indices  	: BLENDINDICES0;
    float4 Weights  : BLENDWEIGHT0;
};
//頂点シェーダーへの入力。
struct SVSIn{
	float4 pos 		: POSITION;		//モデルの頂点座標。
	float3 normal   :NORMAL;
	float2 uv 		: TEXCOORD0;	//UV座標。
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
	SSkinVSIn skinVert;				//スキン用のデータ。
};
//ピクセルシェーダーへの入力。
struct SPSIn{
	float4 pos 			: SV_POSITION;	//スクリーン空間でのピクセルの座標。
	float3 normal       :NORMAL;
	float2 uv 			: TEXCOORD0;	//uv座標。
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
};

////////////////////////////////////////////////
// グローバル変数。
////////////////////////////////////////////////
Texture2D<float4> g_albedo : register(t0);				//アルベドマップ
Texture2D<float4> g_normalMap : register(t1);				//法線マップ
Texture2D<float4> g_specularMap : register(t2);             //スペキュラマップ
StructuredBuffer<float4x4> g_boneMatrix : register(t3);	//ボーン行列。
sampler g_sampler : register(s0);	//サンプラステート。

////////////////////////////////////////////////
// 関数定義。
////////////////////////////////////////////////

/// <summary>
//スキン行列を計算する。
/// </summary>
float4x4 CalcSkinMatrix(SSkinVSIn skinVert)
{
	float4x4 skinning = 0;	
	float w = 0.0f;
	[unroll]
    for (int i = 0; i < 3; i++)
    {
        skinning += g_boneMatrix[skinVert.Indices[i]] * skinVert.Weights[i];
        w += skinVert.Weights[i];
    }
    
    skinning += g_boneMatrix[skinVert.Indices[3]] * (1.0f - w);
	
    return skinning;
}

/// <summary>
/// 頂点シェーダーのコア関数。
/// </summary>
SPSIn VSMainCore(SVSIn vsIn, uniform bool hasSkin)
{
	SPSIn psIn;
	float4x4 m;
	if( hasSkin ){
		m = CalcSkinMatrix(vsIn.skinVert);
	}else{
		m = mWorld;
	}

	psIn.pos = mul(m, vsIn.pos);
	psIn.worldPos = vsIn.pos;
	psIn.pos = mul(mView, psIn.pos);
	psIn.pos = mul(mProj, psIn.pos);
	psIn.normal = mul(mWorld, vsIn.normal);
	psIn.uv = vsIn.uv;
	psIn.normalInView = mul(mView, psIn.normal);
	psIn.tangent = normalize(mul(mWorld, vsIn.tangent));
	psIn.biNormal = normalize(mul(mWorld, vsIn.biNormal));

	return psIn;
}

/// <summary>
/// スキンなしメッシュ用の頂点シェーダーのエントリー関数。
/// </summary>
SPSIn VSMain(SVSIn vsIn)
{
	return VSMainCore(vsIn, false);
}
/// <summary>
/// スキンありメッシュの頂点シェーダーのエントリー関数。
/// </summary>
SPSIn VSSkinMain( SVSIn vsIn ) 
{
	return VSMainCore(vsIn, true);
}
/// <summary>
/// ピクセルシェーダーのエントリー関数。
/// </summary>
float4 PSMain(SPSIn psIn) : SV_Target0
{
	float3 Normal = psIn.normal;

//法線マップ

	//法線のサンププリング
	float3 Local_N = g_normalMap.Sample(g_sampler, psIn.uv).xyz;

	//法線の範囲を復元
	Local_N = (Local_N - 0.5f) * 2.0f;

	//ワールドスペースの変換
	Normal = psIn.tangent * Local_N.x + psIn.biNormal * Local_N.y * Normal * Local_N.z;

//スペキュラマップ
	float Spec_P = g_specularMap.Sample(g_sampler, psIn.uv).r;

////////ライト////////
//拡散反射光

	float t = dot(psIn.normal,DirectionLight);

	t *= -1.0f;

	if (t < 0.0f)
	{
		t = 0.0f;
	}

	float3 Diffuse_L = max(0.0f, dot(Normal, -DirectionLight)) * DirectionLight_C * t;

//鏡面反射光

	float3 refVec = reflect(DirectionLight,psIn.normal);

	float3 toEye = eye_P - psIn.worldPos;

	toEye = normalize(toEye);

	t = dot(refVec, toEye);

	if (t < 0.0f)
	{
		t = 0.0f;
	}

	t = pow(t, 10.0f);

	float3 Specular_L = DirectionLight_C * t * (Spec_P * 5.0f);

//拡散反射光+鏡面反射光
	float3 DirectionLight = Diffuse_L + Specular_L;

//ポイントライト

	//光の向きを計算
	float3 Light_D = psIn.worldPos - Point_P;

	//正規化
	Light_D = normalize(Light_D);

	//減衰なしの拡散反射
	float3 DiffPoint = CalcLambertDiffuse(Light_D, Point_C, psIn.normal);

	//減衰なしの鏡面反射
	float3 SpecPoint = CalcPhongSpecular(Light_D, Point_C, psIn.worldPos, psIn.normal);

	//ポイントライトとの距離
	float Distance_Point = length(psIn.worldPos - Point_P);

	//影響率の計算
	float Affect_Point = 1.0f - 1.0f / Point_R * Distance_Point;

	//影響率の補正
	if (Affect_Point < 0.0f)
	{
		Affect_Point = 0.0f;
	}

	//指定関数への変更
	Affect_Point = pow(Affect_Point, 3.0f);

	//拡散反射光と鏡面反射光に影響率を乗算して影響を弱める
	DiffPoint *= Affect_Point;
	SpecPoint *= Affect_Point;

	//ポイントライト
	float3 PointLight = DiffPoint + SpecPoint;

//スポットライト

	//減衰なしの拡散反射
	float3 DiffSpotPoint = CalcLambertDiffuse(Light_D, Spot_C, psIn.normal);

	//減衰なしの鏡面反射
	float3 SpecSpotPoint = CalcPhongSpecular(Light_D, Spot_C, psIn.worldPos, psIn.normal);

	//スポットライトの距離
	float Distance_Spot = length(psIn.worldPos - Spot_P);

	//影響率の計算-1
	float Affect_Spot = 1.0f - 1.0f / Spot_R * Distance_Spot;

	//影響率の補正-1
	if (Affect_Spot < 0.0f)
	{
		Affect_Spot = 0.0f;
	}

	//指定関数への変更-1
	Affect_Spot = pow(Affect_Spot, 3.0f);

	//拡散反射光と鏡面反射光に影響率を乗算して影響を弱める
	DiffSpotPoint *= Affect_Spot;
	SpecSpotPoint *= Affect_Spot;

	//内積
	float Angle_Spot = dot(Light_D, Spot_D);

	//角度
	Angle_Spot = abs(acos(Angle_Spot));

	//影響率の計算-2
	Affect_Spot = 1.0f - 1.0f / Spot_A * Angle_Spot;

	//影響率の補正2
	if (Affect_Spot < 0.0f)
	{
		Affect_Spot = 0.0f;
	}

	//指定関数への変更2
	Affect_Spot = pow(Affect_Spot, 0.5f);

	DiffSpotPoint *= Affect_Spot;
	SpecSpotPoint *= Affect_Spot;

	//スポットライト
	float3 SpotLight = DiffSpotPoint + SpecSpotPoint;

//リムライト
	
	//法線と光の入射方向へのリムの強さ
	float Lim_Power1 = 1.0f - max(0.0f, dot(DirectionLight, psIn.normal));

	//法線と視線へのリムの強さ
	float Lim_Power2 = 1.0f - max(0.0f, psIn.normalInView.z * -1.0f);

	//リムの強さ
	float Lim_Power = Lim_Power1 * Lim_Power2;

	//指定関数へのシステム
	Lim_Power = pow(Lim_Power, 1.3f);

	//リムライトの反射光
	float3 LimLight = Lim_Power * DirectionLight_C;

//半球ライト

	//サーフェースの法線と地面の法線との内積
	float HalfLight_T = dot(psIn.normal, Ground_N);

	//0～1の変換
	HalfLight_T = (HalfLight_T + 1.0f) / 2.0f;

	//地面カラーとライトカラーを内積で補間
	float3 HalfLight = lerp(Ground_C, Sky_C, HalfLight_T);

//ポイントライト+スポットライト+リムライト+半球ライト

//最終的な光

	//float3 FinalLight = DirectionLight + PointLight + SpotLight+ LimLight;

	float3 FinalLight = DirectionLight + PointLight + SpotLight+ LimLight + HalfLight;

	float4 Albedo_C = g_albedo.Sample(g_sampler, psIn.uv);



	Albedo_C.xyz *= FinalLight;

	return Albedo_C;
}

//減衰なしの拡散反射を求める関数
float3 CalcLambertDiffuse(float3 DirectionLight, float3 DirectionLight_C, float3 normal)
{
	float t = dot(normal, DirectionLight) * -1.0f;

	t = max(0.0f, t);

	return DirectionLight_C * t;
}

//減衰なしの鏡面反射を求める関数
float3 CalcPhongSpecular(float3 DirectionLight, float3 DirectionLight_C, float3 worldPos, float3 normal)
{
	float3 refVec = reflect(DirectionLight, normal);

	float3 toEye = eye_P - worldPos;
	toEye = normalize(toEye);

	float t = dot(refVec, toEye);

	t = max(0.0f, t);

	t = pow(t, 5.0f);

	return DirectionLight_C * t;
}
