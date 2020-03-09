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
        .fixs64 = {
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        },
        .fixs32 = {
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        },
        .fixs16 = {
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        },
        .fixs8 = {
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
        },
    },
};

uint64_t src[8] = {0xc2, 0x0, 0x4b63, 0x0, 0x683e0475, 0x0, 0x1c626bcd2715a031, 0x0};

struct rvv_reg dst[] = {
    {
        .fixs64 = {
            {0x1c626bcd2715a031, },
        },
        .fixs32 = {
            {0x683e0475, },
        },
        .fixs16 = {
            {0x4b63,},
        },
        .fixs8 = {
            {0xc2,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    init_testsuite("Testing insn vmv.s.x\n");

    test_vmv_s_x_8(src[0], res.fixs8[0]);
    result_compare_s8(res.fixs8[0], dst[0].fixs8[0]);

    test_vmv_s_x_16(src[2], res.fixs16[0]);
    result_compare_s16(res.fixs16[0], dst[0].fixs16[0]);

    test_vmv_s_x_32(src[4], res.fixs32[0]);
    result_compare_s32(res.fixs32[0], dst[0].fixs32[0]);

    test_vmv_s_x_64(src[6], res.fixs64[0]);
    result_compare_s64(res.fixs64[0], dst[0].fixs64[0]);

    return done_testing();
}
