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
            {0xc7, 0xeb, 0x1a, 0xaf, 0xb0, 0x7f, 0x23, 0x90, 0x8d, 0x2d, 0xe9, 0x18, 0x26, 0x7a, 0x73, 0xdd, },
            {0xc7, 0xeb, 0x1a, 0xaf, 0xb0, 0x7f, 0x23, 0x90, 0x8d, 0x2d, 0xe9, 0x18, 0x26, 0x7a, 0x73, 0x00, },
        },
        .fixs16 = {
            {0x268f, 0x8ba6, 0x7834, 0x093a, 0x71cb, 0xe6bd, 0x777a, 0x711a, },
            {0x268f, 0x8ba6, 0x7834, 0x093a, 0x71cb, 0xe6bd, 0x777a, 0x0000, },
        },
        .fixs32 = {
            {0x47753bc8, 0x7422a277, 0x7de005a1, 0xe998b2d7, },
            {0x47753bc8, 0x7422a277, 0x7de005a1, 0x00000000, },
        },
        .fixs64 = {
            {0x4142cb2bc552c9c9, 0xcdbe92152de11f8b, },
            {0x4142cb2bc552c9c9, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0xc7, 0xea, 0x1a, 0xae, 0xb0, 0x7e, 0x23, 0x8f, 0x8d, 0x2c, 0xe9, 0x17, 0x26, 0x79, 0x73, 0xdc, },
            {0xc7, 0xea, 0x1a, 0xae, 0xb0, 0x7e, 0x23, 0x8f, 0x8d, 0x2c, 0xe9, 0x17, 0x26, 0x79, 0x73, 0xdc, },
        },
        .fixs16 = {
            {0x268f, 0x8ba5, 0x7834, 0x0939, 0x71cb, 0xe6bc, 0x777a, 0x7119, },
            {0x268f, 0x8ba5, 0x7834, 0x0939, 0x71cb, 0xe6bc, 0x777a, 0x7119, },
        },
        .fixs32 = {
            {0x47753bc8, 0x7422a276, 0x7de005a1, 0xe998b2d6, },
            {0x47753bc8, 0x7422a276, 0x7de005a1, 0xe998b2d6, },
        },
        .fixs64 = {
            {0x4142cb2bc552c9c9, 0xcdbe92152de11f8a, },
            {0x4142cb2bc552c9c9, 0xcdbe92152de11f8a, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0xc6, 0xeb, 0x19, 0xaf, 0xaf, 0x7f, 0x22, 0x90, 0x8c, 0x2d, 0xe8, 0x18, 0x25, 0x7a, 0x72, 0xdd, },
            {0xc6, 0xeb, 0x19, 0xaf, 0xaf, 0x7f, 0x22, 0x90, 0x8c, 0x2d, 0xe8, 0x18, 0x25, 0x7a, 0x72, 0xdd, },
        },
        .fixs16 = {
            {0x268e, 0x8ba6, 0x7833, 0x093a, 0x71ca, 0xe6bd, 0x7779, 0x711a, },
            {0x268e, 0x8ba6, 0x7833, 0x093a, 0x71ca, 0xe6bd, 0x7779, 0x711a, },
        },
        .fixs32 = {
            {0x47753bc7, 0x7422a277, 0x7de005a0, 0xe998b2d7, },
            {0x47753bc7, 0x7422a277, 0x7de005a0, 0xe998b2d7, },
        },
        .fixs64 = {
            {0x4142cb2bc552c9c8, 0xcdbe92152de11f8b, },
            {0x4142cb2bc552c9c8, 0xcdbe92152de11f8b, },
        },
    },
};
struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vadc\n");

    /* int8_t adc */
    test_vadc_vvm_8(vlmax_8 - 1, src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], vma.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vadc_vvm_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vadc_vvm_8_vm(src0[i].fixs8[0], src1[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t adc */
    test_vadc_vvm_16(vlmax_16 - 1, src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], vma.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vadc_vvm_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vadc_vvm_16_vm(src0[i].fixs16[0], src1[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t adc */
    test_vadc_vvm_32(vlmax_32 - 1, src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], vma.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vadc_vvm_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vadc_vvm_32_vm(src0[i].fixs32[0], src1[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t adc */
    test_vadc_vvm_64(vlmax_64 - 1, src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], vma.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vadc_vvm_64_vm(src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vadc_vvm_64_vm(src0[i].fixs64[0], src1[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
