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
            {0x18cf500358088d2e, 0xdfc6e7a8b0f6a7b6,},
            {0x18cf500358088d2e, 0x0000000000000000,},
        },
        .fixs32 = {
            {0xac25c8a3, 0xc851a526, 0xd70c4f51, 0xe1ed1aef,},
            {0xac25c8a3, 0xc851a526, 0xd70c4f51, 0x00000000,},
        },
        .fixs16 = {
            {0xc38f, 0x0c20, 0xd4d6, 0x0a05, 0xea64, 0x59e1, 0x0ba1, 0xe8d8,},
            {0xc38f, 0x0c20, 0xd4d6, 0x0a05, 0xea64, 0x59e1, 0x0ba1, 0x0000,},
        },
        .fixs8 = {
            {0xc2, 0x3f, 0x00, 0x1d, 0xf6, 0x36, 0x01, 0x33, 0x1a, 0x03, 0x48, 0x06, 0xeb, 0xef, 0xea, 0x33,},
            {0xc2, 0x3f, 0x00, 0x1d, 0xf6, 0x36, 0x01, 0x33, 0x1a, 0x03, 0x48, 0x06, 0xeb, 0xef, 0xea, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xdfc6e7a8b0f6a7b6,},
            {0x1111111111111111, 0xdfc6e7a8b0f6a7b6,},
        },
        .fixs32 = {
            {0x11111111, 0xc851a526, 0x11111111, 0xe1ed1aef,},
            {0x11111111, 0xc851a526, 0x11111111, 0xe1ed1aef,},
        },
        .fixs16 = {
            {0x1111, 0x0c20, 0x1111, 0x0a04, 0x1111, 0x59e1, 0x1111, 0xe8d8,},
            {0x1111, 0x0c20, 0x1111, 0x0a04, 0x1111, 0x59e1, 0x1111, 0xe8d8,},
        },
        .fixs8 = {
            {0x11, 0x3f, 0x11, 0x1d, 0x11, 0x36, 0x11, 0x32, 0x11, 0x03, 0x11, 0x06, 0x11, 0xee, 0x11, 0x33,},
            {0x11, 0x3f, 0x11, 0x1d, 0x11, 0x36, 0x11, 0x32, 0x11, 0x03, 0x11, 0x06, 0x11, 0xee, 0x11, 0x33,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs64 = {
            {0x18cf500358088d2e, 0x1111111111111111,},
            {0x18cf500358088d2e, 0x1111111111111111,},
        },
        .fixs32 = {
            {0xac25c8a2, 0x11111111, 0xd70c4f51, 0x11111111,},
            {0xac25c8a2, 0x11111111, 0xd70c4f51, 0x11111111,},
        },
        .fixs16 = {
            {0xc38f, 0x1111, 0xd4d5, 0x1111, 0xea64, 0x1111, 0x0ba0, 0x1111,},
            {0xc38f, 0x1111, 0xd4d5, 0x1111, 0xea64, 0x1111, 0x0ba0, 0x1111,},
        },
        .fixs8 = {
            {0xc2, 0x11, 0xff, 0x11, 0xf5, 0x11, 0x01, 0x11, 0x1a, 0x11, 0x48, 0x11, 0xea, 0x11, 0xea, 0x11,},
            {0xc2, 0x11, 0xff, 0x11, 0xf5, 0x11, 0x01, 0x11, 0x1a, 0x11, 0x48, 0x11, 0xea, 0x11, 0xea, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs64 = {
            {0x18cf500358088d2e, 0xdfc6e7a8b0f6a7b6,},
            {0x18cf500358088d2e, 0xdfc6e7a8b0f6a7b6,},
        },
        .fixs32 = {
            {0xac25c8a3, 0xc851a526, 0xd70c4f51, 0xe1ed1aef,},
            {0xac25c8a3, 0xc851a526, 0xd70c4f51, 0xe1ed1aef,},
        },
        .fixs16 = {
            {0xc38f, 0x0c1f, 0xd4d5, 0x0a05, 0xea64, 0x59e1, 0x0ba1, 0xe8d7,},
            {0xc38f, 0x0c1f, 0xd4d5, 0x0a05, 0xea64, 0x59e1, 0x0ba1, 0xe8d7,},
        },
        .fixs8 = {
            {0xc2, 0x3f, 0xff, 0x1d, 0xf5, 0x36, 0x01, 0x33, 0x1a, 0x03, 0x48, 0x05, 0xeb, 0xef, 0xea, 0x33,},
            {0xc2, 0x3f, 0xff, 0x1d, 0xf5, 0x36, 0x01, 0x33, 0x1a, 0x03, 0x48, 0x05, 0xeb, 0xef, 0xea, 0x33,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vasub.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_8_rnu(vlmax_8 - 1, src0[i].fixs8, src1[i].fixs8,
                res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_8_rne(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_8_rdn(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_8_rod(src0[i].fixs8, src1[i].fixs8, res.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_16_rnu(vlmax_16 - 1, src0[i].fixs16,
                src1[i].fixs16, res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_16_rne(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vmo.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_16_rdn(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vme.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_16_rod(src0[i].fixs16, src1[i].fixs16, res.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_32_rnu(vlmax_32 - 1, src0[i].fixs32, src1[i].fixs32,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_32_rne(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vmo.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_32_rdn(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vme.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_32_rod(src0[i].fixs32, src1[i].fixs32, res.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_64_rnu(vlmax_64 - 1, src0[i].fixs64, src1[i].fixs64,
                res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rnu[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_64_rne(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vmo.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rne[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_64_rdn(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vme.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rdn[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vasub_vv_64_rod(src0[i].fixs64, src1[i].fixs64, res.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rod[i].fixs64[0]);
    }

    return done_testing();
}
