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
            {0xffffffa5, 0xffffff8c, 0xffffffcd, 0xffffff92, },
            {0x00000060, 0x0000003c, 0xfffffffd, 0x00000023, },
        },
    },
};

struct rvv_reg dst0[] = {
    {
        .fixs32 = {
            {0xffffffa5, 0xffffffcd, 0x00000060, 0xfffffffd, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0xffffffffffffffcd, },
            {0x0000000000000060, 0xfffffffffffffffd, },
        },
    },
    {
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0x00000060, 0x11111111, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x1111111111111111, },
            {0x0000000000000060, 0x1111111111111111, },
        },
    },
    {
        .fixs32 = {
            {0x11111111, 0xffffffcd, 0x11111111, 0xfffffffd, },
            {0x00000000, 0x00000000, 0x00000000, 0x00000000, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffffffffffffffcd, },
            {0x1111111111111111, 0xfffffffffffffffd, },
        },
    },
};

struct rvv_reg res0;
int main(void)
{
    init_testsuite("Testing insn vlsw\n");

    /* sew 32 */
    test_vlsw_32(vlmax_32 / 2, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[0].fixs32[0]);

    test_vlsw_32_vm(vlmax_32 / 2, &vme.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[1].fixs32[0]);

    test_vlsw_32_vm(vlmax_32 / 2, &vmo.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[2].fixs32[0]);

    /* sew 64 */
    test_vlsw_64(&pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[0].fixs64[0]);

    test_vlsw_64_vm(&vme.fixs64, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[1].fixs64[0]);

    test_vlsw_64_vm(&vmo.fixs64, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[2].fixs64[0]);

    return done_testing();
}
