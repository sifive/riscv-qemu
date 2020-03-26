/*
 * RISC-V translation routines for the RV64Zfh Standard Extension.
 *
 * Copyright (c) 2016-2017 Sagar Karandikar, sagark@eecs.berkeley.edu
 * Copyright (c) 2018 Peer Adelt, peer.adelt@hni.uni-paderborn.de
 *                    Bastian Koppelmann, kbastian@mail.uni-paderborn.de
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

static bool trans_flh(DisasContext *ctx, arg_flh *a)
{
    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    tcg_gen_addi_tl(t0, t0, a->imm);

    tcg_gen_qemu_ld_i64(cpu_fpr[a->rd], t0, ctx->mem_idx, MO_TEUW);

    mark_fs_dirty(ctx);
    tcg_temp_free(t0);
    return true;
}

static bool trans_fsh(DisasContext *ctx, arg_fsh *a)
{
    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    tcg_gen_addi_tl(t0, t0, a->imm);

    tcg_gen_qemu_st_i64(cpu_fpr[a->rs2], t0, ctx->mem_idx, MO_TEUW);

    mark_fs_dirty(ctx);
    tcg_temp_free(t0);
    return true;
}

static bool trans_fmadd_h(DisasContext *ctx, arg_fmadd_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    gen_set_rm(ctx, a->rm);
    gen_helper_fmadd_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                       cpu_fpr[a->rs2], cpu_fpr[a->rs3]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmsub_h(DisasContext *ctx, arg_fmsub_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    gen_set_rm(ctx, a->rm);
    gen_helper_fmsub_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                       cpu_fpr[a->rs2], cpu_fpr[a->rs3]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fnmsub_h(DisasContext *ctx, arg_fnmsub_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    gen_set_rm(ctx, a->rm);
    gen_helper_fnmsub_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                        cpu_fpr[a->rs2], cpu_fpr[a->rs3]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fnmadd_h(DisasContext *ctx, arg_fnmadd_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    gen_set_rm(ctx, a->rm);
    gen_helper_fnmadd_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1],
                        cpu_fpr[a->rs2], cpu_fpr[a->rs3]);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fadd_h(DisasContext *ctx, arg_fadd_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fadd_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsub_h(DisasContext *ctx, arg_fsub_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fsub_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmul_h(DisasContext *ctx, arg_fmul_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fmul_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fdiv_h(DisasContext *ctx, arg_fdiv_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fdiv_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsqrt_h(DisasContext *ctx, arg_fsqrt_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fsqrt_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnj_h(DisasContext *ctx, arg_fsgnj_h *a)
{
    if (a->rs1 == a->rs2) { /* FMOV */
        tcg_gen_mov_i64(cpu_fpr[a->rd], cpu_fpr[a->rs1]);
    } else {
        tcg_gen_deposit_i64(cpu_fpr[a->rd], cpu_fpr[a->rs2],
                            cpu_fpr[a->rs1], 0, 63);
    }
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnjn_h(DisasContext *ctx, arg_fsgnjn_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    if (a->rs1 == a->rs2) { /* FNEG */
        tcg_gen_xori_i64(cpu_fpr[a->rd], cpu_fpr[a->rs1], INT64_MIN);
    } else {
        TCGv_i64 t0 = tcg_temp_new_i64();
        tcg_gen_not_i64(t0, cpu_fpr[a->rs2]);
        tcg_gen_deposit_i64(cpu_fpr[a->rd], t0, cpu_fpr[a->rs1], 0, 63);
        tcg_temp_free_i64(t0);
    }
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fsgnjx_h(DisasContext *ctx, arg_fsgnjx_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    if (a->rs1 == a->rs2) { /* FABS */
        tcg_gen_andi_i64(cpu_fpr[a->rd], cpu_fpr[a->rs1], ~INT64_MIN);
    } else {
        TCGv_i64 t0 = tcg_temp_new_i64();
        tcg_gen_andi_i64(t0, cpu_fpr[a->rs2], INT64_MIN);
        tcg_gen_xor_i64(cpu_fpr[a->rd], cpu_fpr[a->rs1], t0);
        tcg_temp_free_i64(t0);
    }
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmin_h(DisasContext *ctx, arg_fmin_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_helper_fmin_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmax_h(DisasContext *ctx, arg_fmax_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_helper_fmax_h(cpu_fpr[a->rd], cpu_env,
                      cpu_fpr[a->rs1], cpu_fpr[a->rs2]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_s_h(DisasContext *ctx, arg_fcvt_s_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_s_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_d_h(DisasContext *ctx, arg_fcvt_d_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    REQUIRE_EXT(ctx, RVD);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_d_h(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}


static bool trans_fcvt_h_s(DisasContext *ctx, arg_fcvt_h_s *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_s(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_d(DisasContext *ctx, arg_fcvt_h_d *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);
    REQUIRE_EXT(ctx, RVD);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_d(cpu_fpr[a->rd], cpu_env, cpu_fpr[a->rs1]);

    mark_fs_dirty(ctx);
    return true;
}


static bool trans_feq_h(DisasContext *ctx, arg_feq_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_helper_feq_h(t0, cpu_env, cpu_fpr[a->rs1], cpu_fpr[a->rs2]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_flt_h(DisasContext *ctx, arg_flt_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_helper_flt_h(t0, cpu_env, cpu_fpr[a->rs1], cpu_fpr[a->rs2]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_fle_h(DisasContext *ctx, arg_fle_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_helper_fle_h(t0, cpu_env, cpu_fpr[a->rs1], cpu_fpr[a->rs2]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_fclass_h(DisasContext *ctx, arg_fclass_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_helper_fclass_h(t0, cpu_fpr[a->rs1]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);
    return true;
}

static bool trans_fcvt_w_h(DisasContext *ctx, arg_fcvt_w_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_w_h(t0, cpu_env, cpu_fpr[a->rs1]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_fcvt_wu_h(DisasContext *ctx, arg_fcvt_wu_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_wu_h(t0, cpu_env, cpu_fpr[a->rs1]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_fcvt_h_w(DisasContext *ctx, arg_fcvt_h_w *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_w(cpu_fpr[a->rd], cpu_env, t0);
    tcg_temp_free(t0);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_wu(DisasContext *ctx, arg_fcvt_h_wu *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_wu(cpu_fpr[a->rd], cpu_env, t0);
    tcg_temp_free(t0);

    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fmv_x_h(DisasContext *ctx, arg_fmv_x_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVF);

    TCGv t0 = tcg_temp_new();

#if defined(TARGET_RISCV64)
    tcg_gen_ext16s_tl(t0, cpu_fpr[a->rs1]); // 16 bits->64 bits
#else
    tcg_gen_extrl_i64_i32(t0, cpu_fpr[a->rs1]); //16 bits->32 bits
    tcg_gen_ext16s_tl(t0, t0);
#endif

    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);

    return true;
}

static bool trans_fmv_h_x(DisasContext *ctx, arg_fmv_h_x *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVF);

    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);

#if defined(TARGET_RISCV64)
    tcg_gen_mov_i64(cpu_fpr[a->rd], t0);
#else
    TCGv_i64 t1 = tcg_temp_new_i64();
    tcg_gen_extu_i32_i64(t1, t0);
    tcg_gen_mov_i64(cpu_fpr[a->rd], t1);
#endif

    mark_fs_dirty(ctx);
    tcg_temp_free(t0);

    return true;
}

#ifdef TARGET_RISCV64

static bool trans_fcvt_l_h(DisasContext *ctx, arg_fcvt_l_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_l_h(t0, cpu_env, cpu_fpr[a->rs1]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);
    return true;
}

static bool trans_fcvt_lu_h(DisasContext *ctx, arg_fcvt_lu_h *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_lu_h(t0, cpu_env, cpu_fpr[a->rs1]);
    gen_set_gpr(a->rd, t0);
    tcg_temp_free(t0);
    return true;
}

static bool trans_fcvt_h_l(DisasContext *ctx, arg_fcvt_h_l *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_l(cpu_fpr[a->rd], cpu_env, t0);
    tcg_temp_free(t0);
    mark_fs_dirty(ctx);
    return true;
}

static bool trans_fcvt_h_lu(DisasContext *ctx, arg_fcvt_h_lu *a)
{
    REQUIRE_FPU;
    REQUIRE_EXT(ctx, RVZfh);

    TCGv t0 = tcg_temp_new();
    gen_get_gpr(t0, a->rs1);

    gen_set_rm(ctx, a->rm);
    gen_helper_fcvt_h_lu(cpu_fpr[a->rd], cpu_env, t0);
    tcg_temp_free(t0);
    mark_fs_dirty(ctx);
    return true;
}
#endif
