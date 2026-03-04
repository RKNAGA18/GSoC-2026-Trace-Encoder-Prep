module bp_trace_encoder_tb;

  // 1. Declare signals to connect to our module
  logic         clk_i;
  logic         reset_i;
  logic         commit_v_i;
  logic [63:0]  commit_pc_i;
  logic [31:0]  commit_instr_i;
  
  logic         trace_valid_o;
  logic [79:0]  trace_packet_o;

  // 2. Instantiate your Trace Encoder (Device Under Test)
  bp_trace_encoder dut (
    .clk_i(clk_i),
    .reset_i(reset_i),
    .commit_v_i(commit_v_i),
    .commit_pc_i(commit_pc_i),
    .commit_instr_i(commit_instr_i),
    .trace_valid_o(trace_valid_o),
    .trace_packet_o(trace_packet_o)
  );

  // 3. Generate a fake Clock (toggles every 5 time units)
  always #5 clk_i = ~clk_i;

  // 4. The Simulation Sequence
  initial begin
    // Initialize system
    clk_i = 0; reset_i = 1; commit_v_i = 0; commit_pc_i = 0; commit_instr_i = 0;
    
    // Release reset after 10 units
    #10 reset_i = 0;

    // --- TEST 1: Linear Instruction (Should be IGNORED) ---
    // Simulating an R-Type 'ADD' (Opcode: 0110011 / 0x33) at PC 0x1000
    #10;
    commit_v_i = 1; 
    commit_pc_i = 64'h1000; 
    commit_instr_i = 32'h00000033; // ADD opcode
    
    #10 commit_v_i = 0; // Turn off valid signal
    // trace_valid_o should remain 0 here!

    // --- TEST 2: Non-Linear Instruction (Should TRIGGER Trace) ---
    // Simulating a B-Type 'BEQ' (Opcode: 1100011 / 0x63) at PC 0x1004
    #10;
    commit_v_i = 1; 
    commit_pc_i = 64'h1004; 
    commit_instr_i = 32'h00000063; // Branch opcode
    
    #10 commit_v_i = 0;
    // trace_valid_o should spike to 1 here, and packet should output delta!

    // End simulation
    #20 $display("Simulation Complete!");
    $finish;
  end

endmodule
