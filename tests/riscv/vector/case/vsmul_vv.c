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
        .fixs64 = {
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
        },
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
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .fixs64 = {
            {0x038270869129ff0f, 0xfcd22a31035a3f2f,},
            {0x038270869129ff0f, 0x0000000000000000,},
        },
        .fixs32 = {
            {0xd30aaa9a, 0x0dfc4ded, 0x11d82665, 0xf9ea174f,},
            {0xd30aaa9a, 0x0dfc4ded, 0x11d82665, 0x00000000,},
        },
        .fixs16 = {
            {0xe65d, 0x24f0, 0x0da9, 0xff62, 0x23da, 0xc223, 0x1ad2, 0x23b2,},
            {0xe65d, 0x24f0, 0x0da9, 0xff62, 0x23da, 0xc223, 0x1ad2, 0x0000,},
        },
        .fixs8 = {
            {0xe9, 0xe2, 0x68, 0x35, 0x0c, 0x08, 0x60, 0x14, 0x21, 0x04, 0xd9, 0x6a, 0xff, 0x21, 0x16, 0xee,},
            {0xe9, 0xe2, 0x68, 0x35, 0x0c, 0x08, 0x60, 0x14, 0x21, 0x04, 0xd9, 0x6a, 0xff, 0x21, 0x16, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xfcd22a31035a3f2f,},
            {0x1111111111111111, 0xfcd22a31035a3f2f,},
        },
        .fixs32 = {
            {0x11111111, 0x0dfc4ded, 0x11111111, 0xf9ea174f,},
            {0x11111111, 0x0dfc4ded, 0x11111111, 0xf9ea174f,},
        },
        .fixs16 = {
            {0x1111, 0x24f0, 0x1111, 0xff62, 0x1111, 0xc223, 0x1111, 0x23b2,},
            {0x1111, 0x24f0, 0x1111, 0xff62, 0x1111, 0xc223, 0x1111, 0x23b2,},
        },
        .fixs8 = {
            {0x11, 0xe2, 0x11, 0x35, 0x11, 0x08, 0x11, 0x14, 0x11, 0x04, 0x11, 0x6a, 0x11, 0x21, 0x11, 0xee,},
            {0x11, 0xe2, 0x11, 0x35, 0x11, 0x08, 0x11, 0x14, 0x11, 0x04, 0x11, 0x6a, 0x11, 0x21, 0x11, 0xee,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs64 = {
            {0x038270869129ff0f, 0x1111111111111111,},
            {0x038270869129ff0f, 0x1111111111111111,},
        },
        .fixs32 = {
            {0xd30aaa9a, 0x11111111, 0x11d82664, 0x11111111,},
            {0xd30aaa9a, 0x11111111, 0x11d82664, 0x11111111,},
        },
        .fixs16 = {
            {0xe65c, 0x1111, 0x0da9, 0x1111, 0x23da, 0x1111, 0x1ad2, 0x1111,},
            {0xe65c, 0x1111, 0x0da9, 0x1111, 0x23da, 0x1111, 0x1ad2, 0x1111,},
        },
        .fixs8 = {
            {0xe8, 0x11, 0x68, 0x11, 0x0b, 0x11, 0x60, 0x11, 0x21, 0x11, 0xd8, 0x11, 0xff, 0x11, 0x15, 0x11,},
            {0xe8, 0x11, 0x68, 0x11, 0x0b, 0x11, 0x60, 0x11, 0x21, 0x11, 0xd8, 0x11, 0xff, 0x11, 0x15, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs64 = {
            {0x038270869129ff0f, 0xfcd22a31035a3f2e,},
            {0x038270869129ff0f, 0xfcd22a31035a3f2e,},
        },
        .fixs32 = {
            {0xd30aaa9b, 0x0dfc4ded, 0x11d82665, 0xf9ea174f,},
            {0xd30aaa9b, 0x0dfc4ded, 0x11d82665, 0xf9ea174f,},
        },
        .fixs16 = {
            {0xe65d, 0x24f1, 0x0da9, 0xff61, 0x23db, 0xc223, 0x1ad3, 0x23b1,},
            {0xe65d, 0x24f1, 0x0da9, 0xff61, 0x23db, 0xc223, 0x1ad3, 0x23b1,},
        },
        .fixs8 = {
            {0xe9, 0xe1, 0x69, 0x35, 0x0b, 0x09, 0x61, 0x15, 0x21, 0x03, 0xd9, 0x69, 0xff, 0x21, 0x15, 0xef,},
            {0xe9, 0xe1, 0x69, 0x35, 0x0b, 0x09, 0x61, 0x15, 0x21, 0x03, 0xd9, 0x69, 0xff, 0x21, 0x15, 0xef,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsmul.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_8_rnu(vlmax_8 - 1, src0[i].fixs8, src1[i].fixs8,
                res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_8_rne(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_8_rdn(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_8_rod(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_16_rnu(vlmax_16 - 1, src0[i].fixs16,
                src1[i].fixs16, res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_16_rne(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vmo.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_16_rdn(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vme.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_16_rod(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_32_rnu(vlmax_32 - 1, src0[i].fixs32, src1[i].fixs32,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_32_rne(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vmo.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_32_rdn(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vme.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_32_rod(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_64_rnu(vlmax_64 - 1, src0[i].fixs64, src1[i].fixs64,
                res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rnu[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_64_rne(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vmo.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rne[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_64_rdn(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vme.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rdn[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vsmul_vv_64_rod(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rod[i].fixs64[0]);
    }

    return done_testing();
}
