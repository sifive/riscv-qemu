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
    },
};

struct rvv_reg dst0[] = {
    {
        .fixs64 = {
            {0xffffffffffffffa5, 0xffffffffffffff8c, },
            {0xffffffffffffffcd, 0xffffffffffffff92, },
        },
    },
    {
        .fixs64 = {
            {0x0000000000000034, 0x0000000000000074, },
            {0x0000000000000075, 0x000000000000007a, },
        },
    },
    };


struct rvv_reg res0, res1;

int main(void)
{
    init_testsuite("Testing insn vlsseg2w\n");

    /* sew 64 */
    test_vlsseg2w_64(vlmax_64, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0], res1.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[0].fixs64[0]);
    result_compare_s64_lmul(res1.fixs64[0], dst0[1].fixs64[0]);

    return done_testing();
}
