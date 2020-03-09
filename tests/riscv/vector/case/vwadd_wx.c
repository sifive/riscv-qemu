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
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0xc6a630b347e7377b, },
        },
        .fixs32 = {
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x15fc5221, 0xd6b9745a, },
        },
        .fixs16 = {
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x10ef, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0xa164, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

int64_t src1 = 0x1122334455667788;

struct rvv_reg dst_vl[] = {
    {
        .fixs16 = {
            {0xd65e, 0x517a, 0x1077, 0x0e29, 0xa2d1, 0x4cc7, 0x46e5, 0xa0ec, },
            {0xd65e, 0x517a, 0x1077, 0x0e29, 0xa2d1, 0x4cc7, 0x46e5, 0xa0ec, },
            {0xd65e, 0x517a, 0x1077, 0x0e29, 0xa2d1, 0x4cc7, 0x46e5, 0xa0ec, },
            {0xd65e, 0x517a, 0x1077, 0x0e29, 0xa2d1, 0x4cc7, 0x46e5, 0x0000, },
        },
        .fixs32 = {
            {0xcfe0de0e, 0x82636de9, 0x15fcc9a9, 0xd6b9ebe2, },
            {0xcfe0de0e, 0x82636de9, 0x15fcc9a9, 0xd6b9ebe2, },
            {0xcfe0de0e, 0x82636de9, 0x15fcc9a9, 0xd6b9ebe2, },
            {0xcfe0de0e, 0x82636de9, 0x15fcc9a9, 0x00000000, },
        },
        .fixs64 = {
            {0x3970b5999018699a, 0xc6a630b39d4daf03, },
            {0x3970b5999018699a, 0xc6a630b39d4daf03, },
            {0x3970b5999018699a, 0xc6a630b39d4daf03, },
            {0x3970b5999018699a, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xd65e, 0x1111, 0x1077, 0x1111, 0xa2d1, 0x1111, 0x46e5, 0x1111, },
            {0xd65e, 0x1111, 0x1077, 0x1111, 0xa2d1, 0x1111, 0x46e5, 0x1111, },
            {0xd65e, 0x1111, 0x1077, 0x1111, 0xa2d1, 0x1111, 0x46e5, 0x1111, },
            {0xd65e, 0x1111, 0x1077, 0x1111, 0xa2d1, 0x1111, 0x46e5, 0x1111, },
        },
        .fixs32 = {
            {0xcfe0de0e, 0x11111111, 0x15fcc9a9, 0x11111111, },
            {0xcfe0de0e, 0x11111111, 0x15fcc9a9, 0x11111111, },
            {0xcfe0de0e, 0x11111111, 0x15fcc9a9, 0x11111111, },
            {0xcfe0de0e, 0x11111111, 0x15fcc9a9, 0x11111111, },
        },
        .fixs64 = {
            {0x3970b5999018699a, 0x1111111111111111, },
            {0x3970b5999018699a, 0x1111111111111111, },
            {0x3970b5999018699a, 0x1111111111111111, },
            {0x3970b5999018699a, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0x517a, 0x1111, 0x0e29, 0x1111, 0x4cc7, 0x1111, 0xa0ec, },
            {0x1111, 0x517a, 0x1111, 0x0e29, 0x1111, 0x4cc7, 0x1111, 0xa0ec, },
            {0x1111, 0x517a, 0x1111, 0x0e29, 0x1111, 0x4cc7, 0x1111, 0xa0ec, },
            {0x1111, 0x517a, 0x1111, 0x0e29, 0x1111, 0x4cc7, 0x1111, 0xa0ec, },
        },
        .fixs32 = {
            {0x11111111, 0x82636de9, 0x11111111, 0xd6b9ebe2, },
            {0x11111111, 0x82636de9, 0x11111111, 0xd6b9ebe2, },
            {0x11111111, 0x82636de9, 0x11111111, 0xd6b9ebe2, },
            {0x11111111, 0x82636de9, 0x11111111, 0xd6b9ebe2, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xc6a630b39d4daf03, },
            {0x1111111111111111, 0xc6a630b39d4daf03, },
            {0x1111111111111111, 0xc6a630b39d4daf03, },
            {0x1111111111111111, 0xc6a630b39d4daf03, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwadd.wx\n");

    /* uint8_t add */
    test_vwadd_wx_8(vlmax_8 - 1, src0[i].fixs16[0], src1, res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwadd_wx_8_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwadd_wx_8_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* uint16_t add */
    test_vwadd_wx_16(vlmax_16 - 1, src0[i].fixs32[0], src1, res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwadd_wx_16_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwadd_wx_16_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* uint32_t add */
    test_vwadd_wx_32(vlmax_32 - 1, src0[i].fixs64[0], src1, res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwadd_wx_32_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwadd_wx_32_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
