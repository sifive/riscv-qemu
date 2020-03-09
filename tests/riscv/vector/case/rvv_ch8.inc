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

/* vamomind */
TEST_FUNC(test_vamomind_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamomind.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomind_64, .-test_vamomind_64

TEST_FUNC(test_vamomind_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomind.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomind_64_vm, .-test_vamomind_64_vm


/* vamominw */
TEST_FUNC(test_vamominw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamominw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamominw_32, .-test_vamominw_32

TEST_FUNC(test_vamominw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamominw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamominw_32_vm, .-test_vamominw_32_vm

TEST_FUNC(test_vamominw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamominw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamominw_64, .-test_vamominw_64

TEST_FUNC(test_vamominw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamominw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamominw_64_vm, .-test_vamominw_64_vm


/* vamominud */
TEST_FUNC(test_vamominud_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamominud.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamominud_64, .-test_vamominud_64

TEST_FUNC(test_vamominud_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamominud.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamominud_64_vm, .-test_vamominud_64_vm


/* vamominuw */
TEST_FUNC(test_vamominuw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamominuw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamominuw_32, .-test_vamominuw_32

TEST_FUNC(test_vamominuw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamominuw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamominuw_32_vm, .-test_vamominuw_32_vm

TEST_FUNC(test_vamominuw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamominuw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamominuw_64, .-test_vamominuw_64

TEST_FUNC(test_vamominuw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamominuw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamominuw_64_vm, .-test_vamominuw_64_vm


/* vamomaxd */
TEST_FUNC(test_vamomaxd_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamomaxd.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxd_64, .-test_vamomaxd_64

TEST_FUNC(test_vamomaxd_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxd.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxd_64_vm, .-test_vamomaxd_64_vm


/* vamomaxw */
TEST_FUNC(test_vamomaxw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamomaxw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxw_32, .-test_vamomaxw_32

TEST_FUNC(test_vamomaxw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxw_32_vm, .-test_vamomaxw_32_vm

TEST_FUNC(test_vamomaxw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamomaxw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxw_64, .-test_vamomaxw_64

TEST_FUNC(test_vamomaxw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxw_64_vm, .-test_vamomaxw_64_vm



/* vamomaxud */
TEST_FUNC(test_vamomaxud_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamomaxud.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxud_64, .-test_vamomaxud_64

TEST_FUNC(test_vamomaxud_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxud.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxud_64_vm, .-test_vamomaxud_64_vm


/* vamomaxuw */
TEST_FUNC(test_vamomaxuw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamomaxuw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxuw_32, .-test_vamomaxuw_32

TEST_FUNC(test_vamomaxuw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxuw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxuw_32_vm, .-test_vamomaxuw_32_vm

TEST_FUNC(test_vamomaxuw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamomaxuw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxuw_64, .-test_vamomaxuw_64

TEST_FUNC(test_vamomaxuw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamomaxuw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamomaxuw_64_vm, .-test_vamomaxuw_64_vm



/* vamoord */
TEST_FUNC(test_vamoord_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoord.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoord_64, .-test_vamoord_64

TEST_FUNC(test_vamoord_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoord.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoord_64_vm, .-test_vamoord_64_vm


/* vamoorw */
TEST_FUNC(test_vamoorw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamoorw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoorw_32, .-test_vamoorw_32

TEST_FUNC(test_vamoorw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoorw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoorw_32_vm, .-test_vamoorw_32_vm

TEST_FUNC(test_vamoorw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoorw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoorw_64, .-test_vamoorw_64

TEST_FUNC(test_vamoorw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoorw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoorw_64_vm, .-test_vamoorw_64_vm



/* vamoandd */

TEST_FUNC(test_vamoandd_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoandd.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoandd_64, .-test_vamoandd_64

TEST_FUNC(test_vamoandd_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoandd.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoandd_64_vm, .-test_vamoandd_64_vm


/* vamoandw */
TEST_FUNC(test_vamoandw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamoandw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoandw_32, .-test_vamoandw_32

TEST_FUNC(test_vamoandw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoandw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoandw_32_vm, .-test_vamoandw_32_vm

TEST_FUNC(test_vamoandw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoandw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoandw_64, .-test_vamoandw_64

TEST_FUNC(test_vamoandw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoandw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoandw_64_vm, .-test_vamoandw_64_vm


/* vamoxord */
TEST_FUNC(test_vamoxord_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoxord.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoxord_64, .-test_vamoxord_64

TEST_FUNC(test_vamoxord_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoxord.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoxord_64_vm, .-test_vamoxord_64_vm


/* vamoxorw */
TEST_FUNC(test_vamoxorw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamoxorw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoxorw_32, .-test_vamoxorw_32

TEST_FUNC(test_vamoxorw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoxorw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoxorw_32_vm, .-test_vamoxorw_32_vm

TEST_FUNC(test_vamoxorw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoxorw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoxorw_64, .-test_vamoxorw_64

TEST_FUNC(test_vamoxorw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoxorw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoxorw_64_vm, .-test_vamoxorw_64_vm


/* vamoaddd */
TEST_FUNC(test_vamoaddd_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoaddd.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddd_64, .-test_vamoaddd_64

TEST_FUNC(test_vamoaddd_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoaddd.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddd_64_vm, .-test_vamoaddd_64_vm


/* vamoaddw */
TEST_FUNC(test_vamoaddw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamoaddw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddw_32, .-test_vamoaddw_32

TEST_FUNC(test_vamoaddw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoaddw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddw_32_vm, .-test_vamoaddw_32_vm

TEST_FUNC(test_vamoaddw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoaddw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddw_64, .-test_vamoaddw_64

TEST_FUNC(test_vamoaddw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoaddw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoaddw_64_vm, .-test_vamoaddw_64_vm



/* vamoswapd */
TEST_FUNC(test_vamoswapd_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoswapd.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapd_64, .-test_vamoswapd_64

TEST_FUNC(test_vamoswapd_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoswapd.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapd_64_vm, .-test_vamoswapd_64_vm


/* vamoswapw */
TEST_FUNC(test_vamoswapw_32)
        vsetvli   t0, x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e32, m2
        vamoswapw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e32, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapw_32, .-test_vamoswapw_32

TEST_FUNC(test_vamoswapw_32_vm)
        vsetvli   t0 ,x0, e32, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e32, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoswapw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapw_32_vm, .-test_vamoswapw_32_vm

TEST_FUNC(test_vamoswapw_64)
        vsetvli   t0, x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vsetvli   t0, a0, e64, m2
        vamoswapw.v  v4, v4, (a2), v4
        vsetvli   t0, x0, e64, m2
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapw_64, .-test_vamoswapw_64

TEST_FUNC(test_vamoswapw_64_vm)
        vsetvli   t0 ,x0, e64, m1
        vle.v     v0, (a0)
        vsetvli   t0 ,x0, e64, m2
        vle.v     v2, (a1)
        vse.v     v2, (a4)
        vle.v     v4, (a3)
        vamoswapw.v  v4, v4, (a2), v4, v0.t
        vse.v     v4, (a4)
        ret
        .size   test_vamoswapw_64_vm, .-test_vamoswapw_64_vm


