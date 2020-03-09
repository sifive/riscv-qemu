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

struct rvv_reg dst_rnu[] = {
    {
        .fixs64 = {
            {0x0000e5c2d664eac8, 0xffff1a98c2cd1f9d,},
            {0x0000e5c2d664eac8, 0x0000000000000000,},
        },
        .fixs32 = {
            {0xffff3f82, 0xfffe098c, 0x000057f1, 0xffff5ae6,},
            {0xffff3f82, 0xfffe098c, 0x000057f1, 0x00000000,},
        },
        .fixs16 = {
            {0xffae, 0x00a4, 0x0022, 0x001d, 0xff47, 0x009a, 0x008f, 0xff43,},
            {0xffae, 0x00a4, 0x0022, 0x001d, 0xff47, 0x009a, 0x008f, 0x0000,},
        },
        .fixs8 = {
            {0xf5, 0x07, 0xf2, 0x0f, 0xfa, 0x0f, 0xf2, 0x0f, 0x0c, 0x03, 0x08, 0xf2, 0x00, 0xf5, 0x04, 0x04,},
            {0xf5, 0x07, 0xf2, 0x0f, 0xfa, 0x0f, 0xf2, 0x0f, 0x0c, 0x03, 0x08, 0xf2, 0x00, 0xf5, 0x04, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xffff1a98c2cd1f9d,},
            {0x1111111111111111, 0xffff1a98c2cd1f9d,},
        },
        .fixs32 = {
            {0x11111111, 0xfffe098c, 0x11111111, 0xffff5ae6,},
            {0x11111111, 0xfffe098c, 0x11111111, 0xffff5ae6,},
        },
        .fixs16 = {
            {0x1111, 0x00a4, 0x1111, 0x001d, 0x1111, 0x009a, 0x1111, 0xff43,},
            {0x1111, 0x00a4, 0x1111, 0x001d, 0x1111, 0x009a, 0x1111, 0xff43,},
        },
        .fixs8 = {
            {0x11, 0x06, 0x11, 0x0e, 0x11, 0x0f, 0x11, 0x0f, 0x11, 0x03, 0x11, 0xf2, 0x11, 0xf5, 0x11, 0x04,},
            {0x11, 0x06, 0x11, 0x0e, 0x11, 0x0f, 0x11, 0x0f, 0x11, 0x03, 0x11, 0xf2, 0x11, 0xf5, 0x11, 0x04,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs64 = {
            {0x0000e5c2d664eac7, 0x1111111111111111,},
            {0x0000e5c2d664eac7, 0x1111111111111111,},
        },
        .fixs32 = {
            {0xffff3f81, 0x11111111, 0x000057f1, 0x11111111,},
            {0xffff3f81, 0x11111111, 0x000057f1, 0x11111111,},
        },
        .fixs16 = {
            {0xffad, 0x1111, 0x0021, 0x1111, 0xff46, 0x1111, 0x008e, 0x1111,},
            {0xffad, 0x1111, 0x0021, 0x1111, 0xff46, 0x1111, 0x008e, 0x1111,},
        },
        .fixs8 = {
            {0xf4, 0x11, 0xf1, 0x11, 0xf9, 0x11, 0xf2, 0x11, 0x0c, 0x11, 0x07, 0x11, 0xff, 0x11, 0x04, 0x11,},
            {0xf4, 0x11, 0xf1, 0x11, 0xf9, 0x11, 0xf2, 0x11, 0x0c, 0x11, 0x07, 0x11, 0xff, 0x11, 0x04, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs64 = {
            {0x0000e5c2d664eac7, 0xffff1a98c2cd1f9d,},
            {0x0000e5c2d664eac7, 0xffff1a98c2cd1f9d,},
        },
        .fixs32 = {
            {0xffff3f81, 0xfffe098b, 0x000057f1, 0xffff5ae5,},
            {0xffff3f81, 0xfffe098b, 0x000057f1, 0xffff5ae5,},
        },
        .fixs16 = {
            {0xffad, 0x00a3, 0x0021, 0x001d, 0xff47, 0x009b, 0x008f, 0xff43,},
            {0xffad, 0x00a3, 0x0021, 0x001d, 0xff47, 0x009b, 0x008f, 0xff43,},
        },
        .fixs8 = {
            {0xf5, 0x07, 0xf1, 0x0f, 0xf9, 0x0f, 0xf3, 0x0f, 0x0c, 0x03, 0x07, 0xf3, 0xff, 0xf5, 0x05, 0x05,},
            {0xf5, 0x07, 0xf1, 0x0f, 0xf9, 0x0f, 0xf3, 0x0f, 0x0c, 0x03, 0x07, 0xf3, 0xff, 0xf5, 0x05, 0x05,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vssra.vi\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_8_rnu(vlmax_8 - 1, src0[i].fixs8, res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_8_rne(src0[i].fixs8, res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_8_rdn(src0[i].fixs8, res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_8_rod(src0[i].fixs8, res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_16_rnu(vlmax_16 - 1, src0[i].fixs16,
                res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_16_rne(src0[i].fixs16, res.fixs16, vmo.fixs16,
                pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_16_rdn(src0[i].fixs16, res.fixs16, vme.fixs16,
                pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_16_rod(src0[i].fixs16, res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_32_rnu(vlmax_32 - 1, src0[i].fixs32,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_32_rne(src0[i].fixs32, res.fixs32, vmo.fixs32,
                pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_32_rdn(src0[i].fixs32, res.fixs32, vme.fixs32,
                pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_32_rod(src0[i].fixs32, res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_64_rnu(vlmax_64 - 1, src0[i].fixs64,
                res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rnu[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_64_rne(src0[i].fixs64, res.fixs64, vmo.fixs64,
                pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rne[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_64_rdn(src0[i].fixs64, res.fixs64, vme.fixs64,
                pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rdn[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vi_64_rod(src0[i].fixs64, res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rod[i].fixs64[0]);
    }

    return done_testing();
}
