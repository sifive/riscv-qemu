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

int64_t src1 = 0x1122334455667788;
struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0xa8, 0xa0, 0x60, 0xa0, 0xe8, 0x28, 0x90, 0xd0, 0x00, 0x48, 0xe0, 0x08, 0x68, 0xd8, 0x98, 0x88, },
            {0xa8, 0xa0, 0x60, 0xa0, 0xe8, 0x28, 0x90, 0xd0, 0x00, 0x48, 0xe0, 0x08, 0x68, 0xd8, 0x98, 0x00, },
        },
        .fixs16 = {
            {0x9bb0, 0x0690, 0x17f8, 0x9c88, 0xadc8, 0x5278, 0x2468, 0x3920, },
            {0x9bb0, 0x0690, 0x17f8, 0x9c88, 0xadc8, 0x5278, 0x2468, 0x0000, },
        },
        .fixs32 = {
            {0x1642c130, 0xa4bffa88, 0xa65ef888, 0x8577a5d0, },
            {0x1642c130, 0xa4bffa88, 0xa65ef888, 0x00000000, },
        },
        .fixs64 = {
            {0x86b70ebe533af790, 0x6a09dee29fa1a658, },
            {0x86b70ebe533af790, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0xa8, 0x11, 0x60, 0x11, 0xe8, 0x11, 0x90, 0x11, 0x00, 0x11, 0xe0, 0x11, 0x68, 0x11, 0x98, 0x11, },
            {0xa8, 0x11, 0x60, 0x11, 0xe8, 0x11, 0x90, 0x11, 0x00, 0x11, 0xe0, 0x11, 0x68, 0x11, 0x98, 0x11, },
        },
        .fixs16 = {
            {0x9bb0, 0x1111, 0x17f8, 0x1111, 0xadc8, 0x1111, 0x2468, 0x1111, },
            {0x9bb0, 0x1111, 0x17f8, 0x1111, 0xadc8, 0x1111, 0x2468, 0x1111, },
        },
        .fixs32 = {
            {0x1642c130, 0x11111111, 0xa65ef888, 0x11111111, },
            {0x1642c130, 0x11111111, 0xa65ef888, 0x11111111, },
        },
        .fixs64 = {
            {0x86b70ebe533af790, 0x1111111111111111, },
            {0x86b70ebe533af790, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0xa0, 0x11, 0xa0, 0x11, 0x28, 0x11, 0xd0, 0x11, 0x48, 0x11, 0x08, 0x11, 0xd8, 0x11, 0x88, },
            {0x11, 0xa0, 0x11, 0xa0, 0x11, 0x28, 0x11, 0xd0, 0x11, 0x48, 0x11, 0x08, 0x11, 0xd8, 0x11, 0x88, },
        },
        .fixs16 = {
            {0x1111, 0x0690, 0x1111, 0x9c88, 0x1111, 0x5278, 0x1111, 0x3920, },
            {0x1111, 0x0690, 0x1111, 0x9c88, 0x1111, 0x5278, 0x1111, 0x3920, },
        },
        .fixs32 = {
            {0x11111111, 0xa4bffa88, 0x11111111, 0x8577a5d0, },
            {0x11111111, 0xa4bffa88, 0x11111111, 0x8577a5d0, },
        },
        .fixs64 = {
            {0x1111111111111111, 0x6a09dee29fa1a658, },
            {0x1111111111111111, 0x6a09dee29fa1a658, },
        },
    },
};

struct rvv_reg res;
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmul.vx\n");

    /* int8_t vmul */
    test_vmul_vx_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs8[0], vma.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vmul_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vmul_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t vmul */
    test_vmul_vx_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs16[0], vma.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vmul_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vmul_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t vmul */
    test_vmul_vx_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs32[0], vma.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vmul_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vmul_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t vmul */
    test_vmul_vx_64(vlmax_64 - 1, src0[i].fixs64[0], src1, res.fixs64[0], vma.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vmul_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vmul_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
