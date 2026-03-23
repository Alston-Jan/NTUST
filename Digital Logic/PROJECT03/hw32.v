module carry_look_ahead_16_bit(input[15:0] a, b, input cin, output [15:0] sum, output cout);
	wire c1,c2,c3;
	carry_look_ahead_4_bit cla1(a[3:0], b[3:0], cin, sum[3:0], c1);
	carry_look_ahead_4_bit cla2(a[7:4], b[7:4], c1, sum[7:4], c2);
	carry_look_ahead_4_bit cla3(a[11:8], b[11:8], c2, sum[11:8], c3);
	carry_look_ahead_4_bit cla4(a[15:12], b[15:12], c3, sum[15:12], cout);
endmodule

module carry_look_ahead_4_bit(a, b, cin, sum, cout);
	input[3:0] a, b;
	input cin;
	output[3:0] sum;
	output cout;
	wire [3:0] P, G, C;
	assign #10 P = a ^ b;
	assign #10 G = a & b;
	assign #10 C[0]= cin;
	assign #10 C[1]= G[0] | (P[0] & C[0]);
	assign #10 C[2]= G[1] | (P[1] & G[0]) | P[1] & P[0] & C[0];
	assign #10 C[3]= G[2] | (P[2] & G[1]) | P[2] & P[1] & G[0] | P[2] & P[1] & P[0] & C[0];
	assign #10 cout= G[3] | (P[3] & G[2]) | P[3] & P[2] & G[1] | P[3] & P[2] & P[1] & G[0] | P[3] & P[2] & P[1] & P[0] & C[0];
	assign #10 sum = P ^ C;
endmodule

module testbench_carry_look_ahead_16_bit;
	reg [15:0] a,b;
	reg cin;
	wire [15:0] sum;
	wire cout;
	carry_look_ahead_16_bit cla16bit(a, b,cin,sum,cout);
	initial 
        begin
	a=0; b=0; cin=0;
	#100 a= 16'b0000000111110000; b=16'b000101100001100; cin=1'b0;
	#100 a= 16'b1100011010000101; b=16'b000000010000001; cin=1'b1;
	#100 a= 16'b0000001111110000; b=16'b011100000000000; cin=1'b0;
	#100 a= 16'b0000000000010000; b=16'b000010000000001; cin=1'b1;
	end
initial #500 $finish;
initial $dumpvars;
endmodule
