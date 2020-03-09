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

uint64_t src1 = 0x1122334455667788;
struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0x2e, 0xbd, 0x15, 0xfd, 0x56, 0xfe, 0x1b, 0x03, 0xe9, 0xa2, 0xc5, 0x1a, 0x86, 0x34, 0xac, 0xaa, },
            {0x2e, 0xbd, 0x15, 0xfd, 0x56, 0xfe, 0x1b, 0x03, 0xe9, 0xa2, 0xc5, 0x1a, 0x86, 0x34, 0xac, 0x00, },
        },
        .fixs16 = {
            {0x4e5f, 0xc97b, 0x8878, 0x862a, 0x1ad2, 0xc4c8, 0xbee6, 0x18ed, },
            {0x4e5f, 0xc97b, 0x8878, 0x862a, 0x1ad2, 0xc4c8, 0xbee6, 0x0000, },
        },
        .fixs32 = {
            {0x2546de0f, 0xd7c96dea, 0x6b62c9aa, 0x2c1febe3, },
            {0x2546de0f, 0xd7c96dea, 0x6b62c9aa, 0x00000000, },
        },
        .fixs64 = {
            {0x4a92e8dd9018699b, 0xd7c863f79d4daf04, },
            {0x4a92e8dd9018699b, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0x2e, 0xbc, 0x15, 0xfc, 0x56, 0xfd, 0x1b, 0x02, 0xe9, 0xa1, 0xc5, 0x19, 0x86, 0x33, 0xac, 0xa9, },
            {0x2e, 0xbc, 0x15, 0xfc, 0x56, 0xfd, 0x1b, 0x02, 0xe9, 0xa1, 0xc5, 0x19, 0x86, 0x33, 0xac, 0xa9, },
        },
        .fixs16 = {
            {0x4e5f, 0xc97a, 0x8878, 0x8629, 0x1ad2, 0xc4c7, 0xbee6, 0x18ec, },
            {0x4e5f, 0xc97a, 0x8878, 0x8629, 0x1ad2, 0xc4c7, 0xbee6, 0x18ec, },
        },
        .fixs32 = {
            {0x2546de0f, 0xd7c96de9, 0x6b62c9aa, 0x2c1febe2, },
            {0x2546de0f, 0xd7c96de9, 0x6b62c9aa, 0x2c1febe2, },
        },
        .fixs64 = {
            {0x4a92e8dd9018699b, 0xd7c863f79d4daf03, },
            {0x4a92e8dd9018699b, 0xd7c863f79d4daf03, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x2d, 0xbd, 0x14, 0xfd, 0x55, 0xfe, 0x1a, 0x03, 0xe8, 0xa2, 0xc4, 0x1a, 0x85, 0x34, 0xab, 0xaa, },
            {0x2d, 0xbd, 0x14, 0xfd, 0x55, 0xfe, 0x1a, 0x03, 0xe8, 0xa2, 0xc4, 0x1a, 0x85, 0x34, 0xab, 0xaa, },
        },
        .fixs16 = {
            {0x4e5e, 0xc97b, 0x8877, 0x862a, 0x1ad1, 0xc4c8, 0xbee5, 0x18ed, },
            {0x4e5e, 0xc97b, 0x8877, 0x862a, 0x1ad1, 0xc4c8, 0xbee5, 0x18ed, },
        },
        .fixs32 = {
            {0x2546de0e, 0xd7c96dea, 0x6b62c9a9, 0x2c1febe3, },
            {0x2546de0e, 0xd7c96dea, 0x6b62c9a9, 0x2c1febe3, },
        },
        .fixs64 = {
            {0x4a92e8dd9018699a, 0xd7c863f79d4daf04, },
            {0x4a92e8dd9018699a, 0xd7c863f79d4daf04, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vadc.vxm\n");

    /* int8_t adc */
    test_vadc_vxm_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs8[0], vma.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vadc_vxm_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vadc_vxm_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t adc */
    test_vadc_vxm_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs16[0], vma.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vadc_vxm_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vadc_vxm_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t adc */
    test_vadc_vxm_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs32[0], vma.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vadc_vxm_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vadc_vxm_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t adc */
    test_vadc_vxm_64(vlmax_64 - 1, src0[i].fixs64[0], src1, res.fixs64[0], vma.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vadc_vxm_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vadc_vxm_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
