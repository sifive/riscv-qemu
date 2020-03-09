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

/* vmand.mm */
TEST_FUNC(test_vmand_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmand.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmand_mm_8, .-test_vmand_mm_8

TEST_FUNC(test_vmand_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmand.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmand_mm_16, .-test_vmand_mm_16

TEST_FUNC(test_vmand_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmand.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmand_mm_32, .-test_vmand_mm_32

TEST_FUNC(test_vmand_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmand.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmand_mm_64, .-test_vmand_mm_64

/* vmnand.mm */
TEST_FUNC(test_vmnand_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmnand.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmnand_mm_8, .-test_vmnand_mm_8

TEST_FUNC(test_vmnand_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmnand.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmnand_mm_16, .-test_vmnand_mm_16

TEST_FUNC(test_vmnand_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmnand.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmnand_mm_32, .-test_vmnand_mm_32

TEST_FUNC(test_vmnand_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmnand.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmnand_mm_64, .-test_vmnand_mm_64

/* vmandnot.mm */
TEST_FUNC(test_vmandnot_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmandnot.mm     v2, v1, v0 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmandnot_mm_8, .-test_vmandnot_mm_8

TEST_FUNC(test_vmandnot_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmandnot.mm     v2, v1, v0 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmandnot_mm_16, .-test_vmandnot_mm_16

TEST_FUNC(test_vmandnot_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmandnot.mm     v2, v1, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmandnot_mm_32, .-test_vmandnot_mm_32

TEST_FUNC(test_vmandnot_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmandnot.mm     v2, v1, v0 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmandnot_mm_64, .-test_vmandnot_mm_64

/* vmxor.mm */
TEST_FUNC(test_vmxor_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmxor.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmxor_mm_8, .-test_vmxor_mm_8

TEST_FUNC(test_vmxor_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmxor.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmxor_mm_16, .-test_vmxor_mm_16

TEST_FUNC(test_vmxor_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmxor.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmxor_mm_32, .-test_vmxor_mm_32

TEST_FUNC(test_vmxor_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmxor.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmxor_mm_64, .-test_vmxor_mm_64

/* vmnor.mm */
TEST_FUNC(test_vmnor_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmnor_mm_8, .-test_vmnor_mm_8

TEST_FUNC(test_vmnor_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmnor_mm_16, .-test_vmnor_mm_16

TEST_FUNC(test_vmnor_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmnor.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmnor_mm_32, .-test_vmnor_mm_32

TEST_FUNC(test_vmnor_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmnor_mm_64, .-test_vmnor_mm_64

/* vmor.mm */
TEST_FUNC(test_vmor_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmor.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmor_mm_8, .-test_vmor_mm_8

TEST_FUNC(test_vmor_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmor.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmor_mm_16, .-test_vmor_mm_16

TEST_FUNC(test_vmor_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmor.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmor_mm_32, .-test_vmor_mm_32

TEST_FUNC(test_vmor_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmor.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmor_mm_64, .-test_vmor_mm_64

/* vmornot.mm */
TEST_FUNC(test_vmornot_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmornot.mm      v2, v1, v0 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmornot_mm_8, .-test_vmornot_mm_8

TEST_FUNC(test_vmornot_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmornot.mm      v2, v1, v0 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmornot_mm_16, .-test_vmornot_mm_16

TEST_FUNC(test_vmornot_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmornot.mm      v2, v1, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmornot_mm_32, .-test_vmornot_mm_32

TEST_FUNC(test_vmornot_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmornot.mm      v2, v1, v0 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmornot_mm_64, .-test_vmornot_mm_64

/* vmxnor.mm */
TEST_FUNC(test_vmxnor_mm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v1, (a2)
        vlb.v           v2, (a4)
        vsetvli         t1, a0, e8, m2
        vmxnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e8, m1
        vsb.v           v2, (a3)
        ret
        .size   test_vmxnor_mm_8, .-test_vmxnor_mm_8

TEST_FUNC(test_vmxnor_mm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v1, (a2)
        vlh.v           v2, (a4)
        vsetvli         t1, a0, e16, m2
        vmxnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e16, m1
        vsh.v           v2, (a3)
        ret
        .size   test_vmxnor_mm_16, .-test_vmxnor_mm_16

TEST_FUNC(test_vmxnor_mm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a1)
        vlw.v           v1, (a2)
        vlw.v           v2, (a4)
        vsetvli         t1, a0, e32, m2
        vmxnor.mm        v2, v0, v1
        vsetvli         t1, x0, e32, m1
        vsw.v           v2, (a3)
        ret
        .size   test_vmxnor_mm_32, .-test_vmxnor_mm_32

TEST_FUNC(test_vmxnor_mm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v1, (a2)
        vle.v           v2, (a4)
        vsetvli         t1, a0, e64, m2
        vmxnor.mm        v2, v0, v1 
        vsetvli         t1, x0, e64, m1
        vse.v           v2, (a3)
        ret
        .size   test_vmxnor_mm_64, .-test_vmxnor_mm_64

/* vmpopc.m */
TEST_FUNC(test_vmpopc_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v2, (a0)
        vsetvli         t1, a1, e8, m2
        vmpopc.m        a0, v2
        ret
        .size   test_vmpopc_m_8, .-test_vmpopc_m_8

TEST_FUNC(test_vmpopc_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v2, (a0)
        vsetvli         t1, x0, e8, m2
        vmpopc.m        a0, v2, v0.t
        ret
        .size   test_vmpopc_m_8_vm, .-test_vmpopc_m_8_vm

TEST_FUNC(test_vmpopc_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v2, (a0)
        vsetvli         t1, a1, e16, m2
        vmpopc.m        a0, v2 
        ret
        .size   test_vmpopc_m_16, .-test_vmpopc_m_16

TEST_FUNC(test_vmpopc_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vmpopc.m        a0, v2, v0.t 
        ret
        .size   test_vmpopc_m_16_vm, .-test_vmpopc_m_16_vm

TEST_FUNC(test_vmpopc_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v2, (a0)
        vsetvli         t1, a1, e32, m2
        vmpopc.m        a0, v2
        ret
        .size   test_vmpopc_m_32, .-test_vmpopc_m_32

TEST_FUNC(test_vmpopc_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v2, (a0)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vmpopc.m        a0, v2, v0.t
        ret
        .size   test_vmpopc_m_32_vm, .-test_vmpopc_m_32_vm

TEST_FUNC(test_vmpopc_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v2, (a0)
        vsetvli         t1, a1, e64, m2
        vmpopc.m        a0, v2 
        ret
        .size   test_vmpopc_m_64, .-test_vmpopc_m_64

TEST_FUNC(test_vmpopc_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v2, (a0)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vmpopc.m        a0, v2, v0.t 
        ret
        .size   test_vmpopc_m_64_vm, .-test_vmpopc_m_64_vm

/* vmfirst.m */
TEST_FUNC(test_vmfirst_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v2, (a0)
        vsetvli         t1, a1, e8, m2
        vmfirst.m       a0, v2
        ret
        .size   test_vmfirst_m_8, .-test_vmfirst_m_8

TEST_FUNC(test_vmfirst_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a1)
        vlb.v           v2, (a0)
        vsetvli         t1, x0, e8, m2
        vmfirst.m       a0, v2, v0.t
        ret
        .size   test_vmfirst_m_8_vm, .-test_vmfirst_m_8_vm

TEST_FUNC(test_vmfirst_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v2, (a0)
        vsetvli         t1, a1, e16, m2
        vmfirst.m       a0, v2 
        ret
        .size   test_vmfirst_m_16, .-test_vmfirst_m_16

TEST_FUNC(test_vmfirst_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a1)
        vlh.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vmfirst.m       a0, v2, v0.t 
        ret
        .size   test_vmfirst_m_16_vm, .-test_vmfirst_m_16_vm

TEST_FUNC(test_vmfirst_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v2, (a0)
        vsetvli         t1, a1, e32, m2
        vmfirst.m       a0, v2
        ret
        .size   test_vmfirst_m_32, .-test_vmfirst_m_32

TEST_FUNC(test_vmfirst_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v2, (a0)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e32, m2
        vmfirst.m       a0, v2, v0.t
        ret
        .size   test_vmfirst_m_32_vm, .-test_vmfirst_m_32_vm

TEST_FUNC(test_vmfirst_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v2, (a0)
        vsetvli         t1, a1, e64, m2
        vmfirst.m       a0, v2 
        ret
        .size   test_vmfirst_m_64, .-test_vmfirst_m_64

TEST_FUNC(test_vmfirst_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v2, (a0)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vmfirst.m       a0, v2, v0.t 
        ret
        .size   test_vmfirst_m_64_vm, .-test_vmfirst_m_64_vm

/* vmsbf.m */
TEST_FUNC(test_vmsbf_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, a3, e8, m2
        vmsbf.m         v2, v1
        vsb.v           v2, (a1)
        ret
        .size   test_vmsbf_m_8, .-test_vmsbf_m_8

TEST_FUNC(test_vmsbf_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, x0, e8, m2
        vmsbf.m         v2, v1, v0.t
        vsb.v           v2, (a1)
        ret
        .size   test_vmsbf_m_8_vm, .-test_vmsbf_m_8_vm

TEST_FUNC(test_vmsbf_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, a3, e16, m2
        vmsbf.m         v2, v1 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsbf_m_16, .-test_vmsbf_m_16

TEST_FUNC(test_vmsbf_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, x0, e16, m2
        vmsbf.m         v2, v1, v0.t 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsbf_m_16_vm, .-test_vmsbf_m_16_vm

TEST_FUNC(test_vmsbf_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vsetvli         t1, a3, e32, m2
        vmsbf.m         v2, v1
        vsw.v           v2, (a1)
        ret
        .size   test_vmsbf_m_32, .-test_vmsbf_m_32

TEST_FUNC(test_vmsbf_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vmsbf.m         v2, v1, v0.t
        vsw.v           v2, (a1)
        ret
        .size   test_vmsbf_m_32_vm, .-test_vmsbf_m_32_vm

TEST_FUNC(test_vmsbf_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vsetvli         t1, a3, e64, m2
        vmsbf.m         v2, v1 
        vse.v           v2, (a1)
        ret
        .size   test_vmsbf_m_64, .-test_vmsbf_m_64

TEST_FUNC(test_vmsbf_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vmsbf.m         v2, v1, v0.t 
        vse.v           v2, (a1)
        ret
        .size   test_vmsbf_m_64_vm, .-test_vmsbf_m_64_vm

/* vmsif.m */
TEST_FUNC(test_vmsif_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, a3, e8, m2
        vmsif.m         v2, v1
        vsb.v           v2, (a1)
        ret
        .size   test_vmsif_m_8, .-test_vmsif_m_8

TEST_FUNC(test_vmsif_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, x0, e8, m2
        vmsif.m         v2, v1, v0.t
        vsb.v           v2, (a1)
        ret
        .size   test_vmsif_m_8_vm, .-test_vmsif_m_8_vm

TEST_FUNC(test_vmsif_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, a3, e16, m2
        vmsif.m         v2, v1 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsif_m_16, .-test_vmsif_m_16

TEST_FUNC(test_vmsif_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, x0, e16, m2
        vmsif.m         v2, v1, v0.t 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsif_m_16_vm, .-test_vmsif_m_16_vm

TEST_FUNC(test_vmsif_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vsetvli         t1, a3, e32, m2
        vmsif.m         v2, v1
        vsw.v           v2, (a1)
        ret
        .size   test_vmsif_m_32, .-test_vmsif_m_32

TEST_FUNC(test_vmsif_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vmsif.m         v2, v1, v0.t
        vsw.v           v2, (a1)
        ret
        .size   test_vmsif_m_32_vm, .-test_vmsif_m_32_vm

TEST_FUNC(test_vmsif_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vsetvli         t1, a3, e64, m2
        vmsif.m         v2, v1 
        vse.v           v2, (a1)
        ret
        .size   test_vmsif_m_64, .-test_vmsif_m_64

TEST_FUNC(test_vmsif_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vmsif.m         v2, v1, v0.t 
        vse.v           v2, (a1)
        ret
        .size   test_vmsif_m_64_vm, .-test_vmsif_m_64_vm

/* vmsof.m */
TEST_FUNC(test_vmsof_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, a3, e8, m2
        vmsof.m         v2, v1
        vsb.v           v2, (a1)
        ret
        .size   test_vmsof_m_8, .-test_vmsof_m_8

TEST_FUNC(test_vmsof_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vlb.v           v1, (a0)
        vlb.v           v2, (a2)
        vsetvli         t1, x0, e8, m2
        vmsof.m         v2, v1, v0.t
        vsb.v           v2, (a1)
        ret
        .size   test_vmsof_m_8_vm, .-test_vmsof_m_8_vm

TEST_FUNC(test_vmsof_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, a3, e16, m2
        vmsof.m         v2, v1 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsof_m_16, .-test_vmsof_m_16

TEST_FUNC(test_vmsof_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vlh.v           v1, (a0)
        vlh.v           v2, (a2)
        vsetvli         t1, x0, e16, m2
        vmsof.m         v2, v1, v0.t 
        vsh.v           v2, (a1)
        ret
        .size   test_vmsof_m_16_vm, .-test_vmsof_m_16_vm

TEST_FUNC(test_vmsof_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vsetvli         t1, a3, e32, m2
        vmsof.m         v2, v1
        vsw.v           v2, (a1)
        ret
        .size   test_vmsof_m_32, .-test_vmsof_m_32

TEST_FUNC(test_vmsof_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v2, (a2)
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vmsof.m         v2, v1, v0.t
        vsw.v           v2, (a1)
        ret
        .size   test_vmsof_m_32_vm, .-test_vmsof_m_32_vm

TEST_FUNC(test_vmsof_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vsetvli         t1, a3, e64, m2
        vmsof.m         v2, v1 
        vse.v           v2, (a1)
        ret
        .size   test_vmsof_m_64, .-test_vmsof_m_64

TEST_FUNC(test_vmsof_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v2, (a2)
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vmsof.m         v2, v1, v0.t 
        vse.v           v2, (a1)
        ret
        .size   test_vmsof_m_64_vm, .-test_vmsof_m_64_vm

/* viota.m */
TEST_FUNC(test_viota_m_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v1, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a2)
        vsetvli         t1, a3, e8, m2
        viota.m         v2, v1
        vsetvli         t1, x0, e8, m2
        vsb.v           v2, (a1)
        ret
        .size   test_viota_m_8, .-test_viota_m_8

TEST_FUNC(test_viota_m_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vlb.v           v1, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a2)
        viota.m         v2, v1, v0.t
        vsb.v           v2, (a1)
        ret
        .size   test_viota_m_8_vm, .-test_viota_m_8_vm

TEST_FUNC(test_viota_m_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a3, e16, m2
        viota.m         v2, v1 
        vsetvli         t1, x0, e16, m2
        vsh.v           v2, (a1)
        ret
        .size   test_viota_m_16, .-test_viota_m_16

TEST_FUNC(test_viota_m_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vlh.v           v1, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        viota.m         v2, v1, v0.t 
        vsh.v           v2, (a1)
        ret
        .size   test_viota_m_16_vm, .-test_viota_m_16_vm

TEST_FUNC(test_viota_m_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a3, e32, m2
        viota.m         v2, v1
        vsetvli         t1, x0, e32, m2
        vsw.v           v2, (a1)
        ret
        .size   test_viota_m_32, .-test_viota_m_32

TEST_FUNC(test_viota_m_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        viota.m         v2, v1, v0.t
        vsw.v           v2, (a1)
        ret
        .size   test_viota_m_32_vm, .-test_viota_m_32_vm

TEST_FUNC(test_viota_m_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a3, e64, m2
        viota.m         v2, v1 
        vsetvli         t1, x0, e64, m2
        vse.v           v2, (a1)
        ret
        .size   test_viota_m_64, .-test_viota_m_64

TEST_FUNC(test_viota_m_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        viota.m         v2, v1, v0.t 
        vse.v           v2, (a1)
        ret
        .size   test_viota_m_64_vm, .-test_viota_m_64_vm

/* vid.v */
TEST_FUNC(test_vid_v_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v2, (a2)
        vsetvli         t1, a3, e8, m2
        vid.v           v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v2, (a1)
        ret
        .size   test_vid_v_8, .-test_vid_v_8

TEST_FUNC(test_vid_v_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vlb.v           v1, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a2)
        vid.v           v2, v0.t
        vsb.v           v2, (a1)
        ret
        .size   test_vid_v_8_vm, .-test_vid_v_8_vm

TEST_FUNC(test_vid_v_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a3, e16, m2
        vid.v           v2 
        vsetvli         t1, x0, e16, m2
        vsh.v           v2, (a1)
        ret
        .size   test_vid_v_16, .-test_vid_v_16

TEST_FUNC(test_vid_v_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vlh.v           v1, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vid.v           v2, v0.t 
        vsh.v           v2, (a1)
        ret
        .size   test_vid_v_16_vm, .-test_vid_v_16_vm

TEST_FUNC(test_vid_v_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a3, e32, m2
        vid.v           v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v2, (a1)
        ret
        .size   test_vid_v_32, .-test_vid_v_32

TEST_FUNC(test_vid_v_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a0)
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vid.v           v2, v0.t
        vsw.v           v2, (a1)
        ret
        .size   test_vid_v_32_vm, .-test_vid_v_32_vm

TEST_FUNC(test_vid_v_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a3, e64, m2
        vid.v           v2
        vsetvli         t1, x0, e64, m2
        vse.v           v2, (a1)
        ret
        .size   test_vid_v_64, .-test_vid_v_64

TEST_FUNC(test_vid_v_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a0)
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vid.v           v2, v0.t 
        vse.v           v2, (a1)
        ret
        .size   test_vid_v_64_vm, .-test_vid_v_64_vm

/* vext.x.v */
TEST_FUNC(test_vext_x_v_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a0)
        vext.x.v        a0, v0, a1 
        ret
        .size   test_vext_x_v_8, .-test_vext_x_v_8

TEST_FUNC(test_vext_x_v_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a0)
        vext.x.v        a0, v0, a1
        ret
        .size   test_vext_x_v_16, .-test_vext_x_v_16

TEST_FUNC(test_vext_x_v_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a0)
        vext.x.v        a0, v0, a1
        ret
        .size   test_vext_x_v_32, .-test_vext_x_v_32

TEST_FUNC(test_vext_x_v_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a0)
        vext.x.v        a0, v0, a1 
        ret
        .size   test_vext_x_v_64, .-test_vext_x_v_64

/* vmv.s.x */
TEST_FUNC(test_vmv_s_x_8)
        vsetvli         t1, x0, e8, m1
        vmv.s.x         v1, a0
        vsb.v           v1, (a1)
        ret
        .size   test_vmv_s_x_8, .-test_vmv_s_x_8

TEST_FUNC(test_vmv_s_x_16)
        vsetvli         t1, x0, e16, m1
        vmv.s.x         v1, a0
        vsh.v           v1, (a1)
        ret
        .size   test_vmv_s_x_16, .-test_vmv_s_x_16

TEST_FUNC(test_vmv_s_x_32)
        vsetvli         t1, x0, e32, m1
        vmv.s.x         v1, a0
        vsw.v           v1, (a1)
        ret
        .size   test_vmv_s_x_32, .-test_vmv_s_x_32

TEST_FUNC(test_vmv_s_x_64)
        vsetvli         t1, x0, e64, m1
        vmv.s.x         v1, a0 
        vse.v           v1, (a1)
        ret
        .size   test_vmv_s_x_64, .-test_vmv_s_x_64

/* vfmv.f.s */
TEST_FUNC(test_vfmv_f_s_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a0)
        vfmv.f.s        fa0, v0
        fmv.x.d         a0, fa0
        ret
        .size   test_vfmv_f_s_8, .-test_vfmv_f_s_8

TEST_FUNC(test_vfmv_f_s_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a0)
        vfmv.f.s        fa0, v0
        fmv.x.d         a0, fa0
        ret
        .size   test_vfmv_f_s_16, .-test_vfmv_f_s_16

TEST_FUNC(test_vfmv_f_s_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a0)
        vfmv.f.s        fa0, v0
        fmv.x.d         a0, fa0
        ret
        .size   test_vfmv_f_s_32, .-test_vfmv_f_s_32

TEST_FUNC(test_vfmv_f_s_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a0)
        vfmv.f.s        fa0, v0 
        fmv.x.d         a0, fa0
        ret
        .size   test_vfmv_f_s_64, .-test_vfmv_f_s_64

/* vfmv.s.f */
TEST_FUNC(test_vfmv_s_f_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v1, (a2)
        fmv.d.x         fa0, a0
        vfmv.s.f        v1, fa0
        vsb.v           v1, (a1)
        ret
        .size   test_vfmv_s_f_8, .-test_vfmv_s_f_8

TEST_FUNC(test_vfmv_s_f_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v1, (a2)
        fmv.d.x         fa0, a0
        vfmv.s.f        v1, fa0
        vsh.v           v1, (a1)
        ret
        .size   test_vfmv_s_f_16, .-test_vfmv_s_f_16

TEST_FUNC(test_vfmv_s_f_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v1, (a2)
        fmv.d.x         fa0, a0
        vfmv.s.f        v1, fa0
        vsw.v           v1, (a1)
        ret
        .size   test_vfmv_s_f_32, .-test_vfmv_s_f_32

TEST_FUNC(test_vfmv_s_f_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v1, (a2)
        fmv.d.x         fa0, a0
        vfmv.s.f        v1, fa0 
        vse.v           v1, (a1)
        ret
        .size   test_vfmv_s_f_64, .-test_vfmv_s_f_64

/* vslideup.vx */
TEST_FUNC(test_vslideup_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslideup.vx     v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslideup_vx_8, .-test_vslideup_vx_8

TEST_FUNC(test_vslideup_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslideup.vx     v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslideup_vx_8_vm, .-test_vslideup_vx_8_vm

TEST_FUNC(test_vslideup_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslideup.vx     v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslideup_vx_16, .-test_vslideup_vx_16

TEST_FUNC(test_vslideup_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslideup.vx     v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslideup_vx_16_vm, .-test_vslideup_vx_16_vm

TEST_FUNC(test_vslideup_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslideup.vx     v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslideup_vx_32, .-test_vslideup_vx_32

TEST_FUNC(test_vslideup_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslideup.vx     v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslideup_vx_32_vm, .-test_vslideup_vx_32_vm

TEST_FUNC(test_vslideup_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslideup.vx     v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslideup_vx_64, .-test_vslideup_vx_64

TEST_FUNC(test_vslideup_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslideup.vx     v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslideup_vx_64_vm, .-test_vslideup_vx_64_vm

/* vslideup.vi */
TEST_FUNC(test_vslideup_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslideup.vi     v4, v0, 0x8
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslideup_vi_8, .-test_vslideup_vi_8

TEST_FUNC(test_vslideup_vi_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslideup.vi     v4, v2, 0x8, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslideup_vi_8_vm, .-test_vslideup_vi_8_vm

TEST_FUNC(test_vslideup_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslideup.vi     v4, v0, 0x4
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslideup_vi_16, .-test_vslideup_vi_16

TEST_FUNC(test_vslideup_vi_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslideup.vi     v4, v2, 0x4, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslideup_vi_16_vm, .-test_vslideup_vi_16_vm

TEST_FUNC(test_vslideup_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslideup.vi     v4, v0, 0x2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslideup_vi_32, .-test_vslideup_vi_32

TEST_FUNC(test_vslideup_vi_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslideup.vi     v4, v2, 0x2, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslideup_vi_32_vm, .-test_vslideup_vi_32_vm

TEST_FUNC(test_vslideup_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslideup.vi     v4, v0, 0x1
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslideup_vi_64, .-test_vslideup_vi_64

TEST_FUNC(test_vslideup_vi_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslideup.vi     v4, v2, 0x1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslideup_vi_64_vm, .-test_vslideup_vi_64_vm

/* vslidedown.vx */
TEST_FUNC(test_vslidedown_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslidedown.vx   v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslidedown_vx_8, .-test_vslidedown_vx_8

TEST_FUNC(test_vslidedown_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslidedown.vx   v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslidedown_vx_8_vm, .-test_vslidedown_vx_8_vm

TEST_FUNC(test_vslidedown_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslidedown.vx   v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslidedown_vx_16, .-test_vslidedown_vx_16

TEST_FUNC(test_vslidedown_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslidedown.vx   v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslidedown_vx_16_vm, .-test_vslidedown_vx_16_vm

TEST_FUNC(test_vslidedown_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslidedown.vx   v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslidedown_vx_32, .-test_vslidedown_vx_32

TEST_FUNC(test_vslidedown_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslidedown.vx   v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslidedown_vx_32_vm, .-test_vslidedown_vx_32_vm

TEST_FUNC(test_vslidedown_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslidedown.vx   v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslidedown_vx_64, .-test_vslidedown_vx_64

TEST_FUNC(test_vslidedown_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslidedown.vx   v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslidedown_vx_64_vm, .-test_vslidedown_vx_64_vm

/* vslidedown.vi */
TEST_FUNC(test_vslidedown_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslidedown.vi   v4, v0, 0x8
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslidedown_vi_8, .-test_vslidedown_vi_8

TEST_FUNC(test_vslidedown_vi_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslidedown.vi   v4, v2, 0x8, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslidedown_vi_8_vm, .-test_vslidedown_vi_8_vm

TEST_FUNC(test_vslidedown_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslidedown.vi   v4, v0, 0x4
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslidedown_vi_16, .-test_vslidedown_vi_16

TEST_FUNC(test_vslidedown_vi_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslidedown.vi   v4, v2, 0x4, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslidedown_vi_16_vm, .-test_vslidedown_vi_16_vm

TEST_FUNC(test_vslidedown_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslidedown.vi   v4, v0, 0x2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslidedown_vi_32, .-test_vslidedown_vi_32

TEST_FUNC(test_vslidedown_vi_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslidedown.vi   v4, v2, 0x2, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslidedown_vi_32_vm, .-test_vslidedown_vi_32_vm

TEST_FUNC(test_vslidedown_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslidedown.vi   v4, v0, 0x1
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslidedown_vi_64, .-test_vslidedown_vi_64

TEST_FUNC(test_vslidedown_vi_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslidedown.vi   v4, v2, 0x1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslidedown_vi_64_vm, .-test_vslidedown_vi_64_vm

/* vslide1up.vx */
TEST_FUNC(test_vslide1up_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslide1up.vx    v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslide1up_vx_8, .-test_vslide1up_vx_8

TEST_FUNC(test_vslide1up_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslide1up.vx    v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslide1up_vx_8_vm, .-test_vslide1up_vx_8_vm

TEST_FUNC(test_vslide1up_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslide1up.vx    v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslide1up_vx_16, .-test_vslide1up_vx_16

TEST_FUNC(test_vslide1up_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslide1up.vx    v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslide1up_vx_16_vm, .-test_vslide1up_vx_16_vm

TEST_FUNC(test_vslide1up_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslide1up.vx    v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslide1up_vx_32, .-test_vslide1up_vx_32

TEST_FUNC(test_vslide1up_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslide1up.vx    v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslide1up_vx_32_vm, .-test_vslide1up_vx_32_vm

TEST_FUNC(test_vslide1up_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslide1up.vx    v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslide1up_vx_64, .-test_vslide1up_vx_64

TEST_FUNC(test_vslide1up_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslide1up.vx    v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslide1up_vx_64_vm, .-test_vslide1up_vx_64_vm

/* vslide1down.vx */
TEST_FUNC(test_vslide1down_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vslide1down.vx  v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vslide1down_vx_8, .-test_vslide1down_vx_8

TEST_FUNC(test_vslide1down_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vslide1down.vx  v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vslide1down_vx_8_vm, .-test_vslide1down_vx_8_vm

TEST_FUNC(test_vslide1down_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vslide1down.vx  v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vslide1down_vx_16, .-test_vslide1down_vx_16

TEST_FUNC(test_vslide1down_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vslide1down.vx  v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vslide1down_vx_16_vm, .-test_vslide1down_vx_16_vm

TEST_FUNC(test_vslide1down_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vslide1down.vx  v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vslide1down_vx_32, .-test_vslide1down_vx_32

TEST_FUNC(test_vslide1down_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vslide1down.vx  v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vslide1down_vx_32_vm, .-test_vslide1down_vx_32_vm

TEST_FUNC(test_vslide1down_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vslide1down.vx  v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vslide1down_vx_64, .-test_vslide1down_vx_64

TEST_FUNC(test_vslide1down_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vslide1down.vx  v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vslide1down_vx_64_vm, .-test_vslide1down_vx_64_vm

/* vrgather.vv */
TEST_FUNC(test_vrgather_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsetvli         t1, a0, e8, m2
        vrgather.vv     v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vrgather_vv_8, .-test_vrgather_vv_8

TEST_FUNC(test_vrgather_vv_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vrgather.vv     v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vrgather_vv_8_vm, .-test_vrgather_vv_8_vm

TEST_FUNC(test_vrgather_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vrgather.vv     v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vrgather_vv_16, .-test_vrgather_vv_16

TEST_FUNC(test_vrgather_vv_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vrgather.vv     v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vrgather_vv_16_vm, .-test_vrgather_vv_16_vm

TEST_FUNC(test_vrgather_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vrgather.vv     v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vrgather_vv_32, .-test_vrgather_vv_32

TEST_FUNC(test_vrgather_vv_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vrgather.vv     v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vrgather_vv_32_vm, .-test_vrgather_vv_32_vm

TEST_FUNC(test_vrgather_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vrgather.vv     v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vrgather_vv_64, .-test_vrgather_vv_64

TEST_FUNC(test_vrgather_vv_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vrgather.vv     v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vrgather_vv_64_vm, .-test_vrgather_vv_64_vm

/* vrgather.vx */
TEST_FUNC(test_vrgather_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vrgather.vx     v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vrgather_vx_8, .-test_vrgather_vx_8

TEST_FUNC(test_vrgather_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vrgather.vx     v6, v2, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vrgather_vx_8_vm, .-test_vrgather_vx_8_vm

TEST_FUNC(test_vrgather_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vrgather.vx     v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vrgather_vx_16, .-test_vrgather_vx_16

TEST_FUNC(test_vrgather_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vlh.v           v2, (a0)
        vrgather.vx     v6, v2, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vrgather_vx_16_vm, .-test_vrgather_vx_16_vm

TEST_FUNC(test_vrgather_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vrgather.vx     v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vrgather_vx_32, .-test_vrgather_vx_32

TEST_FUNC(test_vrgather_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vrgather.vx     v6, v2, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vrgather_vx_32_vm, .-test_vrgather_vx_32_vm

TEST_FUNC(test_vrgather_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vrgather.vx     v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vrgather_vx_64, .-test_vrgather_vx_64

TEST_FUNC(test_vrgather_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vrgather.vx     v6, v2, a1, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vrgather_vx_64_vm, .-test_vrgather_vx_64_vm

/* vrgather.vi */
TEST_FUNC(test_vrgather_vi_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vrgather.vi     v4, v0, 0x3
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vrgather_vi_8, .-test_vrgather_vi_8

TEST_FUNC(test_vrgather_vi_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vrgather.vi     v6, v2, 0x3, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vrgather_vi_8_vm, .-test_vrgather_vi_8_vm

TEST_FUNC(test_vrgather_vi_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vrgather.vi     v4, v0, 0x3
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vrgather_vi_16, .-test_vrgather_vi_16

TEST_FUNC(test_vrgather_vi_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vlh.v           v2, (a0)
        vrgather.vi     v6, v2, 0x3, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vrgather_vi_16_vm, .-test_vrgather_vi_16_vm

TEST_FUNC(test_vrgather_vi_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vrgather.vi     v4, v0, 0x3
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vrgather_vi_32, .-test_vrgather_vi_32

TEST_FUNC(test_vrgather_vi_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vrgather.vi     v6, v2, 0x3, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vrgather_vi_32_vm, .-test_vrgather_vi_32_vm

TEST_FUNC(test_vrgather_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vrgather.vi     v4, v0, 0x3
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vrgather_vi_64, .-test_vrgather_vi_64

TEST_FUNC(test_vrgather_vi_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vrgather.vi     v6, v2, 0x3, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vrgather_vi_64_vm, .-test_vrgather_vi_64_vm

/* vcompress.vm */
TEST_FUNC(test_vcompress_vm_8)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a1)
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        vcompress.vm    v4, v2, v0 
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vcompress_vm_8, .-test_vcompress_vm_8

TEST_FUNC(test_vcompress_vm_16)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a1)
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        vcompress.vm    v4, v2, v0 
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vcompress_vm_16, .-test_vcompress_vm_16

TEST_FUNC(test_vcompress_vm_32)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a1)
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        vcompress.vm    v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vcompress_vm_32, .-test_vcompress_vm_32

TEST_FUNC(test_vcompress_vm_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a1)
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        vcompress.vm    v4, v2, v0 
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vcompress_vm_64, .-test_vcompress_vm_64

