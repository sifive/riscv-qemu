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
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x00, },
        },
        .fixs16 = {
            {0xffd6, 0x0051, 0x0010, 0x000e, 0xffa3, 0x004d, 0x0047, 0xffa1, },
            {0xffd6, 0x0051, 0x0010, 0x000e, 0xffa3, 0x004d, 0x0047, 0x0000, },
        },
        .fixs32 = {
            {0xffcfe066, 0xff8262f6, 0x0015fc52, 0xffd6b974, },
            {0xffcfe066, 0xff8262f6, 0x0015fc52, 0x00000000, },
        },
        .fixs64 = {
            {0x003970b5993ab1f2, 0xffc6a630b347e737, },
            {0x003970b5993ab1f2, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
        },
        .fixs16 = {
            {0xffd6, 0x1111, 0x0010, 0x1111, 0xffa3, 0x1111, 0x0047, 0x1111, },
            {0xffd6, 0x1111, 0x0010, 0x1111, 0xffa3, 0x1111, 0x0047, 0x1111, },
        },
        .fixs32 = {
            {0xffcfe066, 0x11111111, 0x0015fc52, 0x11111111, },
            {0xffcfe066, 0x11111111, 0x0015fc52, 0x11111111, },
        },
        .fixs64 = {
            {0x003970b5993ab1f2, 0x1111111111111111, },
            {0x003970b5993ab1f2, 0x1111111111111111, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
        },
        .fixs16 = {
            {0x1111, 0x0051, 0x1111, 0x000e, 0x1111, 0x004d, 0x1111, 0xffa1, },
            {0x1111, 0x0051, 0x1111, 0x000e, 0x1111, 0x004d, 0x1111, 0xffa1, },
        },
        .fixs32 = {
            {0x11111111, 0xff8262f6, 0x11111111, 0xffd6b974, },
            {0x11111111, 0xff8262f6, 0x11111111, 0xffd6b974, },
        },
        .fixs64 = {
            {0x1111111111111111, 0xffc6a630b347e737, },
            {0x1111111111111111, 0xffc6a630b347e737, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsra.vx\n");

    test_vsra_vx_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vsra_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vsra_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    test_vsra_vx_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs16[0], pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vsra_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vsra_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    test_vsra_vx_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs32[0], pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vsra_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vsra_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    test_vsra_vx_64(vlmax_64 - 1, src0[i].fixs64[0], src1, res.fixs64[0], pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vsra_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vsra_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
