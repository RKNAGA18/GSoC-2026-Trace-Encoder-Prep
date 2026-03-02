// Module: bp_me_trace_encoder
// Description: Monitors the BlackParrot backend commit stage for non-linear 
//              control flow (branches/jumps) and generates a compressed trace.

`include "bp_common_defines.svh"
`include "bp_be_defines.svh"

module bp_me_trace_encoder
 import bp_common_pkg::*;
 import bp_be_pkg::*;
#(
  // Standard BlackParrot parameters
  parameter bp_params_e bp_params_p = e_bp_default_cfg
  `declare_bp_proc_params(bp_params_p)
)
(
  input logic clk_i,
  input logic reset_i,

  // --- 1. TAPPING INTO THE COMMIT STAGE ---
  input logic               commit_v_i,   // Is the instruction actually retiring?
  input bp_be_commit_pkt_s  commit_pkt_i, // The packet containing PC and Instruction bits

  // --- 2. THE COMPRESSED TRACE OUTPUT ---
  // Sending the compressed data out to the Zynq PS
  output logic [63:0]       trace_data_o, // The compressed PC delta/branch data
  output logic              trace_v_o,    // Tells the system our trace data is valid
  input  logic              trace_ready_i // Backpressure: system is ready to receive
);

  // ---------------------------------------------------------------------------
  // Internal Logic Draft (To be implemented during GSoC)
  // ---------------------------------------------------------------------------
  
  // Example of Non-Linear Control Flow detection:
  // wire is_branch = commit_pkt_i.instr.t.btype; 
  // wire is_jump   = commit_pkt_i.instr.t.jtype;
  // wire non_linear_event = commit_v_i & (is_branch | is_jump);

endmodule
