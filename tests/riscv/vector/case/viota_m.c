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
            {0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04,}, 
            {0x05, 0x05, 0x05, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x00, 0x00,}, 
        },
        .fixs16 = {
            {0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0001,},
            {0x0001, 0x0002, 0x0002, 0x0003, 0x0004, 0x0004, 0x0000, 0x0000,},
        },
        .fixs32 = {
            {0x00000000, 0x00000000, 0x00000001, 0x00000002,},
            {0x00000002, 0x00000003, 0x00000000, 0x00000000,},
        },
        .fixs64 = {
            {0x0000000000000000, 0x0000000000000001},
            {0x0000000000000000, 0x0000000000000000},
        },
    },
};

/* vmo */
struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x11, 0x00, 0x11, 0x00, 0x11, 0x01, 0x11, 0x01, 0x11, 0x02, 0x11, 0x02, 0x11, 0x02, 0x11, 0x03, },
            {0x11, 0x04, 0x11, 0x04, 0x11, 0x05, 0x11, 0x05, 0x11, 0x05, 0x11, 0x05, 0x11, 0x05, 0x11, 0x05, },
        },
        .fixs16 = {
            {0x1111, 0x0000, 0x1111, 0x0000, 0x1111, 0x0001, 0x1111, 0x0001, },
            {0x1111, 0x0001, 0x1111, 0x0001, 0x1111, 0x0002, 0x1111, 0x0002, },
        },
        .fixs32 = {
            {0x11111111, 0x00000000, 0x11111111, 0x00000001, },
            {0x11111111, 0x00000001, 0x11111111, 0x00000002, },
        },
        .fixs64 = {
            {0x1111111111111111, 0x00000000000000000, },
            {0x1111111111111111, 0x00000000000000000, },
        },
    },
};

/* vme */
struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x01, 0x11, 0x01, 0x11, },
            {0x01, 0x11, 0x01, 0x11, 0x02, 0x11, 0x02, 0x11, 0x02, 0x11, 0x02, 0x11, 0x02, 0x11, 0x03, 0x11, },
        },
        .fixs16 = {
            {0x0000, 0x1111, 0x0000, 0x1111, 0x0000, 0x1111, 0x0000, 0x1111, },
            {0x0000, 0x1111, 0x0001, 0x1111, 0x0002, 0x1111, 0x0002, 0x1111, },
        },
        .fixs32 = {
            {0x00000000, 0x11111111, 0x00000000, 0x11111111, },
            {0x00000001, 0x11111111, 0x00000002, 0x11111111, },
        },
        .fixs64 = {
            {0x0000000000000000, 0x1111111111111111, },
            {0x0000000000000001, 0x1111111111111111, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn viota.m\n");

    test_viota_m_8(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vlmax_8 - 2);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[0].fixs8[0]);

    test_viota_m_8_vm(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vmo.fixs8);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[0].fixs8[0]);

    test_viota_m_8_vm(src0[i].fixs8[0], res.fixs8[0], pad.fixs8[0], vme.fixs8);
    result_compare_s8_lmul(res.fixs8[0], dst_even[0].fixs8[0]);

    test_viota_m_16(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vlmax_16 - 2);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[0].fixs16[0]);

    test_viota_m_16_vm(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vmo.fixs16);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[0].fixs16[0]);

    test_viota_m_16_vm(src0[i].fixs16[0], res.fixs16[0], pad.fixs16[0], vme.fixs16);
    result_compare_s16_lmul(res.fixs16[0], dst_even[0].fixs16[0]);

    test_viota_m_32(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vlmax_32 - 2);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[0].fixs32[0]);

    test_viota_m_32_vm(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vmo.fixs32);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[0].fixs32[0]);

    test_viota_m_32_vm(src0[i].fixs32[0], res.fixs32[0], pad.fixs32[0], vme.fixs32);
    result_compare_s32_lmul(res.fixs32[0], dst_even[0].fixs32[0]);

    test_viota_m_64(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vlmax_64 - 2);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[0].fixs64[0]);

    test_viota_m_64_vm(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vmo.fixs64);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[0].fixs64[0]);

    test_viota_m_64_vm(src0[i].fixs64[0], res.fixs64[0], pad.fixs64[0], vme.fixs64);
    result_compare_s64_lmul(res.fixs64[0], dst_even[0].fixs64[0]);

    return done_testing();
}
