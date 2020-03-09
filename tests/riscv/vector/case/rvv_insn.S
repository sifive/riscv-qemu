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

   .file   "rvv_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

#include "rvv_ch8.inc"
#include "rvv_ch12.inc"
#include "rvv_ch14.inc"
#include "rvv_ch16_17.inc"

TEST_FUNC(test_vlseg2wuff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlseg2wuff.v v2, (a2)
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlseg2wuff_64, .-test_vlseg2wuff_64


TEST_FUNC(test_vlseg2huff_32)
        vsetvli   t0, a0, e32, m2
        vlwu.v     v2, (a1)
        vlwu.v     v4, (a1)
        vlseg2huff.v v2, (a2)
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlseg2huff_32, .-test_vlseg2huff_32

TEST_FUNC(test_vlseg2buff_16)
        vsetvli   t0, a0, e16, m2
        vlhu.v     v2, (a1)
        vlhu.v     v4, (a1)
        vlseg2buff.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2buff_16, .-test_vlseg2buff_16
TEST_FUNC(test_vlseg2eff_16)
        vsetvli   t0, a0, e16, m1
        vlh.v     v2, (a1)
        vlh.v     v3, (a1)
        vlh.v     v4, (a1)
        vlh.v     v5, (a1)
        vsetvli   t0, x0, e16, m2
        vlseg2eff.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2eff_16, .-test_vlseg2eff_16
TEST_FUNC(test_vlseg2wff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlseg2wff.v v2, (a2)
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlseg2wff_64, .-test_vlseg2wff_64


TEST_FUNC(test_vlseg2hff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vlseg2hff.v v2, (a2)
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlseg2hff_32, .-test_vlseg2hff_32

TEST_FUNC(test_vlseg2bff_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vlseg2bff.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2bff_16, .-test_vlseg2bff_16


/* vleff */
TEST_FUNC(test_vleff_8)
        vsetvli   t0, a0, e8, m2
        vleff.v     v2, (a1)
        vleff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vleff_8, .-test_vleff_8

TEST_FUNC(test_vleff_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vleff.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vleff.v     v2, (a1)
        vleff.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vleff_8_vm, .-test_vleff_8_vm

TEST_FUNC(test_vleff_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vleff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vleff_16, .-test_vleff_16

TEST_FUNC(test_vleff_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vleff.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vleff.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vleff_16_vm, .-test_vleff_16_vm

TEST_FUNC(test_vleff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vleff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vleff_32, .-test_vleff_32

TEST_FUNC(test_vleff_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vleff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vleff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vleff_32_vm, .-test_vleff_32_vm

TEST_FUNC(test_vleff_64)
        vsetvli   t0, a0, e64, m2
        vleff.v     v2, (a1)
        vleff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vleff_64, .-test_vleff_64

TEST_FUNC(test_vleff_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vleff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vleff.v     v2, (a1)
        vleff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vleff_64_vm, .-test_vleff_64_vm

/* vlwff */
TEST_FUNC(test_vlwff_32)
        vsetvli   t0, a0, e32, m2
        vlwff.v     v2, (a1)
        vlwff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlwff_32, .-test_vlwff_32

TEST_FUNC(test_vlwff_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlwff.v     v2, (a1)
        vlwff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlwff_32_vm, .-test_vlwff_32_vm

TEST_FUNC(test_vlwff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlwff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlwff_64, .-test_vlwff_64

TEST_FUNC(test_vlwff_64_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlwff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlwff_64_vm, .-test_vlwff_64_vm

/* vlwuff */
TEST_FUNC(test_vlwuff_32)
        vsetvli   t0, a0, e32, m2
        vlwuff.v     v2, (a1)
        vlwuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlwuff_32, .-test_vlwuff_32

TEST_FUNC(test_vlwuff_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwuff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlwuff.v     v2, (a1)
        vlwuff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlwuff_32_vm, .-test_vlwuff_32_vm

TEST_FUNC(test_vlwuff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlwuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlwuff_64, .-test_vlwuff_64

TEST_FUNC(test_vlwuff_64_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwuff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlwuff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlwuff_64_vm, .-test_vlwuff_64_vm

/* vlhff */
TEST_FUNC(test_vlhff_16)
        vsetvli   t0, a0, e16, m2
        vlhff.v     v2, (a1)
        vlhff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlhff_16, .-test_vlhff_16

TEST_FUNC(test_vlhff_16_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhff.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlhff.v     v2, (a1)
        vlhff.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlhff_16_vm, .-test_vlhff_16_vm

TEST_FUNC(test_vlhff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlhff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlhff_32, .-test_vlhff_32

TEST_FUNC(test_vlhff_32_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlhff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlhff_32_vm, .-test_vlhff_32_vm

TEST_FUNC(test_vlhff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlhff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlhff_64, .-test_vlhff_64

TEST_FUNC(test_vlhff_64_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlhff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlhff_64_vm, .-test_vlhff_64_vm


/* vlhuff */
TEST_FUNC(test_vlhuff_16)
        vsetvli   t0, a0, e16, m2
        vlhuff.v     v2, (a1)
        vlhuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlhuff_16, .-test_vlhuff_16

TEST_FUNC(test_vlhuff_16_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhuff.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlhuff.v     v2, (a1)
        vlhuff.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlhuff_16_vm, .-test_vlhuff_16_vm

TEST_FUNC(test_vlhuff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlhuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlhuff_32, .-test_vlhuff_32

TEST_FUNC(test_vlhuff_32_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhuff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlhuff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlhuff_32_vm, .-test_vlhuff_32_vm

TEST_FUNC(test_vlhuff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlhuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlhuff_64, .-test_vlhuff_64

TEST_FUNC(test_vlhuff_64_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhuff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlhuff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlhuff_64_vm, .-test_vlhuff_64_vm


/* vlbff */
TEST_FUNC(test_vlbff_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlbff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vlbff_8, .-test_vlbff_8

TEST_FUNC(test_vlbff_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbff.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlbff.v     v2, (a1)
        vlbff.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vlbff_8_vm, .-test_vlbff_8_vm

TEST_FUNC(test_vlbff_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlbff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlbff_16, .-test_vlbff_16

TEST_FUNC(test_vlbff_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbff.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlbff.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlbff_16_vm, .-test_vlbff_16_vm

TEST_FUNC(test_vlbff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlbff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlbff_32, .-test_vlbff_32

TEST_FUNC(test_vlbff_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlbff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlbff_32_vm, .-test_vlbff_32_vm

TEST_FUNC(test_vlbff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlbff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlbff_64, .-test_vlbff_64

TEST_FUNC(test_vlbff_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlbff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlbff_64_vm, .-test_vlbff_64_vm


/* vlbuff */
TEST_FUNC(test_vlbuff_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlbuff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vlbuff_8, .-test_vlbuff_8

TEST_FUNC(test_vlbuff_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbuff.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlbuff.v     v2, (a1)
        vlbuff.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vlbuff_8_vm, .-test_vlbuff_8_vm

TEST_FUNC(test_vlbuff_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlbuff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlbuff_16, .-test_vlbuff_16

TEST_FUNC(test_vlbuff_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbuff.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlbuff.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlbuff_16_vm, .-test_vlbuff_16_vm

TEST_FUNC(test_vlbuff_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlbuff.v  v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlbuff_32, .-test_vlbuff_32

TEST_FUNC(test_vlbuff_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbuff.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlbuff.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlbuff_32_vm, .-test_vlbuff_32_vm

TEST_FUNC(test_vlbuff_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlbuff.v     v2, (a2)
        csrr      a0, vl
        vsetvli   t0, a0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlbuff_64, .-test_vlbuff_64

TEST_FUNC(test_vlbuff_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbuff.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlbuff.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlbuff_64_vm, .-test_vlbuff_64_vm

/* vlb */
TEST_FUNC(test_vlb_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vlb_8, .-test_vlb_8

TEST_FUNC(test_vlb_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vlb_8_vm, .-test_vlb_8_vm

TEST_FUNC(test_vlb_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlb.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vlb_16, .-test_vlb_16

TEST_FUNC(test_vlb_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlb.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlb_16_vm, .-test_vlb_16_vm

TEST_FUNC(test_vlb_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlb.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlb_32, .-test_vlb_32

TEST_FUNC(test_vlb_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlb.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlb_32_vm, .-test_vlb_32_vm

TEST_FUNC(test_vlb_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlb.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlb_64, .-test_vlb_64

TEST_FUNC(test_vlb_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlb.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlb_64_vm, .-test_vlb_64_vm
TEST_FUNC(test_vlseg2b_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vlseg2b.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2b_16, .-test_vlseg2b_16

/* vlh */
TEST_FUNC(test_vlh_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vlh_16, .-test_vlh_16

TEST_FUNC(test_vlh_16_vm)
        vsetvli   t0 ,x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlh_16_vm, .-test_vlh_16_vm

TEST_FUNC(test_vlh_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlh.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlh_32, .-test_vlh_32

TEST_FUNC(test_vlh_32_vm)
        vsetvli   t0 ,x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlh.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlh_32_vm, .-test_vlh_32_vm

TEST_FUNC(test_vlh_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlh.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlh_64, .-test_vlh_64

TEST_FUNC(test_vlh_64_vm)
        vsetvli   t0 ,x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlh.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlh_64_vm, .-test_vlh_64_vm
TEST_FUNC(test_vlseg2h_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vlseg2h.v v2, (a2)
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlseg2h_32, .-test_vlseg2h_32
/* vlw */
TEST_FUNC(test_vlw_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlw_32, .-test_vlw_32

TEST_FUNC(test_vlw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlw_32_vm, .-test_vlw_32_vm

TEST_FUNC(test_vlw_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlw.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlw_64, .-test_vlw_64

TEST_FUNC(test_vlw_64_vm)
        vsetvli   t0 ,x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlw.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlw_64_vm, .-test_vlw_64_vm
TEST_FUNC(test_vlseg2w_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlseg2w.v v2, (a2)
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlseg2w_64, .-test_vlseg2w_64

/* vle */
TEST_FUNC(test_vle_8)
        vsetvli   t0, a0, e8, m2
        vle.v     v2, (a1)
        vle.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vle_8, .-test_vle_8

TEST_FUNC(test_vle_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vle.v     v2, (a1)
        vle.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vle_8_vm, .-test_vle_8_vm

TEST_FUNC(test_vle_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vle.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vle_16, .-test_vle_16

TEST_FUNC(test_vle_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vle.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vle_16_vm, .-test_vle_16_vm

TEST_FUNC(test_vle_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vle.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vle_32, .-test_vle_32

TEST_FUNC(test_vle_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vle.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vle_32_vm, .-test_vle_32_vm

TEST_FUNC(test_vle_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vle_64, .-test_vle_64

TEST_FUNC(test_vle_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vle_64_vm, .-test_vle_64_vm
TEST_FUNC(test_vlseg2e_16)
        vsetvli   t0, a0, e16, m1
        vlh.v     v2, (a1)
        vlh.v     v3, (a1)
        vlh.v     v4, (a1)
        vlh.v     v5, (a1)
        vsetvli   t0, x0, e16, m2
        vlseg2e.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2e_16, .-test_vlseg2e_16
/* vlbu */
TEST_FUNC(test_vlbu_8)
        vsetvli   t0, a0, e8, m2
        vlbu.v     v2, (a1)
        vlbu.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vlbu_8, .-test_vlbu_8

TEST_FUNC(test_vlbu_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbu.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlbu.v     v2, (a1)
        vlbu.v     v2, (a2), v0.t
        vsb.v     v2, (a3)
        ret
        .size   test_vlbu_8_vm, .-test_vlbu_8_vm

TEST_FUNC(test_vlbu_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlbu.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vlbu_16, .-test_vlbu_16

TEST_FUNC(test_vlbu_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbu.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlbu.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlbu_16_vm, .-test_vlbu_16_vm

TEST_FUNC(test_vlbu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlbu.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlbu_32, .-test_vlbu_32

TEST_FUNC(test_vlbu_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbu.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlbu.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlbu_32_vm, .-test_vlbu_32_vm

TEST_FUNC(test_vlbu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlbu.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlbu_64, .-test_vlbu_64

TEST_FUNC(test_vlbu_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlbu.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlbu.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlbu_64_vm, .-test_vlbu_64_vm
TEST_FUNC(test_vlseg2bu_16)
        vsetvli   t0, a0, e16, m2
        vlhu.v     v2, (a1)
        vlhu.v     v4, (a1)
        vlseg2bu.v v2, (a2)
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlseg2bu_16, .-test_vlseg2bu_16
/* vlhu */
TEST_FUNC(test_vlhu_16)
        vsetvli   t0, a0, e16, m2
        vlhu.v     v2, (a1)
        vlhu.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vlhu_16, .-test_vlhu_16

TEST_FUNC(test_vlhu_16_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhu.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlhu.v     v2, (a1)
        vlhu.v     v2, (a2), v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlhu_16_vm, .-test_vlhu_16_vm

TEST_FUNC(test_vlhu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlhu.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlhu_32, .-test_vlhu_32

TEST_FUNC(test_vlhu_32_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhu.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlhu.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlhu_32_vm, .-test_vlhu_32_vm

TEST_FUNC(test_vlhu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlhu.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlhu_64, .-test_vlhu_64

TEST_FUNC(test_vlhu_64_vm)
        vsetvli   t0 ,x0, e16, m1
        vlhu.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlhu.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlhu_64_vm, .-test_vlhu_64_vm
TEST_FUNC(test_vlseg2hu_32)
        vsetvli   t0, a0, e32, m2
        vlwu.v     v2, (a1)
        vlwu.v     v4, (a1)
        vlseg2hu.v v2, (a2)
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlseg2hu_32, .-test_vlseg2hu_32
/* vlwu */
TEST_FUNC(test_vlwu_32)
        vsetvli   t0, a0, e32, m2
        vlwu.v     v2, (a1)
        vlwu.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vlwu_32, .-test_vlwu_32

TEST_FUNC(test_vlwu_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwu.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlwu.v     v2, (a1)
        vlwu.v     v2, (a2), v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlwu_32_vm, .-test_vlwu_32_vm

TEST_FUNC(test_vlwu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vlwu.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vlwu_64, .-test_vlwu_64

TEST_FUNC(test_vlwu_64_vm)
        vsetvli   t0 ,x0, e32, m1
        vlwu.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlwu.v     v2, (a2), v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlwu_64_vm, .-test_vlwu_64_vm
TEST_FUNC(test_vlseg2wu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlseg2wu.v v2, (a2)
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlseg2wu_64, .-test_vlseg2wu_64

/* vsb */
TEST_FUNC(test_vsb_8)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vsb_8, .-test_vsb_8
TEST_FUNC(test_vsb_8_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a2)
        vsb.v     v2, (a3), v0.t
        ret
        .size   test_vsb_8_vm, .-test_vsb_8_vm
TEST_FUNC(test_vsb_16)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vsb_16, .-test_vsb_16
TEST_FUNC(test_vsb_16_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a2)
        vsb.v     v2, (a3), v0.t
        ret
        .size   test_vsb_16_vm, .-test_vsb_16_vm
TEST_FUNC(test_vsb_32)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vsb_32, .-test_vsb_32
TEST_FUNC(test_vsb_32_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsb.v     v2, (a3), v0.t
        ret
        .size   test_vsb_32_vm, .-test_vsb_32_vm
TEST_FUNC(test_vsb_64)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vsb.v     v2, (a3)
        ret
        .size   test_vsb_64, .-test_vsb_64
TEST_FUNC(test_vsb_64_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a2)
        vsb.v     v2, (a3), v0.t
        ret
        .size   test_vsb_64_vm, .-test_vsb_64_vm
TEST_FUNC(test_vsseg2b_16)
        vsetvli   t0, x0, e8, m2
        vlb.v     v6, (a0)
        vsb.v     v6, (a3)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a2)
        vsseg2b.v v2, (a3)
        ret
        .size test_vsseg2b_16, .-test_vsseg2b_16

/* vsh */
TEST_FUNC(test_vsh_16)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vsh_16, .-test_vsh_16
TEST_FUNC(test_vsh_16_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a2)
        vsh.v     v2, (a3), v0.t
        ret
        .size   test_vsh_16_vm, .-test_vsh_16_vm
TEST_FUNC(test_vsh_32)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vsh_32, .-test_vsh_32
TEST_FUNC(test_vsh_32_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsh.v     v2, (a3), v0.t
        ret
        .size   test_vsh_32_vm, .-test_vsh_32_vm
TEST_FUNC(test_vsh_64)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vsh.v     v2, (a3)
        ret
        .size   test_vsh_64, .-test_vsh_64
TEST_FUNC(test_vsh_64_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a2)
        vsh.v     v2, (a3), v0.t
        ret
        .size   test_vsh_64_vm, .-test_vsh_64_vm
TEST_FUNC(test_vsseg2h_32)
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a0)
        vsh.v     v6, (a3)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a2)
        vsseg2h.v v2, (a3)
        ret
        .size test_vsseg2h_32, .-test_vsseg2h_32

/* vsw */
TEST_FUNC(test_vsw_32)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vsw_32, .-test_vsw_32
TEST_FUNC(test_vsw_32_vm)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsw.v     v2, (a3), v0.t
        ret
        .size   test_vsw_32_vm, .-test_vsw_32_vm
TEST_FUNC(test_vsw_64)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vsw.v     v2, (a3)
        ret
        .size   test_vsw_64, .-test_vsw_64
TEST_FUNC(test_vsw_64_vm)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a2)
        vsw.v     v2, (a3), v0.t
        ret
        .size   test_vsw_64_vm, .-test_vsw_64_vm
TEST_FUNC(test_vsseg2w_64)
        vsetvli   t0, x0, e32, m2
        vlw.v     v6, (a0)
        vsw.v     v6, (a3)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a2)
        vsseg2w.v v2, (a3)
        ret
        .size test_vsseg2w_64, .-test_vsseg2w_64

/* vse */
TEST_FUNC(test_vse_8)
        vsetvli   t0, x0, e8, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e8, m2
        vle.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vse_8, .-test_vse_8

TEST_FUNC(test_vse_8_vm)
        vsetvli   t0 ,x0, e8, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, x0, e8, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vle.v     v2, (a2)
        vse.v     v2, (a3), v0.t
        ret
        .size   test_vse_8_vm, .-test_vse_8_vm
TEST_FUNC(test_vse_16)
        vsetvli   t0, x0, e16, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vle.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vse_16, .-test_vse_16

TEST_FUNC(test_vse_16_vm)
        vsetvli   t0 ,x0, e16, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, x0, e16, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vle.v     v2, (a2), v0.t
        vse.v     v2, (a3), v0.t
        ret
        .size   test_vse_16_vm, .-test_vse_16_vm
TEST_FUNC(test_vse_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vle.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vse_32, .-test_vse_32

TEST_FUNC(test_vse_32_vm)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a2), v0.t
        vse.v     v2, (a3), v0.t
        ret
        .size   test_vse_32_vm, .-test_vse_32_vm
TEST_FUNC(test_vse_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vse.v     v2, (a3)
        ret
        .size   test_vse_64, .-test_vse_64

TEST_FUNC(test_vse_64_vm)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a2), v0.t
        vse.v     v2, (a3), v0.t
        ret
        .size   test_vse_64_vm, .-test_vse_64_vm
TEST_FUNC(test_vsseg2e_16)
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a1)
        vsh.v     v6, (a4)
        vlh.v     v2, (a2)
        vlh.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vsseg2e.v v2, (a4)
        ret
        .size   test_vsseg2e_16, .-test_vsseg2e_16

/* vlsb */
TEST_FUNC(test_vlsb_8)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a1)
        vsetvli   t0, a0, e8, m2
        vlsb.v    v2, (a2), t1
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vlsb_8, .-test_vlsb_8
TEST_FUNC(test_vlsb_8_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a2)
        vsetvli   t0, a0, e8, m2
        vlsb.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a4)
        ret
        .size   test_vlsb_8_vm, .-test_vlsb_8_vm

TEST_FUNC(test_vlsb_16)
        li        t1, 2
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a0)
        vlsb.v    v2, (a1), t1
        vsh.v     v2, (a2)
        ret
        .size   test_vlsb_16, .-test_vlsb_16
TEST_FUNC(test_vlsb_16_vm)
        li        t1, 2
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vlsb.v    v2, (a2), t1, v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlsb_16_vm, .-test_vlsb_16_vm

TEST_FUNC(test_vlsb_32)
        li        t1, 2
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a0)
        vlsb.v    v2, (a1), t1
        vsw.v     v2, (a2)
        ret
        .size   test_vlsb_32, .-test_vlsb_32

TEST_FUNC(test_vlsb_32_vm)
        li        t1, 2
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlsb.v    v2, (a2), t1, v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlsb_32_vm, .-test_vlsb_32_vm

TEST_FUNC(test_vlsb_64)
        li        t1, 2
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlsb.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlsb_64, .-test_vlsb_64

TEST_FUNC(test_vlsb_64_vm)
        li        t1, 2
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlsb.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlsb_64_vm, .-test_vlsb_64_vm

TEST_FUNC(test_vlsseg2b_16)
        li        t1, 2
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vlsseg2b.v v2, (a2), t1
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlsseg2b_16, .-test_vlsseg2b_16

/* vlsh */
TEST_FUNC(test_vlsh_16)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vsetvli   t0, a0, e16, m2
        vlsh.v    v2, (a2), t1
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlsh_16, .-test_vlsh_16
TEST_FUNC(test_vlsh_16_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a2)
        vsetvli   t0, a0, e16, m2
        vlsh.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a4)
        ret
        .size   test_vlsh_16_vm, .-test_vlsh_16_vm

TEST_FUNC(test_vlsh_32)
        li        t1, 4
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a0)
        vlsh.v    v2, (a1), t1
        vsw.v     v2, (a2)
        ret
        .size   test_vlsh_32, .-test_vlsh_32

TEST_FUNC(test_vlsh_32_vm)
        li        t1, 4
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlsh.v    v2, (a2), t1, v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlsh_32_vm, .-test_vlsh_32_vm

TEST_FUNC(test_vlsh_64)
        li        t1, 4
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlsh.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlsh_64, .-test_vlsh_64

TEST_FUNC(test_vlsh_64_vm)
        li        t1, 4
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlsh.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlsh_64_vm, .-test_vlsh_64_vm
TEST_FUNC(test_vlsseg2h_32)
        li        t1, 4
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vlsseg2h.v v2, (a2), t1
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlsseg2h_32, .-test_vlseg2h_32

/* vlsw */
TEST_FUNC(test_vlsw_32)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vsetvli   t0, a0, e32, m2
        vlsw.v    v2, (a2), t1
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlsw_32, .-test_vlsw_32
TEST_FUNC(test_vlsw_32_vm)
        li        t1, 8
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsetvli   t0, a0, e32, m2
        vlsw.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a4)
        ret
        .size   test_vlsw_32_vm, .-test_vlsw_32_vm

TEST_FUNC(test_vlsw_64)
        li        t1, 8
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlsw.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlsw_64, .-test_vlsw_64

TEST_FUNC(test_vlsw_64_vm)
        li        t1, 8
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vlsw.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlsw_64_vm, .-test_vlsw_64_vm

TEST_FUNC(test_vlsseg2w_64)
        li        t1, 8
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlsseg2w.v v2, (a2), t1
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlsseg2w_64, .-test_vlseg2w_64

/* vlse */
TEST_FUNC(test_vlse_8)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a1)
        vsetvli   t0, a0, e8, m2
        vlse.v    v2, (a2), t1
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vlse_8, .-test_vlse_8
TEST_FUNC(test_vlse_8_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a2)
        vsetvli   t0, a0, e8, m2
        vlse.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a4)
        ret
        .size   test_vlse_8_vm, .-test_vlse_8_vm

TEST_FUNC(test_vlse_16)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vsetvli   t0, a0, e16, m2
        vlse.v    v2, (a2), t1
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlse_16, .-test_vlse_16
TEST_FUNC(test_vlse_16_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a2)
        vsetvli   t0, a0, e16, m2
        vlse.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a4)
        ret
        .size   test_vlse_16_vm, .-test_vlse_16_vm

TEST_FUNC(test_vlse_32)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vsetvli   t0, a0, e32, m2
        vlse.v    v2, (a2), t1
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlse_32, .-test_vlse_32
TEST_FUNC(test_vlse_32_vm)
        li        t1, 8
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsetvli   t0, a0, e32, m2
        vlse.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a4)
        ret
        .size   test_vlse_32_vm, .-test_vlse_32_vm

TEST_FUNC(test_vlse_64)
        li        t1, 16
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vsetvli   t0, a0, e64, m2
        vlse.v    v2, (a2), t1
        vsetvli   t0, x0, e64, m2
        vse.v     v2, (a3)
        ret
        .size   test_vlse_64, .-test_vlse_64

TEST_FUNC(test_vlse_64_vm)
        li        t1, 16
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a2)
        vsetvli   t0, a0, e64, m2
        vlse.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e64, m2
        vse.v     v2, (a4)
        ret
        .size   test_vlse_64_vm, .-test_vlse_64_vm
TEST_FUNC(test_vlsseg2e_16)
        li        t1, 4
        vsetvli   t0, a0, e16, m1
        vlh.v     v2, (a1)
        vlh.v     v3, (a1)
        vlh.v     v4, (a1)
        vlh.v     v5, (a1)
        vsetvli   t0, x0, e16, m2
        vlsseg2e.v v2, (a2), t1
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlsseg2e_16, .-test_vlsseg2e_16
/* vlsbu */
TEST_FUNC(test_vlsbu_8)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a1)
        vsetvli   t0, a0, e8, m2
        vlsbu.v    v2, (a2), t1
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a3)
        ret
        .size   test_vlsbu_8, .-test_vlsbu_8
TEST_FUNC(test_vlsbu_8_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, x0, e8, m2
        vlb.v     v2, (a2)
        vsetvli   t0, a0, e8, m2
        vlsbu.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e8, m2
        vsb.v     v2, (a4)
        ret
        .size   test_vlsbu_8_vm, .-test_vlsbu_8_vm

TEST_FUNC(test_vlsbu_16)
        li        t1, 2
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a0)
        vlsbu.v    v2, (a1), t1
        vsh.v     v2, (a2)
        ret
        .size   test_vlsbu_16, .-test_vlsbu_16
TEST_FUNC(test_vlsbu_16_vm)
        li        t1, 2
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a0)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vlsbu.v    v2, (a2), t1, v0.t
        vsh.v     v2, (a3)
        ret
        .size   test_vlsbu_16_vm, .-test_vlsbu_16_vm

TEST_FUNC(test_vlsbu_32)
        li        t1, 2
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a0)
        vlsbu.v    v2, (a1), t1
        vsw.v     v2, (a2)
        ret
        .size   test_vlsbu_32, .-test_vlsbu_32

TEST_FUNC(test_vlsbu_32_vm)
        li        t1, 2
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlsbu.v    v2, (a2), t1, v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlsbu_32_vm, .-test_vlsbu_32_vm

TEST_FUNC(test_vlsbu_64)
        li        t1, 2
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlsbu.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlsbu_64, .-test_vlsbu_64

TEST_FUNC(test_vlsbu_64_vm)
        li        t1, 2
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlsbu.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlsbu_64_vm, .-test_vlsbu_64_vm

TEST_FUNC(test_vlsseg2bu_16)
        li        t1, 2
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vlsseg2bu.v v2, (a2), t1
        vsh.v     v2, (a3)
        vsh.v     v4, (a4)
        ret
        .size   test_vlsseg2bu_16, .-test_vlsseg2bu_16



/* vlshu */
TEST_FUNC(test_vlshu_16)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vsetvli   t0, a0, e16, m2
        vlshu.v    v2, (a2), t1
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a3)
        ret
        .size   test_vlshu_16, .-test_vlsh_16
TEST_FUNC(test_vlshu_16_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a2)
        vsetvli   t0, a0, e16, m2
        vlshu.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e16, m2
        vsh.v     v2, (a4)
        ret
        .size   test_vlshu_16_vm, .-test_vlsh_16_vm

TEST_FUNC(test_vlshu_32)
        li        t1, 4
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a0)
        vlshu.v    v2, (a1), t1
        vsw.v     v2, (a2)
        ret
        .size   test_vlshu_32, .-test_vlsh_32

TEST_FUNC(test_vlshu_32_vm)
        li        t1, 4
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a0)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlshu.v    v2, (a2), t1, v0.t
        vsw.v     v2, (a3)
        ret
        .size   test_vlshu_32_vm, .-test_vlsh_32_vm

TEST_FUNC(test_vlshu_64)
        li        t1, 4
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlshu.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlshu_64, .-test_vlsh_64

TEST_FUNC(test_vlshu_64_vm)
        li        t1, 4
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vlshu.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlshu_64_vm, .-test_vlsh_64_vm
TEST_FUNC(test_vlsseg2hu_32)
        li        t1, 4
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vlsseg2hu.v v2, (a2), t1
        vsw.v     v2, (a3)
        vsw.v     v4, (a4)
        ret
        .size   test_vlsseg2hu_32, .-test_vlseg2hu_32

/* vlswu */
TEST_FUNC(test_vlswu_32)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vsetvli   t0, a0, e32, m2
        vlswu.v    v2, (a2), t1
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a3)
        ret
        .size   test_vlswu_32, .-test_vlswu_32
TEST_FUNC(test_vlswu_32_vm)
        li        t1, 8
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a2)
        vsetvli   t0, a0, e32, m2
        vlswu.v    v2, (a3), t1, v0.t
        vsetvli   t0, x0, e32, m2
        vsw.v     v2, (a4)
        ret
        .size   test_vlswu_32_vm, .-test_vlswu_32_vm

TEST_FUNC(test_vlswu_64)
        li        t1, 8
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a0)
        vlswu.v    v2, (a1), t1
        vse.v     v2, (a2)
        ret
        .size   test_vlswu_64, .-test_vlswu_64

TEST_FUNC(test_vlswu_64_vm)
        li        t1, 8
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vlswu.v    v2, (a2), t1, v0.t
        vse.v     v2, (a3)
        ret
        .size   test_vlswu_64_vm, .-test_vlswu_64_vm

TEST_FUNC(test_vlsseg2wu_64)
        li        t1, 8
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vlsseg2wu.v v2, (a2), t1
        vse.v     v2, (a3)
        vse.v     v4, (a4)
        ret
        .size   test_vlsseg2wu_64, .-test_vlseg2wu_64
/* vssb */
TEST_FUNC(test_vssb_8)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a2)
        vssb.v    v2, (a3), t1
        ret
        .size   test_vssb_8, .-test_vssb_8
TEST_FUNC(test_vssb_8_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a4)
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a3)
        vssb.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssb_8_vm, .-test_vssb_8_vm
TEST_FUNC(test_vssb_16)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a2)
        vssb.v    v2, (a3), t1
        ret
        .size   test_vssb_16, .-test_vssb_16
TEST_FUNC(test_vssb_16_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a4)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a3)
        vssb.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssb_16_vm, .-test_vssb_16_vm
TEST_FUNC(test_vssb_32)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vssb.v    v2, (a3), t1
        ret
        .size   test_vssb_32, .-test_vssb_32
TEST_FUNC(test_vssb_32_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a4)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a3)
        vssb.v    v2, (a4), t1, v0.t
        ret
        .size   test_vssb_32_vm, .-test_vssb_32_vm
TEST_FUNC(test_vssb_64)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vssb.v     v2, (a3), t1
        ret
        .size   test_vssb_64, .-test_vssb_64
TEST_FUNC(test_vssb_64_vm)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a4)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a3)
        vssb.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssb_64_vm, .-test_vssb_64_vm
TEST_FUNC(test_vssseg2b_16)
        li        t1, 4
        vsetvli   t0, x0, e8, m2
        vlb.v     v6, (a0)
        vsb.v     v6, (a3)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a2)
        vssseg2b.v v2, (a3), t1
        ret
        .size test_vssseg2b_16, .-test_vssseg2b_16


/* vssh */
TEST_FUNC(test_vssh_16)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a2)
        vssh.v     v2, (a3), t1
        ret
        .size   test_vssh_16, .-test_vssh_16
TEST_FUNC(test_vssh_16_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a4)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a3)
        vssh.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssh_16_vm, .-test_vssh_16_vm
TEST_FUNC(test_vssh_32)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vssh.v     v2, (a3), t1
        ret
        .size   test_vssh_32, .-test_vssh_32
TEST_FUNC(test_vssh_32_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a4)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a3)
        vssh.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssh_32_vm, .-test_vssh_32_vm
TEST_FUNC(test_vssh_64)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vssh.v     v2, (a3), t1
        ret
        .size   test_vssh_64, .-test_vssh_64
TEST_FUNC(test_vssh_64_vm)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a4)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a3)
        vssh.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssh_64_vm, .-test_vssh_64_vm
TEST_FUNC(test_vssseg2h_32)
        li        t1, 8
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a0)
        vsh.v     v6, (a3)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a2)
        vssseg2h.v v2, (a3), t1
        ret
        .size test_vssseg2h_32, .-test_vssseg2h_32

/* vsw */
TEST_FUNC(test_vssw_32)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a2)
        vssw.v     v2, (a3), t1
        ret
        .size   test_vssw_32, .-test_vssw_32
TEST_FUNC(test_vssw_32_vm)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a2)
        vsw.v     v4, (a4)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a3)
        vssw.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssw_32_vm, .-test_vssw_32_vm
TEST_FUNC(test_vssw_64)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vssw.v     v2, (a3), t1
        ret
        .size   test_vssw_64, .-test_vssw_64
TEST_FUNC(test_vssw_64_vm)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a2)
        vsw.v     v4, (a4)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a3)
        vssw.v     v2, (a4), t1, v0.t
        ret
        .size   test_vssw_64_vm, .-test_vssw_64_vm
TEST_FUNC(test_vssseg2w_64)
        li        t1, 16
        vsetvli   t0, x0, e32, m2
        vlw.v     v6, (a0)
        vsw.v     v6, (a3)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a2)
        vssseg2w.v v2, (a3), t1
        ret
        .size test_vssseg2w_64, .-test_vssseg2w_64


/* vsse */
TEST_FUNC(test_vsse_8)
        li        t1, 2
        vsetvli   t0, x0, e8, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e8, m2
        vle.v     v2, (a2)
        vsse.v    v2, (a3), t1
        ret
        .size   test_vsse_8, .-test_vsse_8

TEST_FUNC(test_vsse_8_vm)
        li        t1, 2
        vsetvli   t0 ,x0, e8, m2
        vle.v     v4, (a2)
        vse.v     v4, (a4)
        vsetvli   t0, x0, e8, m1
        vle.v     v0, (a1)
        vsetvli   t0 ,a0, e8, m2
        vle.v     v2, (a3)
        vsse.v     v2, (a4), t1, v0.t
        ret
        .size   test_vsse_8_vm, .-test_vsse_8_vm
TEST_FUNC(test_vsse_16)
        li        t1, 4
        vsetvli   t0, x0, e16, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e16, m2
        vle.v     v2, (a2)
        vsse.v     v2, (a3), t1
        ret
        .size   test_vsse_16, .-test_vsse_16

TEST_FUNC(test_vsse_16_vm)
        li        t1, 4
        vsetvli   t0 ,x0, e16, m2
        vle.v     v4, (a2)
        vse.v     v4, (a4)
        vsetvli   t0, x0, e16, m1
        vle.v     v0, (a1)
        vsetvli   t0 ,a0, e16, m2
        vle.v     v2, (a3), v0.t
        vsse.v     v2, (a4), t1, v0.t
        ret
        .size   test_vsse_16_vm, .-test_vsse_16_vm
TEST_FUNC(test_vsse_32)
        li        t1, 8
        vsetvli   t0, x0, e32, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vle.v     v2, (a2)
        vsse.v     v2, (a3), t1
        ret
        .size   test_vsse_32, .-test_vsse_32

TEST_FUNC(test_vsse_32_vm)
        li        t1, 8
        vsetvli   t0 ,x0, e32, m2
        vle.v     v4, (a2)
        vse.v     v4, (a4)
        vsetvli   t0, x0, e32, m1
        vle.v     v0, (a1)
        vsetvli   t0 ,a0, e32, m2
        vle.v     v2, (a3), v0.t
        vsse.v     v2, (a4), t1, v0.t
        ret
        .size   test_vsse_32_vm, .-test_vsse_32_vm
TEST_FUNC(test_vsse_64)
        li        t1, 16
        vsetvli   t0, x0, e64, m2
        vle.v     v4, (a1)
        vse.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a2)
        vsse.v     v2, (a3), t1
        ret
        .size   test_vsse_64, .-test_vsse_64

TEST_FUNC(test_vsse_64_vm)
        li        t1, 16
        vsetvli   t0 ,x0, e64, m2
        vle.v     v4, (a2)
        vse.v     v4, (a4)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0 ,a0, e64, m2
        vle.v     v2, (a3), v0.t
        vsse.v     v2, (a4), t1, v0.t
        ret
        .size   test_vsse_64_vm, .-test_vsse_64_vm
TEST_FUNC(test_vssseg2e_16)
        li        t1, 8
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a0)
        vsh.v     v6, (a3)
        vlh.v     v2, (a1)
        vlh.v     v4, (a2)
        vssseg2e.v v2, (a3), t1
        ret
        .size   test_vssseg2e_16, .-test_vssseg2e_16

/* vlxb */
TEST_FUNC(test_vlxb_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxb.v    v2, (a2), v4
        vsb.v     v2, (a4)
        ret
        .size   test_vlxb_8, .-test_vlxb_8

TEST_FUNC(test_vlxb_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxb.v    v2, (a2), v4, v0.t
        vsb.v     v2, (a4)
        ret
        .size   test_vlxb_8_vm, .-test_vlxb_8_vm

TEST_FUNC(test_vlxb_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxb.v    v2, (a2), v4
        vsh.v     v2, (a4)
        ret
        .size   test_vlxb_16, .-test_vlxb_16

TEST_FUNC(test_vlxb_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxb.v     v2, (a2), v4, v0.t
        vsh.v     v2, (a4)
        ret
        .size   test_vlxb_16_vm, .-test_vlxb_16_vm

TEST_FUNC(test_vlxb_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxb.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxb_32, .-test_vlxb_32

TEST_FUNC(test_vlxb_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxb.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxb_32_vm, .-test_vlxb_32_vm

TEST_FUNC(test_vlxb_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxb.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxb_64, .-test_vlxb_64

TEST_FUNC(test_vlxb_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxb.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxb_64_vm, .-test_vlxb_64_vm
TEST_FUNC(test_vlxseg2b_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a3)
        vlxseg2b.v v2, (a2), v6
        vsh.v     v2, (a4)
        vsh.v     v4, (a5)
        ret
        .size   test_vlxseg2b_16, .-test_vlxseg2b_16


/* vlxh */
TEST_FUNC(test_vlxh_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxh.v    v2, (a2), v4
        vsh.v     v2, (a4)
        ret
        .size   test_vlxh_16, .-test_vlxh_16

TEST_FUNC(test_vlxh_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxh.v     v2, (a2), v4, v0.t
        vsh.v     v2, (a4)
        ret
        .size   test_vlxh_16_vm, .-test_vlxh_16_vm

TEST_FUNC(test_vlxh_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxh.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxh_32, .-test_vlxh_32

TEST_FUNC(test_vlxh_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxh.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxh_32_vm, .-test_vlxh_32_vm

TEST_FUNC(test_vlxh_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxh.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxh_64, .-test_vlxh_64

TEST_FUNC(test_vlxh_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxh.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxh_64_vm, .-test_vlxh_64_vm
TEST_FUNC(test_vlxseg2h_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vsetvli   t0, x0, e32, m2
        vlw.v     v6, (a3)
        vlxseg2h.v v2, (a2), v6
        vsw.v     v2, (a4)
        vsw.v     v4, (a5)
        ret
        .size   test_vlxseg2h_32, .-test_vlseg2h_32


/* vlxw */
TEST_FUNC(test_vlxw_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxw.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxw_32, .-test_vlxw_32

TEST_FUNC(test_vlxw_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxw.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxw_32_vm, .-test_vlxw_32_vm

TEST_FUNC(test_vlxw_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxw.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxw_64, .-test_vlxw_64

TEST_FUNC(test_vlxw_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxw.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxw_64_vm, .-test_vlxw_64_vm

TEST_FUNC(test_vlxseg2w_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vsetvli   t0, x0, e64, m2
        vle.v     v6, (a3)
        vlxseg2w.v v2, (a2), v6
        vse.v     v2, (a4)
        vse.v     v4, (a5)
        ret
        .size   test_vlxseg2w_64, .-test_vlseg2w_64

/* vlxe */
TEST_FUNC(test_vlxe_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxe.v    v2, (a2), v4
        vsb.v     v2, (a4)
        ret
        .size   test_vlxe_8, .-test_vlxe_8

TEST_FUNC(test_vlxe_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxe.v    v2, (a2), v4, v0.t
        vsb.v     v2, (a4)
        ret
        .size   test_vlxe_8_vm, .-test_vlxe_8_vm

TEST_FUNC(test_vlxe_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxe.v    v2, (a2), v4
        vsh.v     v2, (a4)
        ret
        .size   test_vlxe_16, .-test_vlxe_16

TEST_FUNC(test_vlxe_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxe.v     v2, (a2), v4, v0.t
        vsh.v     v2, (a4)
        ret
        .size   test_vlxe_16_vm, .-test_vlxe_16_vm

TEST_FUNC(test_vlxe_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxe.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxe_32, .-test_vlxe_32

TEST_FUNC(test_vlxe_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxe.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxe_32_vm, .-test_vlxe_32_vm

TEST_FUNC(test_vlxe_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxe.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxe_64, .-test_vlxe_64

TEST_FUNC(test_vlxe_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxe.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxe_64_vm, .-test_vlxe_64_vm

TEST_FUNC(test_vlxseg2e_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a3)
        vlxseg2e.v v2, (a2), v6
        vsh.v     v2, (a4)
        vsh.v     v4, (a5)
        ret
        .size   test_vlxseg2e_16, .-test_vlxseg2e_16

/* vlxbu */
TEST_FUNC(test_vlxbu_8)
        vsetvli   t0, a0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxbu.v    v2, (a2), v4
        vsb.v     v2, (a4)
        ret
        .size   test_vlxbu_8, .-test_vlxbu_8

TEST_FUNC(test_vlxbu_8_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e8, m2
        vlb.v     v2, (a1)
        vlb.v     v4, (a3)
        vlxbu.v    v2, (a2), v4, v0.t
        vsb.v     v2, (a4)
        ret
        .size   test_vlxbu_8_vm, .-test_vlxbu_8_vm

TEST_FUNC(test_vlxbu_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxbu.v    v2, (a2), v4
        vsh.v     v2, (a4)
        ret
        .size   test_vlxbu_16, .-test_vlxbu_16

TEST_FUNC(test_vlxbu_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxbu.v     v2, (a2), v4, v0.t
        vsh.v     v2, (a4)
        ret
        .size   test_vlxbu_16_vm, .-test_vlxbu_16_vm

TEST_FUNC(test_vlxbu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxbu.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxbu_32, .-test_vlxbu_32

TEST_FUNC(test_vlxbu_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxbu.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxbu_32_vm, .-test_vlxbu_32_vm

TEST_FUNC(test_vlxbu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxbu.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxbu_64, .-test_vlxbu_64

TEST_FUNC(test_vlxbu_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxbu.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxbu_64_vm, .-test_vlxbu_64_vm
TEST_FUNC(test_vlxseg2bu_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a1)
        vsetvli   t0, x0, e16, m2
        vlh.v     v6, (a3)
        vlxseg2bu.v v2, (a2), v6
        vsh.v     v2, (a4)
        vsh.v     v4, (a5)
        ret
        .size   test_vlxseg2bu_16, .-test_vlxseg2bu_16


/* vlxh */
TEST_FUNC(test_vlxhu_16)
        vsetvli   t0, a0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxhu.v    v2, (a2), v4
        vsh.v     v2, (a4)
        ret
        .size   test_vlxhu_16, .-test_vlxhu_16

TEST_FUNC(test_vlxhu_16_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a3)
        vlxhu.v     v2, (a2), v4, v0.t
        vsh.v     v2, (a4)
        ret
        .size   test_vlxhu_16_vm, .-test_vlxhu_16_vm

TEST_FUNC(test_vlxhu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxhu.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxhu_32, .-test_vlxhu_32

TEST_FUNC(test_vlxhu_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxhu.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxhu_32_vm, .-test_vlxhu_32_vm

TEST_FUNC(test_vlxhu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxhu.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxhu_64, .-test_vlxhu_64

TEST_FUNC(test_vlxhu_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxhu.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxhu_64_vm, .-test_vlxhu_64_vm
TEST_FUNC(test_vlxseg2hu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a1)
        vsetvli   t0, x0, e32, m2
        vlw.v     v6, (a3)
        vlxseg2hu.v v2, (a2), v6
        vsw.v     v2, (a4)
        vsw.v     v4, (a5)
        ret
        .size   test_vlxseg2hu_32, .-test_vlseg2hu_32


/* vlxw */
TEST_FUNC(test_vlxwu_32)
        vsetvli   t0, a0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxwu.v    v2, (a2), v4
        vsw.v     v2, (a4)
        ret
        .size   test_vlxwu_32, .-test_vlxwu_32

TEST_FUNC(test_vlxwu_32_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a3)
        vlxwu.v    v2, (a2), v4, v0.t
        vsw.v     v2, (a4)
        ret
        .size   test_vlxwu_32_vm, .-test_vlxwu_32_vm

TEST_FUNC(test_vlxwu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxwu.v     v2, (a2), v4
        vse.v     v2, (a4)
        ret
        .size   test_vlxwu_64, .-test_vlxwu_64

TEST_FUNC(test_vlxwu_64_vm)
        vsetvli   t0 ,x0, e8, m1
        vlb.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a3)
        vlxwu.v     v2, (a2), v4, v0.t
        vse.v     v2, (a4)
        ret
        .size   test_vlxwu_64_vm, .-test_vlxwu_64_vm
TEST_FUNC(test_vlxseg2wu_64)
        vsetvli   t0, a0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a1)
        vsetvli   t0, x0, e64, m2
        vle.v     v6, (a3)
        vlxseg2wu.v v2, (a2), v6
        vse.v     v2, (a4)
        vse.v     v4, (a5)
        ret
        .size   test_vlxseg2wu_64, .-test_vlseg2wu_64
/* vsxb */
TEST_FUNC(test_vsxb_8)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a4)
        vsetvli   t0, a0, e8, m2
        vlb.v     v6, (a3)
        vlb.v     v2, (a2)
        vsxb.v    v2, (a4), v6
        ret
        .size   test_vsxb_8, .-test_vsxb_8
TEST_FUNC(test_vsxb_8_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a5)
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, a0, e8, m2
        vlb.v     v6, (a4)
        vlb.v     v2, (a3)
        vsxb.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxb_8_vm, .-test_vsxb_8_vm
TEST_FUNC(test_vsxb_16)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a4)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a3)
        vlh.v     v2, (a2)
        vsxb.v    v2, (a4), v6
        ret
        .size   test_vsxb_16, .-test_vsxb_16
TEST_FUNC(test_vsxb_16_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a5)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a4)
        vlh.v     v2, (a3)
        vsxb.v     v2, (a5), v6,  v0.t
        ret
        .size   test_vsxb_16_vm, .-test_vsxb_16_vm
TEST_FUNC(test_vsxb_32)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a4)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a3)
        vlw.v     v2, (a2)
        vsxb.v    v2, (a4), v6
        ret
        .size   test_vsxb_32, .-test_vsxb_32
TEST_FUNC(test_vsxb_32_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a5)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a4)
        vlw.v     v2, (a3)
        vsxb.v    v2, (a5), v6, v0.t
        ret
        .size   test_vsxb_32_vm, .-test_vsxb_32_vm
TEST_FUNC(test_vsxb_64)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a4)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a3)
        vle.v     v2, (a2)
        vsxb.v     v2, (a4), v6
        ret
        .size   test_vsxb_64, .-test_vsxb_64
TEST_FUNC(test_vsxb_64_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a5)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a4)
        vle.v     v2, (a3)
        vsxb.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxb_64_vm, .-test_vsxb_64_vm
TEST_FUNC(test_vsxseg2b_16)
        vsetvli   t0, x0, e8, m2
        vlb.v     v8, (a0)
        vsb.v     v8, (a4)
        vsetvli   t0, x0, e16, m2
        vlh.v     v2, (a1)
        vlh.v     v4, (a2)
        vlh.v     v6, (a3)
        vsxseg2b.v v2, (a4), v6
        ret
        .size test_vsxseg2b_16, .-test_vsxseg2b_16

/* vsxh */
TEST_FUNC(test_vsxh_16)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a4)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a3)
        vlh.v     v2, (a2)
        vsxh.v    v2, (a4), v6
        ret
        .size   test_vsxh_16, .-test_vsxh_16
TEST_FUNC(test_vsxh_16_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a5)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a4)
        vlh.v     v2, (a3)
        vsxh.v     v2, (a5), v6,  v0.t
        ret
        .size   test_vsxh_16_vm, .-test_vsxh_16_vm
TEST_FUNC(test_vsxh_32)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a4)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a3)
        vlw.v     v2, (a2)
        vsxh.v    v2, (a4), v6
        ret
        .size   test_vsxh_32, .-test_vsxh_32
TEST_FUNC(test_vsxh_32_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a5)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a4)
        vlw.v     v2, (a3)
        vsxh.v    v2, (a5), v6, v0.t
        ret
        .size   test_vsxh_32_vm, .-test_vsxh_32_vm
TEST_FUNC(test_vsxh_64)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a4)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a3)
        vle.v     v2, (a2)
        vsxh.v     v2, (a4), v6
        ret
        .size   test_vsxh_64, .-test_vsxh_64
TEST_FUNC(test_vsxh_64_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a5)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a4)
        vle.v     v2, (a3)
        vsxh.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxh_64_vm, .-test_vsxh_64_vm
TEST_FUNC(test_vsxseg2h_32)
        vsetvli   t0, x0, e16, m2
        vlh.v     v8, (a0)
        vsh.v     v8, (a4)
        vsetvli   t0, x0, e32, m2
        vlw.v     v2, (a1)
        vlw.v     v4, (a2)
        vlw.v     v6, (a3)
        vsxseg2h.v v2, (a4), v6
        ret
        .size test_vsxseg2h_32, .-test_vsxseg2h_32


/* vsxw */
TEST_FUNC(test_vsxw_32)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a4)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a3)
        vlw.v     v2, (a2)
        vsxw.v    v2, (a4), v6
        ret
        .size   test_vsxw_32, .-test_vsxw_32
TEST_FUNC(test_vsxw_32_vm)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a2)
        vsw.v     v4, (a5)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a4)
        vlw.v     v2, (a3)
        vsxw.v    v2, (a5), v6, v0.t
        ret
        .size   test_vsxw_32_vm, .-test_vsxw_32_vm
TEST_FUNC(test_vsxw_64)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a4)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a3)
        vle.v     v2, (a2)
        vsxw.v     v2, (a4), v6
        ret
        .size   test_vsxw_64, .-test_vsxw_64
TEST_FUNC(test_vsxw_64_vm)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a2)
        vsw.v     v4, (a5)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a4)
        vle.v     v2, (a3)
        vsxw.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxw_64_vm, .-test_vsxw_64_vm
TEST_FUNC(test_vsxseg2w_64)
        vsetvli   t0, x0, e32, m2
        vlw.v     v8, (a0)
        vsw.v     v8, (a4)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vle.v     v4, (a2)
        vle.v     v6, (a3)
        vsxseg2w.v v2, (a4), v6
        ret
        .size test_vsxseg2w_64, .-test_vsxseg2w_64



/* vsxe */
TEST_FUNC(test_vsxe_8)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a1)
        vsb.v     v4, (a4)
        vsetvli   t0, a0, e8, m2
        vlb.v     v6, (a3)
        vlb.v     v2, (a2)
        vsxe.v    v2, (a4), v6
        ret
        .size   test_vsxe_8, .-test_vsxe_8
TEST_FUNC(test_vsxe_8_vm)
        vsetvli   t0, x0, e8, m2
        vlb.v     v4, (a2)
        vsb.v     v4, (a5)
        vsetvli   t0, x0, e8, m1
        vlb.v     v0, (a1)
        vsetvli   t0, a0, e8, m2
        vlb.v     v6, (a4)
        vlb.v     v2, (a3)
        vsxe.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxe_8_vm, .-test_vsxe_8_vm
TEST_FUNC(test_vsxe_16)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a1)
        vsh.v     v4, (a4)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a3)
        vlh.v     v2, (a2)
        vsxe.v    v2, (a4), v6
        ret
        .size   test_vsxe_16, .-test_vsxe_16
TEST_FUNC(test_vsxe_16_vm)
        vsetvli   t0, x0, e16, m2
        vlh.v     v4, (a2)
        vsh.v     v4, (a5)
        vsetvli   t0, x0, e16, m1
        vlh.v     v0, (a1)
        vsetvli   t0, a0, e16, m2
        vlh.v     v6, (a4)
        vlh.v     v2, (a3)
        vsxe.v     v2, (a5), v6,  v0.t
        ret
        .size   test_vsxe_16_vm, .-test_vsxe_16_vm
TEST_FUNC(test_vsxe_32)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a1)
        vsw.v     v4, (a4)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a3)
        vlw.v     v2, (a2)
        vsxe.v    v2, (a4), v6
        ret
        .size   test_vsxe_32, .-test_vsxe_32
TEST_FUNC(test_vsxe_32_vm)
        vsetvli   t0, x0, e32, m2
        vlw.v     v4, (a2)
        vsw.v     v4, (a5)
        vsetvli   t0, x0, e32, m1
        vlw.v     v0, (a1)
        vsetvli   t0, a0, e32, m2
        vlw.v     v6, (a4)
        vlw.v     v2, (a3)
        vsxe.v    v2, (a5), v6, v0.t
        ret
        .size   test_vsxe_32_vm, .-test_vsxe_32_vm
TEST_FUNC(test_vsxe_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v4, (a1)
        vse.v     v4, (a4)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a3)
        vle.v     v2, (a2)
        vsxe.v     v2, (a4), v6
        ret
        .size   test_vsxe_64, .-test_vsxe_64
TEST_FUNC(test_vsxe_64_vm)
        vsetvli   t0, x0, e64, m2
        vle.v     v4, (a2)
        vse.v     v4, (a5)
        vsetvli   t0, x0, e64, m1
        vle.v     v0, (a1)
        vsetvli   t0, a0, e64, m2
        vle.v     v6, (a4)
        vle.v     v2, (a3)
        vsxe.v     v2, (a5), v6, v0.t
        ret
        .size   test_vsxe_64_vm, .-test_vsxe_64_vm
TEST_FUNC(test_vsxseg2e_16)
        vsetvli   t0, x0, e16, m2
        vlh.v     v8, (a0)
        vsh.v     v8, (a4)
        vlh.v     v2, (a1)
        vlh.v     v4, (a2)
        vlh.v     v6, (a3)
        vsxseg2e.v v2, (a4), v6
        ret
        .size   test_vsxseg2e_16, .-test_vsxseg2e_16


/* vsaddu.vv */
TEST_FUNC(test_vsaddu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vsaddu.vv       v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsaddu_vv_8, .-test_vsaddu_vv_8

TEST_FUNC(test_vsaddu_vv_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v6, (a4)
        vlbu.v          v2, (a0)
        vlbu.v          v4, (a1)
        vsaddu.vv       v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vsaddu_vv_8_vm, .-test_vsaddu_vv_8_vm

TEST_FUNC(test_vsaddu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vsaddu.vv       v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsaddu_vv_16, .-test_vsaddu_vv_16

TEST_FUNC(test_vsaddu_vv_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1), v0.t
        vsaddu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vsaddu_vv_16_vm, .-test_vsaddu_vv_16_vm

TEST_FUNC(test_vsaddu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vsaddu.vv       v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsaddu_vv_32, .-test_vsaddu_vv_32

TEST_FUNC(test_vsaddu_vv_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v6, (a4)
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsaddu.vv       v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vsaddu_vv_32_vm, .-test_vsaddu_vv_32_vm

TEST_FUNC(test_vsaddu_vv_64)
        vsetvli         t1, x0, e32, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vsaddu.vv       v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsaddu_vv_64, .-test_vsaddu_vv_64

TEST_FUNC(test_vsaddu_vv_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsaddu.vv       v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vsaddu_vv_64_vm, .-test_vsaddu_vv_64_vm

/* vsadd.vv */
TEST_FUNC(test_vsadd_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsetvli         t1, a0, e8, m2
        vsadd.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsadd_vv_8, .-test_vsadd_vv_8

TEST_FUNC(test_vsadd_vv_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsadd.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vsadd_vv_8_vm, .-test_vsadd_vv_8_vm

TEST_FUNC(test_vsadd_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vsadd.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsadd_vv_16, .-test_vsadd_vv_16

TEST_FUNC(test_vsadd_vv_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsadd.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vsadd_vv_16_vm, .-test_vsadd_vv_16_vm

TEST_FUNC(test_vsadd_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vsadd.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsadd_vv_32, .-test_vsadd_vv_32

TEST_FUNC(test_vsadd_vv_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsadd.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vsadd_vv_32_vm, .-test_vsadd_vv_32_vm

TEST_FUNC(test_vsadd_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vsadd.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsadd_vv_64, .-test_vsadd_vv_64

TEST_FUNC(test_vsadd_vv_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsadd.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vsadd_vv_64_vm, .-test_vsadd_vv_64_vm

/* vsaddu.vx */
TEST_FUNC(test_vsaddu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, a0, e8, m2
        vsaddu.vx       v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsaddu_vx_8, .-test_vsaddu_vx_8

TEST_FUNC(test_vsaddu_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vlbu.v          v2, (a0)
        vsaddu.vx       v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vsaddu_vx_8_vm, .-test_vsaddu_vx_8_vm

TEST_FUNC(test_vsaddu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vlhu.v          v0, (a1)
        vsaddu.vx       v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsaddu_vx_16, .-test_vsaddu_vx_16

TEST_FUNC(test_vsaddu_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v2, (a0)
        vsaddu.vx       v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vsaddu_vx_16_vm, .-test_vsaddu_vx_16_vm

TEST_FUNC(test_vsaddu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vlwu.v          v0, (a1)
        vsaddu.vx       v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsaddu_vx_32, .-test_vsaddu_vx_32

TEST_FUNC(test_vsaddu_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v2, (a0)
        vsaddu.vx       v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vsaddu_vx_32_vm, .-test_vsaddu_vx_32_vm

TEST_FUNC(test_vsaddu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsaddu.vx       v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsaddu_vx_64, .-test_vsaddu_vx_64

TEST_FUNC(test_vsaddu_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vsaddu.vx       v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vsaddu_vx_64_vm, .-test_vsaddu_vx_64_vm

/* vsadd.vx */
TEST_FUNC(test_vsadd_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vsadd.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsadd_vx_8, .-test_vsadd_vx_8

TEST_FUNC(test_vsadd_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vsadd.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vsadd_vx_8_vm, .-test_vsadd_vx_8_vm

TEST_FUNC(test_vsadd_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vsadd.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsadd_vx_16, .-test_vsadd_vx_16

TEST_FUNC(test_vsadd_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vsadd.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vsadd_vx_16_vm, .-test_vsadd_vx_16_vm

TEST_FUNC(test_vsadd_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vsadd.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsadd_vx_32, .-test_vsadd_vx_32

TEST_FUNC(test_vsadd_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vsadd.vx        v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsadd_vx_32_vm, .-test_vsadd_vx_32_vm

TEST_FUNC(test_vsadd_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vsadd.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsadd_vx_64, .-test_vsadd_vx_64

TEST_FUNC(test_vsadd_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vsadd.vx        v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsadd_vx_64_vm, .-test_vsadd_vx_64_vm

/* vsaddu.vi */
TEST_FUNC(test_vsaddu_vi_8)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlbu.v          v0, (a1)
        vsaddu.vi       v4, v0, 0xf
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsaddu_vi_8, .-test_vsaddu_vi_8

TEST_FUNC(test_vsaddu_vi_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a3)
        vlbu.v          v2, (a0)
        vsaddu.vi       v4, v2, 0xf, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vsaddu_vi_8_vm, .-test_vsaddu_vi_8_vm

TEST_FUNC(test_vsaddu_vi_16)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlhu.v          v0, (a1)
        vsaddu.vi       v4, v0, 0xf
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsaddu_vi_16, .-test_vsaddu_vi_16

TEST_FUNC(test_vsaddu_vi_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a3)
        vlhu.v          v2, (a0)
        vsaddu.vi       v4, v2, 0xf, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vsaddu_vi_16_vm, .-test_vsaddu_vi_16_vm

TEST_FUNC(test_vsaddu_vi_32)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlwu.v          v0, (a1)
        vsaddu.vi       v4, v0, 0xf
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsaddu_vi_32, .-test_vsaddu_vi_32

TEST_FUNC(test_vsaddu_vi_32_vm)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a3)
        vlwu.v          v2, (a0)
        vsaddu.vi       v4, v2, 0xf, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vsaddu_vi_32_vm, .-test_vsaddu_vi_32_vm

TEST_FUNC(test_vsaddu_vi_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsaddu.vi       v4, v0, 0xf
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsaddu_vi_64, .-test_vsaddu_vi_64

TEST_FUNC(test_vsaddu_vi_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vle.v           v2, (a0)
        vsaddu.vi       v4, v2, 0xf, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vsaddu_vi_64_vm, .-test_vsaddu_vi_64_vm

/* vsadd.vi */
TEST_FUNC(test_vsadd_vi_8_min)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsadd.vi        v4, v0, 0xfffffffffffffff0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsadd_vi_8_min, .-test_vsadd_vi_8_min

TEST_FUNC(test_vsadd_vi_8_max)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vsadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vsadd_vi_8_max, .-test_vsadd_vi_8_max

TEST_FUNC(test_vsadd_vi_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vlb.v           v2, (a0)
        vsadd.vi        v4, v2, 0xfffffffffffffff0, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vsadd_vi_8_vm, .-test_vsadd_vi_8_vm

TEST_FUNC(test_vsadd_vi_16_min)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsadd.vi        v4, v0, 0xfffffffffffffff0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsadd_vi_16_min, .-test_vsadd_vi_16_min

TEST_FUNC(test_vsadd_vi_16_max)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vsadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vsadd_vi_16_max, .-test_vsadd_vi_16_max

TEST_FUNC(test_vsadd_vi_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vlh.v           v2, (a0)
        vsadd.vi        v4, v2, 0xfffffffffffffff0, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vsadd_vi_16_vm, .-test_vsadd_vi_16_vm

TEST_FUNC(test_vsadd_vi_32_min)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsadd.vi        v4, v0, 0xfffffffffffffff0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsadd_vi_32_min, .-test_vsadd_vi_32_min

TEST_FUNC(test_vsadd_vi_32_max)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vsadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vsadd_vi_32_max, .-test_vsadd_vi_32_max

TEST_FUNC(test_vsadd_vi_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vlw.v           v2, (a0)
        vsadd.vi        v4, v2, 0xe, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a1)
        ret
        .size   test_vsadd_vi_32_vm, .-test_vsadd_vi_32_vm

TEST_FUNC(test_vsadd_vi_64_min)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsadd.vi        v4, v0, 0xfffffffffffffff0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsadd_vi_64_min, .-test_vsadd_vi_64_min

TEST_FUNC(test_vsadd_vi_64_max)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vsadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vsadd_vi_64_max, .-test_vsadd_vi_64_max

TEST_FUNC(test_vsadd_vi_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vle.v           v2, (a0), v0.t
        vsadd.vi        v4, v2, 0xe, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a1)
        ret
        .size   test_vsadd_vi_64_vm, .-test_vsadd_vi_64_vm

/* vssubu.vv */
TEST_FUNC(test_vssubu_vv_8)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vsetvli         t1, a0, e8, m2
        vlbu.v          v0, (a1)
        vlbu.v          v2, (a2)
        vssubu.vv       v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssubu_vv_8, .-test_vssubu_vv_8

TEST_FUNC(test_vssubu_vv_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v6, (a4)
        vlbu.v          v2, (a0)
        vlbu.v          v4, (a1)
        vssubu.vv       v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssubu_vv_8_vm, .-test_vssubu_vv_8_vm

TEST_FUNC(test_vssubu_vv_16)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vssubu.vv       v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssubu_vv_16, .-test_vssubu_vv_16

TEST_FUNC(test_vssubu_vv_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vssubu.vv       v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssubu_vv_16_vm, .-test_vssubu_vv_16_vm

TEST_FUNC(test_vssubu_vv_32)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vssubu.vv       v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssubu_vv_32, .-test_vssubu_vv_32

TEST_FUNC(test_vssubu_vv_32_vm)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vssubu.vv       v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssubu_vv_32_vm, .-test_vssubu_vv_32_vm

TEST_FUNC(test_vssubu_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vssubu.vv       v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssubu_vv_64, .-test_vssubu_vv_64

TEST_FUNC(test_vssubu_vv_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0), v0.t
        vle.v           v4, (a1), v0.t
        vssubu.vv       v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssubu_vv_64_vm, .-test_vssubu_vv_64_vm

/* vssub.vv */
TEST_FUNC(test_vssub_vv_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vssub.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssub_vv_8, .-test_vssub_vv_8

TEST_FUNC(test_vssub_vv_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssub.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssub_vv_8_vm, .-test_vssub_vv_8_vm

TEST_FUNC(test_vssub_vv_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vssub.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssub_vv_16, .-test_vssub_vv_16

TEST_FUNC(test_vssub_vv_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssub.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssub_vv_16_vm, .-test_vssub_vv_16_vm

TEST_FUNC(test_vssub_vv_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vssub.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssub_vv_32, .-test_vssub_vv_32

TEST_FUNC(test_vssub_vv_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssub.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssub_vv_32_vm, .-test_vssub_vv_32_vm

TEST_FUNC(test_vssub_vv_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vssub.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssub_vv_64, .-test_vssub_vv_64

TEST_FUNC(test_vssub_vv_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssub.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssub_vv_64_vm, .-test_vssub_vv_64_vm

/* vssubu.vx */
TEST_FUNC(test_vssubu_vx_8)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vsetvli         t1, a0, e8, m2
        vlbu.v          v0, (a1)
        vssubu.vx       v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssubu_vx_8, .-test_vssubu_vx_8

TEST_FUNC(test_vssubu_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a4)
        vlbu.v          v2, (a0)
        vssubu.vx       v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssubu_vx_8_vm, .-test_vssubu_vx_8_vm

TEST_FUNC(test_vssubu_vx_16)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vsetvli         t1, a0, e16, m2
        vlhu.v          v0, (a1)
        vssubu.vx       v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssubu_vx_16, .-test_vssubu_vx_16

TEST_FUNC(test_vssubu_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a4)
        vlhu.v          v2, (a0)
        vssubu.vx       v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssubu_vx_16_vm, .-test_vssubu_vx_16_vm

TEST_FUNC(test_vssubu_vx_32)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vsetvli         t1, a0, e32, m2
        vlwu.v          v0, (a1)
        vssubu.vx       v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssubu_vx_32, .-test_vssubu_vx_32

TEST_FUNC(test_vssubu_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a4)
        vlwu.v          v2, (a0)
        vssubu.vx       v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vssubu_vx_32_vm, .-test_vssubu_vx_32_vm

TEST_FUNC(test_vssubu_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        vle.v           v0, (a1)
        vssubu.vx       v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssubu_vx_64, .-test_vssubu_vx_64

TEST_FUNC(test_vssubu_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vssubu.vx       v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vssubu_vx_64_vm, .-test_vssubu_vx_64_vm

/* vssub.vx */
TEST_FUNC(test_vssub_vx_8)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        vssub.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssub_vx_8, .-test_vssub_vx_8

TEST_FUNC(test_vssub_vx_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v2, (a0)
        vssub.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssub_vx_8_vm, .-test_vssub_vx_8_vm

TEST_FUNC(test_vssub_vx_16)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        vssub.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssub_vx_16, .-test_vssub_vx_16

TEST_FUNC(test_vssub_vx_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v2, (a0)
        vssub.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssub_vx_16_vm, .-test_vssub_vx_16_vm

TEST_FUNC(test_vssub_vx_32)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        vssub.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssub_vx_32, .-test_vssub_vx_32

TEST_FUNC(test_vssub_vx_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v2, (a0)
        vssub.vx        v4, v2, a1, v0.t
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vssub_vx_32_vm, .-test_vssub_vx_32_vm

TEST_FUNC(test_vssub_vx_64)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        vssub.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssub_vx_64, .-test_vssub_vx_64

TEST_FUNC(test_vssub_vx_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vssub.vx        v4, v2, a1, v0.t
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vssub_vx_64_vm, .-test_vssub_vx_64_vm

/* vaadd.vv */
TEST_FUNC(test_vaadd_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vaadd.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vaadd_vv_8_rnu, .-test_vaadd_vv_8_rnu

TEST_FUNC(test_vaadd_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vaadd_vv_8_rne, .-test_vaadd_vv_8_rne

TEST_FUNC(test_vaadd_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vaadd_vv_8_rdn, .-test_vaadd_vv_8_rdn

TEST_FUNC(test_vaadd_vv_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vaadd.vv        v4, v2, v4
        vsb.v           v4, (a2)
        ret
        .size   test_vaadd_vv_8_rod, .-test_vaadd_vv_8_rod

TEST_FUNC(test_vaadd_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vaadd.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vaadd_vv_16_rnu, .-test_vaadd_vv_16_rnu

TEST_FUNC(test_vaadd_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vaadd_vv_16_rne, .-test_vaadd_vv_16_rne

TEST_FUNC(test_vaadd_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vaadd_vv_16_rdn, .-test_vaadd_vv_16_rdn

TEST_FUNC(test_vaadd_vv_16_rod)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vaadd.vv        v4, v2, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vaadd_vv_16_rod, .-test_vaadd_vv_16_rod

TEST_FUNC(test_vaadd_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vaadd.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vaadd_vv_32_rnu, .-test_vaadd_vv_32_rnu

TEST_FUNC(test_vaadd_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vaadd_vv_32_rne, .-test_vaadd_vv_32_rne

TEST_FUNC(test_vaadd_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vaadd_vv_32_rdn, .-test_vaadd_vv_32_rdn

TEST_FUNC(test_vaadd_vv_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vaadd.vv        v4, v2, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vaadd_vv_32_rod, .-test_vaadd_vv_32_rod

TEST_FUNC(test_vaadd_vv_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vaadd.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vaadd_vv_64_rnu, .-test_vaadd_vv_64_rnu

TEST_FUNC(test_vaadd_vv_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vaadd_vv_64_rne, .-test_vaadd_vv_64_rne

TEST_FUNC(test_vaadd_vv_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vaadd.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vaadd_vv_64_rdn, .-test_vaadd_vv_64_rdn

TEST_FUNC(test_vaadd_vv_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vaadd.vv        v4, v2, v4
        vse.v           v4, (a2)
        ret
        .size   test_vaadd_vv_64_rod, .-test_vaadd_vv_64_rod

/* vaadd.vx */
TEST_FUNC(test_vaadd_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vaadd.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vaadd_vx_8_rnu, .-test_vaadd_vx_8_rnu

TEST_FUNC(test_vaadd_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vaadd_vx_8_rne, .-test_vaadd_vx_8_rne

TEST_FUNC(test_vaadd_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vaadd_vx_8_rdn, .-test_vaadd_vx_8_rdn

TEST_FUNC(test_vaadd_vx_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vaadd.vx        v4, v2, a1
        vsb.v           v4, (a2)
        ret
        .size   test_vaadd_vx_8_rod, .-test_vaadd_vx_8_rod

TEST_FUNC(test_vaadd_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vaadd.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vaadd_vx_16_rnu, .-test_vaadd_vx_16_rnu

TEST_FUNC(test_vaadd_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vaadd_vx_16_rne, .-test_vaadd_vx_16_rne

TEST_FUNC(test_vaadd_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vaadd_vx_16_rdn, .-test_vaadd_vx_16_rdn

TEST_FUNC(test_vaadd_vx_16_rod)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vaadd.vx        v4, v2, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vaadd_vx_16_rod, .-test_vaadd_vx_16_rod

TEST_FUNC(test_vaadd_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vaadd.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vaadd_vx_32_rnu, .-test_vaadd_vx_32_rnu

TEST_FUNC(test_vaadd_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vaadd_vx_32_rne, .-test_vaadd_vx_32_rne

TEST_FUNC(test_vaadd_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vaadd_vx_32_rdn, .-test_vaadd_vx_32_rdn

TEST_FUNC(test_vaadd_vx_32_rod)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vaadd.vx        v4, v2, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vaadd_vx_32_rod, .-test_vaadd_vx_32_rod

TEST_FUNC(test_vaadd_vx_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vaadd.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vaadd_vx_64_rnu, .-test_vaadd_vx_64_rnu

TEST_FUNC(test_vaadd_vx_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vaadd_vx_64_rne, .-test_vaadd_vx_64_rne

TEST_FUNC(test_vaadd_vx_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x2
        vle.v           v4, (a4)
        vle.v           v2, (a0)
        vaadd.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vaadd_vx_64_rdn, .-test_vaadd_vx_64_rdn

TEST_FUNC(test_vaadd_vx_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v4, (a3)
        vle.v           v2, (a0)
        vaadd.vx        v4, v2, a1
        vse.v           v4, (a2)
        ret
        .size   test_vaadd_vx_64_rod, .-test_vaadd_vx_64_rod

/* vaadd.vi */
TEST_FUNC(test_vaadd_vi_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vaadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vaadd_vi_8_rnu, .-test_vaadd_vi_8_rnu

TEST_FUNC(test_vaadd_vi_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vaadd_vi_8_rne, .-test_vaadd_vi_8_rne

TEST_FUNC(test_vaadd_vi_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0), v0.t
        vaadd.vi        v4, v2, 0xe, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vaadd_vi_8_rdn, .-test_vaadd_vi_8_rdn

TEST_FUNC(test_vaadd_vi_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe
        vsb.v           v4, (a1)
        ret
        .size   test_vaadd_vi_8_rod, .-test_vaadd_vi_8_rod

TEST_FUNC(test_vaadd_vi_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vaadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vaadd_vi_16_rnu, .-test_vaadd_vi_16_rnu

TEST_FUNC(test_vaadd_vi_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vaadd_vi_16_rne, .-test_vaadd_vi_16_rne

TEST_FUNC(test_vaadd_vi_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vaadd_vi_16_rdn, .-test_vaadd_vi_16_rdn

TEST_FUNC(test_vaadd_vi_16_rod)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe
        vsh.v           v4, (a1)
        ret
        .size   test_vaadd_vi_16_rod, .-test_vaadd_vi_16_rod

TEST_FUNC(test_vaadd_vi_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vaadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vaadd_vi_32_rnu, .-test_vaadd_vi_32_rnu

TEST_FUNC(test_vaadd_vi_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vaadd_vi_32_rne, .-test_vaadd_vi_32_rne

TEST_FUNC(test_vaadd_vi_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vaadd_vi_32_rdn, .-test_vaadd_vi_32_rdn

TEST_FUNC(test_vaadd_vi_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlw.v           v4, (a2)
        vlw.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe
        vsw.v           v4, (a1)
        ret
        .size   test_vaadd_vi_32_rod, .-test_vaadd_vi_32_rod

TEST_FUNC(test_vaadd_vi_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vaadd.vi        v4, v0, 0xe
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vaadd_vi_64_rnu, .-test_vaadd_vi_64_rnu

TEST_FUNC(test_vaadd_vi_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vaadd_vi_64_rne, .-test_vaadd_vi_64_rne

TEST_FUNC(test_vaadd_vi_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vaadd_vi_64_rdn, .-test_vaadd_vi_64_rdn

TEST_FUNC(test_vaadd_vi_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x2
        vle.v           v4, (a2)
        vle.v           v2, (a0)
        vaadd.vi        v4, v2, 0xe
        vse.v           v4, (a1)
        ret
        .size   test_vaadd_vi_64_rod, .-test_vaadd_vi_64_rod

/* vasub.vv */
TEST_FUNC(test_vasub_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vasub.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vasub_vv_8_rnu, .-test_vasub_vv_8_rnu

TEST_FUNC(test_vasub_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vasub_vv_8_rne, .-test_vasub_vv_8_rne

TEST_FUNC(test_vasub_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vasub_vv_8_rdn, .-test_vasub_vv_8_rdn

TEST_FUNC(test_vasub_vv_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vasub.vv        v6, v2, v4
        vsb.v           v6, (a2)
        ret
        .size   test_vasub_vv_8_rod, .-test_vasub_vv_8_rod

TEST_FUNC(test_vasub_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vasub.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vasub_vv_16_rnu, .-test_vasub_vv_16_rnu

TEST_FUNC(test_vasub_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vasub_vv_16_rne, .-test_vasub_vv_16_rne

TEST_FUNC(test_vasub_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vasub_vv_16_rdn, .-test_vasub_vv_16_rdn

TEST_FUNC(test_vasub_vv_16_rod)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vasub.vv        v6, v2, v4
        vsh.v           v6, (a2)
        ret
        .size   test_vasub_vv_16_rod, .-test_vasub_vv_16_rod

TEST_FUNC(test_vasub_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vasub.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vasub_vv_32_rnu, .-test_vasub_vv_32_rnu

TEST_FUNC(test_vasub_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vasub_vv_32_rne, .-test_vasub_vv_32_rne

TEST_FUNC(test_vasub_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vasub_vv_32_rdn, .-test_vasub_vv_32_rdn

TEST_FUNC(test_vasub_vv_32_rod)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vasub.vv        v6, v2, v4
        vsw.v           v6, (a2)
        ret
        .size   test_vasub_vv_32_rod, .-test_vasub_vv_32_rod

TEST_FUNC(test_vasub_vv_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vasub.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vasub_vv_64_rnu, .-test_vasub_vv_64_rnu

TEST_FUNC(test_vasub_vv_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vasub_vv_64_rne, .-test_vasub_vv_64_rne

TEST_FUNC(test_vasub_vv_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vasub.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vasub_vv_64_rdn, .-test_vasub_vv_64_rdn

TEST_FUNC(test_vasub_vv_64_rod)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vasub.vv        v6, v2, v4
        vse.v           v6, (a2)
        ret
        .size   test_vasub_vv_64_rod, .-test_vasub_vv_64_rod

/* vasub.vx */
TEST_FUNC(test_vasub_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vasub.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vasub_vx_8_rnu, .-test_vasub_vx_8_rnu

TEST_FUNC(test_vasub_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vasub_vx_8_rne, .-test_vasub_vx_8_rne

TEST_FUNC(test_vasub_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vasub_vx_8_rdn, .-test_vasub_vx_8_rdn

TEST_FUNC(test_vasub_vx_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vasub.vx        v4, v2, a1
        vsb.v           v4, (a2)
        ret
        .size   test_vasub_vx_8_rod, .-test_vasub_vx_8_rod

TEST_FUNC(test_vasub_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vasub.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vasub_vx_16_rnu, .-test_vasub_vx_16_rnu

TEST_FUNC(test_vasub_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vasub_vx_16_rne, .-test_vasub_vx_16_rne

TEST_FUNC(test_vasub_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vasub_vx_16_rdn, .-test_vasub_vx_16_rdn

TEST_FUNC(test_vasub_vx_16_rod)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vasub.vx        v4, v2, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vasub_vx_16_rod, .-test_vasub_vx_16_rod

TEST_FUNC(test_vasub_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vasub.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vasub_vx_32_rnu, .-test_vasub_vx_32_rnu

TEST_FUNC(test_vasub_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vasub_vx_32_rne, .-test_vasub_vx_32_rne

TEST_FUNC(test_vasub_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vasub_vx_32_rdn, .-test_vasub_vx_32_rdn

TEST_FUNC(test_vasub_vx_32_rod)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vasub.vx        v4, v2, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vasub_vx_32_rod, .-test_vasub_vx_32_rod

TEST_FUNC(test_vasub_vx_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vasub.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vasub_vx_64_rnu, .-test_vasub_vx_64_rnu

TEST_FUNC(test_vasub_vx_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vasub_vx_64_rne, .-test_vasub_vx_64_rne

TEST_FUNC(test_vasub_vx_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vasub.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vasub_vx_64_rdn, .-test_vasub_vx_64_rdn

TEST_FUNC(test_vasub_vx_64_rod)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vasub.vx        v4, v2, a1
        vse.v           v4, (a2)
        ret
        .size   test_vasub_vx_64_rod, .-test_vasub_vx_64_rod

/* vsmul.vv */
TEST_FUNC(test_vsmul_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vsmul.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsmul_vv_8_rnu, .-test_vsmul_vv_8_rnu

TEST_FUNC(test_vsmul_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vsmul_vv_8_rne, .-test_vsmul_vv_8_rne

TEST_FUNC(test_vsmul_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vsmul_vv_8_rdn, .-test_vsmul_vv_8_rdn

TEST_FUNC(test_vsmul_vv_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vsmul.vv        v4, v2, v4
        vsb.v           v4, (a2)
        ret
        .size   test_vsmul_vv_8_rod, .-test_vsmul_vv_8_rod

TEST_FUNC(test_vsmul_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vsmul.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsmul_vv_16_rnu, .-test_vsmul_vv_16_rnu

TEST_FUNC(test_vsmul_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vsmul_vv_16_rne, .-test_vsmul_vv_16_rne

TEST_FUNC(test_vsmul_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vsmul_vv_16_rdn, .-test_vsmul_vv_16_rdn

TEST_FUNC(test_vsmul_vv_16_rod)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vsmul.vv        v4, v2, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vsmul_vv_16_rod, .-test_vsmul_vv_16_rod

TEST_FUNC(test_vsmul_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vsmul.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsmul_vv_32_rnu, .-test_vsmul_vv_32_rnu

TEST_FUNC(test_vsmul_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vsmul_vv_32_rne, .-test_vsmul_vv_32_rne

TEST_FUNC(test_vsmul_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vsmul_vv_32_rdn, .-test_vsmul_vv_32_rdn

TEST_FUNC(test_vsmul_vv_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vsmul.vv        v4, v2, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vsmul_vv_32_rod, .-test_vsmul_vv_32_rod

TEST_FUNC(test_vsmul_vv_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vsmul.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        csrr            a5, vxsat
        ret
        .size   test_vsmul_vv_64_rnu, .-test_vsmul_vv_64_rnu

TEST_FUNC(test_vsmul_vv_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vsmul_vv_64_rne, .-test_vsmul_vv_64_rne

TEST_FUNC(test_vsmul_vv_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsmul.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vsmul_vv_64_rdn, .-test_vsmul_vv_64_rdn

TEST_FUNC(test_vsmul_vv_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vsmul.vv        v4, v2, v4
        vse.v           v4, (a2)
        ret
        .size   test_vsmul_vv_64_rod, .-test_vsmul_vv_64_rod

/* vsmul.vx */
TEST_FUNC(test_vsmul_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vsmul.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vsmul_vx_8_rnu, .-test_vsmul_vx_8_rnu

TEST_FUNC(test_vsmul_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vsmul_vx_8_rne, .-test_vsmul_vx_8_rne

TEST_FUNC(test_vsmul_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vsmul_vx_8_rdn, .-test_vsmul_vx_8_rdn

TEST_FUNC(test_vsmul_vx_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vsmul.vx        v4, v2, a1
        vsb.v           v4, (a2)
        ret
        .size   test_vsmul_vx_8_rod, .-test_vsmul_vx_8_rod

TEST_FUNC(test_vsmul_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vsmul.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vsmul_vx_16_rnu, .-test_vsmul_vx_16_rnu

TEST_FUNC(test_vsmul_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vsmul_vx_16_rne, .-test_vsmul_vx_16_rne

TEST_FUNC(test_vsmul_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vsmul_vx_16_rdn, .-test_vsmul_vx_16_rdn

TEST_FUNC(test_vsmul_vx_16_rod)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vsmul.vx        v4, v2, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vsmul_vx_16_rod, .-test_vsmul_vx_16_rod

TEST_FUNC(test_vsmul_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vsmul.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vsmul_vx_32_rnu, .-test_vsmul_vx_32_rnu

TEST_FUNC(test_vsmul_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vsmul_vx_32_rne, .-test_vsmul_vx_32_rne

TEST_FUNC(test_vsmul_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vsmul_vx_32_rdn, .-test_vsmul_vx_32_rdn

TEST_FUNC(test_vsmul_vx_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vsmul.vx        v4, v2, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vsmul_vx_32_rod, .-test_vsmul_vx_32_rod

TEST_FUNC(test_vsmul_vx_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vsmul.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vsmul_vx_64_rnu, .-test_vsmul_vx_64_rnu

TEST_FUNC(test_vsmul_vx_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vsmul_vx_64_rne, .-test_vsmul_vx_64_rne

TEST_FUNC(test_vsmul_vx_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vsmul.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vsmul_vx_64_rdn, .-test_vsmul_vx_64_rdn

TEST_FUNC(test_vsmul_vx_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vsmul.vx        v4, v2, a1
        vse.v           v4, (a2)
        ret
        .size   test_vsmul_vx_64_rod, .-test_vsmul_vx_64_rod

/* vwsmacc.vv */
TEST_FUNC(test_vwsmacc_vv_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vwsmacc.vv      v4, v0, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmacc_vv_8_rnu, .-test_vwsmacc_vv_8_rnu

TEST_FUNC(test_vwsmacc_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_8_rne, .-test_vwsmacc_vv_8_rne

TEST_FUNC(test_vwsmacc_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_8_rdn, .-test_vwsmacc_vv_8_rdn

TEST_FUNC(test_vwsmacc_vv_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_8_rod, .-test_vwsmacc_vv_8_rod

TEST_FUNC(test_vwsmacc_vv_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vwsmacc.vv      v4, v0, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmacc_vv_16_rnu, .-test_vwsmacc_vv_16_rnu

TEST_FUNC(test_vwsmacc_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_16_rne, .-test_vwsmacc_vv_16_rne

TEST_FUNC(test_vwsmacc_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_16_rdn, .-test_vwsmacc_vv_16_rdn

TEST_FUNC(test_vwsmacc_vv_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_16_rod, .-test_vwsmacc_vv_16_rod

TEST_FUNC(test_vwsmacc_vv_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vwsmacc.vv      v4, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmacc_vv_32_rnu, .-test_vwsmacc_vv_32_rnu

TEST_FUNC(test_vwsmacc_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_32_rne, .-test_vwsmacc_vv_32_rne

TEST_FUNC(test_vwsmacc_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_32_rdn, .-test_vwsmacc_vv_32_rdn

TEST_FUNC(test_vwsmacc_vv_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vwsmacc.vv      v8, v2, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmacc_vv_32_rod, .-test_vwsmacc_vv_32_rod

/* vwsmaccu.vv */
TEST_FUNC(test_vwsmaccu_vv_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v4, (a3)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlbu.v          v0, (a1)
        vlbu.v          v2, (a2)
        vwsmaccu.vv     v4, v0, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vv_8_rnu, .-test_vwsmaccu_vv_8_rnu

TEST_FUNC(test_vwsmaccu_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlbu.v          v2, (a0)
        vlbu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_8_rne, .-test_vwsmaccu_vv_8_rne

TEST_FUNC(test_vwsmaccu_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlbu.v          v2, (a0)
        vlbu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_8_rdn, .-test_vwsmaccu_vv_8_rdn

TEST_FUNC(test_vwsmaccu_vv_8_rod)
        vsetvli         t1, x0, e16, m4
        vlhu.v          v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlbu.v          v2, (a0)
        vlbu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_8_rod, .-test_vwsmaccu_vv_8_rod

TEST_FUNC(test_vwsmaccu_vv_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlhu.v          v0, (a1)
        vlhu.v          v2, (a2)
        vwsmaccu.vv     v4, v0, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vv_16_rnu, .-test_vwsmaccu_vv_16_rnu

TEST_FUNC(test_vwsmaccu_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_16_rne, .-test_vwsmaccu_vv_16_rne

TEST_FUNC(test_vwsmaccu_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_16_rdn, .-test_vwsmaccu_vv_16_rdn

TEST_FUNC(test_vwsmaccu_vv_16_rod)
        vsetvli         t1, x0, e32, m4
        vlwu.v          v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlhu.v          v2, (a0)
        vlhu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_16_rod, .-test_vwsmaccu_vv_16_rod

TEST_FUNC(test_vwsmaccu_vv_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlwu.v          v0, (a1)
        vlwu.v          v2, (a2)
        vwsmaccu.vv     v4, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vv_32_rnu, .-test_vwsmaccu_vv_32_rnu

TEST_FUNC(test_vwsmaccu_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_32_rne, .-test_vwsmaccu_vv_32_rne

TEST_FUNC(test_vwsmaccu_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_32_rdn, .-test_vwsmaccu_vv_32_rdn

TEST_FUNC(test_vwsmaccu_vv_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlwu.v          v2, (a0)
        vlwu.v          v4, (a1)
        vwsmaccu.vv     v8, v2, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccu_vv_32_rod, .-test_vwsmaccu_vv_32_rod

/* vwsmacc.vx */
TEST_FUNC(test_vwsmacc_vx_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        csrrwi          t2, vxrm, 0x0
        vwsmacc.vx      v4, a2, v0
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmacc_vx_8_rnu, .-test_vwsmacc_vx_8_rnu

TEST_FUNC(test_vwsmacc_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_8_rne, .-test_vwsmacc_vx_8_rne

TEST_FUNC(test_vwsmacc_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_8_rdn, .-test_vwsmacc_vx_8_rdn

TEST_FUNC(test_vwsmacc_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_8_rod, .-test_vwsmacc_vx_8_rod

TEST_FUNC(test_vwsmacc_vx_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vwsmacc.vx      v4, a2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmacc_vx_16_rnu, .-test_vwsmacc_vx_16_rnu

TEST_FUNC(test_vwsmacc_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_16_rne, .-test_vwsmacc_vx_16_rne

TEST_FUNC(test_vwsmacc_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_16_rdn, .-test_vwsmacc_vx_16_rdn

TEST_FUNC(test_vwsmacc_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_16_rod, .-test_vwsmacc_vx_16_rod

TEST_FUNC(test_vwsmacc_vx_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vwsmacc.vx      v4, a2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmacc_vx_32_rnu, .-test_vwsmacc_vx_32_rnu

TEST_FUNC(test_vwsmacc_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_32_rne, .-test_vwsmacc_vx_32_rne

TEST_FUNC(test_vwsmacc_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_32_rdn, .-test_vwsmacc_vx_32_rdn

TEST_FUNC(test_vwsmacc_vx_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vwsmacc.vx      v4, a1, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmacc_vx_32_rod, .-test_vwsmacc_vx_32_rod

/* vwsmaccu.vx */
TEST_FUNC(test_vwsmaccu_vx_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlb.v           v0, (a1)
        csrrwi          t2, vxrm, 0x0
        vwsmaccu.vx      v4, a2, v0
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vx_8_rnu, .-test_vwsmaccu_vx_8_rnu

TEST_FUNC(test_vwsmaccu_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_8_rne, .-test_vwsmaccu_vx_8_rne

TEST_FUNC(test_vwsmaccu_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_8_rdn, .-test_vwsmaccu_vx_8_rdn

TEST_FUNC(test_vwsmaccu_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_8_rod, .-test_vwsmaccu_vx_8_rod

TEST_FUNC(test_vwsmaccu_vx_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vwsmaccu.vx      v4, a2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vx_16_rnu, .-test_vwsmaccu_vx_16_rnu

TEST_FUNC(test_vwsmaccu_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_16_rne, .-test_vwsmaccu_vx_16_rne

TEST_FUNC(test_vwsmaccu_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_16_rdn, .-test_vwsmaccu_vx_16_rdn

TEST_FUNC(test_vwsmaccu_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_16_rod, .-test_vwsmaccu_vx_16_rod

TEST_FUNC(test_vwsmaccu_vx_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vwsmaccu.vx      v4, a2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmaccu_vx_32_rnu, .-test_vwsmaccu_vx_32_rnu

TEST_FUNC(test_vwsmaccu_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_32_rne, .-test_vwsmaccu_vx_32_rne

TEST_FUNC(test_vwsmaccu_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_32_rdn, .-test_vwsmaccu_vx_32_rdn

TEST_FUNC(test_vwsmaccu_vx_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vwsmaccu.vx      v4, a1, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccu_vx_32_rod, .-test_vwsmaccu_vx_32_rod

/* vwsmaccsu.vv */
TEST_FUNC(test_vwsmaccsu_vv_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlbu.v          v0, (a1)
        vlb.v           v2, (a2)
        vwsmaccsu.vv    v4, v0, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vv_8_rnu, .-test_vwsmaccsu_vv_8_rnu

TEST_FUNC(test_vwsmaccsu_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlbu.v          v2, (a0)
        vlb.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_8_rne, .-test_vwsmaccsu_vv_8_rne

TEST_FUNC(test_vwsmaccsu_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlbu.v          v2, (a0)
        vlb.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_8_rdn, .-test_vwsmaccsu_vv_8_rdn

TEST_FUNC(test_vwsmaccsu_vv_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlbu.v          v2, (a0)
        vlb.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4
        vsetvli         t1, x0, e16, m4
        vsh.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_8_rod, .-test_vwsmaccsu_vv_8_rod

TEST_FUNC(test_vwsmaccsu_vv_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlhu.v          v0, (a1)
        vlh.v           v2, (a2)
        vwsmaccsu.vv    v4, v0, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vv_16_rnu, .-test_vwsmaccsu_vv_16_rnu

TEST_FUNC(test_vwsmaccsu_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlhu.v          v2, (a0)
        vlh.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_16_rne, .-test_vwsmaccsu_vv_16_rne

TEST_FUNC(test_vwsmaccsu_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlhu.v          v2, (a0)
        vlh.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_16_rdn, .-test_vwsmaccsu_vv_16_rdn

TEST_FUNC(test_vwsmaccsu_vv_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlhu.v          v2, (a0)
        vlh.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4
        vsetvli         t1, x0, e32, m4
        vsw.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_16_rod, .-test_vwsmaccsu_vv_16_rod

TEST_FUNC(test_vwsmaccsu_vv_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlwu.v          v0, (a1)
        vlw.v           v2, (a2)
        vwsmaccsu.vv    v4, v0, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vv_32_rnu, .-test_vwsmaccsu_vv_32_rnu

TEST_FUNC(test_vwsmaccsu_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlwu.v          v2, (a0)
        vlw.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_32_rne, .-test_vwsmaccsu_vv_32_rne

TEST_FUNC(test_vwsmaccsu_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlwu.v          v2, (a0)
        vlw.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_32_rdn, .-test_vwsmaccsu_vv_32_rdn

TEST_FUNC(test_vwsmaccsu_vv_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v8, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlwu.v          v2, (a0)
        vlw.v           v4, (a1)
        vwsmaccsu.vv    v8, v2, v4
        vsetvli         t1, x0, e64, m4
        vse.v           v8, (a3)
        ret
        .size   test_vwsmaccsu_vv_32_rod, .-test_vwsmaccsu_vv_32_rod

/* vwsmaccus.vx */
TEST_FUNC(test_vwsmaccus_vx_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlbu.v          v0, (a1)
        csrrwi          t2, vxrm, 0x0
        vwsmaccus.vx    v4, a2, v0
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmaccus_vx_8_rnu, .-test_vwsmaccus_vx_8_rnu

TEST_FUNC(test_vwsmaccus_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlbu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_8_rne, .-test_vwsmaccus_vx_8_rne

TEST_FUNC(test_vwsmaccus_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlbu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_8_rdn, .-test_vwsmaccus_vx_8_rdn

TEST_FUNC(test_vwsmaccus_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlbu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_8_rod, .-test_vwsmaccus_vx_8_rod

TEST_FUNC(test_vwsmaccus_vx_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlhu.v          v0, (a1)
        vwsmaccus.vx    v4, a2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmaccus_vx_16_rnu, .-test_vwsmaccus_vx_16_rnu

TEST_FUNC(test_vwsmaccus_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlhu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_16_rne, .-test_vwsmaccus_vx_16_rne

TEST_FUNC(test_vwsmaccus_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlhu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_16_rdn, .-test_vwsmaccus_vx_16_rdn

TEST_FUNC(test_vwsmaccus_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlhu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_16_rod, .-test_vwsmaccus_vx_16_rod

TEST_FUNC(test_vwsmaccus_vx_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlwu.v          v0, (a1)
        vwsmaccus.vx    v4, a2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmaccus_vx_32_rnu, .-test_vwsmaccus_vx_32_rnu

TEST_FUNC(test_vwsmaccus_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlwu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_32_rne, .-test_vwsmaccus_vx_32_rne

TEST_FUNC(test_vwsmaccus_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlwu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_32_rdn, .-test_vwsmaccus_vx_32_rdn

TEST_FUNC(test_vwsmaccus_vx_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlwu.v          v2, (a0)
        vwsmaccus.vx    v4, a1, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccus_vx_32_rod, .-test_vwsmaccus_vx_32_rod

/* vwsmaccsu.vx */
TEST_FUNC(test_vwsmaccsu_vx_8_rnu)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e8, m2
        vlbu.v          v0, (a1)
        csrrwi          t2, vxrm, 0x0
        vwsmaccsu.vx    v4, a2, v0
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vx_8_rnu, .-test_vwsmaccsu_vx_8_rnu

TEST_FUNC(test_vwsmaccsu_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlbu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_8_rne, .-test_vwsmaccsu_vx_8_rne

TEST_FUNC(test_vwsmaccsu_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x2
        vlbu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_8_rdn, .-test_vwsmaccsu_vx_8_rdn

TEST_FUNC(test_vwsmaccsu_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a2)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlbu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2
        vsetvli         t1, x0, e16, m4
        vsh.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_8_rod, .-test_vwsmaccsu_vx_8_rod

TEST_FUNC(test_vwsmaccsu_vx_16_rnu)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlhu.v          v0, (a1)
        vwsmaccsu.vx    v4, a2, v0
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vx_16_rnu, .-test_vwsmaccsu_vx_16_rnu

TEST_FUNC(test_vwsmaccsu_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x1
        vlhu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_16_rne, .-test_vwsmaccsu_vx_16_rne

TEST_FUNC(test_vwsmaccsu_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a4)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x2
        vlhu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_16_rdn, .-test_vwsmaccsu_vx_16_rdn

TEST_FUNC(test_vwsmaccsu_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v4, (a2)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlhu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2
        vsetvli         t1, x0, e32, m4
        vsw.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_16_rod, .-test_vwsmaccsu_vx_16_rod

TEST_FUNC(test_vwsmaccsu_vx_32_rnu)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a3)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlwu.v          v0, (a1)
        vwsmaccsu.vx    v4, a2, v0
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a4)
        ret
        .size   test_vwsmaccsu_vx_32_rnu, .-test_vwsmaccsu_vx_32_rnu

TEST_FUNC(test_vwsmaccsu_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x1
        vlwu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_32_rne, .-test_vwsmaccsu_vx_32_rne

TEST_FUNC(test_vwsmaccsu_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a4)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x2
        vlwu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2, v0.t
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_32_rdn, .-test_vwsmaccsu_vx_32_rdn

TEST_FUNC(test_vwsmaccsu_vx_32_rod)
        vsetvli         t1, x0, e64, m4
        vle.v           v4, (a2)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlwu.v          v2, (a0)
        vwsmaccsu.vx    v4, a1, v2
        vsetvli         t1, x0, e64, m4
        vse.v           v4, (a3)
        ret
        .size   test_vwsmaccsu_vx_32_rod, .-test_vwsmaccsu_vx_32_rod

/* vssrl.vv */
TEST_FUNC(test_vssrl_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vssrl.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vssrl_vv_8_rnu, .-test_vssrl_vv_8_rnu

TEST_FUNC(test_vssrl_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssrl_vv_8_rne, .-test_vssrl_vv_8_rne

TEST_FUNC(test_vssrl_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssrl_vv_8_rdn, .-test_vssrl_vv_8_rdn

TEST_FUNC(test_vssrl_vv_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssrl.vv        v4, v2, v4
        vsb.v           v4, (a2)
        ret
        .size   test_vssrl_vv_8_rod, .-test_vssrl_vv_8_rod

TEST_FUNC(test_vssrl_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vssrl.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vssrl_vv_16_rnu, .-test_vssrl_vv_16_rnu

TEST_FUNC(test_vssrl_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssrl_vv_16_rne, .-test_vssrl_vv_16_rne

TEST_FUNC(test_vssrl_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssrl_vv_16_rdn, .-test_vssrl_vv_16_rdn

TEST_FUNC(test_vssrl_vv_16_rod)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssrl.vv        v4, v2, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vssrl_vv_16_rod, .-test_vssrl_vv_16_rod

TEST_FUNC(test_vssrl_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vssrl.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssrl_vv_32_rnu, .-test_vssrl_vv_32_rnu

TEST_FUNC(test_vssrl_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssrl_vv_32_rne, .-test_vssrl_vv_32_rne

TEST_FUNC(test_vssrl_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssrl_vv_32_rdn, .-test_vssrl_vv_32_rdn

TEST_FUNC(test_vssrl_vv_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssrl.vv        v4, v2, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vssrl_vv_32_rod, .-test_vssrl_vv_32_rod

TEST_FUNC(test_vssrl_vv_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vssrl.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssrl_vv_64_rnu, .-test_vssrl_vv_64_rnu

TEST_FUNC(test_vssrl_vv_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssrl_vv_64_rne, .-test_vssrl_vv_64_rne

TEST_FUNC(test_vssrl_vv_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssrl.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssrl_vv_64_rdn, .-test_vssrl_vv_64_rdn

TEST_FUNC(test_vssrl_vv_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssrl.vv        v4, v2, v4
        vse.v           v4, (a2)
        ret
        .size   test_vssrl_vv_64_rod, .-test_vssrl_vv_64_rod

/* vssrl.vx */
TEST_FUNC(test_vssrl_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssrl_vx_8_rnu, .-test_vssrl_vx_8_rnu

TEST_FUNC(test_vssrl_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssrl_vx_8_rne, .-test_vssrl_vx_8_rne

TEST_FUNC(test_vssrl_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssrl_vx_8_rdn, .-test_vssrl_vx_8_rdn

TEST_FUNC(test_vssrl_vx_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vssrl.vx        v4, v2, a1
        vsb.v           v4, (a2)
        ret
        .size   test_vssrl_vx_8_rod, .-test_vssrl_vx_8_rod

TEST_FUNC(test_vssrl_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssrl_vx_16_rnu, .-test_vssrl_vx_16_rnu

TEST_FUNC(test_vssrl_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssrl_vx_16_rne, .-test_vssrl_vx_16_rne

TEST_FUNC(test_vssrl_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssrl_vx_16_rdn, .-test_vssrl_vx_16_rdn

TEST_FUNC(test_vssrl_vx_16_rod)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vssrl.vx        v4, v2, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vssrl_vx_16_rod, .-test_vssrl_vx_16_rod

TEST_FUNC(test_vssrl_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssrl_vx_32_rnu, .-test_vssrl_vx_32_rnu

TEST_FUNC(test_vssrl_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vssrl_vx_32_rne, .-test_vssrl_vx_32_rne

TEST_FUNC(test_vssrl_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vssrl_vx_32_rdn, .-test_vssrl_vx_32_rdn

TEST_FUNC(test_vssrl_vx_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vssrl.vx        v4, v2, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vssrl_vx_32_rod, .-test_vssrl_vx_32_rod

TEST_FUNC(test_vssrl_vx_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssrl_vx_64_rnu, .-test_vssrl_vx_64_rnu

TEST_FUNC(test_vssrl_vx_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vssrl_vx_64_rne, .-test_vssrl_vx_64_rne

TEST_FUNC(test_vssrl_vx_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vssrl.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vssrl_vx_64_rdn, .-test_vssrl_vx_64_rdn

TEST_FUNC(test_vssrl_vx_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vssrl.vx        v4, v2, a1
        vse.v           v4, (a2)
        ret
        .size   test_vssrl_vx_64_rod, .-test_vssrl_vx_64_rod

/* vssrl.vi */
TEST_FUNC(test_vssrl_vi_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vi        v4, v0, 0x3
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vssrl_vi_8_rnu, .-test_vssrl_vi_8_rnu

TEST_FUNC(test_vssrl_vi_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vssrl.vi        v4, v2, 0x3, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vssrl_vi_8_rne, .-test_vssrl_vi_8_rne

TEST_FUNC(test_vssrl_vi_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0), v0.t
        vssrl.vi        v4, v2, 0x3, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vssrl_vi_8_rdn, .-test_vssrl_vi_8_rdn

TEST_FUNC(test_vssrl_vi_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vssrl.vi        v4, v2, 0x3
        vsb.v           v4, (a1)
        ret
        .size   test_vssrl_vi_8_rod, .-test_vssrl_vi_8_rod

TEST_FUNC(test_vssrl_vi_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vi        v4, v0, 0x7
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vssrl_vi_16_rnu, .-test_vssrl_vi_16_rnu

TEST_FUNC(test_vssrl_vi_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vssrl.vi        v4, v2, 0x7, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vssrl_vi_16_rne, .-test_vssrl_vi_16_rne

TEST_FUNC(test_vssrl_vi_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vssrl.vi        v4, v2, 0x7, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vssrl_vi_16_rdn, .-test_vssrl_vi_16_rdn

TEST_FUNC(test_vssrl_vi_16_rod)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vssrl.vi        v4, v2, 0x7
        vsh.v           v4, (a1)
        ret
        .size   test_vssrl_vi_16_rod, .-test_vssrl_vi_16_rod

TEST_FUNC(test_vssrl_vi_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vi        v4, v0, 0xe
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vssrl_vi_32_rnu, .-test_vssrl_vi_32_rnu

TEST_FUNC(test_vssrl_vi_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vssrl_vi_32_rne, .-test_vssrl_vi_32_rne

TEST_FUNC(test_vssrl_vi_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vssrl_vi_32_rdn, .-test_vssrl_vi_32_rdn

TEST_FUNC(test_vssrl_vi_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v4, (a2)
        vlw.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe
        vsw.v           v4, (a1)
        ret
        .size   test_vssrl_vi_32_rod, .-test_vssrl_vi_32_rod

TEST_FUNC(test_vssrl_vi_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vssrl.vi        v4, v0, 0xe
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vssrl_vi_64_rnu, .-test_vssrl_vi_64_rnu

TEST_FUNC(test_vssrl_vi_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vssrl_vi_64_rne, .-test_vssrl_vi_64_rne

TEST_FUNC(test_vssrl_vi_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vssrl_vi_64_rdn, .-test_vssrl_vi_64_rdn

TEST_FUNC(test_vssrl_vi_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v4, (a2)
        vle.v           v2, (a0)
        vssrl.vi        v4, v2, 0xe
        vse.v           v4, (a1)
        ret
        .size   test_vssrl_vi_64_rod, .-test_vssrl_vi_64_rod

/* vssra.vv */
TEST_FUNC(test_vssra_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vlb.v           v0, (a1)
        vlb.v           v2, (a2)
        vssra.vv        v4, v0, v2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vssra_vv_8_rnu, .-test_vssra_vv_8_rnu

TEST_FUNC(test_vssra_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x1
        vlb.v           v6, (a4)
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssra_vv_8_rne, .-test_vssra_vv_8_rne

TEST_FUNC(test_vssra_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vssra_vv_8_rdn, .-test_vssra_vv_8_rdn

TEST_FUNC(test_vssra_vv_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vlb.v           v4, (a1)
        vssra.vv        v4, v2, v4
        vsb.v           v4, (a2)
        ret
        .size   test_vssra_vv_8_rod, .-test_vssra_vv_8_rod

TEST_FUNC(test_vssra_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v0, (a1)
        vlh.v           v2, (a2)
        vssra.vv        v4, v0, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        csrr            a0, vxsat
        ret
        .size   test_vssra_vv_16_rnu, .-test_vssra_vv_16_rnu

TEST_FUNC(test_vssra_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssra_vv_16_rne, .-test_vssra_vv_16_rne

TEST_FUNC(test_vssra_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vssra_vv_16_rdn, .-test_vssra_vv_16_rdn

TEST_FUNC(test_vssra_vv_16_rod)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vlh.v           v4, (a1)
        vssra.vv        v4, v2, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vssra_vv_16_rod, .-test_vssra_vv_16_rod

TEST_FUNC(test_vssra_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v0, (a1)
        vlw.v           v2, (a2)
        vssra.vv        v4, v0, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssra_vv_32_rnu, .-test_vssra_vv_32_rnu

TEST_FUNC(test_vssra_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssra_vv_32_rne, .-test_vssra_vv_32_rne

TEST_FUNC(test_vssra_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vssra_vv_32_rdn, .-test_vssra_vv_32_rdn

TEST_FUNC(test_vssra_vv_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vlw.v           v4, (a1)
        vssra.vv        v4, v2, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vssra_vv_32_rod, .-test_vssra_vv_32_rod

TEST_FUNC(test_vssra_vv_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vle.v           v0, (a1)
        vle.v           v2, (a2)
        vssra.vv        v4, v0, v2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssra_vv_64_rnu, .-test_vssra_vv_64_rnu

TEST_FUNC(test_vssra_vv_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssra_vv_64_rne, .-test_vssra_vv_64_rne

TEST_FUNC(test_vssra_vv_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssra.vv        v6, v2, v4, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vssra_vv_64_rdn, .-test_vssra_vv_64_rdn

TEST_FUNC(test_vssra_vv_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vle.v           v4, (a1)
        vssra.vv        v4, v2, v4
        vse.v           v4, (a2)
        ret
        .size   test_vssra_vv_64_rod, .-test_vssra_vv_64_rod

/* vssra.vx */
TEST_FUNC(test_vssra_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vx        v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vssra_vx_8_rnu, .-test_vssra_vx_8_rnu

TEST_FUNC(test_vssra_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssra_vx_8_rne, .-test_vssra_vx_8_rne

TEST_FUNC(test_vssra_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsb.v           v4, (a2)
        ret
        .size   test_vssra_vx_8_rdn, .-test_vssra_vx_8_rdn

TEST_FUNC(test_vssra_vx_8_rod)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vssra.vx        v4, v2, a1
        vsb.v           v4, (a2)
        ret
        .size   test_vssra_vx_8_rod, .-test_vssra_vx_8_rod

TEST_FUNC(test_vssra_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vx        v4, v0, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vssra_vx_16_rnu, .-test_vssra_vx_16_rnu

TEST_FUNC(test_vssra_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssra_vx_16_rne, .-test_vssra_vx_16_rne

TEST_FUNC(test_vssra_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsh.v           v4, (a2)
        ret
        .size   test_vssra_vx_16_rdn, .-test_vssra_vx_16_rdn

TEST_FUNC(test_vssra_vx_16_rod)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vssra.vx        v4, v2, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vssra_vx_16_rod, .-test_vssra_vx_16_rod

TEST_FUNC(test_vssra_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vx        v4, v0, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vssra_vx_32_rnu, .-test_vssra_vx_32_rnu

TEST_FUNC(test_vssra_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vssra_vx_32_rne, .-test_vssra_vx_32_rne

TEST_FUNC(test_vssra_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vsw.v           v4, (a2)
        ret
        .size   test_vssra_vx_32_rdn, .-test_vssra_vx_32_rdn

TEST_FUNC(test_vssra_vx_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v2, (a0)
        vssra.vx        v4, v2, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vssra_vx_32_rod, .-test_vssra_vx_32_rod

TEST_FUNC(test_vssra_vx_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vx        v4, v0, a2
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vssra_vx_64_rnu, .-test_vssra_vx_64_rnu

TEST_FUNC(test_vssra_vx_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vssra_vx_64_rne, .-test_vssra_vx_64_rne

TEST_FUNC(test_vssra_vx_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a4)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vssra.vx        v4, v2, a1, v0.t
        vse.v           v4, (a2)
        ret
        .size   test_vssra_vx_64_rdn, .-test_vssra_vx_64_rdn

TEST_FUNC(test_vssra_vx_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v2, (a0)
        vssra.vx        v4, v2, a1
        vse.v           v4, (a2)
        ret
        .size   test_vssra_vx_64_rod, .-test_vssra_vx_64_rod

/* vssra.vi */
TEST_FUNC(test_vssra_vi_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vlb.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vi        v4, v0, 0x3
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vssra_vi_8_rnu, .-test_vssra_vi_8_rnu

TEST_FUNC(test_vssra_vi_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v2, (a0)
        vssra.vi        v4, v2, 0x3, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vssra_vi_8_rne, .-test_vssra_vi_8_rne

TEST_FUNC(test_vssra_vi_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v2, (a0), v0.t
        vssra.vi        v4, v2, 0x3, v0.t
        vsb.v           v4, (a1)
        ret
        .size   test_vssra_vi_8_rdn, .-test_vssra_vi_8_rdn

TEST_FUNC(test_vssra_vi_8_rod)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a0)
        vssra.vi        v4, v2, 0x3
        vsb.v           v4, (a1)
        ret
        .size   test_vssra_vi_8_rod, .-test_vssra_vi_8_rod

TEST_FUNC(test_vssra_vi_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vi        v4, v0, 0x7
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vssra_vi_16_rnu, .-test_vssra_vi_16_rnu

TEST_FUNC(test_vssra_vi_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v2, (a0)
        vssra.vi        v4, v2, 0x7, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vssra_vi_16_rne, .-test_vssra_vi_16_rne

TEST_FUNC(test_vssra_vi_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v2, (a0)
        vssra.vi        v4, v2, 0x7, v0.t
        vsh.v           v4, (a1)
        ret
        .size   test_vssra_vi_16_rdn, .-test_vssra_vi_16_rdn

TEST_FUNC(test_vssra_vi_16_rod)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a2)
        csrrwi          t2, vxrm, 0x3
        vlh.v           v2, (a0)
        vssra.vi        v4, v2, 0x7
        vsh.v           v4, (a1)
        ret
        .size   test_vssra_vi_16_rod, .-test_vssra_vi_16_rod

TEST_FUNC(test_vssra_vi_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vlw.v           v0, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vi        v4, v0, 0xe
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vssra_vi_32_rnu, .-test_vssra_vi_32_rnu

TEST_FUNC(test_vssra_vi_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v2, (a0)
        vssra.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vssra_vi_32_rne, .-test_vssra_vi_32_rne

TEST_FUNC(test_vssra_vi_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v2, (a0)
        vssra.vi        v4, v2, 0xe, v0.t
        vsw.v           v4, (a1)
        ret
        .size   test_vssra_vi_32_rdn, .-test_vssra_vi_32_rdn

TEST_FUNC(test_vssra_vi_32_rod)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v4, (a2)
        vlw.v           v2, (a0)
        vssra.vi        v4, v2, 0xe
        vsw.v           v4, (a1)
        ret
        .size   test_vssra_vi_32_rod, .-test_vssra_vi_32_rod

TEST_FUNC(test_vssra_vi_64_rnu)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        vle.v           v0, (a1)
        vsetvli         t1, a0, e64, m2
        csrrwi          t2, vxrm, 0x0
        vssra.vi        v4, v0, 0xe
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a2)
        ret
        .size   test_vssra_vi_64_rnu, .-test_vssra_vi_64_rnu

TEST_FUNC(test_vssra_vi_64_rne)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x1
        vle.v           v2, (a0)
        vssra.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vssra_vi_64_rne, .-test_vssra_vi_64_rne

TEST_FUNC(test_vssra_vi_64_rdn)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a2)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a3)
        csrrwi          t2, vxrm, 0x2
        vle.v           v2, (a0)
        vssra.vi        v4, v2, 0xe, v0.t
        vse.v           v4, (a1)
        ret
        .size   test_vssra_vi_64_rdn, .-test_vssra_vi_64_rdn

TEST_FUNC(test_vssra_vi_64_rod)
        vsetvli         t1, x0, e64, m2
        csrrwi          t2, vxrm, 0x3
        vle.v           v4, (a2)
        vle.v           v2, (a0)
        vssra.vi        v4, v2, 0xe
        vse.v           v4, (a1)
        ret
        .size   test_vssra_vi_64_rod, .-test_vssra_vi_64_rod

/* vnclip.vv */
TEST_FUNC(test_vnclip_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v6, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vv       v4, v0, v6
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnclip_vv_8_rnu, .-test_vnclip_vv_8_rnu

TEST_FUNC(test_vnclip_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclip_vv_8_rne, .-test_vnclip_vv_8_rne

TEST_FUNC(test_vnclip_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclip_vv_8_rdn, .-test_vnclip_vv_8_rdn

TEST_FUNC(test_vnclip_vv_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a1)
        vnclip.vv       v0, v4, v2
        vsb.v           v0, (a2)
        ret
        .size   test_vnclip_vv_8_rod, .-test_vnclip_vv_8_rod

TEST_FUNC(test_vnclip_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v2, (a2)
        vnclip.vv       v4, v8, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnclip_vv_16_rnu, .-test_vnclip_vv_16_rnu

TEST_FUNC(test_vnclip_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclip_vv_16_rne, .-test_vnclip_vv_16_rne

TEST_FUNC(test_vnclip_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclip_vv_16_rdn, .-test_vnclip_vv_16_rdn

TEST_FUNC(test_vnclip_vv_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v4, (a1)
        vnclip.vv       v4, v8, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vnclip_vv_16_rod, .-test_vnclip_vv_16_rod

TEST_FUNC(test_vnclip_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v2, (a2)
        vnclip.vv       v4, v8, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnclip_vv_32_rnu, .-test_vnclip_vv_32_rnu

TEST_FUNC(test_vnclip_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclip_vv_32_rne, .-test_vnclip_vv_32_rne

TEST_FUNC(test_vnclip_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v4, (a1)
        vnclip.vv       v6, v8, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclip_vv_32_rdn, .-test_vnclip_vv_32_rdn

TEST_FUNC(test_vnclip_vv_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v4, (a1)
        vnclip.vv       v4, v8, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vnclip_vv_32_rod, .-test_vnclip_vv_32_rod

/* vnclipu.vv */
TEST_FUNC(test_vnclipu_vv_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vlb.v           v6, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vv      v4, v0, v6
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnclipu_vv_8_rnu, .-test_vnclipu_vv_8_rnu

TEST_FUNC(test_vnclipu_vv_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlb.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_8_rne, .-test_vnclipu_vv_8_rne

TEST_FUNC(test_vnclipu_vv_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlb.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_8_rdn, .-test_vnclipu_vv_8_rdn

TEST_FUNC(test_vnclipu_vv_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vlb.v           v2, (a1)
        vnclipu.vv      v0, v4, v2
        vsb.v           v0, (a2)
        ret
        .size   test_vnclipu_vv_8_rod, .-test_vnclipu_vv_8_rod

TEST_FUNC(test_vnclipu_vv_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vlh.v           v2, (a2)
        vnclipu.vv      v4, v8, v2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnclipu_vv_16_rnu, .-test_vnclipu_vv_16_rnu

TEST_FUNC(test_vnclipu_vv_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlh.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_16_rne, .-test_vnclipu_vv_16_rne

TEST_FUNC(test_vnclipu_vv_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlh.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_16_rdn, .-test_vnclipu_vv_16_rdn

TEST_FUNC(test_vnclipu_vv_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vlh.v           v4, (a1)
        vnclipu.vv      v4, v8, v4
        vsh.v           v4, (a2)
        ret
        .size   test_vnclipu_vv_16_rod, .-test_vnclipu_vv_16_rod

TEST_FUNC(test_vnclipu_vv_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vlw.v           v2, (a2)
        vnclipu.vv      v4, v8, v2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnclipu_vv_32_rnu, .-test_vnclipu_vv_32_rnu

TEST_FUNC(test_vnclipu_vv_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vlw.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_32_rne, .-test_vnclipu_vv_32_rne

TEST_FUNC(test_vnclipu_vv_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vlw.v           v4, (a1)
        vnclipu.vv      v6, v8, v4, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclipu_vv_32_rdn, .-test_vnclipu_vv_32_rdn

TEST_FUNC(test_vnclipu_vv_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vlw.v           v4, (a1)
        vnclipu.vv      v4, v8, v4
        vsw.v           v4, (a2)
        ret
        .size   test_vnclipu_vv_32_rod, .-test_vnclipu_vv_32_rod

/* vnclip.vx */
TEST_FUNC(test_vnclip_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vx       v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnclip_vx_8_rnu, .-test_vnclip_vx_8_rnu

TEST_FUNC(test_vnclip_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclip.vx       v6, v8, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclip_vx_8_rne, .-test_vnclip_vx_8_rne

TEST_FUNC(test_vnclip_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclip.vx       v6, v8, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclip_vx_8_rdn, .-test_vnclip_vx_8_rdn

TEST_FUNC(test_vnclip_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vx       v0, v4, a1
        vsb.v           v0, (a2)
        ret
        .size   test_vnclip_vx_8_rod, .-test_vnclip_vx_8_rod

TEST_FUNC(test_vnclip_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vx       v4, v8, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnclip_vx_16_rnu, .-test_vnclip_vx_16_rnu

TEST_FUNC(test_vnclip_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclip.vx       v6, v8, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclip_vx_16_rne, .-test_vnclip_vx_16_rne

TEST_FUNC(test_vnclip_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclip.vx       v6, v8, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclip_vx_16_rdn, .-test_vnclip_vx_16_rdn

TEST_FUNC(test_vnclip_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vx       v4, v8, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vnclip_vx_16_rod, .-test_vnclip_vx_16_rod

TEST_FUNC(test_vnclip_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vx       v4, v8, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnclip_vx_32_rnu, .-test_vnclip_vx_32_rnu

TEST_FUNC(test_vnclip_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclip.vx       v6, v8, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclip_vx_32_rne, .-test_vnclip_vx_32_rne

TEST_FUNC(test_vnclip_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclip.vx       v6, v8, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclip_vx_32_rdn, .-test_vnclip_vx_32_rdn

TEST_FUNC(test_vnclip_vx_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vx       v4, v8, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vnclip_vx_32_rod, .-test_vnclip_vx_32_rod

/* vnclipu.vx */
TEST_FUNC(test_vnclipu_vx_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a4)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vx      v4, v0, a2
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vnclipu_vx_8_rnu, .-test_vnclipu_vx_8_rnu

TEST_FUNC(test_vnclipu_vx_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vx      v6, v8, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_8_rne, .-test_vnclipu_vx_8_rne

TEST_FUNC(test_vnclipu_vx_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vx      v6, v8, a1, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_8_rdn, .-test_vnclipu_vx_8_rdn

TEST_FUNC(test_vnclipu_vx_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vx      v0, v4, a1
        vsb.v           v0, (a2)
        ret
        .size   test_vnclipu_vx_8_rod, .-test_vnclipu_vx_8_rod

TEST_FUNC(test_vnclipu_vx_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a4)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vx      v4, v8, a2
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vnclipu_vx_16_rnu, .-test_vnclipu_vx_16_rnu

TEST_FUNC(test_vnclipu_vx_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vx      v6, v8, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_16_rne, .-test_vnclipu_vx_16_rne

TEST_FUNC(test_vnclipu_vx_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vx      v6, v8, a1, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_16_rdn, .-test_vnclipu_vx_16_rdn

TEST_FUNC(test_vnclipu_vx_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vx      v4, v8, a1
        vsh.v           v4, (a2)
        ret
        .size   test_vnclipu_vx_16_rod, .-test_vnclipu_vx_16_rod

TEST_FUNC(test_vnclipu_vx_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a4)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vx      v4, v8, a2
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vnclipu_vx_32_rnu, .-test_vnclipu_vx_32_rnu

TEST_FUNC(test_vnclipu_vx_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vx      v6, v8, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_32_rne, .-test_vnclipu_vx_32_rne

TEST_FUNC(test_vnclipu_vx_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a4)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vx      v6, v8, a1, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vnclipu_vx_32_rdn, .-test_vnclipu_vx_32_rdn

TEST_FUNC(test_vnclipu_vx_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vx      v4, v8, a1
        vsw.v           v4, (a2)
        ret
        .size   test_vnclipu_vx_32_rod, .-test_vnclipu_vx_32_rod

/* vnclip.vi */
TEST_FUNC(test_vnclip_vi_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vi       v4, v0, 0x5
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnclip_vi_8_rnu, .-test_vnclip_vi_8_rnu

TEST_FUNC(test_vnclip_vi_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclip.vi       v6, v8, 0x5, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vnclip_vi_8_rne, .-test_vnclip_vi_8_rne

TEST_FUNC(test_vnclip_vi_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclip.vi       v6, v8, 0x5, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vnclip_vi_8_rdn, .-test_vnclip_vi_8_rdn

TEST_FUNC(test_vnclip_vi_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vi       v0, v4, 0x5
        vsb.v           v0, (a1)
        ret
        .size   test_vnclip_vi_8_rod, .-test_vnclip_vi_8_rod

TEST_FUNC(test_vnclip_vi_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vi       v4, v8, 0xc
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnclip_vi_16_rnu, .-test_vnclip_vi_16_rnu

TEST_FUNC(test_vnclip_vi_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclip.vi       v6, v8, 0xc, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vnclip_vi_16_rne, .-test_vnclip_vi_16_rne

TEST_FUNC(test_vnclip_vi_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclip.vi       v6, v8, 0xc, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vnclip_vi_16_rdn, .-test_vnclip_vi_16_rdn

TEST_FUNC(test_vnclip_vi_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vi       v4, v8, 0xc
        vsh.v           v4, (a1)
        ret
        .size   test_vnclip_vi_16_rod, .-test_vnclip_vi_16_rod

TEST_FUNC(test_vnclip_vi_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vnclip.vi       v4, v8, 0x1f
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnclip_vi_32_rnu, .-test_vnclip_vi_32_rnu

TEST_FUNC(test_vnclip_vi_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclip.vi       v6, v8, 0x1f, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vnclip_vi_32_rne, .-test_vnclip_vi_32_rne

TEST_FUNC(test_vnclip_vi_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclip.vi       v6, v8, 0x1f, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vnclip_vi_32_rdn, .-test_vnclip_vi_32_rdn

TEST_FUNC(test_vnclip_vi_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vnclip.vi       v4, v8, 0x1f
        vsw.v           v4, (a1)
        ret
        .size   test_vnclip_vi_32_rod, .-test_vnclip_vi_32_rod

/* vnclipu.vi */
TEST_FUNC(test_vnclipu_vi_8_rnu)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a3)
        vsetvli         t1, x0, e16, m4
        vlh.v           v0, (a1)
        vsetvli         t1, a0, e8, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vi      v4, v0, 0x5
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a2)
        ret
        .size   test_vnclipu_vi_8_rnu, .-test_vnclipu_vi_8_rnu

TEST_FUNC(test_vnclipu_vi_8_rne)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vi      v6, v8, 0x5, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_8_rne, .-test_vnclipu_vi_8_rne

TEST_FUNC(test_vnclipu_vi_8_rdn)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a2)
        vsetvli         t1, x0, e16, m4
        vlh.v           v8, (a0)
        vsetvli         t1, x0, e8, m2
        vlb.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vi      v6, v8, 0x9, v0.t
        vsb.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_8_rdn, .-test_vnclipu_vi_8_rdn

TEST_FUNC(test_vnclipu_vi_8_rod)
        vsetvli         t1, x0, e16, m4
        vlh.v           v4, (a0)
        vsetvli         t1, x0, e8, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vi      v0, v4, 0x9
        vsb.v           v0, (a1)
        ret
        .size   test_vnclipu_vi_8_rod, .-test_vnclipu_vi_8_rod

TEST_FUNC(test_vnclipu_vi_16_rnu)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a3)
        vsetvli         t1, a0, e32, m4
        vlw.v           v8, (a1)
        vsetvli         t1, a0, e16, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vi      v4, v8, 0xc
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a2)
        ret
        .size   test_vnclipu_vi_16_rnu, .-test_vnclipu_vi_16_rnu

TEST_FUNC(test_vnclipu_vi_16_rne)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vi      v6, v8, 0xc, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_16_rne, .-test_vnclipu_vi_16_rne

TEST_FUNC(test_vnclipu_vi_16_rdn)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a2)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vi      v6, v8, 0xe, v0.t
        vsh.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_16_rdn, .-test_vnclipu_vi_16_rdn

TEST_FUNC(test_vnclipu_vi_16_rod)
        vsetvli         t1, x0, e32, m4
        vlw.v           v8, (a0)
        vsetvli         t1, x0, e16, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vi      v4, v8, 0xe
        vsh.v           v4, (a1)
        ret
        .size   test_vnclipu_vi_16_rod, .-test_vnclipu_vi_16_rod

TEST_FUNC(test_vnclipu_vi_32_rnu)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a3)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a1)
        vsetvli         t1, a0, e32, m2
        csrrwi          t2, vxrm, 0x0
        vnclipu.vi      v4, v8, 0x1f
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a2)
        ret
        .size   test_vnclipu_vi_32_rnu, .-test_vnclipu_vi_32_rnu

TEST_FUNC(test_vnclipu_vi_32_rne)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        csrrwi          t2, vxrm, 0x1
        vnclipu.vi      v6, v8, 0x1f, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_32_rne, .-test_vnclipu_vi_32_rne

TEST_FUNC(test_vnclipu_vi_32_rdn)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a2)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v6, (a3)
        csrrwi          t2, vxrm, 0x2
        vnclipu.vi      v6, v8, 0x1f, v0.t
        vsw.v           v6, (a1)
        ret
        .size   test_vnclipu_vi_32_rdn, .-test_vnclipu_vi_32_rdn

TEST_FUNC(test_vnclipu_vi_32_rod)
        vsetvli         t1, a0, e64, m4
        vle.v           v8, (a0)
        vsetvli         t1, x0, e32, m2
        csrrwi          t2, vxrm, 0x3
        vnclipu.vi      v4, v8, 0x1f
        vsw.v           v4, (a1)
        ret
        .size   test_vnclipu_vi_32_rod, .-test_vnclipu_vi_32_rod

/* vredsum.vs */
TEST_FUNC(test_vredsum_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredsum.vs      v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredsum_vs_8, .-test_vredsum_vs_8

TEST_FUNC(test_vredsum_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredsum.vs      v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredsum_vs_8_vm, .-test_vredsum_vs_8_vm

TEST_FUNC(test_vredsum_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredsum.vs      v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredsum_vs_16, .-test_vredsum_vs_16

TEST_FUNC(test_vredsum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredsum.vs      v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredsum_vs_16_vm, .-test_vredsum_vs_16_vm

TEST_FUNC(test_vredsum_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredsum.vs      v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredsum_vs_32, .-test_vredsum_vs_32

TEST_FUNC(test_vredsum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredsum.vs      v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredsum_vs_32_vm, .-test_vredsum_vs_32_vm

TEST_FUNC(test_vredsum_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredsum.vs      v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredsum_vs_64, .-test_vredsum_vs_64

TEST_FUNC(test_vredsum_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredsum.vs      v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredsum_vs_64_vm, .-test_vredsum_vs_64_vm

/* vredmax.vs */
TEST_FUNC(test_vredmax_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredmax.vs      v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredmax_vs_8, .-test_vredmax_vs_8

TEST_FUNC(test_vredmax_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredmax.vs      v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredmax_vs_8_vm, .-test_vredmax_vs_8_vm

TEST_FUNC(test_vredmax_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredmax.vs      v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredmax_vs_16, .-test_vredmax_vs_16

TEST_FUNC(test_vredmax_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredmax.vs      v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredmax_vs_16_vm, .-test_vredmax_vs_16_vm

TEST_FUNC(test_vredmax_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredmax.vs      v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredmax_vs_32, .-test_vredmax_vs_32

TEST_FUNC(test_vredmax_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredmax.vs      v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredmax_vs_32_vm, .-test_vredmax_vs_32_vm

TEST_FUNC(test_vredmax_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredmax.vs      v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredmax_vs_64, .-test_vredmax_vs_64

TEST_FUNC(test_vredmax_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredmax.vs      v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredmax_vs_64_vm, .-test_vredmax_vs_64_vm

/* vredmaxu.vs */
TEST_FUNC(test_vredmaxu_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredmaxu.vs     v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredmaxu_vs_8, .-test_vredmaxu_vs_8

TEST_FUNC(test_vredmaxu_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredmaxu.vs     v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredmaxu_vs_8_vm, .-test_vredmaxu_vs_8_vm

TEST_FUNC(test_vredmaxu_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredmaxu.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredmaxu_vs_16, .-test_vredmaxu_vs_16

TEST_FUNC(test_vredmaxu_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredmaxu.vs     v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredmaxu_vs_16_vm, .-test_vredmaxu_vs_16_vm

TEST_FUNC(test_vredmaxu_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredmaxu.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredmaxu_vs_32, .-test_vredmaxu_vs_32

TEST_FUNC(test_vredmaxu_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredmaxu.vs     v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredmaxu_vs_32_vm, .-test_vredmaxu_vs_32_vm

TEST_FUNC(test_vredmaxu_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredmaxu.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredmaxu_vs_64, .-test_vredmaxu_vs_64

TEST_FUNC(test_vredmaxu_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredmaxu.vs     v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredmaxu_vs_64_vm, .-test_vredmaxu_vs_64_vm

/* vredmin.vs */
TEST_FUNC(test_vredmin_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredmin.vs      v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredmin_vs_8, .-test_vredmin_vs_8

TEST_FUNC(test_vredmin_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredmin.vs      v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredmin_vs_8_vm, .-test_vredmin_vs_8_vm

TEST_FUNC(test_vredmin_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredmin.vs      v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredmin_vs_16, .-test_vredmin_vs_16

TEST_FUNC(test_vredmin_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredmin.vs      v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredmin_vs_16_vm, .-test_vredmin_vs_16_vm

TEST_FUNC(test_vredmin_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredmin.vs      v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredmin_vs_32, .-test_vredmin_vs_32

TEST_FUNC(test_vredmin_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredmin.vs      v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredmin_vs_32_vm, .-test_vredmin_vs_32_vm

TEST_FUNC(test_vredmin_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredmin.vs      v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredmin_vs_64, .-test_vredmin_vs_64

TEST_FUNC(test_vredmin_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredmin.vs      v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredmin_vs_64_vm, .-test_vredmin_vs_64_vm

/* vredminu.vs */
TEST_FUNC(test_vredminu_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredminu.vs     v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredminu_vs_8, .-test_vredminu_vs_8

TEST_FUNC(test_vredminu_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredminu.vs     v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredminu_vs_8_vm, .-test_vredminu_vs_8_vm

TEST_FUNC(test_vredminu_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredminu.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredminu_vs_16, .-test_vredminu_vs_16

TEST_FUNC(test_vredminu_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredminu.vs     v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredminu_vs_16_vm, .-test_vredminu_vs_16_vm

TEST_FUNC(test_vredminu_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredminu.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredminu_vs_32, .-test_vredminu_vs_32

TEST_FUNC(test_vredminu_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredminu.vs     v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredminu_vs_32_vm, .-test_vredminu_vs_32_vm

TEST_FUNC(test_vredminu_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredminu.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredminu_vs_64, .-test_vredminu_vs_64

TEST_FUNC(test_vredminu_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredminu.vs     v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredminu_vs_64_vm, .-test_vredminu_vs_64_vm

/* vredand.vs */
TEST_FUNC(test_vredand_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredand.vs      v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredand_vs_8, .-test_vredand_vs_8

TEST_FUNC(test_vredand_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredand.vs      v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredand_vs_8_vm, .-test_vredand_vs_8_vm

TEST_FUNC(test_vredand_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredand.vs      v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredand_vs_16, .-test_vredand_vs_16

TEST_FUNC(test_vredand_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredand.vs      v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredand_vs_16_vm, .-test_vredand_vs_16_vm

TEST_FUNC(test_vredand_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredand.vs      v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredand_vs_32, .-test_vredand_vs_32

TEST_FUNC(test_vredand_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredand.vs      v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredand_vs_32_vm, .-test_vredand_vs_32_vm

TEST_FUNC(test_vredand_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredand.vs      v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredand_vs_64, .-test_vredand_vs_64

TEST_FUNC(test_vredand_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredand.vs      v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredand_vs_64_vm, .-test_vredand_vs_64_vm

/* vredor.vs */
TEST_FUNC(test_vredor_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredor.vs       v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredor_vs_8, .-test_vredor_vs_8

TEST_FUNC(test_vredor_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredor.vs       v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredor_vs_8_vm, .-test_vredor_vs_8_vm

TEST_FUNC(test_vredor_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredor.vs       v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredor_vs_16, .-test_vredor_vs_16

TEST_FUNC(test_vredor_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredor.vs       v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredor_vs_16_vm, .-test_vredor_vs_16_vm

TEST_FUNC(test_vredor_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredor.vs       v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredor_vs_32, .-test_vredor_vs_32

TEST_FUNC(test_vredor_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredor.vs       v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredor_vs_32_vm, .-test_vredor_vs_32_vm

TEST_FUNC(test_vredor_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredor.vs       v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredor_vs_64, .-test_vredor_vs_64

TEST_FUNC(test_vredor_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredor.vs       v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredor_vs_64_vm, .-test_vredor_vs_64_vm

/* vredxor.vs */
TEST_FUNC(test_vredxor_vs_8)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v4, (a4)
        vlbu.v          v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v2, (a2)
        vsetvli         t1, a0, e8, m2
        vredxor.vs      v4, v2, v0
        vsetvli         t1, x0, e8, m2
        vsb.v           v4, (a3)
        ret
        .size   test_vredxor_vs_8, .-test_vredxor_vs_8

TEST_FUNC(test_vredxor_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlbu.v          v0, (a3)
        vlbu.v          v2, (a0)
        vlbu.v          v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlbu.v          v4, (a1)
        vredxor.vs      v6, v4, v2, v0.t
        vsb.v           v6, (a2)
        ret
        .size   test_vredxor_vs_8_vm, .-test_vredxor_vs_8_vm

TEST_FUNC(test_vredxor_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vredxor.vs      v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vredxor_vs_16, .-test_vredxor_vs_16

TEST_FUNC(test_vredxor_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vredxor.vs      v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vredxor_vs_16_vm, .-test_vredxor_vs_16_vm

TEST_FUNC(test_vredxor_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vredxor.vs      v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vredxor_vs_32, .-test_vredxor_vs_32

TEST_FUNC(test_vredxor_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vredxor.vs      v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vredxor_vs_32_vm, .-test_vredxor_vs_32_vm

TEST_FUNC(test_vredxor_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vredxor.vs      v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vredxor_vs_64, .-test_vredxor_vs_64

TEST_FUNC(test_vredxor_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vredxor.vs      v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vredxor_vs_64_vm, .-test_vredxor_vs_64_vm

/* vwredsum.vs */
TEST_FUNC(test_vwredsum_vs_8)
        vsetvli         t1, x0, e16, m1
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a2)
        vsetvli         t1, a0, e8, m2
        vwredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m1
        vsh.v           v4, (a3)
        ret
        .size   test_vwredsum_vs_8, .-test_vwredsum_vs_8

TEST_FUNC(test_vwredsum_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m1
        vlh.v           v2, (a0)
        vlh.v           v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a1)
        vwredsum.vs     v6, v4, v2, v0.t
        vsetvli         t1, x0, e16, m1
        vsh.v           v6, (a2)
        ret
        .size   test_vwredsum_vs_8_vm, .-test_vwredsum_vs_8_vm

TEST_FUNC(test_vwredsum_vs_16)
        vsetvli         t1, x0, e32, m1
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vwredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v4, (a3)
        ret
        .size   test_vwredsum_vs_16, .-test_vwredsum_vs_16

TEST_FUNC(test_vwredsum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m1
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a1)
        vwredsum.vs     v6, v4, v2, v0.t
        vsetvli         t1, x0, e32, m1
        vsw.v           v6, (a2)
        ret
        .size   test_vwredsum_vs_16_vm, .-test_vwredsum_vs_16_vm

TEST_FUNC(test_vwredsum_vs_32)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vwredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m1
        vse.v           v4, (a3)
        ret
        .size   test_vwredsum_vs_32, .-test_vwredsum_vs_32

TEST_FUNC(test_vwredsum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m1
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a1)
        vwredsum.vs     v6, v4, v2, v0.t
        vsetvli         t1, x0, e64, m1
        vse.v           v6, (a2)
        ret
        .size   test_vwredsum_vs_32_vm, .-test_vwredsum_vs_32_vm

/* vwredsumu.vs */
TEST_FUNC(test_vwredsumu_vs_8)
        vsetvli         t1, x0, e16, m1
        vlh.v           v4, (a4)
        vlh.v           v0, (a1)
        vsetvli         t1, x0, e8, m2
        vlb.v           v2, (a2)
        vsetvli         t1, a0, e8, m2
        vwredsumu.vs    v4, v2, v0
        vsetvli         t1, x0, e16, m1
        vsh.v           v4, (a3)
        ret
        .size   test_vwredsumu_vs_8, .-test_vwredsumu_vs_8

TEST_FUNC(test_vwredsumu_vs_8_vm)
        vsetvli         t1, x0, e8, m1
        vlb.v           v0, (a3)
        vsetvli         t1, x0, e16, m1
        vlh.v           v2, (a0)
        vlh.v           v6, (a4)
        vsetvli         t1, x0, e8, m2
        vlb.v           v4, (a1)
        vwredsumu.vs    v6, v4, v2, v0.t
        vsetvli         t1, x0, e16, m1
        vsh.v           v6, (a2)
        ret
        .size   test_vwredsumu_vs_8_vm, .-test_vwredsumu_vs_8_vm

TEST_FUNC(test_vwredsumu_vs_16)
        vsetvli         t1, x0, e32, m1
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vwredsumu.vs    v4, v2, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v4, (a3)
        ret
        .size   test_vwredsumu_vs_16, .-test_vwredsumu_vs_16

TEST_FUNC(test_vwredsumu_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m1
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a1)
        vwredsumu.vs    v6, v4, v2, v0.t
        vsetvli         t1, x0, e32, m1
        vsw.v           v6, (a2)
        ret
        .size   test_vwredsumu_vs_16_vm, .-test_vwredsumu_vs_16_vm

TEST_FUNC(test_vwredsumu_vs_32)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vwredsumu.vs    v4, v2, v0
        vsetvli         t1, x0, e64, m1
        vse.v           v4, (a3)
        ret
        .size   test_vwredsumu_vs_32, .-test_vwredsumu_vs_32

TEST_FUNC(test_vwredsumu_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m1
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a1)
        vwredsumu.vs    v6, v4, v2, v0.t
        vsetvli         t1, x0, e64, m1
        vse.v           v6, (a2)
        ret
        .size   test_vwredsumu_vs_32_vm, .-test_vwredsumu_vs_32_vm

/* vfredsum.vs */
TEST_FUNC(test_vfredsum_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vfredsum_vs_16, .-test_vfredsum_vs_16

TEST_FUNC(test_vfredsum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vfredsum.vs     v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vfredsum_vs_16_vm, .-test_vfredsum_vs_16_vm

TEST_FUNC(test_vfredsum_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vfredsum_vs_32, .-test_vfredsum_vs_32

TEST_FUNC(test_vfredsum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vfredsum.vs     v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vfredsum_vs_32_vm, .-test_vfredsum_vs_32_vm

TEST_FUNC(test_vfredsum_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfredsum.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vfredsum_vs_64, .-test_vfredsum_vs_64

TEST_FUNC(test_vfredsum_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vfredsum.vs     v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vfredsum_vs_64_vm, .-test_vfredsum_vs_64_vm

/* vfredmax.vs */
TEST_FUNC(test_vfredmax_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfredmax.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vfredmax_vs_16, .-test_vfredmax_vs_16

TEST_FUNC(test_vfredmax_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vfredmax.vs     v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vfredmax_vs_16_vm, .-test_vfredmax_vs_16_vm

TEST_FUNC(test_vfredmax_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfredmax.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vfredmax_vs_32, .-test_vfredmax_vs_32

TEST_FUNC(test_vfredmax_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vfredmax.vs     v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vfredmax_vs_32_vm, .-test_vfredmax_vs_32_vm

TEST_FUNC(test_vfredmax_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfredmax.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vfredmax_vs_64, .-test_vfredmax_vs_64

TEST_FUNC(test_vfredmax_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vfredmax.vs     v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vfredmax_vs_64_vm, .-test_vfredmax_vs_64_vm

/* vfredmin.vs */
TEST_FUNC(test_vfredmin_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfredmin.vs     v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vfredmin_vs_16, .-test_vfredmin_vs_16

TEST_FUNC(test_vfredmin_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vfredmin.vs     v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vfredmin_vs_16_vm, .-test_vfredmin_vs_16_vm

TEST_FUNC(test_vfredmin_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfredmin.vs     v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vfredmin_vs_32, .-test_vfredmin_vs_32

TEST_FUNC(test_vfredmin_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vfredmin.vs     v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vfredmin_vs_32_vm, .-test_vfredmin_vs_32_vm

TEST_FUNC(test_vfredmin_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfredmin.vs     v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vfredmin_vs_64, .-test_vfredmin_vs_64

TEST_FUNC(test_vfredmin_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vfredmin.vs     v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vfredmin_vs_64_vm, .-test_vfredmin_vs_64_vm

/* vfwredsum.vs */
TEST_FUNC(test_vfwredsum_vs_16)
        vsetvli         t1, x0, e32, m1
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwredsum.vs    v4, v2, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v4, (a3)
        ret
        .size   test_vfwredsum_vs_16, .-test_vfwredsum_vs_16

TEST_FUNC(test_vfwredsum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m1
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a1)
        vfwredsum.vs    v6, v4, v2, v0.t
        vsetvli         t1, x0, e32, m1
        vsw.v           v6, (a2)
        ret
        .size   test_vfwredsum_vs_16_vm, .-test_vfwredsum_vs_16_vm

TEST_FUNC(test_vfwredsum_vs_32)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwredsum.vs    v4, v2, v0
        vsetvli         t1, x0, e64, m1
        vse.v           v4, (a3)
        ret
        .size   test_vfwredsum_vs_32, .-test_vfwredsum_vs_32

TEST_FUNC(test_vfwredsum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m1
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a1)
        vfwredsum.vs    v6, v4, v2, v0.t
        vsetvli         t1, x0, e64, m1
        vse.v           v6, (a2)
        ret
        .size   test_vfwredsum_vs_32_vm, .-test_vfwredsum_vs_32_vm

/* vfredosum.vs */
TEST_FUNC(test_vfredosum_vs_16)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v4, (a4)
        vlhu.v          v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfredosum.vs    v4, v2, v0
        vsetvli         t1, x0, e16, m2
        vsh.v           v4, (a3)
        ret
        .size   test_vfredosum_vs_16, .-test_vfredosum_vs_16

TEST_FUNC(test_vfredosum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlhu.v          v0, (a3)
        vlhu.v          v6, (a4)
        vlhu.v          v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlhu.v          v4, (a1), v0.t
        vfredosum.vs    v6, v4, v2, v0.t
        vsh.v           v6, (a2)
        ret
        .size   test_vfredosum_vs_16_vm, .-test_vfredosum_vs_16_vm

TEST_FUNC(test_vfredosum_vs_32)
        vsetvli         t1, x0, e32, m1
        vlwu.v          v4, (a4)
        vlwu.v          v0, (a1)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfredosum.vs    v4, v2, v0
        vsetvli         t1, x0, e32, m2
        vsw.v           v4, (a3)
        ret
        .size   test_vfredosum_vs_32, .-test_vfredosum_vs_32

TEST_FUNC(test_vfredosum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vlwu.v          v6, (a4)
        vlwu.v          v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlwu.v          v4, (a1)
        vfredosum.vs    v6, v4, v2, v0.t
        vsw.v           v6, (a2)
        ret
        .size   test_vfredosum_vs_32_vm, .-test_vfredosum_vs_32_vm

TEST_FUNC(test_vfredosum_vs_64)
        vsetvli         t1, x0, e64, m1
        vle.v           v4, (a4)
        vle.v           v0, (a1)
        vsetvli         t1, x0, e64, m2
        vle.v           v2, (a2)
        vsetvli         t1, a0, e64, m2
        vfredosum.vs    v4, v2, v0
        vsetvli         t1, x0, e64, m2
        vse.v           v4, (a3)
        ret
        .size   test_vfredosum_vs_64, .-test_vfredosum_vs_64

TEST_FUNC(test_vfredosum_vs_64_vm)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a3)
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e64, m2
        vle.v           v4, (a1)
        vfredosum.vs    v6, v4, v2, v0.t
        vse.v           v6, (a2)
        ret
        .size   test_vfredosum_vs_64_vm, .-test_vfredosum_vs_64_vm

/* vfwredosum.vs */
TEST_FUNC(test_vfwredosum_vs_16)
        vsetvli         t1, x0, e32, m1
        vlw.v           v4, (a4)
        vlw.v           v0, (a1)
        vsetvli         t1, x0, e16, m2
        vlh.v           v2, (a2)
        vsetvli         t1, a0, e16, m2
        vfwredosum.vs   v4, v2, v0
        vsetvli         t1, x0, e32, m1
        vsw.v           v4, (a3)
        ret
        .size   test_vfwredosum_vs_16, .-test_vfwredosum_vs_16

TEST_FUNC(test_vfwredosum_vs_16_vm)
        vsetvli         t1, x0, e16, m1
        vlh.v           v0, (a3)
        vsetvli         t1, x0, e32, m1
        vlw.v           v6, (a4)
        vlw.v           v2, (a0)
        vsetvli         t1, x0, e16, m2
        vlh.v           v4, (a1)
        vfwredosum.vs   v6, v4, v2, v0.t
        vsetvli         t1, x0, e32, m1
        vsw.v           v6, (a2)
        ret
        .size   test_vfwredosum_vs_16_vm, .-test_vfwredosum_vs_16_vm

TEST_FUNC(test_vfwredosum_vs_32)
        vsetvli         t1, x0, e64, m1
        vle.v           v0, (a1)
        vle.v           v4, (a4)
        vsetvli         t1, x0, e32, m2
        vlw.v           v2, (a2)
        vsetvli         t1, a0, e32, m2
        vfwredosum.vs   v4, v2, v0
        vsetvli         t1, x0, e64, m1
        vse.v           v4, (a3)
        ret
        .size   test_vfwredosum_vs_32, .-test_vfwredosum_vs_32

TEST_FUNC(test_vfwredosum_vs_32_vm)
        vsetvli         t1, x0, e32, m1
        vlw.v           v0, (a3)
        vsetvli         t1, x0, e64, m1
        vle.v           v6, (a4)
        vle.v           v2, (a0)
        vsetvli         t1, x0, e32, m2
        vlw.v           v4, (a1)
        vfwredosum.vs   v6, v4, v2, v0.t
        vsetvli         t1, x0, e64, m1
        vse.v           v6, (a2)
        ret
        .size   test_vfwredosum_vs_32_vm, .-test_vfwredosum_vs_32_vm

