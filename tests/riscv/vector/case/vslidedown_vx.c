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
 * Lesser General Public License for more details.
 *
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
            {0xcfe06686, 0x80000001, 0x15fc5221, 0x7fff745a, },
            {0xcfe06686, 0x80000001, 0x15fc5221, 0x7fff745a, },
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

uint32_t src1_s8  = 0x8;
uint32_t src1_s16 = 0x4;
uint32_t src1_s32 = 0x2;
uint32_t src1_s64 = 0x1;

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0xc6a630b347e7377b, 0x3970b5993ab1f212,},
            {0xc6a630b347e7377b, 0x0000000000000000,},
        },
        .fixs32 = {
            {0x15fc5221, 0x7fff745a, 0xcfe06686, 0x80000001, },
            {0x15fc5221, 0x7fff745a, 0x00000000, 0x00000000, },
        },
        .fixs16 = {
            {0xa349, 0x4d3f, 0x475d, 0xa164, 0xd6d6, 0x51f2, 0x10ef, 0x0ea1,},
            {0xa349, 0x4d3f, 0x475d, 0xa164, 0x0000, 0x0000, 0x0000, 0x0000,},
        },
        .fixs8 = {
            {0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, 0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a,},
            {0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0x3970b5993ab1f212,},
            {0x1111111111111111, 0x0000000000000000,},
        },
        .fixs32 = {
            {0x11111111, 0x7fff745a, 0x11111111, 0x80000001, },
            {0x11111111, 0x7fff745a, 0x11111111, 0x00000000, },
        },
        .fixs16 = {
            {0x1111, 0x4d3f, 0x1111, 0xa164, 0x1111, 0x51f2, 0x1111, 0x0ea1,},
            {0x1111, 0x4d3f, 0x1111, 0xa164, 0x1111, 0x0000, 0x1111, 0x0000,},
        },
        .fixs8 = {
            {0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, 0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a,},
            {0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00,},
        },
    }
};

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0xc6a630b347e7377b, 0x1111111111111111,},
            {0xc6a630b347e7377b, 0x1111111111111111,},
        },
        .fixs32 = {
            {0x15fc5221, 0x11111111, 0xcfe06686, 0x11111111, },
            {0x15fc5221, 0x11111111, 0x00000000, 0x11111111, },
        },
        .fixs16 = {
            {0xa349, 0x1111, 0x475d, 0x1111, 0xd6d6, 0x1111, 0x10ef, 0x1111,},
            {0xa349, 0x1111, 0x475d, 0x1111, 0x0000, 0x1111, 0x0000, 0x1111,},
        },
        .fixs8 = {
            {0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, 0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11,},
            {0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11,},
        },
    },

};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vslidedown.vx\n");

   for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_8(vlmax_8 - 1, src0[0].fixs8[0], src1_s8,
                res.fixs8[0], pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_8_vm(src0[0].fixs8[0], src1_s8, res.fixs8[0],
                vmo.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_8_vm(src0[0].fixs8[0], src1_s8, res.fixs8[0],
                vme.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_16(vlmax_16 - 1, src0[0].fixs16[0], src1_s16,
                res.fixs16[0], pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_16_vm(src0[0].fixs16[0], src1_s16, res.fixs16[0],
                vmo.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_16_vm(src0[0].fixs16[0], src1_s16, res.fixs16[0],
                vme.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_32(vlmax_32 - 1, src0[0].fixs32[0], src1_s32,
                res.fixs32[0], pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_32_vm(src0[0].fixs32[0], src1_s32, res.fixs32[0],
                vme.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_32_vm(src0[0].fixs32[0], src1_s32, res.fixs32[0],
                vmo.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(dst_vl) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_64(vlmax_64 - 1, src0[0].fixs64[0], src1_s64,
                res.fixs64[0], pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(dst_odd) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_64_vm(src0[0].fixs64[0], src1_s64, res.fixs64[0],
                vmo.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(dst_even) / sizeof(struct rvv_reg); i++) {
        test_vslidedown_vx_64_vm(src0[0].fixs64[0], src1_s64, res.fixs64[0],
                vme.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);
    }

    return done_testing();
}
