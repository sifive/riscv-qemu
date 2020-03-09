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
        .fixs64 = {
            {0x0000000000000e5c, 0xffffffff1a98c2cd,},
            {0x0000000000000e5c, 0x0000000000000000,},
        },
        .fixs32 = {
            {0xffffffff, 0xffffffff, 0x00000000, 0xffffffff,},
            {0xffffffff, 0xffffffff, 0x00000000, 0x00000000,},
        },
        .fixs16 = {
            {0xeb6b, 0x0290, 0x0001, 0x003b, 0xd1a5, 0x1350, 0x11d7, 0xffa1,},
            {0xeb6b, 0x0290, 0x0001, 0x003b, 0xd1a5, 0x1350, 0x11d7, 0x0000,},
        },
        .fixs8 = {
            {0xfa, 0x0d, 0xf2, 0x0f, 0xfd, 0x01, 0xf2, 0x0f, 0x02, 0x00, 0x1e, 0x91, 0xff, 0xd6, 0x04, 0x21,},
            {0xfa, 0x0d, 0xf2, 0x0f, 0xfd, 0x01, 0xf2, 0x0f, 0x02, 0x00, 0x1e, 0x91, 0xff, 0xd6, 0x04, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xffffffff1a98c2cd,},
            {0x1111111111111111, 0xffffffff1a98c2cd,},
        },
        .fixs32 = {
            {0x11111111, 0xffffffff, 0x11111111, 0xffffffff,},
            {0x11111111, 0xffffffff, 0x11111111, 0xffffffff,},
        },
        .fixs16 = {
            {0x1111, 0x0290, 0x1111, 0x003b, 0x1111, 0x1350, 0x1111, 0xffa1,},
            {0x1111, 0x0290, 0x1111, 0x003b, 0x1111, 0x1350, 0x1111, 0xffa1,},
        },
        .fixs8 = {
            {0x11, 0x0d, 0x11, 0x0e, 0x11, 0x01, 0x11, 0x0f, 0x11, 0x00, 0x11, 0x91, 0x11, 0xd6, 0x11, 0x21,},
            {0x11, 0x0d, 0x11, 0x0e, 0x11, 0x01, 0x11, 0x0f, 0x11, 0x00, 0x11, 0x91, 0x11, 0xd6, 0x11, 0x21,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixs64 = {
            {0x0000000000000e5c, 0x1111111111111111,},
            {0x0000000000000e5c, 0x1111111111111111,},
        },
        .fixs32 = {
            {0xffffffff, 0x11111111, 0x00000000, 0x11111111,},
            {0xffffffff, 0x11111111, 0x00000000, 0x11111111,},
        },
        .fixs16 = {
            {0xeb6b, 0x1111, 0x0000, 0x1111, 0xd1a4, 0x1111, 0x11d7, 0x1111,},
            {0xeb6b, 0x1111, 0x0000, 0x1111, 0xd1a4, 0x1111, 0x11d7, 0x1111,},
        },
        .fixs8 = {
            {0xfa, 0x11, 0xf1, 0x11, 0xfc, 0x11, 0xf2, 0x11, 0x01, 0x11, 0x1e, 0x11, 0xff, 0x11, 0x04, 0x11,},
            {0xfa, 0x11, 0xf1, 0x11, 0xfc, 0x11, 0xf2, 0x11, 0x01, 0x11, 0x1e, 0x11, 0xff, 0x11, 0x04, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixs64 = {
            {0x0000000000000e5d, 0xffffffff1a98c2cd,},
            {0x0000000000000e5d, 0xffffffff1a98c2cd,},
        },
        .fixs32 = {
            {0xffffffff, 0xffffffff, 0x00000001, 0xffffffff,},
            {0xffffffff, 0xffffffff, 0x00000001, 0xffffffff,},
        },
        .fixs16 = {
            {0xeb6b, 0x028f, 0x0001, 0x003b, 0xd1a5, 0x134f, 0x11d7, 0xffa1,},
            {0xeb6b, 0x028f, 0x0001, 0x003b, 0xd1a5, 0x134f, 0x11d7, 0xffa1,},
        },
        .fixs8 = {
            {0xfb, 0x0d, 0xf1, 0x0f, 0xfd, 0x01, 0xf3, 0x0f, 0x01, 0x01, 0x1e, 0x91, 0xff, 0xd5, 0x05, 0x21,},
            {0xfb, 0x0d, 0xf1, 0x0f, 0xfd, 0x01, 0xf3, 0x0f, 0x01, 0x01, 0x1e, 0x91, 0xff, 0xd5, 0x05, 0x21,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vssra.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_8_rnu(vlmax_8 - 1, src0[i].fixs8, src1[i].fixu8,
                res.fixs8, pad.fixs8);
        result_compare_u8_lmul(res.fixs8[0], dst_rnu[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_8_rne(src0[i].fixs8, src1[i].fixu8,
                res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_u8_lmul(res.fixs8[0], dst_rne[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_8_rdn(src0[i].fixs8, src1[i].fixu8,
                res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_u8_lmul(res.fixs8[0], dst_rdn[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_8_rod(src0[i].fixs8, src1[i].fixu8, res.fixs8);
        result_compare_u8_lmul(res.fixs8[0], dst_rod[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_16_rnu(vlmax_16 - 1, src0[i].fixs16,
                src1[i].fixu16, res.fixs16, pad.fixs16);
        result_compare_u16_lmul(res.fixs16[0], dst_rnu[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_16_rne(src0[i].fixs16, src1[i].fixu16,
                res.fixs16, vmo.fixs16, pad.fixs16);
        result_compare_u16_lmul(res.fixs16[0], dst_rne[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_16_rdn(src0[i].fixs16, src1[i].fixu16,
                res.fixs16, vme.fixs16, pad.fixs16);
        result_compare_u16_lmul(res.fixs16[0], dst_rdn[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_16_rod(src0[i].fixs16, src1[i].fixu16, res.fixs16);
        result_compare_u16_lmul(res.fixs16[0], dst_rod[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_32_rnu(vlmax_32 - 1, src0[i].fixs32, src1[i].fixu32,
                res.fixs32, pad.fixs32);
        result_compare_u32_lmul(res.fixs32[0], dst_rnu[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_32_rne(src0[i].fixs32, src1[i].fixu32,
                res.fixs32, vmo.fixs32, pad.fixs32);
        result_compare_u32_lmul(res.fixs32[0], dst_rne[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_32_rdn(src0[i].fixs32, src1[i].fixu32,
                res.fixs32, vme.fixs32, pad.fixs32);
        result_compare_u32_lmul(res.fixs32[0], dst_rdn[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_32_rod(src0[i].fixs32, src1[i].fixu32, res.fixs32);
        result_compare_u32_lmul(res.fixs32[0], dst_rod[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_64_rnu(vlmax_64 - 1, src0[i].fixs64, src1[i].fixu64,
                res.fixs64, pad.fixs64);
        result_compare_u64_lmul(res.fixs64[0], dst_rnu[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_64_rne(src0[i].fixs64, src1[i].fixu64,
                res.fixs64, vmo.fixs64, pad.fixs64);
        result_compare_u64_lmul(res.fixs64[0], dst_rne[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_64_rdn(src0[i].fixs64, src1[i].fixu64,
                res.fixs64, vme.fixs64, pad.fixs64);
        result_compare_u64_lmul(res.fixs64[0], dst_rdn[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssra_vv_64_rod(src0[i].fixs64, src1[i].fixu64, res.fixs64);
        result_compare_u64_lmul(res.fixs64[0], dst_rod[i].fixs64[0]);
    }

    return done_testing();
}
