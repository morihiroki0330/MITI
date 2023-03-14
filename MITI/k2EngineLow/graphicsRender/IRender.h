#pragma once
namespace nsK2EngineLow {
	/// �����_�[���[�̊��N���X�B
	class IRender : public Noncopyable {
	public:
		/// �V���h�E�}�b�v�ւ̕`��p�X����Ă΂�鏈���B
		virtual void OnRenderShadowMap(
			RenderContext& rc,
			int ligNo,
			int shadowMapNo,
			const Matrix& lvpMatrix
		)
		{

		}

		/// ���_�v�Z�p�X����Ă΂�鏈���B
		virtual void OnComputeVertex(RenderContext& rc)
		{

		}

		/// ZPrepass����Ă΂�鏈���B
		virtual void OnZPrepass(RenderContext& rc)
		{

		}

		/// G-Buffer�`��p�X����Ă΂�鏈���B
		virtual void OnRenderToGBuffer(RenderContext& rc)
		{

		}

		/// �t�H���[�h�����_�[�p�X����Ă΂�鏈���B
		virtual void OnForwardRender(RenderContext& rc)
		{

		}

		/// �������I�u�W�F�N�g�`��p�X����Ă΂�鏈���B
		virtual void OnTlanslucentRender(RenderContext& rc)
		{

		}

		/// 2D�`��p�X����Ă΂�鏈���B
		virtual void OnRender2D(RenderContext& rc)
		{

		}

		//�ʏ�`��p�X����Ăяo����鏈��
		virtual void OnRender(RenderContext& rc)
		{

		}

		/// �����_���[���`�悷��I�u�W�F�N�g�̍ő���W�ƍŏ����W���擾�B
		virtual void GetAABB(Vector3& vMax, Vector3& vMin, bool& isGet)
		{
			vMax.Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
			vMin.Set(FLT_MAX, FLT_MAX, FLT_MAX);
			isGet = false;
		}



		/// �V���h�E�L���X�^�[�H
		virtual bool IsShadowCaster() const
		{
			return false;
		}
	};
}

