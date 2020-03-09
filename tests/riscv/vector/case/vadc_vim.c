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
            {0xb5, 0x44, 0x9c, 0x84, 0xdd, 0x85, 0xa2, 0x8a, 0x70, 0x29, 0x4c, 0xa1, 0x0d, 0xbb, 0x33, 0x31, },
            {0xb5, 0x44, 0x9c, 0x84, 0xdd, 0x85, 0xa2, 0x8a, 0x70, 0x29, 0x4c, 0xa1, 0x0d, 0xbb, 0x33, 0x00, },
        },
        .fixs16 = {
            {0xd6e6, 0x5202, 0x10ff, 0x0eb1, 0xa359, 0x4d4f, 0x476d, 0xa174, },
            {0xd6e6, 0x5202, 0x10ff, 0x0eb1, 0xa359, 0x4d4f, 0x476d, 0x0000, },
        },
        .fixs32 = {
            {0xcfe06696, 0x8262f671, 0x15fc5231, 0xd6b9746a, },
            {0xcfe06696, 0x8262f671, 0x15fc5231, 0x00000000, },
        },
        .fixs64 = {
            {0x3970b5993ab1f222, 0xc6a630b347e7378b, },
            {0x3970b5993ab1f222, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0x96, 0x24, 0x7d, 0x64, 0xbe, 0x65, 0x83, 0x6a, 0x51, 0x09, 0x2d, 0x81, 0xee, 0x9b, 0x14, 0x11, },
            {0x96, 0x24, 0x7d, 0x64, 0xbe, 0x65, 0x83, 0x6a, 0x51, 0x09, 0x2d, 0x81, 0xee, 0x9b, 0x14, 0x11, },
        },
        .fixs16 = {
            {0xd6c7, 0x51e2, 0x10e0, 0x0e91, 0xa33a, 0x4d2f, 0x474e, 0xa154, },
            {0xd6c7, 0x51e2, 0x10e0, 0x0e91, 0xa33a, 0x4d2f, 0x474e, 0xa154, },
        },
        .fixs32 = {
            {0xcfe06677, 0x8262f651, 0x15fc5212, 0xd6b9744a, },
            {0xcfe06677, 0x8262f651, 0x15fc5212, 0xd6b9744a, },
        },
        .fixs64 = {
            {0x3970b5993ab1f203, 0xc6a630b347e7376b, },
            {0x3970b5993ab1f203, 0xc6a630b347e7376b, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x95, 0x25, 0x7c, 0x65, 0xbd, 0x66, 0x82, 0x6b, 0x50, 0x0a, 0x2c, 0x82, 0xed, 0x9c, 0x13, 0x12, },
            {0x95, 0x25, 0x7c, 0x65, 0xbd, 0x66, 0x82, 0x6b, 0x50, 0x0a, 0x2c, 0x82, 0xed, 0x9c, 0x13, 0x12, },
        },
        .fixs16 = {
            {0xd6c6, 0x51e3, 0x10df, 0x0e92, 0xa339, 0x4d30, 0x474d, 0xa155, },
            {0xd6c6, 0x51e3, 0x10df, 0x0e92, 0xa339, 0x4d30, 0x474d, 0xa155, },
        },
        .fixs32 = {
            {0xcfe06676, 0x8262f652, 0x15fc5211, 0xd6b9744b, },
            {0xcfe06676, 0x8262f652, 0x15fc5211, 0xd6b9744b, },
        },
        .fixs64 = {
            {0x3970b5993ab1f202, 0xc6a630b347e7376c, },
            {0x3970b5993ab1f202, 0xc6a630b347e7376c, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vadc.vim\n");

    /* int8_t adc */
    test_vadc_vim_8(vlmax_8 - 1, src0[i].fixs8[0], res.fixs8[0], vma.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vadc_vim_8_vm(src0[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vadc_vim_8_vm(src0[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t adc */
    test_vadc_vim_16(vlmax_16 - 1, src0[i].fixs16[0], res.fixs16[0], vma.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vadc_vim_16_vm(src0[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vadc_vim_16_vm(src0[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t adc */
    test_vadc_vim_32(vlmax_32 - 1, src0[i].fixs32[0], res.fixs32[0], vma.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vadc_vim_32_vm(src0[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vadc_vim_32_vm(src0[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t adc */
    test_vadc_vim_64(vlmax_64 - 1, src0[i].fixs64[0], res.fixs64[0], vma.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vadc_vim_64_vm(src0[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vadc_vim_64_vm(src0[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
