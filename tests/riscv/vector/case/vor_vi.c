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
        },
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
struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0xf5, 0xf4, 0xfc, 0xf4, 0xfd, 0xf5, 0xf2, 0xfa, 0xf0, 0xf9, 0xfc, 0xf1, 0xfd, 0xfb, 0xf3, 0xf1, },
            {0xf5, 0xf4, 0xfc, 0xf4, 0xfd, 0xf5, 0xf2, 0xfa, 0xf0, 0xf9, 0xfc, 0xf1, 0xfd, 0xfb, 0xf3, 0x00, },
        },
        .fixs16 = {
            {0xfff6, 0xfff2, 0xffff, 0xfff1, 0xfff9, 0xffff, 0xfffd, 0xfff4, },
            {0xfff6, 0xfff2, 0xffff, 0xfff1, 0xfff9, 0xffff, 0xfffd, 0x0000, },
        },
        .fixs32 = {
            {0xfffffff6, 0xfffffff1, 0xfffffff1, 0xfffffffa, },
            {0xfffffff6, 0xfffffff1, 0xfffffff1, 0x00000000, },
        },
        .fixs64 = {
            {0xfffffffffffffff2, 0xfffffffffffffffb, },
            {0xfffffffffffffff2, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0xaf, 0x11, 0x8f, 0x11, 0xcf, 0x11, 0x9f, 0x11, 0x6f, 0x11, 0x3f, 0x11, 0xff, 0x11, 0x2f, 0x11, },
            {0xaf, 0x11, 0x8f, 0x11, 0xcf, 0x11, 0x9f, 0x11, 0x6f, 0x11, 0x3f, 0x11, 0xff, 0x11, 0x2f, 0x11, },
        },
        .fixs16 = {
            {0xd6df, 0x1111, 0x10ef, 0x1111, 0xa34f, 0x1111, 0x475f, 0x1111, },
            {0xd6df, 0x1111, 0x10ef, 0x1111, 0xa34f, 0x1111, 0x475f, 0x1111, },
        },
        .fixs32 = {
            {0xcfe0668f, 0x11111111, 0x15fc522f, 0x11111111, },
            {0xcfe0668f, 0x11111111, 0x15fc522f, 0x11111111, },
        },
        .fixs64 = {
            {0x3970b5993ab1f21f, 0x1111111111111111, },
            {0x3970b5993ab1f21f, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0x3f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x1f, 0x11, 0x9f, 0x11, 0xaf, 0x11, 0x2f, },
            {0x11, 0x3f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x1f, 0x11, 0x9f, 0x11, 0xaf, 0x11, 0x2f, },
        },
        .fixs16 = {
            {0x1111, 0x51ff, 0x1111, 0x0eaf, 0x1111, 0x4d3f, 0x1111, 0xa16f, },
            {0x1111, 0x51ff, 0x1111, 0x0eaf, 0x1111, 0x4d3f, 0x1111, 0xa16f, },
        },
        .fixs32 = {
            {0x11111111, 0x8262f66f, 0x11111111, 0xd6b9745f, },
            {0x11111111, 0x8262f66f, 0x11111111, 0xd6b9745f, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xc6a630b347e7377f, },
            {0x1111111111111111, 0xc6a630b347e7377f, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vor.vi\n");

    test_vor_vi_8(vlmax_8 - 1, src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vor_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vor_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    test_vor_vi_16(vlmax_16 - 1, src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vor_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vor_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    test_vor_vi_32(vlmax_32 - 1, src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vor_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vor_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    test_vor_vi_64(vlmax_64 - 1, src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vor_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vor_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
