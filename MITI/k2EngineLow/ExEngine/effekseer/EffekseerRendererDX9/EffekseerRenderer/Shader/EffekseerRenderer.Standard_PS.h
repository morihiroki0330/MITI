#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_2_0 /EPS /Fh Shader/EffekseerRenderer.Standard_PS.h
//    Shader/standard_renderer_PS.fx
//
//
// Parameters:
//
//   sampler2D g_sampler;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   g_sampler    s0       1
//

    ps_2_0
    def c0, -1, -0, 0, 0
    dcl t0
    dcl t1.xy
    dcl_2d s0
    texld r0, t1, s0
    mul r0, r0, t0
    cmp r1, -r0.w, c0.x, c0.y
    texkill r1
    mov oC0, r0

// approximately 5 instruction slots used (1 texture, 4 arithmetic)
#endif

const BYTE g_ps20_PS[] =
{
      0,   2, 255, 255, 254, 255, 
     34,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  83,   0, 
      0,   0,   0,   2, 255, 255, 
      1,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
     76,   0,   0,   0,  48,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   2,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 115,  97, 109, 112, 
    108, 101, 114,   0, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 112, 115, 
     95,  50,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
     81,   0,   0,   5,   0,   0, 
     15, 160,   0,   0, 128, 191, 
      0,   0,   0, 128,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   1,   0, 228, 176, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 176,  88,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
    255, 129,   0,   0,   0, 160, 
      0,   0,  85, 160,  65,   0, 
      0,   1,   1,   0,  15, 128, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0
};
