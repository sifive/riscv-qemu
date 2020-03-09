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

uint64_t src1 = 0x1122334455667788;


struct rvv_reg dst_vl[] = {
    {
        .fixu16 = {
            {0x57a8, 0x1ba0, 0x4a60, 0x3da0, 0x6ce8, 0x3e28, 0x4d90, 0x40d0, },
            {0x3300, 0x0d48, 0x1fe0, 0x4d08, 0x8668, 0x5ad8, 0x1298, 0x1188, },
            {0x57a8, 0x1ba0, 0x4a60, 0x3da0, 0x6ce8, 0x3e28, 0x4d90, 0x40d0, },
            {0x3300, 0x0d48, 0x1fe0, 0x4d08, 0x8668, 0x5ad8, 0x1298, 0x0000, },
        },
        .fixu32 = {
            {0x644f9bb0, 0x26430690, 0x07e817f8, 0x06d49c88, },
            {0x4c3dadc8, 0x24115278, 0x21522468, 0x4b5b3920, },
            {0x644f9bb0, 0x26430690, 0x07e817f8, 0x06d49c88, },
            {0x4c3dadc8, 0x24115278, 0x21522468, 0x00000000, },
        },
        .fixu64 = {
            {0x4558b6831642c130, 0x2b7f0c1da4bffa88, },
            {0x07559411a65ef888, 0x47a185c88577a5d0, },
            {0x4558b6831642c130, 0x2b7f0c1da4bffa88, },
            {0x07559411a65ef888, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu16 = {
            {0x57a8, 0x1111, 0x4a60, 0x1111, 0x6ce8, 0x1111, 0x4d90, 0x1111, },
            {0x3300, 0x1111, 0x1fe0, 0x1111, 0x8668, 0x1111, 0x1298, 0x1111, },
            {0x57a8, 0x1111, 0x4a60, 0x1111, 0x6ce8, 0x1111, 0x4d90, 0x1111, },
            {0x3300, 0x1111, 0x1fe0, 0x1111, 0x8668, 0x1111, 0x1298, 0x1111, },
        },
        .fixu32 = {
            {0x644f9bb0, 0x11111111, 0x07e817f8, 0x11111111, },
            {0x4c3dadc8, 0x11111111, 0x21522468, 0x11111111, },
            {0x644f9bb0, 0x11111111, 0x07e817f8, 0x11111111, },
            {0x4c3dadc8, 0x11111111, 0x21522468, 0x11111111, },
        },
        .fixu64 = {
            {0x4558b6831642c130, 0x1111111111111111, },
            {0x07559411a65ef888, 0x1111111111111111, },
            {0x4558b6831642c130, 0x1111111111111111, },
            {0x07559411a65ef888, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu16 = {
            {0x1111, 0x1ba0, 0x1111, 0x3da0, 0x1111, 0x3e28, 0x1111, 0x40d0, },
            {0x1111, 0x0d48, 0x1111, 0x4d08, 0x1111, 0x5ad8, 0x1111, 0x1188, },
            {0x1111, 0x1ba0, 0x1111, 0x3da0, 0x1111, 0x3e28, 0x1111, 0x40d0, },
            {0x1111, 0x0d48, 0x1111, 0x4d08, 0x1111, 0x5ad8, 0x1111, 0x1188, },
        },
        .fixu32 = {
            {0x11111111, 0x26430690, 0x11111111, 0x06d49c88, },
            {0x11111111, 0x24115278, 0x11111111, 0x4b5b3920, },
            {0x11111111, 0x26430690, 0x11111111, 0x06d49c88, },
            {0x11111111, 0x24115278, 0x11111111, 0x4b5b3920, },
        },
        .fixu64 = {
            {0x1111111111111111, 0x2b7f0c1da4bffa88, },
            {0x1111111111111111, 0x47a185c88577a5d0, },
            {0x1111111111111111, 0x2b7f0c1da4bffa88, },
            {0x1111111111111111, 0x47a185c88577a5d0, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwmulu.vx\n");

    /* uint8_t vwmul */
    test_vwmulu_vx_8(vlmax_8 - 1, src0[i].fixu8[0], src1, res.fixu16[0], pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_vl[i].fixu16[0]);

    test_vwmulu_vx_8_vm(src0[i].fixu8[0], src1, res.fixu16[0], vme.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_even[i].fixu16[0]);

    test_vwmulu_vx_8_vm(src0[i].fixu8[0], src1, res.fixu16[0], vmo.fixu8, pad.fixu16[0]);
    result_compare_s16_lmulw(res.fixu16[0], dst_odd[i].fixu16[0]);

    /* uint16_t vwmul */
    test_vwmulu_vx_16(vlmax_16 - 1, src0[i].fixu16[0], src1, res.fixu32[0], pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_vl[i].fixu32[0]);

    test_vwmulu_vx_16_vm(src0[i].fixu16[0], src1, res.fixu32[0], vme.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_even[i].fixu32[0]);

    test_vwmulu_vx_16_vm(src0[i].fixu16[0], src1, res.fixu32[0], vmo.fixu16, pad.fixu32[0]);
    result_compare_s32_lmulw(res.fixu32[0], dst_odd[i].fixu32[0]);

    /* uint32_t vwmul */
    test_vwmulu_vx_32(vlmax_32 - 1, src0[i].fixu32[0], src1, res.fixu64[0], pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_vl[i].fixu64[0]);

    test_vwmulu_vx_32_vm(src0[i].fixu32[0], src1, res.fixu64[0], vme.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_even[i].fixu64[0]);

    test_vwmulu_vx_32_vm(src0[i].fixu32[0], src1, res.fixu64[0], vmo.fixu32, pad.fixu64[0]);
    result_compare_s64_lmulw(res.fixu64[0], dst_odd[i].fixu64[0]);

    return done_testing();
}
