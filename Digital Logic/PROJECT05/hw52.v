module edge_triggered_D_flip_flop(input D, CLK, output Q, Qbar);
wire wA, wB, wD, S, R;
    nand g1(wA, S, wD);
    nand g2(S, wA, CLK);
    nand g3(R, S, CLK, wD);
    nand g4(wD, R, D);
    nand g5(Q, S, Qbar);
    nand g6(Qbar, Q, R);
endmodule

module edge_triggered_D_flip_flop_testbench;
reg D, CLK;
edge_triggered_D_flip_flop m1(D, CLK, Q, Qbar);
initial begin
   	D = 0; 
CLK=0;
	#10 D = 1;
	#10 D = 0;
        #10 D = 1;
   end
always #5 CLK = ~CLK;
initial #100 $finish;
initial $dumpvars;
endmodule