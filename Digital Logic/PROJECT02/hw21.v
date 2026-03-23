module Simple_Circuit (A, B, C, D, F);
   output F;
   input A, B, C, D;
   wire w1,w2,w3,w4;

   nand #10 G1(w1, C, D);
   nand #10 G2(w2, w1, ~B);
   nand #10 G3(w3, w2, A);
   nand #10 G4(w4, B, ~C);
   nand #10 G5(F, w3, w4);

endmodule

module t_Simple_Circuit;

   wire f;
   reg a, b, c, d;

   Simple_Circuit M1 (a, b, c, d, f);
   initial
   begin
	   a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0;
	   #100 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1;
	   #100 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b0;
	   #100 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0;
	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1;
	   #100 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0;
       	   #100 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0;
           #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1;
		
   end
   initial #1600 $finish;

   initial $dumpvars;
endmodule