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
        .fixu8 = {
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
            {0xc2, 0x29, 0x99, 0x3e, 0xe3, 0x82, 0x47, 0x89, 0xcd, 0xfb, 0xad, 0x9e, 0xe6, 0x27, 0x14, 0xc9, },
        },
    },
};

struct rvv_reg dst_rnu[] = {
    {
        .fixu64 = {
            {0x0001ffc3a4b95bf8, 0x00007189af349c57,},
            {0x0001ffc3a4b95bf8, 0x0000000000000000,},
        },
        .fixu32 = {
            {0x0003173d, 0x0001d6f2, 0x0003c2fb, 0x0001a0f8,},
            {0x0003173d, 0x0001d6f2, 0x0003c2fb, 0x00000000,},
        },
        .fixu16 = {
            {0x01fd, 0x0097, 0x01e3, 0x0011, 0x00de, 0x001c, 0x01bd, 0x015f,},
            {0x01fd, 0x0097, 0x01e3, 0x0011, 0x00de, 0x001c, 0x01bd, 0x0000,},
        },
        .fixu8 = {
            {0x18, 0x05, 0x13, 0x08, 0x1c, 0x10, 0x09, 0x11, 0x1a, 0x1f, 0x16, 0x14, 0x1d, 0x05, 0x03, 0x19,},
            {0x18, 0x05, 0x13, 0x08, 0x1c, 0x10, 0x09, 0x11, 0x1a, 0x1f, 0x16, 0x14, 0x1d, 0x05, 0x03, 0x00,},
        },
    },
};

/* vmo */
struct rvv_reg dst_rne[] = {
    {
        .fixu64 = {
            {0x1111111111111111, 0x00007189af349c57,},
            {0x1111111111111111, 0x00007189af349c57,},
        },
        .fixu32 = {
            {0x11111111, 0x0001d6f2, 0x11111111, 0x0001a0f8,},
            {0x11111111, 0x0001d6f2, 0x11111111, 0x0001a0f8,},
        },
        .fixu16 = {
            {0x1111, 0x0097, 0x1111, 0x0011, 0x1111, 0x001c, 0x1111, 0x015f,},
            {0x1111, 0x0097, 0x1111, 0x0011, 0x1111, 0x001c, 0x1111, 0x015f,},
        },
        .fixu8 = {
            {0x11, 0x05, 0x11, 0x08, 0x11, 0x10, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x14, 0x11, 0x05, 0x11, 0x19,},
            {0x11, 0x05, 0x11, 0x08, 0x11, 0x10, 0x11, 0x11, 0x11, 0x1f, 0x11, 0x14, 0x11, 0x05, 0x11, 0x19,},
        },
    },
};

/* vme */
struct rvv_reg dst_rdn[] = {
    {
        .fixu64 = {
            {0x0001ffc3a4b95bf8, 0x1111111111111111,},
            {0x0001ffc3a4b95bf8, 0x1111111111111111,},
        },
        .fixu32 = {
            {0x0003173d, 0x11111111, 0x0003c2fb, 0x11111111,},
            {0x0003173d, 0x11111111, 0x0003c2fb, 0x11111111,},
        },
        .fixu16 = {
            {0x01fc, 0x1111, 0x01e2, 0x1111, 0x00de, 0x1111, 0x01bd, 0x1111,},
            {0x01fc, 0x1111, 0x01e2, 0x1111, 0x00de, 0x1111, 0x01bd, 0x1111,},
        },
        .fixu8 = {
            {0x18, 0x11, 0x13, 0x11, 0x1c, 0x11, 0x08, 0x11, 0x19, 0x11, 0x15, 0x11, 0x1c, 0x11, 0x02, 0x11,},
            {0x18, 0x11, 0x13, 0x11, 0x1c, 0x11, 0x08, 0x11, 0x19, 0x11, 0x15, 0x11, 0x1c, 0x11, 0x02, 0x11,},
        },
    },
};

struct rvv_reg dst_rod[] = {
    {
        .fixu64 = {
            {0x0001ffc3a4b95bf9, 0x00007189af349c57,},
            {0x0001ffc3a4b95bf9, 0x00007189af349c57,},
        },
        .fixu32 = {
            {0x0003173d, 0x0001d6f1, 0x0003c2fb, 0x0001a0f9,},
            {0x0003173d, 0x0001d6f1, 0x0003c2fb, 0x0001a0f9,},
        },
        .fixu16 = {
            {0x01fd, 0x0097, 0x01e3, 0x0011, 0x00df, 0x001b, 0x01bd, 0x015f,},
            {0x01fd, 0x0097, 0x01e3, 0x0011, 0x00df, 0x001b, 0x01bd, 0x015f,},
        },
        .fixu8 = {
            {0x19, 0x05, 0x13, 0x07, 0x1d, 0x11, 0x09, 0x11, 0x19, 0x1f, 0x15, 0x13, 0x1d, 0x05, 0x03, 0x19,},
            {0x19, 0x05, 0x13, 0x07, 0x1d, 0x11, 0x09, 0x11, 0x19, 0x1f, 0x15, 0x13, 0x1d, 0x05, 0x03, 0x19,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vssrl.vi\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_8_rnu(vlmax_8 - 1, src0[i].fixu8, res.fixu8, pad.fixu8);
        result_compare_s8_lmul(res.fixu8[0], dst_rnu[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_8_rne(src0[i].fixu8, res.fixu8, vmo.fixu8, pad.fixu8);
        result_compare_s8_lmul(res.fixu8[0], dst_rne[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_8_rdn(src0[i].fixu8, res.fixu8, vme.fixu8, pad.fixu8);
        result_compare_s8_lmul(res.fixu8[0], dst_rdn[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_8_rod(src0[i].fixu8, res.fixu8, pad.fixu8);
        result_compare_s8_lmul(res.fixu8[0], dst_rod[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_16_rnu(vlmax_16 - 1, src0[i].fixu16,
                res.fixu16, pad.fixu16);
        result_compare_s16_lmul(res.fixu16[0], dst_rnu[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_16_rne(src0[i].fixu16, res.fixu16, vmo.fixu16,
                pad.fixu16);
        result_compare_s16_lmul(res.fixu16[0], dst_rne[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_16_rdn(src0[i].fixu16, res.fixu16, vme.fixu16,
                pad.fixu16);
        result_compare_s16_lmul(res.fixu16[0], dst_rdn[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_16_rod(src0[i].fixu16, res.fixu16, pad.fixu16);
        result_compare_s16_lmul(res.fixu16[0], dst_rod[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_32_rnu(vlmax_32 - 1, src0[i].fixu32,
                res.fixu32, pad.fixu32);
        result_compare_s32_lmul(res.fixu32[0], dst_rnu[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_32_rne(src0[i].fixu32, res.fixu32, vmo.fixu32,
                pad.fixu32);
        result_compare_s32_lmul(res.fixu32[0], dst_rne[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_32_rdn(src0[i].fixu32, res.fixu32, vme.fixu32,
                pad.fixu32);
        result_compare_s32_lmul(res.fixu32[0], dst_rdn[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_32_rod(src0[i].fixu32, res.fixu32, pad.fixu32);
        result_compare_s32_lmul(res.fixu32[0], dst_rod[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_64_rnu(vlmax_64 - 1, src0[i].fixu64,
                res.fixu64, pad.fixu64);
        result_compare_s64_lmul(res.fixu64[0], dst_rnu[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_64_rne(src0[i].fixu64, res.fixu64, vmo.fixu64,
                pad.fixu64);
        result_compare_s64_lmul(res.fixu64[0], dst_rne[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_64_rdn(src0[i].fixu64, res.fixu64, vme.fixu64,
                pad.fixu64);
        result_compare_s64_lmul(res.fixu64[0], dst_rdn[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssrl_vi_64_rod(src0[i].fixu64, res.fixu64, pad.fixu64);
        result_compare_s64_lmul(res.fixu64[0], dst_rod[i].fixu64[0]);
    }

    return done_testing();
}
