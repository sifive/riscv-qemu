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
        .float32 = {
            {0x0002d1c8, 0x00007970, 0x00001000, 0x00015ad4,},
            {0xffffffff, 0x00007970, 0x00000000, 0x00030000,}, 
        },
        .float16 = {
            {0x000e, 0x0002, 0x0020, 0x0007, 0x000d, 0x0002, 0x0200, 0x0006,},
            {0x000e, 0xffff, 0x0010, 0x0000, 0x000d, 0x0002, 0x0300, 0x0e00,}, 
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
        .wfloat64 = {
            {0x41068e4000000000, 0x40de5c0000000000, 0x40b0000000000000, 0x40f5ad4000000000,},
            {0x41efffffffe00000, 0x40de5c0000000000, 0x0000000000000000, 0x0000000000000000,},
        },
        .wfloat32 = {
            {0x41600000, 0x40000000, 0x42000000, 0x40e00000, 0x41500000, 0x40000000, 0x44000000, 0x40c00000,},
            {0x41600000, 0x477fff00, 0x41800000, 0x00000000, 0x41500000, 0x40000000, 0x44400000, 0x00000000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .wfloat64 = {
            {0x41068e4000000000, 0x1111111111111111, 0x40b0000000000000, 0x1111111111111111,},
            {0x41efffffffe00000, 0x1111111111111111, 0x0000000000000000, 0x1111111111111111,},
        },
        .wfloat32 = {
            {0x41600000, 0x11111111, 0x42000000, 0x11111111, 0x41500000, 0x11111111, 0x44000000, 0x11111111,},
            {0x41600000, 0x11111111, 0x41800000, 0x11111111, 0x41500000, 0x11111111, 0x44400000, 0x11111111,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .wfloat64 = {
            {0x1111111111111111, 0x40de5c0000000000, 0x1111111111111111, 0x40f5ad4000000000,},
            {0x1111111111111111, 0x40de5c0000000000, 0x1111111111111111, 0x4108000000000000,},
        },
        .wfloat32 = {
            {0x11111111, 0x40000000, 0x11111111, 0x40e00000, 0x11111111, 0x40000000, 0x11111111, 0x40c00000,},
            {0x11111111, 0x477fff00, 0x11111111, 0x00000000, 0x11111111, 0x40000000, 0x11111111, 0x45600000,},
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfwcvt.f.xu.v\n");


    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0], res.wfloat32[0], pad.fixu16[0]);
        result_compare_s32_lmul(res.wfloat32[0], dst_vl[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.wfloat32[0], vmo.fixu16, pad.fixu16[0]);
        result_compare_s32_lmul(res.wfloat32[0], dst_odd[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.wfloat32[0], vme.fixu16, pad.fixu16[0]);
        result_compare_s32_lmul(res.wfloat32[0], dst_even[i].wfloat32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_32(vlmax_32 - 1, src0[i].float32[0],
                src1[i].float32[0], res.wfloat64[0], pad.fixu32[0]);
        result_compare_s64_lmul(res.wfloat64[0], dst_vl[i].wfloat64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.wfloat64[0], vme.fixu32, pad.fixu32[0]);
        result_compare_s64_lmul(res.wfloat64[0], dst_even[i].wfloat64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfwcvt_f_xu_v_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.wfloat64[0], vmo.fixu32, pad.fixu32[0]);
        result_compare_s64_lmul(res.wfloat64[0], dst_odd[i].wfloat64[0]);
    }

    return done_testing();
}
