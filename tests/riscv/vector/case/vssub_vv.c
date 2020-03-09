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

struct rvv_reg src1[] = {
    {
        .fixs64 = {
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
            {0x07d215928aa0d7b6, 0x07186161e5f9e80f, },
        },
        .fixs32 = {
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
            {0x7794d541, 0xf1bfac15, 0x67e3b37f, 0x12df3e7c, },
        },
        .fixs16 = {
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
            {0x4fb8, 0x39b3, 0x6744, 0xfa98, 0xce81, 0x997d, 0x301c, 0xcfb5, },
        },
        .fixs8 = {
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
            {0x21, 0xb6, 0x8d, 0x3a, 0xe2, 0x09, 0x90, 0x15, 0x2c, 0x13, 0xac, 0x86, 0x28, 0xce, 0x4f, 0xbb, },
        },
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

struct rvv_reg dst_odd[] = {
    {
        .fixs64 = {
            {0x1111111111111111, 0xbf8dcf5161ed4f6c, },
            {0x1111111111111111, 0xbf8dcf5161ed4f6c, },
        },
        .fixs32 = {
            {0x11111111, 0x90a34a4c, 0x11111111, 0xc3da35de, },
            {0x11111111, 0x90a34a4c, 0x11111111, 0xc3da35de, },
        },
        .fixs16 = {
            {0x1111, 0x183f, 0x1111, 0x1409, 0x1111, 0x7fff, 0x1111, 0xd1af, },
            {0x1111, 0x183f, 0x1111, 0x1409, 0x1111, 0x7fff, 0x1111, 0xd1af, },
        },
        .fixs8 = {
            {0x11, 0x7e, 0x11, 0x3a, 0x11, 0x6c, 0x11, 0x65, 0x11, 0x06, 0x11, 0x0b, 0x11, 0xdd, 0x11, 0x66, },
            {0x11, 0x7e, 0x11, 0x3a, 0x11, 0x6c, 0x11, 0x65, 0x11, 0x06, 0x11, 0x0b, 0x11, 0xdd, 0x11, 0x66, },
        },
        .fixu64 = {
            {0x1111111111111111, 0x1164e184199f72d3, },
            {0x1111111111111111, 0x1164e184199f72d3, },
        },
        .fixu32 = {
            {0x11111111, 0x00000000, 0x11111111, 0x4c029377, },
            {0x11111111, 0x00000000, 0x11111111, 0x4c029377, },
        },
        .fixu16 = {
            {0x1111, 0x101e, 0x1111, 0x0000, 0x1111, 0x0000, 0x1111, 0x0000, },
            {0x1111, 0x101e, 0x1111, 0x0000, 0x1111, 0x0000, 0x1111, 0x0000, },
        },
        .fixu8 = {
            {0x11, 0x00, 0x11, 0x00, 0x11, 0x2b, 0x11, 0x00, 0x11, 0x65, 0x11, 0x76, 0x11, 0x00, 0x11, 0x59, },
            {0x11, 0x00, 0x11, 0x00, 0x11, 0x2b, 0x11, 0x00, 0x11, 0x65, 0x11, 0x76, 0x11, 0x00, 0x11, 0x59, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs64 = {
            {0x319ea006b0111a5c, 0x1111111111111111, },
            {0x319ea006b0111a5c, 0x1111111111111111, },
        },
        .fixs32 = {
            {0x80000000, 0x11111111, 0xae189ea2, 0x11111111, },
            {0x80000000, 0x11111111, 0xae189ea2, 0x11111111, },
        },
        .fixs16 = {
            {0x871e, 0x1111, 0xa9ab, 0x1111, 0xd4c8, 0x1111, 0x1741, 0x1111, },
            {0x871e, 0x1111, 0xa9ab, 0x1111, 0xd4c8, 0x1111, 0x1741, 0x1111, },
        },
        .fixs8 = {
            {0x84, 0x11, 0xff, 0x11, 0xeb, 0x11, 0x02, 0x11, 0x34, 0x11, 0x7f, 0x11, 0xd5, 0x11, 0xd4, 0x11, },
            {0x84, 0x11, 0xff, 0x11, 0xeb, 0x11, 0x02, 0x11, 0x34, 0x11, 0x7f, 0x11, 0xd5, 0x11, 0xd4, 0x11, },
        },
        .fixu64 = {
            {0x0000000000000000, 0x1111111111111111, },
            {0x0000000000000000, 0x1111111111111111, },
        },
        .fixu32 = {
            {0x00000000, 0x11111111, 0x682ed3bf, 0x11111111, },
            {0x00000000, 0x11111111, 0x682ed3bf, 0x11111111, },
        },
        .fixu16 = {
            {0x9ae5, 0x1111, 0xa779, 0x1111, 0x0000, 0x1111, 0x8227, 0x1111, },
            {0x9ae5, 0x1111, 0xa779, 0x1111, 0x0000, 0x1111, 0x8227, 0x1111, },
        },
        .fixu8 = {
            {0xa6, 0x11, 0x00, 0x11, 0x4f, 0x11, 0x00, 0x11, 0x1f, 0x11, 0x6c, 0x11, 0xac, 0x11, 0x00, 0x11, },
            {0xa6, 0x11, 0x00, 0x11, 0x4f, 0x11, 0x00, 0x11, 0x1f, 0x11, 0x6c, 0x11, 0xac, 0x11, 0x00, 0x11, },
        },
    },
};

struct rvv_reg dst_vl[] = {
    {
        .fixs64 = {
            {0x319ea006b0111a5c, 0xbf8dcf5161ed4f6c, },
            {0x319ea006b0111a5c, 0x0000000000000000, },
        },
        .fixs32 = {
            {0x80000000, 0x90a34a4c, 0xae189ea2, 0xc3da35de, },
            {0x80000000, 0x90a34a4c, 0xae189ea2, 0x00000000, },
        },
        .fixs16 = {
            {0x871e, 0x183f, 0xa9ab, 0x1409, 0xd4c8, 0x7fff, 0x1741, 0xd1af, },
            {0x871e, 0x183f, 0xa9ab, 0x1409, 0xd4c8, 0x7fff, 0x1741, 0x0000, },
        },
        .fixs8 = {
            {0x84, 0x7e, 0xff, 0x3a, 0xeb, 0x6c, 0x02, 0x65, 0x34, 0x06, 0x7f, 0x0b, 0xd5, 0xdd, 0xd4, 0x66, },
            {0x84, 0x7e, 0xff, 0x3a, 0xeb, 0x6c, 0x02, 0x65, 0x34, 0x06, 0x7f, 0x0b, 0xd5, 0xdd, 0xd4, 0x00, },
        },
        .fixu64 = {
            {0x0000000000000000, 0x1164e184199f72d3, },
            {0x0000000000000000, 0x0000000000000000, },
        },
        .fixu32 = {
            {0x00000000, 0x00000000, 0x682ed3bf, 0x4c029377, },
            {0x00000000, 0x00000000, 0x682ed3bf, 0x00000000, },
        },
        .fixu16 = {
            {0x9ae5, 0x101e, 0xa779, 0x0000, 0x0000, 0x0000, 0x8227, 0x0000, },
            {0x9ae5, 0x101e, 0xa779, 0x0000, 0x0000, 0x0000, 0x8227, 0x0000, },
        },
        .fixu8 = {
            {0xa6, 0x00, 0x00, 0x00, 0x4f, 0x2b, 0x00, 0x00, 0x1f, 0x65, 0x6c, 0x76, 0xac, 0x00, 0x00, 0x59, },
            {0xa6, 0x00, 0x00, 0x00, 0x4f, 0x2b, 0x00, 0x00, 0x1f, 0x65, 0x6c, 0x76, 0xac, 0x00, 0x00, 0x00, },
        },
    },
};

struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vssub.vv\n");

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_8(vlmax_8 - 1, src0[i].fixs8, src1[i].fixs8,
                res.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_8_vm(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vmo.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_8_vm(src0[i].fixs8, src1[i].fixs8,
                res.fixs8, vme.fixs8, pad.fixs8);
        result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_16(vlmax_16 - 1, src0[i].fixs16, src1[i].fixs16,
                res.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_16_vm(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vmo.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_16_vm(src0[i].fixs16, src1[i].fixs16,
                res.fixs16, vme.fixs16, pad.fixs16);
        result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_32(vlmax_32 - 1, src0[i].fixs32, src1[i].fixs32,
                res.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_32_vm(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vme.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_32_vm(src0[i].fixs32, src1[i].fixs32,
                res.fixs32, vmo.fixs32, pad.fixs32);
        result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_64(vlmax_64 - 1, src0[i].fixs64, src1[i].fixs64,
                res.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_64_vm(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vme.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssub_vv_64_vm(src0[i].fixs64, src1[i].fixs64,
                res.fixs64, vmo.fixs64, pad.fixs64);
        result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_8(vlmax_8 - 1, src0[i].fixu8, src1[i].fixu8,
                res.fixu8, pad.fixs8);
        result_compare_u8_lmul(res.fixu8[0], dst_vl[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_8_vm(src0[i].fixu8, src1[i].fixu8,
                res.fixu8, vmo.fixs8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_odd[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_8_vm(src0[i].fixu8, src1[i].fixu8,
                res.fixu8, vme.fixs8, pad.fixu8);
        result_compare_u8_lmul(res.fixu8[0], dst_even[i].fixu8[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_16(vlmax_16 - 1, src0[i].fixu16, src1[i].fixu16,
                res.fixu16, pad.fixs16);
        result_compare_u16_lmul(res.fixu16[0], dst_vl[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_16_vm(src0[i].fixu16, src1[i].fixu16,
                res.fixu16, vmo.fixs16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_odd[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_16_vm(src0[i].fixu16, src1[i].fixu16,
                res.fixu16, vme.fixs16, pad.fixu16);
        result_compare_u16_lmul(res.fixu16[0], dst_even[i].fixu16[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_32(vlmax_32 - 1, src0[i].fixu32, src1[i].fixu32,
                res.fixu32, pad.fixs32);
        result_compare_u32_lmul(res.fixu32[0], dst_vl[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_32_vm(src0[i].fixu32, src1[i].fixu32,
                res.fixu32, vmo.fixs32, pad.fixu32);
        result_compare_u32(res.fixu32[0], dst_odd[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_32_vm(src0[i].fixu32, src1[i].fixu32,
                res.fixu32, vme.fixs32, pad.fixu32);
        result_compare_u32_lmul(res.fixu32[0], dst_even[i].fixu32[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_64(vlmax_64 - 1, src0[i].fixu64, src1[i].fixu64,
                res.fixu64, pad.fixs64);
        result_compare_u64_lmul(res.fixu64[0], dst_vl[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_64_vm(src0[i].fixu64, src1[i].fixu64,
                res.fixu64, vmo.fixs64, pad.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_odd[i].fixu64[0]);
    }

    for (i = 0; i < sizeof(src0) / sizeof(struct rvv_reg); i++) {
        test_vssubu_vv_64_vm(src0[i].fixu64, src1[i].fixu64,
                res.fixu64, vme.fixs64, pad.fixu64);
        result_compare_u64_lmul(res.fixu64[0], dst_even[i].fixu64[0]);
    }

    return done_testing();
}
