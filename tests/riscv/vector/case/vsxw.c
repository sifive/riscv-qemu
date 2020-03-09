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
        .fixs32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x0000007a, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x0000000000000034, },
            {0xffffffffffffff8c, 0x0000000000000074, },
        }
    },
};

struct rvv_reg src1[] = {
    {
        .fixs32 = {
            {0x00000000, 0x00000008, 0x00000010, 0x00000018, },
            {0x00000000, 0x00000008, 0x00000010, 0x00000018, },
        },
        .fixs64 = {
            {0x0000000000000000, 0x0000000000000008, },
            {0x0000000000000000, 0x0000000000000008, },
        },

    },
};
struct rvv_reg dst0[] = {
    {
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0x00000034, 0x11111111, },
            {0xffffff8c, 0x11111111, 0x00000074, 0x11111111, },
        },
    },
    {
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0x11111111, 0x11111111, },
            {0xffffff8c, 0x11111111, 0x11111111, 0x11111111, },
        },
    },
    {
        .fixs32 = {
            {0x11111111, 0x11111111, 0x00000034, 0x11111111, },
            {0x11111111, 0x11111111, 0x00000074, 0x11111111, },
        },
    },
};

struct rvv_reg dst1[] = {
    {
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0x00000034, 0x11111111, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
    },
    {
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0x11111111, 0x11111111, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
    },
    {
        .fixs32 = {
            {0x11111111, 0x11111111, 0x00000034, 0x11111111, },
            {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        },
    },
};


struct rvv_reg res0;

int main(void)
{
    init_testsuite("Testing insn vsxw\n");

    /* sew 32 */
    test_vsxw_32(vlmax_32 / 2, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[0].fixs32[0]);

    test_vsxw_32_vm(vlmax_32 / 2, &vme.fixs32, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[1].fixs32[0]);

    test_vsxw_32_vm(vlmax_32 / 2, &vmo.fixs32, &pad.fixs32[0], src0[0].fixs32[0], src1[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[2].fixs32[0]);

    /* sew 64 */
    test_vsxw_64(vlmax_64 / 2, &pad.fixs32[0], src0[0].fixs64[0], src1[0].fixs64[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst1[0].fixs32[0]);

    test_vsxw_64_vm(vlmax_64 / 2, &vme.fixs64, &pad.fixs32[0], src0[0].fixs64[0], src1[0].fixs64[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst1[1].fixs32[0]);

    test_vsxw_64_vm(vlmax_64 / 2, &vmo.fixs64, &pad.fixs32[0], src0[0].fixs64[0], src1[0].fixs64[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst1[2].fixs32[0]);

    return done_testing();
}
