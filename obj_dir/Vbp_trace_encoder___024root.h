// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbp_trace_encoder.h for the primary calling header

#ifndef VERILATED_VBP_TRACE_ENCODER___024ROOT_H_
#define VERILATED_VBP_TRACE_ENCODER___024ROOT_H_  // guard

#include "verilated.h"


class Vbp_trace_encoder__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbp_trace_encoder___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(reset_i,0,0);
    VL_IN8(commit_v_i,0,0);
    VL_OUT8(trace_valid_o,0,0);
    CData/*0:0*/ bp_trace_encoder__DOT__branch_active;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(commit_instr_i,31,0);
    VL_OUTW(trace_packet_o,79,0,3);
    IData/*31:0*/ __VactIterCount;
    VL_IN64(commit_pc_i,63,0);
    QData/*63:0*/ bp_trace_encoder__DOT__prev_pc_r;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbp_trace_encoder__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbp_trace_encoder___024root(Vbp_trace_encoder__Syms* symsp, const char* v__name);
    ~Vbp_trace_encoder___024root();
    VL_UNCOPYABLE(Vbp_trace_encoder___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
