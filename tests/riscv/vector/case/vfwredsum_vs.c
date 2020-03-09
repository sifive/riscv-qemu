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
        .float64 = {
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
        },
        .float32 = {
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
        },
        .float16 = {
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
            {0x4aee, 0x40aa, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626, },
        },
    },
};

struct rvv_reg src1[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
        },
        .float32 = {
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        },
        .float16 = {
            {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
            {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float64 = {
            {0xc11e54542d0295ff,},
        },
        .float32 = {
            {0x4834600e,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float64 = {
            {0x4125b6c5757eb500,},
        },
        .float32 = {
            {0x48348b9f},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0x40e9511497eb5008,},
        },
        .float32 = {
            {0x483476de,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfwredsum.vs\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_16(vlmax_16 - 1, src0[i].float32[0],
                src1[i].float16[0], res.float32[0], pad.fixu32[0]);
        result_compare_s32(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_16_vm(src0[i].float32[0], src1[i].float16[0],
                res.float32[0], vmo.fixu16, pad.fixu32[0]);
        result_compare_s32(res.float32[0], dst_odd[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_16_vm(src0[i].float32[0], src1[i].float16[0],
                res.float32[0], vme.fixu16, pad.fixu32[0]);
        result_compare_s32(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_32(vlmax_32 - 1, src0[i].float64[0],
                src1[i].float32[0], res.float64[0], pad.fixu64[0]);
        result_compare_s64(res.float64[0], dst_vl[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_32_vm(src0[i].float64[0], src1[i].float32[0],
                res.float64[0], vme.fixu32, pad.fixu64[0]);
        result_compare_s64(res.float64[0], dst_even[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwredsum_vs_32_vm(src0[i].float64[0], src1[i].float32[0],
                res.float64[0], vmo.fixu32, pad.fixu64[0]);
        result_compare_s64(res.float64[0], dst_odd[i].float64[0]);
    }

    return done_testing();
}
