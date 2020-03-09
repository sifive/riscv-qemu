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
        .fixu64 = {
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
            {0x7ff0e92e56fe196a, 0x1c626bcd2715a031, },
        },
        .fixu32 = {
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
            {0xc5cf5eb9, 0x75bc7c30, 0xf0bec11d, 0x683e0475, },
        },
        .fixu16 = {
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
            {0xfe56, 0x4b63, 0xf166, 0x08bc, 0x6f16, 0x0ddb, 0xdeb9, 0xafbe, },
        },
        .fixu8 = {
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .fixu64 = {
            {0xbc73041be547e732, 0x0afd8a490d762d5e, },
            {0xbc73041be547e732, 0x0afd8a490d762d5e, },
        },
        .fixu32 = {
            {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
            {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
        },
        .fixu16 = {
            {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
            {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
        },
        .fixu8 = {
            {0x1c, 0x42, 0xd3, 0x53, 0x94, 0x57, 0x7b, 0xa3, 0xae, 0x96, 0x41, 0x28, 0x3a, 0x59, 0x9b, 0x70, },
            {0x1c, 0x42, 0xd3, 0x53, 0x94, 0x57, 0x7b, 0xa3, 0xae, 0x96, 0x41, 0x28, 0x3a, 0x59, 0x9b, 0x70, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixu64 = {
            {0xfff3ed3ff7ffff7a,},
        },
        .fixu32 = {
            {0xefdfffff,},
        },
        .fixu16 = {
            {0xffff},
        },
        .fixu8 = {
            {0xff},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixu64 = {
            {0x7ffdeb6f5ffe3d7e,},
        },
        .fixu32 = {
            {0xffffffff,},
        },
        .fixu16 = {
            {0xff7f,},
        },
        .fixu8 = {
            {0xff,},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixu64 = {
            {0xffffef7fffffff7e},
        },
        .fixu32 = {
            {0xffffffff},
        },
        .fixu16 = {
            {0xffff,},
        },
        .fixu8 = {
            {0xff,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vredor.vs\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_8(vlmax_8 - 1, src0[i].fixu8[0], src1[i].fixu8[0],
                res.fixu8[0], pad.fixu8[0]);
        result_compare_u8(res.fixu8[0], dst_vl[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_8_vm(src0[i].fixu8[0], src1[i].fixu8[0],
                res.fixu8[0], vmo.fixu8, pad.fixu8[0]);
        result_compare_u8(res.fixu8[0], dst_odd[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_8_vm(src0[i].fixu8[0], src1[i].fixu8[0],
                res.fixu8[0], vme.fixu8, pad.fixu8[0]);
        result_compare_u8(res.fixu8[0], dst_even[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_16(vlmax_16 - 1, src0[i].fixu16[0],
                src1[i].fixu16[0], res.fixu16[0], pad.fixu16[0]);
        result_compare_u16(res.fixu16[0], dst_vl[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_16_vm(src0[i].fixu16[0], src1[i].fixu16[0],
                res.fixu16[0], vmo.fixu16, pad.fixu16[0]);
        result_compare_u16(res.fixu16[0], dst_odd[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_16_vm(src0[i].fixu16[0], src1[i].fixu16[0],
                res.fixu16[0], vme.fixu16, pad.fixu16[0]);
        result_compare_u16(res.fixu16[0], dst_even[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_32(vlmax_32 - 1, src0[i].fixu32[0],
                src1[i].fixu32[0], res.fixu32[0], pad.fixu32[0]);
        result_compare_u32(res.fixu32[0], dst_vl[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_32_vm(src0[i].fixu32[0], src1[i].fixu32[0],
                res.fixu32[0], vme.fixu32, pad.fixu32[0]);
        result_compare_u32(res.fixu32[0], dst_even[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_32_vm(src0[i].fixu32[0], src1[i].fixu32[0],
                res.fixu32[0], vmo.fixu32, pad.fixu32[0]);
        result_compare_u32(res.fixu32[0], dst_odd[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_64(vlmax_64 - 1, src0[i].fixu64[0],
                src1[i].fixu64[0], res.fixu64[0], pad.fixu64);
        result_compare_u64(res.fixu64[0], dst_vl[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_64_vm(src0[i].fixu64[0], src1[i].fixu64[0],
                res.fixu64[0], vmo.fixu64, pad.fixu64[0]);
        result_compare_u64(res.fixu64[0], dst_odd[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vredor_vs_64_vm(src0[i].fixu64[0], src1[i].fixu64[0],
                res.fixu64[0], vme.fixu64, pad.fixu64[0]);
        result_compare_u64(res.fixu64[0], dst_even[i].fixu64[0]);
    }

    return done_testing();
}
