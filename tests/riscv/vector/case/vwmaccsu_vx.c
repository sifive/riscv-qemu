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
        },
        .fixu32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixu16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};


int64_t src1 = 0x1122334455667788;
struct rvv_reg dst_vl[] = {
    {
        .fixs16 = {
            {0xc3b9, 0xf8b1, 0xcf71, 0xdab1, 0xb0f9, 0xda39, 0xcca1, 0xd7e1, },
            {0xe411, 0x0559, 0xf4f1, 0xcd19, 0x9a79, 0xc0e9, 0x00a9, 0x0199, },
            {0xc3b9, 0xf8b1, 0xcf71, 0xdab1, 0xb0f9, 0xda39, 0xcca1, 0xd7e1, },
            {0xe411, 0x0559, 0xf4f1, 0xcd19, 0x9a79, 0xc0e9, 0x00a9, 0x0000, },
        },
        .fixs32 = {
            {0x7560acc1, 0x375417a1, 0x18f92909, 0x17e5ad99, },
            {0x5d4ebed9, 0x35226389, 0x32633579, 0x5c6c4a31, },
            {0x7560acc1, 0x375417a1, 0x18f92909, 0x17e5ad99, },
            {0x5d4ebed9, 0x35226389, 0x32633579, 0x00000000, },
        },
        .fixs64 = {
            {0x5669c7942753d241, 0x3c901d2eb5d10b99, },
            {0x1866a522b7700999, 0x58b296d99688b6e1, },
            {0x5669c7942753d241, 0x3c901d2eb5d10b99, },
            {0x1866a522b7700999, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xc3b9, 0x1111, 0xcf71, 0x1111, 0xb0f9, 0x1111, 0xcca1, 0x1111, },
            {0xe411, 0x1111, 0xf4f1, 0x1111, 0x9a79, 0x1111, 0x00a9, 0x1111, },
            {0xc3b9, 0x1111, 0xcf71, 0x1111, 0xb0f9, 0x1111, 0xcca1, 0x1111, },
            {0xe411, 0x1111, 0xf4f1, 0x1111, 0x9a79, 0x1111, 0x00a9, 0x1111, },
        },
        .fixs32 = {
            {0x7560acc1, 0x11111111, 0x18f92909, 0x11111111, },
            {0x5d4ebed9, 0x11111111, 0x32633579, 0x11111111, },
            {0x7560acc1, 0x11111111, 0x18f92909, 0x11111111, },
            {0x5d4ebed9, 0x11111111, 0x32633579, 0x11111111, },
        },
        .fixs64 = {
            {0x5669c7942753d241, 0x1111111111111111, },
            {0x1866a522b7700999, 0x1111111111111111, },
            {0x5669c7942753d241, 0x1111111111111111, },
            {0x1866a522b7700999, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0xf8b1, 0x1111, 0xdab1, 0x1111, 0xda39, 0x1111, 0xd7e1, },
            {0x1111, 0x0559, 0x1111, 0xcd19, 0x1111, 0xc0e9, 0x1111, 0x0199, },
            {0x1111, 0xf8b1, 0x1111, 0xdab1, 0x1111, 0xda39, 0x1111, 0xd7e1, },
            {0x1111, 0x0559, 0x1111, 0xcd19, 0x1111, 0xc0e9, 0x1111, 0x0199, },
        },
        .fixs32 = {
            {0x11111111, 0x375417a1, 0x11111111, 0x17e5ad99, },
            {0x11111111, 0x35226389, 0x11111111, 0x5c6c4a31, },
            {0x11111111, 0x375417a1, 0x11111111, 0x17e5ad99, },
            {0x11111111, 0x35226389, 0x11111111, 0x5c6c4a31, },
        },
        .fixs64 = {
            {0x1111111111111111, 0x3c901d2eb5d10b99, },
            {0x1111111111111111, 0x58b296d99688b6e1, },
            {0x1111111111111111, 0x3c901d2eb5d10b99, },
            {0x1111111111111111, 0x58b296d99688b6e1, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwmaccsu.vx\n");

    /* int8_t vwmaccsu */
    test_vwmaccsu_vx_8(vlmax_8 - 1, src0[i].fixu8[0], src1, res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwmaccsu_vx_8_vm(src0[i].fixu8[0], src1, res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwmaccsu_vx_8_vm(src0[i].fixu8[0], src1, res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int16_t vwmaccsu */
    test_vwmaccsu_vx_16(vlmax_16 - 1, src0[i].fixu16[0], src1, res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwmaccsu_vx_16_vm(src0[i].fixu16[0], src1, res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwmaccsu_vx_16_vm(src0[i].fixu16[0], src1, res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int32_t vwmaccsu */
    test_vwmaccsu_vx_32(vlmax_32 - 1, src0[i].fixu32[0], src1, res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwmaccsu_vx_32_vm(src0[i].fixu32[0], src1, res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwmaccsu_vx_32_vm(src0[i].fixu32[0], src1, res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
