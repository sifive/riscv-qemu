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
        .fixs32 = {
            {0x0fa42b25, 0x0e30c2c4, 0x0fa42b25, 0x0e30c2c4,},
            {0x0fa42b25, 0x0e30c2c4, 0x0fa42b25, 0x00000000,},
        },
        .fixs16 = {
            {0x7fff, 0x8000, 0x7fff, 0x7fff, 0x7fff, 0x8000, 0x7fff, 0x7fff,},
            {0x7fff, 0x8000, 0x7fff, 0x7fff, 0x7fff, 0x8000, 0x7fff, 0x0000,},
        },
        .fixs8 = {
            {0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80,},
            {0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x00,},
        },
        .fixu32 = {
            {0xffffffff, 0x15fb1492, 0xffffffff, 0x15fb1492,},
            {0xffffffff, 0x15fb1492, 0xffffffff, 0x00000000,},
        },
        .fixu16 = {
            {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,},
            {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000,},
        },
        .fixu8 = {
            {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,},
            {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs32 = {
            {0x11111111, 0x0e30c2c4, 0x11111111, 0x0e30c2c4,},
            {0x11111111, 0x0e30c2c4, 0x11111111, 0x0e30c2c4,},
        },
        .fixs16 = {
            {0x1111, 0x8000, 0x1111, 0x7fff, 0x1111, 0x8000, 0x1111, 0x7fff,},
            {0x1111, 0x8000, 0x1111, 0x7fff, 0x1111, 0x8000, 0x1111, 0x7fff,},
        },
        .fixs8 = {
            {0x11, 0x7f, 0x11, 0xd5, 0x11, 0x80, 0x11, 0x80, 0x11, 0x7f, 0x11, 0xd5, 0x11, 0x80, 0x11, 0x80,},
            {0x11, 0x7f, 0x11, 0xd5, 0x11, 0x80, 0x11, 0x80, 0x11, 0x7f, 0x11, 0xd5, 0x11, 0x80, 0x11, 0x80,},
        },
        .fixu32 = {
            {0x11111111, 0x15fb1492, 0x11111111, 0x15fb1492,},
            {0x11111111, 0x15fb1492, 0x11111111, 0x15fb1492,},
        },
        .fixu16 = {
            {0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff,},
            {0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff,},
        },
        .fixu8 = {
            {0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff,},
            {0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff, 0x11, 0xff,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs32 = {
            {0x0fa42b25, 0x11111111, 0x0fa42b25, 0x11111111,},
            {0x0fa42b25, 0x11111111, 0x0fa42b25, 0x11111111,},
        },
        .fixs16 = {
            {0x7fff, 0x1111, 0x7fff, 0x1111, 0x7fff, 0x1111, 0x7fff, 0x1111,},
            {0x7fff, 0x1111, 0x7fff, 0x1111, 0x7fff, 0x1111, 0x7fff, 0x1111,},
        },
        .fixs8 = {
            {0x7f, 0x11, 0x7f, 0x11, 0x80, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x80, 0x11, 0x7f, 0x11,},
            {0x7f, 0x11, 0x7f, 0x11, 0x80, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x7f, 0x11, 0x80, 0x11, 0x7f, 0x11,},
        },
        .fixu32 = {
            {0xffffffff, 0x11111111, 0xffffffff, 0x11111111,},
            {0xffffffff, 0x11111111, 0xffffffff, 0x11111111,},
        },
        .fixu16 = {
            {0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111,},
            {0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111, 0xffff, 0x1111,},
        },
        .fixu8 = {
            {0x31, 0x11, 0x24, 0x11, 0x4f, 0x11, 0x2e, 0x11, 0x31, 0x11, 0x24, 0x11, 0x4f, 0x11, 0x2e, 0x11,},
            {0x31, 0x11, 0x24, 0x11, 0x4f, 0x11, 0x2e, 0x11, 0x31, 0x11, 0x24, 0x11, 0x4f, 0x11, 0x2e, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs32 = {
            {0x0fa42b25, 0x0e30c2c3, 0x0fa42b25, 0x0e30c2c3,},
            {0x0fa42b25, 0x0e30c2c3, 0x0fa42b25, 0x0e30c2c3,},
        },
        .fixs16 = {
            {0x7fff, 0x8000, 0x7fff, 0x7fff, 0x7fff, 0x8000, 0x7fff, 0x7fff,},
            {0x7fff, 0x8000, 0x7fff, 0x7fff, 0x7fff, 0x8000, 0x7fff, 0x7fff,},
        },
        .fixs8 = {
            {0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80,},
            {0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0xd5, 0x80, 0x80, 0x7f, 0x80,},
        },
        .fixu32 = {
            {0xffffffff, 0x15fb1493, 0xffffffff, 0x15fb1493,}, 
            {0xffffffff, 0x15fb1493, 0xffffffff, 0x15fb1493,}, 
        },
        .fixu16 = {
            {0xffff, 0xffff, 0xffff, 0x70ed, 0xffff, 0xffff, 0xffff, 0x70ed,},
            {0xffff, 0xffff, 0xffff, 0x70ed, 0xffff, 0xffff, 0xffff, 0x70ed,},
        },
        .fixu8 = {
            {0x31, 0x1d, 0x25, 0x3f, 0x4f, 0x6b, 0x2f, 0x7f, 0x31, 0x1d, 0x25, 0x3f, 0x4f, 0x6b, 0x2f, 0x7f,},
            {0x31, 0x1d, 0x25, 0x3f, 0x4f, 0x6b, 0x2f, 0x7f, 0x31, 0x1d, 0x25, 0x3f, 0x4f, 0x6b, 0x2f, 0x7f,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vnclip.vi\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_8_rnu(vlmax_8 - 1, src0[i].wfixs16,
                res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_8_rne(src0[i].wfixs16,
                res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_8_rdn(src0[i].wfixs16,
                res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_8_rod(src0[i].wfixs16, res.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_16_rnu(vlmax_16 - 1, src0[i].wfixs32,
                res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_16_rne(src0[i].wfixs32,
                res.fixs16, vmo.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_16_rdn(src0[i].wfixs32,
                res.fixs16, vme.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_16_rod(src0[i].wfixs32, res.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_32_rnu(vlmax_32 - 1, src0[i].wfixs64,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_32_rne(src0[i].wfixs64,
                res.fixs32, vmo.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_32_rdn(src0[i].wfixs64,
                res.fixs32, vme.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclip_vi_32_rod(src0[i].wfixs64, res.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_8_rnu(vlmax_8 - 1, src0[i].wfixu16,
                res.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rnu[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_8_rne(src0[i].wfixu16,
                res.fixu8, vmo.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rne[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_8_rdn(src0[i].wfixu16,
                res.fixu8, vme.fixu8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rdn[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_8_rod(src0[i].wfixu16, res.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_rod[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_16_rnu(vlmax_16 - 1, src0[i].wfixu32,
                res.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rnu[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_16_rne(src0[i].wfixu32,
                res.fixu16, vmo.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rne[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_16_rdn(src0[i].wfixu32,
                res.fixu16, vme.fixu16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rdn[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_16_rod(src0[i].wfixu32, res.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_rod[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_32_rnu(vlmax_32 - 1, src0[i].wfixu64,
                res.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rnu[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_32_rne(src0[i].wfixu64,
                res.fixu32, vmo.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rne[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_32_rdn(src0[i].wfixu64,
                res.fixu32, vme.fixu32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rdn[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vnclipu_vi_32_rod(src0[i].wfixu64, res.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_rod[i].fixu32[0]);
    }

    return done_testing();
}
