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
        .fixs64 = {
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
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
            {0xd6b5, 0x523c, 0x1162, 0x0e67, 0xa367, 0x4d36, 0x47cd, 0xa14f, },
            {0xd6aa, 0x51df, 0x1143, 0x0f1b, 0xa321, 0x4d71, 0x470e, 0xa1a9, },
            {0xd6b5, 0x523c, 0x1162, 0x0e67, 0xa367, 0x4d36, 0x47cd, 0xa14f, },
            {0xd6aa, 0x51df, 0x1143, 0x0f1b, 0xa321, 0x4d71, 0x470e, 0x0000, },
        },
        .fixs32 = {
            {0xcfe016ce, 0x8262bcae, 0x15fbeadd, 0xd6b979c2, },
            {0xcfe09805, 0x82635ce4, 0x15fc2205, 0xd6b9a4a5, },
            {0xcfe016ce, 0x8262bcae, 0x15fbeadd, 0xd6b979c2, },
            {0xcfe09805, 0x82635ce4, 0x15fc2205, 0x00000000, },
        },
        .fixs64 = {
            {0x3970b598c31d1cd1, 0xc6a630b356278b66, },
            {0x3970b598d2ce3e93, 0xc6a630b33507f8ff, },
            {0x3970b598c31d1cd1, 0xc6a630b356278b66, },
            {0x3970b598d2ce3e93, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xd6b5, 0x1111, 0x1162, 0x1111, 0xa367, 0x1111, 0x47cd, 0x1111, },
            {0xd6aa, 0x1111, 0x1143, 0x1111, 0xa321, 0x1111, 0x470e, 0x1111, },
            {0xd6b5, 0x1111, 0x1162, 0x1111, 0xa367, 0x1111, 0x47cd, 0x1111, },
            {0xd6aa, 0x1111, 0x1143, 0x1111, 0xa321, 0x1111, 0x470e, 0x1111, },
        },
        .fixs32 = {
            {0xcfe016ce, 0x11111111, 0x15fbeadd, 0x11111111, },
            {0xcfe09805, 0x11111111, 0x15fc2205, 0x11111111, },
            {0xcfe016ce, 0x11111111, 0x15fbeadd, 0x11111111, },
            {0xcfe09805, 0x11111111, 0x15fc2205, 0x11111111, },
        },
        .fixs64 = {
            {0x3970b598c31d1cd1, 0x1111111111111111, },
            {0x3970b598d2ce3e93, 0x1111111111111111, },
            {0x3970b598c31d1cd1, 0x1111111111111111, },
            {0x3970b598d2ce3e93, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0x523c, 0x1111, 0x0e67, 0x1111, 0x4d36, 0x1111, 0xa14f, },
            {0x1111, 0x51df, 0x1111, 0x0f1b, 0x1111, 0x4d71, 0x1111, 0xa1a9, },
            {0x1111, 0x523c, 0x1111, 0x0e67, 0x1111, 0x4d36, 0x1111, 0xa14f, },
            {0x1111, 0x51df, 0x1111, 0x0f1b, 0x1111, 0x4d71, 0x1111, 0xa1a9, },
        },
        .fixs32 = {
            {0x11111111, 0x8262bcae, 0x11111111, 0xd6b979c2, },
            {0x11111111, 0x82635ce4, 0x11111111, 0xd6b9a4a5, },
            {0x11111111, 0x8262bcae, 0x11111111, 0xd6b979c2, },
            {0x11111111, 0x82635ce4, 0x11111111, 0xd6b9a4a5, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xc6a630b356278b66, },
            {0x1111111111111111, 0xc6a630b33507f8ff, },
            {0x1111111111111111, 0xc6a630b356278b66, },
            {0x1111111111111111, 0xc6a630b33507f8ff, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsub.wv\n");

    /* int8_t sub */
    test_vwsub_wv_8(vlmax_8 - 1, src0[i].fixs16[0], src1[i].fixs8[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwsub_wv_8_vm(src0[i].fixs16[0], src1[i].fixs8[0], res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwsub_wv_8_vm(src0[i].fixs16[0], src1[i].fixs8[0], res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int16_t sub */
    test_vwsub_wv_16(vlmax_16 - 1, src0[i].fixs32[0], src1[i].fixs16[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwsub_wv_16_vm(src0[i].fixs32[0], src1[i].fixs16[0], res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwsub_wv_16_vm(src0[i].fixs32[0], src1[i].fixs16[0], res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int32_t sub */
    test_vwsub_wv_32(vlmax_32 - 1, src0[i].fixs64[0], src1[i].fixs32[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwsub_wv_32_vm(src0[i].fixs64[0], src1[i].fixs32[0], res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwsub_wv_32_vm(src0[i].fixs64[0], src1[i].fixs32[0], res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
