/*
 * RISC-V Bitmanip Extension Helpers for QEMU.
 *
 * Copyright (c) 2020 Kito Cheng, kito.cheng@sifive.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qemu/osdep.h"
#include "cpu.h"
#include "qemu/host-utils.h"
#include "exec/exec-all.h"
#include "exec/helper-proto.h"

#ifdef TARGET_RISCV64
#define XLEN 64
#else
#define XLEN 32
#endif

static target_ulong slo(target_ulong rs1, target_ulong rs2)
{
    int shamt = rs2 & (XLEN - 1);
    return ~((~rs1) << shamt);
}

target_ulong helper_bfp(target_ulong rs1, target_ulong rs2)
{
    target_ulong cfg = rs2 >> (XLEN / 2);

    if ((cfg >> 30) == 2)
        cfg = cfg >> 16;

    int len = (cfg >> 8) & ((XLEN / 2)  - 1);
    int off = cfg & (XLEN - 1);
    len = len ? len : (XLEN / 2);
    target_ulong mask = slo(0, len) << off;
    target_ulong data = rs2 << off;
    return (data & mask) | (rs1 & ~mask);
}

target_ulong helper_bext(target_ulong rs1, target_ulong rs2)
{
    target_ulong c = 0, i = 0, data = rs1, mask = rs2;
    while (mask) {
        target_ulong b = mask & ~((mask | (mask - 1)) + 1);
        c |= (data & b) >> (ctzl(b) - i);
        i += ctpopl(b);
        mask -= b;
    }
    return c;
}

target_ulong helper_bdep(target_ulong rs1, target_ulong rs2)
{
    target_ulong c = 0, i = 0, data = rs1, mask = rs2;
    while (mask) {
        target_ulong b = mask & ~((mask | (mask - 1)) + 1);
        c |= (data << (ctzl(b) - i)) & b;
        i += ctpopl(b);
        mask -= b;
    }
    return c;
}

target_ulong helper_crc32(target_ulong x, target_ulong nbits)
{
    for (int i = 0; i < nbits; i++)
        x = (x >> 1) ^ (0xEDB88320 & ~((x & 1) - 1));
    return x;
}

target_ulong helper_crc32c(target_ulong x, target_ulong nbits)
{
    for (int i = 0; i < nbits; i++)
        x = (x >> 1) ^ (0x82F63B78 & ~((x & 1) - 1));
    return x;
}

#if 0
target_ulong helper_slo(target_ulong rs1, target_ulong rs2)
{
    return 0;
}

target_ulong helper_sro(target_ulong rs1, target_ulong rs2)
{
    return 0;
}
#endif
