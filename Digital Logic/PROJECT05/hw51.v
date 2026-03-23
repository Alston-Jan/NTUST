module D_latch(output Q, input D, En);
   wire wA, wB, wC;
   nand g2(wA, En, D); 
   nand g3(wB, En, ~D);  
   nand g4(Q, wC, wA); 
   nand g5(wC, Q, wB);
endmodule

module D_flip_flop(input D, CLK, output Q);
   wire L;
   D_latch d1(L, D, CLK);
   D_latch d2(Q, L, ~CLK);
endmodule
//14

module testbench_D_flip_flop;
   reg D, CLK;
D_flip_flop m1(D, CLK, Q);
   initial begin
   	D = 1; 
CLK=0;
	#3 D = 0;
	#3 D = 1;
        #3 D = 0;
   end
always #5 CLK = ~CLK;
initial #100 $finish;
initial $dumpvars;
endmodule
        