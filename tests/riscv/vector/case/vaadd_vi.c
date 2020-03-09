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
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .fixs64 = {
            {0x1cb85acc9d58f910, 0xe3531859a3f39bc5,},
            {0x1cb85acc9d58f910, 0x0000000000000000,},
        },
        .fixs32 = {
            {0xe7f0334a, 0xc1317b38, 0x0afe2918, 0xeb5cba34,},
            {0xe7f0334a, 0xc1317b38, 0x0afe2918, 0x00000000,},
        },
        .fixs16 = {
            {0xeb72, 0x2900, 0x087f, 0x0758, 0xd1ac, 0x26a7, 0x23b6, 0xd0b9,},
            {0xeb72, 0x2900, 0x087f, 0x0758, 0xd1ac, 0x26a7, 0x23b6, 0x00000,},
        },
        .fixs8 = {
            {0xda, 0x21, 0xcd, 0x41, 0xee, 0x42, 0xd0, 0x44, 0x37, 0x14, 0x25, 0xd0, 0x06, 0xdd, 0x19, 0x18,},
            {0xda, 0x21, 0xcd, 0x41, 0xee, 0x42, 0xd0, 0x44, 0x37, 0x14, 0x25, 0xd0, 0x06, 0xdd, 0x19, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xe3531859a3f39bc4, },
            {0x1111111111111111, 0xe3531859a3f39bc4, },
        },
        .fixs32 = {
            {0x11111111, 0xc1317b38, 0x11111111, 0xeb5cba34,},
            {0x11111111, 0xc1317b38, 0x11111111, 0xeb5cba34,},
        },
        .fixs16 = {
            {0x1111, 0x2900, 0x1111, 0x0758, 0x1111, 0x26a6, 0x1111, 0xd0b9,},
            {0x1111, 0x2900, 0x1111, 0x0758, 0x1111, 0x26a6, 0x1111, 0xd0b9,},
        },
        .fixs8 = {
            {0x11, 0x21, 0x11, 0x41, 0x11, 0x42, 0x11, 0x44, 0x11, 0x14, 0x11, 0xd0, 0x11, 0xdc, 0x11, 0x18,},
            {0x11, 0x21, 0x11, 0x41, 0x11, 0x42, 0x11, 0x44, 0x11, 0x14, 0x11, 0xd0, 0x11, 0xdc, 0x11, 0x18,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs64 = {
            {0x1cb85acc9d58f910, 0x1111111111111111,},
            {0x1cb85acc9d58f910, 0x1111111111111111,},
        },
        .fixs32 = {
            {0xe7f0334a, 0x11111111, 0x0afe2917, 0x11111111,},
            {0xe7f0334a, 0x11111111, 0x0afe2917, 0x11111111,},
        },
        .fixs16 = {
            {0xeb72, 0x1111, 0x087e, 0x1111, 0xd1ab, 0x1111, 0x23b5, 0x1111,},
            {0xeb72, 0x1111, 0x087e, 0x1111, 0xd1ab, 0x1111, 0x23b5, 0x1111,},
        },
        .fixs8 = {
            {0xd9, 0x11, 0xcd, 0x11, 0xed, 0x11, 0xd0, 0x11, 0x37, 0x11, 0x25, 0x11, 0x05, 0x11, 0x18, 0x11,},
            {0xd9, 0x11, 0xcd, 0x11, 0xed, 0x11, 0xd0, 0x11, 0x37, 0x11, 0x25, 0x11, 0x05, 0x11, 0x18, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs64 = {
            {0x1cb85acc9d58f910, 0xe3531859a3f39bc4,},
            {0x1cb85acc9d58f910, 0xe3531859a3f39bc4,},
        },
        .fixs32 = {
            {0xe7f0334a, 0xc1317b37, 0x0afe2917, 0xeb5cba34,},
            {0xe7f0334a, 0xc1317b37, 0x0afe2917, 0xeb5cba34,},
        },
        .fixs16 = {
            {0xeb72, 0x2900, 0x087f, 0x0757, 0xd1ab, 0x26a7, 0x23b5, 0xd0b9,},
            {0xeb72, 0x2900, 0x087f, 0x0757, 0xd1ab, 0x26a7, 0x23b5, 0xd0b9,},
        },
        .fixs8 = {
            {0xd9, 0x21, 0xcd, 0x41, 0xed, 0x41, 0xd0, 0x44, 0x37, 0x13, 0x25, 0xcf, 0x05, 0xdd, 0x19, 0x17,},
            {0xd9, 0x21, 0xcd, 0x41, 0xed, 0x41, 0xd0, 0x44, 0x37, 0x13, 0x25, 0xcf, 0x05, 0xdd, 0x19, 0x17,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vaadd.vi\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_8_rnu(vlmax_8 - 1, src0[i].fixs8, res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_8_rne(src0[i].fixs8, res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_8_rdn(src0[i].fixs8, res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_8_rod(src0[i].fixs8, res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_16_rnu(vlmax_16 - 1, src0[i].fixs16,
                res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_16_rne(src0[i].fixs16, res.fixs16, vmo.fixs16,
                pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_16_rdn(src0[i].fixs16, res.fixs16, vme.fixs16,
                pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_16_rod(src0[i].fixs16, res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_32_rnu(vlmax_32 - 1, src0[i].fixs32,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_32_rne(src0[i].fixs32, res.fixs32, vmo.fixs32,
                pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_32_rdn(src0[i].fixs32, res.fixs32, vme.fixs32,
                pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_32_rod(src0[i].fixs32, res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_64_rnu(vlmax_64 - 1, src0[i].fixs64,
                res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rnu[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_64_rne(src0[i].fixs64, res.fixs64, vmo.fixs64,
                pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rne[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_64_rdn(src0[i].fixs64, res.fixs64, vme.fixs64,
                pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rdn[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vaadd_vi_64_rod(src0[i].fixs64, res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_rod[i].fixs64[0]);
    }

    return done_testing();
}
