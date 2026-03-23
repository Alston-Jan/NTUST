module Simple_Circuit (A, B, C, D, E, F);
   output F;
   input A, B, C, D, E;
   wire w1,w2,w3,w4;

   nand #20 G1(w1, A, B);
   nand #20 G2(w2, C, D);
   not #20 G3(w3, E);
   and #20 G4(F, w1, w2, w3);

endmodule

module t_Simple_Circuit;

   wire f;
   reg a, b, c, d, e;

   Simple_Circuit M1 (a, b, c, d, e, f);
   initial
   begin
	   a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0; e = 1'b0;
	   #100 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0; e = 1'b1;
	   #100 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1; e = 1'b0;
	   #100 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1; e = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b0;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b1;
	   #100 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1; e = 1'b0;
	   #100 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1; e = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0; e = 1'b0;
       	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0; e = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1; e = 1'b0;
	   #100 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1; e = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b0;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b1;
	   #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1; e = 1'b0;
           #100 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1; e = 1'b1;
           #100 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0; e = 1'b0;
           
	   #100 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0; e = 1'b1;
	   #100 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1; e = 1'b0;
	   #100 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1; e = 1'b1;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0; e = 1'b0;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0; e = 1'b1;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1; e = 1'b0;
	   #100 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1; e = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0; e = 1'b0;
       	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0; e = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1; e = 1'b0;
	   #100 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1; e = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b0;
	   #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0; e = 1'b1;
	   #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1; e = 1'b0;
           #100 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1; e = 1'b1;
 
		
   end
   initial #400 $finish;

   initial $dumpvars;
endmodule