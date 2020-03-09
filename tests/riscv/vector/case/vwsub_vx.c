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
            {0x001d, 0x00ac, 0x0004, 0x00ec, 0x0045, 0x00ed, 0x000a, 0x00f2, },
            {0x00d8, 0x0091, 0x00b4, 0x0009, 0x0075, 0x0023, 0x009b, 0x0099, },
            {0x001d, 0x00ac, 0x0004, 0x00ec, 0x0045, 0x00ed, 0x000a, 0x00f2, },
            {0x00d8, 0x0091, 0x00b4, 0x0009, 0x0075, 0x0023, 0x009b, 0x0000, },
        },
        .fixs32 = {
            {0xffff5f4e, 0xffffda6a, 0xffff9967, 0xffff9719, },
            {0xffff2bc1, 0xffffd5b7, 0xffffcfd5, 0xffff29dc, },
            {0xffff5f4e, 0xffffda6a, 0xffff9967, 0xffff9719, },
            {0xffff2bc1, 0xffffd5b7, 0xffffcfd5, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffff7a79eefe, 0xffffffff2cfc7ed9, },
            {0xffffffffc095da99, 0xffffffff8152fcd2, },
            {0xffffffff7a79eefe, 0xffffffff2cfc7ed9, },
            {0xffffffffc095da99, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0x001d, 0x1111, 0x0004, 0x1111, 0x0045, 0x1111, 0x000a, 0x1111, },
            {0x00d8, 0x1111, 0x00b4, 0x1111, 0x0075, 0x1111, 0x009b, 0x1111, },
            {0x001d, 0x1111, 0x0004, 0x1111, 0x0045, 0x1111, 0x000a, 0x1111, },
            {0x00d8, 0x1111, 0x00b4, 0x1111, 0x0075, 0x1111, 0x009b, 0x1111, },
        },
        .fixs32 = {
            {0xffff5f4e, 0x11111111, 0xffff9967, 0x11111111, },
            {0xffff2bc1, 0x11111111, 0xffffcfd5, 0x11111111, },
            {0xffff5f4e, 0x11111111, 0xffff9967, 0x11111111, },
            {0xffff2bc1, 0x11111111, 0xffffcfd5, 0x11111111, },
        },
        .fixs64 = {
            {0xffffffff7a79eefe, 0x1111111111111111, },
            {0xffffffffc095da99, 0x1111111111111111, },
            {0xffffffff7a79eefe, 0x1111111111111111, },
            {0xffffffffc095da99, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0x00ac, 0x1111, 0x00ec, 0x1111, 0x00ed, 0x1111, 0x00f2, },
            {0x1111, 0x0091, 0x1111, 0x0009, 0x1111, 0x0023, 0x1111, 0x0099, },
            {0x1111, 0x00ac, 0x1111, 0x00ec, 0x1111, 0x00ed, 0x1111, 0x00f2, },
            {0x1111, 0x0091, 0x1111, 0x0009, 0x1111, 0x0023, 0x1111, 0x0099, },
        },
        .fixs32 = {
            {0x11111111, 0xffffda6a, 0x11111111, 0xffff9719, },
            {0x11111111, 0xffffd5b7, 0x11111111, 0xffff29dc, },
            {0x11111111, 0xffffda6a, 0x11111111, 0xffff9719, },
            {0x11111111, 0xffffd5b7, 0x11111111, 0xffff29dc, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffffffff2cfc7ed9, },
            {0x1111111111111111, 0xffffffff8152fcd2, },
            {0x1111111111111111, 0xffffffff2cfc7ed9, },
            {0x1111111111111111, 0xffffffff8152fcd2, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsub.vx\n");

    /* int8_t sub */
    test_vwsub_vx_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwsub_vx_8_vm(src0[i].fixs8[0], src1, res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwsub_vx_8_vm(src0[i].fixs8[0], src1, res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int16_t sub */
    test_vwsub_vx_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwsub_vx_16_vm(src0[i].fixs16[0], src1, res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwsub_vx_16_vm(src0[i].fixs16[0], src1, res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int32_t sub */
    test_vwsub_vx_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwsub_vx_32_vm(src0[i].fixs32[0], src1, res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwsub_vx_32_vm(src0[i].fixs32[0], src1, res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
