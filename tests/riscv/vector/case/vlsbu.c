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

struct rvv_reg dst0[] = {
    {
        .fixu8 = {
            {0xa5, 0x8c, 0xcd, 0x92, 0x60, 0x3c, 0xfd, 0x23, 0xa5, 0x8c, 0xcd, 0x92, 0x60, 0x3c, 0xfd, 0x23, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
        },
        .fixu16 = {
            {0x00a5, 0x008c, 0x00cd, 0x0092, 0x0060, 0x003c, 0x00fd, 0x0023, },
            {0x00a5, 0x008c, 0x00cd, 0x0092, 0x0060, 0x003c, 0x00fd, 0x0023, },
        },
        .fixu32 = {
            {0x000000a5, 0x0000008c, 0x000000cd, 0x00000092, },
            {0x00000060, 0x0000003c, 0x000000fd, 0x00000023, },
        },
        .fixu64 = {
            {0x00000000000000a5, 0x000000000000008c, },
            {0x00000000000000cd, 0x0000000000000092, },
        },
    },
    {
        .fixu8 = {
            {0xa5, 0x11, 0xcd, 0x11, 0x60, 0x11, 0xfd, 0x11, 0xa5, 0x11, 0xcd, 0x11, 0x60, 0x11, 0xfd, 0x11, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        },
        .fixu16 = {
            {0x00a5, 0x1111, 0x00cd, 0x1111, 0x0060, 0x1111, 0x00fd, 0x1111, },
            {0x00a5, 0x1111, 0x00cd, 0x1111, 0x0060, 0x1111, 0x00fd, 0x1111, },
        },
        .fixu32 = {
            {0x000000a5, 0x11111111, 0x000000cd, 0x11111111, },
            {0x00000060, 0x11111111, 0x000000fd, 0x11111111, },
        },
        .fixu64 = {
            {0x00000000000000a5, 0x1111111111111111, },
            {0x00000000000000cd, 0x1111111111111111, },
        },
    },
    {
        .fixu8 = {
            {0x11, 0x8c, 0x11, 0x92, 0x11, 0x3c, 0x11, 0x23, 0x11, 0x8c, 0x11, 0x92, 0x11, 0x3c, 0x11, 0x23, },
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        },
        .fixu16 = {
            {0x1111, 0x008c, 0x1111, 0x0092, 0x1111, 0x003c, 0x1111, 0x0023, },
            {0x1111, 0x008c, 0x1111, 0x0092, 0x1111, 0x003c, 0x1111, 0x0023, },
        },
        .fixu32 = {
            {0x11111111, 0x0000008c, 0x11111111, 0x00000092, },
            {0x11111111, 0x0000003c, 0x11111111, 0x00000023, },
        },
        .fixu64 = {
            {0x1111111111111111, 0x000000000000008c, },
            {0x1111111111111111, 0x0000000000000092, },
        },
    },
};

struct rvv_reg res0;
int main(void)
{
    init_testsuite("Testing insn vlsbu\n");

    /* sew 8 */
    test_vlsbu_8(vlmax_8 / 2, &pad.fixu8[0], src0[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[0].fixu8[0]);

    test_vlsbu_8_vm(vlmax_8 / 2, &vme.fixu8, &pad.fixu8[0], src0[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[1].fixu8[0]);

    test_vlsbu_8_vm(vlmax_8 / 2, &vmo.fixu8, &pad.fixu8[0], src0[0].fixu8[0], res0.fixu8[0]);
    result_compare_s8_lmul(res0.fixu8[0], dst0[2].fixu8[0]);

    /* sew 16 */
    test_vlsbu_16(&pad.fixu16[0], src0[0].fixu8[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[0].fixu16[0]);

    test_vlsbu_16_vm(&vme.fixu16, &pad.fixu16[0], src0[0].fixu8[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[1].fixu16[0]);

    test_vlsbu_16_vm(&vmo.fixu16, &pad.fixu16[0], src0[0].fixu8[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[2].fixu16[0]);

    /* sew 32 */
    test_vlsbu_32(&pad.fixu32[0], src0[0].fixu8[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[0].fixu32[0]);

    test_vlsbu_32_vm(&vme.fixu32, &pad.fixu32[0], src0[0].fixu8[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[1].fixu32[0]);

    test_vlsbu_32_vm(&vmo.fixu32, &pad.fixu32[0], src0[0].fixu8[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[2].fixu32[0]);

    /* sew 64 */
    test_vlsbu_64(&pad.fixu64[0], src0[0].fixu8[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[0].fixu64[0]);

    test_vlsbu_64_vm(&vme.fixu64, &pad.fixu64[0], src0[0].fixu8[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[1].fixu64[0]);

    test_vlsbu_64_vm(&vmo.fixu64, &pad.fixu64[0], src0[0].fixu8[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[2].fixu64[0]);

    return done_testing();
}
