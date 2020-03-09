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

struct rvv_reg dst_rnu[] = {
    {
        .fixu64 = {
            {0x0000000000001ffc, 0x000000007189af35,},
            {0x0000000000001ffc, 0x0000000000000000,},
        },
        .fixu32 = {
            {0x00000003, 0x00000001, 0x00000004, 0x00000002,},
            {0x00000003, 0x00000001, 0x00000004, 0x00000000,},
        },
        .fixu16 = {
            {0x7f2b, 0x025b, 0x0008, 0x0023, 0x378b, 0x0377, 0x37ae, 0x00b0,},
            {0x7f2b, 0x025b, 0x0008, 0x0023, 0x378b, 0x0377, 0x37ae, 0x0000,},
        },
        .fixu8 = {
            {0x0c, 0x0a, 0x13, 0x08, 0x0e, 0x01, 0x09, 0x11, 0x03, 0x04, 0x57, 0x9e, 0x3a, 0x14, 0x03, 0xc9,},
            {0x0c, 0x0a, 0x13, 0x08, 0x0e, 0x01, 0x09, 0x11, 0x03, 0x04, 0x57, 0x9e, 0x3a, 0x14, 0x03, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixu64 = {
            {0x1111111111111111, 0x000000007189af35,},
            {0x1111111111111111, 0x000000007189af35,},
        },
        .fixu32 = {
            {0x11111111, 0x00000001, 0x11111111, 0x00000002,},
            {0x11111111, 0x00000001, 0x11111111, 0x00000002,},
        },
        .fixu16 = {
            {0x1111, 0x025b, 0x1111, 0x0023, 0x1111, 0x0377, 0x1111, 0x00b0,}, 
            {0x1111, 0x025b, 0x1111, 0x0023, 0x1111, 0x0377, 0x1111, 0x00b0,}, 
        },
        .fixu8 = {
            {0x11, 0x0a, 0x11, 0x08, 0x11, 0x01, 0x11, 0x11, 0x11, 0x04, 0x11, 0x9e, 0x11, 0x14, 0x11, 0xc9,},
            {0x11, 0x0a, 0x11, 0x08, 0x11, 0x01, 0x11, 0x11, 0x11, 0x04, 0x11, 0x9e, 0x11, 0x14, 0x11, 0xc9,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixu64 = {
            {0x0000000000001ffc, 0x1111111111111111,},
            {0x0000000000001ffc, 0x1111111111111111,},
        },
        .fixu32 = {
            {0x00000003, 0x11111111, 0x00000003, 0x11111111,},
            {0x00000003, 0x11111111, 0x00000003, 0x11111111,},
        },
        .fixu16 = {
            {0x7f2b, 0x1111, 0x0007, 0x1111, 0x378b, 0x1111, 0x37ae, 0x1111,},
            {0x7f2b, 0x1111, 0x0007, 0x1111, 0x378b, 0x1111, 0x37ae, 0x1111,},
        },
        .fixu8 = {
            {0x0c, 0x11, 0x13, 0x11, 0x0e, 0x11, 0x08, 0x11, 0x03, 0x11, 0x56, 0x11, 0x39, 0x11, 0x02, 0x11,},
            {0x0c, 0x11, 0x13, 0x11, 0x0e, 0x11, 0x08, 0x11, 0x03, 0x11, 0x56, 0x11, 0x39, 0x11, 0x02, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixu64 = {
            {0x0000000000001ffd, 0x000000007189af35,},
            {0x0000000000001ffd, 0x000000007189af35,},
        },
        .fixu32 = {
            {0x00000003, 0x00000001, 0x00000003, 0x00000001,},
            {0x00000003, 0x00000001, 0x00000003, 0x00000001,},
        },
        .fixu16 = {
            {0x7f2b, 0x025b, 0x0007, 0x0023, 0x378b, 0x0377, 0x37af, 0x00af,},
            {0x7f2b, 0x025b, 0x0007, 0x0023, 0x378b, 0x0377, 0x37af, 0x00af,},
        },
        .fixu8 = {
            {0x0d, 0x0b, 0x13, 0x07, 0x0f, 0x01, 0x09, 0x11, 0x03, 0x03, 0x57, 0x9e, 0x39, 0x13, 0x03, 0xc9,},
            {0x0d, 0x0b, 0x13, 0x07, 0x0f, 0x01, 0x09, 0x11, 0x03, 0x03, 0x57, 0x9e, 0x39, 0x13, 0x03, 0xc9,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vssrl.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_8_rnu(vlmax_8 - 1, src0[i].fixu8, src1[i].fixu8,
                res.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rnu[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_8_rne(src0[i].fixu8, src1[i].fixu8,
                res.fixu8, vmo.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rne[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_8_rdn(src0[i].fixu8, src1[i].fixu8,
                res.fixu8, vme.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rdn[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_8_rod(src0[i].fixu8, src1[i].fixu8, res.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rod[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_16_rnu(vlmax_16 - 1, src0[i].fixu16,
                src1[i].fixu16, res.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rnu[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_16_rne(src0[i].fixu16, src1[i].fixu16,
                res.fixu16, vmo.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rne[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_16_rdn(src0[i].fixu16, src1[i].fixu16,
                res.fixu16, vme.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rdn[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_16_rod(src0[i].fixu16, src1[i].fixu16, res.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rod[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_32_rnu(vlmax_32 - 1, src0[i].fixu32, src1[i].fixu32,
                res.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rnu[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_32_rne(src0[i].fixu32, src1[i].fixu32,
                res.fixu32, vmo.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rne[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_32_rdn(src0[i].fixu32, src1[i].fixu32,
                res.fixu32, vme.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rdn[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_32_rod(src0[i].fixu32, src1[i].fixu32, res.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rod[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_64_rnu(vlmax_64 - 1, src0[i].fixu64, src1[i].fixu64,
                res.fixu64, pad.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_rnu[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_64_rne(src0[i].fixu64, src1[i].fixu64,
                res.fixu64, vmo.fixu64, pad.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_rne[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_64_rdn(src0[i].fixu64, src1[i].fixu64,
                res.fixu64, vme.fixu64, pad.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_rdn[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vv_64_rod(src0[i].fixu64, src1[i].fixu64, res.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_rod[i].fixu64[0]);
    }

    return done_testing();
}
