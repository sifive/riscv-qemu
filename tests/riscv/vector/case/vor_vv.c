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

struct rvv_reg src1[] = {
    {
        .fixs64 = {
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
        },
        .fixs32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .fixs16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .fixs8 = {
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0xa5, 0xb6, 0x8d, 0x7e, 0xef, 0x7d, 0x92, 0x7f, 0x6c, 0x1b, 0xbc, 0x97, 0xfd, 0xef, 0x6f, 0xbb, },
            {0xa5, 0xb6, 0x8d, 0x7e, 0xef, 0x7d, 0x92, 0x7f, 0x6c, 0x1b, 0xbc, 0x97, 0xfd, 0xef, 0x6f, 0x00, },
        },
        .fixs16 = {
            {0xdffe, 0x79f3, 0x77ef, 0xfeb9, 0xefc9, 0xdd7f, 0x775d, 0xeff5, },
            {0xdffe, 0x79f3, 0x77ef, 0xfeb9, 0xefc9, 0xdd7f, 0x775d, 0x0000, },
        },
        .fixs32 = {
            {0xfff4f7c7, 0xf3fffe75, 0x77fff37f, 0xd6ff7e7e, },
            {0xfff4f7c7, 0xf3fffe75, 0x77fff37f, 0x00000000, },
        },
        .fixs64 = {
            {0x3ff2b59bbab1f7b6, 0xc7be71f3e7ffff7f, },
            {0x3ff2b59bbab1f7b6, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0xa5, 0x11, 0x8d, 0x11, 0xef, 0x11, 0x92, 0x11, 0x6c, 0x11, 0xbc, 0x11, 0xfd, 0x11, 0x6f, 0x11, },
            {0xa5, 0x11, 0x8d, 0x11, 0xef, 0x11, 0x92, 0x11, 0x6c, 0x11, 0xbc, 0x11, 0xfd, 0x11, 0x6f, 0x11, },
        },
        .fixs16 = {
            {0xdffe, 0x1111, 0x77ef, 0x1111, 0xefc9, 0x1111, 0x775d, 0x1111, },
            {0xdffe, 0x1111, 0x77ef, 0x1111, 0xefc9, 0x1111, 0x775d, 0x1111, },
        },
        .fixs32 = {
            {0xfff4f7c7, 0x11111111, 0x77fff37f, 0x11111111, },
            {0xfff4f7c7, 0x11111111, 0x77fff37f, 0x11111111, },
        },
        .fixs64 = {
            {0x3ff2b59bbab1f7b6, 0x1111111111111111, },
            {0x3ff2b59bbab1f7b6, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0xb6, 0x11, 0x7e, 0x11, 0x7d, 0x11, 0x7f, 0x11, 0x1b, 0x11, 0x97, 0x11, 0xef, 0x11, 0xbb, },
            {0x11, 0xb6, 0x11, 0x7e, 0x11, 0x7d, 0x11, 0x7f, 0x11, 0x1b, 0x11, 0x97, 0x11, 0xef, 0x11, 0xbb, },
        },
        .fixs16 = {
            {0x1111, 0x79f3, 0x1111, 0xfeb9, 0x1111, 0xdd7f, 0x1111, 0xeff5, },
            {0x1111, 0x79f3, 0x1111, 0xfeb9, 0x1111, 0xdd7f, 0x1111, 0xeff5, },
        },
        .fixs32 = {
            {0x11111111, 0xf3fffe75, 0x11111111, 0xd6ff7e7e, },
            {0x11111111, 0xf3fffe75, 0x11111111, 0xd6ff7e7e, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xc7be71f3e7ffff7f, },
            {0x1111111111111111, 0xc7be71f3e7ffff7f, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vor.vv\n");

    /* int8_t or */
    test_vor_vv_8(vlmax_8 - 1, src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vor_vv_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vor_vv_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t or */
    test_vor_vv_16(vlmax_16 - 1, src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vor_vv_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vor_vv_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t or */
    test_vor_vv_32(vlmax_32 - 1, src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vor_vv_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vor_vv_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t or */
    test_vor_vv_64(vlmax_64 - 1, src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vor_vv_64_vm(src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vor_vv_64_vm(src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
