// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBP_TRACE_ENCODER__SYMS_H_
#define VERILATED_VBP_TRACE_ENCODER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbp_trace_encoder.h"

// INCLUDE MODULE CLASSES
#include "Vbp_trace_encoder___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vbp_trace_encoder__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbp_trace_encoder* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbp_trace_encoder___024root    TOP;

    // CONSTRUCTORS
    Vbp_trace_encoder__Syms(VerilatedContext* contextp, const char* namep, Vbp_trace_encoder* modelp);
    ~Vbp_trace_encoder__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
