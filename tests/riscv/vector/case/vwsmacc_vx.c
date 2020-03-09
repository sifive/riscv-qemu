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

int8_t   src1_s8 = 0x7d;
int16_t src1_s16 = 0xaf83;
int32_t src1_s32 = 0x80000083;

uint8_t   src1_u8 = 0x5f;
uint16_t src1_u16 = 0x5fff;
uint32_t src1_u32 = 0x3fffffff;

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
            {0x07d22da25745378a, 0x0718a0306a8920b3, 0x07d20a94619b97d4, 0x071876052bb7c8f6,},
            {0x07d22da25745378a, 0x0718a0306a8920b3, 0x07d20a94619b97d4, 0x0000000000000000,},
        },
        .wfixs32 = {
            {0x77a1c67b, 0xf1a5e872, 0x67de608a, 0x12daa507, 0x77b1fbb6, 0xf1a762ad, 0x67cd4397, 0x12fcfd6e,},
            {0x77a1c67b, 0xf1a5e872, 0x67de608a, 0x12daa507, 0x77b1fbb6, 0xf1a762ad, 0x67cd4397, 0x00000000,},
        },
        .wfixs16 = {
            {0x4cf1, 0x3b49, 0x63ba, 0xfe22, 0xccf3, 0x9d0f, 0x2cc1, 0xd36e, 0x52a6, 0x3a76, 0x6919, 0xf735, 0xce6a, 0x96e5, 0x312d, 0xd0b7,},
            {0x4cf1, 0x3b49, 0x63ba, 0xfe22, 0xccf3, 0x9d0f, 0x2cc1, 0xd36e, 0x52a6, 0x3a76, 0x6919, 0xf735, 0xce6a, 0x96e5, 0x312d, 0x0000,},
        },
        .wfixu64 = {
            {0xbc73358fbcf56163, 0x0afda7b82c81b7a2, 0xbc73404b958e3673, 0x0afda4588e930520,},
            {0xbc73358fbcf56163, 0x0afda7b82c81b7a2, 0xbc73404b958e3673, 0x0000000000000000,},
        },
        .wfixu32 = {
            {0xe3f14120, 0xb2dd2274, 0x88ea72ad, 0x1c3eb775, 0xe3bb89af, 0xb2c60fb1, 0x88e371df, 0x1c7d578e,},
            {0xe3f14120, 0xb2dd2274, 0x88ea72ad, 0x1c3eb775, 0xe3bb89af, 0xb2c60fb1, 0x88e371df, 0x00000000,},
        },
        .wfixu16 = {
            {0x67f1, 0x3c38, 0x4d79, 0x7f96, 0xa3e5, 0xd916, 0x5e38, 0xff75, 0x6832, 0x4117, 0x4df0, 0x81d0, 0xa3f7, 0xd6fa, 0x5d09, 0xffff,},
            {0x67f1, 0x3c38, 0x4d79, 0x7f96, 0xa3e5, 0xd916, 0x5e38, 0xff75, 0x6832, 0x4117, 0x4df0, 0x81d0, 0xa3f7, 0xd6fa, 0x5d09, 0x0000,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x0718a0306a8920b3, 0x07d215928aa0d7b6, 0x071876052bb7c8f6,},
            {0x07d215928aa0d7b6, 0x0718a0306a8920b3, 0x07d215928aa0d7b6, 0x071876052bb7c8f6,},
        },
        .wfixs32 = {
            {0x7794d541, 0xf1a5e872, 0x67e3b37f, 0x12daa507, 0x7794d541, 0xf1a762ad, 0x67e3b37f, 0x12fcfd6e,},
            {0x7794d541, 0xf1a5e872, 0x67e3b37f, 0x12daa507, 0x7794d541, 0xf1a762ad, 0x67e3b37f, 0x12fcfd6e,},
        },
        .wfixs16 = {
            {0x4fb8, 0x3b49, 0x6744, 0xfe22, 0xce81, 0x9d0f, 0x301c, 0xd36e, 0x4fb8, 0x3a76, 0x6744, 0xf735, 0xce81, 0x96e5, 0x301c, 0xd0b7,},
            {0x4fb8, 0x3b49, 0x6744, 0xfe22, 0xce81, 0x9d0f, 0x301c, 0xd36e, 0x4fb8, 0x3a76, 0x6744, 0xf735, 0xce81, 0x96e5, 0x301c, 0xd0b7,},
        },
        .wfixu64 = {
            {0xbc73041be547e732, 0x0afda7b82c81b7a2, 0xbc73041be547e732, 0x0afda4588e930520,},
            {0xbc73041be547e732, 0x0afda7b82c81b7a2, 0xbc73041be547e732, 0x0afda4588e930520,},
        },
        .wfixu32 = {
            {0xe391e1de, 0xb2dd2274, 0x888fed5e, 0x1c3eb775, 0xe391e1de, 0xb2c60fb1, 0x888fed5e, 0x1c7d578e,},
            {0xe391e1de, 0xb2dd2274, 0x888fed5e, 0x1c3eb775, 0xe391e1de, 0xb2c60fb1, 0x888fed5e, 0x1c7d578e,},
        },
        .wfixu16 = {
            {0x6371, 0x3c38, 0x49ed, 0x7f96, 0x9ea1, 0xd916, 0x5c92, 0xff75, 0x6371, 0x4117, 0x49ed, 0x81d0, 0x9ea1, 0xd6fa, 0x5c92, 0xffff,},
            {0x6371, 0x3c38, 0x49ed, 0x7f96, 0x9ea1, 0xd916, 0x5c92, 0xff75, 0x6371, 0x4117, 0x49ed, 0x81d0, 0x9ea1, 0xd6fa, 0x5c92, 0xffff,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .wfixs64 = {
            {0x07d22da25745378a, 0x07186161e5f9e80f, 0x07d20a94619b97d4, 0x07186161e5f9e80f,},
            {0x07d22da25745378a, 0x07186161e5f9e80f, 0x07d20a94619b97d4, 0x07186161e5f9e80f,},
        },
        .wfixs32 = {
            {0x77a1c67a, 0xf1bfac15, 0x67de608a, 0x12df3e7c, 0x77b1fbb6, 0xf1bfac15, 0x67cd4396, 0x12df3e7c,},
            {0x77a1c67a, 0xf1bfac15, 0x67de608a, 0x12df3e7c, 0x77b1fbb6, 0xf1bfac15, 0x67cd4396, 0x12df3e7c,},
        },
        .wfixs16 = {
            {0x4cf1, 0x39b3, 0x63b9, 0xfa98, 0xccf2, 0x997d, 0x2cc0, 0xcfb5, 0x52a6, 0x39b3, 0x6918, 0xfa98, 0xce69, 0x997d, 0x312d, 0xcfb5,},
            {0x4cf1, 0x39b3, 0x63b9, 0xfa98, 0xccf2, 0x997d, 0x2cc0, 0xcfb5, 0x52a6, 0x39b3, 0x6918, 0xfa98, 0xce69, 0x997d, 0x312d, 0xcfb5,},
        },
        .wfixu64 = {
            {0xbc73358fbcf56162, 0x0afd8a490d762d5e, 0xbc73404b958e3673, 0x0afd8a490d762d5e,},
            {0xbc73358fbcf56162, 0x0afd8a490d762d5e, 0xbc73404b958e3673, 0x0afd8a490d762d5e,},
        },
        .wfixu32 = {
            {0xe3f1411f, 0xb2c0dd9f, 0x88ea72ac, 0x1c3b70fe, 0xe3bb89ae, 0xb2c0dd9f, 0x88e371df, 0x1c3b70fe,},
            {0xe3f1411f, 0xb2c0dd9f, 0x88ea72ac, 0x1c3b70fe, 0xe3bb89ae, 0xb2c0dd9f, 0x88e371df, 0x1c3b70fe,},
        },
        .wfixu16 = {
            {0x67f0, 0x3b45, 0x4d79, 0x7e26, 0xa3e4, 0xd612, 0x5e37, 0xfc48, 0x6832, 0x3b45, 0x4df0, 0x7e26, 0xa3f6, 0xd612, 0x5d08, 0xfc48,},
            {0x67f0, 0x3b45, 0x4d79, 0x7e26, 0xa3e4, 0xd612, 0x5e37, 0xfc48, 0x6832, 0x3b45, 0x4df0, 0x7e26, 0xa3f6, 0xd612, 0x5d08, 0xfc48,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .wfixs64 = {
            {0x07d22da25745378b, 0x0718a0306a8920b4, 0x07d20a94619b97d5, 0x071876052bb7c8f6,},
            {0x07d22da25745378b, 0x0718a0306a8920b4, 0x07d20a94619b97d5, 0x071876052bb7c8f6,},
        },
        .wfixs32 = {
            {0x77a1c67a, 0xf1a5e872, 0x67de608a, 0x12daa507, 0x77b1fbb6, 0xf1a762ae, 0x67cd4396, 0x12fcfd6f,},
            {0x77a1c67a, 0xf1a5e872, 0x67de608a, 0x12daa507, 0x77b1fbb6, 0xf1a762ae, 0x67cd4396, 0x12fcfd6f,},
        },
        .wfixs16 = {
            {0x4cf1, 0x3b4a, 0x63b9, 0xfe23, 0xccf2, 0x9d10, 0x2cc1, 0xd36e, 0x52a6, 0x3a76, 0x6919, 0xf735, 0xce6a, 0x96e4, 0x312d, 0xd0b6,},
            {0x4cf1, 0x3b4a, 0x63b9, 0xfe23, 0xccf2, 0x9d10, 0x2cc1, 0xd36e, 0x52a6, 0x3a76, 0x6919, 0xf735, 0xce6a, 0x96e4, 0x312d, 0xd0b6,},
        },
        .wfixu64 = {
            {0xbc73358fbcf56163, 0x0afda7b82c81b7a1, 0xbc73404b958e3673, 0x0afda4588e93051f,},
            {0xbc73358fbcf56163, 0x0afda7b82c81b7a1, 0xbc73404b958e3673, 0x0afda4588e93051f,},
        },
        .wfixu32 = {
            {0xe3f1411f, 0xb2dd2274, 0x88ea72ad, 0x1c3eb775, 0xe3bb89af, 0xb2c60fb2, 0x88e371df, 0x1c7d578f,},
            {0xe3f1411f, 0xb2dd2274, 0x88ea72ad, 0x1c3eb775, 0xe3bb89af, 0xb2c60fb2, 0x88e371df, 0x1c7d578f,},
        },
        .wfixu16 = {
            {0x67f0, 0x3c38, 0x4d7a, 0x7f97, 0xa3e4, 0xd915, 0x5e37, 0xff75, 0x6832, 0x4118, 0x4df0, 0x81d1, 0xa3f6, 0xd6f9, 0x5d09, 0xffff,},
            {0x67f0, 0x3c38, 0x4d7a, 0x7f97, 0xa3e4, 0xd915, 0x5e37, 0xff75, 0x6832, 0x4118, 0x4df0, 0x81d1, 0xa3f6, 0xd6f9, 0x5d09, 0xffff,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsmacc.vx\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_8_rnu(vlmax_8 - 1, src0[i].fixu8, src1_u8,
                src2[i].wfixu16, res.wfixu16);
        result_compare_u16_lmul(res.wfixu16[0], dst_rnu[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rnu[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_8_rne(src0[i].fixu8, src1_u8, src2[i].wfixu16,
                res.wfixu16, vmo.fixu8);
        result_compare_u16_lmul(res.wfixu16[0], dst_rne[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rne[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_8_rdn(src0[i].fixu8, src1_u8, src2[i].wfixu16,
                res.wfixu16, vme.fixu8);
        result_compare_u16_lmul(res.wfixu16[0], dst_rdn[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rdn[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_8_rod(src0[i].fixu8, src1_u8, src2[i].wfixu16,
                res.wfixu16);
        result_compare_u16_lmul(res.wfixu16[0], dst_rod[i].wfixu16[0]);
        result_compare_u16_lmul(res.wfixu16[1], dst_rod[i].wfixu16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_16_rnu(vlmax_16 - 1, src0[i].fixu16, src1_u16,
                src2[i].wfixu32, res.wfixu32);
        result_compare_u32_lmul(res.wfixu32[0], dst_rnu[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rnu[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_16_rne(src0[i].fixu16, src1_u16, src2[i].wfixu32,
                res.wfixu32, vmo.fixu16);
        result_compare_u32_lmul(res.wfixu32[0], dst_rne[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rne[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_16_rdn(src0[i].fixu16, src1_u16, src2[i].wfixu32,
                res.wfixu32, vme.fixu16);
        result_compare_u32_lmul(res.wfixu32[0], dst_rdn[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rdn[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_16_rod(src0[i].fixu16, src1_u16, src2[i].wfixu32,
                res.wfixu32);
        result_compare_u32_lmul(res.wfixu32[0], dst_rod[i].wfixu32[0]);
        result_compare_u32_lmul(res.wfixu32[1], dst_rod[i].wfixu32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_32_rnu(vlmax_32 - 1, src0[i].fixu32, src1_u32,
                src2[i].wfixu64, res.wfixu64);
        result_compare_u64_lmul(res.wfixu64[0], dst_rnu[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rnu[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_32_rne(src0[i].fixu32, src1_u32, src2[i].wfixu64,
                res.wfixu64, vmo.fixu32);
        result_compare_u64_lmul(res.wfixu64[0], dst_rne[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rne[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_32_rdn(src0[i].fixu32, src1_u32, src2[i].wfixu64,
                res.wfixu64, vme.fixu32);
        result_compare_u64_lmul(res.wfixu64[0], dst_rdn[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rdn[i].wfixu64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccu_vx_32_rod(src0[i].fixu32, src1_u32, src2[i].wfixu64,
                res.wfixu64);
        result_compare_u64_lmul(res.wfixu64[0], dst_rod[i].wfixu64[0]);
        result_compare_u64_lmul(res.wfixu64[1], dst_rod[i].wfixu64[1]);
    }

    return done_testing();
}
