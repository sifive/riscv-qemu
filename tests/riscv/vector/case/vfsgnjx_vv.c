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
            {0x7fefffffffffffff, 0xffefffffffffffff,},
            {0x40154afd6a012e31, 0xc0417456836cfe7b,},
        },
        .float32 = {
            {0x483471f7, 0x46f2e02b, 0xc785dc35, 0x47ad69d9, },
            {0x483471f7, 0x46f2e02b, 0xff7fffff, 0x47ad69d9, },
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
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x7f7fffff, },
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        },
        .float16 = {
            {0xcb85, 0x4b3d, 0xc332, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
            {0x7bff, 0x4b3d, 0xfbff, 0x4a1a, 0xcaf1, 0x4aae, 0xc2a4, 0x49a2, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0x40371fb2129cb102,},
            {0x402b982fa8cba1c2, 0x0000000000000000,},
        },
        .float32 = {
            {0xc843ca22, 0x483c7bbf, 0x473b64a7, 0x7f7fffff,},
            {0xc843ca22, 0x483c7bbf, 0x473b64a7, 0x00000000,},
        },
        .float16 = {
            {0xcb85, 0x4b3d, 0x4332, 0x4a1a, 0xcaf1, 0x4aae, 0x42a4, 0x49a2,},
            {0x7bff, 0x4b3d, 0x7bff, 0x4a1a, 0xcaf1, 0x4aae, 0x42a4, 0x0000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float64 = {
            {0x402b982fa8cba1c2, 0x1111111111111111,},
            {0x402b982fa8cba1c2, 0x1111111111111111,},
        },
        .float32 = {
            {0xc843ca22, 0x11111111, 0x473b64a7, 0x11111111,},
            {0xc843ca22, 0x11111111, 0x473b64a7, 0x11111111,},
        },
        .float16 = {
            {0xcb85, 0x1111, 0x4332, 0x1111, 0xcaf1, 0x1111, 0x42a4, 0x1111,},
            {0x7bff, 0x1111, 0x7bff, 0x1111, 0xcaf1, 0x1111, 0x42a4, 0x1111,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float64 = {
            {0x1111111111111111, 0x40371fb2129cb102,},
            {0x1111111111111111, 0x40371fb2129cb102,},
        },
        .float32 = {
            {0x11111111, 0x483c7bbf, 0x11111111, 0x7f7fffff,},
            {0x11111111, 0x483c7bbf, 0x11111111, 0x481eefee,},
        },
        .float16 = {
            {0x1111, 0x4b3d, 0x1111, 0x4a1a, 0x1111, 0x4aae, 0x1111, 0x49a2,},
            {0x1111, 0x4b3d, 0x1111, 0x4a1a, 0x1111, 0x4aae, 0x1111, 0x49a2,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfsgnjx.vv\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0], res.float16[0], pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vmo.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_odd[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vme.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_even[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_32(vlmax_32 - 1, src0[i].float32[0],
                src1[i].float32[0], res.float32[0], pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vme.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vmo.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_odd[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_64(vlmax_64 - 1, src0[i].float64[0],
                src1[i].float64[0], res.float64[0], pad.fixu64);
        result_compare_s64_lmul(res.float64[0], dst_vl[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vmo.fixu64, pad.fixu64[0]);
        result_compare_s64_lmul(res.float64[0], dst_odd[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfsgnjx_vv_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vme.fixu64, pad.fixu64[0]);
        result_compare_s64_lmul(res.float64[0], dst_even[i].float64[0]);
    }

    return done_testing();
}
