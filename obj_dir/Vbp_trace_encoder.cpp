// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbp_trace_encoder__pch.h"

//============================================================
// Constructors

Vbp_trace_encoder::Vbp_trace_encoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbp_trace_encoder__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , reset_i{vlSymsp->TOP.reset_i}
    , commit_v_i{vlSymsp->TOP.commit_v_i}
    , trace_valid_o{vlSymsp->TOP.trace_valid_o}
    , commit_instr_i{vlSymsp->TOP.commit_instr_i}
    , trace_packet_o{vlSymsp->TOP.trace_packet_o}
    , commit_pc_i{vlSymsp->TOP.commit_pc_i}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbp_trace_encoder::Vbp_trace_encoder(const char* _vcname__)
    : Vbp_trace_encoder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbp_trace_encoder::~Vbp_trace_encoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbp_trace_encoder___024root___eval_debug_assertions(Vbp_trace_encoder___024root* vlSelf);
#endif  // VL_DEBUG
void Vbp_trace_encoder___024root___eval_static(Vbp_trace_encoder___024root* vlSelf);
void Vbp_trace_encoder___024root___eval_initial(Vbp_trace_encoder___024root* vlSelf);
void Vbp_trace_encoder___024root___eval_settle(Vbp_trace_encoder___024root* vlSelf);
void Vbp_trace_encoder___024root___eval(Vbp_trace_encoder___024root* vlSelf);

void Vbp_trace_encoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbp_trace_encoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbp_trace_encoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbp_trace_encoder___024root___eval_static(&(vlSymsp->TOP));
        Vbp_trace_encoder___024root___eval_initial(&(vlSymsp->TOP));
        Vbp_trace_encoder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbp_trace_encoder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbp_trace_encoder::eventsPending() { return false; }

uint64_t Vbp_trace_encoder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbp_trace_encoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbp_trace_encoder___024root___eval_final(Vbp_trace_encoder___024root* vlSelf);

VL_ATTR_COLD void Vbp_trace_encoder::final() {
    Vbp_trace_encoder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbp_trace_encoder::hierName() const { return vlSymsp->name(); }
const char* Vbp_trace_encoder::modelName() const { return "Vbp_trace_encoder"; }
unsigned Vbp_trace_encoder::threads() const { return 1; }
void Vbp_trace_encoder::prepareClone() const { contextp()->prepareClone(); }
void Vbp_trace_encoder::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vbp_trace_encoder::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbp_trace_encoder::trace()' called on model that was Verilated without --trace option");
}
