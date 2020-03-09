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
        .fixs32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .fixs16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .fixs8 = {
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
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

struct rvv_reg src2[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f,
                0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f,
                0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
        },
        .wfixs32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c,
                0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c,
                0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .wfixs16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, 
                0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, 
                0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .wfixu64 = {
            {0xbc73041be547e732, 0x0afd8a490d762d5e,
                0xbc73041be547e732, 0x0afd8a490d762d5e, },
            {0xbc73041be547e732, 0x0afd8a490d762d5e,
                0xbc73041be547e732, 0x0afd8a490d762d5e, },
        },
        .wfixu32 = {
            {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe,
                0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
            {0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe,
                0xe391e1de, 0xb2c0dd9f, 0x888fed5e, 0x1c3b70fe, },
        },
        .wfixu16 = {
            {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48,
                0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
            {0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48,
                0x6371, 0x3b45, 0x49ed, 0x7e26, 0x9ea1, 0xd612, 0x5c92, 0xfc48, },
        },
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .wfixs64 = {
            {0x07d1ff17dfede476, 0x071868600cf03b15, 0x07d21e7e9dd34793, 0x07185e56f1a18277,},
            {0x07d1ff17dfede476, 0x071868600cf03b15, 0x07d21e7e9dd34793, 0x0000000000000000},
        },
        .wfixs32 = {
            {0x778803b5, 0xf1d22443, 0x67ea8827, 0x12deef66, 0x77a6c247, 0xf1a0bd74, 0x67f11cbd, 0x12f11774,},
            {0x778803b5, 0xf1d22443, 0x67ea8827, 0x12deef66, 0x77a6c247, 0xf1a0bd74, 0x67f11cbd, 0x00000000,},
        },
        .wfixs16 = {
            {0x4efc, 0x38c3, 0x6a86, 0xfc3d, 0xcee1, 0x99bf, 0x331e, 0xd055, 0x50c0, 0x39d1, 0x6609, 0xfde6, 0xce7a, 0x9a87, 0x30c9, 0xcf27,},
            {0x4efc, 0x38c3, 0x6a86, 0xfc3d, 0xcee1, 0x99bf, 0x331e, 0xd055, 0x50c0, 0x39d1, 0x6609, 0xfde6, 0xce7a, 0x9a87, 0x30c9, 0x0000,},
        },
        .wfixu64 = {
            {0xbc73b3f37f416510, 0x0afddc7ecf1988a5, 0xbc73848895a62d38, 0x0afd95c80a408fd1,},
            {0xbc73b3f37f416510, 0x0afddc7ecf1988a5, 0xbc73848895a62d38, 0x0000000000000000,},
        },
        .wfixu32 = {
            {0xe3f4ad64, 0xb2d251c2, 0x88d5a2ef, 0x1c3fbed2, 0xe3d6b74f, 0xb2cc73aa, 0x88e076e0, 0x1ce8a173,},
            {0xe3f4ad64, 0xb2d251c2, 0x88d5a2ef, 0x1c3fbed2, 0xe3d6b74f, 0xb2cc73aa, 0x88e076e0, 0x00000000,},
        },
        .wfixu16 = {
            {0x64c5, 0x3bee, 0x51cf, 0x7f68, 0xa6d5, 0xd8d5, 0x5eb4, 0xffff, 0x6c26, 0x4476, 0x4cac, 0x7fb1, 0xa1e3, 0xd6eb, 0x5d54, 0xffff,},
            {0x64c5, 0x3bee, 0x51cf, 0x7f68, 0xa6d5, 0xd8d5, 0x5eb4, 0xffff, 0x6c26, 0x4476, 0x4cac, 0x7fb1, 0xa1e3, 0xd6eb, 0x5d54, 0x0000,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x071868600cf03b15, 0x07d215928aa0d7b6, 0x07185e56f1a18277,},
            {0x07d215928aa0d7b6, 0x071868600cf03b15, 0x07d215928aa0d7b6, 0x07185e56f1a18277,},
        },
        .wfixs32 = {
            {0x7794d541, 0xf1d22443, 0x67e3b37f, 0x12deef66, 0x7794d541, 0xf1a0bd74, 0x67e3b37f, 0x12f11774,},
            {0x7794d541, 0xf1d22443, 0x67e3b37f, 0x12deef66, 0x7794d541, 0xf1a0bd74, 0x67e3b37f, 0x12f11774,},
        },
        .wfixs16 = {
            {0x4fb8, 0x38c3, 0x6744, 0xfc3c, 0xce81, 0x99bf, 0x301c, 0xd055, 0x4fb8, 0x39d1, 0x6744, 0xfde6, 0xce81, 0x9a87, 0x301c, 0xcf27,},
            {0x4fb8, 0x38c3, 0x6744, 0xfc3c, 0xce81, 0x99bf, 0x301c, 0xd055, 0x4fb8, 0x39d1, 0x6744, 0xfde6, 0xce81, 0x9a87, 0x301c, 0xcf27,},
        },
        .wfixu64 = {
            {0xbc73041be547e732, 0x0afddc7ecf1988a5, 0xbc73041be547e732, 0x0afd95c80a408fd1,},
            {0xbc73041be547e732, 0x0afddc7ecf1988a5, 0xbc73041be547e732, 0x0afd95c80a408fd1,},
        },
        .wfixu32 = {
            {0xe391e1de, 0xb2d251c2, 0x888fed5e, 0x1c3fbed2, 0xe391e1de, 0xb2cc73aa, 0x888fed5e, 0x1ce8a173,},
            {0xe391e1de, 0xb2d251c2, 0x888fed5e, 0x1c3fbed2, 0xe391e1de, 0xb2cc73aa, 0x888fed5e, 0x1ce8a173,},
        },
        .wfixu16 = {
            {0x6371, 0x3bee, 0x49ed, 0x7f68, 0x9ea1, 0xd8d5, 0x5c92, 0xffff, 0x6371, 0x4476, 0x49ed, 0x7fb1, 0x9ea1, 0xd6eb, 0x5c92, 0xffff,},
            {0x6371, 0x3bee, 0x49ed, 0x7f68, 0x9ea1, 0xd8d5, 0x5c92, 0xffff, 0x6371, 0x4476, 0x49ed, 0x7fb1, 0x9ea1, 0xd6eb, 0x5c92, 0xffff,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .wfixs64 = {
            {0x07d1ff17dfede475, 0x07186161e5f9e80f, 0x07d21e7e9dd34792, 0x07186161e5f9e80f,},
            {0x07d1ff17dfede475, 0x07186161e5f9e80f, 0x07d21e7e9dd34792, 0x07186161e5f9e80f,},
        },
        .wfixs32 = {
            {0x778803b4, 0xf1bfac15, 0x67ea8827, 0x12df3e7c, 0x77a6c246, 0xf1bfac15, 0x67f11cbd, 0x12df3e7c,},
            {0x778803b4, 0xf1bfac15, 0x67ea8827, 0x12df3e7c, 0x77a6c246, 0xf1bfac15, 0x67f11cbd, 0x12df3e7c,},
        },
        .wfixs16 = {
            {0x4efc, 0x39b3, 0x6a85, 0xfa98, 0xcee0, 0x997d, 0x331e, 0xcfb5, 0x50c0, 0x39b3, 0x6609, 0xfa98, 0xce79, 0x997d, 0x30c8, 0xcfb5,},
            {0x4efc, 0x39b3, 0x6a85, 0xfa98, 0xcee0, 0x997d, 0x331e, 0xcfb5, 0x50c0, 0x39b3, 0x6609, 0xfa98, 0xce79, 0x997d, 0x30c8, 0xcfb5,},
        },
        .wfixu64 = {
            {0xbc73b3f37f41650f, 0x0afd8a490d762d5e, 0xbc73848895a62d37, 0x0afd8a490d762d5e,},
            {0xbc73b3f37f41650f, 0x0afd8a490d762d5e, 0xbc73848895a62d37, 0x0afd8a490d762d5e,},
        },
        .wfixu32 = {
            {0xe3f4ad63, 0xb2c0dd9f, 0x88d5a2ef, 0x1c3b70fe, 0xe3d6b74e, 0xb2c0dd9f, 0x88e076df, 0x1c3b70fe,},
            {0xe3f4ad63, 0xb2c0dd9f, 0x88d5a2ef, 0x1c3b70fe, 0xe3d6b74e, 0xb2c0dd9f, 0x88e076df, 0x1c3b70fe,},
        },
        .wfixu16 = {
            {0x64c4, 0x3b45, 0x51ce, 0x7e26, 0xa6d4, 0xd612, 0x5eb3, 0xfc48, 0x6c26, 0x3b45, 0x4cab, 0x7e26, 0xa1e2, 0xd612, 0x5d53, 0xfc48,},
            {0x64c4, 0x3b45, 0x51ce, 0x7e26, 0xa6d4, 0xd612, 0x5eb3, 0xfc48, 0x6c26, 0x3b45, 0x4cab, 0x7e26, 0xa1e2, 0xd612, 0x5d53, 0xfc48,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .wfixs64 = {
            {0x07d1ff17dfede475, 0x071868600cf03b16, 0x07d21e7e9dd34793, 0x07185e56f1a18278,},
            {0x07d1ff17dfede475, 0x071868600cf03b16, 0x07d21e7e9dd34793, 0x07185e56f1a18278,},
        },
        .wfixs32 = {
            {0x778803b4, 0xf1d22444, 0x67ea8828, 0x12deef65, 0x77a6c246, 0xf1a0bd74, 0x67f11cbe, 0x12f11773,},
            {0x778803b4, 0xf1d22444, 0x67ea8828, 0x12deef65, 0x77a6c246, 0xf1a0bd74, 0x67f11cbe, 0x12f11773,},
        },
        .wfixs16 = {
            {0x4efd, 0x38c2, 0x6a85, 0xfc3d, 0xcee0, 0x99be, 0x331e, 0xd056, 0x50c0, 0x39d0, 0x6609, 0xfde7, 0xce7a, 0x9a86, 0x30c9, 0xcf26,},
            {0x4efd, 0x38c2, 0x6a85, 0xfc3d, 0xcee0, 0x99be, 0x331e, 0xd056, 0x50c0, 0x39d0, 0x6609, 0xfde7, 0xce7a, 0x9a86, 0x30c9, 0xcf26,},
        },
        .wfixu64 = {
            {0xbc73b3f37f41650f, 0x0afddc7ecf1988a5, 0xbc73848895a62d37, 0x0afd95c80a408fd1,},
            {0xbc73b3f37f41650f, 0x0afddc7ecf1988a5, 0xbc73848895a62d37, 0x0afd95c80a408fd1,},
        },
        .wfixu32 = {
            {0xe3f4ad63, 0xb2d251c2, 0x88d5a2ef, 0x1c3fbed1, 0xe3d6b74f, 0xb2cc73aa, 0x88e076df, 0x1ce8a173,},
            {0xe3f4ad63, 0xb2d251c2, 0x88d5a2ef, 0x1c3fbed1, 0xe3d6b74f, 0xb2cc73aa, 0x88e076df, 0x1ce8a173,},
        },
        .wfixu16 = {
            {0x64c4, 0x3bee, 0x51ce, 0x7f67, 0xa6d4, 0xd8d5, 0x5eb3, 0xffff, 0x6c26, 0x4476, 0x4cac, 0x7fb1, 0xa1e2, 0xd6eb, 0x5d53, 0xffff,},
            {0x64c4, 0x3bee, 0x51ce, 0x7f67, 0xa6d4, 0xd8d5, 0x5eb3, 0xffff, 0x6c26, 0x4476, 0x4cac, 0x7fb1, 0xa1e2, 0xd6eb, 0x5d53, 0xffff,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsmaccu.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_8_rnu(vlmax_8 - 1, src0[i].fixu8, src1[i].fixu8,
                src2[i].wfixu16, res.wfixu16);
        result_compare_u16_lmul(res.wfixu16[0], dst_rnu[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rnu[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_8_rne(src0[i].fixu8, src1[i].fixu8, src2[i].wfixu16,
                res.wfixu16, vmo.fixu8);
        result_compare_u16_lmul(res.wfixu16[0], dst_rne[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rne[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_8_rdn(src0[i].fixu8, src1[i].fixu8, src2[i].wfixu16,
                res.wfixu16, vme.fixu8);
        result_compare_u16_lmul(res.wfixu16[0], dst_rdn[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rdn[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_8_rod(src0[i].fixu8, src1[i].fixu8, src2[i].wfixu16,
                res.wfixu16);
        result_compare_u16_lmul(res.wfixu16[0], dst_rod[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rod[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_16_rnu(vlmax_16 - 1, src0[i].fixu16, src1[i].fixu16,
                src2[i].wfixu32, res.wfixu32);
        result_compare_u32_lmul(res.wfixu32[0], dst_rnu[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rnu[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_16_rne(src0[i].fixu16, src1[i].fixu16, src2[i].wfixu32,
                res.wfixu32, vmo.fixu16);
        result_compare_u32_lmul(res.wfixu32[0], dst_rne[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rne[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_16_rdn(src0[i].fixu16, src1[i].fixu16, src2[i].wfixu32,
                res.wfixu32, vme.fixu16);
        result_compare_u32_lmul(res.wfixu32[0], dst_rdn[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rdn[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_16_rod(src0[i].fixu16, src1[i].fixu16, src2[i].wfixu32,
                res.wfixu32);
        result_compare_u32_lmul(res.wfixu32[0], dst_rod[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rod[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_32_rnu(vlmax_32 - 1, src0[i].fixu32, src1[i].fixu32,
                src2[i].wfixu64, res.wfixu64);
        result_compare_u64_lmul(res.wfixu64[0], dst_rnu[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rnu[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_32_rne(src0[i].fixu32, src1[i].fixu32, src2[i].wfixu64,
                res.wfixu64, vmo.fixu32);
        result_compare_u64_lmul(res.wfixu64[0], dst_rne[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rne[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_32_rdn(src0[i].fixu32, src1[i].fixu32, src2[i].wfixu64,
                res.wfixu64, vme.fixu32);
        result_compare_u64_lmul(res.wfixu64[0], dst_rdn[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rdn[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vv_32_rod(src0[i].fixu32, src1[i].fixu32, src2[i].wfixu64,
                res.wfixu64);
        result_compare_u64_lmul(res.wfixu64[0], dst_rod[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rod[i].wfixu64[1]);
    }

    return done_testing();
}
