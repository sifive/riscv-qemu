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
        .fixu64 = {
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixu16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};
struct rvv_reg src1[] = {
    {
        .fixu32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .fixu16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .fixu8 = {
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixu16 = {
            {0xd6b5, 0x513c, 0x1062, 0x0e67, 0xa267, 0x4d36, 0x46cd, 0xa14f, },
            {0xd6aa, 0x51df, 0x1043, 0x0e1b, 0xa321, 0x4c71, 0x470e, 0xa0a9, },
            {0xd6b5, 0x513c, 0x1062, 0x0e67, 0xa267, 0x4d36, 0x46cd, 0xa14f, },
            {0xd6aa, 0x51df, 0x1043, 0x0e1b, 0xa321, 0x4c71, 0x470e, 0x0000, },
        },
        .fixu32 = {
            {0xcfe016ce, 0x8262bcae, 0x15fbeadd, 0xd6b879c2, },
            {0xcfdf9805, 0x82625ce4, 0x15fc2205, 0xd6b8a4a5, },
            {0xcfe016ce, 0x8262bcae, 0x15fbeadd, 0xd6b879c2, },
            {0xcfdf9805, 0x82625ce4, 0x15fc2205, 0x00000000, },
        },
        .fixu64 = {
            {0x3970b598c31d1cd1, 0xc6a630b256278b66, },
            {0x3970b598d2ce3e93, 0xc6a630b33507f8ff, },
            {0x3970b598c31d1cd1, 0xc6a630b256278b66, },
            {0x3970b598d2ce3e93, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu16 = {
            {0xd6b5, 0x1111, 0x1062, 0x1111, 0xa267, 0x1111, 0x46cd, 0x1111, },
            {0xd6aa, 0x1111, 0x1043, 0x1111, 0xa321, 0x1111, 0x470e, 0x1111, },
            {0xd6b5, 0x1111, 0x1062, 0x1111, 0xa267, 0x1111, 0x46cd, 0x1111, },
            {0xd6aa, 0x1111, 0x1043, 0x1111, 0xa321, 0x1111, 0x470e, 0x1111, },
        },
        .fixu32 = {
            {0xcfe016ce, 0x11111111, 0x15fbeadd, 0x11111111, },
            {0xcfdf9805, 0x11111111, 0x15fc2205, 0x11111111, },
            {0xcfe016ce, 0x11111111, 0x15fbeadd, 0x11111111, },
            {0xcfdf9805, 0x11111111, 0x15fc2205, 0x11111111, },
        },
        .fixu64 = {
            {0x3970b598c31d1cd1, 0x1111111111111111, },
            {0x3970b598d2ce3e93, 0x1111111111111111, },
            {0x3970b598c31d1cd1, 0x1111111111111111, },
            {0x3970b598d2ce3e93, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu16 = {
            {0x1111, 0x513c, 0x1111, 0x0e67, 0x1111, 0x4d36, 0x1111, 0xa14f, },
            {0x1111, 0x51df, 0x1111, 0x0e1b, 0x1111, 0x4c71, 0x1111, 0xa0a9, },
            {0x1111, 0x513c, 0x1111, 0x0e67, 0x1111, 0x4d36, 0x1111, 0xa14f, },
            {0x1111, 0x51df, 0x1111, 0x0e1b, 0x1111, 0x4c71, 0x1111, 0xa0a9, },
        },
        .fixu32 = {
            {0x11111111, 0x8262bcae, 0x11111111, 0xd6b879c2, },
            {0x11111111, 0x82625ce4, 0x11111111, 0xd6b8a4a5, },
            {0x11111111, 0x8262bcae, 0x11111111, 0xd6b879c2, },
            {0x11111111, 0x82625ce4, 0x11111111, 0xd6b8a4a5, },
        },
        .fixu64 = {
            {0x1111111111111111, 0xc6a630b256278b66, },
            {0x1111111111111111, 0xc6a630b33507f8ff, },
            {0x1111111111111111, 0xc6a630b256278b66, },
            {0x1111111111111111, 0xc6a630b33507f8ff, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsubu.wv\n");

    /* uint8_t add */
    test_vwsubu_wv_8(vlmax_8 - 1, src0[i].fixu16[0], src1[i].fixu8[0], res.fixu16[0], pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_vl[i].fixu16[0]);

    test_vwsubu_wv_8_vm(src0[i].fixu16[0], src1[i].fixu8[0], res.fixu16[0], vme.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_even[i].fixu16[0]);

    test_vwsubu_wv_8_vm(src0[i].fixu16[0], src1[i].fixu8[0], res.fixu16[0], vmo.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_odd[i].fixu16[0]);

    /* uint16_t add */
    test_vwsubu_wv_16(vlmax_16 - 1, src0[i].fixu32[0], src1[i].fixu16[0], res.fixu32[0], pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_vl[i].fixu32[0]);

    test_vwsubu_wv_16_vm(src0[i].fixu32[0], src1[i].fixu16[0], res.fixu32[0], vme.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_even[i].fixu32[0]);

    test_vwsubu_wv_16_vm(src0[i].fixu32[0], src1[i].fixu16[0], res.fixu32[0], vmo.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_odd[i].fixu32[0]);

    /* uint32_t add */
    test_vwsubu_wv_32(vlmax_32 - 1, src0[i].fixu64[0], src1[i].fixu32[0], res.fixu64[0], pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_vl[i].fixu64[0]);

    test_vwsubu_wv_32_vm(src0[i].fixu64[0], src1[i].fixu32[0], res.fixu64[0], vme.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_even[i].fixu64[0]);

    test_vwsubu_wv_32_vm(src0[i].fixu64[0], src1[i].fixu32[0], res.fixu64[0], vmo.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_odd[i].fixu64[0]);

    return done_testing();
}
