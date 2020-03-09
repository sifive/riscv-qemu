/*
 * Copyright (c) 2020 C-SKY Limited. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
/* vfmv.v.f */
TEST_FUNC(test_vfmv_v_f_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a3)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a1
        vfmv.v.f        v4, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        frflags         a0
        ret
        .size   test_vfmv_v_f_16, .-test_vfmv_v_f_16

TEST_FUNC(test_vfmv_v_f_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a2)
        fmv.d.x         fa0, a0
        vsetvli         t1, a0, e32, m2
        vfmv.v.f        v4, fa0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        frflags         a0
        ret
        .size   test_vfmv_v_f_32, .-test_vfmv_v_f_32

TEST_FUNC(test_vfmv_v_f_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a2)
        fmv.d.x         fa0, a0
        vsetvli         t1, a0, e64, m2
        vfmv.v.f        v4, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        frflags         a0
        ret
        .size   test_vfmv_v_f_64, .-test_vfmv_v_f_64

/* vfmerge.vfm */
TEST_FUNC(test_vfmerge_vfm_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v8, (a1)
        vlhu.v          v0, (a5)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmerge.vfm      v4, v8, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_16, .-test_vfmerge_vfm_16

TEST_FUNC(test_vfmerge_vfm_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmerge.vfm        v6, v2, fa0, v0
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_16_vm, .-test_vfmerge_vfm_16_vm

TEST_FUNC(test_vfmerge_vfm_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v8, (a1)
        vlwu.v          v0, (a5)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmerge.vfm     v4, v8, fa0, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_32, .-test_vfmerge_vfm_32

TEST_FUNC(test_vfmerge_vfm_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmerge.vfm        v6, v2, fa0, v0
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_32_vm, .-test_vfmerge_vfm_32_vm

TEST_FUNC(test_vfmerge_vfm_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v8, (a1)
        vle.v           v0, (a5)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmerge.vfm     v4, v8, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_64, .-test_vfmerge_vfm_64

TEST_FUNC(test_vfmerge_vfm_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmerge.vfm     v6, v2, fa0, v0
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmerge_vfm_64_vm, .-test_vfmerge_vfm_64_vm



/* vfadd.vv */
TEST_FUNC(test_vfadd_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfadd.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vv_16, .-test_vfadd_vv_16

TEST_FUNC(test_vfadd_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfadd.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vv_16_vm, .-test_vfadd_vv_16_vm

TEST_FUNC(test_vfadd_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfadd.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vv_32, .-test_vfadd_vv_32

TEST_FUNC(test_vfadd_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfadd.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vv_32_vm, .-test_vfadd_vv_32_vm

TEST_FUNC(test_vfadd_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfadd.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vv_64, .-test_vfadd_vv_64

TEST_FUNC(test_vfadd_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfadd.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vv_64_vm, .-test_vfadd_vv_64_vm

/* vfadd.vf */
TEST_FUNC(test_vfadd_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfadd.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vf_16, .-test_vfadd_vf_16

TEST_FUNC(test_vfadd_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfadd.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vf_16_vm, .-test_vfadd_vf_16_vm

TEST_FUNC(test_vfadd_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfadd.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vf_32, .-test_vfadd_vf_32

TEST_FUNC(test_vfadd_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfadd.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vf_32_vm, .-test_vfadd_vf_32_vm

TEST_FUNC(test_vfadd_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfadd.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfadd_vf_64, .-test_vfadd_vf_64

TEST_FUNC(test_vfadd_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfadd.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfadd_vf_64_vm, .-test_vfadd_vf_64_vm

/* vfsub.vv */
TEST_FUNC(test_vfsub_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfsub.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vv_16, .-test_vfsub_vv_16

TEST_FUNC(test_vfsub_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vfsub.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vv_16_vm, .-test_vfsub_vv_16_vm

TEST_FUNC(test_vfsub_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfsub.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vv_32, .-test_vfsub_vv_32

TEST_FUNC(test_vfsub_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfsub.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vv_32_vm, .-test_vfsub_vv_32_vm

TEST_FUNC(test_vfsub_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfsub.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vv_64, .-test_vfsub_vv_64

TEST_FUNC(test_vfsub_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfsub.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vv_64_vm, .-test_vfsub_vv_64_vm

/* vfsub.vf */
TEST_FUNC(test_vfsub_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfsub.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vf_16, .-test_vfsub_vf_16

TEST_FUNC(test_vfsub_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfsub.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vf_16_vm, .-test_vfsub_vf_16_vm

TEST_FUNC(test_vfsub_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfsub.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vf_32, .-test_vfsub_vf_32

TEST_FUNC(test_vfsub_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfsub.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vf_32_vm, .-test_vfsub_vf_32_vm

TEST_FUNC(test_vfsub_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfsub.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsub_vf_64, .-test_vfsub_vf_64

TEST_FUNC(test_vfsub_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfsub.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsub_vf_64_vm, .-test_vfsub_vf_64_vm

/* vfrsub.vf */
TEST_FUNC(test_vfrsub_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfrsub.vf       v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrsub_vf_16, .-test_vfrsub_vf_16

TEST_FUNC(test_vfrsub_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfrsub.vf       v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrsub_vf_16_vm, .-test_vfrsub_vf_16_vm

TEST_FUNC(test_vfrsub_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfrsub.vf       v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrsub_vf_32, .-test_vfrsub_vf_32

TEST_FUNC(test_vfrsub_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfrsub.vf       v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrsub_vf_32_vm, .-test_vfrsub_vf_32_vm

TEST_FUNC(test_vfrsub_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfrsub.vf       v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrsub_vf_64, .-test_vfrsub_vf_64

TEST_FUNC(test_vfrsub_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfrsub.vf       v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrsub_vf_64_vm, .-test_vfrsub_vf_64_vm

/* vfwadd.vv */
TEST_FUNC(test_vfwadd_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwadd.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_vv_16, .-test_vfwadd_vv_16

TEST_FUNC(test_vfwadd_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwadd.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_vv_16_vm, .-test_vfwadd_vv_16_vm

TEST_FUNC(test_vfwadd_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwadd.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_vv_32, .-test_vfwadd_vv_32

TEST_FUNC(test_vfwadd_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwadd.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_vv_32_vm, .-test_vfwadd_vv_32_vm

/* vfwadd.vf */
TEST_FUNC(test_vfwadd_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwadd.vf       v4, v0, fa0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_vf_16, .-test_vfwadd_vf_16

TEST_FUNC(test_vfwadd_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwadd.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_vf_16_vm, .-test_vfwadd_vf_16_vm

TEST_FUNC(test_vfwadd_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwadd.vf       v4, v0, fa0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_vf_32, .-test_vfwadd_vf_32

TEST_FUNC(test_vfwadd_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwadd.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_vf_32_vm, .-test_vfwadd_vf_32_vm

/* vfwsub.vv */
TEST_FUNC(test_vfwsub_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwsub.vv       v4, v0, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_vv_16, .-test_vfwsub_vv_16

TEST_FUNC(test_vfwsub_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vfwsub.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_vv_16_vm, .-test_vfwsub_vv_16_vm

TEST_FUNC(test_vfwsub_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwsub.vv       v4, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_vv_32, .-test_vfwsub_vv_32

TEST_FUNC(test_vfwsub_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwsub.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_vv_32_vm, .-test_vfwsub_vv_32_vm

/* vfwsub.vf */
TEST_FUNC(test_vfwsub_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwsub.vf       v4, v0, fa0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_vf_16, .-test_vfwsub_vf_16

TEST_FUNC(test_vfwsub_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwsub.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_vf_16_vm, .-test_vfwsub_vf_16_vm

TEST_FUNC(test_vfwsub_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwsub.vf       v4, v0, fa0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_vf_32, .-test_vfwsub_vf_32

TEST_FUNC(test_vfwsub_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwsub.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_vf_32_vm, .-test_vfwsub_vf_32_vm

/* vfwadd.wv */
TEST_FUNC(test_vfwadd_wv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vlw.v           v8, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwadd.wv       v4, v8, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_wv_16, .-test_vfwadd_wv_16

TEST_FUNC(test_vfwadd_wv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vlwu.v          v4, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a1)
        vfwadd.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_wv_16_vm, .-test_vfwadd_wv_16_vm

TEST_FUNC(test_vfwadd_wv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vle.v           v8, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwadd.wv       v4, v8, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_wv_32, .-test_vfwadd_wv_32

TEST_FUNC(test_vfwadd_wv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a1)
        vfwadd.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_wv_32_vm, .-test_vfwadd_wv_32_vm

/* vfwsub.wv */
TEST_FUNC(test_vfwsub_wv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vlw.v           v8, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwsub.wv       v4, v8, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_wv_16, .-test_vfwsub_wv_16

TEST_FUNC(test_vfwsub_wv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vlwu.v          v4, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a1)
        vfwsub.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_wv_16_vm, .-test_vfwsub_wv_16_vm

TEST_FUNC(test_vfwsub_wv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vle.v           v8, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwsub.wv       v4, v8, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_wv_32, .-test_vfwsub_wv_32

TEST_FUNC(test_vfwsub_wv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a1)
        vfwsub.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_wv_32_vm, .-test_vfwsub_wv_32_vm

/* vfwadd.wf */
TEST_FUNC(test_vfwadd_wf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwadd.wf       v4, v0, fa0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_wf_16, .-test_vfwadd_wf_16

TEST_FUNC(test_vfwadd_wf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vlw.v           v4, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        fmv.d.x         fa0, a1
        vfwadd.wf       v8, v4, fa0, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_wf_16_vm, .-test_vfwadd_wf_16_vm

TEST_FUNC(test_vfwadd_wf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwadd.wf       v4, v0, fa0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwadd_wf_32, .-test_vfwadd_wf_32

TEST_FUNC(test_vfwadd_wf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        fmv.d.x         fa0, a1
        vfwadd.wf       v8, v4, fa0, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwadd_wf_32_vm, .-test_vfwadd_wf_32_vm

/* vfwsub.wf */
TEST_FUNC(test_vfwsub_wf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwsub.wf       v4, v0, fa0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_wf_16, .-test_vfwsub_wf_16

TEST_FUNC(test_vfwsub_wf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vlw.v           v4, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        fmv.d.x         fa0, a1
        vfwsub.wf       v8, v4, fa0, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_wf_16_vm, .-test_vfwsub_wf_16_vm

TEST_FUNC(test_vfwsub_wf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwsub.wf       v4, v0, fa0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwsub_wf_32, .-test_vfwsub_wf_32

TEST_FUNC(test_vfwsub_wf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        fmv.d.x         fa0, a1
        vfwsub.wf       v8, v4, fa0, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwsub_wf_32_vm, .-test_vfwsub_wf_32_vm

/* vfmul.vv */
TEST_FUNC(test_vfmul_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmul.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vv_16, .-test_vfmul_vv_16

TEST_FUNC(test_vfmul_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmul.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vv_16_vm, .-test_vfmul_vv_16_vm

TEST_FUNC(test_vfmul_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmul.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vv_32, .-test_vfmul_vv_32

TEST_FUNC(test_vfmul_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmul.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vv_32_vm, .-test_vfmul_vv_32_vm

TEST_FUNC(test_vfmul_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmul.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vv_64, .-test_vfmul_vv_64

TEST_FUNC(test_vfmul_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmul.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vv_64_vm, .-test_vfmul_vv_64_vm

/* vfmul.vf */
TEST_FUNC(test_vfmul_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmul.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vf_16, .-test_vfmul_vf_16

TEST_FUNC(test_vfmul_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmul.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vf_16_vm, .-test_vfmul_vf_16_vm

TEST_FUNC(test_vfmul_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmul.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vf_32, .-test_vfmul_vf_32

TEST_FUNC(test_vfmul_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmul.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vf_32_vm, .-test_vfmul_vf_32_vm

TEST_FUNC(test_vfmul_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmul.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmul_vf_64, .-test_vfmul_vf_64

TEST_FUNC(test_vfmul_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmul.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmul_vf_64_vm, .-test_vfmul_vf_64_vm

/* vfdiv.vv */
TEST_FUNC(test_vfdiv_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfdiv.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vv_16, .-test_vfdiv_vv_16

TEST_FUNC(test_vfdiv_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfdiv.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vv_16_vm, .-test_vfdiv_vv_16_vm

TEST_FUNC(test_vfdiv_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfdiv.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vv_32, .-test_vfdiv_vv_32

TEST_FUNC(test_vfdiv_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfdiv.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vv_32_vm, .-test_vfdiv_vv_32_vm

TEST_FUNC(test_vfdiv_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfdiv.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vv_64, .-test_vfdiv_vv_64

TEST_FUNC(test_vfdiv_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfdiv.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vv_64_vm, .-test_vfdiv_vv_64_vm

/* vfdiv.vf */
TEST_FUNC(test_vfdiv_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vf_16, .-test_vfdiv_vf_16

TEST_FUNC(test_vfdiv_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfdiv.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vf_16_vm, .-test_vfdiv_vf_16_vm

TEST_FUNC(test_vfdiv_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vf_32, .-test_vfdiv_vf_32

TEST_FUNC(test_vfdiv_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfdiv.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vf_32_vm, .-test_vfdiv_vf_32_vm

TEST_FUNC(test_vfdiv_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfdiv_vf_64, .-test_vfdiv_vf_64

TEST_FUNC(test_vfdiv_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfdiv.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfdiv_vf_64_vm, .-test_vfdiv_vf_64_vm

/* vfrdiv.vf */
TEST_FUNC(test_vfrdiv_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfrdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_16, .-test_vfrdiv_vf_16

TEST_FUNC(test_vfrdiv_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfrdiv.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_16_vm, .-test_vfrdiv_vf_16_vm

TEST_FUNC(test_vfrdiv_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfrdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_32, .-test_vfrdiv_vf_32

TEST_FUNC(test_vfrdiv_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfrdiv.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_32_vm, .-test_vfrdiv_vf_32_vm

TEST_FUNC(test_vfrdiv_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfrdiv.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_64, .-test_vfrdiv_vf_64

TEST_FUNC(test_vfrdiv_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfrdiv.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfrdiv_vf_64_vm, .-test_vfrdiv_vf_64_vm

/* vfwmul.vv */
TEST_FUNC(test_vfwmul_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwmul.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmul_vv_16, .-test_vfwmul_vv_16

TEST_FUNC(test_vfwmul_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwmul.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmul_vv_16_vm, .-test_vfwmul_vv_16_vm

TEST_FUNC(test_vfwmul_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwmul.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmul_vv_32, .-test_vfwmul_vv_32

TEST_FUNC(test_vfwmul_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwmul.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmul_vv_32_vm, .-test_vfwmul_vv_32_vm

/* vfwmul.vf */
TEST_FUNC(test_vfwmul_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwmul.vf       v4, v0, fa0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmul_vf_16, .-test_vfwmul_vf_16

TEST_FUNC(test_vfwmul_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmul.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmul_vf_16_vm, .-test_vfwmul_vf_16_vm

TEST_FUNC(test_vfwmul_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwmul.vf       v4, v0, fa0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmul_vf_32, .-test_vfwmul_vf_32

TEST_FUNC(test_vfwmul_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmul.vf       v8, v2, fa0, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmul_vf_32_vm, .-test_vfwmul_vf_32_vm

/* vfmacc.vv */
TEST_FUNC(test_vfmacc_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vv_16, .-test_vfmacc_vv_16

TEST_FUNC(test_vfmacc_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmacc.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vv_16_vm, .-test_vfmacc_vv_16_vm

TEST_FUNC(test_vfmacc_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vv_32, .-test_vfmacc_vv_32

TEST_FUNC(test_vfmacc_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmacc.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vv_32_vm, .-test_vfmacc_vv_32_vm

TEST_FUNC(test_vfmacc_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vv_64, .-test_vfmacc_vv_64

TEST_FUNC(test_vfmacc_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmacc.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vv_64_vm, .-test_vfmacc_vv_64_vm

/* vfmacc.vf */
TEST_FUNC(test_vfmacc_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vf_16, .-test_vfmacc_vf_16

TEST_FUNC(test_vfmacc_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmacc.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vf_16_vm, .-test_vfmacc_vf_16_vm

TEST_FUNC(test_vfmacc_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vf_32, .-test_vfmacc_vf_32

TEST_FUNC(test_vfmacc_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmacc.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vf_32_vm, .-test_vfmacc_vf_32_vm

TEST_FUNC(test_vfmacc_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmacc_vf_64, .-test_vfmacc_vf_64

TEST_FUNC(test_vfmacc_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmacc.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmacc_vf_64_vm, .-test_vfmacc_vf_64_vm

/* vfnmacc.vv */
TEST_FUNC(test_vfnmacc_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfnmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_16, .-test_vfnmacc_vv_16

TEST_FUNC(test_vfnmacc_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfnmacc.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_16_vm, .-test_vfnmacc_vv_16_vm

TEST_FUNC(test_vfnmacc_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfnmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_32, .-test_vfnmacc_vv_32

TEST_FUNC(test_vfnmacc_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfnmacc.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_32_vm, .-test_vfnmacc_vv_32_vm

TEST_FUNC(test_vfnmacc_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfnmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_64, .-test_vfnmacc_vv_64

TEST_FUNC(test_vfnmacc_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfnmacc.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vv_64_vm, .-test_vfnmacc_vv_64_vm

/* vfnmacc.vf */
TEST_FUNC(test_vfnmacc_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfnmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_16, .-test_vfnmacc_vf_16

TEST_FUNC(test_vfnmacc_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfnmacc.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_16_vm, .-test_vfnmacc_vf_16_vm

TEST_FUNC(test_vfnmacc_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfnmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_32, .-test_vfnmacc_vf_32

TEST_FUNC(test_vfnmacc_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfnmacc.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_32_vm, .-test_vfnmacc_vf_32_vm

TEST_FUNC(test_vfnmacc_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfnmacc.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_64, .-test_vfnmacc_vf_64

TEST_FUNC(test_vfnmacc_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfnmacc.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmacc_vf_64_vm, .-test_vfnmacc_vf_64_vm

/* vfmsac.vv */
TEST_FUNC(test_vfmsac_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vv_16, .-test_vfmsac_vv_16

TEST_FUNC(test_vfmsac_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmsac.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vv_16_vm, .-test_vfmsac_vv_16_vm

TEST_FUNC(test_vfmsac_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vv_32, .-test_vfmsac_vv_32

TEST_FUNC(test_vfmsac_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmsac.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vv_32_vm, .-test_vfmsac_vv_32_vm

TEST_FUNC(test_vfmsac_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vv_64, .-test_vfmsac_vv_64

TEST_FUNC(test_vfmsac_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmsac.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vv_64_vm, .-test_vfmsac_vv_64_vm

/* vfmsac.vf */
TEST_FUNC(test_vfmsac_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vf_16, .-test_vfmsac_vf_16

TEST_FUNC(test_vfmsac_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmsac.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vf_16_vm, .-test_vfmsac_vf_16_vm

TEST_FUNC(test_vfmsac_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vf_32, .-test_vfmsac_vf_32

TEST_FUNC(test_vfmsac_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmsac.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vf_32_vm, .-test_vfmsac_vf_32_vm

TEST_FUNC(test_vfmsac_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsac_vf_64, .-test_vfmsac_vf_64

TEST_FUNC(test_vfmsac_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmsac.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsac_vf_64_vm, .-test_vfmsac_vf_64_vm

/* vfnmsac.vv */
TEST_FUNC(test_vfnmsac_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfnmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_16, .-test_vfnmsac_vv_16

TEST_FUNC(test_vfnmsac_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfnmsac.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_16_vm, .-test_vfnmsac_vv_16_vm

TEST_FUNC(test_vfnmsac_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfnmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_32, .-test_vfnmsac_vv_32

TEST_FUNC(test_vfnmsac_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfnmsac.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_32_vm, .-test_vfnmsac_vv_32_vm

TEST_FUNC(test_vfnmsac_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfnmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_64, .-test_vfnmsac_vv_64

TEST_FUNC(test_vfnmsac_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfnmsac.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vv_64_vm, .-test_vfnmsac_vv_64_vm

/* vfnmsac.vf */
TEST_FUNC(test_vfnmsac_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfnmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_16, .-test_vfnmsac_vf_16

TEST_FUNC(test_vfnmsac_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfnmsac.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_16_vm, .-test_vfnmsac_vf_16_vm

TEST_FUNC(test_vfnmsac_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfnmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_32, .-test_vfnmsac_vf_32

TEST_FUNC(test_vfnmsac_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfnmsac.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_32_vm, .-test_vfnmsac_vf_32_vm

TEST_FUNC(test_vfnmsac_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfnmsac.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_64, .-test_vfnmsac_vf_64

TEST_FUNC(test_vfnmsac_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfnmsac.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsac_vf_64_vm, .-test_vfnmsac_vf_64_vm

/* vfmadd.vv */
TEST_FUNC(test_vfmadd_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vv_16, .-test_vfmadd_vv_16

TEST_FUNC(test_vfmadd_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmadd.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vv_16_vm, .-test_vfmadd_vv_16_vm

TEST_FUNC(test_vfmadd_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vv_32, .-test_vfmadd_vv_32

TEST_FUNC(test_vfmadd_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmadd.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vv_32_vm, .-test_vfmadd_vv_32_vm

TEST_FUNC(test_vfmadd_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vv_64, .-test_vfmadd_vv_64

TEST_FUNC(test_vfmadd_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmadd.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vv_64_vm, .-test_vfmadd_vv_64_vm

/* vfmadd.vf */
TEST_FUNC(test_vfmadd_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vf_16, .-test_vfmadd_vf_16

TEST_FUNC(test_vfmadd_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmadd.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vf_16_vm, .-test_vfmadd_vf_16_vm

TEST_FUNC(test_vfmadd_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vf_32, .-test_vfmadd_vf_32

TEST_FUNC(test_vfmadd_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmadd.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vf_32_vm, .-test_vfmadd_vf_32_vm

TEST_FUNC(test_vfmadd_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmadd_vf_64, .-test_vfmadd_vf_64

TEST_FUNC(test_vfmadd_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmadd.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmadd_vf_64_vm, .-test_vfmadd_vf_64_vm

/* vfnmadd.vv */
TEST_FUNC(test_vfnmadd_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfnmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_16, .-test_vfnmadd_vv_16

TEST_FUNC(test_vfnmadd_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfnmadd.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_16_vm, .-test_vfnmadd_vv_16_vm

TEST_FUNC(test_vfnmadd_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfnmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_32, .-test_vfnmadd_vv_32

TEST_FUNC(test_vfnmadd_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfnmadd.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_32_vm, .-test_vfnmadd_vv_32_vm

TEST_FUNC(test_vfnmadd_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfnmadd.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_64, .-test_vfnmadd_vv_64

TEST_FUNC(test_vfnmadd_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfnmadd.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vv_64_vm, .-test_vfnmadd_vv_64_vm

/* vfnmadd.vf */
TEST_FUNC(test_vfnmadd_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfnmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_16, .-test_vfnmadd_vf_16

TEST_FUNC(test_vfnmadd_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfnmadd.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_16_vm, .-test_vfnmadd_vf_16_vm

TEST_FUNC(test_vfnmadd_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfnmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_32, .-test_vfnmadd_vf_32

TEST_FUNC(test_vfnmadd_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfnmadd.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_32_vm, .-test_vfnmadd_vf_32_vm

TEST_FUNC(test_vfnmadd_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfnmadd.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_64, .-test_vfnmadd_vf_64

TEST_FUNC(test_vfnmadd_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfnmadd.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmadd_vf_64_vm, .-test_vfnmadd_vf_64_vm

/* vfmsub.vv */
TEST_FUNC(test_vfmsub_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vv_16, .-test_vfmsub_vv_16

TEST_FUNC(test_vfmsub_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmsub.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vv_16_vm, .-test_vfmsub_vv_16_vm

TEST_FUNC(test_vfmsub_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vv_32, .-test_vfmsub_vv_32

TEST_FUNC(test_vfmsub_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmsub.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vv_32_vm, .-test_vfmsub_vv_32_vm

TEST_FUNC(test_vfmsub_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vv_64, .-test_vfmsub_vv_64

TEST_FUNC(test_vfmsub_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmsub.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vv_64_vm, .-test_vfmsub_vv_64_vm

/* vfmsub.vf */
TEST_FUNC(test_vfmsub_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vf_16, .-test_vfmsub_vf_16

TEST_FUNC(test_vfmsub_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmsub.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vf_16_vm, .-test_vfmsub_vf_16_vm

TEST_FUNC(test_vfmsub_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vf_32, .-test_vfmsub_vf_32

TEST_FUNC(test_vfmsub_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmsub.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vf_32_vm, .-test_vfmsub_vf_32_vm

TEST_FUNC(test_vfmsub_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmsub_vf_64, .-test_vfmsub_vf_64

TEST_FUNC(test_vfmsub_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmsub.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmsub_vf_64_vm, .-test_vfmsub_vf_64_vm

/* vfnmsub.vv */
TEST_FUNC(test_vfnmsub_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfnmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_16, .-test_vfnmsub_vv_16

TEST_FUNC(test_vfnmsub_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfnmsub.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_16_vm, .-test_vfnmsub_vv_16_vm

TEST_FUNC(test_vfnmsub_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfnmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_32, .-test_vfnmsub_vv_32

TEST_FUNC(test_vfnmsub_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfnmsub.vv       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_32_vm, .-test_vfnmsub_vv_32_vm

TEST_FUNC(test_vfnmsub_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfnmsub.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_64, .-test_vfnmsub_vv_64

TEST_FUNC(test_vfnmsub_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfnmsub.vv       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vv_64_vm, .-test_vfnmsub_vv_64_vm

/* vfnmsub.vf */
TEST_FUNC(test_vfnmsub_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfnmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_16, .-test_vfnmsub_vf_16

TEST_FUNC(test_vfnmsub_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfnmsub.vf       v6, fa0, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_16_vm, .-test_vfnmsub_vf_16_vm

TEST_FUNC(test_vfnmsub_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfnmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_32, .-test_vfnmsub_vf_32

TEST_FUNC(test_vfnmsub_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfnmsub.vf       v6, fa0, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_32_vm, .-test_vfnmsub_vf_32_vm

TEST_FUNC(test_vfnmsub_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfnmsub.vf       v4, fa0, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_64, .-test_vfnmsub_vf_64

TEST_FUNC(test_vfnmsub_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfnmsub.vf       v6, fa0, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfnmsub_vf_64_vm, .-test_vfnmsub_vf_64_vm

/* vfwmacc.vv */
TEST_FUNC(test_vfwmacc_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmacc_vv_16, .-test_vfwmacc_vv_16

TEST_FUNC(test_vfwmacc_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmacc_vv_16_vm, .-test_vfwmacc_vv_16_vm

TEST_FUNC(test_vfwmacc_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmacc_vv_32, .-test_vfwmacc_vv_32

TEST_FUNC(test_vfwmacc_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmacc_vv_32_vm, .-test_vfwmacc_vv_32_vm

/* vfwmacc.vf */
TEST_FUNC(test_vfwmacc_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwmacc.vf      v4, fa0, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmacc_vf_16, .-test_vfwmacc_vf_16

TEST_FUNC(test_vfwmacc_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmacc.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmacc_vf_16_vm, .-test_vfwmacc_vf_16_vm

TEST_FUNC(test_vfwmacc_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwmacc.vf      v4, fa0, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmacc_vf_32, .-test_vfwmacc_vf_32

TEST_FUNC(test_vfwmacc_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmacc.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmacc_vf_32_vm, .-test_vfwmacc_vf_32_vm

/* vfwnmacc.vv */
TEST_FUNC(test_vfwnmacc_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwnmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmacc_vv_16, .-test_vfwnmacc_vv_16

TEST_FUNC(test_vfwnmacc_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwnmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmacc_vv_16_vm, .-test_vfwnmacc_vv_16_vm

TEST_FUNC(test_vfwnmacc_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwnmacc.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmacc_vv_32, .-test_vfwnmacc_vv_32

TEST_FUNC(test_vfwnmacc_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwnmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmacc_vv_32_vm, .-test_vfwnmacc_vv_32_vm

/* vfwnmacc.vf */
TEST_FUNC(test_vfwnmacc_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwnmacc.vf      v4, fa0, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmacc_vf_16, .-test_vfwnmacc_vf_16

TEST_FUNC(test_vfwnmacc_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwnmacc.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmacc_vf_16_vm, .-test_vfwnmacc_vf_16_vm

TEST_FUNC(test_vfwnmacc_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwnmacc.vf      v4, fa0, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmacc_vf_32, .-test_vfwnmacc_vf_32

TEST_FUNC(test_vfwnmacc_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwnmacc.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmacc_vf_32_vm, .-test_vfwnmacc_vf_32_vm

/* vfwmsac.vv */
TEST_FUNC(test_vfwmsac_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmsac_vv_16, .-test_vfwmsac_vv_16

TEST_FUNC(test_vfwmsac_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwmsac.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmsac_vv_16_vm, .-test_vfwmsac_vv_16_vm

TEST_FUNC(test_vfwmsac_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmsac_vv_32, .-test_vfwmsac_vv_32

TEST_FUNC(test_vfwmsac_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwmsac.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmsac_vv_32_vm, .-test_vfwmsac_vv_32_vm

/* vfwmsac.vf */
TEST_FUNC(test_vfwmsac_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwmsac.vf      v4, fa0, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmsac_vf_16, .-test_vfwmsac_vf_16

TEST_FUNC(test_vfwmsac_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmsac.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmsac_vf_16_vm, .-test_vfwmsac_vf_16_vm

TEST_FUNC(test_vfwmsac_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwmsac.vf      v4, fa0, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwmsac_vf_32, .-test_vfwmsac_vf_32

TEST_FUNC(test_vfwmsac_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwmsac.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwmsac_vf_32_vm, .-test_vfwmsac_vf_32_vm

/* vfwnmsac.vv */
TEST_FUNC(test_vfwnmsac_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwnmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmsac_vv_16, .-test_vfwnmsac_vv_16

TEST_FUNC(test_vfwnmsac_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfwnmsac.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmsac_vv_16_vm, .-test_vfwnmsac_vv_16_vm

TEST_FUNC(test_vfwnmsac_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwnmsac.vv       v4, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmsac_vv_32, .-test_vfwnmsac_vv_32

TEST_FUNC(test_vfwnmsac_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vfwnmsac.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmsac_vv_32_vm, .-test_vfwnmsac_vv_32_vm

/* vfwnmsac.vf */
TEST_FUNC(test_vfwnmsac_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfwnmsac.vf      v4, fa0, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmsac_vf_16, .-test_vfwnmsac_vf_16

TEST_FUNC(test_vfwnmsac_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwnmsac.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmsac_vf_16_vm, .-test_vfwnmsac_vf_16_vm

TEST_FUNC(test_vfwnmsac_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfwnmsac.vf      v4, fa0, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwnmsac_vf_32, .-test_vfwnmsac_vf_32

TEST_FUNC(test_vfwnmsac_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfwnmsac.vf      v8, fa0, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwnmsac_vf_32_vm, .-test_vfwnmsac_vf_32_vm

/* vfsqrt.v */
TEST_FUNC(test_vfsqrt_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfsqrt.v        v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsqrt_v_16, .-test_vfsqrt_v_16

TEST_FUNC(test_vfsqrt_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfsqrt.v        v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsqrt_v_16_vm, .-test_vfsqrt_v_16_vm

TEST_FUNC(test_vfsqrt_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfsqrt.v        v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsqrt_v_32, .-test_vfsqrt_v_32

TEST_FUNC(test_vfsqrt_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfsqrt.v        v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsqrt_v_32_vm, .-test_vfsqrt_v_32_vm

TEST_FUNC(test_vfsqrt_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfsqrt.v        v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsqrt_v_64, .-test_vfsqrt_v_64

TEST_FUNC(test_vfsqrt_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfsqrt.v        v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsqrt_v_64_vm, .-test_vfsqrt_v_64_vm

/* vfmin.vv */
TEST_FUNC(test_vfmin_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmin.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vv_16, .-test_vfmin_vv_16

TEST_FUNC(test_vfmin_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmin.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vv_16_vm, .-test_vfmin_vv_16_vm

TEST_FUNC(test_vfmin_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmin.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vv_32, .-test_vfmin_vv_32

TEST_FUNC(test_vfmin_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmin.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vv_32_vm, .-test_vfmin_vv_32_vm

TEST_FUNC(test_vfmin_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmin.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vv_64, .-test_vfmin_vv_64

TEST_FUNC(test_vfmin_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmin.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vv_64_vm, .-test_vfmin_vv_64_vm

/* vfmin.vf */
TEST_FUNC(test_vfmin_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmin.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vf_16, .-test_vfmin_vf_16

TEST_FUNC(test_vfmin_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmin.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vf_16_vm, .-test_vfmin_vf_16_vm

TEST_FUNC(test_vfmin_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmin.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vf_32, .-test_vfmin_vf_32

TEST_FUNC(test_vfmin_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmin.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vf_32_vm, .-test_vfmin_vf_32_vm

TEST_FUNC(test_vfmin_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmin.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmin_vf_64, .-test_vfmin_vf_64

TEST_FUNC(test_vfmin_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmin.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmin_vf_64_vm, .-test_vfmin_vf_64_vm

/* vfmax.vv */
TEST_FUNC(test_vfmax_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfmax.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vv_16, .-test_vfmax_vv_16

TEST_FUNC(test_vfmax_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfmax.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vv_16_vm, .-test_vfmax_vv_16_vm

TEST_FUNC(test_vfmax_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfmax.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vv_32, .-test_vfmax_vv_32

TEST_FUNC(test_vfmax_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfmax.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vv_32_vm, .-test_vfmax_vv_32_vm

TEST_FUNC(test_vfmax_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfmax.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vv_64, .-test_vfmax_vv_64

TEST_FUNC(test_vfmax_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfmax.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vv_64_vm, .-test_vfmax_vv_64_vm

/* vfmax.vf */
TEST_FUNC(test_vfmax_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfmax.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vf_16, .-test_vfmax_vf_16

TEST_FUNC(test_vfmax_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfmax.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vf_16_vm, .-test_vfmax_vf_16_vm

TEST_FUNC(test_vfmax_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfmax.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vf_32, .-test_vfmax_vf_32

TEST_FUNC(test_vfmax_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfmax.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vf_32_vm, .-test_vfmax_vf_32_vm

TEST_FUNC(test_vfmax_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfmax.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfmax_vf_64, .-test_vfmax_vf_64

TEST_FUNC(test_vfmax_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfmax.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfmax_vf_64_vm, .-test_vfmax_vf_64_vm

/* vfsgnj.vv */
TEST_FUNC(test_vfsgnj_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfsgnj.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_16, .-test_vfsgnj_vv_16

TEST_FUNC(test_vfsgnj_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfsgnj.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_16_vm, .-test_vfsgnj_vv_16_vm

TEST_FUNC(test_vfsgnj_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfsgnj.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_32, .-test_vfsgnj_vv_32

TEST_FUNC(test_vfsgnj_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfsgnj.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_32_vm, .-test_vfsgnj_vv_32_vm

TEST_FUNC(test_vfsgnj_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfsgnj.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_64, .-test_vfsgnj_vv_64

TEST_FUNC(test_vfsgnj_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfsgnj.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vv_64_vm, .-test_vfsgnj_vv_64_vm

/* vfsgnj.vf */
TEST_FUNC(test_vfsgnj_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfsgnj.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_16, .-test_vfsgnj_vf_16

TEST_FUNC(test_vfsgnj_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnj.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_16_vm, .-test_vfsgnj_vf_16_vm

TEST_FUNC(test_vfsgnj_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfsgnj.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_32, .-test_vfsgnj_vf_32

TEST_FUNC(test_vfsgnj_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfsgnj.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_32_vm, .-test_vfsgnj_vf_32_vm

TEST_FUNC(test_vfsgnj_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfsgnj.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_64, .-test_vfsgnj_vf_64

TEST_FUNC(test_vfsgnj_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnj.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnj_vf_64_vm, .-test_vfsgnj_vf_64_vm

/* vfsgnjn.vv */
TEST_FUNC(test_vfsgnjn_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfsgnjn.vv      v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_16, .-test_vfsgnjn_vv_16

TEST_FUNC(test_vfsgnjn_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfsgnjn.vv      v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_16_vm, .-test_vfsgnjn_vv_16_vm

TEST_FUNC(test_vfsgnjn_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfsgnjn.vv      v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_32, .-test_vfsgnjn_vv_32

TEST_FUNC(test_vfsgnjn_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfsgnjn.vv      v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_32_vm, .-test_vfsgnjn_vv_32_vm

TEST_FUNC(test_vfsgnjn_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfsgnjn.vv      v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_64, .-test_vfsgnjn_vv_64

TEST_FUNC(test_vfsgnjn_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfsgnjn.vv      v6, v2, v4, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vv_64_vm, .-test_vfsgnjn_vv_64_vm

/* vfsgnjn.vf */
TEST_FUNC(test_vfsgnjn_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfsgnjn.vf      v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_16, .-test_vfsgnjn_vf_16

TEST_FUNC(test_vfsgnjn_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnjn.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_16_vm, .-test_vfsgnjn_vf_16_vm

TEST_FUNC(test_vfsgnjn_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfsgnjn.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_32, .-test_vfsgnjn_vf_32

TEST_FUNC(test_vfsgnjn_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfsgnjn.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_32_vm, .-test_vfsgnjn_vf_32_vm

TEST_FUNC(test_vfsgnjn_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfsgnjn.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_64, .-test_vfsgnjn_vf_64

TEST_FUNC(test_vfsgnjn_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnjn.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjn_vf_64_vm, .-test_vfsgnjn_vf_64_vm

/* vfsgnjx.vv */
TEST_FUNC(test_vfsgnjx_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfsgnjx.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_16, .-test_vfsgnjx_vv_16

TEST_FUNC(test_vfsgnjx_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vfsgnjx.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_16_vm, .-test_vfsgnjx_vv_16_vm

TEST_FUNC(test_vfsgnjx_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfsgnjx.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_32, .-test_vfsgnjx_vv_32

TEST_FUNC(test_vfsgnjx_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vfsgnjx.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_32_vm, .-test_vfsgnjx_vv_32_vm

TEST_FUNC(test_vfsgnjx_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfsgnjx.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_64, .-test_vfsgnjx_vv_64

TEST_FUNC(test_vfsgnjx_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vfsgnjx.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vv_64_vm, .-test_vfsgnjx_vv_64_vm

/* vfsgnjx.vf */
TEST_FUNC(test_vfsgnjx_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vfsgnjx.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_16, .-test_vfsgnjx_vf_16

TEST_FUNC(test_vfsgnjx_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnjx.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_16_vm, .-test_vfsgnjx_vf_16_vm

TEST_FUNC(test_vfsgnjx_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vfsgnjx.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_32, .-test_vfsgnjx_vf_32

TEST_FUNC(test_vfsgnjx_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vfsgnjx.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_32_vm, .-test_vfsgnjx_vf_32_vm

TEST_FUNC(test_vfsgnjx_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vfsgnjx.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_64, .-test_vfsgnjx_vf_64

TEST_FUNC(test_vfsgnjx_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vfsgnjx.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfsgnjx_vf_64_vm, .-test_vfsgnjx_vf_64_vm

/* vmfeq.vv */
TEST_FUNC(test_vmfeq_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vmfeq.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vv_16, .-test_vmfeq_vv_16

TEST_FUNC(test_vmfeq_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vmfeq.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vv_16_vm, .-test_vmfeq_vv_16_vm

TEST_FUNC(test_vmfeq_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vmfeq.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vv_32, .-test_vmfeq_vv_32

TEST_FUNC(test_vmfeq_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vmfeq.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vv_32_vm, .-test_vmfeq_vv_32_vm

TEST_FUNC(test_vmfeq_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vmfeq.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vv_64, .-test_vmfeq_vv_64

TEST_FUNC(test_vmfeq_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmfeq.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vv_64_vm, .-test_vmfeq_vv_64_vm

/* vmfeq.vf */
TEST_FUNC(test_vmfeq_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmfeq.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vf_16, .-test_vmfeq_vf_16

TEST_FUNC(test_vmfeq_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmfeq.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vf_16_vm, .-test_vmfeq_vf_16_vm

TEST_FUNC(test_vmfeq_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmfeq.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vf_32, .-test_vmfeq_vf_32

TEST_FUNC(test_vmfeq_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmfeq.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vf_32_vm, .-test_vmfeq_vf_32_vm

TEST_FUNC(test_vmfeq_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmfeq.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfeq_vf_64, .-test_vmfeq_vf_64

TEST_FUNC(test_vmfeq_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmfeq.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfeq_vf_64_vm, .-test_vmfeq_vf_64_vm

/* vmfne.vv */
TEST_FUNC(test_vmfne_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vmfne.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vv_16, .-test_vmfne_vv_16

TEST_FUNC(test_vmfne_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vmfne.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vv_16_vm, .-test_vmfne_vv_16_vm

TEST_FUNC(test_vmfne_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vmfne.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vv_32, .-test_vmfne_vv_32

TEST_FUNC(test_vmfne_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vmfne.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vv_32_vm, .-test_vmfne_vv_32_vm

TEST_FUNC(test_vmfne_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vmfne.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vv_64, .-test_vmfne_vv_64

TEST_FUNC(test_vmfne_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmfne.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vv_64_vm, .-test_vmfne_vv_64_vm

/* vmfne.vf */
TEST_FUNC(test_vmfne_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmfne.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vf_16, .-test_vmfne_vf_16

TEST_FUNC(test_vmfne_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmfne.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vf_16_vm, .-test_vmfne_vf_16_vm

TEST_FUNC(test_vmfne_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmfne.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vf_32, .-test_vmfne_vf_32

TEST_FUNC(test_vmfne_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmfne.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vf_32_vm, .-test_vmfne_vf_32_vm

TEST_FUNC(test_vmfne_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmfne.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfne_vf_64, .-test_vmfne_vf_64

TEST_FUNC(test_vmfne_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmfne.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfne_vf_64_vm, .-test_vmfne_vf_64_vm

/* vmflt.vv */
TEST_FUNC(test_vmflt_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vmflt.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vv_16, .-test_vmflt_vv_16

TEST_FUNC(test_vmflt_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vmflt.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vv_16_vm, .-test_vmflt_vv_16_vm

TEST_FUNC(test_vmflt_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vmflt.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vv_32, .-test_vmflt_vv_32

TEST_FUNC(test_vmflt_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vmflt.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vv_32_vm, .-test_vmflt_vv_32_vm

TEST_FUNC(test_vmflt_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vmflt.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vv_64, .-test_vmflt_vv_64

TEST_FUNC(test_vmflt_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmflt.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vv_64_vm, .-test_vmflt_vv_64_vm

/* vmflt.vf */
TEST_FUNC(test_vmflt_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmflt.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vf_16, .-test_vmflt_vf_16

TEST_FUNC(test_vmflt_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmflt.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vf_16_vm, .-test_vmflt_vf_16_vm

TEST_FUNC(test_vmflt_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmflt.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vf_32, .-test_vmflt_vf_32

TEST_FUNC(test_vmflt_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmflt.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vf_32_vm, .-test_vmflt_vf_32_vm

TEST_FUNC(test_vmflt_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmflt.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmflt_vf_64, .-test_vmflt_vf_64

TEST_FUNC(test_vmflt_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmflt.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmflt_vf_64_vm, .-test_vmflt_vf_64_vm

/* vmfle.vv */
TEST_FUNC(test_vmfle_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vmfle.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vv_16, .-test_vmfle_vv_16

TEST_FUNC(test_vmfle_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vmfle.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vv_16_vm, .-test_vmfle_vv_16_vm

TEST_FUNC(test_vmfle_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vmfle.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vv_32, .-test_vmfle_vv_32

TEST_FUNC(test_vmfle_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vmfle.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vv_32_vm, .-test_vmfle_vv_32_vm

TEST_FUNC(test_vmfle_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vmfle.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vv_64, .-test_vmfle_vv_64

TEST_FUNC(test_vmfle_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmfle.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vv_64_vm, .-test_vmfle_vv_64_vm

/* vmfle.vf */
TEST_FUNC(test_vmfle_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmfle.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vf_16, .-test_vmfle_vf_16

TEST_FUNC(test_vmfle_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmfle.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vf_16_vm, .-test_vmfle_vf_16_vm

TEST_FUNC(test_vmfle_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmfle.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vf_32, .-test_vmfle_vf_32

TEST_FUNC(test_vmfle_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmfle.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vf_32_vm, .-test_vmfle_vf_32_vm

TEST_FUNC(test_vmfle_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmfle.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfle_vf_64, .-test_vmfle_vf_64

TEST_FUNC(test_vmfle_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmfle.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfle_vf_64_vm, .-test_vmfle_vf_64_vm

/* vmfgt.vf */
TEST_FUNC(test_vmfgt_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmfgt.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfgt_vf_16, .-test_vmfgt_vf_16

TEST_FUNC(test_vmfgt_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmfgt.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfgt_vf_16_vm, .-test_vmfgt_vf_16_vm

TEST_FUNC(test_vmfgt_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmfgt.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfgt_vf_32, .-test_vmfgt_vf_32

TEST_FUNC(test_vmfgt_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmfgt.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfgt_vf_32_vm, .-test_vmfgt_vf_32_vm

TEST_FUNC(test_vmfgt_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmfgt.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfgt_vf_64, .-test_vmfgt_vf_64

TEST_FUNC(test_vmfgt_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmfgt.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfgt_vf_64_vm, .-test_vmfgt_vf_64_vm

/* vmfge.vf */
TEST_FUNC(test_vmfge_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmfge.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfge_vf_16, .-test_vmfge_vf_16

TEST_FUNC(test_vmfge_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmfge.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfge_vf_16_vm, .-test_vmfge_vf_16_vm

TEST_FUNC(test_vmfge_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmfge.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfge_vf_32, .-test_vmfge_vf_32

TEST_FUNC(test_vmfge_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmfge.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfge_vf_32_vm, .-test_vmfge_vf_32_vm

TEST_FUNC(test_vmfge_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmfge.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmfge_vf_64, .-test_vmfge_vf_64

TEST_FUNC(test_vmfge_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmfge.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmfge_vf_64_vm, .-test_vmfge_vf_64_vm

/* vmford.vv */
TEST_FUNC(test_vmford_vv_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vmford.vv        v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vv_16, .-test_vmford_vv_16

TEST_FUNC(test_vmford_vv_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vmford.vv        v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vv_16_vm, .-test_vmford_vv_16_vm

TEST_FUNC(test_vmford_vv_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vmford.vv        v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vv_32, .-test_vmford_vv_32

TEST_FUNC(test_vmford_vv_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vlwu.v          v4, (a1)
        vmford.vv        v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vv_32_vm, .-test_vmford_vv_32_vm

TEST_FUNC(test_vmford_vv_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vmford.vv        v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vv_64, .-test_vmford_vv_64

TEST_FUNC(test_vmford_vv_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmford.vv        v6, v4, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vv_64_vm, .-test_vmford_vv_64_vm

/* vmford.vf */
TEST_FUNC(test_vmford_vf_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        fmv.d.x         fa0, a2
        vmford.vf        v4, v0, fa0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vf_16, .-test_vmford_vf_16

TEST_FUNC(test_vmford_vf_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        fmv.d.x         fa0, a1
        vmford.vf        v6, v2, fa0, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vf_16_vm, .-test_vmford_vf_16_vm

TEST_FUNC(test_vmford_vf_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        fmv.d.x         fa0, a2
        vmford.vf        v4, v0, fa0
        vsetvli         t1, x0, e32, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vf_32, .-test_vmford_vf_32

TEST_FUNC(test_vmford_vf_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        fmv.d.x         fa0, a1
        vmford.vf        v6, v2, fa0, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vf_32_vm, .-test_vmford_vf_32_vm

TEST_FUNC(test_vmford_vf_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        fmv.d.x         fa0, a2
        vmford.vf        v4, v0, fa0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vmford_vf_64, .-test_vmford_vf_64

TEST_FUNC(test_vmford_vf_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        fmv.d.x         fa0, a1
        vmford.vf        v6, v2, fa0, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vmford_vf_64_vm, .-test_vmford_vf_64_vm

/* vfclass.v */
TEST_FUNC(test_vfclass_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfclass.v        v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfclass_v_16, .-test_vfclass_v_16

TEST_FUNC(test_vfclass_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfclass.v        v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfclass_v_16_vm, .-test_vfclass_v_16_vm

TEST_FUNC(test_vfclass_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfclass.v        v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfclass_v_32, .-test_vfclass_v_32

TEST_FUNC(test_vfclass_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfclass.v        v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfclass_v_32_vm, .-test_vfclass_v_32_vm

TEST_FUNC(test_vfclass_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfclass.v        v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfclass_v_64, .-test_vfclass_v_64

TEST_FUNC(test_vfclass_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfclass.v        v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfclass_v_64_vm, .-test_vfclass_v_64_vm

/* vfcvt.xu.f.v */
TEST_FUNC(test_vfcvt_xu_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfcvt.xu.f.v    v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_16, .-test_vfcvt_xu_f_v_16

TEST_FUNC(test_vfcvt_xu_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfcvt.xu.f.v    v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_16_vm, .-test_vfcvt_xu_f_v_16_vm

TEST_FUNC(test_vfcvt_xu_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfcvt.xu.f.v    v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_32, .-test_vfcvt_xu_f_v_32

TEST_FUNC(test_vfcvt_xu_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfcvt.xu.f.v    v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_32_vm, .-test_vfcvt_xu_f_v_32_vm

TEST_FUNC(test_vfcvt_xu_f_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfcvt.xu.f.v    v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_64, .-test_vfcvt_xu_f_v_64

TEST_FUNC(test_vfcvt_xu_f_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfcvt.xu.f.v    v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_xu_f_v_64_vm, .-test_vfcvt_xu_f_v_64_vm

/* vfcvt.x.f.v */
TEST_FUNC(test_vfcvt_x_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfcvt.x.f.v    v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_16, .-test_vfcvt_x_f_v_16

TEST_FUNC(test_vfcvt_x_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfcvt.x.f.v    v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_16_vm, .-test_vfcvt_x_f_v_16_vm

TEST_FUNC(test_vfcvt_x_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfcvt.x.f.v    v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_32, .-test_vfcvt_x_f_v_32

TEST_FUNC(test_vfcvt_x_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfcvt.x.f.v    v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_32_vm, .-test_vfcvt_x_f_v_32_vm

TEST_FUNC(test_vfcvt_x_f_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfcvt.x.f.v    v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_64, .-test_vfcvt_x_f_v_64

TEST_FUNC(test_vfcvt_x_f_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfcvt.x.f.v    v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_x_f_v_64_vm, .-test_vfcvt_x_f_v_64_vm

/* vfcvt.f.xu.v */
TEST_FUNC(test_vfcvt_f_xu_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfcvt.f.xu.v    v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_16, .-test_vfcvt_f_xu_v_16

TEST_FUNC(test_vfcvt_f_xu_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfcvt.f.xu.v    v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_16_vm, .-test_vfcvt_f_xu_v_16_vm

TEST_FUNC(test_vfcvt_f_xu_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfcvt.f.xu.v    v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_32, .-test_vfcvt_f_xu_v_32

TEST_FUNC(test_vfcvt_f_xu_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfcvt.f.xu.v    v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_32_vm, .-test_vfcvt_f_xu_v_32_vm

TEST_FUNC(test_vfcvt_f_xu_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfcvt.f.xu.v    v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_64, .-test_vfcvt_f_xu_v_64

TEST_FUNC(test_vfcvt_f_xu_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfcvt.f.xu.v    v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_xu_v_64_vm, .-test_vfcvt_f_xu_v_64_vm

/* vfcvt.f.x.v */
TEST_FUNC(test_vfcvt_f_x_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfcvt.f.x.v    v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_16, .-test_vfcvt_f_x_v_16

TEST_FUNC(test_vfcvt_f_x_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vfcvt.f.x.v    v6, v2, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_16_vm, .-test_vfcvt_f_x_v_16_vm

TEST_FUNC(test_vfcvt_f_x_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfcvt.f.x.v    v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_32, .-test_vfcvt_f_x_v_32

TEST_FUNC(test_vfcvt_f_x_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vlwu.v          v6, (a4)
        vfcvt.f.x.v    v6, v2, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_32_vm, .-test_vfcvt_f_x_v_32_vm

TEST_FUNC(test_vfcvt_f_x_v_64)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vfcvt.f.x.v    v4, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_64, .-test_vfcvt_f_x_v_64

TEST_FUNC(test_vfcvt_f_x_v_64_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vfcvt.f.x.v    v6, v2, v0.t
        vse.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfcvt_f_x_v_64_vm, .-test_vfcvt_f_x_v_64_vm

/* vfwcvt.xu.f.v */
TEST_FUNC(test_vfwcvt_xu_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfwcvt.xu.f.v   v4, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_xu_f_v_16, .-test_vfwcvt_xu_f_v_16

TEST_FUNC(test_vfwcvt_xu_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vfwcvt.xu.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_xu_f_v_16_vm, .-test_vfwcvt_xu_f_v_16_vm

TEST_FUNC(test_vfwcvt_xu_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfwcvt.xu.f.v   v4, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_xu_f_v_32, .-test_vfwcvt_xu_f_v_32

TEST_FUNC(test_vfwcvt_xu_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vfwcvt.xu.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_xu_f_v_32_vm, .-test_vfwcvt_xu_f_v_32_vm

/* vfwcvt.x.f.v */
TEST_FUNC(test_vfwcvt_x_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfwcvt.x.f.v   v4, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_x_f_v_16, .-test_vfwcvt_x_f_v_16

TEST_FUNC(test_vfwcvt_x_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vfwcvt.x.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_x_f_v_16_vm, .-test_vfwcvt_x_f_v_16_vm

TEST_FUNC(test_vfwcvt_x_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfwcvt.x.f.v   v4, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_x_f_v_32, .-test_vfwcvt_x_f_v_32

TEST_FUNC(test_vfwcvt_x_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vfwcvt.x.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_x_f_v_32_vm, .-test_vfwcvt_x_f_v_32_vm

/* vfwcvt.f.xu.v */
TEST_FUNC(test_vfwcvt_f_xu_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfwcvt.f.xu.v   v4, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_xu_v_16, .-test_vfwcvt_f_xu_v_16

TEST_FUNC(test_vfwcvt_f_xu_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vfwcvt.f.xu.v   v8, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_xu_v_16_vm, .-test_vfwcvt_f_xu_v_16_vm

TEST_FUNC(test_vfwcvt_f_xu_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfwcvt.f.xu.v   v4, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_xu_v_32, .-test_vfwcvt_f_xu_v_32

TEST_FUNC(test_vfwcvt_f_xu_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vfwcvt.f.xu.v   v8, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_xu_v_32_vm, .-test_vfwcvt_f_xu_v_32_vm

/* vfwcvt.f.x.v */
TEST_FUNC(test_vfwcvt_f_x_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfwcvt.f.x.v   v4, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_x_v_16, .-test_vfwcvt_f_x_v_16

TEST_FUNC(test_vfwcvt_f_x_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vfwcvt.f.x.v   v8, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_x_v_16_vm, .-test_vfwcvt_f_x_v_16_vm

TEST_FUNC(test_vfwcvt_f_x_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfwcvt.f.x.v   v4, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_x_v_32, .-test_vfwcvt_f_x_v_32

TEST_FUNC(test_vfwcvt_f_x_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vfwcvt.f.x.v   v8, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_x_v_32_vm, .-test_vfwcvt_f_x_v_32_vm

/* vfwcvt.f.f.v */
TEST_FUNC(test_vfwcvt_f_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v0, (a1)
        vsetvli         t1, a0, e16, m2
        vfwcvt.f.f.v   v4, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_f_v_16, .-test_vfwcvt_f_f_v_16

TEST_FUNC(test_vfwcvt_f_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a4)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a0)
        vfwcvt.f.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_f_v_16_vm, .-test_vfwcvt_f_f_v_16_vm

TEST_FUNC(test_vfwcvt_f_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v0, (a1)
        vsetvli         t1, a0, e32, m2
        vfwcvt.f.f.v   v4, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfwcvt_f_f_v_32, .-test_vfwcvt_f_f_v_32

TEST_FUNC(test_vfwcvt_f_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a4)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a0)
        vfwcvt.f.f.v   v8, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        frflags         a0
        ret
        .size   test_vfwcvt_f_f_v_32_vm, .-test_vfwcvt_f_f_v_32_vm

/* vfncvt.xu.f.v */
TEST_FUNC(test_vfncvt_xu_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vfncvt.xu.f.v   v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_xu_f_v_16, .-test_vfncvt_xu_f_v_16

TEST_FUNC(test_vfncvt_xu_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vfncvt.xu.f.v   v6, v8, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_xu_f_v_16_vm, .-test_vfncvt_xu_f_v_16_vm

TEST_FUNC(test_vfncvt_xu_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vfncvt.xu.f.v   v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_xu_f_v_32, .-test_vfncvt_xu_f_v_32

TEST_FUNC(test_vfncvt_xu_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vfncvt.xu.f.v   v6, v8, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_xu_f_v_32_vm, .-test_vfncvt_xu_f_v_32_vm

/* vfncvt.x.f.v */
TEST_FUNC(test_vfncvt_x_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vfncvt.x.f.v   v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_x_f_v_16, .-test_vfncvt_x_f_v_16

TEST_FUNC(test_vfncvt_x_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vfncvt.x.f.v   v6, v8, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_x_f_v_16_vm, .-test_vfncvt_x_f_v_16_vm

TEST_FUNC(test_vfncvt_x_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vfncvt.x.f.v   v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_x_f_v_32, .-test_vfncvt_x_f_v_32

TEST_FUNC(test_vfncvt_x_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vfncvt.x.f.v   v6, v8, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_x_f_v_32_vm, .-test_vfncvt_x_f_v_32_vm

/* vfncvt.f.xu.v */
TEST_FUNC(test_vfncvt_f_xu_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vfncvt.f.xu.v   v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_xu_v_16, .-test_vfncvt_f_xu_v_16

TEST_FUNC(test_vfncvt_f_xu_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vfncvt.f.xu.v   v6, v8, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_xu_v_16_vm, .-test_vfncvt_f_xu_v_16_vm

TEST_FUNC(test_vfncvt_f_xu_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vfncvt.f.xu.v   v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_xu_v_32, .-test_vfncvt_f_xu_v_32

TEST_FUNC(test_vfncvt_f_xu_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vfncvt.f.xu.v   v6, v8, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_xu_v_32_vm, .-test_vfncvt_f_xu_v_32_vm

/* vfncvt.f.x.v */
TEST_FUNC(test_vfncvt_f_x_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vfncvt.f.x.v   v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_x_v_16, .-test_vfncvt_f_x_v_16

TEST_FUNC(test_vfncvt_f_x_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vfncvt.f.x.v   v6, v8, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_x_v_16_vm, .-test_vfncvt_f_x_v_16_vm

TEST_FUNC(test_vfncvt_f_x_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vfncvt.f.x.v   v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_x_v_32, .-test_vfncvt_f_x_v_32

TEST_FUNC(test_vfncvt_f_x_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vfncvt.f.x.v   v6, v8, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_x_v_32_vm, .-test_vfncvt_f_x_v_32_vm

/* vfncvt.f.f.v */
TEST_FUNC(test_vfncvt_f_f_v_16)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vfncvt.f.f.v   v4, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_f_v_16, .-test_vfncvt_f_f_v_16

TEST_FUNC(test_vfncvt_f_f_v_16_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vfncvt.f.f.v   v6, v8, v0.t
        vsh.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_f_v_16_vm, .-test_vfncvt_f_f_v_16_vm

TEST_FUNC(test_vfncvt_f_f_v_32)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vfncvt.f.f.v   v4, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        frflags         a0
        ret
        .size   test_vfncvt_f_f_v_32, .-test_vfncvt_f_f_v_32

TEST_FUNC(test_vfncvt_f_f_v_32_vm)
        fsflagsi        0x0
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vfncvt.f.f.v   v6, v8, v0.t
        vsw.v           v6, (a2)
        frflags         a0
        ret
        .size   test_vfncvt_f_f_v_32_vm, .-test_vfncvt_f_f_v_32_vm

