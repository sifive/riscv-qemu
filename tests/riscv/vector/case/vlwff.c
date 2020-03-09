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
        .fixs32 = {
            {0xffffffa5, 0x00000034, 0xffffff8c, 0x00000074, },
            {0xffffffcd, 0x00000075, 0xffffff92, 0x0000007a, },
        },
    },
};

struct rvv_reg dst0[] = {
    {
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
    int32_t *binv, *brw, *start;
    int pagesize;
    pagesize = sysconf(_SC_PAGESIZE);
    int i, vl;
    init_testsuite("Testing insn vlwff\n");

    /* sew 32 */
    test_vlwff_32(vlmax_32 - 1, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[0].fixs32[0]);

    test_vlwff_32_vm(&vme.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[1].fixs32[0]);

    test_vlwff_32_vm(&vmo.fixs32, &pad.fixs32[0], src0[0].fixs32[0], res0.fixs32[0]);
    result_compare_s32_lmul(res0.fixs32[0], dst0[2].fixs32[0]);

    /* sew 64 */
    test_vlwff_64(vlmax_64 - 1, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[0].fixs64[0]);

    test_vlwff_64_vm(&vme.fixs64, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[1].fixs64[0]);

    test_vlwff_64_vm(&vmo.fixs64, &pad.fixs64[0], src0[0].fixs32[0], res0.fixs64[0]);
    result_compare_s64_lmul(res0.fixs64[0], dst0[2].fixs64[0]);
    /* cross the boundary */
    binv = mmap(NULL, 2 * pagesize, PROT_NONE,  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    brw = mmap(binv, pagesize, PROT_WRITE | PROT_READ,
        MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    binv = (int32_t *)((uint64_t)binv + pagesize);
    /* sew 32 */
    start = (int32_t *)((uint64_t)brw + pagesize - 4 * 4);
    for (i = 0; i < 4; i++) {
        *(start + i) = src0[0].fixs32[0][i];
    }
    vl = test_vlwff_32(vlmax_32, &pad.fixs32[0], start, res0.fixs32[0]);
    result_compare_s32(res0.fixs32[0], dst0[0].fixs32[0]);
    TEST(vl == vlmax_32 / 2);
    /* sew 64 */
    start = (int32_t *)((uint64_t)brw + pagesize - 2 * 4);
    for (i = 0; i < 2; i++) {
        *(start + i) = src0[0].fixs32[0][i];
    }
    vl = test_vlwff_64(vlmax_64, &pad.fixs64[0], start, res0.fixs64[0]);
    result_compare_s64(res0.fixs64[0], dst0[0].fixs64[0]);
    TEST(vl == vlmax_64 / 2);
    munmap(binv, pagesize);
    munmap(brw, pagesize);

    return done_testing();
}
