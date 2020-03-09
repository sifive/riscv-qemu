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
 * Lesser General Public License  *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "testsuite.h"
#include "rvv_insn.h"

struct rvv_reg src0[] = {
    {
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .fixs32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .fixs16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .fixs8 = {
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs16 = {
            {0xffc6, 0xffea, 0xff19, 0x00ae, 0xffaf, 0x007e, 0xff22, 0x008f, },
            {0x008c, 0x002c, 0xffe8, 0xff17, 0x0025, 0xff79, 0x0072, 0xffdc, },
            {0xffc6, 0xffea, 0xff19, 0x00ae, 0xffaf, 0x007e, 0xff22, 0x008f, },
            {0x008c, 0x002c, 0xffe8, 0xff17, 0x0025, 0xff79, 0x0072, 0x0000, },
        },
        .fixs32 = {
            {0x0000268e, 0x00008ba5, 0x00007833, 0x00000939, },
            {0xffff71ca, 0xffffe6bc, 0x00007779, 0xffff7119, },
            {0x0000268e, 0x00008ba5, 0x00007833, 0x00000939, },
            {0xffff71ca, 0xffffe6bc, 0x00007779, 0x00000000, },
        },
        .fixs64 = {
            {0x0000000047753bc7, 0xffffffff7422a276, },
            {0x000000007de005a0, 0xffffffffe998b2d6, },
            {0x0000000047753bc7, 0xffffffff7422a276, },
            {0x000000007de005a0, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xffc6, 0x1111, 0xff19, 0x1111, 0xffaf, 0x1111, 0xff22, 0x1111, },
            {0x008c, 0x1111, 0xffe8, 0x1111, 0x0025, 0x1111, 0x0072, 0x1111, },
            {0xffc6, 0x1111, 0xff19, 0x1111, 0xffaf, 0x1111, 0xff22, 0x1111, },
            {0x008c, 0x1111, 0xffe8, 0x1111, 0x0025, 0x1111, 0x0072, 0x1111, },
        },
        .fixs32 = {
            {0x0000268e, 0x11111111, 0x00007833, 0x11111111, },
            {0xffff71ca, 0x11111111, 0x00007779, 0x11111111, },
            {0x0000268e, 0x11111111, 0x00007833, 0x11111111, },
            {0xffff71ca, 0x11111111, 0x00007779, 0x11111111, },
        },
        .fixs64 = {
            {0x0000000047753bc7, 0x1111111111111111, },
            {0x000000007de005a0, 0x1111111111111111, },
            {0x0000000047753bc7, 0x1111111111111111, },
            {0x000000007de005a0, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0xffea, 0x1111, 0x00ae, 0x1111, 0x007e, 0x1111, 0x008f, },
            {0x1111, 0x002c, 0x1111, 0xff17, 0x1111, 0xff79, 0x1111, 0xffdc, },
            {0x1111, 0xffea, 0x1111, 0x00ae, 0x1111, 0x007e, 0x1111, 0x008f, },
            {0x1111, 0x002c, 0x1111, 0xff17, 0x1111, 0xff79, 0x1111, 0xffdc, },
        },
        .fixs32 = {
            {0x11111111, 0x00008ba5, 0x11111111, 0x00000939, },
            {0x11111111, 0xffffe6bc, 0x11111111, 0xffff7119, },
            {0x11111111, 0x00008ba5, 0x11111111, 0x00000939, },
            {0x11111111, 0xffffe6bc, 0x11111111, 0xffff7119, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffffffff7422a276, },
            {0x1111111111111111, 0xffffffffe998b2d6, },
            {0x1111111111111111, 0xffffffff7422a276, },
            {0x1111111111111111, 0xffffffffe998b2d6, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwadd.vv\n");

    /* uint8_t add */
    test_vwadd_vv_8(vlmax_8 - 1, src0[i].fixs8[0], src1[i].fixs8[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwadd_vv_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwadd_vv_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* uint16_t add */
    test_vwadd_vv_16(vlmax_16 - 1, src0[i].fixs16[0], src1[i].fixs16[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwadd_vv_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwadd_vv_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* uint32_t add */
    test_vwadd_vv_32(vlmax_32 - 1, src0[i].fixs32[0], src1[i].fixs32[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwadd_vv_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwadd_vv_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
