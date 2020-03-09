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
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x00, },
        },
        .fixu16 = {
            {0xd600, 0xf200, 0xef00, 0xa100, 0x4900, 0x3f00, 0x5d00, 0x6400, },
            {0xd600, 0xf200, 0xef00, 0xa100, 0x4900, 0x3f00, 0x5d00, 0x0000, },
        },
        .fixu32 = {
            {0xe0668600, 0x62f66100, 0xfc522100, 0xb9745a00, },
            {0xe0668600, 0x62f66100, 0xfc522100, 0x00000000, },
        },
        .fixu64 = {
            {0x70b5993ab1f21200, 0xa630b347e7377b00, },
            {0x70b5993ab1f21200, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu8 = {
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
        },
        .fixu16 = {
            {0xd600, 0x1111, 0xef00, 0x1111, 0x4900, 0x1111, 0x5d00, 0x1111, },
            {0xd600, 0x1111, 0xef00, 0x1111, 0x4900, 0x1111, 0x5d00, 0x1111, },
        },
        .fixu32 = {
            {0xe0668600, 0x11111111, 0xfc522100, 0x11111111, },
            {0xe0668600, 0x11111111, 0xfc522100, 0x11111111, },
        },
        .fixu64 = {
            {0x70b5993ab1f21200, 0x1111111111111111, },
            {0x70b5993ab1f21200, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu8 = {
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
        },
        .fixu16 = {
            {0x1111, 0xf200, 0x1111, 0xa100, 0x1111, 0x3f00, 0x1111, 0x6400, },
            {0x1111, 0xf200, 0x1111, 0xa100, 0x1111, 0x3f00, 0x1111, 0x6400, },
        },
        .fixu32 = {
            {0x11111111, 0x62f66100, 0x11111111, 0xb9745a00, },
            {0x11111111, 0x62f66100, 0x11111111, 0xb9745a00, },
        },
        .fixu64 = {
            {0x1111111111111111, 0xa630b347e7377b00, },
            {0x1111111111111111, 0xa630b347e7377b00, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsll.vx\n");

    test_vsll_vx_8(vlmax_8 - 1, src0[i].fixu8[0], src1, res.fixu8[0], pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_vl[i].fixu8[0]);

    test_vsll_vx_8_vm(src0[i].fixu8[0], src1, res.fixu8[0], vme.fixu8, pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_even[i].fixu8[0]);

    test_vsll_vx_8_vm(src0[i].fixu8[0], src1, res.fixu8[0], vmo.fixu8, pad.fixu8[0]);
    result_compare_u8_lmul(res.fixu8[0], dst_odd[i].fixu8[0]);

    test_vsll_vx_16(vlmax_16 - 1, src0[i].fixu16[0], src1, res.fixu16[0], pad.fixu8[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_vl[i].fixu16[0]);

    test_vsll_vx_16_vm(src0[i].fixu16[0], src1, res.fixu16[0], vme.fixu16, pad.fixu8[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_even[i].fixu16[0]);

    test_vsll_vx_16_vm(src0[i].fixu16[0], src1, res.fixu16[0], vmo.fixu16, pad.fixu8[0]);
    result_compare_u16_lmul(res.fixu16[0], dst_odd[i].fixu16[0]);

    test_vsll_vx_32(vlmax_32 - 1, src0[i].fixu32[0], src1, res.fixu32[0], pad.fixu8[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_vl[i].fixu32[0]);

    test_vsll_vx_32_vm(src0[i].fixu32[0], src1, res.fixu32[0], vme.fixu32, pad.fixu8[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_even[i].fixu32[0]);

    test_vsll_vx_32_vm(src0[i].fixu32[0], src1, res.fixu32[0], vmo.fixu32, pad.fixu8[0]);
    result_compare_u32_lmul(res.fixu32[0], dst_odd[i].fixu32[0]);

    test_vsll_vx_64(vlmax_64 - 1, src0[i].fixu64[0], src1, res.fixu64[0], pad.fixu8[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_vl[i].fixu64[0]);

    test_vsll_vx_64_vm(src0[i].fixu64[0], src1, res.fixu64[0], vme.fixu64, pad.fixu8[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_even[i].fixu64[0]);

    test_vsll_vx_64_vm(src0[i].fixu64[0], src1, res.fixu64[0], vmo.fixu64, pad.fixu8[0]);
    result_compare_u64_lmul(res.fixu64[0], dst_odd[i].fixu64[0]);

    return done_testing();
}
