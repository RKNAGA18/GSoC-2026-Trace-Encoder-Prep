// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbp_trace_encoder.h for the primary calling header

#include "Vbp_trace_encoder__pch.h"
#include "Vbp_trace_encoder___024root.h"

VL_INLINE_OPT void Vbp_trace_encoder___024root___ico_sequent__TOP__0(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->bp_trace_encoder__DOT__branch_active = 
        ((IData)(vlSelf->commit_v_i) & (0x63U == (0x7fU 
                                                  & vlSelf->commit_instr_i)));
    if (vlSelf->bp_trace_encoder__DOT__branch_active) {
        vlSelf->trace_valid_o = 1U;
        vlSelf->trace_packet_o[0U] = 0U;
        vlSelf->trace_packet_o[1U] = 0U;
        vlSelf->trace_packet_o[2U] = 0U;
        vlSelf->trace_packet_o[0U] = (IData)((vlSelf->commit_pc_i 
                                              - vlSelf->bp_trace_encoder__DOT__prev_pc_r));
        vlSelf->trace_packet_o[1U] = (IData)(((vlSelf->commit_pc_i 
                                               - vlSelf->bp_trace_encoder__DOT__prev_pc_r) 
                                              >> 0x20U));
        vlSelf->trace_packet_o[2U] = 0xbeefU;
    } else {
        vlSelf->trace_valid_o = 0U;
        vlSelf->trace_packet_o[0U] = 0U;
        vlSelf->trace_packet_o[1U] = 0U;
        vlSelf->trace_packet_o[2U] = 0U;
    }
}

void Vbp_trace_encoder___024root___eval_ico(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vbp_trace_encoder___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vbp_trace_encoder___024root___eval_triggers__ico(Vbp_trace_encoder___024root* vlSelf);

bool Vbp_trace_encoder___024root___eval_phase__ico(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbp_trace_encoder___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vbp_trace_encoder___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbp_trace_encoder___024root___eval_act(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vbp_trace_encoder___024root___nba_sequent__TOP__0(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->reset_i) {
        vlSelf->bp_trace_encoder__DOT__prev_pc_r = 0ULL;
    } else if (vlSelf->commit_v_i) {
        vlSelf->bp_trace_encoder__DOT__prev_pc_r = vlSelf->commit_pc_i;
    }
    vlSelf->trace_packet_o[0U] = 0U;
    vlSelf->trace_packet_o[1U] = 0U;
    vlSelf->trace_packet_o[2U] = 0U;
    if (vlSelf->bp_trace_encoder__DOT__branch_active) {
        vlSelf->trace_packet_o[0U] = (IData)((vlSelf->commit_pc_i 
                                              - vlSelf->bp_trace_encoder__DOT__prev_pc_r));
        vlSelf->trace_packet_o[1U] = (IData)(((vlSelf->commit_pc_i 
                                               - vlSelf->bp_trace_encoder__DOT__prev_pc_r) 
                                              >> 0x20U));
        vlSelf->trace_packet_o[2U] = 0xbeefU;
    }
}

void Vbp_trace_encoder___024root___eval_nba(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vbp_trace_encoder___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vbp_trace_encoder___024root___eval_triggers__act(Vbp_trace_encoder___024root* vlSelf);

bool Vbp_trace_encoder___024root___eval_phase__act(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbp_trace_encoder___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vbp_trace_encoder___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbp_trace_encoder___024root___eval_phase__nba(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbp_trace_encoder___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbp_trace_encoder___024root___dump_triggers__ico(Vbp_trace_encoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbp_trace_encoder___024root___dump_triggers__nba(Vbp_trace_encoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbp_trace_encoder___024root___dump_triggers__act(Vbp_trace_encoder___024root* vlSelf);
#endif  // VL_DEBUG

void Vbp_trace_encoder___024root___eval(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vbp_trace_encoder___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("bp_trace_encoder.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vbp_trace_encoder___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vbp_trace_encoder___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("bp_trace_encoder.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vbp_trace_encoder___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("bp_trace_encoder.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vbp_trace_encoder___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vbp_trace_encoder___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbp_trace_encoder___024root___eval_debug_assertions(Vbp_trace_encoder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbp_trace_encoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbp_trace_encoder___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->reset_i & 0xfeU))) {
        Verilated::overWidthError("reset_i");}
    if (VL_UNLIKELY((vlSelf->commit_v_i & 0xfeU))) {
        Verilated::overWidthError("commit_v_i");}
}
#endif  // VL_DEBUG
