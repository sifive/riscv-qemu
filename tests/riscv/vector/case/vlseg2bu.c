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
        .fixu16 = {
            {0x00a5, 0x008c, 0x00cd, 0x0092, 0x0060, 0x003c, 0x00fd, 0x0023, },
            {0x00a5, 0x008c, 0x00cd, 0x0092, 0x0060, 0x003c, 0x00fd, 0x0023, },
        },
    },
    {
        .fixu16 = {
            {0x0034, 0x0074, 0x0075, 0x007a, 0x0019, 0x0091, 0x00ab, 0x0021},
            {0x0034, 0x0074, 0x0075, 0x007a, 0x0019, 0x0091, 0x00ab, 0x0021},
        },
    },
    };


struct rvv_reg res0, res1;

int main(void)
{
    init_testsuite("Testing insn vlseg2bu\n");

    /* sew 16 */
    test_vlseg2bu_16(vlmax_16, &pad.fixu16[0], src0[0].fixu8[0], res0.fixu16[0], res1.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[0].fixu16[0]);
    result_compare_s16_lmul(res1.fixu16[0], dst0[1].fixu16[0]);

    return done_testing();
}
