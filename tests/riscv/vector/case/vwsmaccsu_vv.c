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
    },
};

struct rvv_reg src1[] = {
    {
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
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .wfixs64 = {
            {0x07d24059fc13751b, 0x0718b917b9304326, 0x07d209d822aac498, 0x071865ef32ba1068,},
            {0x07d24059fc13751b, 0x0718b917b9304326, 0x07d209d822aac498, 0x0000000000000000,},
        },
        .wfixs32 = {
            {0x77a4d2ab, 0xf1acb339, 0x67decfab, 0x12d80912, 0x77ce4882, 0xf17f13fd, 0x67c9e560, 0x133c7aa8,},
            {0x77a4d2ab, 0xf1acb339, 0x67decfab, 0x12d80912, 0x77ce4882, 0xf17f13fd, 0x67c9e560, 0x00000000,},
        },
        .wfixs16 = {
            {0x5057, 0x38dc, 0x6d3e, 0xf83e, 0xd059, 0x9701, 0x336a, 0xcada, 0x4ba4, 0x38c9, 0x6650, 0xfbad, 0xce8c, 0x9b56, 0x2ec9, 0xcece,},
            {0x5057, 0x38dc, 0x6d3e, 0xf83e, 0xd059, 0x9701, 0x336a, 0xcada, 0x4ba4, 0x38c9, 0x6650, 0xfbad, 0xce8c, 0x9b56, 0x2ec9, 0x0000,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x0718b917b9304326, 0x07d215928aa0d7b6, 0x071865ef32ba1068,},
            {0x07d215928aa0d7b6, 0x0718b917b9304326, 0x07d215928aa0d7b6, 0x071865ef32ba1068,},
        },
        .wfixs32 = {
            {0x7794d541, 0xf1acb339, 0x67e3b37f, 0x12d80912, 0x7794d541, 0xf17f13fd, 0x67e3b37f, 0x133c7aa8,},
            {0x7794d541, 0xf1acb339, 0x67e3b37f, 0x12d80912, 0x7794d541, 0xf17f13fd, 0x67e3b37f, 0x133c7aa8,},
        },
        .wfixs16 = {
            {0x4fb8, 0x38dd, 0x6744, 0xf83e, 0xce81, 0x9701, 0x301c, 0xcada, 0x4fb8, 0x38c9, 0x6744, 0xfbae, 0xce81, 0x9b56, 0x301c, 0xcece,},
            {0x4fb8, 0x38dd, 0x6744, 0xf83e, 0xce81, 0x9701, 0x301c, 0xcada, 0x4fb8, 0x38c9, 0x6744, 0xfbae, 0xce81, 0x9b56, 0x301c, 0xcece,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .wfixs64 = {
            {0x07d24059fc13751c, 0x07186161e5f9e80f, 0x07d209d822aac499, 0x07186161e5f9e80f,},
            {0x07d24059fc13751c, 0x07186161e5f9e80f, 0x07d209d822aac499, 0x07186161e5f9e80f,},
        },
        .wfixs32 = {
            {0x77a4d2ab, 0xf1bfac15, 0x67decfab, 0x12df3e7c, 0x77ce4883, 0xf1bfac15, 0x67c9e560, 0x12df3e7c,},
            {0x77a4d2ab, 0xf1bfac15, 0x67decfab, 0x12df3e7c, 0x77ce4883, 0xf1bfac15, 0x67c9e560, 0x12df3e7c,},
        },
        .wfixs16 = {
            {0x5058, 0x39b3, 0x6d3e, 0xfa98, 0xd059, 0x997d, 0x336a, 0xcfb5, 0x4ba4, 0x39b3, 0x6651, 0xfa98, 0xce8c, 0x997d, 0x2ec9, 0xcfb5,},
            {0x5058, 0x39b3, 0x6d3e, 0xfa98, 0xd059, 0x997d, 0x336a, 0xcfb5, 0x4ba4, 0x39b3, 0x6651, 0xfa98, 0xce8c, 0x997d, 0x2ec9, 0xcfb5,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .wfixs64 = {
            {0x07d24059fc13751b, 0x0718b917b9304326, 0x07d209d822aac499, 0x071865ef32ba1068,},
            {0x07d24059fc13751b, 0x0718b917b9304326, 0x07d209d822aac499, 0x071865ef32ba1068,},
        },
        .wfixs32 = {
            {0x77a4d2aa, 0xf1acb338, 0x67decfaa, 0x12d80913, 0x77ce4882, 0xf17f13fc, 0x67c9e560, 0x133c7aa7,},
            {0x77a4d2aa, 0xf1acb338, 0x67decfaa, 0x12d80913, 0x77ce4882, 0xf17f13fc, 0x67c9e560, 0x133c7aa7,},
        },
        .wfixs16 = {
            {0x5057, 0x38dc, 0x6d3d, 0xf83f, 0xd058, 0x9700, 0x3369, 0xcada, 0x4ba4, 0x38c8, 0x6651, 0xfbad, 0xce8c, 0x9b56, 0x2ec9, 0xcece,},
            {0x5057, 0x38dc, 0x6d3d, 0xf83f, 0xd058, 0x9700, 0x3369, 0xcada, 0x4ba4, 0x38c8, 0x6651, 0xfbad, 0xce8c, 0x9b56, 0x2ec9, 0xcece,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsmaccsu.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_8_rnu(vlmax_8 - 1, src0[i].fixs8, src1[i].fixu8,
                src2[i].wfixs16, res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rnu[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rnu[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_8_rne(src0[i].fixs8, src1[i].fixu8, src2[i].wfixs16,
                res.wfixs16, vmo.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rne[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rne[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_8_rdn(src0[i].fixs8, src1[i].fixu8, src2[i].wfixs16,
                res.wfixs16, vme.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rdn[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rdn[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_8_rod(src0[i].fixs8, src1[i].fixu8, src2[i].wfixs16,
                res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rod[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rod[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_16_rnu(vlmax_16 - 1, src0[i].fixs16, src1[i].fixu16,
                src2[i].wfixs32, res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rnu[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rnu[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_16_rne(src0[i].fixs16, src1[i].fixu16, src2[i].wfixs32,
                res.wfixs32, vmo.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rne[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rne[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_16_rdn(src0[i].fixs16, src1[i].fixu16, src2[i].wfixs32,
                res.wfixs32, vme.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rdn[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rdn[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_16_rod(src0[i].fixs16, src1[i].fixu16, src2[i].wfixs32,
                res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rod[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rod[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_32_rnu(vlmax_32 - 1, src0[i].fixs32, src1[i].fixu32,
                src2[i].wfixs64, res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rnu[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rnu[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_32_rne(src0[i].fixs32, src1[i].fixu32, src2[i].wfixs64,
                res.wfixs64, vmo.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rne[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rne[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_32_rdn(src0[i].fixs32, src1[i].fixu32, src2[i].wfixs64,
                res.wfixs64, vme.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rdn[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rdn[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vv_32_rod(src0[i].fixs32, src1[i].fixu32, src2[i].wfixs64,
                res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rod[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rod[i].wfixs64[1]);
    }

    return done_testing();
}
