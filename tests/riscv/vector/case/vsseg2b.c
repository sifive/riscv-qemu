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
        .fixs16 = {
            {0xffa5, 0xff8c, 0xffcd, 0xff92, 0x0060, 0x003c, 0xfffd, 0x0023, },
            {0xffa5, 0xff8c, 0xffcd, 0xff92, 0x0060, 0x003c, 0xfffd, 0x0023, },
        },
    },
    {
        .fixs16 = {
            {0x0034, 0x0074, 0x0075, 0x007a, 0x0019, 0xff91, 0xffab, 0x0021},
            {0x0034, 0x0074, 0x0075, 0x007a, 0x0019, 0xff91, 0xffab, 0x0021},
        },
    },
};

struct rvv_reg dst0[] = {
    {
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};


struct rvv_reg res0;

int main(void)
{
    init_testsuite("Testing insn vsseg2b\n");

    /* sew 16 */
    test_vsseg2b_16(&pad.fixs8[0], src0[0].fixs16[0], src0[1].fixs16[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[0].fixs8[0]);

    return done_testing();
}
