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
 * Lesser General Public License  *
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
    },
};

uint64_t src1 = 0x1122334455667788;
struct rvv_reg dst_vl[] = {
    {
        .fixs8 = {
            {0x1c, 0xab, 0x03, 0xeb, 0x44, 0xec, 0x09, 0xf1, 0xd7, 0x90, 0xb3, 0x08, 0x74, 0x22, 0x9a, 0x98, },
            {0x1c, 0xab, 0x03, 0xeb, 0x44, 0xec, 0x09, 0xf1, 0xd7, 0x90, 0xb3, 0x08, 0x74, 0x22, 0x9a, 0x00, },
        },
        .fixs16 = {
            {0x5f4d, 0xda69, 0x9966, 0x9718, 0x2bc0, 0xd5b6, 0xcfd4, 0x29db, },
            {0x5f4d, 0xda69, 0x9966, 0x9718, 0x2bc0, 0xd5b6, 0xcfd4, 0x0000, },
        },
        .fixs32 = {
            {0x7a79eefd, 0x2cfc7ed8, 0xc095da98, 0x8152fcd1, },
            {0x7a79eefd, 0x2cfc7ed8, 0xc095da98, 0x00000000, },
        },
        .fixs64 = {
            {0x284e8254e54b7a89, 0xb583fd6ef280bff2, },
            {0x284e8254e54b7a89, 0x0000000000000000, },
        },
    },
};

struct rvv_reg dst_even[] = {
    {
        .fixs8 = {
            {0x1c, 0xac, 0x03, 0xec, 0x44, 0xed, 0x09, 0xf2, 0xd7, 0x91, 0xb3, 0x09, 0x74, 0x23, 0x9a, 0x99, },
            {0x1c, 0xac, 0x03, 0xec, 0x44, 0xed, 0x09, 0xf2, 0xd7, 0x91, 0xb3, 0x09, 0x74, 0x23, 0x9a, 0x99, },
        },
        .fixs16 = {
            {0x5f4d, 0xda6a, 0x9966, 0x9719, 0x2bc0, 0xd5b7, 0xcfd4, 0x29dc, },
            {0x5f4d, 0xda6a, 0x9966, 0x9719, 0x2bc0, 0xd5b7, 0xcfd4, 0x29dc, },
        },
        .fixs32 = {
            {0x7a79eefd, 0x2cfc7ed9, 0xc095da98, 0x8152fcd2, },
            {0x7a79eefd, 0x2cfc7ed9, 0xc095da98, 0x8152fcd2, },
        },
        .fixs64 = {
            {0x284e8254e54b7a89, 0xb583fd6ef280bff3, },
            {0x284e8254e54b7a89, 0xb583fd6ef280bff3, },
        },
    },
};

struct rvv_reg dst_odd[] = {
    {
        .fixs8 = {
            {0x1d, 0xab, 0x04, 0xeb, 0x45, 0xec, 0x0a, 0xf1, 0xd8, 0x90, 0xb4, 0x08, 0x75, 0x22, 0x9b, 0x98, },
            {0x1d, 0xab, 0x04, 0xeb, 0x45, 0xec, 0x0a, 0xf1, 0xd8, 0x90, 0xb4, 0x08, 0x75, 0x22, 0x9b, 0x98, },
        },
        .fixs16 = {
            {0x5f4e, 0xda69, 0x9967, 0x9718, 0x2bc1, 0xd5b6, 0xcfd5, 0x29db, },
            {0x5f4e, 0xda69, 0x9967, 0x9718, 0x2bc1, 0xd5b6, 0xcfd5, 0x29db, },
        },
        .fixs32 = {
            {0x7a79eefe, 0x2cfc7ed8, 0xc095da99, 0x8152fcd1, },
            {0x7a79eefe, 0x2cfc7ed8, 0xc095da99, 0x8152fcd1, },
        },
        .fixs64 = {
            {0x284e8254e54b7a8a, 0xb583fd6ef280bff2, },
            {0x284e8254e54b7a8a, 0xb583fd6ef280bff2, },
        },
    },
};


struct rvv_reg res;

int main(void)
{
    int i = 0;
    init_testsuite("Testing insn vsbc.vxm\n");

    /* int8_t sbc */
    test_vsbc_vxm_8(vlmax_8 - 1, src0[i].fixs8[0], src1, res.fixs8[0], vma.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_vl[i].fixs8[0]);

    test_vsbc_vxm_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vme.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_even[i].fixs8[0]);

    test_vsbc_vxm_8_vm(src0[i].fixs8[0], src1, res.fixs8[0], vmo.fixs8, pad.fixs8[0]);
    result_compare_s8_lmul(res.fixs8[0], dst_odd[i].fixs8[0]);

    /* int16_t sbc */
    test_vsbc_vxm_16(vlmax_16 - 1, src0[i].fixs16[0], src1, res.fixs16[0], vma.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_vl[i].fixs16[0]);

    test_vsbc_vxm_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vme.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_even[i].fixs16[0]);

    test_vsbc_vxm_16_vm(src0[i].fixs16[0], src1, res.fixs16[0], vmo.fixs16, pad.fixs8[0]);
    result_compare_s16_lmul(res.fixs16[0], dst_odd[i].fixs16[0]);

    /* int32_t sbc */
    test_vsbc_vxm_32(vlmax_32 - 1, src0[i].fixs32[0], src1, res.fixs32[0], vma.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_vl[i].fixs32[0]);

    test_vsbc_vxm_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vme.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_even[i].fixs32[0]);

    test_vsbc_vxm_32_vm(src0[i].fixs32[0], src1, res.fixs32[0], vmo.fixs32, pad.fixs8[0]);
    result_compare_s32_lmul(res.fixs32[0], dst_odd[i].fixs32[0]);

    /* int64_t sbc */
    test_vsbc_vxm_64(vlmax_64 - 1, src0[i].fixs64[0], src1, res.fixs64[0], vma.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_vl[i].fixs64[0]);

    test_vsbc_vxm_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vme.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_even[i].fixs64[0]);

    test_vsbc_vxm_64_vm(src0[i].fixs64[0], src1, res.fixs64[0], vmo.fixs64, pad.fixs8[0]);
    result_compare_s64_lmul(res.fixs64[0], dst_odd[i].fixs64[0]);

    return done_testing();
}
