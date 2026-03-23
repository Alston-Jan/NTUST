module D_flip_flop_AR (Q, D, Clk, rst);
  output Q;
  input D, Clk, rst;
  reg Q;
 
  always @ (posedge Clk, negedge rst)
    if (rst == 0) Q <= 1'b0;
    else Q <= D;
endmodule
//10
module t_D_flip_flops;
  wire  Q, Q_AR;
  reg   D, Clk, rst;
  D_flip_flop_AR M1 (Q_AR, D, Clk, rst);

  always #5 Clk = ~Clk;
  initial begin
    D = 0;
    rst = 1;
    Clk = 0;
    #10 D = 1;
    #30 D = 0;
    #15 rst = 1;
    #10 D = 0;
    #10 D = 1;
    #15 rst = 1;
    #30 D = 0;
    #30 D = 1;
  end

initial #100 $finish;
initial $dumpvars;
endmodule