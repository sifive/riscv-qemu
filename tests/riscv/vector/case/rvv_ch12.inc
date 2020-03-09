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



/* vmv.v.i */
TEST_FUNC(test_vmv_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmv.v.i        v6, -16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmv_vi_8, .-test_vmv_vi_8

TEST_FUNC(test_vmv_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmv.v.i         v6, 15
        vsb.v           v6, (a1)
        ret
        .size   test_vmv_vi_8_vm, .-test_vmv_vi_8_vm
TEST_FUNC(test_vmv_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmv.v.i        v6, -16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmv_vi_16, .-test_vmv_vi_16

TEST_FUNC(test_vmv_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmv.v.i        v6, 15
        vsh.v           v6, (a1)
        ret
        .size   test_vmv_vi_16_vm, .-test_vmv_vi_16_vm

TEST_FUNC(test_vmv_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmv.v.i        v6, -16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmv_vi_32, .-test_vmv_vi_32

TEST_FUNC(test_vmv_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmv.v.i        v6, 15
        vsw.v           v6, (a1)
        ret
        .size   test_vmv_vi_32_vm, .-test_vmv_vi_32_vm

TEST_FUNC(test_vmv_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmv.v.i        v6, -16 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmv_vi_64, .-test_vmv_vi_64

TEST_FUNC(test_vmv_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmv.v.i         v6, 15
        vse.v           v6, (a1)
        ret
        .size   test_vmv_vi_64_vm, .-test_vmv_vi_64_vm


/* vmv.v.x */
TEST_FUNC(test_vmv_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmv.v.x        v6, a2 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmv_vx_8, .-test_vmv_vx_8

TEST_FUNC(test_vmv_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmv.v.x         v6, a1
        vsb.v           v6, (a2)
        ret
        .size   test_vmv_vx_8_vm, .-test_vmv_vx_8_vm
TEST_FUNC(test_vmv_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmv.v.x        v6, a2 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmv_vx_16, .-test_vmv_vx_16

TEST_FUNC(test_vmv_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmv.v.x        v6, a1
        vsh.v           v6, (a2)
        ret
        .size   test_vmv_vx_16_vm, .-test_vmv_vx_16_vm

TEST_FUNC(test_vmv_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmv.v.x        v6, a2 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmv_vx_32, .-test_vmv_vx_32

TEST_FUNC(test_vmv_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmv.v.x        v6, a1
        vsw.v           v6, (a2)
        ret
        .size   test_vmv_vx_32_vm, .-test_vmv_vx_32_vm

TEST_FUNC(test_vmv_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmv.v.x        v6, a2 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmv_vx_64, .-test_vmv_vx_64

TEST_FUNC(test_vmv_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmv.v.x         v6, a1
        vse.v           v6, (a2)
        ret
        .size   test_vmv_vx_64_vm, .-test_vmv_vx_64_vm


/* vmv.v.v */
TEST_FUNC(test_vmv_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmv.v.v        v6, v4 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmv_vv_8, .-test_vmv_vv_8

TEST_FUNC(test_vmv_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmv.v.v         v6, v4
        vsb.v           v6, (a2)
        ret
        .size   test_vmv_vv_8_vm, .-test_vmv_vv_8_vm

TEST_FUNC(test_vmv_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmv.v.v       v6, v4 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmv_vv_16, .-test_vmv_vv_16

TEST_FUNC(test_vmv_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmv.v.v       v6, v4
        vsh.v           v6, (a2)
        ret
        .size   test_vmv_vv_16_vm, .-test_vmv_vv_16_vm

TEST_FUNC(test_vmv_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmv.v.v        v6, v4 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmv_vv_32, .-test_vmv_vv_32

TEST_FUNC(test_vmv_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmv.v.v         v6, v4
        vsw.v           v6, (a2)
        ret
        .size   test_vmv_vv_32_vm, .-test_vmv_vv_32_vm

TEST_FUNC(test_vmv_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmv.v.v        v6, v4 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmv_vv_64, .-test_vmv_vv_64

TEST_FUNC(test_vmv_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmv.v.v         v6, v4
        vse.v           v6, (a2)
        ret
        .size   test_vmv_vv_64_vm, .-test_vmv_vv_64_vm




/* vmerge.vim */
TEST_FUNC(test_vmerge_vim_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmerge.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmerge_vim_8, .-test_vmerge_vim_8

TEST_FUNC(test_vmerge_vim_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmerge.vim         v6, v2, 15, v0
        vsb.v           v6, (a1)
        ret
        .size   test_vmerge_vim_8_vm, .-test_vmerge_vim_8_vm
TEST_FUNC(test_vmerge_vim_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmerge.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmerge_vim_16, .-test_vmerge_vim_16

TEST_FUNC(test_vmerge_vim_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmerge.vim        v6, v2, 15, v0
        vsh.v           v6, (a1)
        ret
        .size   test_vmerge_vim_16_vm, .-test_vmerge_vim_16_vm

TEST_FUNC(test_vmerge_vim_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmerge.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmerge_vim_32, .-test_vmerge_vim_32

TEST_FUNC(test_vmerge_vim_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmerge.vim        v6, v2, 15, v0
        vsw.v           v6, (a1)
        ret
        .size   test_vmerge_vim_32_vm, .-test_vmerge_vim_32_vm

TEST_FUNC(test_vmerge_vim_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmerge.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmerge_vim_64, .-test_vmerge_vim_64

TEST_FUNC(test_vmerge_vim_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmerge.vim         v6, v2, 15, v0
        vse.v           v6, (a1)
        ret
        .size   test_vmerge_vim_64_vm, .-test_vmerge_vim_64_vm


/* vmerge.vxm */
TEST_FUNC(test_vmerge_vxm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmerge.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmerge_vxm_8, .-test_vmerge_vxm_8

TEST_FUNC(test_vmerge_vxm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmerge.vxm         v6, v2, a1, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmerge_vxm_8_vm, .-test_vmerge_vxm_8_vm
TEST_FUNC(test_vmerge_vxm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmerge.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmerge_vxm_16, .-test_vmerge_vxm_16

TEST_FUNC(test_vmerge_vxm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmerge.vxm        v6, v2, a1, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmerge_vxm_16_vm, .-test_vmerge_vxm_16_vm

TEST_FUNC(test_vmerge_vxm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmerge.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmerge_vxm_32, .-test_vmerge_vxm_32

TEST_FUNC(test_vmerge_vxm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmerge.vxm        v6, v2, a1, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmerge_vxm_32_vm, .-test_vmerge_vxm_32_vm

TEST_FUNC(test_vmerge_vxm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmerge.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmerge_vxm_64, .-test_vmerge_vxm_64

TEST_FUNC(test_vmerge_vxm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmerge.vxm         v6, v2, a1, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmerge_vxm_64_vm, .-test_vmerge_vxm_64_vm


/* vmerge.vvm */
TEST_FUNC(test_vmerge_vvm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmerge.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmerge_vvm_8, .-test_vmerge_vvm_8

TEST_FUNC(test_vmerge_vvm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmerge.vvm         v6, v2, v4, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmerge_vvm_8_vm, .-test_vmerge_vvm_8_vm

TEST_FUNC(test_vmerge_vvm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmerge.vvm       v6, v2, v4, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmerge_vvm_16, .-test_vmerge_vvm_16

TEST_FUNC(test_vmerge_vvm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmerge.vvm       v6, v2, v4, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmerge_vvm_16_vm, .-test_vmerge_vvm_16_vm

TEST_FUNC(test_vmerge_vvm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmerge.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmerge_vvm_32, .-test_vmerge_vvm_32

TEST_FUNC(test_vmerge_vvm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmerge.vvm         v6, v2, v4, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmerge_vvm_32_vm, .-test_vmerge_vvm_32_vm

TEST_FUNC(test_vmerge_vvm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmerge.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmerge_vvm_64, .-test_vmerge_vvm_64

TEST_FUNC(test_vmerge_vvm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmerge.vvm         v6, v2, v4, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmerge_vvm_64_vm, .-test_vmerge_vvm_64_vm



/* vwmaccus.vx */
TEST_FUNC(test_vwmaccus_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmaccus.vx       v8, a2, v0 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccus_vx_8, .-test_vwmaccus_vx_8

TEST_FUNC(test_vwmaccus_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmaccus.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccus_vx_8_vm, .-test_vwmaccus_vx_8_vm

TEST_FUNC(test_vwmaccus_vx_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmaccus.vx       v8, a2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccus_vx_16, .-test_vwmaccus_vx_16

TEST_FUNC(test_vwmaccus_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmaccus.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccus_vx_16_vm, .-test_vwmaccus_vx_16_vm

TEST_FUNC(test_vwmaccus_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmaccus.vx       v8, a2, v0 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccus_vx_32, .-test_vwmaccus_vx_32

TEST_FUNC(test_vwmaccus_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmaccus.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccus_vx_32_vm, .-test_vwmaccus_vx_32_vm


/* vwmaccsu.vx */
TEST_FUNC(test_vwmaccsu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmaccsu.vx       v8, a2, v0 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vx_8, .-test_vwmaccsu_vx_8

TEST_FUNC(test_vwmaccsu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmaccsu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vx_8_vm, .-test_vwmaccsu_vx_8_vm

TEST_FUNC(test_vwmaccsu_vx_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmaccsu.vx       v8, a2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vx_16, .-test_vwmaccsu_vx_16

TEST_FUNC(test_vwmaccsu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmaccsu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vx_16_vm, .-test_vwmaccsu_vx_16_vm

TEST_FUNC(test_vwmaccsu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmaccsu.vx       v8, a2, v0 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vx_32, .-test_vwmaccsu_vx_32

TEST_FUNC(test_vwmaccsu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmaccsu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vx_32_vm, .-test_vwmaccsu_vx_32_vm


/* vwmaccsu.vv */
TEST_FUNC(test_vwmaccsu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmaccsu.vv       v8, v2, v0
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vv_8, .-test_vwmaccsu_vv_8

TEST_FUNC(test_vwmaccsu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmaccsu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vv_8_vm, .-test_vwmaccsu_vv_8_vm

TEST_FUNC(test_vwmaccsu_vv_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmaccsu.vv       v8, v2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vv_16, .-test_vwmaccsu_vv_16

TEST_FUNC(test_vwmaccsu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmaccsu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vv_16_vm, .-test_vwmaccsu_vv_16_vm

TEST_FUNC(test_vwmaccsu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmaccsu.vv       v8, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccsu_vv_32, .-test_vwmaccsu_vv_32

TEST_FUNC(test_vwmaccsu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmaccsu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccsu_vv_32_vm, .-test_vwmaccsu_vv_32_vm


/* vwmaccu.vx */
TEST_FUNC(test_vwmaccu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmaccu.vx       v8, a2, v0 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vx_8, .-test_vwmaccu_vx_8

TEST_FUNC(test_vwmaccu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmaccu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vx_8_vm, .-test_vwmaccu_vx_8_vm

TEST_FUNC(test_vwmaccu_vx_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmaccu.vx       v8, a2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vx_16, .-test_vwmaccu_vx_16

TEST_FUNC(test_vwmaccu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmaccu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vx_16_vm, .-test_vwmaccu_vx_16_vm

TEST_FUNC(test_vwmaccu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmaccu.vx       v8, a2, v0 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vx_32, .-test_vwmaccu_vx_32

TEST_FUNC(test_vwmaccu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmaccu.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vx_32_vm, .-test_vwmaccu_vx_32_vm


/* vwmaccu.vv */
TEST_FUNC(test_vwmaccu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmaccu.vv       v8, v2, v0
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vv_8, .-test_vwmaccu_vv_8

TEST_FUNC(test_vwmaccu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmaccu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vv_8_vm, .-test_vwmaccu_vv_8_vm

TEST_FUNC(test_vwmaccu_vv_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmaccu.vv       v8, v2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vv_16, .-test_vwmaccu_vv_16

TEST_FUNC(test_vwmaccu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmaccu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vv_16_vm, .-test_vwmaccu_vv_16_vm

TEST_FUNC(test_vwmaccu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmaccu.vv       v8, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmaccu_vv_32, .-test_vwmaccu_vv_32

TEST_FUNC(test_vwmaccu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmaccu.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmaccu_vv_32_vm, .-test_vwmaccu_vv_32_vm


/* vwmacc.vx */
TEST_FUNC(test_vwmacc_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmacc.vx       v8, a2, v0 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vx_8, .-test_vwmacc_vx_8

TEST_FUNC(test_vwmacc_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmacc.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vx_8_vm, .-test_vwmacc_vx_8_vm

TEST_FUNC(test_vwmacc_vx_16)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmacc.vx       v8, a2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vx_16, .-test_vwmacc_vx_16

TEST_FUNC(test_vwmacc_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmacc.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vx_16_vm, .-test_vwmacc_vx_16_vm

TEST_FUNC(test_vwmacc_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmacc.vx       v8, a2, v0 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vx_32, .-test_vwmacc_vx_32

TEST_FUNC(test_vwmacc_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmacc.vx       v8, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vx_32_vm, .-test_vwmacc_vx_32_vm


/* vwmacc.vv */
TEST_FUNC(test_vwmacc_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmacc.vv       v8, v2, v0
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vv_8, .-test_vwmacc_vv_8

TEST_FUNC(test_vwmacc_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vv_8_vm, .-test_vwmacc_vv_8_vm

TEST_FUNC(test_vwmacc_vv_16)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a4)
        vsw.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmacc.vv       v8, v2, v0
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vv_16, .-test_vwmacc_vv_16

TEST_FUNC(test_vwmacc_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vv_16_vm, .-test_vwmacc_vv_16_vm

TEST_FUNC(test_vwmacc_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmacc.vv       v8, v2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmacc_vv_32, .-test_vwmacc_vv_32

TEST_FUNC(test_vwmacc_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmacc.vv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmacc_vv_32_vm, .-test_vwmacc_vv_32_vm


/* vnmsub.vx */
TEST_FUNC(test_vnmsub_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vnmsub.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vnmsub_vx_8, .-test_vnmsub_vx_8

TEST_FUNC(test_vnmsub_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vnmsub.vx         v6, a1, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnmsub_vx_8_vm, .-test_vnmsub_vx_8_vm
TEST_FUNC(test_vnmsub_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vnmsub.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vnmsub_vx_16, .-test_vnmsub_vx_16

TEST_FUNC(test_vnmsub_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vnmsub.vx        v6, a1, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnmsub_vx_16_vm, .-test_vnmsub_vx_16_vm

TEST_FUNC(test_vnmsub_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vnmsub.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vnmsub_vx_32, .-test_vnmsub_vx_32

TEST_FUNC(test_vnmsub_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vnmsub.vx        v6, a1, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnmsub_vx_32_vm, .-test_vnmsub_vx_32_vm

TEST_FUNC(test_vnmsub_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vnmsub.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vnmsub_vx_64, .-test_vnmsub_vx_64

TEST_FUNC(test_vnmsub_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vnmsub.vx         v6, a1, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vnmsub_vx_64_vm, .-test_vnmsub_vx_64_vm


/* vnmsub.vv */
TEST_FUNC(test_vnmsub_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vnmsub.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vnmsub_vv_8, .-test_vnmsub_vv_8

TEST_FUNC(test_vnmsub_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vnmsub.vv         v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnmsub_vv_8_vm, .-test_vnmsub_vv_8_vm

TEST_FUNC(test_vnmsub_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vnmsub.vv       v6, v4, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vnmsub_vv_16, .-test_vnmsub_vv_16

TEST_FUNC(test_vnmsub_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vnmsub.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnmsub_vv_16_vm, .-test_vnmsub_vv_16_vm

TEST_FUNC(test_vnmsub_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vnmsub.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vnmsub_vv_32, .-test_vnmsub_vv_32

TEST_FUNC(test_vnmsub_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vnmsub.vv         v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnmsub_vv_32_vm, .-test_vnmsub_vv_32_vm

TEST_FUNC(test_vnmsub_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vnmsub.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vnmsub_vv_64, .-test_vnmsub_vv_64

TEST_FUNC(test_vnmsub_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vnmsub.vv         v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vnmsub_vv_64_vm, .-test_vnmsub_vv_64_vm


/* vmadd.vx */
TEST_FUNC(test_vmadd_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmadd.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmadd_vx_8, .-test_vmadd_vx_8

TEST_FUNC(test_vmadd_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmadd.vx         v6, a1, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmadd_vx_8_vm, .-test_vmadd_vx_8_vm
TEST_FUNC(test_vmadd_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmadd.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmadd_vx_16, .-test_vmadd_vx_16

TEST_FUNC(test_vmadd_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmadd.vx        v6, a1, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmadd_vx_16_vm, .-test_vmadd_vx_16_vm

TEST_FUNC(test_vmadd_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmadd.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmadd_vx_32, .-test_vmadd_vx_32

TEST_FUNC(test_vmadd_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmadd.vx        v6, a1, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmadd_vx_32_vm, .-test_vmadd_vx_32_vm

TEST_FUNC(test_vmadd_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmadd.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmadd_vx_64, .-test_vmadd_vx_64

TEST_FUNC(test_vmadd_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmadd.vx         v6, a1, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmadd_vx_64_vm, .-test_vmadd_vx_64_vm


/* vmadd.vv */
TEST_FUNC(test_vmadd_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmadd.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmadd_vv_8, .-test_vmadd_vv_8

TEST_FUNC(test_vmadd_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmadd.vv         v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmadd_vv_8_vm, .-test_vmadd_vv_8_vm

TEST_FUNC(test_vmadd_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmadd.vv       v6, v4, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmadd_vv_16, .-test_vmadd_vv_16

TEST_FUNC(test_vmadd_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmadd.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmadd_vv_16_vm, .-test_vmadd_vv_16_vm

TEST_FUNC(test_vmadd_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmadd.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmadd_vv_32, .-test_vmadd_vv_32

TEST_FUNC(test_vmadd_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmadd.vv         v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmadd_vv_32_vm, .-test_vmadd_vv_32_vm

TEST_FUNC(test_vmadd_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmadd.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmadd_vv_64, .-test_vmadd_vv_64

TEST_FUNC(test_vmadd_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmadd.vv         v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmadd_vv_64_vm, .-test_vmadd_vv_64_vm


/* vnmsac.vx */
TEST_FUNC(test_vnmsac_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vnmsac.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vnmsac_vx_8, .-test_vnmsac_vx_8

TEST_FUNC(test_vnmsac_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vnmsac.vx         v6, a1, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnmsac_vx_8_vm, .-test_vnmsac_vx_8_vm
TEST_FUNC(test_vnmsac_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vnmsac.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vnmsac_vx_16, .-test_vnmsac_vx_16

TEST_FUNC(test_vnmsac_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vnmsac.vx        v6, a1, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnmsac_vx_16_vm, .-test_vnmsac_vx_16_vm

TEST_FUNC(test_vnmsac_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vnmsac.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vnmsac_vx_32, .-test_vnmsac_vx_32

TEST_FUNC(test_vnmsac_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vnmsac.vx        v6, a1, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnmsac_vx_32_vm, .-test_vnmsac_vx_32_vm

TEST_FUNC(test_vnmsac_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vnmsac.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vnmsac_vx_64, .-test_vnmsac_vx_64

TEST_FUNC(test_vnmsac_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vnmsac.vx         v6, a1, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vnmsac_vx_64_vm, .-test_vnmsac_vx_64_vm


/* vnmsac.vv */
TEST_FUNC(test_vnmsac_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vnmsac.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vnmsac_vv_8, .-test_vnmsac_vv_8

TEST_FUNC(test_vnmsac_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vnmsac.vv         v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnmsac_vv_8_vm, .-test_vnmsac_vv_8_vm

TEST_FUNC(test_vnmsac_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vnmsac.vv       v6, v4, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vnmsac_vv_16, .-test_vnmsac_vv_16

TEST_FUNC(test_vnmsac_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vnmsac.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnmsac_vv_16_vm, .-test_vnmsac_vv_16_vm

TEST_FUNC(test_vnmsac_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vnmsac.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vnmsac_vv_32, .-test_vnmsac_vv_32

TEST_FUNC(test_vnmsac_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vnmsac.vv         v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnmsac_vv_32_vm, .-test_vnmsac_vv_32_vm

TEST_FUNC(test_vnmsac_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vnmsac.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vnmsac_vv_64, .-test_vnmsac_vv_64

TEST_FUNC(test_vnmsac_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vnmsac.vv         v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vnmsac_vv_64_vm, .-test_vnmsac_vv_64_vm


/* vmacc.vx */
TEST_FUNC(test_vmacc_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmacc.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmacc_vx_8, .-test_vmacc_vx_8

TEST_FUNC(test_vmacc_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmacc.vx         v6, a1, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmacc_vx_8_vm, .-test_vmacc_vx_8_vm
TEST_FUNC(test_vmacc_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmacc.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmacc_vx_16, .-test_vmacc_vx_16

TEST_FUNC(test_vmacc_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmacc.vx        v6, a1, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmacc_vx_16_vm, .-test_vmacc_vx_16_vm

TEST_FUNC(test_vmacc_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmacc.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmacc_vx_32, .-test_vmacc_vx_32

TEST_FUNC(test_vmacc_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmacc.vx        v6, a1, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmacc_vx_32_vm, .-test_vmacc_vx_32_vm

TEST_FUNC(test_vmacc_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmacc.vx        v6, a2, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmacc_vx_64, .-test_vmacc_vx_64

TEST_FUNC(test_vmacc_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmacc.vx         v6, a1, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmacc_vx_64_vm, .-test_vmacc_vx_64_vm


/* vmacc.vv */
TEST_FUNC(test_vmacc_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmacc.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmacc_vv_8, .-test_vmacc_vv_8

TEST_FUNC(test_vmacc_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmacc.vv         v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmacc_vv_8_vm, .-test_vmacc_vv_8_vm

TEST_FUNC(test_vmacc_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmacc.vv       v6, v4, v2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmacc_vv_16, .-test_vmacc_vv_16

TEST_FUNC(test_vmacc_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmacc.vv       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmacc_vv_16_vm, .-test_vmacc_vv_16_vm

TEST_FUNC(test_vmacc_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmacc.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmacc_vv_32, .-test_vmacc_vv_32

TEST_FUNC(test_vmacc_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmacc.vv         v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmacc_vv_32_vm, .-test_vmacc_vv_32_vm

TEST_FUNC(test_vmacc_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmacc.vv        v6, v4, v2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmacc_vv_64, .-test_vmacc_vv_64

TEST_FUNC(test_vmacc_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmacc.vv         v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmacc_vv_64_vm, .-test_vmacc_vv_64_vm


/* vwmulsu.vx */
TEST_FUNC(test_vwmulsu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmulsu.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vx_8, .-test_vwmulsu_vx_8

TEST_FUNC(test_vwmulsu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmulsu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vx_8_vm, .-test_vwmulsu_vx_8_vm

TEST_FUNC(test_vwmulsu_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmulsu.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vx_16, .-test_vwmulsu_vx_16

TEST_FUNC(test_vwmulsu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmulsu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vx_16_vm, .-test_vwmulsu_vx_16_vm

TEST_FUNC(test_vwmulsu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmulsu.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vx_32, .-test_vwmulsu_vx_32

TEST_FUNC(test_vwmulsu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmulsu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vx_32_vm, .-test_vwmulsu_vx_32_vm

/* vwmulsu.vv */
TEST_FUNC(test_vwmulsu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmulsu.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vv_8, .-test_vwmulsu_vv_8

TEST_FUNC(test_vwmulsu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmulsu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vv_8_vm, .-test_vwmulsu_vv_8_vm

TEST_FUNC(test_vwmulsu_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmulsu.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vv_16, .-test_vwmulsu_vv_16

TEST_FUNC(test_vwmulsu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmulsu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vv_16_vm, .-test_vwmulsu_vv_16_vm

TEST_FUNC(test_vwmulsu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmulsu.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulsu_vv_32, .-test_vwmulsu_vv_32

TEST_FUNC(test_vwmulsu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmulsu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulsu_vv_32_vm, .-test_vwmulsu_vv_32_vm

/* vwmul.vx */
TEST_FUNC(test_vwmul_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmul.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vx_8, .-test_vwmul_vx_8

TEST_FUNC(test_vwmul_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmul.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vx_8_vm, .-test_vwmul_vx_8_vm

TEST_FUNC(test_vwmul_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmul.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vx_16, .-test_vwmul_vx_16

TEST_FUNC(test_vwmul_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmul.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vx_16_vm, .-test_vwmul_vx_16_vm

TEST_FUNC(test_vwmul_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmul.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vx_32, .-test_vwmul_vx_32

TEST_FUNC(test_vwmul_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmul.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vx_32_vm, .-test_vwmul_vx_32_vm

/* vwmul.vv */
TEST_FUNC(test_vwmul_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmul.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vv_8, .-test_vwmul_vv_8

TEST_FUNC(test_vwmul_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmul.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vv_8_vm, .-test_vwmul_vv_8_vm

TEST_FUNC(test_vwmul_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmul.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vv_16, .-test_vwmul_vv_16

TEST_FUNC(test_vwmul_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmul.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vv_16_vm, .-test_vwmul_vv_16_vm

TEST_FUNC(test_vwmul_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmul.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmul_vv_32, .-test_vwmul_vv_32

TEST_FUNC(test_vwmul_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmul.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmul_vv_32_vm, .-test_vwmul_vv_32_vm



/* vwmulu.vx */
TEST_FUNC(test_vwmulu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwmulu.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vx_8, .-test_vwmulu_vx_8

TEST_FUNC(test_vwmulu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwmulu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vx_8_vm, .-test_vwmulu_vx_8_vm

TEST_FUNC(test_vwmulu_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwmulu.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vx_16, .-test_vwmulu_vx_16

TEST_FUNC(test_vwmulu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwmulu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vx_16_vm, .-test_vwmulu_vx_16_vm

TEST_FUNC(test_vwmulu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwmulu.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vx_32, .-test_vwmulu_vx_32

TEST_FUNC(test_vwmulu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwmulu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vx_32_vm, .-test_vwmulu_vx_32_vm

/* vwmulu.vv */
TEST_FUNC(test_vwmulu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwmulu.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vv_8, .-test_vwmulu_vv_8

TEST_FUNC(test_vwmulu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwmulu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vv_8_vm, .-test_vwmulu_vv_8_vm

TEST_FUNC(test_vwmulu_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwmulu.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vv_16, .-test_vwmulu_vv_16

TEST_FUNC(test_vwmulu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwmulu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vv_16_vm, .-test_vwmulu_vv_16_vm

TEST_FUNC(test_vwmulu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwmulu.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwmulu_vv_32, .-test_vwmulu_vv_32

TEST_FUNC(test_vwmulu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwmulu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwmulu_vv_32_vm, .-test_vwmulu_vv_32_vm

/* vremu.vx */
TEST_FUNC(test_vremu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vremu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vremu_vx_8, .-test_vremu_vx_8

TEST_FUNC(test_vremu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vremu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vremu_vx_8_vm, .-test_vremu_vx_8_vm
TEST_FUNC(test_vremu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vremu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vremu_vx_16, .-test_vremu_vx_16

TEST_FUNC(test_vremu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vremu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vremu_vx_16_vm, .-test_vremu_vx_16_vm

TEST_FUNC(test_vremu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vremu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vremu_vx_32, .-test_vremu_vx_32

TEST_FUNC(test_vremu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vremu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vremu_vx_32_vm, .-test_vremu_vx_32_vm

TEST_FUNC(test_vremu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vremu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vremu_vx_64, .-test_vremu_vx_64

TEST_FUNC(test_vremu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vremu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vremu_vx_64_vm, .-test_vremu_vx_64_vm


/* vremu.vv */
TEST_FUNC(test_vremu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vremu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vremu_vv_8, .-test_vremu_vv_8

TEST_FUNC(test_vremu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vremu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vremu_vv_8_vm, .-test_vremu_vv_8_vm

TEST_FUNC(test_vremu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vremu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vremu_vv_16, .-test_vremu_vv_16

TEST_FUNC(test_vremu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vremu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vremu_vv_16_vm, .-test_vremu_vv_16_vm

TEST_FUNC(test_vremu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vremu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vremu_vv_32, .-test_vremu_vv_32

TEST_FUNC(test_vremu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vremu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vremu_vv_32_vm, .-test_vremu_vv_32_vm

TEST_FUNC(test_vremu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vremu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vremu_vv_64, .-test_vremu_vv_64

TEST_FUNC(test_vremu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vremu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vremu_vv_64_vm, .-test_vremu_vv_64_vm



/* vrem.vx */
TEST_FUNC(test_vrem_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vrem.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vrem_vx_8, .-test_vrem_vx_8

TEST_FUNC(test_vrem_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vrem.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vrem_vx_8_vm, .-test_vrem_vx_8_vm
TEST_FUNC(test_vrem_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vrem.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vrem_vx_16, .-test_vrem_vx_16

TEST_FUNC(test_vrem_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vrem.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vrem_vx_16_vm, .-test_vrem_vx_16_vm

TEST_FUNC(test_vrem_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vrem.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vrem_vx_32, .-test_vrem_vx_32

TEST_FUNC(test_vrem_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vrem.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vrem_vx_32_vm, .-test_vrem_vx_32_vm

TEST_FUNC(test_vrem_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vrem.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vrem_vx_64, .-test_vrem_vx_64

TEST_FUNC(test_vrem_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vrem.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vrem_vx_64_vm, .-test_vrem_vx_64_vm


/* vrem.vv */
TEST_FUNC(test_vrem_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vrem.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vrem_vv_8, .-test_vrem_vv_8

TEST_FUNC(test_vrem_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vrem.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vrem_vv_8_vm, .-test_vrem_vv_8_vm

TEST_FUNC(test_vrem_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vrem.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vrem_vv_16, .-test_vrem_vv_16

TEST_FUNC(test_vrem_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vrem.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vrem_vv_16_vm, .-test_vrem_vv_16_vm

TEST_FUNC(test_vrem_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vrem.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vrem_vv_32, .-test_vrem_vv_32

TEST_FUNC(test_vrem_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vrem.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vrem_vv_32_vm, .-test_vrem_vv_32_vm

TEST_FUNC(test_vrem_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vrem.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vrem_vv_64, .-test_vrem_vv_64

TEST_FUNC(test_vrem_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vrem.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vrem_vv_64_vm, .-test_vrem_vv_64_vm


/* vdivu.vx */
TEST_FUNC(test_vdivu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vdivu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vdivu_vx_8, .-test_vdivu_vx_8

TEST_FUNC(test_vdivu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vdivu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vdivu_vx_8_vm, .-test_vdivu_vx_8_vm
TEST_FUNC(test_vdivu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vdivu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vdivu_vx_16, .-test_vdivu_vx_16

TEST_FUNC(test_vdivu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vdivu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vdivu_vx_16_vm, .-test_vdivu_vx_16_vm

TEST_FUNC(test_vdivu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vdivu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vdivu_vx_32, .-test_vdivu_vx_32

TEST_FUNC(test_vdivu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vdivu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vdivu_vx_32_vm, .-test_vdivu_vx_32_vm

TEST_FUNC(test_vdivu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vdivu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vdivu_vx_64, .-test_vdivu_vx_64

TEST_FUNC(test_vdivu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vdivu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vdivu_vx_64_vm, .-test_vdivu_vx_64_vm


/* vdivu.vv */
TEST_FUNC(test_vdivu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vdivu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vdivu_vv_8, .-test_vdivu_vv_8

TEST_FUNC(test_vdivu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vdivu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vdivu_vv_8_vm, .-test_vdivu_vv_8_vm

TEST_FUNC(test_vdivu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vdivu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vdivu_vv_16, .-test_vdivu_vv_16

TEST_FUNC(test_vdivu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vdivu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vdivu_vv_16_vm, .-test_vdivu_vv_16_vm

TEST_FUNC(test_vdivu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vdivu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vdivu_vv_32, .-test_vdivu_vv_32

TEST_FUNC(test_vdivu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vdivu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vdivu_vv_32_vm, .-test_vdivu_vv_32_vm

TEST_FUNC(test_vdivu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vdivu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vdivu_vv_64, .-test_vdivu_vv_64

TEST_FUNC(test_vdivu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vdivu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vdivu_vv_64_vm, .-test_vdivu_vv_64_vm



/* vdiv.vx */
TEST_FUNC(test_vdiv_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vdiv.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vdiv_vx_8, .-test_vdiv_vx_8

TEST_FUNC(test_vdiv_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vdiv.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vdiv_vx_8_vm, .-test_vdiv_vx_8_vm
TEST_FUNC(test_vdiv_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vdiv.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vdiv_vx_16, .-test_vdiv_vx_16

TEST_FUNC(test_vdiv_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vdiv.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vdiv_vx_16_vm, .-test_vdiv_vx_16_vm

TEST_FUNC(test_vdiv_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vdiv.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vdiv_vx_32, .-test_vdiv_vx_32

TEST_FUNC(test_vdiv_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vdiv.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vdiv_vx_32_vm, .-test_vdiv_vx_32_vm

TEST_FUNC(test_vdiv_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vdiv.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vdiv_vx_64, .-test_vdiv_vx_64

TEST_FUNC(test_vdiv_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vdiv.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vdiv_vx_64_vm, .-test_vdiv_vx_64_vm


/* vdiv.vv */
TEST_FUNC(test_vdiv_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vdiv.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vdiv_vv_8, .-test_vdiv_vv_8

TEST_FUNC(test_vdiv_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vdiv.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vdiv_vv_8_vm, .-test_vdiv_vv_8_vm

TEST_FUNC(test_vdiv_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vdiv.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vdiv_vv_16, .-test_vdiv_vv_16

TEST_FUNC(test_vdiv_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vdiv.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vdiv_vv_16_vm, .-test_vdiv_vv_16_vm

TEST_FUNC(test_vdiv_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vdiv.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vdiv_vv_32, .-test_vdiv_vv_32

TEST_FUNC(test_vdiv_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vdiv.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vdiv_vv_32_vm, .-test_vdiv_vv_32_vm

TEST_FUNC(test_vdiv_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vdiv.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vdiv_vv_64, .-test_vdiv_vv_64

TEST_FUNC(test_vdiv_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vdiv.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vdiv_vv_64_vm, .-test_vdiv_vv_64_vm


/* vdivsu.vx */
TEST_FUNC(test_vmulhsu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulhsu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulhsu_vx_8, .-test_vmulhsu_vx_8

TEST_FUNC(test_vmulhsu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmulhsu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulhsu_vx_8_vm, .-test_vmulhsu_vx_8_vm
TEST_FUNC(test_vmulhsu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulhsu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulhsu_vx_16, .-test_vmulhsu_vx_16

TEST_FUNC(test_vmulhsu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmulhsu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulhsu_vx_16_vm, .-test_vmulhsu_vx_16_vm

TEST_FUNC(test_vmulhsu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulhsu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulhsu_vx_32, .-test_vmulhsu_vx_32

TEST_FUNC(test_vmulhsu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmulhsu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulhsu_vx_32_vm, .-test_vmulhsu_vx_32_vm

TEST_FUNC(test_vmulhsu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulhsu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulhsu_vx_64, .-test_vmulhsu_vx_64

TEST_FUNC(test_vmulhsu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmulhsu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulhsu_vx_64_vm, .-test_vmulhsu_vx_64_vm


/* vmulhsu.vv */
TEST_FUNC(test_vmulhsu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulhsu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulhsu_vv_8, .-test_vmulhsu_vv_8

TEST_FUNC(test_vmulhsu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmulhsu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulhsu_vv_8_vm, .-test_vmulhsu_vv_8_vm

TEST_FUNC(test_vmulhsu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulhsu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulhsu_vv_16, .-test_vmulhsu_vv_16

TEST_FUNC(test_vmulhsu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmulhsu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulhsu_vv_16_vm, .-test_vmulhsu_vv_16_vm

TEST_FUNC(test_vmulhsu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulhsu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulhsu_vv_32, .-test_vmulhsu_vv_32

TEST_FUNC(test_vmulhsu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmulhsu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulhsu_vv_32_vm, .-test_vmulhsu_vv_32_vm

TEST_FUNC(test_vmulhsu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulhsu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulhsu_vv_64, .-test_vmulhsu_vv_64

TEST_FUNC(test_vmulhsu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmulhsu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulhsu_vv_64_vm, .-test_vmulhsu_vv_64_vm


/* vmulhu.vx */
TEST_FUNC(test_vmulhu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulhu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulhu_vx_8, .-test_vmulhu_vx_8

TEST_FUNC(test_vmulhu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmulhu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulhu_vx_8_vm, .-test_vmulhu_vx_8_vm
TEST_FUNC(test_vmulhu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulhu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulhu_vx_16, .-test_vmulhu_vx_16

TEST_FUNC(test_vmulhu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmulhu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulhu_vx_16_vm, .-test_vmulhu_vx_16_vm

TEST_FUNC(test_vmulhu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulhu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulhu_vx_32, .-test_vmulhu_vx_32

TEST_FUNC(test_vmulhu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmulhu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulhu_vx_32_vm, .-test_vmulhu_vx_32_vm

TEST_FUNC(test_vmulhu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulhu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulhu_vx_64, .-test_vmulhu_vx_64

TEST_FUNC(test_vmulhu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmulhu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulhu_vx_64_vm, .-test_vmulhu_vx_64_vm


/* vmulhu.vv */
TEST_FUNC(test_vmulhu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulhu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulhu_vv_8, .-test_vmulhu_vv_8

TEST_FUNC(test_vmulhu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmulhu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulhu_vv_8_vm, .-test_vmulhu_vv_8_vm

TEST_FUNC(test_vmulhu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulhu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulhu_vv_16, .-test_vmulhu_vv_16

TEST_FUNC(test_vmulhu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmulhu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulhu_vv_16_vm, .-test_vmulhu_vv_16_vm

TEST_FUNC(test_vmulhu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulhu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulhu_vv_32, .-test_vmulhu_vv_32

TEST_FUNC(test_vmulhu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmulhu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulhu_vv_32_vm, .-test_vmulhu_vv_32_vm

TEST_FUNC(test_vmulhu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulhu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulhu_vv_64, .-test_vmulhu_vv_64

TEST_FUNC(test_vmulhu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmulhu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulhu_vv_64_vm, .-test_vmulhu_vv_64_vm



/* vmulh.vx */
TEST_FUNC(test_vmulh_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulh.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulh_vx_8, .-test_vmulh_vx_8

TEST_FUNC(test_vmulh_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmulh.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulh_vx_8_vm, .-test_vmulh_vx_8_vm
TEST_FUNC(test_vmulh_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulh.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulh_vx_16, .-test_vmulh_vx_16

TEST_FUNC(test_vmulh_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmulh.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulh_vx_16_vm, .-test_vmulh_vx_16_vm

TEST_FUNC(test_vmulh_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulh.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulh_vx_32, .-test_vmulh_vx_32

TEST_FUNC(test_vmulh_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmulh.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulh_vx_32_vm, .-test_vmulh_vx_32_vm

TEST_FUNC(test_vmulh_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulh.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulh_vx_64, .-test_vmulh_vx_64

TEST_FUNC(test_vmulh_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmulh.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulh_vx_64_vm, .-test_vmulh_vx_64_vm


/* vmulh.vv */
TEST_FUNC(test_vmulh_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmulh.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmulh_vv_8, .-test_vmulh_vv_8

TEST_FUNC(test_vmulh_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmulh.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmulh_vv_8_vm, .-test_vmulh_vv_8_vm

TEST_FUNC(test_vmulh_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmulh.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmulh_vv_16, .-test_vmulh_vv_16

TEST_FUNC(test_vmulh_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmulh.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmulh_vv_16_vm, .-test_vmulh_vv_16_vm

TEST_FUNC(test_vmulh_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmulh.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmulh_vv_32, .-test_vmulh_vv_32

TEST_FUNC(test_vmulh_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmulh.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmulh_vv_32_vm, .-test_vmulh_vv_32_vm

TEST_FUNC(test_vmulh_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmulh.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmulh_vv_64, .-test_vmulh_vv_64

TEST_FUNC(test_vmulh_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmulh.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmulh_vv_64_vm, .-test_vmulh_vv_64_vm


/* vmul.vx */
TEST_FUNC(test_vmul_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmul.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmul_vx_8, .-test_vmul_vx_8

TEST_FUNC(test_vmul_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmul.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmul_vx_8_vm, .-test_vmul_vx_8_vm
TEST_FUNC(test_vmul_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmul.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmul_vx_16, .-test_vmul_vx_16

TEST_FUNC(test_vmul_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmul.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmul_vx_16_vm, .-test_vmul_vx_16_vm

TEST_FUNC(test_vmul_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmul.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmul_vx_32, .-test_vmul_vx_32

TEST_FUNC(test_vmul_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmul.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmul_vx_32_vm, .-test_vmul_vx_32_vm

TEST_FUNC(test_vmul_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmul.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmul_vx_64, .-test_vmul_vx_64

TEST_FUNC(test_vmul_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmul.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmul_vx_64_vm, .-test_vmul_vx_64_vm


/* vmul.vv */
TEST_FUNC(test_vmul_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmul.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmul_vv_8, .-test_vmul_vv_8

TEST_FUNC(test_vmul_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmul.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmul_vv_8_vm, .-test_vmul_vv_8_vm

TEST_FUNC(test_vmul_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmul.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmul_vv_16, .-test_vmul_vv_16

TEST_FUNC(test_vmul_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmul.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmul_vv_16_vm, .-test_vmul_vv_16_vm

TEST_FUNC(test_vmul_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmul.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmul_vv_32, .-test_vmul_vv_32

TEST_FUNC(test_vmul_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmul.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmul_vv_32_vm, .-test_vmul_vv_32_vm

TEST_FUNC(test_vmul_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmul.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmul_vv_64, .-test_vmul_vv_64

TEST_FUNC(test_vmul_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmul.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmul_vv_64_vm, .-test_vmul_vv_64_vm


/* vmax.vx */
TEST_FUNC(test_vmax_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmax.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmax_vx_8, .-test_vmax_vx_8

TEST_FUNC(test_vmax_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmax.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmax_vx_8_vm, .-test_vmax_vx_8_vm
TEST_FUNC(test_vmax_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmax.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmax_vx_16, .-test_vmax_vx_16

TEST_FUNC(test_vmax_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmax.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmax_vx_16_vm, .-test_vmax_vx_16_vm

TEST_FUNC(test_vmax_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmax.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmax_vx_32, .-test_vmax_vx_32

TEST_FUNC(test_vmax_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmax.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmax_vx_32_vm, .-test_vmax_vx_32_vm

TEST_FUNC(test_vmax_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmax.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmax_vx_64, .-test_vmax_vx_64

TEST_FUNC(test_vmax_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmax.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmax_vx_64_vm, .-test_vmax_vx_64_vm


/* vmax.vv */
TEST_FUNC(test_vmax_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmax.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmax_vv_8, .-test_vmax_vv_8

TEST_FUNC(test_vmax_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmax.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmax_vv_8_vm, .-test_vmax_vv_8_vm

TEST_FUNC(test_vmax_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmax.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmax_vv_16, .-test_vmax_vv_16

TEST_FUNC(test_vmax_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmax.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmax_vv_16_vm, .-test_vmax_vv_16_vm

TEST_FUNC(test_vmax_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmax.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmax_vv_32, .-test_vmax_vv_32

TEST_FUNC(test_vmax_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmax.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmax_vv_32_vm, .-test_vmax_vv_32_vm

TEST_FUNC(test_vmax_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmax.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmax_vv_64, .-test_vmax_vv_64

TEST_FUNC(test_vmax_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmax.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmax_vv_64_vm, .-test_vmax_vv_64_vm

/* vmaxu.vx */
TEST_FUNC(test_vmaxu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmaxu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmaxu_vx_8, .-test_vmaxu_vx_8

TEST_FUNC(test_vmaxu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmaxu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmaxu_vx_8_vm, .-test_vmaxu_vx_8_vm
TEST_FUNC(test_vmaxu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmaxu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmaxu_vx_16, .-test_vmaxu_vx_16

TEST_FUNC(test_vmaxu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmaxu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmaxu_vx_16_vm, .-test_vmaxu_vx_16_vm

TEST_FUNC(test_vmaxu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmaxu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmaxu_vx_32, .-test_vmaxu_vx_32

TEST_FUNC(test_vmaxu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmaxu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmaxu_vx_32_vm, .-test_vmaxu_vx_32_vm

TEST_FUNC(test_vmaxu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmaxu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmaxu_vx_64, .-test_vmaxu_vx_64

TEST_FUNC(test_vmaxu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmaxu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmaxu_vx_64_vm, .-test_vmaxu_vx_64_vm


/* vmaxu.vv */
TEST_FUNC(test_vmaxu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmaxu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmaxu_vv_8, .-test_vmaxu_vv_8

TEST_FUNC(test_vmaxu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmaxu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmaxu_vv_8_vm, .-test_vmaxu_vv_8_vm

TEST_FUNC(test_vmaxu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmaxu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmaxu_vv_16, .-test_vmaxu_vv_16

TEST_FUNC(test_vmaxu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmaxu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmaxu_vv_16_vm, .-test_vmaxu_vv_16_vm

TEST_FUNC(test_vmaxu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmaxu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmaxu_vv_32, .-test_vmaxu_vv_32

TEST_FUNC(test_vmaxu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmaxu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmaxu_vv_32_vm, .-test_vmaxu_vv_32_vm

TEST_FUNC(test_vmaxu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmaxu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmaxu_vv_64, .-test_vmaxu_vv_64

TEST_FUNC(test_vmaxu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmaxu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmaxu_vv_64_vm, .-test_vmaxu_vv_64_vm


/* vminu.vx */
TEST_FUNC(test_vminu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vminu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vminu_vx_8, .-test_vminu_vx_8

TEST_FUNC(test_vminu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vminu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vminu_vx_8_vm, .-test_vminu_vx_8_vm
TEST_FUNC(test_vminu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vminu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vminu_vx_16, .-test_vminu_vx_16

TEST_FUNC(test_vminu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vminu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vminu_vx_16_vm, .-test_vminu_vx_16_vm

TEST_FUNC(test_vminu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vminu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vminu_vx_32, .-test_vminu_vx_32

TEST_FUNC(test_vminu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vminu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vminu_vx_32_vm, .-test_vminu_vx_32_vm

TEST_FUNC(test_vminu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vminu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vminu_vx_64, .-test_vminu_vx_64

TEST_FUNC(test_vminu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vminu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vminu_vx_64_vm, .-test_vminu_vx_64_vm


/* vminu.vv */
TEST_FUNC(test_vminu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vminu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vminu_vv_8, .-test_vminu_vv_8

TEST_FUNC(test_vminu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vminu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vminu_vv_8_vm, .-test_vminu_vv_8_vm

TEST_FUNC(test_vminu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vminu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vminu_vv_16, .-test_vminu_vv_16

TEST_FUNC(test_vminu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vminu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vminu_vv_16_vm, .-test_vminu_vv_16_vm

TEST_FUNC(test_vminu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vminu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vminu_vv_32, .-test_vminu_vv_32

TEST_FUNC(test_vminu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vminu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vminu_vv_32_vm, .-test_vminu_vv_32_vm

TEST_FUNC(test_vminu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vminu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vminu_vv_64, .-test_vminu_vv_64

TEST_FUNC(test_vminu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vminu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vminu_vv_64_vm, .-test_vminu_vv_64_vm

/* vmin.vx */
TEST_FUNC(test_vmin_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmin.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmin_vx_8, .-test_vmin_vx_8

TEST_FUNC(test_vmin_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmin.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmin_vx_8_vm, .-test_vmin_vx_8_vm
TEST_FUNC(test_vmin_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmin.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmin_vx_16, .-test_vmin_vx_16

TEST_FUNC(test_vmin_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmin.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmin_vx_16_vm, .-test_vmin_vx_16_vm

TEST_FUNC(test_vmin_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmin.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmin_vx_32, .-test_vmin_vx_32

TEST_FUNC(test_vmin_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmin.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmin_vx_32_vm, .-test_vmin_vx_32_vm

TEST_FUNC(test_vmin_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmin.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmin_vx_64, .-test_vmin_vx_64

TEST_FUNC(test_vmin_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmin.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmin_vx_64_vm, .-test_vmin_vx_64_vm


/* vmin.vv */
TEST_FUNC(test_vmin_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmin.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmin_vv_8, .-test_vmin_vv_8

TEST_FUNC(test_vmin_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmin.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmin_vv_8_vm, .-test_vmin_vv_8_vm

TEST_FUNC(test_vmin_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmin.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmin_vv_16, .-test_vmin_vv_16

TEST_FUNC(test_vmin_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmin.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmin_vv_16_vm, .-test_vmin_vv_16_vm

TEST_FUNC(test_vmin_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmin.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmin_vv_32, .-test_vmin_vv_32

TEST_FUNC(test_vmin_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmin.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmin_vv_32_vm, .-test_vmin_vv_32_vm

TEST_FUNC(test_vmin_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmin.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmin_vv_64, .-test_vmin_vv_64

TEST_FUNC(test_vmin_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmin.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmin_vv_64_vm, .-test_vmin_vv_64_vm


/* vmsgtu.vi */
TEST_FUNC(test_vmsgtu_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmsgtu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmsgtu_vi_8, .-test_vmsgtu_vi_8

TEST_FUNC(test_vmsgtu_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsgtu.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmsgtu_vi_8_vm, .-test_vmsgtu_vi_8_vm
TEST_FUNC(test_vmsgtu_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmsgtu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmsgtu_vi_16, .-test_vmsgtu_vi_16

TEST_FUNC(test_vmsgtu_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsgtu.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmsgtu_vi_16_vm, .-test_vmsgtu_vi_16_vm

TEST_FUNC(test_vmsgtu_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmsgtu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmsgtu_vi_32, .-test_vmsgtu_vi_32

TEST_FUNC(test_vmsgtu_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsgtu.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmsgtu_vi_32_vm, .-test_vmsgtu_vi_32_vm

TEST_FUNC(test_vmsgtu_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmsgtu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmsgtu_vi_64, .-test_vmsgtu_vi_64

TEST_FUNC(test_vmsgtu_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsgtu.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmsgtu_vi_64_vm, .-test_vmsgtu_vi_64_vm


/* vmsgtu.vx */
TEST_FUNC(test_vmsgtu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsgtu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsgtu_vx_8, .-test_vmsgtu_vx_8

TEST_FUNC(test_vmsgtu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsgtu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsgtu_vx_8_vm, .-test_vmsgtu_vx_8_vm
TEST_FUNC(test_vmsgtu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsgtu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsgtu_vx_16, .-test_vmsgtu_vx_16

TEST_FUNC(test_vmsgtu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsgtu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsgtu_vx_16_vm, .-test_vmsgtu_vx_16_vm

TEST_FUNC(test_vmsgtu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsgtu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsgtu_vx_32, .-test_vmsgtu_vx_32

TEST_FUNC(test_vmsgtu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsgtu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsgtu_vx_32_vm, .-test_vmsgtu_vx_32_vm

TEST_FUNC(test_vmsgtu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsgtu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsgtu_vx_64, .-test_vmsgtu_vx_64

TEST_FUNC(test_vmsgtu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsgtu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsgtu_vx_64_vm, .-test_vmsgtu_vx_64_vm


/* vmsgt.vi */
TEST_FUNC(test_vmsgt_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmsgt.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmsgt_vi_8, .-test_vmsgt_vi_8

TEST_FUNC(test_vmsgt_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsgt.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmsgt_vi_8_vm, .-test_vmsgt_vi_8_vm
TEST_FUNC(test_vmsgt_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmsgt.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmsgt_vi_16, .-test_vmsgt_vi_16

TEST_FUNC(test_vmsgt_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsgt.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmsgt_vi_16_vm, .-test_vmsgt_vi_16_vm

TEST_FUNC(test_vmsgt_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmsgt.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmsgt_vi_32, .-test_vmsgt_vi_32

TEST_FUNC(test_vmsgt_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsgt.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmsgt_vi_32_vm, .-test_vmsgt_vi_32_vm

TEST_FUNC(test_vmsgt_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmsgt.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmsgt_vi_64, .-test_vmsgt_vi_64

TEST_FUNC(test_vmsgt_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsgt.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmsgt_vi_64_vm, .-test_vmsgt_vi_64_vm


/* vmsgt.vx */
TEST_FUNC(test_vmsgt_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsgt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsgt_vx_8, .-test_vmsgt_vx_8

TEST_FUNC(test_vmsgt_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsgt.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsgt_vx_8_vm, .-test_vmsgt_vx_8_vm
TEST_FUNC(test_vmsgt_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsgt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsgt_vx_16, .-test_vmsgt_vx_16

TEST_FUNC(test_vmsgt_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsgt.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsgt_vx_16_vm, .-test_vmsgt_vx_16_vm

TEST_FUNC(test_vmsgt_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsgt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsgt_vx_32, .-test_vmsgt_vx_32

TEST_FUNC(test_vmsgt_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsgt.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsgt_vx_32_vm, .-test_vmsgt_vx_32_vm

TEST_FUNC(test_vmsgt_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsgt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsgt_vx_64, .-test_vmsgt_vx_64

TEST_FUNC(test_vmsgt_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsgt.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsgt_vx_64_vm, .-test_vmsgt_vx_64_vm

/* vmslt.vx */
TEST_FUNC(test_vmslt_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmslt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmslt_vx_8, .-test_vmslt_vx_8

TEST_FUNC(test_vmslt_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmslt.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmslt_vx_8_vm, .-test_vmslt_vx_8_vm
TEST_FUNC(test_vmslt_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmslt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmslt_vx_16, .-test_vmslt_vx_16

TEST_FUNC(test_vmslt_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmslt.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmslt_vx_16_vm, .-test_vmslt_vx_16_vm

TEST_FUNC(test_vmslt_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmslt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmslt_vx_32, .-test_vmslt_vx_32

TEST_FUNC(test_vmslt_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmslt.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmslt_vx_32_vm, .-test_vmslt_vx_32_vm

TEST_FUNC(test_vmslt_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmslt.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmslt_vx_64, .-test_vmslt_vx_64

TEST_FUNC(test_vmslt_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmslt.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmslt_vx_64_vm, .-test_vmslt_vx_64_vm


/* vmslt.vv */
TEST_FUNC(test_vmslt_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmslt.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmslt_vv_8, .-test_vmslt_vv_8

TEST_FUNC(test_vmslt_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmslt.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmslt_vv_8_vm, .-test_vmslt_vv_8_vm

TEST_FUNC(test_vmslt_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmslt.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmslt_vv_16, .-test_vmslt_vv_16

TEST_FUNC(test_vmslt_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmslt.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmslt_vv_16_vm, .-test_vmslt_vv_16_vm

TEST_FUNC(test_vmslt_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmslt.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmslt_vv_32, .-test_vmslt_vv_32

TEST_FUNC(test_vmslt_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmslt.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmslt_vv_32_vm, .-test_vmslt_vv_32_vm

TEST_FUNC(test_vmslt_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmslt.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmslt_vv_64, .-test_vmslt_vv_64

TEST_FUNC(test_vmslt_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmslt.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmslt_vv_64_vm, .-test_vmslt_vv_64_vm


/* vmsltu.vx */
TEST_FUNC(test_vmsltu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsltu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsltu_vx_8, .-test_vmsltu_vx_8

TEST_FUNC(test_vmsltu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsltu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsltu_vx_8_vm, .-test_vmsltu_vx_8_vm
TEST_FUNC(test_vmsltu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsltu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsltu_vx_16, .-test_vmsltu_vx_16

TEST_FUNC(test_vmsltu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsltu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsltu_vx_16_vm, .-test_vmsltu_vx_16_vm

TEST_FUNC(test_vmsltu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsltu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsltu_vx_32, .-test_vmsltu_vx_32

TEST_FUNC(test_vmsltu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsltu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsltu_vx_32_vm, .-test_vmsltu_vx_32_vm

TEST_FUNC(test_vmsltu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsltu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsltu_vx_64, .-test_vmsltu_vx_64

TEST_FUNC(test_vmsltu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsltu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsltu_vx_64_vm, .-test_vmsltu_vx_64_vm


/* vmsltu.vv */
TEST_FUNC(test_vmsltu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsltu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsltu_vv_8, .-test_vmsltu_vv_8

TEST_FUNC(test_vmsltu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmsltu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsltu_vv_8_vm, .-test_vmsltu_vv_8_vm

TEST_FUNC(test_vmsltu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsltu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsltu_vv_16, .-test_vmsltu_vv_16

TEST_FUNC(test_vmsltu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmsltu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsltu_vv_16_vm, .-test_vmsltu_vv_16_vm

TEST_FUNC(test_vmsltu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsltu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsltu_vv_32, .-test_vmsltu_vv_32

TEST_FUNC(test_vmsltu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmsltu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsltu_vv_32_vm, .-test_vmsltu_vv_32_vm

TEST_FUNC(test_vmsltu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsltu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsltu_vv_64, .-test_vmsltu_vv_64

TEST_FUNC(test_vmsltu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmsltu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsltu_vv_64_vm, .-test_vmsltu_vv_64_vm


/* vmsle.vi */
TEST_FUNC(test_vmsle_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmsle.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmsle_vi_8, .-test_vmsle_vi_8

TEST_FUNC(test_vmsle_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsle.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmsle_vi_8_vm, .-test_vmsle_vi_8_vm
TEST_FUNC(test_vmsle_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmsle.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmsle_vi_16, .-test_vmsle_vi_16

TEST_FUNC(test_vmsle_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsle.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmsle_vi_16_vm, .-test_vmsle_vi_16_vm

TEST_FUNC(test_vmsle_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmsle.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmsle_vi_32, .-test_vmsle_vi_32

TEST_FUNC(test_vmsle_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsle.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmsle_vi_32_vm, .-test_vmsle_vi_32_vm

TEST_FUNC(test_vmsle_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmsle.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmsle_vi_64, .-test_vmsle_vi_64

TEST_FUNC(test_vmsle_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsle.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmsle_vi_64_vm, .-test_vmsle_vi_64_vm


/* vmsle.vx */
TEST_FUNC(test_vmsle_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsle.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsle_vx_8, .-test_vmsle_vx_8

TEST_FUNC(test_vmsle_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsle.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsle_vx_8_vm, .-test_vmsle_vx_8_vm
TEST_FUNC(test_vmsle_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsle.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsle_vx_16, .-test_vmsle_vx_16

TEST_FUNC(test_vmsle_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsle.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsle_vx_16_vm, .-test_vmsle_vx_16_vm

TEST_FUNC(test_vmsle_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsle.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsle_vx_32, .-test_vmsle_vx_32

TEST_FUNC(test_vmsle_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsle.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsle_vx_32_vm, .-test_vmsle_vx_32_vm

TEST_FUNC(test_vmsle_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsle.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsle_vx_64, .-test_vmsle_vx_64

TEST_FUNC(test_vmsle_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsle.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsle_vx_64_vm, .-test_vmsle_vx_64_vm


/* vmsle.vv */
TEST_FUNC(test_vmsle_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsle.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsle_vv_8, .-test_vmsle_vv_8

TEST_FUNC(test_vmsle_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmsle.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsle_vv_8_vm, .-test_vmsle_vv_8_vm

TEST_FUNC(test_vmsle_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsle.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsle_vv_16, .-test_vmsle_vv_16

TEST_FUNC(test_vmsle_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmsle.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsle_vv_16_vm, .-test_vmsle_vv_16_vm

TEST_FUNC(test_vmsle_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsle.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsle_vv_32, .-test_vmsle_vv_32

TEST_FUNC(test_vmsle_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmsle.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsle_vv_32_vm, .-test_vmsle_vv_32_vm

TEST_FUNC(test_vmsle_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsle.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsle_vv_64, .-test_vmsle_vv_64

TEST_FUNC(test_vmsle_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmsle.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsle_vv_64_vm, .-test_vmsle_vv_64_vm


/* vmsleu.vi */
TEST_FUNC(test_vmsleu_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmsleu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmsleu_vi_8, .-test_vmsleu_vi_8

TEST_FUNC(test_vmsleu_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsleu.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmsleu_vi_8_vm, .-test_vmsleu_vi_8_vm
TEST_FUNC(test_vmsleu_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmsleu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmsleu_vi_16, .-test_vmsleu_vi_16

TEST_FUNC(test_vmsleu_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsleu.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmsleu_vi_16_vm, .-test_vmsleu_vi_16_vm

TEST_FUNC(test_vmsleu_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmsleu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmsleu_vi_32, .-test_vmsleu_vi_32

TEST_FUNC(test_vmsleu_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsleu.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmsleu_vi_32_vm, .-test_vmsleu_vi_32_vm

TEST_FUNC(test_vmsleu_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmsleu.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmsleu_vi_64, .-test_vmsleu_vi_64

TEST_FUNC(test_vmsleu_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsleu.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmsleu_vi_64_vm, .-test_vmsleu_vi_64_vm


/* vmsleu.vx */
TEST_FUNC(test_vmsleu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsleu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsleu_vx_8, .-test_vmsleu_vx_8

TEST_FUNC(test_vmsleu_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsleu.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsleu_vx_8_vm, .-test_vmsleu_vx_8_vm
TEST_FUNC(test_vmsleu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsleu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsleu_vx_16, .-test_vmsleu_vx_16

TEST_FUNC(test_vmsleu_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsleu.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsleu_vx_16_vm, .-test_vmsleu_vx_16_vm

TEST_FUNC(test_vmsleu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsleu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsleu_vx_32, .-test_vmsleu_vx_32

TEST_FUNC(test_vmsleu_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsleu.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsleu_vx_32_vm, .-test_vmsleu_vx_32_vm

TEST_FUNC(test_vmsleu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsleu.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsleu_vx_64, .-test_vmsleu_vx_64

TEST_FUNC(test_vmsleu_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsleu.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsleu_vx_64_vm, .-test_vmsleu_vx_64_vm


/* vmsleu.vv */
TEST_FUNC(test_vmsleu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsleu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsleu_vv_8, .-test_vmsleu_vv_8

TEST_FUNC(test_vmsleu_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmsleu.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsleu_vv_8_vm, .-test_vmsleu_vv_8_vm

TEST_FUNC(test_vmsleu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsleu.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsleu_vv_16, .-test_vmsleu_vv_16

TEST_FUNC(test_vmsleu_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmsleu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsleu_vv_16_vm, .-test_vmsleu_vv_16_vm

TEST_FUNC(test_vmsleu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsleu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsleu_vv_32, .-test_vmsleu_vv_32

TEST_FUNC(test_vmsleu_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmsleu.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsleu_vv_32_vm, .-test_vmsleu_vv_32_vm

TEST_FUNC(test_vmsleu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsleu.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsleu_vv_64, .-test_vmsleu_vv_64

TEST_FUNC(test_vmsleu_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmsleu.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsleu_vv_64_vm, .-test_vmsleu_vv_64_vm




/* vmsne.vi */
TEST_FUNC(test_vmsne_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmsne.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmsne_vi_8, .-test_vmsne_vi_8

TEST_FUNC(test_vmsne_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsne.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmsne_vi_8_vm, .-test_vmsne_vi_8_vm
TEST_FUNC(test_vmsne_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmsne.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmsne_vi_16, .-test_vmsne_vi_16

TEST_FUNC(test_vmsne_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsne.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmsne_vi_16_vm, .-test_vmsne_vi_16_vm

TEST_FUNC(test_vmsne_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmsne.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmsne_vi_32, .-test_vmsne_vi_32

TEST_FUNC(test_vmsne_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsne.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmsne_vi_32_vm, .-test_vmsne_vi_32_vm

TEST_FUNC(test_vmsne_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmsne.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmsne_vi_64, .-test_vmsne_vi_64

TEST_FUNC(test_vmsne_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsne.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmsne_vi_64_vm, .-test_vmsne_vi_64_vm


/* vmsne.vx */
TEST_FUNC(test_vmsne_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsne.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsne_vx_8, .-test_vmsne_vx_8

TEST_FUNC(test_vmsne_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsne.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsne_vx_8_vm, .-test_vmsne_vx_8_vm
TEST_FUNC(test_vmsne_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsne.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsne_vx_16, .-test_vmsne_vx_16

TEST_FUNC(test_vmsne_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsne.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsne_vx_16_vm, .-test_vmsne_vx_16_vm

TEST_FUNC(test_vmsne_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsne.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsne_vx_32, .-test_vmsne_vx_32

TEST_FUNC(test_vmsne_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsne.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsne_vx_32_vm, .-test_vmsne_vx_32_vm

TEST_FUNC(test_vmsne_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsne.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsne_vx_64, .-test_vmsne_vx_64

TEST_FUNC(test_vmsne_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsne.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsne_vx_64_vm, .-test_vmsne_vx_64_vm


/* vmsne.vv */
TEST_FUNC(test_vmsne_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsne.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsne_vv_8, .-test_vmsne_vv_8

TEST_FUNC(test_vmsne_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmsne.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmsne_vv_8_vm, .-test_vmsne_vv_8_vm

TEST_FUNC(test_vmsne_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsne.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsne_vv_16, .-test_vmsne_vv_16

TEST_FUNC(test_vmsne_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmsne.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmsne_vv_16_vm, .-test_vmsne_vv_16_vm

TEST_FUNC(test_vmsne_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsne.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsne_vv_32, .-test_vmsne_vv_32

TEST_FUNC(test_vmsne_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmsne.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmsne_vv_32_vm, .-test_vmsne_vv_32_vm

TEST_FUNC(test_vmsne_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsne.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsne_vv_64, .-test_vmsne_vv_64

TEST_FUNC(test_vmsne_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmsne.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmsne_vv_64_vm, .-test_vmsne_vv_64_vm


/* vmseq.vi */
TEST_FUNC(test_vmseq_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmseq.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmseq_vi_8, .-test_vmseq_vi_8

TEST_FUNC(test_vmseq_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmseq.vi         v6, v2, 15, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vmseq_vi_8_vm, .-test_vmseq_vi_8_vm
TEST_FUNC(test_vmseq_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmseq.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmseq_vi_16, .-test_vmseq_vi_16

TEST_FUNC(test_vmseq_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmseq.vi        v6, v2, 15, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vmseq_vi_16_vm, .-test_vmseq_vi_16_vm

TEST_FUNC(test_vmseq_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmseq.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmseq_vi_32, .-test_vmseq_vi_32

TEST_FUNC(test_vmseq_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmseq.vi        v6, v2, 15, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vmseq_vi_32_vm, .-test_vmseq_vi_32_vm

TEST_FUNC(test_vmseq_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmseq.vi        v6, v2, -16, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmseq_vi_64, .-test_vmseq_vi_64

TEST_FUNC(test_vmseq_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmseq.vi         v6, v2, 15, v0.t
        vse.v           v6, (a1)
        ret
        .size   test_vmseq_vi_64_vm, .-test_vmseq_vi_64_vm


/* vmseq.vx */
TEST_FUNC(test_vmseq_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmseq.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmseq_vx_8, .-test_vmseq_vx_8

TEST_FUNC(test_vmseq_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmseq.vx         v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmseq_vx_8_vm, .-test_vmseq_vx_8_vm
TEST_FUNC(test_vmseq_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmseq.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmseq_vx_16, .-test_vmseq_vx_16

TEST_FUNC(test_vmseq_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmseq.vx        v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmseq_vx_16_vm, .-test_vmseq_vx_16_vm

TEST_FUNC(test_vmseq_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmseq.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmseq_vx_32, .-test_vmseq_vx_32

TEST_FUNC(test_vmseq_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmseq.vx        v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmseq_vx_32_vm, .-test_vmseq_vx_32_vm

TEST_FUNC(test_vmseq_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmseq.vx        v6, v2, a2, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmseq_vx_64, .-test_vmseq_vx_64

TEST_FUNC(test_vmseq_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmseq.vx         v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmseq_vx_64_vm, .-test_vmseq_vx_64_vm


/* vmseq.vv */
TEST_FUNC(test_vmseq_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmseq.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmseq_vv_8, .-test_vmseq_vv_8

TEST_FUNC(test_vmseq_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmseq.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vmseq_vv_8_vm, .-test_vmseq_vv_8_vm

TEST_FUNC(test_vmseq_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmseq.vv       v6, v2, v4, v0.t 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmseq_vv_16, .-test_vmseq_vv_16

TEST_FUNC(test_vmseq_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmseq.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vmseq_vv_16_vm, .-test_vmseq_vv_16_vm

TEST_FUNC(test_vmseq_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmseq.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmseq_vv_32, .-test_vmseq_vv_32

TEST_FUNC(test_vmseq_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmseq.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vmseq_vv_32_vm, .-test_vmseq_vv_32_vm

TEST_FUNC(test_vmseq_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmseq.vv        v6, v2, v4, v0.t 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmseq_vv_64, .-test_vmseq_vv_64

TEST_FUNC(test_vmseq_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmseq.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vmseq_vv_64_vm, .-test_vmseq_vv_64_vm


/* vnsrl.vv */
TEST_FUNC(test_vnsrl_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v6, (a2)
        vnsrl.vv        v4, v0, v6
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnsrl_vv_8, .-test_vnsrl_vv_8

TEST_FUNC(test_vnsrl_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vnsrl.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vnsrl_vv_8_vm, .-test_vnsrl_vv_8_vm

TEST_FUNC(test_vnsrl_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v6, (a2)
        vnsrl.vv         v4, v0, v6
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnsrl_vv_16, .-test_vnsrl_vv_16

TEST_FUNC(test_vnsrl_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vnsrl.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vnsrl_vv_16_vm, .-test_vnsrl_vv_16_vm

TEST_FUNC(test_vnsrl_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v6, (a2)
        vnsrl.vv        v4, v0, v6
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnsrl_vv_32, .-test_vnsrl_vv_32

TEST_FUNC(test_vnsrl_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vnsrl.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vnsrl_vv_32_vm, .-test_vnsrl_vv_32_vm

/* vnsrl.vx */
TEST_FUNC(test_vnsrl_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vnsrl.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnsrl_vx_8, .-test_vnsrl_vx_8

TEST_FUNC(test_vnsrl_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vnsrl.vx        v4, v8, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnsrl_vx_8_vm, .-test_vnsrl_vx_8_vm

TEST_FUNC(test_vnsrl_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vnsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnsrl_vx_16, .-test_vnsrl_vx_16

TEST_FUNC(test_vnsrl_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vnsrl.vx         v4, v8, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnsrl_vx_16_vm, .-test_vnsrl_vx_16_vm

TEST_FUNC(test_vnsrl_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vnsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnsrl_vx_32, .-test_vnsrl_vx_32

TEST_FUNC(test_vnsrl_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vnsrl.vx         v4, v8, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnsrl_vx_32_vm, .-test_vnsrl_vx_32_vm

/* vnsrl.vi */
TEST_FUNC(test_vnsrl_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vnsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnsrl_vi_8, .-test_vnsrl_vi_8

TEST_FUNC(test_vnsrl_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vnsrl.vi        v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vnsrl_vi_8_vm, .-test_vnsrl_vi_8_vm

TEST_FUNC(test_vnsrl_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vnsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnsrl_vi_16, .-test_vnsrl_vi_16

TEST_FUNC(test_vnsrl_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vnsrl.vi         v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vnsrl_vi_16_vm, .-test_vnsrl_vi_16_vm

TEST_FUNC(test_vnsrl_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vnsrl.vi        v4, v0, 16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnsrl_vi_32, .-test_vnsrl_vi_32

TEST_FUNC(test_vnsrl_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vnsrl.vi        v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vnsrl_vi_32_vm, .-test_vnsrl_vi_32_vm

/* vnsra.vv */
TEST_FUNC(test_vnsra_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v6, (a2)
        vnsra.vv        v4, v0, v6
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnsra_vv_8, .-test_vnsra_vv_8

TEST_FUNC(test_vnsra_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vnsra.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vnsra_vv_8_vm, .-test_vnsra_vv_8_vm

TEST_FUNC(test_vnsra_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v6, (a2)
        vnsra.vv        v4, v0, v6
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnsra_vv_16, .-test_vnsra_vv_16

TEST_FUNC(test_vnsra_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vnsra.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vnsra_vv_16_vm, .-test_vnsra_vv_16_vm

TEST_FUNC(test_vnsra_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v6, (a2)
        vnsra.vv        v4, v0, v6
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnsra_vv_32, .-test_vnsra_vv_32

TEST_FUNC(test_vnsra_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vnsra.vv        v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vnsra_vv_32_vm, .-test_vnsra_vv_32_vm


/* vnsra.vx */
TEST_FUNC(test_vnsra_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vnsra.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnsra_vx_8, .-test_vnsra_vx_8

TEST_FUNC(test_vnsra_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vnsra.vx         v4, v8, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnsra_vx_8_vm, .-test_vnsra_vx_8_vm

TEST_FUNC(test_vnsra_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vnsra.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnsra_vx_16, .-test_vnsra_vx_16

TEST_FUNC(test_vnsra_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vnsra.vx         v4, v8, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnsra_vx_16_vm, .-test_vnsra_vx_16_vm

TEST_FUNC(test_vnsra_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vnsra.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnsra_vx_32, .-test_vnsra_vx_32

TEST_FUNC(test_vnsra_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vnsra.vx         v4, v8, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnsra_vx_32_vm, .-test_vnsra_vx_32_vm

/* vnsra.vi */
TEST_FUNC(test_vnsra_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vnsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnsra_vi_8, .-test_vnsra_vi_8

TEST_FUNC(test_vnsra_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vnsra.vi         v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vnsra_vi_8_vm, .-test_vnsra_vi_8_vm

TEST_FUNC(test_vnsra_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vnsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnsra_vi_16, .-test_vnsra_vi_16

TEST_FUNC(test_vnsra_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vnsra.vi         v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vnsra_vi_16_vm, .-test_vnsra_vi_16_vm

TEST_FUNC(test_vnsra_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vnsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnsra_vi_32, .-test_vnsra_vi_32

TEST_FUNC(test_vnsra_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vnsra.vi         v4, v8, 0x5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vnsra_vi_32_vm, .-test_vnsra_vi_32_vm

/* vsll.vv */
TEST_FUNC(test_vsll_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsll.vv         v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsll_vv_8, .-test_vsll_vv_8

TEST_FUNC(test_vsll_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsll.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vsll_vv_8_vm, .-test_vsll_vv_8_vm

TEST_FUNC(test_vsll_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsll.vv         v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsll_vv_16, .-test_vsll_vv_16

TEST_FUNC(test_vsll_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsll.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vsll_vv_16_vm, .-test_vsll_vv_16_vm

TEST_FUNC(test_vsll_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsll.vv         v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsll_vv_32, .-test_vsll_vv_32

TEST_FUNC(test_vsll_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsll.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vsll_vv_32_vm, .-test_vsll_vv_32_vm

TEST_FUNC(test_vsll_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsll.vv         v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsll_vv_64, .-test_vsll_vv_64

TEST_FUNC(test_vsll_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsll.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vsll_vv_64_vm, .-test_vsll_vv_64_vm

/* vsll.vx */
TEST_FUNC(test_vsll_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsll.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsll_vx_8, .-test_vsll_vx_8

TEST_FUNC(test_vsll_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsll.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsll_vx_8_vm, .-test_vsll_vx_8_vm

TEST_FUNC(test_vsll_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsll.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsll_vx_16, .-test_vsll_vx_16

TEST_FUNC(test_vsll_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsll.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsll_vx_16_vm, .-test_vsll_vx_16_vm

TEST_FUNC(test_vsll_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsll.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsll_vx_32, .-test_vsll_vx_32

TEST_FUNC(test_vsll_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsll.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsll_vx_32_vm, .-test_vsll_vx_32_vm

TEST_FUNC(test_vsll_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsll.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsll_vx_64, .-test_vsll_vx_64

TEST_FUNC(test_vsll_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsll.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsll_vx_64_vm, .-test_vsll_vx_64_vm

/* vsll.vi */
TEST_FUNC(test_vsll_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsll.vi         v4, v0, 16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsll_vi_8, .-test_vsll_vi_8

TEST_FUNC(test_vsll_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsll.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vsll_vi_8_vm, .-test_vsll_vi_8_vm

TEST_FUNC(test_vsll_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsll.vi         v4, v0, 16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsll_vi_16, .-test_vsll_vi_16

TEST_FUNC(test_vsll_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsll.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vsll_vi_16_vm, .-test_vsll_vi_16_vm

TEST_FUNC(test_vsll_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsll.vi         v4, v0, 16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsll_vi_32, .-test_vsll_vi_32

TEST_FUNC(test_vsll_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsll.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vsll_vi_32_vm, .-test_vsll_vi_32_vm

TEST_FUNC(test_vsll_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsll.vi         v4, v0, 16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsll_vi_64, .-test_vsll_vi_64

TEST_FUNC(test_vsll_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsll.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vsll_vi_64_vm, .-test_vsll_vi_64_vm

/* vsrl.vv */
TEST_FUNC(test_vsrl_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsrl.vv         v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsrl_vv_8, .-test_vsrl_vv_8

TEST_FUNC(test_vsrl_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsrl.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vsrl_vv_8_vm, .-test_vsrl_vv_8_vm

TEST_FUNC(test_vsrl_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsrl.vv         v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsrl_vv_16, .-test_vsrl_vv_16

TEST_FUNC(test_vsrl_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsrl.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vsrl_vv_16_vm, .-test_vsrl_vv_16_vm

TEST_FUNC(test_vsrl_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsrl.vv         v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsrl_vv_32, .-test_vsrl_vv_32

TEST_FUNC(test_vsrl_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsrl.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vsrl_vv_32_vm, .-test_vsrl_vv_32_vm

TEST_FUNC(test_vsrl_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsrl.vv         v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsrl_vv_64, .-test_vsrl_vv_64

TEST_FUNC(test_vsrl_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsrl.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vsrl_vv_64_vm, .-test_vsrl_vv_64_vm

/* vsrl.vx */
TEST_FUNC(test_vsrl_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsrl_vx_8, .-test_vsrl_vx_8

TEST_FUNC(test_vsrl_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsrl.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsrl_vx_8_vm, .-test_vsrl_vx_8_vm

TEST_FUNC(test_vsrl_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsrl_vx_16, .-test_vsrl_vx_16

TEST_FUNC(test_vsrl_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsrl.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsrl_vx_16_vm, .-test_vsrl_vx_16_vm

TEST_FUNC(test_vsrl_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsrl_vx_32, .-test_vsrl_vx_32

TEST_FUNC(test_vsrl_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsrl.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsrl_vx_32_vm, .-test_vsrl_vx_32_vm

TEST_FUNC(test_vsrl_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsrl.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsrl_vx_64, .-test_vsrl_vx_64

TEST_FUNC(test_vsrl_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsrl.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsrl_vx_64_vm, .-test_vsrl_vx_64_vm

/* vsrl.vi */
TEST_FUNC(test_vsrl_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsrl_vi_8, .-test_vsrl_vi_8

TEST_FUNC(test_vsrl_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsrl.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vsrl_vi_8_vm, .-test_vsrl_vi_8_vm

TEST_FUNC(test_vsrl_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsrl_vi_16, .-test_vsrl_vi_16

TEST_FUNC(test_vsrl_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsrl.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vsrl_vi_16_vm, .-test_vsrl_vi_16_vm

TEST_FUNC(test_vsrl_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsrl_vi_32, .-test_vsrl_vi_32

TEST_FUNC(test_vsrl_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsrl.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vsrl_vi_32_vm, .-test_vsrl_vi_32_vm

TEST_FUNC(test_vsrl_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsrl.vi         v4, v0, 16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsrl_vi_64, .-test_vsrl_vi_64

TEST_FUNC(test_vsrl_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsrl.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vsrl_vi_64_vm, .-test_vsrl_vi_64_vm

/* vsra.vv */
TEST_FUNC(test_vsra_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsra.vv         v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsra_vv_8, .-test_vsra_vv_8

TEST_FUNC(test_vsra_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsra.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vsra_vv_8_vm, .-test_vsra_vv_8_vm

TEST_FUNC(test_vsra_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsra.vv         v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsra_vv_16, .-test_vsra_vv_16

TEST_FUNC(test_vsra_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsra.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vsra_vv_16_vm, .-test_vsra_vv_16_vm

TEST_FUNC(test_vsra_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsra.vv         v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsra_vv_32, .-test_vsra_vv_32

TEST_FUNC(test_vsra_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsra.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vsra_vv_32_vm, .-test_vsra_vv_32_vm

TEST_FUNC(test_vsra_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsra.vv         v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsra_vv_64, .-test_vsra_vv_64

TEST_FUNC(test_vsra_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsra.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vsra_vv_64_vm, .-test_vsra_vv_64_vm

/* vsra.vx */
TEST_FUNC(test_vsra_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsra.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsra_vx_8, .-test_vsra_vx_8

TEST_FUNC(test_vsra_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsra.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsra_vx_8_vm, .-test_vsra_vx_8_vm

TEST_FUNC(test_vsra_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsra.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsra_vx_16, .-test_vsra_vx_16

TEST_FUNC(test_vsra_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsra.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsra_vx_16_vm, .-test_vsra_vx_16_vm

TEST_FUNC(test_vsra_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsra.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsra_vx_32, .-test_vsra_vx_32

TEST_FUNC(test_vsra_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsra.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsra_vx_32_vm, .-test_vsra_vx_32_vm

TEST_FUNC(test_vsra_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsra.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsra_vx_64, .-test_vsra_vx_64

TEST_FUNC(test_vsra_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsra.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsra_vx_64_vm, .-test_vsra_vx_64_vm

/* vsra.vi */
TEST_FUNC(test_vsra_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsra_vi_8, .-test_vsra_vi_8

TEST_FUNC(test_vsra_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsra.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vsra_vi_8_vm, .-test_vsra_vi_8_vm

TEST_FUNC(test_vsra_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsra_vi_16, .-test_vsra_vi_16

TEST_FUNC(test_vsra_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsra.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vsra_vi_16_vm, .-test_vsra_vi_16_vm

TEST_FUNC(test_vsra_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsra_vi_32, .-test_vsra_vi_32

TEST_FUNC(test_vsra_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsra.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vsra_vi_32_vm, .-test_vsra_vi_32_vm

TEST_FUNC(test_vsra_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsra.vi         v4, v0, 16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsra_vi_64, .-test_vsra_vi_64

TEST_FUNC(test_vsra_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsra.vi         v4, v2, 0x5, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vsra_vi_64_vm, .-test_vsra_vi_64_vm

/* vand.vv */
TEST_FUNC(test_vand_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vand.vv         v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vand_vv_8, .-test_vand_vv_8

TEST_FUNC(test_vand_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vand.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vand_vv_8_vm, .-test_vand_vv_8_vm

TEST_FUNC(test_vand_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vand.vv         v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vand_vv_16, .-test_vand_vv_16

TEST_FUNC(test_vand_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vand.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vand_vv_16_vm, .-test_vand_vv_16_vm

TEST_FUNC(test_vand_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vand.vv         v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vand_vv_32, .-test_vand_vv_32

TEST_FUNC(test_vand_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vand.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vand_vv_32_vm, .-test_vand_vv_32_vm

TEST_FUNC(test_vand_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vand.vv         v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vand_vv_64, .-test_vand_vv_64

TEST_FUNC(test_vand_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vand.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vand_vv_64_vm, .-test_vand_vv_64_vm

/* vand.vx */
TEST_FUNC(test_vand_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vand.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vand_vx_8, .-test_vand_vx_8

TEST_FUNC(test_vand_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vand.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vand_vx_8_vm, .-test_vand_vx_8_vm

TEST_FUNC(test_vand_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vand.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vand_vx_16, .-test_vand_vx_16

TEST_FUNC(test_vand_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vand.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vand_vx_16_vm, .-test_vand_vx_16_vm

TEST_FUNC(test_vand_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vand.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vand_vx_32, .-test_vand_vx_32

TEST_FUNC(test_vand_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vand.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vand_vx_32_vm, .-test_vand_vx_32_vm

TEST_FUNC(test_vand_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vand.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vand_vx_64, .-test_vand_vx_64

TEST_FUNC(test_vand_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vand.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vand_vx_64_vm, .-test_vand_vx_64_vm

/* vand.vi */
TEST_FUNC(test_vand_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vand.vi         v4, v0, -16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vand_vi_8, .-test_vand_vi_8

TEST_FUNC(test_vand_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vand.vi         v4, v2, 0xf, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vand_vi_8_vm, .-test_vand_vi_8_vm

TEST_FUNC(test_vand_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vand.vi         v4, v0, -16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vand_vi_16, .-test_vand_vi_16

TEST_FUNC(test_vand_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vand.vi         v4, v2, 0xf, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vand_vi_16_vm, .-test_vand_vi_16_vm

TEST_FUNC(test_vand_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vand.vi         v4, v0, -16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vand_vi_32, .-test_vand_vi_32

TEST_FUNC(test_vand_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vand.vi         v4, v2, 0xf, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vand_vi_32_vm, .-test_vand_vi_32_vm

TEST_FUNC(test_vand_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vand.vi         v4, v0, -16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vand_vi_64, .-test_vand_vi_64

TEST_FUNC(test_vand_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vand.vi         v4, v2, 0xf, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vand_vi_64_vm, .-test_vand_vi_64_vm
/* vor.vv */
TEST_FUNC(test_vor_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vor.vv          v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vor_vv_8, .-test_vor_vv_8

TEST_FUNC(test_vor_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vor.vv          v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vor_vv_8_vm, .-test_vor_vv_8_vm

TEST_FUNC(test_vor_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vor.vv          v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vor_vv_16, .-test_vor_vv_16

TEST_FUNC(test_vor_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vor.vv          v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vor_vv_16_vm, .-test_vor_vv_16_vm

TEST_FUNC(test_vor_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vor.vv          v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vor_vv_32, .-test_vor_vv_32

TEST_FUNC(test_vor_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vor.vv          v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vor_vv_32_vm, .-test_vor_vv_32_vm

TEST_FUNC(test_vor_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vor.vv          v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vor_vv_64, .-test_vor_vv_64

TEST_FUNC(test_vor_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vor.vv          v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vor_vv_64_vm, .-test_vor_vv_64_vm

/* vor.vx */
TEST_FUNC(test_vor_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vor.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vor_vx_8, .-test_vor_vx_8

TEST_FUNC(test_vor_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vor_vx_8_vm, .-test_vor_vx_8_vm

TEST_FUNC(test_vor_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vor.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vor_vx_16, .-test_vor_vx_16

TEST_FUNC(test_vor_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vor_vx_16_vm, .-test_vor_vx_16_vm

TEST_FUNC(test_vor_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vor.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vor_vx_32, .-test_vor_vx_32

TEST_FUNC(test_vor_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vor_vx_32_vm, .-test_vor_vx_32_vm

TEST_FUNC(test_vor_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vor.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vor_vx_64, .-test_vor_vx_64

TEST_FUNC(test_vor_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vor_vx_64_vm, .-test_vor_vx_64_vm

/* vor.vi */
TEST_FUNC(test_vor_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vor.vi         v4, v0, -16
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vor_vi_8, .-test_vor_vi_8

TEST_FUNC(test_vor_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vor_vi_8_vm, .-test_vor_vi_8_vm

TEST_FUNC(test_vor_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vor.vi         v4, v0, -16
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vor_vi_16, .-test_vor_vi_16

TEST_FUNC(test_vor_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vor_vi_16_vm, .-test_vor_vi_16_vm

TEST_FUNC(test_vor_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vor.vi         v4, v0, -16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vor_vi_32, .-test_vor_vi_32

TEST_FUNC(test_vor_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vor_vi_32_vm, .-test_vor_vi_32_vm

TEST_FUNC(test_vor_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vor.vi         v4, v0, -16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vor_vi_64, .-test_vor_vi_64

TEST_FUNC(test_vor_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vor_vi_64_vm, .-test_vor_vi_64_vm
/* vxor.vv */
TEST_FUNC(test_vxor_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vxor.vv         v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vxor_vv_8, .-test_vxor_vv_8

TEST_FUNC(test_vxor_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v8, (a4)
        vsb.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vxor.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v8, (a2)
        ret
        .size   test_vxor_vv_8_vm, .-test_vxor_vv_8_vm

TEST_FUNC(test_vxor_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vxor.vv         v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vxor_vv_16, .-test_vxor_vv_16

TEST_FUNC(test_vxor_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vxor.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v8, (a2)
        ret
        .size   test_vxor_vv_16_vm, .-test_vxor_vv_16_vm

TEST_FUNC(test_vxor_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vxor.vv         v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vxor_vv_32, .-test_vxor_vv_32

TEST_FUNC(test_vxor_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vxor.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v8, (a2)
        ret
        .size   test_vxor_vv_32_vm, .-test_vxor_vv_32_vm

TEST_FUNC(test_vxor_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vxor.vv         v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vxor_vv_64, .-test_vxor_vv_64

TEST_FUNC(test_vxor_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vxor.vv         v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v8, (a2)
        ret
        .size   test_vxor_vv_64_vm, .-test_vxor_vv_64_vm

/* vxor.vx */
TEST_FUNC(test_vxor_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vxor.vx         v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vxor_vx_8, .-test_vxor_vx_8

TEST_FUNC(test_vxor_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vxor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vxor_vx_8_vm, .-test_vxor_vx_8_vm

TEST_FUNC(test_vxor_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vxor.vx         v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vxor_vx_16, .-test_vxor_vx_16

TEST_FUNC(test_vxor_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vxor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vxor_vx_16_vm, .-test_vxor_vx_16_vm

TEST_FUNC(test_vxor_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vxor.vx         v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vxor_vx_32, .-test_vxor_vx_32

TEST_FUNC(test_vxor_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vxor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vxor_vx_32_vm, .-test_vxor_vx_32_vm

TEST_FUNC(test_vxor_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vxor.vx         v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vxor_vx_64, .-test_vxor_vx_64

TEST_FUNC(test_vxor_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vxor.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vxor_vx_64_vm, .-test_vxor_vx_64_vm

/* vxor.vi */
TEST_FUNC(test_vxor_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vxor.vi         v4, v0, -16 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vxor_vi_8, .-test_vxor_vi_8

TEST_FUNC(test_vxor_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vxor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a1)
        ret
        .size   test_vxor_vi_8_vm, .-test_vxor_vi_8_vm

TEST_FUNC(test_vxor_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vxor.vi         v4, v0, -16 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vxor_vi_16, .-test_vxor_vi_16

TEST_FUNC(test_vxor_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vxor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a1)
        ret
        .size   test_vxor_vi_16_vm, .-test_vxor_vi_16_vm

TEST_FUNC(test_vxor_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vxor.vi         v4, v0, -16 
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vxor_vi_32, .-test_vxor_vi_32

TEST_FUNC(test_vxor_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vxor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vxor_vi_32_vm, .-test_vxor_vi_32_vm

TEST_FUNC(test_vxor_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vxor.vi         v4, v0, -16 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vxor_vi_64, .-test_vxor_vi_64

TEST_FUNC(test_vxor_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vxor.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vxor_vi_64_vm, .-test_vxor_vi_64_vm

/* vadd.vv */
TEST_FUNC(test_vadd_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vadd.vv         v4, v0, v2
        vsb.v           v4, (a3)
        ret
        .size   test_vadd_vv_8, .-test_vadd_vv_8

TEST_FUNC(test_vadd_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vadd.vv         v4, v2, v4, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vadd_vv_8_vm, .-test_vadd_vv_8_vm

TEST_FUNC(test_vadd_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vadd.vv         v4, v0, v2
        vsh.v           v4, (a3)
        ret
        .size   test_vadd_vv_16, .-test_vadd_vv_16

TEST_FUNC(test_vadd_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vadd.vv         v4, v2, v4, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vadd_vv_16_vm, .-test_vadd_vv_16_vm

TEST_FUNC(test_vadd_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vadd.vv         v4, v0, v2
        vsw.v           v4, (a3)
        ret
        .size   test_vadd_vv_32, .-test_vadd_vv_32

TEST_FUNC(test_vadd_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vadd.vv         v4, v2, v4, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vadd_vv_32_vm, .-test_vadd_vv_32_vm

TEST_FUNC(test_vadd_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vadd.vv         v4, v0, v2
        vse.v           v4, (a3)
        ret
        .size   test_vadd_vv_64, .-test_vadd_vv_64

TEST_FUNC(test_vadd_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vadd.vv         v4, v2, v4, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vadd_vv_64_vm, .-test_vadd_vv_64_vm

/* vadd.vx */
TEST_FUNC(test_vadd_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vadd.vx         v4, v0, a2
        vsb.v           v4, (a3)
        ret
        .size   test_vadd_vx_8, .-test_vadd_vx_8

TEST_FUNC(test_vadd_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vadd.vx         v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vadd_vx_8_vm, .-test_vadd_vx_8_vm

TEST_FUNC(test_vadd_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vadd.vx         v4, v0, a2
        vsh.v           v4, (a3)
        ret
        .size   test_vadd_vx_16, .-test_vadd_vx_16

TEST_FUNC(test_vadd_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vadd.vx         v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vadd_vx_16_vm, .-test_vadd_vx_16_vm

TEST_FUNC(test_vadd_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vadd.vx         v4, v0, a2
        vsw.v           v4, (a3)
        ret
        .size   test_vadd_vx_32, .-test_vadd_vx_32

TEST_FUNC(test_vadd_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vadd.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vadd_vx_32_vm, .-test_vadd_vx_32_vm

TEST_FUNC(test_vadd_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vadd.vx         v4, v0, a2
        vse.v           v4, (a3)
        ret
        .size   test_vadd_vx_64, .-test_vadd_vx_64

TEST_FUNC(test_vadd_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vadd.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vadd_vx_64_vm, .-test_vadd_vx_64_vm

/* vadd.vi */
TEST_FUNC(test_vadd_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vadd.vi         v4, v0, -5 
        vsb.v           v4, (a2)
        ret
        .size   test_vadd_vi_8, .-test_vadd_vi_8

TEST_FUNC(test_vadd_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vadd.vi         v4, v2, 5, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vadd_vi_8_vm, .-test_vadd_vi_8_vm

TEST_FUNC(test_vadd_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vadd.vi         v4, v0, -5 
        vsh.v           v4, (a2)
        ret
        .size   test_vadd_vi_16, .-test_vadd_vi_16

TEST_FUNC(test_vadd_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vadd.vi         v4, v2, 5, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vadd_vi_16_vm, .-test_vadd_vi_16_vm

TEST_FUNC(test_vadd_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vadd.vi         v4, v0, -5 
        vsw.v           v4, (a2)
        ret
        .size   test_vadd_vi_32, .-test_vadd_vi_32

TEST_FUNC(test_vadd_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vadd.vi         v4, v2, 5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vadd_vi_32_vm, .-test_vadd_vi_32_vm

TEST_FUNC(test_vadd_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vadd.vi         v4, v0, -16 
        vse.v           v4, (a2)
        ret
        .size   test_vadd_vi_64, .-test_vadd_vi_64

TEST_FUNC(test_vadd_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vadd.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vadd_vi_64_vm, .-test_vadd_vi_64_vm

/* vsub.vv */
TEST_FUNC(test_vsub_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsub.vv         v6, v0, v2
        vsb.v           v6, (a3)
        ret
        .size   test_vsub_vv_8, .-test_vsub_vv_8

TEST_FUNC(test_vsub_vv_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsub.vv         v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vsub_vv_8_vm, .-test_vsub_vv_8_vm

TEST_FUNC(test_vsub_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsub.vv         v6, v0, v2
        vsh.v           v6, (a3)
        ret
        .size   test_vsub_vv_16, .-test_vsub_vv_16

TEST_FUNC(test_vsub_vv_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsub.vv         v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vsub_vv_16_vm, .-test_vsub_vv_16_vm

TEST_FUNC(test_vsub_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsub.vv         v6, v0, v2
        vsw.v           v6, (a3)
        ret
        .size   test_vsub_vv_32, .-test_vsub_vv_32

TEST_FUNC(test_vsub_vv_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsub.vv         v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vsub_vv_32_vm, .-test_vsub_vv_32_vm

TEST_FUNC(test_vsub_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsub.vv         v6, v0, v2
        vse.v           v6, (a3)
        ret
        .size   test_vsub_vv_64, .-test_vsub_vv_64

TEST_FUNC(test_vsub_vv_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsub.vv         v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vsub_vv_64_vm, .-test_vsub_vv_64_vm

/* vsub.vx */
TEST_FUNC(test_vsub_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsub.vx         v4, v0, a2
        vsb.v           v4, (a3)
        ret
        .size   test_vsub_vx_8, .-test_vsub_vx_8

TEST_FUNC(test_vsub_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsub.vx         v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vsub_vx_8_vm, .-test_vsub_vx_8_vm

TEST_FUNC(test_vsub_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsub.vx         v4, v0, a2
        vsh.v           v4, (a3)
        ret
        .size   test_vsub_vx_16, .-test_vsub_vx_16

TEST_FUNC(test_vsub_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsub.vx         v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vsub_vx_16_vm, .-test_vsub_vx_16_vm

TEST_FUNC(test_vsub_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsub.vx         v4, v0, a2
        vsw.v           v4, (a3)
        ret
        .size   test_vsub_vx_32, .-test_vsub_vx_32

TEST_FUNC(test_vsub_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsub.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsub_vx_32_vm, .-test_vsub_vx_32_vm

TEST_FUNC(test_vsub_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsub.vx         v4, v0, a2
        vse.v           v4, (a3)
        ret
        .size   test_vsub_vx_64, .-test_vsub_vx_64

TEST_FUNC(test_vsub_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vsub.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsub_vx_64_vm, .-test_vsub_vx_64_vm

/* vrsub.vx */
TEST_FUNC(test_vrsub_vx_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vrsub.vx        v4, v0, a2
        vsb.v           v4, (a3)
        ret
        .size   test_vrsub_vx_8, .-test_vrsub_vx_8

TEST_FUNC(test_vrsub_vx_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vrsub.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vrsub_vx_8_vm, .-test_vrsub_vx_8_vm

TEST_FUNC(test_vrsub_vx_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vrsub.vx        v4, v0, a2
        vsh.v           v4, (a3)
        ret
        .size   test_vrsub_vx_16, .-test_vrsub_vx_16

TEST_FUNC(test_vrsub_vx_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vrsub.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vrsub_vx_16_vm, .-test_vrsub_vx_16_vm

TEST_FUNC(test_vrsub_vx_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vrsub.vx         v4, v0, a2
        vsw.v           v4, (a3)
        ret
        .size   test_vrsub_vx_32, .-test_vrsub_vx_32

TEST_FUNC(test_vrsub_vx_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vrsub.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vrsub_vx_32_vm, .-test_vrsub_vx_32_vm

TEST_FUNC(test_vrsub_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vrsub.vx         v4, v0, a2
        vse.v           v4, (a3)
        ret
        .size   test_vrsub_vx_64, .-test_vrsub_vx_64

TEST_FUNC(test_vrsub_vx_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vse.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vrsub.vx         v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vrsub_vx_64_vm, .-test_vrsub_vx_64_vm

/* vrsub.vi */
TEST_FUNC(test_vrsub_vi_8)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vrsub.vi         v4, v0, -5 
        vsb.v           v4, (a2)
        ret
        .size   test_vrsub_vi_8, .-test_vrsub_vi_8

TEST_FUNC(test_vrsub_vi_8_vm)
        vsetvli         t1, x0, e8, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vrsub.vi         v4, v2, 5, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vrsub_vi_8_vm, .-test_vrsub_vi_8_vm

TEST_FUNC(test_vrsub_vi_16)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vrsub.vi         v4, v0, -5 
        vsh.v           v4, (a2)
        ret
        .size   test_vrsub_vi_16, .-test_vrsub_vi_16

TEST_FUNC(test_vrsub_vi_16_vm)
        vsetvli         t1, x0, e16, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vrsub.vi         v4, v2, 5, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vrsub_vi_16_vm, .-test_vrsub_vi_16_vm

TEST_FUNC(test_vrsub_vi_32)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vrsub.vi         v4, v0, -5 
        vsw.v           v4, (a2)
        ret
        .size   test_vrsub_vi_32, .-test_vrsub_vi_32

TEST_FUNC(test_vrsub_vi_32_vm)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vrsub.vi         v4, v2, 5, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vrsub_vi_32_vm, .-test_vrsub_vi_32_vm

TEST_FUNC(test_vrsub_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a2)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vrsub.vi         v4, v0, -16 
        vse.v           v4, (a2)
        ret
        .size   test_vrsub_vi_64, .-test_vrsub_vi_64

TEST_FUNC(test_vrsub_vi_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vse.v           v4, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0), v0.t
        vrsub.vi         v4, v2, 15, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vrsub_vi_64_vm, .-test_vrsub_vi_64_vm

/* vwaddu.vv */
TEST_FUNC(test_vwaddu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwaddu.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vv_8, .-test_vwaddu_vv_8

TEST_FUNC(test_vwaddu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwaddu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vv_8_vm, .-test_vwaddu_vv_8_vm

TEST_FUNC(test_vwaddu_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwaddu.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vv_16, .-test_vwaddu_vv_16

TEST_FUNC(test_vwaddu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwaddu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vv_16_vm, .-test_vwaddu_vv_16_vm

TEST_FUNC(test_vwaddu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwaddu.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vv_32, .-test_vwaddu_vv_32

TEST_FUNC(test_vwaddu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwaddu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vv_32_vm, .-test_vwaddu_vv_32_vm

/* vwsubu.vv */
TEST_FUNC(test_vwsubu_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwsubu.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vv_8, .-test_vwsubu_vv_8

TEST_FUNC(test_vwsubu_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwsubu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vv_8_vm, .-test_vwsubu_vv_8_vm

TEST_FUNC(test_vwsubu_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwsubu.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vv_16, .-test_vwsubu_vv_16

TEST_FUNC(test_vwsubu_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwsubu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vv_16_vm, .-test_vwsubu_vv_16_vm

TEST_FUNC(test_vwsubu_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwsubu.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vv_32, .-test_vwsubu_vv_32

TEST_FUNC(test_vwsubu_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwsubu.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vv_32_vm, .-test_vwsubu_vv_32_vm

/* vwaddu.vx */
TEST_FUNC(test_vwaddu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwaddu.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vx_8, .-test_vwaddu_vx_8

TEST_FUNC(test_vwaddu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwaddu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vx_8_vm, .-test_vwaddu_vx_8_vm

TEST_FUNC(test_vwaddu_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwaddu.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vx_16, .-test_vwaddu_vx_16

TEST_FUNC(test_vwaddu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwaddu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vx_16_vm, .-test_vwaddu_vx_16_vm

TEST_FUNC(test_vwaddu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwaddu.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_vx_32, .-test_vwaddu_vx_32

TEST_FUNC(test_vwaddu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwaddu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_vx_32_vm, .-test_vwaddu_vx_32_vm

/* vwsubu.vx */
TEST_FUNC(test_vwsubu_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwsubu.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vx_8, .-test_vwsubu_vx_8

TEST_FUNC(test_vwsubu_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwsubu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vx_8_vm, .-test_vwsubu_vx_8_vm

TEST_FUNC(test_vwsubu_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwsubu.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vx_16, .-test_vwsubu_vx_16

TEST_FUNC(test_vwsubu_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwsubu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vx_16_vm, .-test_vwsubu_vx_16_vm

TEST_FUNC(test_vwsubu_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwsubu.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_vx_32, .-test_vwsubu_vx_32

TEST_FUNC(test_vwsubu_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwsubu.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_vx_32_vm, .-test_vwsubu_vx_32_vm

/* vwadd.vv */
TEST_FUNC(test_vwadd_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwadd.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vv_8, .-test_vwadd_vv_8

TEST_FUNC(test_vwadd_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwadd.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vv_8_vm, .-test_vwadd_vv_8_vm

TEST_FUNC(test_vwadd_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwadd.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vv_16, .-test_vwadd_vv_16

TEST_FUNC(test_vwadd_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwadd.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vv_16_vm, .-test_vwadd_vv_16_vm

TEST_FUNC(test_vwadd_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwadd.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vv_32, .-test_vwadd_vv_32

TEST_FUNC(test_vwadd_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwadd.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vv_32_vm, .-test_vwadd_vv_32_vm

/* vwsub.vv */
TEST_FUNC(test_vwsub_vv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwsub.vv       v8, v0, v2
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vv_8, .-test_vwsub_vv_8

TEST_FUNC(test_vwsub_vv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwsub.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vv_8_vm, .-test_vwsub_vv_8_vm

TEST_FUNC(test_vwsub_vv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwsub.vv       v8, v0, v2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vv_16, .-test_vwsub_vv_16

TEST_FUNC(test_vwsub_vv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwsub.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vv_16_vm, .-test_vwsub_vv_16_vm

TEST_FUNC(test_vwsub_vv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwsub.vv       v8, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vv_32, .-test_vwsub_vv_32

TEST_FUNC(test_vwsub_vv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwsub.vv       v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vv_32_vm, .-test_vwsub_vv_32_vm

/* vwadd.vx */
TEST_FUNC(test_vwadd_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwadd.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vx_8, .-test_vwadd_vx_8

TEST_FUNC(test_vwadd_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwadd.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vx_8_vm, .-test_vwadd_vx_8_vm

TEST_FUNC(test_vwadd_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwadd.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vx_16, .-test_vwadd_vx_16

TEST_FUNC(test_vwadd_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwadd.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vx_16_vm, .-test_vwadd_vx_16_vm

TEST_FUNC(test_vwadd_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwadd.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_vx_32, .-test_vwadd_vx_32

TEST_FUNC(test_vwadd_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwadd.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_vx_32_vm, .-test_vwadd_vx_32_vm

/* vwsub.vx */
TEST_FUNC(test_vwsub_vx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vwsub.vx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vx_8, .-test_vwsub_vx_8

TEST_FUNC(test_vwsub_vx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vwsub.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vx_8_vm, .-test_vwsub_vx_8_vm

TEST_FUNC(test_vwsub_vx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vwsub.vx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vx_16, .-test_vwsub_vx_16

TEST_FUNC(test_vwsub_vx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vwsub.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vx_16_vm, .-test_vwsub_vx_16_vm

TEST_FUNC(test_vwsub_vx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vwsub.vx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_vx_32, .-test_vwsub_vx_32

TEST_FUNC(test_vwsub_vx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vwsub.vx       v8, v2, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_vx_32_vm, .-test_vwsub_vx_32_vm

/* vwaddu.wv */
TEST_FUNC(test_vwaddu_wv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v4, (a2)
        vwaddu.wv       v8, v0, v4
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wv_8, .-test_vwaddu_wv_8

TEST_FUNC(test_vwaddu_wv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vwaddu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wv_8_vm, .-test_vwaddu_wv_8_vm

TEST_FUNC(test_vwaddu_wv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v4,(a2)
        vwaddu.wv       v8, v0, v4
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wv_16, .-test_vwaddu_wv_16

TEST_FUNC(test_vwaddu_wv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vwaddu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wv_16_vm, .-test_vwaddu_wv_16_vm

TEST_FUNC(test_vwaddu_wv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v4, (a2)
        vwaddu.wv       v8, v0, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wv_32, .-test_vwaddu_wv_32

TEST_FUNC(test_vwaddu_wv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vwaddu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wv_32_vm, .-test_vwaddu_wv_32_vm

/* vwsubu.wv */
TEST_FUNC(test_vwsubu_wv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v4, (a2)
        vwsubu.wv       v8, v0, v4
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wv_8, .-test_vwsubu_wv_8

TEST_FUNC(test_vwsubu_wv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vwsubu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wv_8_vm, .-test_vwsubu_wv_8_vm

TEST_FUNC(test_vwsubu_wv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v4, (a2)
        vwsubu.wv       v8, v0, v4
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wv_16, .-test_vwsubu_wv_16

TEST_FUNC(test_vwsubu_wv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vwsubu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wv_16_vm, .-test_vwsubu_wv_16_vm

TEST_FUNC(test_vwsubu_wv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v4, (a2)
        vwsubu.wv       v8, v0, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wv_32, .-test_vwsubu_wv_32

TEST_FUNC(test_vwsubu_wv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vwsubu.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wv_32_vm, .-test_vwsubu_wv_32_vm

/* vwaddu.wx */
TEST_FUNC(test_vwaddu_wx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vwaddu.wx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wx_8, .-test_vwaddu_wx_8

TEST_FUNC(test_vwaddu_wx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vwaddu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wx_8_vm, .-test_vwaddu_wx_8_vm

TEST_FUNC(test_vwaddu_wx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vwaddu.wx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wx_16, .-test_vwaddu_wx_16

TEST_FUNC(test_vwaddu_wx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vwaddu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wx_16_vm, .-test_vwaddu_wx_16_vm

TEST_FUNC(test_vwaddu_wx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vwaddu.wx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwaddu_wx_32, .-test_vwaddu_wx_32

TEST_FUNC(test_vwaddu_wx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vwaddu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwaddu_wx_32_vm, .-test_vwaddu_wx_32_vm

/* vwsubu.wx */
TEST_FUNC(test_vwsubu_wx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vwsubu.wx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wx_8, .-test_vwsubu_wx_8

TEST_FUNC(test_vwsubu_wx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vwsubu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wx_8_vm, .-test_vwsubu_wx_8_vm

TEST_FUNC(test_vwsubu_wx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vwsubu.wx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wx_16, .-test_vwsubu_wx_16

TEST_FUNC(test_vwsubu_wx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vwsubu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wx_16_vm, .-test_vwsubu_wx_16_vm

TEST_FUNC(test_vwsubu_wx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vwsubu.wx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsubu_wx_32, .-test_vwsubu_wx_32

TEST_FUNC(test_vwsubu_wx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vwsubu.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsubu_wx_32_vm, .-test_vwsubu_wx_32_vm

/* vwadd.wv */
TEST_FUNC(test_vwadd_wv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v4, (a2)
        vwadd.wv       v8, v0, v4
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wv_8, .-test_vwadd_wv_8

TEST_FUNC(test_vwadd_wv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vwadd.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wv_8_vm, .-test_vwadd_wv_8_vm

TEST_FUNC(test_vwadd_wv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v4, (a2)
        vwadd.wv       v8, v0, v4
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wv_16, .-test_vwadd_wv_16

TEST_FUNC(test_vwadd_wv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vwadd.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wv_16_vm, .-test_vwadd_wv_16_vm

TEST_FUNC(test_vwadd_wv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v4, (a2)
        vwadd.wv       v8, v0, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wv_32, .-test_vwadd_wv_32

TEST_FUNC(test_vwadd_wv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vwadd.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wv_32_vm, .-test_vwadd_wv_32_vm

/* vwsub.wv */
TEST_FUNC(test_vwsub_wv_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vlb.v           v4, (a2)
        vwsub.wv       v8, v0, v4
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wv_8, .-test_vwsub_wv_8

TEST_FUNC(test_vwsub_wv_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vwsub.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wv_8_vm, .-test_vwsub_wv_8_vm

TEST_FUNC(test_vwsub_wv_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vlh.v           v4, (a2)
        vwsub.wv       v8, v0, v4
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wv_16, .-test_vwsub_wv_16

TEST_FUNC(test_vwsub_wv_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vwsub.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wv_16_vm, .-test_vwsub_wv_16_vm

TEST_FUNC(test_vwsub_wv_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vlw.v           v4, (a2)
        vwsub.wv       v8, v0, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wv_32, .-test_vwsub_wv_32

TEST_FUNC(test_vwsub_wv_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vwsub.wv       v8, v4, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wv_32_vm, .-test_vwsub_wv_32_vm

/* vwadd.wx */
TEST_FUNC(test_vwadd_wx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vwadd.wx       v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wx_8, .-test_vwadd_wx_8

TEST_FUNC(test_vwadd_wx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vwadd.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wx_8_vm, .-test_vwadd_wx_8_vm

TEST_FUNC(test_vwadd_wx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vwadd.wx        v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wx_16, .-test_vwadd_wx_16

TEST_FUNC(test_vwadd_wx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vwadd.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wx_16_vm, .-test_vwadd_wx_16_vm

TEST_FUNC(test_vwadd_wx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vwadd.wx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwadd_wx_32, .-test_vwadd_wx_32

TEST_FUNC(test_vwadd_wx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vwadd.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwadd_wx_32_vm, .-test_vwadd_wx_32_vm

/* vwsub.wx */
TEST_FUNC(test_vwsub_wx_8)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e16, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vwsub.wx        v8, v0, a2 
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wx_8, .-test_vwsub_wx_8

TEST_FUNC(test_vwsub_wx_8_vm)
        vsetvli         t1, x0, e16, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        vwsub.wx        v8, v4, a1, v0.t
        vsetvli         t1, x0, e16, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wx_8_vm, .-test_vwsub_wx_8_vm

TEST_FUNC(test_vwsub_wx_16)
        vsetvli         t1, x0, e32, m4
        vlh.v           v8, (a4)
        vsh.v           v8, (a3)
        vsetvli         t1, a0, e32, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vwsub.wx       v8, v0, a2
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wx_16, .-test_vwsub_wx_16

TEST_FUNC(test_vwsub_wx_16_vm)
        vsetvli         t1, x0, e32, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e16, m2
        vwsub.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e32, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wx_16_vm, .-test_vwsub_wx_16_vm

TEST_FUNC(test_vwsub_wx_32)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vwsub.wx       v8, v0, a2 
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsub_wx_32, .-test_vwsub_wx_32

TEST_FUNC(test_vwsub_wx_32_vm)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a4)
        vse.v           v8, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a0)
        vsetvli         t1, x0, e32, m2
        vwsub.wx       v8, v4, a1, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a2)
        ret
        .size   test_vwsub_wx_32_vm, .-test_vwsub_wx_32_vm

/* vadc.vvm */
TEST_FUNC(test_vadc_vvm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vadc_vvm_8, .-test_vadc_vvm_8

TEST_FUNC(test_vadc_vvm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vadc.vvm         v6, v2, v4, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vadc_vvm_8_vm, .-test_vadc_vvm_8_vm
TEST_FUNC(test_vadc_vvm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vadc_vvm_16, .-test_vadc_vvm_16

TEST_FUNC(test_vadc_vvm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vadc.vvm        v6, v2, v4, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vadc_vvm_16_vm, .-test_vadc_vvm_16_vm

TEST_FUNC(test_vadc_vvm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vadc_vvm_32, .-test_vadc_vvm_32

TEST_FUNC(test_vadc_vvm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vadc.vvm         v6, v2, v4, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vadc_vvm_32_vm, .-test_vadc_vvm_32_vm

TEST_FUNC(test_vadc_vvm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vadc_vvm_64, .-test_vadc_vvm_64

TEST_FUNC(test_vadc_vvm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vadc.vvm         v6, v2, v4, v0
        vse.v           v6, (a2)
        ret
        .size   test_vadc_vvm_64_vm, .-test_vadc_vvm_64_vm

/* vsbc.vvm */
TEST_FUNC(test_vsbc_vvm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vsbc_vvm_8, .-test_vsbc_vvm_8

TEST_FUNC(test_vsbc_vvm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsbc.vvm         v6, v2, v4, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vsbc_vvm_8_vm, .-test_vsbc_vvm_8_vm
TEST_FUNC(test_vsbc_vvm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vsbc_vvm_16, .-test_vsbc_vvm_16

TEST_FUNC(test_vsbc_vvm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsbc.vvm        v6, v2, v4, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vsbc_vvm_16_vm, .-test_vsbc_vvm_16_vm

TEST_FUNC(test_vsbc_vvm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vsbc_vvm_32, .-test_vsbc_vvm_32

TEST_FUNC(test_vsbc_vvm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsbc.vvm         v6, v2, v4, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vsbc_vvm_32_vm, .-test_vsbc_vvm_32_vm

TEST_FUNC(test_vsbc_vvm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vsbc_vvm_64, .-test_vsbc_vvm_64

TEST_FUNC(test_vsbc_vvm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsbc.vvm         v6, v2, v4, v0
        vse.v           v6, (a2)
        ret
        .size   test_vsbc_vvm_64_vm, .-test_vsbc_vvm_64_vm

/* vadc.vxm */
TEST_FUNC(test_vadc_vxm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vadc_vxm_8, .-test_vadc_vxm_8

TEST_FUNC(test_vadc_vxm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vadc.vxm         v6, v2, a1, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vadc_vxm_8_vm, .-test_vadc_vxm_8_vm
TEST_FUNC(test_vadc_vxm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vadc_vxm_16, .-test_vadc_vxm_16

TEST_FUNC(test_vadc_vxm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vadc.vxm        v6, v2, a1, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vadc_vxm_16_vm, .-test_vadc_vxm_16_vm

TEST_FUNC(test_vadc_vxm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vadc_vxm_32, .-test_vadc_vxm_32

TEST_FUNC(test_vadc_vxm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vadc.vxm        v6, v2, a1, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vadc_vxm_32_vm, .-test_vadc_vxm_32_vm

TEST_FUNC(test_vadc_vxm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vadc_vxm_64, .-test_vadc_vxm_64

TEST_FUNC(test_vadc_vxm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vadc.vxm         v6, v2, a1, v0
        vse.v           v6, (a2)
        ret
        .size   test_vadc_vxm_64_vm, .-test_vadc_vxm_64_vm

/* vsbc.vxm */
TEST_FUNC(test_vsbc_vxm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vsbc_vxm_8, .-test_vsbc_vxm_8

TEST_FUNC(test_vsbc_vxm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vsbc.vxm         v6, v2, a1, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vsbc_vxm_8_vm, .-test_vsbc_vxm_8_vm
TEST_FUNC(test_vsbc_vxm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vsbc_vxm_16, .-test_vsbc_vxm_16

TEST_FUNC(test_vsbc_vxm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vsbc.vxm        v6, v2, a1, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vsbc_vxm_16_vm, .-test_vsbc_vxm_16_vm

TEST_FUNC(test_vsbc_vxm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vsbc_vxm_32, .-test_vsbc_vxm_32

TEST_FUNC(test_vsbc_vxm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vsbc.vxm        v6, v2, a1, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vsbc_vxm_32_vm, .-test_vsbc_vxm_32_vm

TEST_FUNC(test_vsbc_vxm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vsbc_vxm_64, .-test_vsbc_vxm_64

TEST_FUNC(test_vsbc_vxm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vsbc.vxm         v6, v2, a1, v0
        vse.v           v6, (a2)
        ret
        .size   test_vsbc_vxm_64_vm, .-test_vsbc_vxm_64_vm

/* vadc.vim */
TEST_FUNC(test_vadc_vim_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vadc.vim        v6, v2, 15, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vadc_vim_8, .-test_vadc_vim_8

TEST_FUNC(test_vadc_vim_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vadc.vim         v6, v2, -16, v0
        vsb.v           v6, (a1)
        ret
        .size   test_vadc_vim_8_vm, .-test_vadc_vim_8_vm
TEST_FUNC(test_vadc_vim_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vadc.vim        v6, v2, 15, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vadc_vim_16, .-test_vadc_vim_16

TEST_FUNC(test_vadc_vim_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vadc.vim        v6, v2, -16, v0
        vsh.v           v6, (a1)
        ret
        .size   test_vadc_vim_16_vm, .-test_vadc_vim_16_vm

TEST_FUNC(test_vadc_vim_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vadc.vim        v6, v2, 15, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vadc_vim_32, .-test_vadc_vim_32

TEST_FUNC(test_vadc_vim_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vadc.vim        v6, v2, -16, v0
        vsw.v           v6, (a1)
        ret
        .size   test_vadc_vim_32_vm, .-test_vadc_vim_32_vm

TEST_FUNC(test_vadc_vim_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vadc.vim        v6, v2, 15, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vadc_vim_64, .-test_vadc_vim_64

TEST_FUNC(test_vadc_vim_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vadc.vim         v6, v2, -16, v0
        vse.v           v6, (a1)
        ret
        .size   test_vadc_vim_64_vm, .-test_vadc_vim_64_vm

/* vmadc.vvm */
TEST_FUNC(test_vmadc_vvm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmadc_vvm_8, .-test_vmadc_vvm_8

TEST_FUNC(test_vmadc_vvm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmadc.vvm         v6, v2, v4, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmadc_vvm_8_vm, .-test_vmadc_vvm_8_vm
TEST_FUNC(test_vmadc_vvm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmadc.vvm       v6, v2, v4, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmadc_vvm_16, .-test_vmadc_vvm_16

TEST_FUNC(test_vmadc_vvm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmadc.vvm       v6, v2, v4, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmadc_vvm_16_vm, .-test_vmadc_vvm_16_vm

TEST_FUNC(test_vmadc_vvm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmadc_vvm_32, .-test_vmadc_vvm_32

TEST_FUNC(test_vmadc_vvm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmadc.vvm         v6, v2, v4, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmadc_vvm_32_vm, .-test_vmadc_vvm_32_vm

TEST_FUNC(test_vmadc_vvm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmadc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmadc_vvm_64, .-test_vmadc_vvm_64

TEST_FUNC(test_vmadc_vvm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmadc.vvm         v6, v2, v4, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmadc_vvm_64_vm, .-test_vmadc_vvm_64_vm

/* vmsbc.vvm */
TEST_FUNC(test_vmsbc_vvm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vlb.v           v4, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsbc_vvm_8, .-test_vmsbc_vvm_8

TEST_FUNC(test_vmsbc_vvm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vmsbc.vvm         v6, v2, v4, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmsbc_vvm_8_vm, .-test_vmsbc_vvm_8_vm
TEST_FUNC(test_vmsbc_vvm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsbc_vvm_16, .-test_vmsbc_vvm_16

TEST_FUNC(test_vmsbc_vvm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vmsbc.vvm        v6, v2, v4, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmsbc_vvm_16_vm, .-test_vmsbc_vvm_16_vm

TEST_FUNC(test_vmsbc_vvm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsbc_vvm_32, .-test_vmsbc_vvm_32

TEST_FUNC(test_vmsbc_vvm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vmsbc.vvm         v6, v2, v4, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmsbc_vvm_32_vm, .-test_vmsbc_vvm_32_vm

TEST_FUNC(test_vmsbc_vvm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vle.v           v4, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsbc.vvm        v6, v2, v4, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsbc_vvm_64, .-test_vmsbc_vvm_64

TEST_FUNC(test_vmsbc_vvm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vmsbc.vvm         v6, v2, v4, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmsbc_vvm_64_vm, .-test_vmsbc_vvm_64_vm

/* vmadc.vxm */
TEST_FUNC(test_vmadc_vxm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmadc_vxm_8, .-test_vmadc_vxm_8

TEST_FUNC(test_vmadc_vxm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmadc.vxm         v6, v2, a1, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmadc_vxm_8_vm, .-test_vmadc_vxm_8_vm
TEST_FUNC(test_vmadc_vxm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmadc_vxm_16, .-test_vmadc_vxm_16

TEST_FUNC(test_vmadc_vxm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmadc.vxm        v6, v2, a1, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmadc_vxm_16_vm, .-test_vmadc_vxm_16_vm

TEST_FUNC(test_vmadc_vxm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmadc_vxm_32, .-test_vmadc_vxm_32

TEST_FUNC(test_vmadc_vxm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmadc.vxm        v6, v2, a1, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmadc_vxm_32_vm, .-test_vmadc_vxm_32_vm

TEST_FUNC(test_vmadc_vxm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmadc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmadc_vxm_64, .-test_vmadc_vxm_64

TEST_FUNC(test_vmadc_vxm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmadc.vxm         v6, v2, a1, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmadc_vxm_64_vm, .-test_vmadc_vxm_64_vm

/* vmsbc.vxm */
TEST_FUNC(test_vmsbc_vxm_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a5)
        vsb.v           v6, (a3)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, a0, e8, m2
        vmsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a3)
        ret
        .size   test_vmsbc_vxm_8, .-test_vmsbc_vxm_8

TEST_FUNC(test_vmsbc_vxm_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmsbc.vxm         v6, v2, a1, v0
        vsb.v           v6, (a2)
        ret
        .size   test_vmsbc_vxm_8_vm, .-test_vmsbc_vxm_8_vm
TEST_FUNC(test_vmsbc_vxm_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a5)
        vsh.v           v6, (a3)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, a0, e16, m2
        vmsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a3)
        ret
        .size   test_vmsbc_vxm_16, .-test_vmsbc_vxm_16

TEST_FUNC(test_vmsbc_vxm_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmsbc.vxm        v6, v2, a1, v0
        vsh.v           v6, (a2)
        ret
        .size   test_vmsbc_vxm_16_vm, .-test_vmsbc_vxm_16_vm

TEST_FUNC(test_vmsbc_vxm_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a5)
        vsw.v           v6, (a3)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, a0, e32, m2
        vmsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a3)
        ret
        .size   test_vmsbc_vxm_32, .-test_vmsbc_vxm_32

TEST_FUNC(test_vmsbc_vxm_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmsbc.vxm        v6, v2, a1, v0
        vsw.v           v6, (a2)
        ret
        .size   test_vmsbc_vxm_32_vm, .-test_vmsbc_vxm_32_vm

TEST_FUNC(test_vmsbc_vxm_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a5)
        vse.v           v6, (a3)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a4)
        vsetvli         t1, a0, e64, m2
        vmsbc.vxm        v6, v2, a2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a3)
        ret
        .size   test_vmsbc_vxm_64, .-test_vmsbc_vxm_64

TEST_FUNC(test_vmsbc_vxm_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmsbc.vxm         v6, v2, a1, v0
        vse.v           v6, (a2)
        ret
        .size   test_vmsbc_vxm_64_vm, .-test_vmsbc_vxm_64_vm

/* vmadc.vim */
TEST_FUNC(test_vmadc_vim_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vsb.v           v6, (a2)
        vlb.v           v2, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, a0, e8, m2
        vmadc.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v6, (a2)
        ret
        .size   test_vmadc_vim_8, .-test_vmadc_vim_8

TEST_FUNC(test_vmadc_vim_8_vm)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        vsb.v           v6, (a1)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a0)
        vmadc.vim         v6, v2, 15, v0
        vsb.v           v6, (a1)
        ret
        .size   test_vmadc_vim_8_vm, .-test_vmadc_vim_8_vm
TEST_FUNC(test_vmadc_vim_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vsh.v           v6, (a2)
        vlh.v           v2, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, a0, e16, m2
        vmadc.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v6, (a2)
        ret
        .size   test_vmadc_vim_16, .-test_vmadc_vim_16

TEST_FUNC(test_vmadc_vim_16_vm)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        vsh.v           v6, (a1)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a0)
        vmadc.vim        v6, v2, 15, v0
        vsh.v           v6, (a1)
        ret
        .size   test_vmadc_vim_16_vm, .-test_vmadc_vim_16_vm

TEST_FUNC(test_vmadc_vim_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vsw.v           v6, (a2)
        vlw.v           v2, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e32, m2
        vmadc.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e32, m2
        vsw.v           v6, (a2)
        ret
        .size   test_vmadc_vim_32, .-test_vmadc_vim_32

TEST_FUNC(test_vmadc_vim_32_vm)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        vsw.v           v6, (a1)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a0)
        vmadc.vim        v6, v2, 15, v0
        vsw.v           v6, (a1)
        ret
        .size   test_vmadc_vim_32_vm, .-test_vmadc_vim_32_vm

TEST_FUNC(test_vmadc_vim_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vse.v           v6, (a2)
        vle.v           v2, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, a0, e64, m2
        vmadc.vim        v6, v2, -16, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v6, (a2)
        ret
        .size   test_vmadc_vim_64, .-test_vmadc_vim_64

TEST_FUNC(test_vmadc_vim_64_vm)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        vse.v           v6, (a1)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a0)
        vmadc.vim         v6, v2, 15, v0
        vse.v           v6, (a1)
        ret
        .size   test_vmadc_vim_64_vm, .-test_vmadc_vim_64_vm


