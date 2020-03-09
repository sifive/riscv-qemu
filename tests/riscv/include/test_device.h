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

#ifndef TEST_DEVICE_H
#define TEST_DEVICE_H

struct unary_calculation {
    uint32_t op1;
    uint32_t result;
};

struct unary64_calculation {
    uint32_t op1;
    uint64_t result;
};

struct binary_calculation {
    uint32_t op1;
    uint32_t op2;
    uint32_t result;
};

struct binary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t result;
};

struct binary64_64_calculation {
   uint64_t op1;
   uint32_t op2;
   uint64_t result;
};

struct ternary_calculation {
    uint32_t op1;
    uint32_t op2;
    uint32_t op3;
    uint32_t result;
};

struct ternary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t op3;
    uint64_t result;
};

struct quanary_calculation {
   uint32_t op1;
   uint32_t op2;
   uint32_t op3;
   uint32_t op4;
   uint32_t result;
};

struct binary64_64_64_calculation {
    uint64_t op1;
    uint64_t op2;
    uint64_t result;
};
#endif  /* TEST_DEVICE_H */
