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
            {0xfff0000000000000, 0xc0417456836cfe7b,},
            {0x8001000000000010, 0x8000000000000000,},
        },
        .float32 = {
            {0xff800000, 0xc785dc35, 0x80001010, 0x80000000,},
            {0x00000000, 0x00010101, 0x47ad69d9, 0x7f800000,},
        },
        .float16 = {
            {0xfc00, 0xc524, 0x8010, 0x8000, 0x0000, 0x0010, 0x4626, 0x7c00,},
            {0x7c11, 0x7e00, 0xc524, 0x46a9, 0x4a65, 0x404e, 0xc4bf, 0x4626,},
        },
    },
};

struct rvv_reg src1[] = {
    {
        .float64 = {
            {0x0000000000000000, 0x0001000000000010,},
            {0x402b982fa8cba1c2, 0x7ff0000000000000,},
        },
        .float32 = {
            {0x7f801010, 0x7fc00000, 0xc73b64a7, 0x7f7fffff, },
            {0xc843ca22, 0x483c7bbf, 0xc73b64a7, 0x481eefee, },
        },
    },
};

struct rvv_reg src2[] = {
    {
        .float64 = {
            {0x7ff0001010100000, 0x7ff8001000000000},
            {0x402b982fa8cba1c2, 0xc0371fb2129cb102},
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .float64 = {
            {0x0000000000000001, 0x0000000000000002,},
            {0x0000000000000004, 0x0000000000000008,},
        },
        .float32 = {
            {0x00000001, 0x00000002, 0x00000004, 0x00000008,},
            {0x00000010, 0x00000020, 0x00000040, 0x00000080,},
        },
        .float16 = {
            {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,},
            {0x0100, 0x0200, 0x0002, 0x0040, 0x0040, 0x0040, 0x0002, 0x0000,},
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .float64 = {
            {0x0000000000000001, 0x1111111111111111,},
            {0x0000000000000004, 0x1111111111111111,},
        },
        .float32 = {
            {0x00000001, 0x11111111, 0x00000004, 0x11111111,},
            {0x00000010, 0x11111111, 0x00000040, 0x11111111,},
        },
        .float16 = {
            {0x0001, 0x1111, 0x0004, 0x1111, 0x0010, 0x1111, 0x0040, 0x1111,},
            {0x0100, 0x1111, 0x0002, 0x1111, 0x0040, 0x1111, 0x0002, 0x1111,},
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .float64 = {
            {0x1111111111111111, 0x0000000000000002,},
            {0x1111111111111111, 0x0000000000000008,},
        },
        .float32 = {
            {0x11111111, 0x00000002, 0x11111111, 0x00000008,},
            {0x11111111, 0x00000020, 0x11111111, 0x00000080,},
        },
        .float16 = {
            {0x1111, 0x0002, 0x1111, 0x0008, 0x1111, 0x0020, 0x1111, 0x0080,},
            {0x1111, 0x0200, 0x1111, 0x0040, 0x1111, 0x0040, 0x1111, 0x0040,},
        },
    },
};

struct rvv_reg dst[] = {
    {
        .float64 = {
            {0x0000000000000010, 0x0000000000000020,},
            {0x0000000000000040, 0x0000000000000080,},
        },
        .float32 = {
            {0x00000100, 0x00000200, 0x00000002, 0x00000040,},
            {0x00000002, 0x00000040, 0x00000002, 0x00000000,},
        },
    },
    {
        .float64 = {
            {0x0000000000000100, 0x0000000000000200,},
            {0x0000000000000040, 0x0000000000000000,},
        },
    }
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vfclass.v\n");

    /* fp16 */
    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_16(vlmax_16 - 1, src0[i].float16[0],
                src1[i].float16[0], res.float16[0], pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_vl[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vmo.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_odd[i].float16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_16_vm(src0[i].float16[0], src1[i].float16[0],
                res.float16[0], vme.fixu16, pad.fixu16[0]);
        result_compare_s16_lmul(res.float16[0], dst_even[i].float16[0]);
    }

    /* fp32 */
    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_32(vlmax_32, src0[i].float32[0],
                src1[i].float32[0], res.float32[0], pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_vl[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vme.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_even[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_32_vm(src0[i].float32[0], src1[i].float32[0],
                res.float32[0], vmo.fixu32, pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst_odd[i].float32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_32(vlmax_32 - 1, src1[i].float32[0],
                src0[i].float32[0], res.float32[0], pad.fixu32[0]);
        result_compare_s32_lmul(res.float32[0], dst[0].float32[0]);
    }

    /* fp64 */
    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_64(vlmax_64, src0[i].float64[0],
                src1[i].float64[0], res.float64[0], pad.fixu64);
        result_compare_s64_lmul(res.float64[0], dst_vl[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vmo.fixu64, pad.fixu64[0]);
        result_compare_s64_lmul(res.float64[0], dst_odd[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_64_vm(src0[i].float64[0], src1[i].float64[0],
                res.float64[0], vme.fixu64, pad.fixu64[0]);
        result_compare_s64_lmul(res.float64[0], dst_even[i].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_64(vlmax_64, src1[i].float64[0],
                src0[i].float64[0], res.float64[0], pad.fixu64);
        result_compare_s64_lmul(res.float64[0], dst[0].float64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vfclass_v_64(vlmax_64 - 1, src2[i].float64[0],
                src0[i].float64[0], res.float64[0], pad.fixu64);
        result_compare_s64_lmul(res.float64[0], dst[1].float64[0]);
    }

    return done_testing();
}
