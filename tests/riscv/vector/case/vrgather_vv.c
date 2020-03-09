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

struct rvv_reg src1[] = {
    {
        .fixu64 = {
            {0x0000000000000004, 0x0000000000000001,},
            {0x0000000000000002, 0x0000000000000005,},
        },
        .fixu32 = {
            {0x00000000, 0x00000008, 0x00000002, 0x00000003,},
            {0x00000004, 0x00000005, 0x0000000f, 0x00000007,},
        },
        .fixu16 = {
            {0x0000, 0x0010, 0x0002, 0x0009, 0x0011, 0x0005, 0x0006, 0x0007,},
            {0x0008, 0x0009, 0x00ff, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,},
        },
        .fixu8 = {
            {0x00, 0x01, 0x02, 0xff, 0x04, 0x05, 0x20, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,},
            {0x10, 0x11, 0x12, 0x13, 0xff, 0x15, 0x16, 0x17, 0x18, 0x21, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0x0000000000000000, 0x1111111111111111, },
            {0x3970b5993ab1f212, 0x1111111111111111, },
        },
        .fixs32 = {
            {0xcfe06686, 0x11111111, 0x15fc5221, 0x11111111, },
            {0xcfe06686, 0x11111111, 0x00000000, 0x11111111, },
        },
        .fixs16 = {
            {0xd6d6, 0x1111, 0x10ef, 0x1111, 0x0000, 0x1111, 0x475d, 0x1111, },
            {0xd6d6, 0x1111, 0x0000, 0x1111, 0xa349, 0x1111, 0x475d, 0x1111, },
        },
        .fixs8 = {
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x00, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
            {0xa5, 0x11, 0x8c, 0x11, 0x00, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xc6a630b347e7377b, },
            {0x1111111111111111, 0x0000000000000000, },
        },
        .fixs32 = {
            {0x11111111, 0x00000000, 0x11111111, 0xd6b9745a, },
            {0x11111111, 0x8262f661, 0x11111111, 0xd6b9745a, },
        },
        .fixs16 = {
            {0x1111, 0x0000, 0x1111, 0x51f2, 0x1111, 0x4d3f, 0x1111, 0xa164, },
            {0x1111, 0x51f2, 0x1111, 0x0ea1, 0x1111, 0x4d3f, 0x1111, 0xa164, },
        },
        .fixs8 = {
            {0x11, 0x34, 0x11, 0x00, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x00, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0x0000000000000000, 0xc6a630b347e7377b, },
            {0x3970b5993ab1f212, 0x0000000000000000, },
        },
        .fixs32 = {
            {0xcfe06686, 0x00000000, 0x15fc5221, 0xd6b9745a, },
            {0xcfe06686, 0x8262f661, 0x00000000, 0x00000000, },
        },
        .fixs16 = {
            {0xd6d6, 0x0000, 0x10ef, 0x51f2, 0x0000, 0x4d3f, 0x475d, 0xa164, },
            {0xd6d6, 0x51f2, 0x0000, 0x0ea1, 0xa349, 0x4d3f, 0x475d, 0x0000, },
        },
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x00, 0xcd, 0x75, 0x00, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0x00, 0x75, 0x92, 0x7a, 0x60, 0x00, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x00, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vrgather.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_8(vlmax_8 - 1, src0[i].fixs8[0], src1[i].fixu8[0],
                res.fixs8[0], pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_8_vm(src0[i].fixs8[0], src1[i].fixu8[0],
                res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_8_vm(src0[i].fixs8[0], src1[i].fixu8[0],
                res.fixs8[0], vme.fixs8, pad.fixs8[0]);
        result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_16(vlmax_16 - 1, src0[i].fixs16[0],
                src1[i].fixu16[0], res.fixs16[0], pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_16_vm(src0[i].fixs16[0], src1[i].fixu16[0],
                res.fixs16[0], vmo.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_16_vm(src0[i].fixs16[0], src1[i].fixu16[0],
                res.fixs16[0], vme.fixs16, pad.fixs16[0]);
        result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_32(vlmax_32 - 1, src0[i].fixs32[0],
                src1[i].fixu32[0], res.fixs32[0], pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_32_vm(src0[i].fixs32[0], src1[i].fixu32[0],
                res.fixs32[0], vme.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_32_vm(src0[i].fixs32[0], src1[i].fixu32[0],
                res.fixs32[0], vmo.fixs32, pad.fixs32[0]);
        result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_64(vlmax_64 - 1, src0[i].fixs64[0],
                src1[i].fixu64[0], res.fixs64[0], pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_64_vm(src0[i].fixs64[0], src1[i].fixu64[0],
                res.fixs64[0], vmo.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vrgather_vv_64_vm(src0[i].fixs64[0], src1[i].fixu64[0],
                res.fixs64[0], vme.fixs64, pad.fixs64[0]);
        result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);
    }

    return done_testing();
}
