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

#ifndef RVV_INSN_H
#define RVV_INSN_H
#include <stdint.h>
#define DEBUG
#define VLEN 128
#define LMUL 2
struct rvv_reg {
    int8_t   fixs8[2 * LMUL][16];
    int16_t  fixs16[2 * LMUL][8];
    int32_t  fixs32[2 * LMUL][4];
    int64_t  fixs64[2 * LMUL][2];
    uint8_t  fixu8[2 * LMUL][16];
    uint16_t fixu16[2 * LMUL][8];
    uint32_t fixu32[2 * LMUL][4];
    uint64_t fixu64[2 * LMUL][2];
    uint64_t float64[2 * LMUL][2];
    uint32_t float32[2 * LMUL][4];
    uint16_t float16[2 * LMUL][8];
    int16_t  wfixs16[LMUL][16];
    int32_t  wfixs32[LMUL][8];
    int64_t  wfixs64[LMUL][4];
    uint16_t wfixu16[LMUL][16];
    uint32_t wfixu32[LMUL][8];
    uint64_t wfixu64[LMUL][4];
    uint64_t wfloat64[2 * LMUL][4];
    uint32_t wfloat32[2 * LMUL][8];
};

struct _vmreg {
    int8_t   fixs8[16];
    int16_t  fixs16[8];
    int32_t  fixs32[4];
    int64_t  fixs64[2];
    uint8_t   fixu8[16];
    uint16_t  fixu16[8];
    uint32_t  fixu32[4];
    uint64_t  fixu64[2];
};

struct _vmreg vmo = {
    .fixs8 = {
        [0 ... 15] = 0x10,
    },
    .fixs16 = {
        [0 ... 7] = 0x0100,
    },
    .fixs32 = {
        [0 ... 3] = 0x00010000,
    },
    .fixs64 = {
        [0 ... 1] = 0x0000000100000000,
    },
    .fixu8 = {
        [0 ... 15] = 0x10,
    },
    .fixu16 = {
        [0 ... 7] = 0x0100,
    },
    .fixu32 = {
        [0 ... 3] = 0x00010000,
    },
    .fixu64 = {
        [0 ... 1] = 0x0000000100000000,
    },
};

struct _vmreg vma = {
    .fixs8 = {
        [0 ... 15] = 0x11,
    },
    .fixs16 = {
        [0 ... 7] = 0x0101,
    },
    .fixs32 = {
        [0 ... 3] = 0x00010001,
    },
    .fixs64 = {
        [0 ... 1] = 0x0000000100000001,
    },
    .fixu8 = {
        [0 ... 15] = 0x11,
    },
    .fixu16 = {
        [0 ... 7] = 0x0101,
    },
    .fixu32 = {
        [0 ... 3] = 0x00010001,
    },
    .fixu64 = {
        [0 ... 1] = 0x0000000100000001,
    },
};

struct _vmreg vme = {
    .fixs8 = {
        [0 ... 15] = 0x01,
    },
    .fixs16 = {
        [0 ... 7] = 0x0001,
    },
    .fixs32 = {
        [0 ... 3] = 0x00000001,
    },
    .fixs64 = {
        [0 ... 1] = 0x0000000000000001,
    },
    .fixu8 = {
        [0 ... 15] = 0x01,
    },
    .fixu16 = {
        [0 ... 7] = 0x0001,
    },
    .fixu32 = {
        [0 ... 3] = 0x00000001,
    },
    .fixu64 = {
        [0 ... 1] = 0x0000000000000001,
    },
};

struct rvv_reg  pad = {
    .fixs8 = {
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    .fixs16 = {
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
    },
    .fixs32 = {
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
    },
    .fixs64 = {
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
    },
    .fixu8 = {
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
        {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, },
    },
    .fixu16 = {
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
        {0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1111, },
    },
    .fixu32 = {
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
        {0x11111111, 0x11111111, 0x11111111, 0x11111111, },
    },
    .fixu64 = {
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
        {0x1111111111111111, 0x1111111111111111, },
    },
};

int vlmax_8 = (LMUL * VLEN) / 8;
int vlmax_16 = (LMUL * VLEN) / 16;
int vlmax_32 = (LMUL * VLEN) / 32;
int vlmax_64 = (LMUL * VLEN) / 64;

static inline void result_compare_s8_lmul(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_s16_lmul(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s32_lmul(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s64_lmul(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}
/* #define DEBUG */
static inline void result_compare_s8(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s16(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s32(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_s64(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
    printf("\n");
}

static inline void result_compare_u8(uint8_t *dst, uint8_t *ref)
{
    int i;
    for (i = 0; i < 16; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#02hhx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 16; i++) {
        printf("%#02hhx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u16(uint16_t *dst, uint16_t *ref)
{
    int i;
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#04hx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 8; i++) {
        printf("%#04hx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u32(uint32_t *dst, uint32_t *ref)
{
    int i;
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#08x, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 4; i++) {
        printf("%#08x, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u64(uint64_t *dst, uint64_t *ref)
{
    int i;
    for (i = 0; i < 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("%#016llx, ", dst[i]);
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 2; i++) {
        printf("%#016llx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_u8_lmul(uint8_t *dst, uint8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%02hhx, 0x%02hhx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u16_lmul(uint16_t *dst, uint16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%04hx, 0x%04hx, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u32_lmul(uint32_t *dst, uint32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_u64_lmul(uint64_t *dst, uint64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
}

inline void result_compare_f32(uint32_t *dst, uint32_t *ref)
{
    int i;
#ifdef DEBUG
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
        printf("0x%x, ", dst[i]);
    }
    printf("\n");
    for (i = 0; i < 4; i++) {
        printf("0x%x, ", ref[i]);
    }
    printf("\n");
#else
    for (i = 0; i < 4; i++) {
        TEST(dst[i] == ref[i]);
    }
#endif
}

inline void result_compare_f16(uint16_t *dst, uint16_t *ref)
{
    int i;
#ifdef DEBUG
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
        printf("0x%x, ", dst[i]);
    }
    printf("\n");
    for (i = 0; i < 8; i++) {
        printf("0x%x, ", ref[i]);
    }
    printf("\n");
#else
    for (i = 0; i < 8; i++) {
        TEST(dst[i] == ref[i]);
    }
#endif
}

static inline void result_compare_s8_lmulw(int8_t *dst, int8_t *ref)
{
    int i;
    for (i = 0; i < 16 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        if (dst[i] != ref[i]) {
            printf("0x%02hhx \n", dst[i]);
        }
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 16 * LMUL * 2; i++) {
        printf("0x%02hhx, ", dst[i]);
    }
#endif
}

static inline void result_compare_s16_lmulw(int16_t *dst, int16_t *ref)
{
    int i;
    for (i = 0; i < 8 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        if (dst[i] != ref[i]) {
            printf("0x%04hx \n", dst[i]);
        }
#endif
    }
#ifdef DEBUG
    for (i = 0; i < 8 * LMUL * 2; i++) {
        printf("0x%04hx, ", dst[i]);
    }
    printf("\n");
#endif
}

static inline void result_compare_s32_lmulw(int32_t *dst, int32_t *ref)
{
    int i;
    for (i = 0; i < 4 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%08x, 0x%08x, ", dst[i], ref[i]);
#endif
    }
}

static inline void result_compare_s64_lmulw(int64_t *dst, int64_t *ref)
{
    int i;
    for (i = 0; i < 2 * LMUL * 2; i++) {
        TEST(dst[i] == ref[i]);
#ifdef DEBUG
        printf("0x%016llx, 0x%016llx, ", dst[i], ref[i]);
#endif
    }
}

void test_vfmv_v_f_16(int a, uint64_t b, void *c, void *d);
void test_vfmv_v_f_32(uint64_t a, void *b, int *c);
void test_vfmv_v_f_64(uint64_t a, void *b, void *c);

void test_vfmerge_vfm_16(int a, void *b, int c, void *d, void *e, void *f);
void test_vfmerge_vfm_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmerge_vfm_32(int a, void *b, int c, void *d, void *e, void *f);
void test_vfmerge_vfm_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmerge_vfm_64(int a, void *b, long long int c, void *d, void *e, void * f);
void test_vfmerge_vfm_64_vm(void *a, long long int b, void *c, void *d, void *e);


void test_vlseg2huff_32(int a, void *b, void *c, void* d, void *e);
void test_vlseg2wuff_64(int a, void *b, void *c, void* d, void *e);
void test_vlseg2buff_16(int a, void *b, void *c, void* d, void *e);
void test_vlseg2eff_16(int a, void *b, void *c, void* d, void *e);
void test_vlseg2wff_64(int a, void *b, void *c, void* d, void *e);
void test_vlseg2hff_32(int a, void *b, void *c, void* d, void *e);
void test_vlseg2bff_16(int a, void *b, void *c, void* d, void *e);
int test_vleff_8(int a, void *b, void *c, void* d);
void test_vleff_8_vm(void *a, void *b, void *c, void* d);
int test_vleff_16(int a, void *b, void *c, void* d);
void test_vleff_16_vm(void *a, void *b, void *c, void* d);
int test_vleff_32(int a, void *b, void *c, void* d);
void test_vleff_32_vm(void *a, void *b, void *c, void* d);
int test_vleff_64(int a, void *b, void *c, void* d);
void test_vleff_64_vm(void *a, void *b, void *c, void* d);

int test_vlwff_32(int a, void *b, void *c, void* d);
void test_vlwff_32_vm(void *a, void *b, void *c, void* d);
int test_vlwff_64(int a, void *b, void *c, void* d);
void test_vlwff_64_vm(void *a, void *b, void *c, void* d);

int test_vlwuff_32(int a, void *b, void *c, void* d);
void test_vlwuff_32_vm(void *a, void *b, void *c, void* d);
int test_vlwuff_64(int a, void *b, void *c, void* d);
void test_vlwuff_64_vm(void *a, void *b, void *c, void* d);

int test_vlhff_16(int a, void *b, void *c, void* d);
void test_vlhff_16_vm(void *a, void *b, void *c, void* d);
int test_vlhff_32(int a, void *b, void *c, void* d);
void test_vlhff_32_vm(void *a, void *b, void *c, void* d);
int test_vlhff_64(int a, void *b, void *c, void* d);
void test_vlhff_64_vm(void *a, void *b, void *c, void* d);

int test_vlhuff_16(int a, void *b, void *c, void* d);
void test_vlhuff_16_vm(void *a, void *b, void *c, void* d);
int test_vlhuff_32(int a, void *b, void *c, void* d);
void test_vlhuff_32_vm(void *a, void *b, void *c, void* d);
int test_vlhuff_64(int a, void *b, void *c, void* d);
void test_vlhuff_64_vm(void *a, void *b, void *c, void* d);

int test_vlbff_8(int a, void *b, void *c, void* d);
void test_vlbff_8_vm(void *a, void *b, void *c, void* d);
int test_vlbff_16(int a, void *b, void *c, void* d);
void test_vlbff_16_vm(void *a, void *b, void *c, void* d);
int test_vlbff_32(int a, void *b, void *c, void* d);
void test_vlbff_32_vm(void *a, void *b, void *c, void* d);
int test_vlbff_64(int a, void *b, void *c, void* d);
void test_vlbff_64_vm(void *a, void *b, void *c, void* d);

int test_vlbuff_8(int a, void *b, void *c, void* d);
void test_vlbuff_8_vm(void *a, void *b, void *c, void* d);
int test_vlbuff_16(int a, void *b, void *c, void* d);
void test_vlbuff_16_vm(void *a, void *b, void *c, void* d);
int test_vlbuff_32(int a, void *b, void *c, void* d);
void test_vlbuff_32_vm(void *a, void *b, void *c, void* d);
int test_vlbuff_64(int a, void *b, void *c, void* d);
void test_vlbuff_64_vm(void *a, void *b, void *c, void* d);

void test_vamoxord_64(int a, void *b, void *c, void* d, void *e);
void test_vamoxord_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoxorw_32(int a, void *b, void *c, void* d, void *e);
void test_vamoxorw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoxorw_64(int a, void *b, void *c, void* d, void *e);
void test_vamoxorw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamoord_64(int a, void *b, void *c, void* d, void *e);
void test_vamoord_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoorw_32(int a, void *b, void *c, void* d, void *e);
void test_vamoorw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoorw_64(int a, void *b, void *c, void* d, void *e);
void test_vamoorw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamoandd_64(int a, void *b, void *c, void* d, void *e);
void test_vamoandd_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoandw_32(int a, void *b, void *c, void* d, void *e);
void test_vamoandw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoandw_64(int a, void *b, void *c, void* d, void *e);
void test_vamoandw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamomind_64(int a, void *b, void *c, void* d, void *e);
void test_vamomind_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamominw_32(int a, void *b, void *c, void* d, void *e);
void test_vamominw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamominw_64(int a, void *b, void *c, void* d, void *e);
void test_vamominw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamomaxd_64(int a, void *b, void *c, void* d, void *e);
void test_vamomaxd_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamomaxw_32(int a, void *b, void *c, void* d, void *e);
void test_vamomaxw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamomaxw_64(int a, void *b, void *c, void* d, void *e);
void test_vamomaxw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamomaxud_64(int a, void *b, void *c, void* d, void *e);
void test_vamomaxud_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamomaxuw_32(int a, void *b, void *c, void* d, void *e);
void test_vamomaxuw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamomaxuw_64(int a, void *b, void *c, void* d, void *e);
void test_vamomaxuw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamominud_64(int a, void *b, void *c, void* d, void *e);
void test_vamominud_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamominuw_32(int a, void *b, void *c, void* d, void *e);
void test_vamominuw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamominuw_64(int a, void *b, void *c, void* d, void *e);
void test_vamominuw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamoaddd_64(int a, void *b, void *c, void* d, void *e);
void test_vamoaddd_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoaddw_32(int a, void *b, void *c, void* d, void *e);
void test_vamoaddw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoaddw_64(int a, void *b, void *c, void* d, void *e);
void test_vamoaddw_64_vm(void *a, void *b, void *c, void* d, void *e);


void test_vamoswapd_64(int a, void *b, void *c, void* d, void *e);
void test_vamoswapd_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoswapw_32(int a, void *b, void *c, void* d, void *e);
void test_vamoswapw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vamoswapw_64(int a, void *b, void *c, void* d, void *e);
void test_vamoswapw_64_vm(void *a, void *b, void *c, void* d, void *e);

void test_vmv_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmv_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmv_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmv_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmv_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmv_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmv_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmv_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmv_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmv_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmv_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmv_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmv_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmv_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmv_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmv_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmv_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmv_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmv_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmv_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmv_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmv_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmv_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmv_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmerge_vxm_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmerge_vxm_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmerge_vxm_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmerge_vxm_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmerge_vxm_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmerge_vxm_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmerge_vxm_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmerge_vxm_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmerge_vim_8(int a, void *b, void *d, void *e, void *f);
void test_vmerge_vim_8_vm(void *a, void *c, void *d, void *e);
void test_vmerge_vim_16(int a, void *b, void *d, void *e, void *f);
void test_vmerge_vim_16_vm(void *a, void *c, void *d, void *e);
void test_vmerge_vim_32(int a, void *b, void *d, void *e, void *f);
void test_vmerge_vim_32_vm(void *a, void *c, void *d, void *e);
void test_vmerge_vim_64(int a, void *b, void *d, void *e, void *f);
void test_vmerge_vim_64_vm(void *a, void *c, void *d, void *e);

void test_vmerge_vvm_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmerge_vvm_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmerge_vvm_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmerge_vvm_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmerge_vvm_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmerge_vvm_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmerge_vvm_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmerge_vvm_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vwmaccus_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccus_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccus_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccus_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccus_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccus_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vwmaccsu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmaccsu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmaccsu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmaccsu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmaccsu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmaccsu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmaccsu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccsu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccsu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccsu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccsu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccsu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vwmacc_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmacc_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmacc_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmacc_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmacc_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmacc_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmacc_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmacc_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmacc_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmacc_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vwmaccu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmaccu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmaccu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmaccu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmaccu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmaccu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmaccu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmaccu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmaccu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vnmsub_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsub_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsub_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsub_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsub_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsub_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsub_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsub_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vnmsub_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsub_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsub_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsub_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsub_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);



void test_vmadd_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadd_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadd_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadd_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadd_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadd_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadd_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadd_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmadd_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadd_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadd_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadd_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadd_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);



void test_vnmsac_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsac_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsac_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsac_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsac_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsac_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vnmsac_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vnmsac_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vnmsac_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsac_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsac_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsac_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsac_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsac_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnmsac_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vnmsac_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmacc_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmacc_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmacc_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmacc_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmacc_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmacc_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmacc_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmacc_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmacc_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmacc_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmacc_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmacc_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmacc_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmacc_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vwmulsu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmulsu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmulsu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmulsu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmulsu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmulsu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmulsu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulsu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmulsu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulsu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmulsu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulsu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwmul_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmul_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmul_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmul_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmul_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmul_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmul_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmul_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmul_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmul_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmul_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmul_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwmulu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwmulu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmulu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwmulu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwmulu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwmulu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwmulu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmulu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwmulu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwmulu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vremu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vremu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vremu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vremu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vremu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vremu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vremu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vremu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vremu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vremu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vremu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vremu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vremu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vremu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vremu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vremu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vrem_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vrem_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vrem_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vrem_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vrem_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vrem_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vrem_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vrem_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vrem_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vrem_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrem_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vrem_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrem_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vrem_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrem_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vrem_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vdivu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdivu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdivu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdivu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdivu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdivu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdivu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdivu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vdivu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdivu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdivu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdivu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdivu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdivu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdivu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdivu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vdiv_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdiv_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdiv_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdiv_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdiv_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdiv_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vdiv_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vdiv_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vdiv_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdiv_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdiv_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdiv_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdiv_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdiv_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vdiv_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vdiv_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmulhsu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhsu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhsu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhsu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhsu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhsu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhsu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhsu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmulhsu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhsu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhsu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhsu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhsu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhsu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhsu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhsu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmulhu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulhu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulhu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmulhu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulhu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulhu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmulh_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulh_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulh_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulh_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulh_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulh_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmulh_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmulh_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmulh_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulh_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulh_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulh_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulh_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulh_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmulh_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmulh_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmul_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmul_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmul_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmul_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmul_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmul_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmul_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmul_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmul_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmul_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmul_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmul_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmul_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmul_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmul_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmul_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmaxu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmaxu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmaxu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmaxu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmaxu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmaxu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmaxu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmaxu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmaxu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmaxu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmaxu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmaxu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmaxu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmaxu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmaxu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmaxu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmax_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmax_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmax_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmax_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmax_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmax_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmax_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmax_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmax_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmax_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmax_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmax_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmax_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmax_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmax_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmax_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vminu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vminu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vminu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vminu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vminu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vminu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vminu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vminu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vminu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vminu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vminu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vminu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vminu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vminu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vminu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vminu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmin_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmin_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmin_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmin_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmin_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmin_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmin_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmin_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmin_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmin_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmin_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmin_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmin_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmin_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmin_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmin_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmsgtu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgtu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgtu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgtu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgtu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgtu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgtu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgtu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsgtu_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmsgtu_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmsgtu_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmsgtu_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmsgtu_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmsgtu_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmsgtu_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmsgtu_vi_64_vm(void *a, void *c, void *d, void *e);


void test_vmsgt_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgt_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgt_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgt_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgt_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgt_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsgt_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsgt_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsgt_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmsgt_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmsgt_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmsgt_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmsgt_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmsgt_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmsgt_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmsgt_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmsltu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsltu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsltu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsltu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsltu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsltu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsltu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsltu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsltu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsltu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsltu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsltu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsltu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsltu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsltu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsltu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmslt_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmslt_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmslt_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmslt_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmslt_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmslt_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmslt_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmslt_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmslt_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmslt_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmslt_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmslt_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmslt_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmslt_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmslt_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmslt_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmsleu_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsleu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsleu_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsleu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsleu_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsleu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsleu_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsleu_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsleu_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmsleu_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmsleu_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmsleu_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmsleu_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmsleu_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmsleu_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmsleu_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmsleu_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsleu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsleu_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsleu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsleu_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsleu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsleu_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsleu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);


void test_vmsle_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsle_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsle_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsle_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsle_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsle_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsle_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsle_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsle_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmsle_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmsle_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmsle_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmsle_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmsle_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmsle_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmsle_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmsle_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsle_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsle_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsle_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsle_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsle_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsle_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsle_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmsne_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsne_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsne_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsne_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsne_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsne_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsne_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsne_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmsne_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmsne_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmsne_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmsne_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmsne_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmsne_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmsne_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmsne_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmsne_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsne_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsne_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsne_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsne_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsne_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsne_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsne_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmseq_vx_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmseq_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmseq_vx_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmseq_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmseq_vx_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmseq_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmseq_vx_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmseq_vx_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmseq_vi_8(int a, void *b, void *d, void *e, void *f);
void test_vmseq_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vmseq_vi_16(int a, void *b, void *d, void *e, void *f);
void test_vmseq_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vmseq_vi_32(int a, void *b, void *d, void *e, void *f);
void test_vmseq_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vmseq_vi_64(int a, void *b, void *d, void *e, void *f);
void test_vmseq_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vmseq_vv_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmseq_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmseq_vv_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmseq_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmseq_vv_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmseq_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmseq_vv_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmseq_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vnsrl_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vnsrl_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vnsrl_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vnsrl_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vnsrl_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vnsrl_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vnsrl_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vnsrl_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vnsrl_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vnsrl_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vnsrl_vi_8(int a, void *b, void *d, void *e);
void test_vnsrl_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vnsrl_vi_16(int a, void *b, void *d, void *e);
void test_vnsrl_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vnsrl_vi_32(int a, void *b, void *d, void *e);
void test_vnsrl_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vnsrl_vi_64(int a, void *b, void *d, void *e);
void test_vnsrl_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vnsra_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vnsra_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vnsra_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vnsra_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vnsra_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vnsra_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vnsra_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vnsra_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vnsra_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vnsra_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vnsra_vi_8(int a, void *b, void *d, void *e);
void test_vnsra_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vnsra_vi_16(int a, void *b, void *d, void *e);
void test_vnsra_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vnsra_vi_32(int a, void *b, void *d, void *e);
void test_vnsra_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vnsra_vi_64(int a, void *b, void *d, void *e);
void test_vnsra_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vsll_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsll_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsll_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsll_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsll_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsll_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsll_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsll_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsll_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vsll_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vsll_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vsll_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vsll_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vsll_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vsll_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vsll_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vsll_vi_8(int a, void *b, void *d, void *e);
void test_vsll_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vsll_vi_16(int a, void *b, void *d, void *e);
void test_vsll_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vsll_vi_32(int a, void *b, void *d, void *e);
void test_vsll_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vsll_vi_64(int a, void *b, void *d, void *e);
void test_vsll_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vsrl_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsrl_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsrl_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vsrl_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vsrl_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vsrl_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vsrl_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vsrl_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vsrl_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vsrl_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vsrl_vi_8(int a, void *b, void *d, void *e);
void test_vsrl_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vsrl_vi_16(int a, void *b, void *d, void *e);
void test_vsrl_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vsrl_vi_32(int a, void *b, void *d, void *e);
void test_vsrl_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vsrl_vi_64(int a, void *b, void *d, void *e);
void test_vsrl_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vsra_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsra_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsra_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsra_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsra_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsra_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsra_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsra_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsra_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vsra_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vsra_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vsra_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vsra_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vsra_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vsra_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vsra_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vsra_vi_8(int a, void *b, void *d, void *e);
void test_vsra_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vsra_vi_16(int a, void *b, void *d, void *e);
void test_vsra_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vsra_vi_32(int a, void *b, void *d, void *e);
void test_vsra_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vsra_vi_64(int a, void *b, void *d, void *e);
void test_vsra_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vand_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vand_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vand_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vand_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vand_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vand_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vand_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vand_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vand_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vand_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vand_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vand_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vand_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vand_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vand_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vand_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vand_vi_8(int a, void *b, void *d, void *e);
void test_vand_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vand_vi_16(int a, void *b, void *d, void *e);
void test_vand_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vand_vi_32(int a, void *b, void *d, void *e);
void test_vand_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vand_vi_64(int a, void *b, void *d, void *e);
void test_vand_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vor_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vor_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vor_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vor_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vor_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vor_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vor_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vor_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vor_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vor_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vor_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vor_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vor_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vor_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vor_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vor_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vor_vi_8(int a, void *b, void *d, void *e);
void test_vor_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vor_vi_16(int a, void *b, void *d, void *e);
void test_vor_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vor_vi_32(int a, void *b, void *d, void *e);
void test_vor_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vor_vi_64(int a, void *b, void *d, void *e);
void test_vor_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vxor_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vxor_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vxor_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vxor_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vxor_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vxor_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vxor_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vxor_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vxor_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vxor_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vxor_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vxor_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vxor_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vxor_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vxor_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vxor_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vxor_vi_8(int a, void *b, void *d, void *e);
void test_vxor_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vxor_vi_16(int a, void *b, void *d, void *e);
void test_vxor_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vxor_vi_32(int a, void *b, void *d, void *e);
void test_vxor_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vxor_vi_64(int a, void *b, void *d, void *e);
void test_vxor_vi_64_vm(void *a, void *c, void *d, void *e);


void test_vadd_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vadd_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadd_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vadd_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vadd_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vadd_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vadd_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vadd_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vadd_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vadd_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vadd_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vadd_vi_8(int a, void *b, void *d, void *e);
void test_vadd_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vadd_vi_16(int a, void *b, void *d, void *e);
void test_vadd_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vadd_vi_32(int a, void *b, void *d, void *e);
void test_vadd_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vadd_vi_64(int a, void *b, void *d, void *e);
void test_vadd_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vsub_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsub_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsub_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsub_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vsub_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vsub_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vsub_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vsub_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vsub_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vsub_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vsub_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vrsub_vx_8(int a, void *b, uint8_t c, void *d, void *e);
void test_vrsub_vx_8_vm(void *a, uint8_t b, void *c, void *d, void *e);
void test_vrsub_vx_16(int a, void *b, uint16_t c, void *d, void *e);
void test_vrsub_vx_16_vm(void *a, uint16_t, void *c, void *d, void *e);
void test_vrsub_vx_32(int a, void *b, uint32_t, void *d, void *e);
void test_vrsub_vx_32_vm(void *a, uint32_t, void *c, void *d, void *e);
void test_vrsub_vx_64(int a, void *b, uint64_t, void *d, void *e);
void test_vrsub_vx_64_vm(void *a, uint64_t, void *c, void *d, void *e);

void test_vrsub_vi_8(int a, void *b, void *d, void *e);
void test_vrsub_vi_8_vm(void *a, void *c, void *d, void *e);
void test_vrsub_vi_16(int a, void *b, void *d, void *e);
void test_vrsub_vi_16_vm(void *a, void *c, void *d, void *e);
void test_vrsub_vi_32(int a, void *b, void *d, void *e);
void test_vrsub_vi_32_vm(void *a, void *c, void *d, void *e);
void test_vrsub_vi_64(int a, void *b, void *d, void *e);
void test_vrsub_vi_64_vm(void *a, void *c, void *d, void *e);

void test_vwaddu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwaddu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwaddu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwaddu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwaddu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwaddu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwsubu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsubu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsubu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwsubu_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsubu_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsubu_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vwadd_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwadd_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwadd_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwadd_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwadd_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwsub_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vwsub_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vwsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vwsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwsub_vx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_vx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsub_vx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_vx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsub_vx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_vx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwaddu_wv_8(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_wv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwaddu_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwaddu_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vwaddu_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwaddu_wx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_wx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwaddu_wx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_wx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwaddu_wx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwaddu_wx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwsubu_wv_8(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_wv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsubu_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsubu_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vwsubu_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwsubu_wx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_wx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsubu_wx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_wx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsubu_wx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsubu_wx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);


void test_vwadd_wv_8(int a, void *b, void *c, void *d, void *e);
void test_vwadd_wv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwadd_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vwadd_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwadd_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vwadd_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwadd_wx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_wx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwadd_wx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_wx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwadd_wx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwadd_wx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vwsub_wv_8(int a, void *b, void *c, void *d, void *e);
void test_vwsub_wv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsub_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vwsub_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwsub_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vwsub_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwsub_wx_8(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_wx_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsub_wx_16(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_wx_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vwsub_wx_32(int a, void *b, uint64_t c, void *d, void *e);
void test_vwsub_wx_32_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vadc_vvm_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vadc_vvm_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadc_vvm_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vadc_vvm_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadc_vvm_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vadc_vvm_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vadc_vvm_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vadc_vvm_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vadc_vxm_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vadc_vxm_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vadc_vxm_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vadc_vxm_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vadc_vxm_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vadc_vxm_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vadc_vxm_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vadc_vxm_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vadc_vim_8(int a, void *b, void *d, void *e, void *f);
void test_vadc_vim_8_vm(void *a, void *c, void *d, void *e);
void test_vadc_vim_16(int a, void *b, void *d, void *e, void *f);
void test_vadc_vim_16_vm(void *a, void *c, void *d, void *e);
void test_vadc_vim_32(int a, void *b, void *d, void *e, void *f);
void test_vadc_vim_32_vm(void *a, void *c, void *d, void *e);
void test_vadc_vim_64(int a, void *b, void *d, void *e, void *f);
void test_vadc_vim_64_vm(void *a, void *c, void *d, void *e);

void test_vsbc_vvm_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vsbc_vvm_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsbc_vvm_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vsbc_vvm_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsbc_vvm_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vsbc_vvm_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsbc_vvm_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vsbc_vvm_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsbc_vxm_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vsbc_vxm_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vsbc_vxm_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vsbc_vxm_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vsbc_vxm_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vsbc_vxm_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vsbc_vxm_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vsbc_vxm_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmadc_vvm_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadc_vvm_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadc_vvm_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadc_vvm_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadc_vvm_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadc_vvm_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmadc_vvm_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmadc_vvm_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmadc_vxm_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadc_vxm_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadc_vxm_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadc_vxm_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadc_vxm_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadc_vxm_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmadc_vxm_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmadc_vxm_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vmadc_vim_8(int a, void *b, void *d, void *e, void *f);
void test_vmadc_vim_8_vm(void *a, void *c, void *d, void *e);
void test_vmadc_vim_16(int a, void *b, void *d, void *e, void *f);
void test_vmadc_vim_16_vm(void *a, void *c, void *d, void *e);
void test_vmadc_vim_32(int a, void *b, void *d, void *e, void *f);
void test_vmadc_vim_32_vm(void *a, void *c, void *d, void *e);
void test_vmadc_vim_64(int a, void *b, void *d, void *e, void *f);
void test_vmadc_vim_64_vm(void *a, void *c, void *d, void *e);

void test_vmsbc_vvm_8(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsbc_vvm_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsbc_vvm_16(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsbc_vvm_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsbc_vvm_32(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsbc_vvm_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmsbc_vvm_64(int a, void *b, void *c, void *d, void *e, void *f);
void test_vmsbc_vvm_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmsbc_vxm_8(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsbc_vxm_8_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsbc_vxm_16(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsbc_vxm_16_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsbc_vxm_32(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsbc_vxm_32_vm(void *a, uint64_t b, void *c, void *d, void *e);
void test_vmsbc_vxm_64(int a, void *b, uint64_t c, void *d, void *e, void *f);
void test_vmsbc_vxm_64_vm(void *a, uint64_t b, void *c, void *d, void *e);

void test_vlb_8(int a, void *b, void *c, void* d);
void test_vlb_8_vm(void *a, void *b, void *c, void* d);
void test_vlb_16(int a, void *b, void *c, void* d);
void test_vlb_16_vm(void *a, void *b, void *c, void* d);
void test_vlb_32(int a, void *b, void *c, void* d);
void test_vlb_32_vm(void *a, void *b, void *c, void* d);
void test_vlb_64(int a, void *b, void *c, void* d);
void test_vlb_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2b_16(int a, void *b, void *c, void* d, void *e);

void test_vlh_16(int a, void *b, void *c, void* d);
void test_vlh_16_vm(void *a, void *b, void *c, void* d);
void test_vlh_32(int a, void *b, void *c, void* d);
void test_vlh_32_vm(void *a, void *b, void *c, void* d);
void test_vlh_64(int a, void *b, void *c, void* d);
void test_vlh_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2h_32(int a, void *b, void *c, void* d, void *e);

void test_vlw_32(int a, void *b, void *c, void* d);
void test_vlw_32_vm(void *a, void *b, void *c, void* d);
void test_vlw_64(int a, void *b, void *c, void* d);
void test_vlw_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2w_64(int a, void *b, void *c, void* d, void *e);

void test_vle_8(int a, void *b, void *c, void* d);
void test_vle_8_vm(void *a, void *b, void *c, void* d);
void test_vle_16(int a, void *b, void *c, void* d);
void test_vle_16_vm(void *a, void *b, void *c, void* d);
void test_vle_32(int a, void *b, void *c, void* d);
void test_vle_32_vm(void *a, void *b, void *c, void* d);
void test_vle_64(int a, void *b, void *c, void* d);
void test_vle_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2e_16(int a, void *b, void *c, void* d, void *e);

void test_vlbu_8(int a, void *b, void *c, void* d);
void test_vlbu_8_vm(void *a, void *b, void *c, void* d);
void test_vlbu_16(int a, void *b, void *c, void* d);
void test_vlbu_16_vm(void *a, void *b, void *c, void* d);
void test_vlbu_32(int a, void *b, void *c, void* d);
void test_vlbu_32_vm(void *a, void *b, void *c, void* d);
void test_vlbu_64(int a, void *b, void *c, void* d);
void test_vlbu_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2bu_16(int a, void *b, void *c, void* d, void *e);

void test_vlhu_16(int a, void *b, void *c, void* d);
void test_vlhu_16_vm(void *a, void *b, void *c, void* d);
void test_vlhu_32(int a, void *b, void *c, void* d);
void test_vlhu_32_vm(void *a, void *b, void *c, void* d);
void test_vlhu_64(int a, void *b, void *c, void* d);
void test_vlhu_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2hu_32(int a, void *b, void *c, void* d, void *e);

void test_vlwu_32(int a, void *b, void *c, void* d);
void test_vlwu_32_vm(void *a, void *b, void *c, void* d);
void test_vlwu_64(int a, void *b, void *c, void* d);
void test_vlwu_64_vm(void *a, void *b, void *c, void* d);
void test_vlseg2wu_64(int a, void *b, void *c, void* d, void *e);

void test_vsb_8(int a, void *b, void *c, void* d);
void test_vsb_8_vm(void *a, void *b, void *c, void* d);
void test_vsb_16(int a, void *b, void *c, void* d);
void test_vsb_16_vm(void *a, void *b, void *c, void* d);
void test_vsb_32(int a, void *b, void *c, void* d);
void test_vsb_32_vm(void *a, void *b, void *c, void* d);
void test_vsb_64(int a, void *b, void *c, void* d);
void test_vsb_64_vm(void *a, void *b, void *c, void* d);
void test_vsseg2b_16(void *b, void *c, void* d, void *e);

void test_vsh_16(int a, void *b, void *c, void* d);
void test_vsh_16_vm(void *a, void *b, void *c, void* d);
void test_vsh_32(int a, void *b, void *c, void* d);
void test_vsh_32_vm(void *a, void *b, void *c, void* d);
void test_vsh_64(int a, void *b, void *c, void* d);
void test_vsh_64_vm(void *a, void *b, void *c, void* d);
void test_vsseg2h_32(void *b, void *c, void* d, void *e);

void test_vsw_32(int a, void *b, void *c, void* d);
void test_vsw_32_vm(void *a, void *b, void *c, void* d);
void test_vsw_64(int a, void *b, void *c, void* d);
void test_vsw_64_vm(void *a, void *b, void *c, void* d);
void test_vsseg2w_64(void *b, void *c, void* d, void *e);

void test_vse_8(int a, void *b, void *c, void* d);
void test_vse_8_vm(void *a, void *b, void *c, void* d);
void test_vse_16(int a, void *b, void *c, void* d);
void test_vse_16_vm(void *a, void *b, void *c, void* d);
void test_vse_32(int a, void *b, void *c, void* d);
void test_vse_32_vm(void *a, void *b, void *c, void* d);
void test_vse_64(int a, void *b, void *c, void* d);
void test_vse_64_vm(void *a, void *b, void *c, void* d);
void test_vsseg2e_16(int a, void *b, void *c, void* d, void *e);

void test_vlsb_8(int a, void *b, void *c, void *d);
void test_vlsb_8_vm(int a, void *b, void *c, void *d, void *e);
void test_vlsb_16(void *b, void *c, void *d);
void test_vlsb_16_vm(void *a, void *b, void *c, void *d);
void test_vlsb_32(void *b, void *c, void *d);
void test_vlsb_32_vm(void *a, void *b, void *c, void *d);
void test_vlsb_64(void *b, void *c, void *d);
void test_vlsb_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2b_16(int a, void *b, void *c, void* d, void *e);

void test_vlsh_16(int a, void *b, void *c, void *d);
void test_vlsh_16_vm(int a, void *b, void *c, void *d, void *e);
void test_vlsh_32(void *b, void *c, void *d);
void test_vlsh_32_vm(void *a, void *b, void *c, void *d);
void test_vlsh_64(void *b, void *c, void *d);
void test_vlsh_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2h_32(int a, void *b, void *c, void* d, void *e);

void test_vlsw_32(int a, void *b, void *c, void *d);
void test_vlsw_32_vm(int a, void *b, void *c, void *d, void *e);
void test_vlsw_64(void *b, void *c, void *d);
void test_vlsw_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2w_64(int a, void *b, void *c, void* d, void *e);

void test_vlse_8(int a, void *b, void *c, void *d);
void test_vlse_8_vm(int a, void *b, void *c, void *d, void *e);
void test_vlse_16(int a, void *b, void *c, void *d);
void test_vlse_16_vm(int a, void *b, void *c, void *d, void *e);
void test_vlse_32(int a, void *b, void *c, void *d);
void test_vlse_32_vm(int a, void *b, void *c, void *d, void *e);
void test_vlse_64(int a, void *b, void *c, void *d);
void test_vlse_64_vm(int a, void *b, void *c, void *d, void *e);
void test_vlsseg2e_16(int a, void *b, void *c, void* d, void *e);

void test_vlsbu_8(int a, void *b, void *c, void *d);
void test_vlsbu_8_vm(int a, void *b, void *c, void *d, void *e);
void test_vlsbu_16(void *b, void *c, void *d);
void test_vlsbu_16_vm(void *a, void *b, void *c, void *d);
void test_vlsbu_32(void *b, void *c, void *d);
void test_vlsbu_32_vm(void *a, void *b, void *c, void *d);
void test_vlsbu_64(void *b, void *c, void *d);
void test_vlsbu_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2bu_16(int a, void *b, void *c, void* d, void *e);

void test_vlshu_16(int a, void *b, void *c, void *d);
void test_vlshu_16_vm(int a, void *b, void *c, void *d, void *e);
void test_vlshu_32(void *b, void *c, void *d);
void test_vlshu_32_vm(void *a, void *b, void *c, void *d);
void test_vlshu_64(void *b, void *c, void *d);
void test_vlshu_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2hu_32(int a, void *b, void *c, void* d, void *e);

void test_vlswu_32(int a, void *b, void *c, void *d);
void test_vlswu_32_vm(int a, void *b, void *c, void *d, void *e);
void test_vlswu_64(void *b, void *c, void *d);
void test_vlswu_64_vm(void *a, void *b, void *c, void *d);
void test_vlsseg2wu_64(int a, void *b, void *c, void* d, void *e);

void test_vssb_8(int a, void *b, void *c, void* d);
void test_vssb_8_vm(int a, void *b, void *c, void* d, void *e);
void test_vssb_16(int a, void *b, void *c, void* d);
void test_vssb_16_vm(int a, void *b, void *c, void* d, void *e);
void test_vssb_32(int a, void *b, void *c, void* d);
void test_vssb_32_vm(int a, void *b, void *c, void* d, void *e);
void test_vssb_64(int a, void *b, void *c, void* d);
void test_vssb_64_vm(int a, void *b, void *c, void* d, void *e);
void test_vssseg2b_16(void *b, void *c, void* d, void *e);

void test_vssh_16(int a, void *b, void *c, void* d);
void test_vssh_16_vm(int a, void *b, void *c, void* d, void *e);
void test_vssh_32(int a, void *b, void *c, void* d);
void test_vssh_32_vm(int a, void *b, void *c, void* d, void *e);
void test_vssh_64(int a, void *b, void *c, void* d);
void test_vssh_64_vm(int a, void *b, void *c, void* d, void *e);
void test_vssseg2h_32(void *b, void *c, void* d, void *e);

void test_vssw_32(int a, void *b, void *c, void* d);
void test_vssw_32_vm(int a, void *b, void *c, void* d, void *e);
void test_vssw_64(int a, void *b, void *c, void* d);
void test_vssw_64_vm(int a, void *b, void *c, void* d, void *e);
void test_vssseg2w_64(void *b, void *c, void* d, void *e);

void test_vsse_8(int a, void *b, void *c, void* d);
void test_vsse_8_vm(int a, void *b, void *c, void* d, void *e);
void test_vsse_16(int a, void *b, void *c, void* d);
void test_vsse_16_vm(int a, void *b, void *c, void* d, void *e);
void test_vsse_32(int a, void *b, void *c, void* d);
void test_vsse_32_vm(int a, void *b, void *c, void* d, void *e);
void test_vsse_64(int a, void *b, void *c, void* d);
void test_vsse_64_vm(int a, void *b, void *c, void* d, void *e);
void test_vssseg2e_16(void *b, void *c, void* d, void *e);

void test_vlxb_8(int a, void *b, void *c, void* d, void *e);
void test_vlxb_8_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxb_16(int a, void *b, void *c, void* d, void *e);
void test_vlxb_16_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxb_32(int a, void *b, void *c, void* d, void *e);
void test_vlxb_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxb_64(int a, void *b, void *c, void* d, void *e);
void test_vlxb_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2b_16(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxh_16(int a, void *b, void *c, void* d, void *e);
void test_vlxh_16_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxh_32(int a, void *b, void *c, void* d, void *e);
void test_vlxh_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxh_64(int a, void *b, void *c, void* d, void *e);
void test_vlxh_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2h_32(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxw_32(int a, void *b, void *c, void* d, void *e);
void test_vlxw_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxw_64(int a, void *b, void *c, void* d, void *e);
void test_vlxw_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2w_64(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxe_8(int a, void *b, void *c, void* d, void *e);
void test_vlxe_8_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxe_16(int a, void *b, void *c, void* d, void *e);
void test_vlxe_16_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxe_32(int a, void *b, void *c, void* d, void *e);
void test_vlxe_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxe_64(int a, void *b, void *c, void* d, void *e);
void test_vlxe_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2e_16(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxbu_8(int a, void *b, void *c, void* d, void *e);
void test_vlxbu_8_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxbu_16(int a, void *b, void *c, void* d, void *e);
void test_vlxbu_16_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxbu_32(int a, void *b, void *c, void* d, void *e);
void test_vlxbu_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxbu_64(int a, void *b, void *c, void* d, void *e);
void test_vlxbu_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2bu_16(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxhu_16(int a, void *b, void *c, void* d, void *e);
void test_vlxhu_16_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxhu_32(int a, void *b, void *c, void* d, void *e);
void test_vlxhu_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxhu_64(int a, void *b, void *c, void* d, void *e);
void test_vlxhu_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2hu_32(int a, void *b, void *c, void* d, void *e, void *f);

void test_vlxwu_32(int a, void *b, void *c, void* d, void *e);
void test_vlxwu_32_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxwu_64(int a, void *b, void *c, void* d, void *e);
void test_vlxwu_64_vm(void *a, void *b, void *c, void* d, void *e);
void test_vlxseg2wu_64(int a, void *b, void *c, void* d, void *e, void *f);

void test_vsxb_8(int a, void *b, void *c, void *d, void *e);
void test_vsxb_8_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxb_16(int a, void *b, void *c, void *d, void *e);
void test_vsxb_16_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxb_32(int a, void *b, void *c, void *d, void *e);
void test_vsxb_32_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxb_64(int a, void *b, void *c, void *d, void *e);
void test_vsxb_64_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxseg2b_16(void *b, void *c, void* d, void *e, void *f);

void test_vsxh_16(int a, void *b, void *c, void *d, void *e);
void test_vsxh_16_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxh_32(int a, void *b, void *c, void *d, void *e);
void test_vsxh_32_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxh_64(int a, void *b, void *c, void *d, void *e);
void test_vsxh_64_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxseg2h_32(void *b, void *c, void* d, void *e, void *f);

void test_vsxw_32(int a, void *b, void *c, void *d, void *e);
void test_vsxw_32_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxw_64(int a, void *b, void *c, void *d, void *e);
void test_vsxw_64_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxseg2w_64(void *b, void *c, void* d, void *e, void *f);

void test_vsxe_8(int a, void *b, void *c, void *d, void *e);
void test_vsxe_8_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxe_16(int a, void *b, void *c, void *d, void *e);
void test_vsxe_16_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxe_32(int a, void *b, void *c, void *d, void *e);
void test_vsxe_32_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxe_64(int a, void *b, void *c, void *d, void *e);
void test_vsxe_64_vm(int a, void *b, void *c, void* d, void *e, void *f);
void test_vsxseg2e_16(void *b, void *c, void* d, void *e, void *f);

void test_vsadd_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsaddu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vsaddu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vsadd_vx_8(int a, void *b, int c, void *d, void *e);
void test_vsadd_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vsadd_vx_16(int a, void *b, int c, void *d, void *e);
void test_vsadd_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vsadd_vx_32(int a, void *b, int c, void *d, void *e);
void test_vsadd_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vsadd_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vsadd_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vsaddu_vx_8(int a, void *b, int c, void *d, void *e);
void test_vsaddu_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vsaddu_vx_16(int a, void *b, int c, void *d, void *e);
void test_vsaddu_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vsaddu_vx_32(int a, void *b, int c, void *d, void *e);
void test_vsaddu_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vsaddu_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vsaddu_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vsadd_vi_8_min(int a, void *b, void *c, void *d);
void test_vsadd_vi_8_max(int a, void *b, void *c, void *d);
void test_vsadd_vi_8_vm(void *a, void *b, void *c, void *d);
void test_vsadd_vi_16_min(int a, void *b, void *c, void *d);
void test_vsadd_vi_16_max(int a, void *b, void *c, void *d);
void test_vsadd_vi_16_vm(void *a, void *b, void *c, void *d);
void test_vsadd_vi_32_min(int a, void *b, void *c, void *d);
void test_vsadd_vi_32_max(int a, void *b, void *c, void *d);
void test_vsadd_vi_32_vm(void *a, void *b, void *c, void *d);
void test_vsadd_vi_64_min(int a, void *b, void *c, void *d);
void test_vsadd_vi_64_max(int a, void *b, void *c, void *d);
void test_vsadd_vi_64_vm(void *a, void *b, void *c, void *d);

void test_vsaddu_vi_8(int a, void *b, void *c, void *d);
void test_vsaddu_vi_8_vm(void *a, void *b, void *c, void *d);
void test_vsaddu_vi_16(int a, void *b, void *c, void *d);
void test_vsaddu_vi_16_vm(void *a, void *b, void *c, void *d);
void test_vsaddu_vi_32(int a, void *b, void *c, void *d);
void test_vsaddu_vi_32_vm(void *a, void *b, void *c, void *d);
void test_vsaddu_vi_64(int a, void *b, void *c, void *d);
void test_vsaddu_vi_64_vm(void *a, void *b, void *c, void *d);

void test_vssub_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vssub_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vssub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vssub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssub_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vssub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vssubu_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vssubu_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vssub_vx_8(int a, void *b, int c, void *d, void *e);
void test_vssub_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vssub_vx_16(int a, void *b, int c, void *d, void *e);
void test_vssub_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vssub_vx_32(int a, void *b, int c, void *d, void *e);
void test_vssub_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vssub_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vssub_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vssubu_vx_8(int a, void *b, int c, void *d, void *e);
void test_vssubu_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vssubu_vx_16(int a, void *b, int c, void *d, void *e);
void test_vssubu_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vssubu_vx_32(int a, void *b, int c, void *d, void *e);
void test_vssubu_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vssubu_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vssubu_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vaadd_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_8_rod(void *a, void *b, void *c);
void test_vaadd_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_16_rod(void *a, void *b, void *c);
void test_vaadd_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_32_rod(void *a, void *b, void *c);
void test_vaadd_vv_64_rnu(int a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_64_rne(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_64_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vaadd_vv_64_rod(void *a, void *b, void *c);

void test_vaadd_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vaadd_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_8_rod(void *a, int b, void *c, void *d);
void test_vaadd_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vaadd_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_16_rod(void *a, int b, void *c, void *d);
void test_vaadd_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vaadd_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vaadd_vx_32_rod(void *a, int b, void *c, void *d);
void test_vaadd_vx_64_rnu(int a, void *b, long long int c, void *d, void *e);
void test_vaadd_vx_64_rne(void *a, long long int b, void *c, void *d, void *e);
void test_vaadd_vx_64_rdn(void *a, long long int b, void *c, void *d, void *e);
void test_vaadd_vx_64_rod(void *a, long long int b, void *c, void *d);

void test_vaadd_vi_8_rnu(int a, void *b, void *c, void *d);
void test_vaadd_vi_8_rne(void *a, void *b, void *c, void *d);
void test_vaadd_vi_8_rdn(void *a, void *b, void *c, void *d);
void test_vaadd_vi_8_rod(void *a, void *b, void *c);
void test_vaadd_vi_16_rnu(int a, void *b, void *c, void *d);
void test_vaadd_vi_16_rne(void *a, void *b, void *c, void *d);
void test_vaadd_vi_16_rdn(void *a, void *b, void *c, void *d);
void test_vaadd_vi_16_rod(void *a, void *b, void *c);
void test_vaadd_vi_32_rnu(int a, void *b, void *c, void *d);
void test_vaadd_vi_32_rne(void *a, void *b, void *c, void *d);
void test_vaadd_vi_32_rdn(void *a, void *b, void *c, void *d);
void test_vaadd_vi_32_rod(void *a, void *b, void *c);
void test_vaadd_vi_64_rnu(int a, void *b, void *c, void *d);
void test_vaadd_vi_64_rne(void *a, void *b, void *c, void *d);
void test_vaadd_vi_64_rdn(void *a, void *b, void *c, void *d);
void test_vaadd_vi_64_rod(void *a, void *b, void *c);

void test_vasub_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vasub_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_8_rod(void *a, void *b, void *c);
void test_vasub_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vasub_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_16_rod(void *a, void *b, void *c);
void test_vasub_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vasub_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_32_rod(void *a, void *b, void *c);
void test_vasub_vv_64_rnu(int a, void *b, void *c, void *d, void *e);
void test_vasub_vv_64_rne(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_64_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vasub_vv_64_rod(void *a, void *b, void *c);

void test_vasub_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vasub_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_8_rod(void *a, int b, void *c, void *d);
void test_vasub_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vasub_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_16_rod(void *a, int b, void *c, void *d);
void test_vasub_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vasub_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vasub_vx_32_rod(void *a, int b, void *c, void *d);
void test_vasub_vx_64_rnu(int a, void *b, long long int c, void *d, void *e);
void test_vasub_vx_64_rne(void *a, long long int b, void *c, void *d, void *e);
void test_vasub_vx_64_rdn(void *a, long long int b, void *c, void *d, void *e);
void test_vasub_vx_64_rod(void *a, long long int b, void *c, void *d);

void test_vsmul_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_8_rod(void *a, void *b, void *c);
void test_vsmul_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_16_rod(void *a, void *b, void *c);
void test_vsmul_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_32_rod(void *a, void *b, void *c);
void test_vsmul_vv_64_rnu(int a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_64_rne(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_64_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vsmul_vv_64_rod(void *a, void *b, void *c);

void test_vsmul_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vsmul_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_8_rod(void *a, int b, void *c, void *d);
void test_vsmul_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vsmul_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_16_rod(void *a, int b, void *c, void *d);
void test_vsmul_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vsmul_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vsmul_vx_32_rod(void *a, int b, void *c, void *d);
void test_vsmul_vx_64_rnu(int a, void *b, long long int c, void *d, void *e);
void test_vsmul_vx_64_rne(void *a, long long int b, void *c, void *d, void *e);
void test_vsmul_vx_64_rdn(void *a, long long int b, void *c, void *d, void *e);
void test_vsmul_vx_64_rod(void *a, long long int b, void *c, void *d);

void test_vwsmacc_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_8_rod(void *a, void *b, void *c, void *d);
void test_vwsmacc_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_16_rod(void *a, void *b, void *c, void *d);
void test_vwsmacc_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmacc_vv_32_rod(void *a, void *b, void *c, void *d);

void test_vwsmaccu_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_8_rod(void *a, void *b, void *c, void *d);
void test_vwsmaccu_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_16_rod(void *a, void *b, void *c, void *d);
void test_vwsmaccu_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccu_vv_32_rod(void *a, void *b, void *c, void *d);

void test_vwsmacc_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmacc_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_8_rod(void *a, int b, void *c, void *d);
void test_vwsmacc_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmacc_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_16_rod(void *a, int b, void *c, void *d);
void test_vwsmacc_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmacc_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmacc_vx_32_rod(void *a, int b, void *c, void *d);

void test_vwsmaccu_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccu_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_8_rod(void *a, int b, void *c, void *d);
void test_vwsmaccu_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccu_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_16_rod(void *a, int b, void *c, void *d);
void test_vwsmaccu_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccu_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccu_vx_32_rod(void *a, int b, void *c, void *d);

void test_vwsmaccsu_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_8_rod(void *a, void *b, void *c, void *d);
void test_vwsmaccsu_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_16_rod(void *a, void *b, void *c, void *d);
void test_vwsmaccsu_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vwsmaccsu_vv_32_rod(void *a, void *b, void *c, void *d);

void test_vwsmaccsu_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccsu_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_8_rod(void *a, int b, void *c, void *d);
void test_vwsmaccsu_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccsu_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_16_rod(void *a, int b, void *c, void *d);
void test_vwsmaccsu_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccsu_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccsu_vx_32_rod(void *a, int b, void *c, void *d);

void test_vwsmaccus_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccus_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_8_rod(void *a, int b, void *c, void *d);
void test_vwsmaccus_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccus_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_16_rod(void *a, int b, void *c, void *d);
void test_vwsmaccus_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vwsmaccus_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vwsmaccus_vx_32_rod(void *a, int b, void *c, void *d);

void test_vssrl_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_8_rod(void *a, void *b, void *c);
void test_vssrl_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_16_rod(void *a, void *b, void *c);
void test_vssrl_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_32_rod(void *a, void *b, void *c);
void test_vssrl_vv_64_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_64_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_64_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssrl_vv_64_rod(void *a, void *b, void *c);

void test_vssrl_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vssrl_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_8_rod(void *a, int b, void *c);
void test_vssrl_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vssrl_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_16_rod(void *a, int b, void *c);
void test_vssrl_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vssrl_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssrl_vx_32_rod(void *a, int b, void *c);
void test_vssrl_vx_64_rnu(int a, void *b, long long int c, void *d, void *e);
void test_vssrl_vx_64_rne(void *a, long long int b, void *c, void *d, void *e);
void test_vssrl_vx_64_rdn(void *a, long long int b, void *c, void *d, void *e);
void test_vssrl_vx_64_rod(void *a, long long int b, void *c);

void test_vssrl_vi_8_rnu(int a, void *b, void *c, void *d);
void test_vssrl_vi_8_rne(void *a, void *b, void *c, void *d);
void test_vssrl_vi_8_rdn(void *a, void *b, void *c, void *d);
void test_vssrl_vi_8_rod(void *a, void *b, void *c);
void test_vssrl_vi_16_rnu(int a, void *b, void *c, void *d);
void test_vssrl_vi_16_rne(void *a, void *b, void *c, void *d);
void test_vssrl_vi_16_rdn(void *a, void *b, void *c, void *d);
void test_vssrl_vi_16_rod(void *a, void *b, void *c);
void test_vssrl_vi_32_rnu(int a, void *b, void *c, void *d);
void test_vssrl_vi_32_rne(void *a, void *b, void *c, void *d);
void test_vssrl_vi_32_rdn(void *a, void *b, void *c, void *d);
void test_vssrl_vi_32_rod(void *a, void *b, void *c);
void test_vssrl_vi_64_rnu(int a, void *b, void *c, void *d);
void test_vssrl_vi_64_rne(void *a, void *b, void *c, void *d);
void test_vssrl_vi_64_rdn(void *a, void *b, void *c, void *d);
void test_vssrl_vi_64_rod(void *a, void *b, void *c);

void test_vssra_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssra_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_8_rod(void *a, void *b, void *c);
void test_vssra_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssra_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_16_rod(void *a, void *b, void *c);
void test_vssra_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssra_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_32_rod(void *a, void *b, void *c);
void test_vssra_vv_64_rnu(int a, void *b, void *c, void *d, void *e);
void test_vssra_vv_64_rne(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_64_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vssra_vv_64_rod(void *a, void *b, void *c);

void test_vssra_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vssra_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_8_rod(void *a, int b, void *c);
void test_vssra_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vssra_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_16_rod(void *a, int b, void *c);
void test_vssra_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vssra_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vssra_vx_32_rod(void *a, int b, void *c);
void test_vssra_vx_64_rnu(int a, void *b, long long int c, void *d, void *e);
void test_vssra_vx_64_rne(void *a, long long int b, void *c, void *d, void *e);
void test_vssra_vx_64_rdn(void *a, long long int b, void *c, void *d, void *e);
void test_vssra_vx_64_rod(void *a, long long int b, void *c);

void test_vssra_vi_8_rnu(int a, void *b, void *c, void *d);
void test_vssra_vi_8_rne(void *a, void *b, void *c, void *d);
void test_vssra_vi_8_rdn(void *a, void *b, void *c, void *d);
void test_vssra_vi_8_rod(void *a, void *b, void *c);
void test_vssra_vi_16_rnu(int a, void *b, void *c, void *d);
void test_vssra_vi_16_rne(void *a, void *b, void *c, void *d);
void test_vssra_vi_16_rdn(void *a, void *b, void *c, void *d);
void test_vssra_vi_16_rod(void *a, void *b, void *c);
void test_vssra_vi_32_rnu(int a, void *b, void *c, void *d);
void test_vssra_vi_32_rne(void *a, void *b, void *c, void *d);
void test_vssra_vi_32_rdn(void *a, void *b, void *c, void *d);
void test_vssra_vi_32_rod(void *a, void *b, void *c);
void test_vssra_vi_64_rnu(int a, void *b, void *c, void *d);
void test_vssra_vi_64_rne(void *a, void *b, void *c, void *d);
void test_vssra_vi_64_rdn(void *a, void *b, void *c, void *d);
void test_vssra_vi_64_rod(void *a, void *b, void *c);

void test_vnclip_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_8_rod(void *a, void *b, void *c);
void test_vnclip_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_16_rod(void *a, void *b, void *c);
void test_vnclip_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclip_vv_32_rod(void *a, void *b, void *c);

void test_vnclipu_vv_8_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_8_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_8_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_8_rod(void *a, void *b, void *c);
void test_vnclipu_vv_16_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_16_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_16_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_16_rod(void *a, void *b, void *c);
void test_vnclipu_vv_32_rnu(int a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_32_rne(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_32_rdn(void *a, void *b, void *c, void *d, void *e);
void test_vnclipu_vv_32_rod(void *a, void *b, void *c);

void test_vnclip_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclip_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_8_rod(void *a, int b, void *c);
void test_vnclip_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclip_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_16_rod(void *a, int b, void *c);
void test_vnclip_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclip_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclip_vx_32_rod(void *a, int b, void *c);

void test_vnclipu_vx_8_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclipu_vx_8_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_8_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_8_rod(void *a, int b, void *c);
void test_vnclipu_vx_16_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclipu_vx_16_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_16_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_16_rod(void *a, int b, void *c);
void test_vnclipu_vx_32_rnu(int a, void *b, int c, void *d, void *e);
void test_vnclipu_vx_32_rne(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_32_rdn(void *a, int b, void *c, void *d, void *e);
void test_vnclipu_vx_32_rod(void *a, int b, void *c);

void test_vnclip_vi_8_rnu(int a, void *b, void *c, void *d);
void test_vnclip_vi_8_rne(void *a, void *b, void *c, void *d);
void test_vnclip_vi_8_rdn(void *a, void *b, void *c, void *d);
void test_vnclip_vi_8_rod(void *a, void *b);
void test_vnclip_vi_16_rnu(int a, void *b, void *c, void *d);
void test_vnclip_vi_16_rne(void *a, void *b, void *c, void *d);
void test_vnclip_vi_16_rdn(void *a, void *b, void *c, void *d);
void test_vnclip_vi_16_rod(void *a, void *b);
void test_vnclip_vi_32_rnu(int a, void *b, void *c, void *d);
void test_vnclip_vi_32_rne(void *a, void *b, void *c, void *d);
void test_vnclip_vi_32_rdn(void *a, void *b, void *c, void *d);
void test_vnclip_vi_32_rod(void *a, void *b);

void test_vnclipu_vi_8_rnu(int a, void *b, void *c, void *d);
void test_vnclipu_vi_8_rne(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_8_rdn(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_8_rod(void *a, void *b);
void test_vnclipu_vi_16_rnu(int a, void *b, void *c, void *d);
void test_vnclipu_vi_16_rne(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_16_rdn(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_16_rod(void *a, void *b);
void test_vnclipu_vi_32_rnu(int a, void *b, void *c, void *d);
void test_vnclipu_vi_32_rne(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_32_rdn(void *a, void *b, void *c, void *d);
void test_vnclipu_vi_32_rod(void *a, void *b);

void test_vredsum_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredsum_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredmax_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredmax_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredmaxu_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredmaxu_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredmin_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredmin_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredminu_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredminu_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredand_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredand_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredand_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredand_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredand_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredand_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredand_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredand_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredor_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredor_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredor_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredor_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredor_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredor_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredor_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredor_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vredxor_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vredxor_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwredsum_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vwredsum_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vwredsumu_vs_8(int a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vwredsumu_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfredsum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfredsum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredsum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfredsum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredsum_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vfredsum_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfredosum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfredosum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredosum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfredosum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredosum_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vfredosum_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfredmax_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfredmax_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredmax_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfredmax_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredmax_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vfredmax_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfredmin_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfredmin_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredmin_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfredmin_vs_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfredmin_vs_64(int a, void *b, void *c, void *d, void *e);
void test_vfredmin_vs_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwredsum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfwredsum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwredsum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfwredsum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwredosum_vs_16(int a, void *b, void *c, void *d, void *e);
void test_vfwredosum_vs_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwredosum_vs_32(int a, void *b, void *c, void *d, void *e);
void test_vfwredosum_vs_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmand_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmand_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmand_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmand_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmnand_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmnand_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmnand_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmnand_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmandnot_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmandnot_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmandnot_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmandnot_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmxor_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmxor_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmxor_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmxor_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmor_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmor_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmor_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmor_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmnor_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmnor_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmnor_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmnor_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmornot_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmornot_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmornot_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmornot_mm_64(int a, void *b, void *c, void *d, void *e);

void test_vmxnor_mm_8(int a, void *b, void *c, void *d, void *e);
void test_vmxnor_mm_16(int a, void *b, void *c, void *d, void *e);
void test_vmxnor_mm_32(int a, void *b, void *c, void *d, void *e);
void test_vmxnor_mm_64(int a, void *b, void *c, void *d, void *e);

int test_vmpopc_m_8(void *a, int b);
int test_vmpopc_m_8_vm(void *a, void *b);
int test_vmpopc_m_16(void *a, int b);
int test_vmpopc_m_16_vm(void *a, void *b);
int test_vmpopc_m_32(void *a, int b);
int test_vmpopc_m_32_vm(void *a, void *b);
int test_vmpopc_m_64(void *a, int b);
int test_vmpopc_m_64_vm(void *a, void *b);

int test_vmfirst_m_8(void *a, int b);
int test_vmfirst_m_8_vm(void *a, void *b);
int test_vmfirst_m_16(void *a, int b);
int test_vmfirst_m_16_vm(void *a, void *b);
int test_vmfirst_m_32(void *a, int b);
int test_vmfirst_m_32_vm(void *a, void *b);
int test_vmfirst_m_64(void *a, int b);
int test_vmfirst_m_64_vm(void *a, void *b);

void test_vmsbf_m_8(void *a, void *b, void *c,  int d);
void test_vmsbf_m_8_vm(void *a, void *b, void *c,  void *d);
void test_vmsbf_m_16(void *a, void *b, void *c,  int d);
void test_vmsbf_m_16_vm(void *a, void *b, void *c,  void *d);
void test_vmsbf_m_32(void *a, void *b, void *c,  int d);
void test_vmsbf_m_32_vm(void *a, void *b, void *c,  void *d);
void test_vmsbf_m_64(void *a, void *b, void *c,  int d);
void test_vmsbf_m_64_vm(void *a, void *b, void *c,  void *d);

void test_vmsif_m_8(void *a, void *b, void *c,  int d);
void test_vmsif_m_8_vm(void *a, void *b, void *c,  void *d);
void test_vmsif_m_16(void *a, void *b, void *c,  int d);
void test_vmsif_m_16_vm(void *a, void *b, void *c,  void *d);
void test_vmsif_m_32(void *a, void *b, void *c,  int d);
void test_vmsif_m_32_vm(void *a, void *b, void *c,  void *d);
void test_vmsif_m_64(void *a, void *b, void *c,  int d);
void test_vmsif_m_64_vm(void *a, void *b, void *c,  void *d);

void test_vmsof_m_8(void *a, void *b, void *c,  int d);
void test_vmsof_m_8_vm(void *a, void *b, void *c,  void *d);
void test_vmsof_m_16(void *a, void *b, void *c,  int d);
void test_vmsof_m_16_vm(void *a, void *b, void *c,  void *d);
void test_vmsof_m_32(void *a, void *b, void *c,  int d);
void test_vmsof_m_32_vm(void *a, void *b, void *c,  void *d);
void test_vmsof_m_64(void *a, void *b, void *c,  int d);
void test_vmsof_m_64_vm(void *a, void *b, void *c,  void *d);

void test_viota_m_8(void *a, void *b, void *c,  int d);
void test_viota_m_8_vm(void *a, void *b, void *c,  void *d);
void test_viota_m_16(void *a, void *b, void *c,  int d);
void test_viota_m_16_vm(void *a, void *b, void *c,  void *d);
void test_viota_m_32(void *a, void *b, void *c,  int d);
void test_viota_m_32_vm(void *a, void *b, void *c,  void *d);
void test_viota_m_64(void *a, void *b, void *c,  int d);
void test_viota_m_64_vm(void *a, void *b, void *c,  void *d);

void test_vid_v_8(void *a, void *b, void *c,  int d);
void test_vid_v_8_vm(void *a, void *b, void *c,  void *d);
void test_vid_v_16(void *a, void *b, void *c,  int d);
void test_vid_v_16_vm(void *a, void *b, void *c,  void *d);
void test_vid_v_32(void *a, void *b, void *c,  int d);
void test_vid_v_32_vm(void *a, void *b, void *c,  void *d);
void test_vid_v_64(void *a, void *b, void *c,  int d);
void test_vid_v_64_vm(void *a, void *b, void *c,  void *d);

long long int test_vext_x_v_8(void *a,  int c);
long long int test_vext_x_v_16(void *a, int c);
long long int test_vext_x_v_32(void *a, int c);
long long int test_vext_x_v_64(void *a, int c);

void test_vmv_s_x_8(int a,  void *b);
void test_vmv_s_x_16(int a, void *b);
void test_vmv_s_x_32(int a, void *b);
void test_vmv_s_x_64(long long int a, void *b);

long long int test_vfmv_f_s_8(void *a);
long long int test_vfmv_f_s_16(void *a);
long long int test_vfmv_f_s_32(void *a);
long long int test_vfmv_f_s_64(void *a);

void test_vfmv_s_f_8(int a,  void *b, void *c);
void test_vfmv_s_f_16(int a, void *b, void *c);
void test_vfmv_s_f_32(int a, void *b, void *c);
void test_vfmv_s_f_64(long long int a, void *b, void *c);

void test_vslideup_vx_8(int a, void *b, int c, void *d, void *e);
void test_vslideup_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vx_16(int a, void *b, int c, void *d, void *e);
void test_vslideup_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vx_32(int a, void *b, int c, void *d, void *e);
void test_vslideup_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vslideup_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vslideup_vi_8(int a, void *b, int c, void *d, void *e);
void test_vslideup_vi_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vi_16(int a, void *b, int c, void *d, void *e);
void test_vslideup_vi_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vi_32(int a, void *b, int c, void *d, void *e);
void test_vslideup_vi_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslideup_vi_64(int a, void *b, long long int c, void *d, void *e);
void test_vslideup_vi_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vslidedown_vx_8(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vx_16(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vx_32(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vslidedown_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vslidedown_vi_8(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vi_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vi_16(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vi_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vi_32(int a, void *b, int c, void *d, void *e);
void test_vslidedown_vi_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslidedown_vi_64(int a, void *b, long long int c, void *d, void *e);
void test_vslidedown_vi_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vslide1up_vx_8(int a, void *b, int c, void *d, void *e);
void test_vslide1up_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1up_vx_16(int a, void *b, int c, void *d, void *e);
void test_vslide1up_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1up_vx_32(int a, void *b, int c, void *d, void *e);
void test_vslide1up_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1up_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vslide1up_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vslide1down_vx_8(int a, void *b, int c, void *d, void *e);
void test_vslide1down_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1down_vx_16(int a, void *b, int c, void *d, void *e);
void test_vslide1down_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1down_vx_32(int a, void *b, int c, void *d, void *e);
void test_vslide1down_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vslide1down_vx_64(int a, void *b, long long int c, void *d, void *e);
void test_vslide1down_vx_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vrgather_vv_8(int a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_8_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vrgather_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vrgather_vx_8(int a, void *b, int c, void *d, void *e);
void test_vrgather_vx_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vx_16(int a, void *b, int c, void *d, void *e);
void test_vrgather_vx_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vx_32(int a, void *b, int c, void *d, void *e);
void test_vrgather_vx_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vx_64(int a, void *b, int c, void *d, void *e);
void test_vrgather_vx_64_vm(void *a, int b, void *c, void *d, void *e);

void test_vrgather_vi_8(int a, void *b, int c, void *d, void *e);
void test_vrgather_vi_8_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vi_16(int a, void *b, int c, void *d, void *e);
void test_vrgather_vi_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vi_32(int a, void *b, int c, void *d, void *e);
void test_vrgather_vi_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vrgather_vi_64(int a, void *b, int c, void *d, void *e);
void test_vrgather_vi_64_vm(void *a, int b, void *c, void *d, void *e);

void test_vcompress_vm_8(int a, void *b, void *c, void *d, void *e);
void test_vcompress_vm_16(int a, void *b, void *c, void *d, void *e);
void test_vcompress_vm_32(int a, void *b, void *c, void *d, void *e);
void test_vcompress_vm_64(int a, void *b, void *c, void *d, void *e);

void test_vfadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfadd_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfadd_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfadd_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfadd_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfadd_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfadd_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfadd_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsub_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfsub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfsub_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfsub_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsub_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfsub_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsub_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfsub_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfrsub_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfrsub_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfrsub_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfrsub_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfrsub_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfrsub_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfwadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwadd_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwadd_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwadd_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwadd_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwsub_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwsub_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwsub_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwsub_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwadd_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwadd_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwadd_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwadd_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwadd_wf_16(int a, void *b, int c, void *d, void *e);
void test_vfwadd_wf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwadd_wf_32(int a, void *b, int c, void *d, void *e);
void test_vfwadd_wf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwsub_wv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwsub_wv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwsub_wv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwsub_wv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwsub_wf_16(int a, void *b, int c, void *d, void *e);
void test_vfwsub_wf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwsub_wf_32(int a, void *b, int c, void *d, void *e);
void test_vfwsub_wf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfmul_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmul_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmul_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmul_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmul_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmul_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmul_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmul_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmul_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmul_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmul_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmul_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfdiv_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfdiv_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfdiv_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfdiv_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfdiv_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfdiv_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfdiv_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfdiv_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfdiv_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfdiv_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfdiv_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfdiv_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfrdiv_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfrdiv_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfrdiv_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfrdiv_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfrdiv_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfrdiv_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfwmul_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwmul_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwmul_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwmul_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwmul_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwmul_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwmul_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwmul_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfmacc_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmacc_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmacc_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmacc_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmacc_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmacc_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmacc_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmacc_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmacc_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmacc_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfnmacc_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfnmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmacc_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfnmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmacc_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfnmacc_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfnmacc_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfnmacc_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmacc_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfnmacc_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmacc_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfnmacc_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfmsac_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmsac_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmsac_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmsac_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmsac_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmsac_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmsac_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmsac_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmsac_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmsac_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmsac_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmsac_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfnmsac_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfnmsac_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmsac_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfnmsac_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmsac_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfnmsac_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfnmsac_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfnmsac_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmsac_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfnmsac_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmsac_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfnmsac_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfmadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmadd_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmadd_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmadd_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmadd_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmadd_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmadd_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmadd_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfnmadd_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfnmadd_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmadd_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfnmadd_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmadd_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfnmadd_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfnmadd_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfnmadd_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmadd_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfnmadd_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmadd_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfnmadd_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfmsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmsub_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmsub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmsub_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmsub_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmsub_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmsub_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmsub_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmsub_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfnmsub_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfnmsub_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmsub_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfnmsub_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfnmsub_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfnmsub_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfnmsub_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfnmsub_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmsub_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfnmsub_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfnmsub_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfnmsub_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfwmacc_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwmacc_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwmacc_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwmacc_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwmacc_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwmacc_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwnmacc_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwnmacc_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwnmacc_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwnmacc_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwnmacc_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwnmacc_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwnmacc_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwnmacc_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwmsac_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwmsac_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwmsac_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwmsac_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwmsac_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwmsac_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwmsac_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwmsac_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfwnmsac_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfwnmsac_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwnmsac_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfwnmsac_vv_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwnmsac_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfwnmsac_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfwnmsac_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfwnmsac_vf_32_vm(void *a, int b, void *c, void *d, void *e);

void test_vfsqrt_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfsqrt_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsqrt_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfsqrt_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsqrt_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfsqrt_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmin_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmin_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmin_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmin_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmin_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmin_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmin_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmin_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmin_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmin_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmin_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmin_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfmax_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfmax_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmax_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfmax_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfmax_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfmax_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfmax_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfmax_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmax_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfmax_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfmax_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfmax_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfsgnj_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfsgnj_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnj_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfsgnj_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnj_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfsgnj_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfsgnj_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfsgnj_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnj_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfsgnj_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnj_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfsgnj_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfsgnjn_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjn_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnjn_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjn_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnjn_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjn_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfsgnjn_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfsgnjn_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnjn_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfsgnjn_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnjn_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfsgnjn_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfsgnjx_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjx_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnjx_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjx_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfsgnjx_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vfsgnjx_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfsgnjx_vf_16(int a, void *b, int c, void *d, void *e);
void test_vfsgnjx_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnjx_vf_32(int a, void *b, int c, void *d, void *e);
void test_vfsgnjx_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vfsgnjx_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vfsgnjx_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmfeq_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vmfeq_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfeq_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vmfeq_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfeq_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vmfeq_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmfeq_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmfeq_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfeq_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmfeq_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfeq_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmfeq_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmfne_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vmfne_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfne_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vmfne_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfne_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vmfne_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmfne_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmfne_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfne_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmfne_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfne_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmfne_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmflt_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vmflt_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmflt_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vmflt_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmflt_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vmflt_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmflt_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmflt_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmflt_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmflt_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmflt_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmflt_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmfle_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vmfle_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfle_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vmfle_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmfle_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vmfle_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmfle_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmfle_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfle_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmfle_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfle_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmfle_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmfgt_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmfgt_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfgt_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmfgt_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfgt_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmfgt_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmfge_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmfge_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfge_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmfge_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmfge_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmfge_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vmford_vv_16(int a, void *b, void *c, void *d, void *e);
void test_vmford_vv_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmford_vv_32(int a, void *b, void *c, void *d, void *e);
void test_vmford_vv_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vmford_vv_64(int a, void *b, void *c, void *d, void *e);
void test_vmford_vv_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vmford_vf_16(int a, void *b, int c, void *d, void *e);
void test_vmford_vf_16_vm(void *a, int b, void *c, void *d, void *e);
void test_vmford_vf_32(int a, void *b, int c, void *d, void *e);
void test_vmford_vf_32_vm(void *a, int b, void *c, void *d, void *e);
void test_vmford_vf_64(int a, void *b, long long int c, void *d, void *e);
void test_vmford_vf_64_vm(void *a, long long int b, void *c, void *d, void *e);

void test_vfclass_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfclass_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfclass_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfclass_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfclass_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfclass_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfcvt_xu_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_xu_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_xu_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_xu_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_xu_f_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_xu_f_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfcvt_x_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_x_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_x_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_x_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_x_f_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_x_f_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfcvt_f_xu_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_xu_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_xu_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_xu_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_xu_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_xu_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfcvt_f_x_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_x_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_x_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_x_v_32_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_x_v_64(int a, void *b, void *c, void *d, void *e);
void test_vfcvt_f_x_v_64_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwcvt_xu_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_xu_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwcvt_xu_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_xu_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwcvt_x_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_x_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwcvt_x_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_x_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwcvt_f_xu_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_xu_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_xu_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_xu_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwcvt_f_x_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_x_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_x_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_x_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfwcvt_f_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfwcvt_f_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfncvt_xu_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_xu_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfncvt_xu_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_xu_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfncvt_x_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_x_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfncvt_x_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_x_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfncvt_f_xu_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_xu_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_xu_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_xu_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfncvt_f_x_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_x_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_x_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_x_v_32_vm(void *a, void *b, void *c, void *d, void *e);

void test_vfncvt_f_f_v_16(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_f_v_16_vm(void *a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_f_v_32(int a, void *b, void *c, void *d, void *e);
void test_vfncvt_f_f_v_32_vm(void *a, void *b, void *c, void *d, void *e);

#endif
