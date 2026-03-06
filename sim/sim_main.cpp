#include "Vbp_trace_encoder.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate your SystemVerilog module!
    Vbp_trace_encoder* dut = new Vbp_trace_encoder;

    // 1. Initialize System
    dut->clk_i = 0;
    dut->reset_i = 1;
    dut->commit_v_i = 0;
    dut->commit_pc_i = 0;
    dut->commit_instr_i = 0;
    dut->eval();

    // Toggle clock a few times to apply reset
    for(int i=0; i<4; i++) {
        dut->clk_i = !dut->clk_i;
        dut->eval();
    }
    dut->reset_i = 0; // Turn off reset

    std::cout << "\n--- TEST 1: Linear Instruction (Should be IGNORED) ---" << std::endl;
    dut->clk_i = 1;
    dut->commit_v_i = 1;
    dut->commit_pc_i = 0x1000;
    dut->commit_instr_i = 0x00000033; // ADD opcode
    dut->eval(); // Evaluate the hardware logic
    std::cout << "PC: 0x" << std::hex << dut->commit_pc_i 
              << " | Trace Valid: " << (int)dut->trace_valid_o << std::endl;
    
    dut->clk_i = 0; dut->eval(); // Clock down

    std::cout << "\n--- TEST 2: Non-Linear Instruction (Should TRIGGER Trace) ---" << std::endl;
    dut->clk_i = 1;
    dut->commit_v_i = 1;
    dut->commit_pc_i = 0x1004;
    dut->commit_instr_i = 0x00000063; // BRANCH opcode
    dut->eval(); // Evaluate the hardware logic
    
    std::cout << "PC: 0x" << std::hex << dut->commit_pc_i 
              << " | Trace Valid: " << (int)dut->trace_valid_o 
              << " | Trace Packet: 0x" << std::hex << dut->trace_packet_o << std::endl;
    
    dut->clk_i = 0; dut->eval(); // Clock down

    std::cout << "\nSimulation Complete!\n" << std::endl;

    delete dut;
    return 0;
}
