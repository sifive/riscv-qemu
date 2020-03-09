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
            {0x07d2787a39981e99, 0x07189c4023d5a89b, 0x07d28df1eab42619, 0x07189580e7ff1053,},
            {0x07d2787a39981e99, 0x07189c4023d5a89b, 0x07d28df1eab42619, 0x0000000000000000,},
        },
        .wfixs32 = {
            {0x77e4cc51, 0xf1d75fd4, 0x682f993e, 0x12e1fd80, 0x77b7c25f, 0xf1c40749, 0x6829ba0f, 0x13167fac,},
            {0x77e4cc51, 0xf1d75fd4, 0x682f993e, 0x12e1fd80, 0x77b7c25f, 0xf1c40749, 0x6829ba0f, 0x00000000,},
        },
        .wfixs16 = {
            {0x49cc, 0x3873, 0x6299, 0xf8b4, 0xc794, 0x9585, 0x2df1, 0xcb87, 0x4976, 0x320a, 0x61fc, 0xf5c6, 0xc77c, 0x984c, 0x2f80, 0xc993,},
            {0x49cc, 0x3873, 0x6299, 0xf8b4, 0xc794, 0x9585, 0x2df1, 0xcb87, 0x4976, 0x320a, 0x61fc, 0xf5c6, 0xc77c, 0x984c, 0x2f80, 0x0000,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .wfixs64 = {
            {0x07d215928aa0d7b6, 0x07189c4023d5a89b, 0x07d215928aa0d7b6, 0x07189580e7ff1053,},
            {0x07d215928aa0d7b6, 0x07189c4023d5a89b, 0x07d215928aa0d7b6, 0x07189580e7ff1053,},
        },
        .wfixs32 = {
            {0x7794d541, 0xf1d75fd4, 0x67e3b37f, 0x12e1fd80, 0x7794d541, 0xf1c40749, 0x67e3b37f, 0x13167fac,},
            {0x7794d541, 0xf1d75fd4, 0x67e3b37f, 0x12e1fd80, 0x7794d541, 0xf1c40749, 0x67e3b37f, 0x13167fac,},
        },
        .wfixs16 = {
            {0x4fb8, 0x3873, 0x6744, 0xf8b4, 0xce81, 0x9585, 0x301c, 0xcb87, 0x4fb8, 0x320a, 0x6744, 0xf5c6, 0xce81, 0x984c, 0x301c, 0xc993,},
            {0x4fb8, 0x3873, 0x6744, 0xf8b4, 0xce81, 0x9585, 0x301c, 0xcb87, 0x4fb8, 0x320a, 0x6744, 0xf5c6, 0xce81, 0x984c, 0x301c, 0xc993,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .wfixs64 = {
            {0x07d2787a39981e99, 0x07186161e5f9e80f, 0x07d28df1eab4261a, 0x07186161e5f9e80f,},
            {0x07d2787a39981e99, 0x07186161e5f9e80f, 0x07d28df1eab4261a, 0x07186161e5f9e80f,},
        },
        .wfixs32 = {
            {0x77e4cc51, 0xf1bfac15, 0x682f993e, 0x12df3e7c, 0x77b7c25f, 0xf1bfac15, 0x6829ba10, 0x12df3e7c,},
            {0x77e4cc51, 0xf1bfac15, 0x682f993e, 0x12df3e7c, 0x77b7c25f, 0xf1bfac15, 0x6829ba10, 0x12df3e7c,},
        },
        .wfixs16 = {
            {0x49cd, 0x39b3, 0x6299, 0xfa98, 0xc794, 0x997d, 0x2df2, 0xcfb5, 0x4977, 0x39b3, 0x61fd, 0xfa98, 0xc77d, 0x997d, 0x2f80, 0xcfb5,},
            {0x49cd, 0x39b3, 0x6299, 0xfa98, 0xc794, 0x997d, 0x2df2, 0xcfb5, 0x4977, 0x39b3, 0x61fd, 0xfa98, 0xc77d, 0x997d, 0x2f80, 0xcfb5,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .wfixs64 = {
            {0x07d2787a39981e99, 0x07189c4023d5a89c, 0x07d28df1eab42619, 0x07189580e7ff1052,},
            {0x07d2787a39981e99, 0x07189c4023d5a89c, 0x07d28df1eab42619, 0x07189580e7ff1052,},
        },
        .wfixs32 = {
            {0x77e4cc50, 0xf1d75fd4, 0x682f993e, 0x12e1fd7f, 0x77b7c25e, 0xf1c40748, 0x6829ba10, 0x13167fab,},
            {0x77e4cc50, 0xf1d75fd4, 0x682f993e, 0x12e1fd7f, 0x77b7c25e, 0xf1c40748, 0x6829ba10, 0x13167fab,},
        },
        .wfixs16 = {
            {0x49cd, 0x3872, 0x6299, 0xf8b3, 0xc794, 0x9586, 0x2df1, 0xcb86, 0x4977, 0x320a, 0x61fd, 0xf5c5, 0xc77c, 0x984c, 0x2f7f, 0xc992,},
            {0x49cd, 0x3872, 0x6299, 0xf8b3, 0xc794, 0x9586, 0x2df1, 0xcb86, 0x4977, 0x320a, 0x61fd, 0xf5c5, 0xc77c, 0x984c, 0x2f7f, 0xc992,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vwsmaccsu.vx\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_8_rnu(vlmax_8 - 1, src0[i].fixu8, src1_s8,
                src2[i].wfixs16, res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rnu[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rnu[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_8_rne(src0[i].fixu8, src1_s8, src2[i].wfixs16,
                res.wfixs16, vmo.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rne[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rne[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_8_rdn(src0[i].fixu8, src1_s8, src2[i].wfixs16,
                res.wfixs16, vme.fixs8);
        result_compare_s16_lmul(res.wfixs16[0], dst_rdn[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rdn[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_8_rod(src0[i].fixu8, src1_s8, src2[i].wfixs16,
                res.wfixs16);
        result_compare_s16_lmul(res.wfixs16[0], dst_rod[i].wfixs16[0]);
        result_compare_s16_lmul(res.wfixs16[1], dst_rod[i].wfixs16[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_16_rnu(vlmax_16 - 1, src0[i].fixu16, src1_s16,
                src2[i].wfixs32, res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rnu[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rnu[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_16_rne(src0[i].fixu16, src1_s16, src2[i].wfixs32,
                res.wfixs32, vmo.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rne[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rne[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_16_rdn(src0[i].fixu16, src1_s16, src2[i].wfixs32,
                res.wfixs32, vme.fixs16);
        result_compare_s32_lmul(res.wfixs32[0], dst_rdn[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rdn[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_16_rod(src0[i].fixu16, src1_s16, src2[i].wfixs32,
                res.wfixs32);
        result_compare_s32_lmul(res.wfixs32[0], dst_rod[i].wfixs32[0]);
        result_compare_s32_lmul(res.wfixs32[1], dst_rod[i].wfixs32[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_32_rnu(vlmax_32 - 1, src0[i].fixu32, src1_s32,
                src2[i].wfixs64, res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rnu[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rnu[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_32_rne(src0[i].fixu32, src1_s32, src2[i].wfixs64,
                res.wfixs64, vmo.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rne[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rne[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_32_rdn(src0[i].fixu32, src1_s32, src2[i].wfixs64,
                res.wfixs64, vme.fixs32);
        result_compare_s64_lmul(res.wfixs64[0], dst_rdn[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rdn[i].wfixs64[1]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vwsmaccsu_vx_32_rod(src0[i].fixu32, src1_s32, src2[i].wfixs64,
                res.wfixs64);
        result_compare_s64_lmul(res.wfixs64[0], dst_rod[i].wfixs64[0]);
        result_compare_s64_lmul(res.wfixs64[1], dst_rod[i].wfixs64[1]);
    }

    return done_testing();
}
