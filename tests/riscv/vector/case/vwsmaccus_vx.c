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
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .wfixs64 = {
            {0x07d2219a70ff2796, 0x071880c928612a72, 0x07d210137618adb2, 0x07186bb388e33ec8,},
            {0x07d2219a70ff2796, 0x071880c928612a72, 0x07d210137618adb2, 0x0000000000000000,},
        },
        .wfixs32 = {
            {0x77a444d8, 0xf1a0f1a7, 0x67dd59f0, 0x12d9c22b, 0x77b79984, 0xf1a2b4c2, 0x67c8f0e6, 0x1302b89d,},
            {0x77a444d8, 0xf1a0f1a7, 0x67dd59f0, 0x12d9c22b, 0x77b79984, 0xf1a2b4c2, 0x67c8f0e6, 0x00000000,},
        },
        .wfixs16 = {
            {0x51d4, 0x387e, 0x69f5, 0xf7e7, 0xcfb0, 0x96c6, 0x32a9, 0xcce1, 0x4d7e, 0x391f, 0x65e0, 0xfd2b, 0xce93, 0x9b76, 0x2f4c, 0xcef1,},
            {0x51d4, 0x387e, 0x69f5, 0xf7e7, 0xcfb0, 0x96c6, 0x32a9, 0xcce1, 0x4d7e, 0x391f, 0x65e0, 0xfd2b, 0xce93, 0x9b76, 0x2f4c, 0x0000,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x071880c928612a72, 0x07d215928aa0d7b6, 0x07186bb388e33ec8,},
            {0x07d215928aa0d7b6, 0x071880c928612a72, 0x07d215928aa0d7b6, 0x07186bb388e33ec8,},
        },
        .wfixs32 = {
            {0x7794d541, 0xf1a0f1a7, 0x67e3b37f, 0x12d9c22b, 0x7794d541, 0xf1a2b4c2, 0x67e3b37f, 0x1302b89d,},
            {0x7794d541, 0xf1a0f1a7, 0x67e3b37f, 0x12d9c22b, 0x7794d541, 0xf1a2b4c2, 0x67e3b37f, 0x1302b89d,},
        },
        .wfixs16 = {
            {0x4fb8, 0x387e, 0x6744, 0xf7e7, 0xce81, 0x96c6, 0x301c, 0xcce1, 0x4fb8, 0x391f, 0x6744, 0xfd2b, 0xce81, 0x9b76, 0x301c, 0xcef1,},
            {0x4fb8, 0x387e, 0x6744, 0xf7e7, 0xce81, 0x96c6, 0x301c, 0xcce1, 0x4fb8, 0x391f, 0x6744, 0xfd2b, 0xce81, 0x9b76, 0x301c, 0xcef1,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .wfixs64 = {
            {0x07d2219a70ff2797, 0x07186161e5f9e80f, 0x07d210137618adb3, 0x07186161e5f9e80f,},
            {0x07d2219a70ff2797, 0x07186161e5f9e80f, 0x07d210137618adb3, 0x07186161e5f9e80f,},
        },
        .wfixs32 = {
            {0x77a444d8, 0xf1bfac15, 0x67dd59f0, 0x12df3e7c, 0x77b79985, 0xf1bfac15, 0x67c8f0e7, 0x12df3e7c,},
            {0x77a444d8, 0xf1bfac15, 0x67dd59f0, 0x12df3e7c, 0x77b79985, 0xf1bfac15, 0x67c8f0e7, 0x12df3e7c,},
        },
        .wfixs16 = {
            {0x51d5, 0x39b3, 0x69f5, 0xfa98, 0xcfb0, 0x997d, 0x32aa, 0xcfb5, 0x4d7e, 0x39b3, 0x65e0, 0xfa98, 0xce93, 0x997d, 0x2f4d, 0xcfb5,},
            {0x51d5, 0x39b3, 0x69f5, 0xfa98, 0xcfb0, 0x997d, 0x32aa, 0xcfb5, 0x4d7e, 0x39b3, 0x65e0, 0xfa98, 0xce93, 0x997d, 0x2f4d, 0xcfb5,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .wfixs64 = {
            {0x07d2219a70ff2797, 0x071880c928612a72, 0x07d210137618adb3, 0x07186bb388e33ec8,},
            {0x07d2219a70ff2797, 0x071880c928612a72, 0x07d210137618adb3, 0x07186bb388e33ec8,},
        },
        .wfixs32 = {
            {0x77a444d8, 0xf1a0f1a6, 0x67dd59f0, 0x12d9c22b, 0x77b79984, 0xf1a2b4c2, 0x67c8f0e6, 0x1302b89d,},
            {0x77a444d8, 0xf1a0f1a6, 0x67dd59f0, 0x12d9c22b, 0x77b79984, 0xf1a2b4c2, 0x67c8f0e6, 0x1302b89d,},
        },
        .wfixs16 = {
            {0x51d5, 0x387e, 0x69f5, 0xf7e7, 0xcfb0, 0x96c6, 0x32a9, 0xcce0, 0x4d7e, 0x391e, 0x65df, 0xfd2b, 0xce92, 0x9b76, 0x2f4d, 0xcef2,},
            {0x51d5, 0x387e, 0x69f5, 0xf7e7, 0xcfb0, 0x96c6, 0x32a9, 0xcce0, 0x4d7e, 0x391e, 0x65df, 0xfd2b, 0xce92, 0x9b76, 0x2f4d, 0xcef2,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsmaccus.vx\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_8_rnu(vlmax_8 - 1, src0[i].fixs8, src1_u8,
                src2[i].wfixs16, res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rnu[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rnu[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_8_rne(src0[i].fixs8, src1_u8, src2[i].wfixs16,
                res.wfixs16, vmo.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rne[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rne[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_8_rdn(src0[i].fixs8, src1_u8, src2[i].wfixs16,
                res.wfixs16, vme.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rdn[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rdn[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_8_rod(src0[i].fixs8, src1_u8, src2[i].wfixs16,
                res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rod[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rod[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_16_rnu(vlmax_16 - 1, src0[i].fixs16, src1_u16,
                src2[i].wfixs32, res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rnu[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rnu[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_16_rne(src0[i].fixs16, src1_u16, src2[i].wfixs32,
                res.wfixs32, vmo.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rne[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rne[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_16_rdn(src0[i].fixs16, src1_u16, src2[i].wfixs32,
                res.wfixs32, vme.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rdn[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rdn[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_16_rod(src0[i].fixs16, src1_u16, src2[i].wfixs32,
                res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rod[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rod[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_32_rnu(vlmax_32 - 1, src0[i].fixs32, src1_u32,
                src2[i].wfixs64, res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rnu[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rnu[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_32_rne(src0[i].fixs32, src1_u32, src2[i].wfixs64,
                res.wfixs64, vmo.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rne[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rne[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_32_rdn(src0[i].fixs32, src1_u32, src2[i].wfixs64,
                res.wfixs64, vme.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rdn[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rdn[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccus_vx_32_rod(src0[i].fixs32, src1_u32, src2[i].wfixs64,
                res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rod[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rod[i].wfixs64[1]);
    }

    return done_testing();
}
