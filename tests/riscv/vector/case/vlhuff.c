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
        .fixu16 = {
            {0xffa5, 0x0034, 0xff8c, 0x0074, 0xffcd, 0x0075, 0xff92, 0x007a, },
            {0x0060, 0x0019, 0x003c, 0xff91, 0xfffd, 0xffab, 0x0023, 0x0021, },
        },
    },
};

struct rvv_reg dst0[] = {
    {
        .fixu16 = {
            {0xffa5, 0x0034, 0xff8c, 0x0074, 0xffcd, 0x0075, 0xff92, 0x007a, },
            {0x0060, 0x0019, 0x003c, 0xff91, 0xfffd, 0xffab, 0x0023, 0x0000, },
        },
        .fixu32 = {
            {0x0000ffa5, 0x00000034, 0x0000ff8c, 0x00000074, },
            {0x0000ffcd, 0x00000075, 0x0000ff92, 0x00000000, },
        },
        .fixu64 = {
            {0x000000000000ffa5, 0x0000000000000034, },
            {0x000000000000ff8c, 0x0000000000000000, },
        },
    },
    {
        .fixu16 = {
            {0xffa5, 0x1111, 0xff8c, 0x1111, 0xffcd, 0x1111, 0xff92, 0x1111, },
            {0x0060, 0x1111, 0x003c, 0x1111, 0xfffd, 0x1111, 0x0023, 0x1111, },
        },
        .fixu32 = {
            {0x0000ffa5, 0x11111111, 0x0000ff8c, 0x11111111, },
            {0x0000ffcd, 0x11111111, 0x0000ff92, 0x11111111, },
        },
        .fixu64 = {
            {0x000000000000ffa5, 0x1111111111111111, },
            {0x000000000000ff8c, 0x1111111111111111, },
        },
    },
    {
        .fixu16 = {
            {0x1111, 0x0034, 0x1111, 0x0074, 0x1111, 0x0075, 0x1111, 0x007a, },
            {0x1111, 0x0019, 0x1111, 0xff91, 0x1111, 0xffab, 0x1111, 0x0021, },
        },
        .fixu32 = {
            {0x11111111, 0x00000034, 0x11111111, 0x00000074, },
            {0x11111111, 0x00000075, 0x11111111, 0x0000007a, },
        },
        .fixu64 = {
            {0x1111111111111111, 0x0000000000000034, },
            {0x1111111111111111, 0x0000000000000074, },
        },
    },
    };


struct rvv_reg res0;

int main(void)
{
    uint16_t *binv, *brw, *start;
    int pagesize;
    pagesize = sysconf(_SC_PAGESIZE);
    int i, vl;
    init_testsuite("Testing insn vlhuff\n");

    /* sew 16 */
    test_vlhuff_16(vlmax_16 - 1, &pad.fixu16[0], src0[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[0].fixu16[0]);

    test_vlhuff_16_vm(&vme.fixu16, &pad.fixu16[0], src0[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[1].fixu16[0]);

    test_vlhuff_16_vm(&vmo.fixu16, &pad.fixu16[0], src0[0].fixu16[0], res0.fixu16[0]);
    result_compare_s16_lmul(res0.fixu16[0], dst0[2].fixu16[0]);

    /* sew 32 */
    test_vlhuff_32(vlmax_32 - 1, &pad.fixu32[0], src0[0].fixu16[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[0].fixu32[0]);

    test_vlhuff_32_vm(&vme.fixu32, &pad.fixu32[0], src0[0].fixu16[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[1].fixu32[0]);

    test_vlhuff_32_vm(&vmo.fixu32, &pad.fixu32[0], src0[0].fixu16[0], res0.fixu32[0]);
    result_compare_s32_lmul(res0.fixu32[0], dst0[2].fixu32[0]);

    /* sew 64 */
    test_vlhuff_64(vlmax_64 - 1, &pad.fixu64[0], src0[0].fixu16[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[0].fixu64[0]);

    test_vlhuff_64_vm(&vme.fixu64, &pad.fixu64[0], src0[0].fixu16[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[1].fixu64[0]);

    test_vlhuff_64_vm(&vmo.fixu64, &pad.fixu64[0], src0[0].fixu16[0], res0.fixu64[0]);
    result_compare_s64_lmul(res0.fixu64[0], dst0[2].fixu64[0]);

    /* cross the boundary */
    binv = mmap(NULL, 2 * pagesize, PROT_NONE,  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    brw = mmap(binv, pagesize, PROT_WRITE | PROT_READ,
        MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    binv = (uint16_t *)((uint64_t)binv + pagesize);
    /* sew 16 */
    start = (uint16_t *)((uint64_t)brw + pagesize - 8 * 2);
    for (i = 0; i < 8; i++) {
        *(start + i) = src0[0].fixu16[0][i];
    }
    vl = test_vlhuff_16(vlmax_16, &pad.fixu16[0], start, res0.fixu16[0]);
    result_compare_s16(res0.fixu16[0], dst0[0].fixu16[0]);
    TEST(vl == vlmax_16 / 2);
    /* sew 32 */
    start = (uint16_t*)((uint64_t)brw + pagesize - 4 * 2);
    for (i = 0; i < 4; i++) {
        *(start + i) = src0[0].fixu16[0][i];
    }
    vl = test_vlhuff_32(vlmax_32, &pad.fixu32[0], start, res0.fixu32[0]);
    result_compare_s32(res0.fixu32[0], dst0[0].fixu32[0]);
    TEST(vl == vlmax_32 / 2);
    /* sew 64 */
    start = (uint16_t *)((uint64_t)brw + pagesize - 2 * 2);
    for (i = 0; i < 2; i++) {
        *(start + i) = src0[0].fixu16[0][i];
    }
    vl = test_vlhuff_64(vlmax_64, &pad.fixu64[0], start, res0.fixu64[0]);
    result_compare_s64(res0.fixu64[0], dst0[0].fixu64[0]);
    TEST(vl == vlmax_64 / 2);
    munmap(binv, pagesize);
    munmap(brw, pagesize);
    return done_testing();
}
