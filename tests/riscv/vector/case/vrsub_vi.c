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
            {0x800f16d1a901e6a5, 0x1111111111111111,  },
            {0x800f16d1a901e6a5, 0x1111111111111111,  },
        },
        .fixs32 = {
            {0x3a30a14c, 0x11111111, 0x0f413ee8, 0x11111111, },
            {0x3a30a14c, 0x11111111, 0x0f413ee8, 0x11111111, },
        },
        .fixs16 = {
            {0x01af, 0x1111, 0x0e9f, 0x1111, 0x90ef, 0x1111, 0x214c, 0x1111, },
            {0x01af, 0x1111, 0x0e9f, 0x1111, 0x90ef, 0x1111, 0x214c, 0x1111, },
        },
        .fixs8 = {
            {0x43, 0x11, 0x6c, 0x11, 0x22, 0x11, 0xbe, 0x11, 0x38, 0x11, 0x58, 0x11, 0x1f, 0x11, 0xf1, 0x11, },
            {0x43, 0x11, 0x6c, 0x11, 0x22, 0x11, 0xbe, 0x11, 0x38, 0x11, 0x58, 0x11, 0x1f, 0x11, 0xf1, 0x11, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xe39d9432d8ea5fde, },
            {0x1111111111111111, 0xe39d9432d8ea5fde, },
        },
        .fixs32 = {
            {0x11111111, 0x8a4383d5, 0x11111111, 0x97c1fb90, },
            {0x11111111, 0x8a4383d5, 0x11111111, 0x97c1fb90, },
        },
        .fixs16 = {
            {0x1111, 0xb4a2, 0x1111, 0xf749, 0x1111, 0xf22a, 0x1111, 0x5047, },
            {0x1111, 0xb4a2, 0x1111, 0xf749, 0x1111, 0xf22a, 0x1111, 0x5047, },
        },
        .fixs8 = {
            {0x11, 0xdc, 0x11, 0xc7, 0x11, 0x83, 0x11, 0x7c, 0x11, 0x0a, 0x11, 0x67, 0x11, 0xde, 0x11, 0x3c, },
            {0x11, 0xdc, 0x11, 0xc7, 0x11, 0x83, 0x11, 0x7c, 0x11, 0x0a, 0x11, 0x67, 0x11, 0xde, 0x11, 0x3c, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0x800f16d1a901e686, 0xe39d9432d8ea5fbf, },
            {0x800f16d1a901e686, 0x1111111111111111, },
        },
        .fixs32 = {
            {0x3a30a142, 0x8a4383cb, 0x0f413ede, 0x97c1fb86, },
            {0x3a30a142, 0x8a4383cb, 0x0f413ede, 0x11111111, },
        },
        .fixs16 = {
            {0x01a5, 0xb498, 0x0e95, 0xf73f, 0x90e5, 0xf220, 0x2142, 0x503d, },
            {0x01a5, 0xb498, 0x0e95, 0xf73f, 0x90e5, 0xf220, 0x2142, 0x1111, },
        },
        .fixs8 = {
            {0x39, 0xd2, 0x62, 0xbd, 0x18, 0x79, 0xb4, 0x72, 0x2e, 0x00, 0x4e, 0x5d, 0x15, 0xd4, 0xe7, 0x32, },
            {0x39, 0xd2, 0x62, 0xbd, 0x18, 0x79, 0xb4, 0x72, 0x2e, 0x00, 0x4e, 0x5d, 0x15, 0xd4, 0xe7, 0x11, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrsub.vi\n");

    test_vrsub_vi_8(vlmax_8 - 1, src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vrsub_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vrsub_vi_8_vm(src0[i].fixs8[0], res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    test_vrsub_vi_16(vlmax_16 - 1, src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vrsub_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vme.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vrsub_vi_16_vm(src0[i].fixs16[0], res.fixs16[0], vmo.fixs16, pad.fixs16[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    test_vrsub_vi_32(vlmax_32 - 1, src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vrsub_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vme.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vrsub_vi_32_vm(src0[i].fixs32[0], res.fixs32[0], vmo.fixs32, pad.fixs32[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    test_vrsub_vi_64(vlmax_64 - 1, src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vrsub_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vme.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vrsub_vi_64_vm(src0[i].fixs64[0], res.fixs64[0], vmo.fixs64, pad.fixs64[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
