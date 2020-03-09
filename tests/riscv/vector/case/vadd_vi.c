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
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        },
        .fixs32 = {
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        },
        .fixs16 = {
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        },
        .fixs8 = {
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0x7ff0e92e56fe1979, 0x1111111111111111, },
            {0x7ff0e92e56fe1979, 0x1111111111111111, },
        },
        .fixs32 = {
            {0xc5cf5ebe, 0x11111111, 0xf0bec122, 0x11111111, },
            {0xc5cf5ebe, 0x11111111, 0xf0bec122, 0x11111111, },
        },
        .fixs16 = {
            {0xfe5b, 0x1111, 0xf16b, 0x1111, 0x6f1b, 0x1111, 0xdebe, 0x1111, },
            {0xfe5b, 0x1111, 0xf16b, 0x1111, 0x6f1b, 0x1111, 0xdebe, 0x1111, },
        },
        .fixs8 = {
            {0xc7, 0x11, 0x9e, 0x11, 0xe8, 0x11, 0x4c, 0x11, 0xd2, 0x11, 0xb2, 0x11, 0xeb, 0x11, 0x19, 0x11, },
            {0xc7, 0x11, 0x9e, 0x11, 0xe8, 0x11, 0x4c, 0x11, 0xd2, 0x11, 0xb2, 0x11, 0xeb, 0x11, 0x19, 0x11, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0x1c626bcd2715a040, },
            {0x1111111111111111, 0x1c626bcd2715a040, },
        },
        .fixs32 = {
            {0x11111111, 0x75bc7c35, 0x11111111, 0x683e047a, },
            {0x11111111, 0x75bc7c35, 0x11111111, 0x683e047a, },
        },
        .fixs16 = {
            {0x1111, 0x4b68, 0x1111, 0x08c1, 0x1111, 0x0de0, 0x1111, 0xafc3, },
            {0x1111, 0x4b68, 0x1111, 0x08c1, 0x1111, 0x0de0, 0x1111, 0xafc3, },
        },
        .fixs8 = {
            {0x11, 0x2e, 0x11, 0x43, 0x11, 0x87, 0x11, 0x8e, 0x11, 0x00, 0x11, 0xa3, 0x11, 0x2c, 0x11, 0xce, },
            {0x11, 0x2e, 0x11, 0x43, 0x11, 0x87, 0x11, 0x8e, 0x11, 0x00, 0x11, 0xa3, 0x11, 0x2c, 0x11, 0xce, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0x7ff0e92e56fe195a, 0x1c626bcd2715a021, },
            {0x7ff0e92e56fe195a, 0x1111111111111111, },
        },
        .fixs32 = {
            {0xc5cf5eb4, 0x75bc7c2b, 0xf0bec118, 0x683e0470, },
            {0xc5cf5eb4, 0x75bc7c2b, 0xf0bec118, 0x11111111, },
        },
        .fixs16 = {
            {0xfe51, 0x4b5e, 0xf161, 0x08b7, 0x6f11, 0x0dd6, 0xdeb4, 0xafb9, },
            {0xfe51, 0x4b5e, 0xf161, 0x08b7, 0x6f11, 0x0dd6, 0xdeb4, 0x1111, },
        },
        .fixs8 = {
            {0xbd, 0x24, 0x94, 0x39, 0xde, 0x7d, 0x42, 0x84, 0xc8, 0xf6, 0xa8, 0x99, 0xe1, 0x22, 0x0f, 0xc4, },
            {0xbd, 0x24, 0x94, 0x39, 0xde, 0x7d, 0x42, 0x84, 0xc8, 0xf6, 0xa8, 0x99, 0xe1, 0x22, 0x0f, 0x11, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vadd.vi\n");

    test_vadd_vi_8(vlmax_8 - 1, src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vadd_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vadd_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    test_vadd_vi_16(vlmax_16 - 1, src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vadd_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vadd_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    test_vadd_vi_32(vlmax_32 - 1, src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vadd_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vadd_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    test_vadd_vi_64(vlmax_64 - 1, src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vadd_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vadd_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
