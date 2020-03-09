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
        .wfloat64 = {
            {0x000000000002d1c8, 0x0000000000007970, 0x0000000000002200, 0x0000000000015ad4,},
            {0xffffffffffffffff, 0x0000000000007970, 0x0000000000000122, 0x0000000002200000,}, 
        },
        .wfloat32 = {
            {0x0000000e, 0x00000002, 0x000001120, 0x00001007, 0x0000000d, 0x00000002, 0x00020000, 0x00000006,},
            {0x0000000e, 0xffffffff, 0x000000233, 0x00123300, 0x0000000d, 0x00000002, 0x00000300, 0x00012000,}, 
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
        .float32 = {
            {0x48347200, 0x46f2e000, 0x46080000, 0x47ad6a00,},
            {0x5f800000, 0x46f2e000, 0x43910000, 0x00000000,},
        },
        .float16 = {
            {0x4b00, 0x4000, 0x6c48, 0x6c02, 0x4a80, 0x4000, 0x7c00, 0x4600,},
            {0x4b00, 0x7c00, 0x6066, 0x7c00, 0x4a80, 0x4000, 0x6200, 0x0000,}, 
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float32 = {
            {0x48347200, 0x11111111, 0x46080000, 0x11111111,},
            {0x5f800000, 0x11111111, 0x43910000, 0x11111111,},
        },
        .float16 = {
            {0x4b00, 0x1111, 0x6c48, 0x1111, 0x4a80, 0x1111, 0x7c00, 0x1111,},
            {0x4b00, 0x1111, 0x6066, 0x1111, 0x4a80, 0x1111, 0x6200, 0x1111,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float32 = {
            {0x11111111, 0x46f2e000, 0x11111111, 0x47ad6a00,},
            {0x11111111, 0x46f2e000, 0x11111111, 0x4c080000,},
        },
        .float16 = {
            {0x1111, 0x4000, 0x1111, 0x6c02, 0x1111, 0x4000, 0x1111, 0x4600,},
            {0x1111, 0x7c00, 0x1111, 0x7c00, 0x1111, 0x4000, 0x1111, 0x7c00,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfncvt.f.xu.v\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_16(vlmax_16 - 1, src0[i].wfloat32[0],
                src1[i].float16[0], res.float16[0], pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_16_vm(src0[i].wfloat32[0], src1[i].float16[0],
                res.float16[0], vmo.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_odd[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_16_vm(src0[i].wfloat32[0], src1[i].float16[0],
                res.float16[0], vme.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_even[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_32(vlmax_32 - 1, src0[i].wfloat64[0],
                src1[i].float32[0], res.float32[0], pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_32_vm(src0[i].wfloat64[0], src1[i].float32[0],
                res.float32[0], vme.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfncvt_f_xu_v_32_vm(src0[i].wfloat64[0], src1[i].float32[0],
                res.float32[0], vmo.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_odd[i].float32[0]);
    }

    return done_testing();
}
