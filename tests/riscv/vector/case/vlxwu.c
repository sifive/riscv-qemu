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
        .fixu32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x0000007a, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .fixu32 = {
            {0x00000000, 0x00000004, 0x00000008, 0x0000000c, },
            {0x00000010, 0x00000014, 0x00000018, 0x0000001c, },
        },
        .fixu64 = {
            {0x0000000000000000, 0x0000000000000004, },
            {0x0000000000000008, 0x000000000000000c, }
        },

    },
};


struct rvv_reg dst0[] = {
    {
        .fixu32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x00000000, },
        },
        .fixu64 = {
            {0x00000000ffffffa5, 0x0000000000000034, },
            {0x00000000ffffff8c, 0x0000000000000000, },
        },
    },
    {
        .fixu32 = {
            {0xffffffa5, 0x11111111, 0xffffff8c, 0x11111111, },
            {0xffffffcd, 0x11111111, 0xffffff92, 0x11111111, },
        },
        .fixu64 = {
            {0x00000000ffffffa5, 0x1111111111111111, },
            {0x00000000ffffff8c, 0x1111111111111111, },
        },
    },
    {
        .fixu32 = {
            {0x11111111, 0x00000034, 0x11111111, 0x00000074, },
            {0x11111111, 0x00000075, 0x11111111, 0x0000007a, },
        },
        .fixu64 = {
            {0x1111111111111111, 0x0000000000000034, },
            {0x1111111111111111, 0x0000000000000074, },
        },
    },
    };


struct rvv_reg res0;

int main(void)
{
    init_testsuite("Testing insn vlxwu\n");

    /* sew 32 */
    test_vlxwu_32(vlmax_32 - 1, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[0].fixu32[0]);

    test_vlxwu_32_vm(&vme.fixu32, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[1].fixu32[0]);

    test_vlxwu_32_vm(&vmo.fixu32, &pad.fixu32[0], src0[0].fixu32[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[2].fixu32[0]);

    /* sew 64 */
    test_vlxwu_64(vlmax_64 - 1, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[0].fixu64[0]);

    test_vlxwu_64_vm(&vme.fixu64, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[1].fixu64[0]);

    test_vlxwu_64_vm(&vmo.fixu64, &pad.fixu64[0], src0[0].fixu32[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[2].fixu64[0]);

    return done_testing();
}
