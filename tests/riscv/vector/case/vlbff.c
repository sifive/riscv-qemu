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

#include <sys/mman.h>
#include <unistd.h>
#include "testsuite.h"
#include "rvv_insn.h"

struct rvv_reg src0[] = {
    {
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
        },
    },
};

struct rvv_reg dst0[] = {
    {
        .fixs8 = {
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x21, },
            {0xa5, 0x34, 0x8c, 0x74, 0xcd, 0x75, 0x92, 0x7a, 0x60, 0x19, 0x3c, 0x91, 0xfd, 0xab, 0x23, 0x00, },
        },
        .fixs16 = {
            {0xffa5, 0x0034, 0xff8c, 0x0074, 0xffcd, 0x0075, 0xff92, 0x007a, },
            {0x0060, 0x0019, 0x003c, 0xff91, 0xfffd, 0xffab, 0x0023, 0x0000, },
        },
        .fixs32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x00000000, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x0000000000000034, },
            {0xffffffffffffff8c, 0x0000000000000000, },
        },
    },
    {
        .fixs8 = {
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
            {0xa5, 0x11, 0x8c, 0x11, 0xcd, 0x11, 0x92, 0x11, 0x60, 0x11, 0x3c, 0x11, 0xfd, 0x11, 0x23, 0x11, },
        },
        .fixs16 = {
            {0xffa5, 0x1111, 0xff8c, 0x1111, 0xffcd, 0x1111, 0xff92, 0x1111, },
            {0x0060, 0x1111, 0x003c, 0x1111, 0xfffd, 0x1111, 0x0023, 0x1111, },
        },
        .fixs32 = {
            {0xffffffa5, 0x11111111, 0xffffff8c, 0x11111111, },
            {0xffffffcd, 0x11111111, 0xffffff92, 0x11111111, },
        },
        .fixs64 = {
            {0xffffffffffffffa5, 0x1111111111111111, },
            {0xffffffffffffff8c, 0x1111111111111111, },
        },
    },
    {
        .fixs8 = {
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
            {0x11, 0x34, 0x11, 0x74, 0x11, 0x75, 0x11, 0x7a, 0x11, 0x19, 0x11, 0x91, 0x11, 0xab, 0x11, 0x21, },
        },
        .fixs16 = {
            {0x1111, 0x0034, 0x1111, 0x0074, 0x1111, 0x0075, 0x1111, 0x007a, },
            {0x1111, 0x0019, 0x1111, 0xff91, 0x1111, 0xffab, 0x1111, 0x0021, },
        },
        .fixs32 = {
            {0x11111111, 0x00000034, 0x11111111, 0x00000074, },
            {0x11111111, 0x00000075, 0x11111111, 0x0000007a, },
        },
        .fixs64 = {
            {0x1111111111111111, 0x0000000000000034, },
            {0x1111111111111111, 0x0000000000000074, },
        },
    },
    };


struct rvv_reg res0;

int main(void)
{
    char *binv, *brw, *start;
    int pagesize;
    pagesize = sysconf(_SC_PAGESIZE);
    int i, vl;
    init_testsuite("Testing insn vlbff\n");

    /* sew 8 */
    test_vlbff_8(vlmax_8 - 1, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[0].fixs8[0]);

    test_vlbff_8_vm(&vme.fixs8, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[1].fixs8[0]);

    test_vlbff_8_vm(&vmo.fixs8, &pad.fixs8[0], src0[0].fixs8[0], res0.fixs8[0]);
    result_compare_s8_lmul(res0.fixs8[0], dst0[2].fixs8[0]);

    /* sew 16 */
    test_vlbff_16(vlmax_16 - 1, &pad.fixs16[0], src0[0].fixs8[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[0].fixs16[0]);

    test_vlbff_16_vm(&vme.fixs16, &pad.fixs16[0], src0[0].fixs8[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[1].fixs16[0]);

    test_vlbff_16_vm(&vmo.fixs16, &pad.fixs16[0], src0[0].fixs8[0], res0.fixs16[0]);
    result_compare_s16_lmul(res0.fixs16[0], dst0[2].fixs16[0]);

    /* sew 32 */
    test_vlbff_32(vlmax_32 - 1, &pad.fixs32[0], src0[0].fixs8[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[0].fixs32[0]);

    test_vlbff_32_vm(&vme.fixs32, &pad.fixs32[0], src0[0].fixs8[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[1].fixs32[0]);

    test_vlbff_32_vm(&vmo.fixs32, &pad.fixs32[0], src0[0].fixs8[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[2].fixs32[0]);

    /* sew 64 */
    test_vlbff_64(vlmax_64 - 1, &pad.fixs64[0], src0[0].fixs8[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[0].fixs64[0]);

    test_vlbff_64_vm(&vme.fixs64, &pad.fixs64[0], src0[0].fixs8[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[1].fixs64[0]);

    test_vlbff_64_vm(&vmo.fixs64, &pad.fixs64[0], src0[0].fixs8[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[2].fixs64[0]);

    /* cross the boundary */
    binv = mmap(NULL, 2 * pagesize, PROT_NONE,  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    brw = mmap(binv, pagesize, PROT_WRITE | PROT_READ, MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    binv += pagesize;
    start = brw + pagesize - 16;

    /* sew 8 */
    for (i = 0; i < 16; i++) {
        *(start + i) = src0[0].fixs8[0][i];
    }
    vl = test_vlbff_8(vlmax_8, &pad.fixs8[0], start, res0.fixs8[0]);
    result_compare_s8(res0.fixs8[0], dst0[0].fixs8[0]);
    TEST(vl == vlmax_8 / 2);
    /* sew 16 */
    start = brw + pagesize - 8;
    for (i = 0; i < 8; i++) {
        *(start + i) = src0[0].fixs8[0][i];
    }
    vl = test_vlbff_16(vlmax_16, &pad.fixs16[0], start, res0.fixs16[0]);
    result_compare_s16(res0.fixs16[0], dst0[0].fixs16[0]);
    TEST(vl == vlmax_16 / 2);
    /* sew 32 */
    start = brw + pagesize - 4;
    for (i = 0; i < 4; i++) {
        *(start + i) = src0[0].fixs8[0][i];
    }
    vl = test_vlbff_32(vlmax_32, &pad.fixs32[0], start, res0.fixs32[0]);
    result_compare_s32(res0.fixs32[0], dst0[0].fixs32[0]);
    TEST(vl == vlmax_32 / 2);
    /* sew 64 */
    start = brw + pagesize - 2;
    for (i = 0; i < 2; i++) {
        *(start + i) = src0[0].fixs8[0][i];
    }
    vl = test_vlbff_64(vlmax_64, &pad.fixs64[0], start, res0.fixs64[0]);
    result_compare_s64(res0.fixs64[0], dst0[0].fixs64[0]);
    TEST(vl == vlmax_64 / 2);
    munmap(binv, pagesize);
    munmap(brw, pagesize);

    return done_testing();
}
