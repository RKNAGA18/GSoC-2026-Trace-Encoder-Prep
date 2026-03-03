# GSoC 2026 Prep: RISC-V Trace Encoder for BlackParrot

This repository contains my preparatory RTL design and architectural research for the **FOSSi Foundation GSoC 2026** project: *RISC-V Trace Implementation into ZynqParrot*.

## Objective
The goal of this prep work is to design the interface for a hardware trace encoder (`bp_me_trace_encoder`) that tracks non-linear control flow (branches and jumps) within the BlackParrot processor backend without overwhelming system bandwidth.

## Signal Discovery & Methodology
To avoid tracing linear `PC+4` execution, the encoder must monitor the commit stage for discontinuities. Using Verilator co-simulation and GTKWave, I mapped the BlackParrot backend (`core_minimal/be`) and isolated the required signals:

1. **Trigger:** `commit_v_o` (Valid instruction retirement)
2. **Payload:** `bp_be_commit_pkt_s` (Contains the PC and instruction bits)
3. **Branch Detection:** Extracted `instr.t.btype` and `instr.t.jtype` directly from the commit packet to trigger the trace generation.

*(Screenshot of the BlackParrot Backend commit packet inside GTKWave)*
![GTKWave Commit Signals](images/gtkwave_commit.png)

## Integration Plan
The drafted SystemVerilog interface is designed to be instantiated directly alongside the commit logic (e.g., within `bp_be_top.sv`), intercepting the `commit_pkt` before routing the compressed trace data via AXI to the Zynq Processing System.
