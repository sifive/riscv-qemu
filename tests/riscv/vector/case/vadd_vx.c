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

uint64_t src1 = 0xf0bec11d617cafde;

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0x70afaa4bb87ac948, 0x1111111111111111, },
            {0x70afaa4bb87ac948, 0x1111111111111111, },
        },
        .fixs32 = {
            {0x274c0e97, 0x11111111, 0x523b70fb, 0x11111111, },
            {0x274c0e97, 0x11111111, 0x523b70fb, 0x11111111, },
        },
        .fixs16 = {
            {0xae34, 0x1111, 0xa144, 0x1111, 0x1ef4, 0x1111, 0x8e97, 0x1111, },
            {0xae34, 0x1111, 0xa144, 0x1111, 0x1ef4, 0x1111, 0x8e97, 0x1111, },
        },
        .fixs8 = {
            {0xa0, 0x11, 0x77, 0x11, 0xc1, 0x11, 0x25, 0x11, 0xab, 0x11, 0x8b, 0x11, 0xc4, 0x11, 0xf2, 0x11, },
            {0xa0, 0x11, 0x77, 0x11, 0xc1, 0x11, 0x25, 0x11, 0xab, 0x11, 0x8b, 0x11, 0xc4, 0x11, 0xf2, 0x11, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0x0d212cea8892500f, },
            {0x1111111111111111, 0x0d212cea8892500f, },
        },
        .fixs32 = {
            {0x11111111, 0xd7392c0e, 0x11111111, 0xc9bab453, },
            {0x11111111, 0xd7392c0e, 0x11111111, 0xc9bab453, },
        },
        .fixs16 = {
            {0x1111, 0xfb41, 0x1111, 0xb89a, 0x1111, 0xbdb9, 0x1111, 0x5f9c, },
            {0x1111, 0xfb41, 0x1111, 0xb89a, 0x1111, 0xbdb9, 0x1111, 0x5f9c, },
        },
        .fixs8 = {
            {0x11, 0x07, 0x11, 0x1c, 0x11, 0x60, 0x11, 0x67, 0x11, 0xd9, 0x11, 0x7c, 0x11, 0x05, 0x11, 0xa7, },
            {0x11, 0x07, 0x11, 0x1c, 0x11, 0x60, 0x11, 0x67, 0x11, 0xd9, 0x11, 0x7c, 0x11, 0x05, 0x11, 0xa7, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0x70afaa4bb87ac948, 0x0d212cea8892500f, },
            {0x70afaa4bb87ac948, 0x1111111111111111, },
        },
        .fixs32 = {
            {0x274c0e97, 0xd7392c0e, 0x523b70fb, 0xc9bab453, },
            {0x274c0e97, 0xd7392c0e, 0x523b70fb, 0x11111111, },
        },
        .fixs16 = {
            {0xae34, 0xfb41, 0xa144, 0xb89a, 0x1ef4, 0xbdb9, 0x8e97, 0x5f9c, },
            {0xae34, 0xfb41, 0xa144, 0xb89a, 0x1ef4, 0xbdb9, 0x8e97, 0x1111, },
        },
        .fixs8 = {
            {0xa0, 0x07, 0x77, 0x1c, 0xc1, 0x60, 0x25, 0x67, 0xab, 0xd9, 0x8b, 0x7c, 0xc4, 0x05, 0xf2, 0xa7, },
            {0xa0, 0x07, 0x77, 0x1c, 0xc1, 0x60, 0x25, 0x67, 0xab, 0xd9, 0x8b, 0x7c, 0xc4, 0x05, 0xf2, 0x11, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vadd.vx\n");

    test_vadd_vx_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs8[0], pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vadd_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vadd_vx_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    test_vadd_vx_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs16[0], pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vadd_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vadd_vx_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    test_vadd_vx_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs32[0], pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vadd_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vadd_vx_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    test_vadd_vx_64(vlmax_64 - 1, src0[i].fixs64[0], src1, res.fixs64[0], pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vadd_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vadd_vx_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
