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
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .fixu8 = {
            {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, },
            {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, },
        },
        .fixu16 = {
            {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007},
            {0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f},
        },
        .fixu32 = {
            {0x00000000, 0x00000001, 0x00000002, 0x00000003, },
            {0x00000004, 0x00000005, 0x00000006, 0x00000007, },
        },
        .fixu64 = {
            {0x0000000000000000, 0x0000000000000001, },
            {0x0000000000000002, 0x0000000000000003, }
        },

    },
};


struct rvv_reg dst0[] = {
    {
        .fixu8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x00, },
        },
        .fixu16 = {
            {0x00a5, 0x0034, 0x008c, 0x0074, 0x00cd, 0x0075, 0x0092, 0x007a, },
            {0x0060, 0x0019, 0x003c, 0x0091, 0x00fd, 0x00ab, 0x0023, 0x0000, },
        },
        .fixu32 = {
            {0x000000a5, 0x00000034, 0x0000008c, 0x00000074, },
            {0x000000cd, 0x00000075, 0x00000092, 0x00000000, },
        },
        .fixu64 = {
            {0x00000000000000a5, 0x0000000000000034, },
            {0x000000000000008c, 0x0000000000000000, },
        },
    },
    {
        .fixu8 = {
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
        },
        .fixu16 = {
            {0x00a5, 0x1111, 0x008c, 0x1111, 0x00cd, 0x1111, 0x0092, 0x1111, },
            {0x0060, 0x1111, 0x003c, 0x1111, 0x00fd, 0x1111, 0x0023, 0x1111, },
        },
        .fixu32 = {
            {0x000000a5, 0x11111111, 0x0000008c, 0x11111111, },
            {0x000000cd, 0x11111111, 0x00000092, 0x11111111, },
        },
        .fixu64 = {
            {0x00000000000000a5, 0x1111111111111111, },
            {0x000000000000008c, 0x1111111111111111, },
        },
    },
    {
        .fixu8 = {
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
        },
        .fixu16 = {
            {0x1111, 0x0034, 0x1111, 0x0074, 0x1111, 0x0075, 0x1111, 0x007a, },
            {0x1111, 0x0019, 0x1111, 0x0091, 0x1111, 0x00ab, 0x1111, 0x0021, },
        },
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
    init_testsuite("Testing insn vlxbu\n");

    /* sew 8 */
    test_vlxbu_8(vlmax_8 - 1, &pad.fixu8[0], src0[0].fixu8[0], src1[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[0].fixu8[0]);

    test_vlxbu_8_vm(&vme.fixu8, &pad.fixu8[0], src0[0].fixu8[0], src1[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[1].fixu8[0]);

    test_vlxbu_8_vm(&vmo.fixu8, &pad.fixu8[0], src0[0].fixu8[0], src1[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[2].fixu8[0]);

    /* sew 16 */
    test_vlxbu_16(vlmax_16 - 1, &pad.fixu16[0], src0[0].fixu8[0], src1[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[0].fixu16[0]);

    test_vlxbu_16_vm(&vme.fixu16, &pad.fixu16[0], src0[0].fixu8[0], src1[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[1].fixu16[0]);

    test_vlxbu_16_vm(&vmo.fixu16, &pad.fixu16[0], src0[0].fixu8[0], src1[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[2].fixu16[0]);

    /* sew 32 */
    test_vlxbu_32(vlmax_32 - 1, &pad.fixu32[0], src0[0].fixu8[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[0].fixu32[0]);

    test_vlxbu_32_vm(&vme.fixu32, &pad.fixu32[0], src0[0].fixu8[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[1].fixu32[0]);

    test_vlxbu_32_vm(&vmo.fixu32, &pad.fixu32[0], src0[0].fixu8[0], src1[0].fixu32[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[2].fixu32[0]);

    /* sew 64 */
    test_vlxbu_64(vlmax_64 - 1, &pad.fixu64[0], src0[0].fixu8[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[0].fixu64[0]);

    test_vlxbu_64_vm(&vme.fixu64, &pad.fixu64[0], src0[0].fixu8[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[1].fixu64[0]);

    test_vlxbu_64_vm(&vmo.fixu64, &pad.fixu64[0], src0[0].fixu8[0], src1[0].fixu64[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[2].fixu64[0]);

    return done_testing();
}
