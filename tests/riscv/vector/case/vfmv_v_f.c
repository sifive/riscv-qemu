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

#include "testsuite.h"
#include "rvv_insn.h"

struct rvv_reg src0[] = {
    {
        .float64 = {
            {0x7fefffffffffffff, 0xffefffffffffffff,},
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
        },
        .float32 = {
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
            {0x483471f7, 0x46f2e02b, 0xff7fffff, 0x47ad69d9, },
        },
        .float16 = {
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
        },
    },
};

uint64_t src1 = 0x402b982fa8cba1c2;

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0x402b982fa8cba1c2, },
            {0x402b982fa8cba1c2, 0x402b982fa8cba1c2, },
        },
        .float32 = {
            {0xa8cba1c2, 0xa8cba1c2, 0xa8cba1c2, 0xa8cba1c2, },
            {0xa8cba1c2, 0xa8cba1c2, 0xa8cba1c2, 0xa8cba1c2, },
        },
        .float16 = {
            {0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, },
            {0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0xa1c2, 0x0000, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfmv.v.f\n");

    /* sew 16 */
    test_vfmv_v_f_16(vlmax_16 - 1, (uint16_t)src1, res.float16[0],
        pad.fixu16[0]);
    result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    /* sew 32 */
    test_vfmv_v_f_32((uint32_t)src1, res.float32[0], pad.fixu32[0]);
    result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    /* sew 64 */
    test_vfmv_v_f_64((uint64_t)src1, res.float64[0], pad.fixu64);
    result_compare_s64_lmul(res.float64[0], dst_vl[i].float64[0]);
    return done_testing();
}
