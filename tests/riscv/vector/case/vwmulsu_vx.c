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
        .fixs16 = {
            {0xcfa8, 0x1ba0, 0xc260, 0x3da0, 0xe4e8, 0x3e28, 0xc590, 0x40d0, },
            {0x3300, 0x0d48, 0x1fe0, 0xc508, 0xfe68, 0xd2d8, 0x1298, 0x1188, },
            {0xcfa8, 0x1ba0, 0xc260, 0x3da0, 0xe4e8, 0x3e28, 0xc590, 0x40d0, },
            {0x3300, 0x0d48, 0x1fe0, 0xc508, 0xfe68, 0xd2d8, 0x1298, 0x0000, },
        },
        .fixs32 = {
            {0xecc79bb0, 0x26430690, 0x07e817f8, 0x06d49c88, },
            {0xd4b5adc8, 0x24115278, 0x21522468, 0xd3d33920, },
            {0xecc79bb0, 0x26430690, 0x07e817f8, 0x06d49c88, },
            {0xd4b5adc8, 0x24115278, 0x21522468, 0x00000000, },
        },
        .fixs64 = {
            {0xeff23efb1642c130, 0xd6189495a4bffa88, },
            {0x07559411a65ef888, 0xf23b0e408577a5d0, },
            {0xeff23efb1642c130, 0xd6189495a4bffa88, },
            {0x07559411a65ef888, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs16 = {
            {0xcfa8, 0x1111, 0xc260, 0x1111, 0xe4e8, 0x1111, 0xc590, 0x1111, },
            {0x3300, 0x1111, 0x1fe0, 0x1111, 0xfe68, 0x1111, 0x1298, 0x1111, },
            {0xcfa8, 0x1111, 0xc260, 0x1111, 0xe4e8, 0x1111, 0xc590, 0x1111, },
            {0x3300, 0x1111, 0x1fe0, 0x1111, 0xfe68, 0x1111, 0x1298, 0x1111, },
        },
        .fixs32 = {
            {0xecc79bb0, 0x11111111, 0x07e817f8, 0x11111111, },
            {0xd4b5adc8, 0x11111111, 0x21522468, 0x11111111, },
            {0xecc79bb0, 0x11111111, 0x07e817f8, 0x11111111, },
            {0xd4b5adc8, 0x11111111, 0x21522468, 0x11111111, },
        },
        .fixs64 = {
            {0xeff23efb1642c130, 0x1111111111111111, },
            {0x07559411a65ef888, 0x1111111111111111, },
            {0xeff23efb1642c130, 0x1111111111111111, },
            {0x07559411a65ef888, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs16 = {
            {0x1111, 0x1ba0, 0x1111, 0x3da0, 0x1111, 0x3e28, 0x1111, 0x40d0, },
            {0x1111, 0x0d48, 0x1111, 0xc508, 0x1111, 0xd2d8, 0x1111, 0x1188, },
            {0x1111, 0x1ba0, 0x1111, 0x3da0, 0x1111, 0x3e28, 0x1111, 0x40d0, },
            {0x1111, 0x0d48, 0x1111, 0xc508, 0x1111, 0xd2d8, 0x1111, 0x1188, },
        },
        .fixs32 = {
            {0x11111111, 0x26430690, 0x11111111, 0x06d49c88, },
            {0x11111111, 0x24115278, 0x11111111, 0xd3d33920, },
            {0x11111111, 0x26430690, 0x11111111, 0x06d49c88, },
            {0x11111111, 0x24115278, 0x11111111, 0xd3d33920, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xd6189495a4bffa88, },
            {0x1111111111111111, 0xf23b0e408577a5d0, },
            {0x1111111111111111, 0xd6189495a4bffa88, },
            {0x1111111111111111, 0xf23b0e408577a5d0, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwmulsu.vx\n");

    /* uint8_t vwmulsu */
    test_vwmulsu_vx_8(vlmax_8 - 1, src0[i].fixs8[0], (uint8_t)src1, res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vwmulsu_vx_8_vm(src0[i].fixs8[0], (uint8_t)src1, res.fixs16[0], vme.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vwmulsu_vx_8_vm(src0[i].fixs8[0], (uint8_t)src1, res.fixs16[0], vmo.fixs8, pad.fixs16[0]);
    result_compare_s16_lmulw(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* uint16_t vwmulsu */
    test_vwmulsu_vx_16(vlmax_16 - 1, src0[i].fixs16[0], (uint16_t)src1, res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vwmulsu_vx_16_vm(src0[i].fixs16[0], (uint16_t)src1, res.fixs32[0], vme.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vwmulsu_vx_16_vm(src0[i].fixs16[0], (uint16_t)src1, res.fixs32[0], vmo.fixs16, pad.fixs32[0]);
    result_compare_s32_lmulw(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* uint32_t vwmulsu */
    test_vwmulsu_vx_32(vlmax_32 - 1, src0[i].fixs32[0], (uint32_t)src1, res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vwmulsu_vx_32_vm(src0[i].fixs32[0], (uint32_t)src1, res.fixs64[0], vme.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vwmulsu_vx_32_vm(src0[i].fixs32[0], (uint32_t)src1, res.fixs64[0], vmo.fixs32, pad.fixs64[0]);
    result_compare_s64_lmulw(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
