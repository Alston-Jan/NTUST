module Simple_Circuit (A, B, C, D, F);
   output F;
   input A, B, C, D;
   wire w1,w2,w3,w4;

   nor #20 G1(w1, ~A, B);
   nor #20 G2(w2, w1, w3);
   nor #20 G3(w3, A, ~B);
   nor #20 G4(w4, C, D);
   nor #20 G5(F, w2, w4);

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
   initial #800 $finish;

   initial $dumpvars;
endmodule