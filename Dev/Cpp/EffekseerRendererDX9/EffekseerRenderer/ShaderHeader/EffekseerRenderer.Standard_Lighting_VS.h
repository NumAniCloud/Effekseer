#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tvs_3_0 /Emain /Fh
//    ShaderHeader/EffekseerRenderer.Standard_Lighting_VS.h
//    Shader/standard_renderer_lighting_VS.fx
//
//
// Parameters:
//
//   float4x4 _255_mCamera;
//   float4x4 _255_mProj;
//   float4 _255_mUVInversed;
//   float4 _255_mflipbookParameter;
//
//
// Registers:
//
//   Name                    Reg   Size
//   ----------------------- ----- ----
//   _255_mCamera            c0       4
//   _255_mProj              c4       4
//   _255_mUVInversed        c8       1
//   _255_mflipbookParameter c9       1
//

    vs_3_0
    def c10, -0.5, 0, 1, -1
    def c11, -2, 2, 0, 0
    dcl_texcoord v0
    dcl_texcoord1 v1
    dcl_texcoord2 v2
    dcl_texcoord3 v3
    dcl_texcoord4 v4
    dcl_texcoord6 v5
    dcl_texcoord7 v6
    dcl_texcoord8 v7
    dcl_texcoord9 v8
    dcl_texcoord10 v9
    dcl_texcoord o0
    dcl_texcoord1 o1.xy
    dcl_texcoord2 o2.xyz
    dcl_texcoord3 o3.xyz
    dcl_texcoord4 o4.xyz
    dcl_texcoord5 o5
    dcl_texcoord6 o6
    dcl_texcoord7 o7
    dcl_texcoord8 o8.xy
    dcl_position o9
    add r0.xyz, c10.x, v2
    add r0.xyz, r0, r0
    add r1.xyz, c10.x, v3
    add r1.xyz, r1, r1
    mul r2.xyz, r0.zxyw, r1.yzxw
    mad o4.xyz, r0.yzxw, r1.zxyw, -r2
    mad r2.x, c8.y, v4.y, c8.x
    mul r3, c1, v0.y
    mad r3, c0, v0.x, r3
    mad r3, c2, v0.z, r3
    add r3, r3, c3
    rcp r0.w, r3.w
    mul r3.xyz, r0.w, r3
    mul r4, r3.y, c5
    mad r4, c4, r3.x, r4
    mad r3, c6, r3.z, r4
    add o9, r3, c7
    mad o5.yw, c8.y, v5, c8.x
    mad r3.x, c8.y, v6.y, c8.x
    mad o6.yw, c8.y, v7, c8.x
    mov r4.yw, c10
    if_lt r4.y, c9.x
      frc r4.x, v8.x
      add r5.x, -r4.x, v8.x
      add r0.w, r5.x, c10.z
      mul r1.w, c9.w, c9.z
      abs r2.w, c9.y
      if_ge -r2.w, r2.w
        sge r2.w, r0.w, r1.w
        mad r4.z, c9.z, c9.w, r4.w
        add r5.y, r5.x, c10.z
        lrp r6.xy, r2.w, r4.z, r5
      else
        add r2.w, r4.w, c9.y
        if_ge -r2_abs.w, r2_abs.w
          rcp r2.w, r1.w
          mul r4.z, r2.w, r5.x
          frc r5.y, r4.z
          add r4.z, r4.z, -r5.y
          mad r6.x, r1.w, -r4.z, r5.x
          mul r2.w, r0.w, r2.w
          frc r4.z, r2.w
          add r2.w, r2.w, -r4.z
          mad r6.y, r1.w, -r2.w, r0.w
        else
          mov r5.y, c9.y
          add r2.w, r5.y, c11.x
          sge r2.w, -r2_abs.w, r2_abs.w
          rcp r4.z, r1.w
          mul r5.y, r4.z, r5.x
          frc r5.w, r5.y
          add r5.y, -r5.w, r5.y
          mul r5.w, r5.y, -c10.x
          frc r6.z, r5.w
          add r5.w, r5.w, -r6.z
          mad r5.w, r5.w, -c11.y, r5.y
          add r5.w, r5.w, c10.w
          sge r5.w, -r5_abs.w, r5_abs.w
          mul r6.z, r1.w, r5.y
          mad r5.y, r1.w, -r5.y, r5.x
          mad r4.w, c9.z, c9.w, r4.w
          frc r6.z, -r6.z
          add r6.z, r5.y, -r6.z
          add r6.z, r4.w, -r6.z
          lrp r7.x, r5.w, r6.z, r5.y
          mul r4.z, r0.w, r4.z
          frc r5.y, r4.z
          add r4.z, r4.z, -r5.y
          mul r5.y, r4.z, -c10.x
          frc r5.w, r5.y
          add r5.y, -r5.w, r5.y
          mad r5.y, r5.y, -c11.y, r4.z
          add r5.y, r5.y, c10.w
          sge r5.y, -r5_abs.y, r5_abs.y
          mul r5.w, r1.w, r4.z
          mad r0.w, r1.w, -r4.z, r0.w
          frc r1.w, -r5.w
          add r1.w, r0.w, -r1.w
          add r1.w, -r1.w, r4.w
          lrp r7.y, r5.y, r1.w, r0.w
          add r5.z, r5.x, c10.z
          lrp r6.xy, r2.w, r7, r5.xzzw
        endif
      endif
      frc r0.w, r6.x
      add r1.w, r6.x, -r0.w
      slt r2.w, r6.x, -r6.x
      slt r0.w, -r0.w, r0.w
      mad r0.w, r2.w, r0.w, r1.w
      frc r1.w, c9.z
      add r2.w, -r1.w, c9.z
      slt r4.z, c9.z, -c9.z
      slt r1.w, -r1.w, r1.w
      mad r1.w, r4.z, r1.w, r2.w
      mul r2.w, r0.w, r1.w
      sge r2.w, r2.w, -r2.w
      lrp r4.z, r2.w, r1.w, -r1.w
      rcp r2.w, r4.z
      mul r2.w, r0.w, r2.w
      frc r2.w, r2.w
      mul r2.w, r2.w, r4.z
      frc r4.z, r2.w
      add r4.w, r2.w, -r4.z
      slt r2.w, r2.w, -r2.w
      slt r4.z, -r4.z, r4.z
      mad r5.x, r2.w, r4.z, r4.w
      rcp r2.w, r1.w
      mul r0.w, r0.w, r2.w
      frc r4.z, r0.w
      add r4.w, r0.w, -r4.z
      slt r0.w, r0.w, -r0.w
      slt r4.z, -r4.z, r4.z
      mad r5.y, r0.w, r4.z, r4.w
      rcp r7.x, c9.z
      rcp r7.y, c9.w
      mov r2.y, v4.x
      mad r4.zw, r5.xyxy, -r7.xyxy, r2.xyyx
      mul r4.zw, r4, c9
      frc r0.w, r6.y
      add r2.y, r6.y, -r0.w
      slt r5.x, r6.y, -r6.y
      slt r0.w, -r0.w, r0.w
      mad r0.w, r5.x, r0.w, r2.y
      mul r2.y, r1.w, r0.w
      sge r2.y, r2.y, -r2.y
      lrp r5.x, r2.y, r1.w, -r1.w
      rcp r1.w, r5.x
      mul r1.w, r0.w, r1.w
      frc r1.w, r1.w
      mul r1.w, r1.w, r5.x
      frc r2.y, r1.w
      add r5.x, r1.w, -r2.y
      slt r1.w, r1.w, -r1.w
      slt r2.y, -r2.y, r2.y
      mad r5.x, r1.w, r2.y, r5.x
      mul r0.w, r2.w, r0.w
      frc r1.w, r0.w
      add r2.y, r0.w, -r1.w
      slt r0.w, r0.w, -r0.w
      slt r1.w, -r1.w, r1.w
      mad r5.y, r0.w, r1.w, r2.y
      mul r2.yw, r7.xxzy, r5.xxzy
      mad r3.yz, r4.xzww, r7.xxyw, r2.xyww
    else
      mov r3.yz, c10.y
      mov r4.x, c10.y
    endif
    mov o0, v1
    mov r2.z, v4.x
    mov o1.xy, r2.zxzw
    mov o2.xyz, r0
    mov o3.xyz, r1
    mov o5.xz, v5
    mov o6.xz, v7
    mov r3.w, v6.x
    mov o7, r3.wxyz
    mov r4.y, v9.x
    mov o8.xy, r4

// approximately 164 instruction slots used
#endif

const BYTE g_vs30_main[] =
{
      0,   3, 254, 255, 254, 255, 
     67,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 215,   0, 
      0,   0,   0,   3, 254, 255, 
      4,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
    208,   0,   0,   0, 108,   0, 
      0,   0,   2,   0,   0,   0, 
      4,   0,   2,   0, 124,   0, 
      0,   0,   0,   0,   0,   0, 
    140,   0,   0,   0,   2,   0, 
      4,   0,   4,   0,  18,   0, 
    124,   0,   0,   0,   0,   0, 
      0,   0, 151,   0,   0,   0, 
      2,   0,   8,   0,   1,   0, 
     34,   0, 168,   0,   0,   0, 
      0,   0,   0,   0, 184,   0, 
      0,   0,   2,   0,   9,   0, 
      1,   0,  38,   0, 168,   0, 
      0,   0,   0,   0,   0,   0, 
     95,  50,  53,  53,  95, 109, 
     67,  97, 109, 101, 114,  97, 
      0, 171, 171, 171,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  95,  50,  53,  53, 
     95, 109,  80, 114, 111, 106, 
      0,  95,  50,  53,  53,  95, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  95,  50, 
     53,  53,  95, 109, 102, 108, 
    105, 112,  98, 111, 111, 107, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 118, 115, 
     95,  51,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
     81,   0,   0,   5,  10,   0, 
     15, 160,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0, 128, 191, 
     81,   0,   0,   5,  11,   0, 
     15, 160,   0,   0,   0, 192, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      1, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      2, 128,   2,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      3, 128,   3,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      4, 128,   4,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      6, 128,   5,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      7, 128,   6,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      8, 128,   7,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      9, 128,   8,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
     10, 128,   9,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 224, 
     31,   0,   0,   2,   5,   0, 
      1, 128,   1,   0,   3, 224, 
     31,   0,   0,   2,   5,   0, 
      2, 128,   2,   0,   7, 224, 
     31,   0,   0,   2,   5,   0, 
      3, 128,   3,   0,   7, 224, 
     31,   0,   0,   2,   5,   0, 
      4, 128,   4,   0,   7, 224, 
     31,   0,   0,   2,   5,   0, 
      5, 128,   5,   0,  15, 224, 
     31,   0,   0,   2,   5,   0, 
      6, 128,   6,   0,  15, 224, 
     31,   0,   0,   2,   5,   0, 
      7, 128,   7,   0,  15, 224, 
     31,   0,   0,   2,   5,   0, 
      8, 128,   8,   0,   3, 224, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   9,   0,  15, 224, 
      2,   0,   0,   3,   0,   0, 
      7, 128,  10,   0,   0, 160, 
      2,   0, 228, 144,   2,   0, 
      0,   3,   0,   0,   7, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,   7, 128,  10,   0, 
      0, 160,   3,   0, 228, 144, 
      2,   0,   0,   3,   1,   0, 
      7, 128,   1,   0, 228, 128, 
      1,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,   7, 128, 
      0,   0, 210, 128,   1,   0, 
    201, 128,   4,   0,   0,   4, 
      4,   0,   7, 224,   0,   0, 
    201, 128,   1,   0, 210, 128, 
      2,   0, 228, 129,   4,   0, 
      0,   4,   2,   0,   1, 128, 
      8,   0,  85, 160,   4,   0, 
     85, 144,   8,   0,   0, 160, 
      5,   0,   0,   3,   3,   0, 
     15, 128,   1,   0, 228, 160, 
      0,   0,  85, 144,   4,   0, 
      0,   4,   3,   0,  15, 128, 
      0,   0, 228, 160,   0,   0, 
      0, 144,   3,   0, 228, 128, 
      4,   0,   0,   4,   3,   0, 
     15, 128,   2,   0, 228, 160, 
      0,   0, 170, 144,   3,   0, 
    228, 128,   2,   0,   0,   3, 
      3,   0,  15, 128,   3,   0, 
    228, 128,   3,   0, 228, 160, 
      6,   0,   0,   2,   0,   0, 
      8, 128,   3,   0, 255, 128, 
      5,   0,   0,   3,   3,   0, 
      7, 128,   0,   0, 255, 128, 
      3,   0, 228, 128,   5,   0, 
      0,   3,   4,   0,  15, 128, 
      3,   0,  85, 128,   5,   0, 
    228, 160,   4,   0,   0,   4, 
      4,   0,  15, 128,   4,   0, 
    228, 160,   3,   0,   0, 128, 
      4,   0, 228, 128,   4,   0, 
      0,   4,   3,   0,  15, 128, 
      6,   0, 228, 160,   3,   0, 
    170, 128,   4,   0, 228, 128, 
      2,   0,   0,   3,   9,   0, 
     15, 224,   3,   0, 228, 128, 
      7,   0, 228, 160,   4,   0, 
      0,   4,   5,   0,  10, 224, 
      8,   0,  85, 160,   5,   0, 
    228, 144,   8,   0,   0, 160, 
      4,   0,   0,   4,   3,   0, 
      1, 128,   8,   0,  85, 160, 
      6,   0,  85, 144,   8,   0, 
      0, 160,   4,   0,   0,   4, 
      6,   0,  10, 224,   8,   0, 
     85, 160,   7,   0, 228, 144, 
      8,   0,   0, 160,   1,   0, 
      0,   2,   4,   0,  10, 128, 
     10,   0, 228, 160,  41,   0, 
      4,   2,   4,   0,  85, 128, 
      9,   0,   0, 160,  19,   0, 
      0,   2,   4,   0,   1, 128, 
      8,   0,   0, 144,   2,   0, 
      0,   3,   5,   0,   1, 128, 
      4,   0,   0, 129,   8,   0, 
      0, 144,   2,   0,   0,   3, 
      0,   0,   8, 128,   5,   0, 
      0, 128,  10,   0, 170, 160, 
      5,   0,   0,   3,   1,   0, 
      8, 128,   9,   0, 255, 160, 
      9,   0, 170, 160,  35,   0, 
      0,   2,   2,   0,   8, 128, 
      9,   0,  85, 160,  41,   0, 
      3,   2,   2,   0, 255, 129, 
      2,   0, 255, 128,  13,   0, 
      0,   3,   2,   0,   8, 128, 
      0,   0, 255, 128,   1,   0, 
    255, 128,   4,   0,   0,   4, 
      4,   0,   4, 128,   9,   0, 
    170, 160,   9,   0, 255, 160, 
      4,   0, 255, 128,   2,   0, 
      0,   3,   5,   0,   2, 128, 
      5,   0,   0, 128,  10,   0, 
    170, 160,  18,   0,   0,   4, 
      6,   0,   3, 128,   2,   0, 
    255, 128,   4,   0, 170, 128, 
      5,   0, 228, 128,  42,   0, 
      0,   0,   2,   0,   0,   3, 
      2,   0,   8, 128,   4,   0, 
    255, 128,   9,   0,  85, 160, 
     41,   0,   3,   2,   2,   0, 
    255, 140,   2,   0, 255, 139, 
      6,   0,   0,   2,   2,   0, 
      8, 128,   1,   0, 255, 128, 
      5,   0,   0,   3,   4,   0, 
      4, 128,   2,   0, 255, 128, 
      5,   0,   0, 128,  19,   0, 
      0,   2,   5,   0,   2, 128, 
      4,   0, 170, 128,   2,   0, 
      0,   3,   4,   0,   4, 128, 
      4,   0, 170, 128,   5,   0, 
     85, 129,   4,   0,   0,   4, 
      6,   0,   1, 128,   1,   0, 
    255, 128,   4,   0, 170, 129, 
      5,   0,   0, 128,   5,   0, 
      0,   3,   2,   0,   8, 128, 
      0,   0, 255, 128,   2,   0, 
    255, 128,  19,   0,   0,   2, 
      4,   0,   4, 128,   2,   0, 
    255, 128,   2,   0,   0,   3, 
      2,   0,   8, 128,   2,   0, 
    255, 128,   4,   0, 170, 129, 
      4,   0,   0,   4,   6,   0, 
      2, 128,   1,   0, 255, 128, 
      2,   0, 255, 129,   0,   0, 
    255, 128,  42,   0,   0,   0, 
      1,   0,   0,   2,   5,   0, 
      2, 128,   9,   0,  85, 160, 
      2,   0,   0,   3,   2,   0, 
      8, 128,   5,   0,  85, 128, 
     11,   0,   0, 160,  13,   0, 
      0,   3,   2,   0,   8, 128, 
      2,   0, 255, 140,   2,   0, 
    255, 139,   6,   0,   0,   2, 
      4,   0,   4, 128,   1,   0, 
    255, 128,   5,   0,   0,   3, 
      5,   0,   2, 128,   4,   0, 
    170, 128,   5,   0,   0, 128, 
     19,   0,   0,   2,   5,   0, 
      8, 128,   5,   0,  85, 128, 
      2,   0,   0,   3,   5,   0, 
      2, 128,   5,   0, 255, 129, 
      5,   0,  85, 128,   5,   0, 
      0,   3,   5,   0,   8, 128, 
      5,   0,  85, 128,  10,   0, 
      0, 161,  19,   0,   0,   2, 
      6,   0,   4, 128,   5,   0, 
    255, 128,   2,   0,   0,   3, 
      5,   0,   8, 128,   5,   0, 
    255, 128,   6,   0, 170, 129, 
      4,   0,   0,   4,   5,   0, 
      8, 128,   5,   0, 255, 128, 
     11,   0,  85, 161,   5,   0, 
     85, 128,   2,   0,   0,   3, 
      5,   0,   8, 128,   5,   0, 
    255, 128,  10,   0, 255, 160, 
     13,   0,   0,   3,   5,   0, 
      8, 128,   5,   0, 255, 140, 
      5,   0, 255, 139,   5,   0, 
      0,   3,   6,   0,   4, 128, 
      1,   0, 255, 128,   5,   0, 
     85, 128,   4,   0,   0,   4, 
      5,   0,   2, 128,   1,   0, 
    255, 128,   5,   0,  85, 129, 
      5,   0,   0, 128,   4,   0, 
      0,   4,   4,   0,   8, 128, 
      9,   0, 170, 160,   9,   0, 
    255, 160,   4,   0, 255, 128, 
     19,   0,   0,   2,   6,   0, 
      4, 128,   6,   0, 170, 129, 
      2,   0,   0,   3,   6,   0, 
      4, 128,   5,   0,  85, 128, 
      6,   0, 170, 129,   2,   0, 
      0,   3,   6,   0,   4, 128, 
      4,   0, 255, 128,   6,   0, 
    170, 129,  18,   0,   0,   4, 
      7,   0,   1, 128,   5,   0, 
    255, 128,   6,   0, 170, 128, 
      5,   0,  85, 128,   5,   0, 
      0,   3,   4,   0,   4, 128, 
      0,   0, 255, 128,   4,   0, 
    170, 128,  19,   0,   0,   2, 
      5,   0,   2, 128,   4,   0, 
    170, 128,   2,   0,   0,   3, 
      4,   0,   4, 128,   4,   0, 
    170, 128,   5,   0,  85, 129, 
      5,   0,   0,   3,   5,   0, 
      2, 128,   4,   0, 170, 128, 
     10,   0,   0, 161,  19,   0, 
      0,   2,   5,   0,   8, 128, 
      5,   0,  85, 128,   2,   0, 
      0,   3,   5,   0,   2, 128, 
      5,   0, 255, 129,   5,   0, 
     85, 128,   4,   0,   0,   4, 
      5,   0,   2, 128,   5,   0, 
     85, 128,  11,   0,  85, 161, 
      4,   0, 170, 128,   2,   0, 
      0,   3,   5,   0,   2, 128, 
      5,   0,  85, 128,  10,   0, 
    255, 160,  13,   0,   0,   3, 
      5,   0,   2, 128,   5,   0, 
     85, 140,   5,   0,  85, 139, 
      5,   0,   0,   3,   5,   0, 
      8, 128,   1,   0, 255, 128, 
      4,   0, 170, 128,   4,   0, 
      0,   4,   0,   0,   8, 128, 
      1,   0, 255, 128,   4,   0, 
    170, 129,   0,   0, 255, 128, 
     19,   0,   0,   2,   1,   0, 
      8, 128,   5,   0, 255, 129, 
      2,   0,   0,   3,   1,   0, 
      8, 128,   0,   0, 255, 128, 
      1,   0, 255, 129,   2,   0, 
      0,   3,   1,   0,   8, 128, 
      1,   0, 255, 129,   4,   0, 
    255, 128,  18,   0,   0,   4, 
      7,   0,   2, 128,   5,   0, 
     85, 128,   1,   0, 255, 128, 
      0,   0, 255, 128,   2,   0, 
      0,   3,   5,   0,   4, 128, 
      5,   0,   0, 128,  10,   0, 
    170, 160,  18,   0,   0,   4, 
      6,   0,   3, 128,   2,   0, 
    255, 128,   7,   0, 228, 128, 
      5,   0, 232, 128,  43,   0, 
      0,   0,  43,   0,   0,   0, 
     19,   0,   0,   2,   0,   0, 
      8, 128,   6,   0,   0, 128, 
      2,   0,   0,   3,   1,   0, 
      8, 128,   6,   0,   0, 128, 
      0,   0, 255, 129,  12,   0, 
      0,   3,   2,   0,   8, 128, 
      6,   0,   0, 128,   6,   0, 
      0, 129,  12,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    255, 129,   0,   0, 255, 128, 
      4,   0,   0,   4,   0,   0, 
      8, 128,   2,   0, 255, 128, 
      0,   0, 255, 128,   1,   0, 
    255, 128,  19,   0,   0,   2, 
      1,   0,   8, 128,   9,   0, 
    170, 160,   2,   0,   0,   3, 
      2,   0,   8, 128,   1,   0, 
    255, 129,   9,   0, 170, 160, 
     12,   0,   0,   3,   4,   0, 
      4, 128,   9,   0, 170, 160, 
      9,   0, 170, 161,  12,   0, 
      0,   3,   1,   0,   8, 128, 
      1,   0, 255, 129,   1,   0, 
    255, 128,   4,   0,   0,   4, 
      1,   0,   8, 128,   4,   0, 
    170, 128,   1,   0, 255, 128, 
      2,   0, 255, 128,   5,   0, 
      0,   3,   2,   0,   8, 128, 
      0,   0, 255, 128,   1,   0, 
    255, 128,  13,   0,   0,   3, 
      2,   0,   8, 128,   2,   0, 
    255, 128,   2,   0, 255, 129, 
     18,   0,   0,   4,   4,   0, 
      4, 128,   2,   0, 255, 128, 
      1,   0, 255, 128,   1,   0, 
    255, 129,   6,   0,   0,   2, 
      2,   0,   8, 128,   4,   0, 
    170, 128,   5,   0,   0,   3, 
      2,   0,   8, 128,   0,   0, 
    255, 128,   2,   0, 255, 128, 
     19,   0,   0,   2,   2,   0, 
      8, 128,   2,   0, 255, 128, 
      5,   0,   0,   3,   2,   0, 
      8, 128,   2,   0, 255, 128, 
      4,   0, 170, 128,  19,   0, 
      0,   2,   4,   0,   4, 128, 
      2,   0, 255, 128,   2,   0, 
      0,   3,   4,   0,   8, 128, 
      2,   0, 255, 128,   4,   0, 
    170, 129,  12,   0,   0,   3, 
      2,   0,   8, 128,   2,   0, 
    255, 128,   2,   0, 255, 129, 
     12,   0,   0,   3,   4,   0, 
      4, 128,   4,   0, 170, 129, 
      4,   0, 170, 128,   4,   0, 
      0,   4,   5,   0,   1, 128, 
      2,   0, 255, 128,   4,   0, 
    170, 128,   4,   0, 255, 128, 
      6,   0,   0,   2,   2,   0, 
      8, 128,   1,   0, 255, 128, 
      5,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 255, 128, 
      2,   0, 255, 128,  19,   0, 
      0,   2,   4,   0,   4, 128, 
      0,   0, 255, 128,   2,   0, 
      0,   3,   4,   0,   8, 128, 
      0,   0, 255, 128,   4,   0, 
    170, 129,  12,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    255, 128,   0,   0, 255, 129, 
     12,   0,   0,   3,   4,   0, 
      4, 128,   4,   0, 170, 129, 
      4,   0, 170, 128,   4,   0, 
      0,   4,   5,   0,   2, 128, 
      0,   0, 255, 128,   4,   0, 
    170, 128,   4,   0, 255, 128, 
      6,   0,   0,   2,   7,   0, 
      1, 128,   9,   0, 170, 160, 
      6,   0,   0,   2,   7,   0, 
      2, 128,   9,   0, 255, 160, 
      1,   0,   0,   2,   2,   0, 
      2, 128,   4,   0,   0, 144, 
      4,   0,   0,   4,   4,   0, 
     12, 128,   5,   0,  68, 128, 
      7,   0,  68, 129,   2,   0, 
     20, 128,   5,   0,   0,   3, 
      4,   0,  12, 128,   4,   0, 
    228, 128,   9,   0, 228, 160, 
     19,   0,   0,   2,   0,   0, 
      8, 128,   6,   0,  85, 128, 
      2,   0,   0,   3,   2,   0, 
      2, 128,   6,   0,  85, 128, 
      0,   0, 255, 129,  12,   0, 
      0,   3,   5,   0,   1, 128, 
      6,   0,  85, 128,   6,   0, 
     85, 129,  12,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    255, 129,   0,   0, 255, 128, 
      4,   0,   0,   4,   0,   0, 
      8, 128,   5,   0,   0, 128, 
      0,   0, 255, 128,   2,   0, 
     85, 128,   5,   0,   0,   3, 
      2,   0,   2, 128,   1,   0, 
    255, 128,   0,   0, 255, 128, 
     13,   0,   0,   3,   2,   0, 
      2, 128,   2,   0,  85, 128, 
      2,   0,  85, 129,  18,   0, 
      0,   4,   5,   0,   1, 128, 
      2,   0,  85, 128,   1,   0, 
    255, 128,   1,   0, 255, 129, 
      6,   0,   0,   2,   1,   0, 
      8, 128,   5,   0,   0, 128, 
      5,   0,   0,   3,   1,   0, 
      8, 128,   0,   0, 255, 128, 
      1,   0, 255, 128,  19,   0, 
      0,   2,   1,   0,   8, 128, 
      1,   0, 255, 128,   5,   0, 
      0,   3,   1,   0,   8, 128, 
      1,   0, 255, 128,   5,   0, 
      0, 128,  19,   0,   0,   2, 
      2,   0,   2, 128,   1,   0, 
    255, 128,   2,   0,   0,   3, 
      5,   0,   1, 128,   1,   0, 
    255, 128,   2,   0,  85, 129, 
     12,   0,   0,   3,   1,   0, 
      8, 128,   1,   0, 255, 128, 
      1,   0, 255, 129,  12,   0, 
      0,   3,   2,   0,   2, 128, 
      2,   0,  85, 129,   2,   0, 
     85, 128,   4,   0,   0,   4, 
      5,   0,   1, 128,   1,   0, 
    255, 128,   2,   0,  85, 128, 
      5,   0,   0, 128,   5,   0, 
      0,   3,   0,   0,   8, 128, 
      2,   0, 255, 128,   0,   0, 
    255, 128,  19,   0,   0,   2, 
      1,   0,   8, 128,   0,   0, 
    255, 128,   2,   0,   0,   3, 
      2,   0,   2, 128,   0,   0, 
    255, 128,   1,   0, 255, 129, 
     12,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 255, 128, 
      0,   0, 255, 129,  12,   0, 
      0,   3,   1,   0,   8, 128, 
      1,   0, 255, 129,   1,   0, 
    255, 128,   4,   0,   0,   4, 
      5,   0,   2, 128,   0,   0, 
    255, 128,   1,   0, 255, 128, 
      2,   0,  85, 128,   5,   0, 
      0,   3,   2,   0,  10, 128, 
      7,   0,  96, 128,   5,   0, 
     96, 128,   4,   0,   0,   4, 
      3,   0,   6, 128,   4,   0, 
    248, 128,   7,   0, 208, 128, 
      2,   0, 244, 128,  42,   0, 
      0,   0,   1,   0,   0,   2, 
      3,   0,   6, 128,  10,   0, 
     85, 160,   1,   0,   0,   2, 
      4,   0,   1, 128,  10,   0, 
     85, 160,  43,   0,   0,   0, 
      1,   0,   0,   2,   0,   0, 
     15, 224,   1,   0, 228, 144, 
      1,   0,   0,   2,   2,   0, 
      4, 128,   4,   0,   0, 144, 
      1,   0,   0,   2,   1,   0, 
      3, 224,   2,   0, 226, 128, 
      1,   0,   0,   2,   2,   0, 
      7, 224,   0,   0, 228, 128, 
      1,   0,   0,   2,   3,   0, 
      7, 224,   1,   0, 228, 128, 
      1,   0,   0,   2,   5,   0, 
      5, 224,   5,   0, 228, 144, 
      1,   0,   0,   2,   6,   0, 
      5, 224,   7,   0, 228, 144, 
      1,   0,   0,   2,   3,   0, 
      8, 128,   6,   0,   0, 144, 
      1,   0,   0,   2,   7,   0, 
     15, 224,   3,   0, 147, 128, 
      1,   0,   0,   2,   4,   0, 
      2, 128,   9,   0,   0, 144, 
      1,   0,   0,   2,   8,   0, 
      3, 224,   4,   0, 228, 128, 
    255, 255,   0,   0
};
