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
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

int64_t src1 = 0x1122334455667788;

struct rvv_reg dst_vl[] = {
    {
        .fixs16 = {
            {0xff2d, 0xffbc, 0xff14, 0xfffc, 0xff55, 0xfffd, 0xff1a, 0x0002, },
            {0xffe8, 0xffa1, 0xffc4, 0xff19, 0xff85, 0xff33, 0xffab, 0xffa9, },
            {0xff2d, 0xffbc, 0xff14, 0xfffc, 0xff55, 0xfffd, 0xff1a, 0x0002, },
            {0xffe8, 0xffa1, 0xffc4, 0xff19, 0xff85, 0xff33, 0xffab, 0x0000, },
        },
        .fixs32 = {
            {0x00004e5e, 0x0000c97a, 0x00008877, 0x00008629, },
            {0x00001ad1, 0x0000c4c7, 0x0000bee5, 0x000018ec, },
            {0x00004e5e, 0x0000c97a, 0x00008877, 0x00008629, },
            {0x00001ad1, 0x0000c4c7, 0x0000bee5, 0x00000000, },
        },
        .fixs64 = {
            {0x000000002546de0e, 0xffffffffd7c96de9, },
            {0x000000006b62c9a9, 0x000000002c1febe2, },
            {0x000000002546de0e, 0xffffffffd7c96de9, },
            {0x000000006b62c9a9, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xff2d, 0x1111, 0xff14, 0x1111, 0xff55, 0x1111, 0xff1a, 0x1111, },
            {0xffe8, 0x1111, 0xffc4, 0x1111, 0xff85, 0x1111, 0xffab, 0x1111, },
            {0xff2d, 0x1111, 0xff14, 0x1111, 0xff55, 0x1111, 0xff1a, 0x1111, },
            {0xffe8, 0x1111, 0xffc4, 0x1111, 0xff85, 0x1111, 0xffab, 0x1111, },
        },
        .fixs32 = {
            {0x00004e5e, 0x11111111, 0x00008877, 0x11111111, },
            {0x00001ad1, 0x11111111, 0x0000bee5, 0x11111111, },
            {0x00004e5e, 0x11111111, 0x00008877, 0x11111111, },
            {0x00001ad1, 0x11111111, 0x0000bee5, 0x11111111, },
        },
        .fixs64 = {
            {0x000000002546de0e, 0x1111111111111111, },
            {0x000000006b62c9a9, 0x1111111111111111, },
            {0x000000002546de0e, 0x1111111111111111, },
            {0x000000006b62c9a9, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0xffbc, 0x1111, 0xfffc, 0x1111, 0xfffd, 0x1111, 0x0002, },
            {0x1111, 0xffa1, 0x1111, 0xff19, 0x1111, 0xff33, 0x1111, 0xffa9, },
            {0x1111, 0xffbc, 0x1111, 0xfffc, 0x1111, 0xfffd, 0x1111, 0x0002, },
            {0x1111, 0xffa1, 0x1111, 0xff19, 0x1111, 0xff33, 0x1111, 0xffa9, },
        },
        .fixs32 = {
            {0x11111111, 0x0000c97a, 0x11111111, 0x00008629, },
            {0x11111111, 0x0000c4c7, 0x11111111, 0x000018ec, },
            {0x11111111, 0x0000c97a, 0x11111111, 0x00008629, },
            {0x11111111, 0x0000c4c7, 0x11111111, 0x000018ec, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffffffffd7c96de9, },
            {0x1111111111111111, 0x000000002c1febe2, },
            {0x1111111111111111, 0xffffffffd7c96de9, },
            {0x1111111111111111, 0x000000002c1febe2, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwadd.vx\n");

    /* uint8_t add */
    test_vwadd_vx_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwadd_vx_8_vm(src0[i].fixs8[0], src1, res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwadd_vx_8_vm(src0[i].fixs8[0], src1, res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* uint16_t add */
    test_vwadd_vx_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwadd_vx_16_vm(src0[i].fixs16[0], src1, res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwadd_vx_16_vm(src0[i].fixs16[0], src1, res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* uint32_t add */
    test_vwadd_vx_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwadd_vx_32_vm(src0[i].fixs32[0], src1, res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwadd_vx_32_vm(src0[i].fixs32[0], src1, res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
