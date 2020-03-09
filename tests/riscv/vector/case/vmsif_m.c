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
        .fixs8 = {
            {0x00, 0x10, 0x00, 0x10, 0x00, 0x01, 0x10, 0x10, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, },
        },
        .fixs16 = {
            {0x0000, 0x0100, 0x0000, 0x0000, 0x0001, 0x0101, 0x0000, 0x0000, },
        },
        .fixs32 = {
            {0x00010000, 0x00000001, 0x00010001, 0x00010000, },
        },
        .fixs64 = {
            {0x0000000000000001, 0x0000000100000000, },
        },
    },
};


struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, 
        },
        .fixs16 = {
            {0x0101, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,},
        },
        .fixs32 = {
            {0x00010001, 0x00000000, 0x00000000, 0x00000000,},
        },
        .fixs64 = {
            {0x0000000000000001, 0x0000000000000000},
        },
    },
};

/* vmo */
struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, },
        },
        .fixs16 = {
            {0x0111, 0x0111, 0x0011, 0x0011, 0x0011, 0x0011, 0x0011, 0x0011, },
        },
        .fixs32 = {
            {0x00011111, 0x00001111, 0x00001111, 0x00001111, },
        },
        .fixs64 = {
            {0x0000000111111111, 0x00000000111111111, },
        },
    },
};

/* vme */
struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, },
        },
        .fixs16 = {
            {0x1101, 0x1101, 0x1101, 0x1101, 0x1101, 0x1100, 0x1100, 0x1100, },
        },
        .fixs32 = {
            {0x11110001, 0x11110001, 0x11110000, 0x11110000, },
        },
        .fixs64 = {
            {0x1111111100000001, 0x1111111100000000, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vmsif.m\n");

    test_vmsif_m_8(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vlmax_8 - 2);
    result_compare_s8(res.fixs8[0], dst_vl[0].fixs8[0]);

    test_vmsif_m_8_vm(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vmo.fixs8);
    result_compare_s8(res.fixs8[0], dst_odd[0].fixs8[0]);

    test_vmsif_m_8_vm(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vme.fixs8);
    result_compare_s8(res.fixs8[0], dst_even[0].fixs8[0]);

    test_vmsif_m_16(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vlmax_16 - 2);
    result_compare_s16(res.fixs16[0], dst_vl[0].fixs16[0]);

    test_vmsif_m_16_vm(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vmo.fixs16);
    result_compare_s16(res.fixs16[0], dst_odd[0].fixs16[0]);

    test_vmsif_m_16_vm(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vme.fixs16);
    result_compare_s16(res.fixs16[0], dst_even[0].fixs16[0]);

    test_vmsif_m_32(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vlmax_32 - 2);
    result_compare_s32(res.fixs32[0], dst_vl[0].fixs32[0]);

    test_vmsif_m_32_vm(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vmo.fixs32);
    result_compare_s32(res.fixs32[0], dst_odd[0].fixs32[0]);

    test_vmsif_m_32_vm(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vme.fixs32);
    result_compare_s32(res.fixs32[0], dst_even[0].fixs32[0]);

    test_vmsif_m_64(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vlmax_64 - 2);
    result_compare_s64(res.fixs64[0], dst_vl[0].fixs64[0]);

    test_vmsif_m_64_vm(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vmo.fixs64);
    result_compare_s64(res.fixs64[0], dst_odd[0].fixs64[0]);

    test_vmsif_m_64_vm(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vme.fixs64);
    result_compare_s64(res.fixs64[0], dst_even[0].fixs64[0]);

    return done_testing();
}
