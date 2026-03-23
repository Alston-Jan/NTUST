module half_adder(output S, C, input x, y);
    xor #(20)(S, x, y);
    and #(10)(C, x, y);
endmodule

module full_adder(output sum, carry, input x, y, z);
    wire S1, C1, C2;
    half_adder ha1(S1, C1, x, y);
    half_adder ha2(sum, C2, S1, z);
    or #(15) G1(carry, C2, C1);
endmodule

module ripple_carry_4_bit_adder(output [3:0]s, output cout,  input[3:0] X, Y, input Z);
    wire C1, C2, C3;
    full_adder fa1(s[0], C1, X[0], Y[0], Z);
    full_adder fa2(s[1], C2, X[1], Y[1], C1);
    full_adder fa3(s[2], C3, X[2], Y[2], C2);
    full_adder fa4(s[3], cout, X[3], Y[3], C3);
endmodule

module ripple_carry_16_bit_adder(output[15:0]aaa, output cout, input[15:0] A, B, input cin);
   wire C1, C2, C3;
   ripple_carry_4_bit_adder rca1(aaa[3:0], C1, A[3:0], B[3:0], cin);
   ripple_carry_4_bit_adder rca2(aaa[7:4], C2, A[7:4], B[7:4], C1);
   ripple_carry_4_bit_adder rca3(aaa[11:8], C3, A[11:8], B[11:8], C2);
   ripple_carry_4_bit_adder rca4(aaa[15:12], cout, A[15:12], B[15:12], C3);
endmodule

module testbench_ripple_carry_16_bit_adder;
reg[15:0]A, B;
reg Cin;
wire[15:0]Sum;
wire Cout;
ripple_carry_16_bit_adder rca16bit(Sum, Cout, A, B, Cin);
initial begin
A = 0; B = 0; Cin = 0;
#200 A = 16'b0110100101010101; B = 16'b0101010101010101; Cin = 1'b0;
#100 A = 16'b0000001000010000; B = 16'b0000000000100010; Cin = 1'b1;
#100 A = 16'b0101000011110000; B = 16'b0000011111110000; Cin = 1'b0;
#100 A = 16'b0101000000011100; B = 16'b0000000000111111; Cin = 1'b1;
end
initial #800 $finish;
initial $dumpvars;
endmodule