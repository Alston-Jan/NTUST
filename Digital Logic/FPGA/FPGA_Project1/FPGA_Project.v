// Copyright (C) 1991-2013 Altera Corporation
// Your use of Altera Corporation's design tools, logic functions 
// and other software and tools, and its AMPP partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License 
// Subscription Agreement, Altera MegaCore Function License 
// Agreement, or other applicable license agreement, including, 
// without limitation, that your use is for the sole purpose of 
// programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the 
// applicable agreement for further details.

// PROGRAM		"Quartus II 64-Bit"
// VERSION		"Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"
// CREATED		"Thu Dec 02 13:02:57 2021"

module FPGA_Project(
	sw_0,
	sw_1,
	sw_2,
	sw_3,
	sw_4,
	sw_5,
	sw_6,
	Botton_0,
	Botton_1,
	Botton_2,
	SEG7_0_D2,
	SEG7_0_D3,
	SEG7_0_D4,
	SEG7_0_D5,
	SEG7_0_D6,
	SEG7_0_D0,
	SEG7_0_D1,
	LED0,
	LED1,
	LED2
);


input wire	sw_0;
input wire	sw_1;
input wire	sw_2;
input wire	sw_3;
input wire	sw_4;
input wire	sw_5;
input wire	sw_6;
input wire	Botton_0;
input wire	Botton_1;
input wire	Botton_2;
output wire	SEG7_0_D2;
output wire	SEG7_0_D3;
output wire	SEG7_0_D4;
output wire	SEG7_0_D5;
output wire	SEG7_0_D6;
output wire	SEG7_0_D0;
output wire	SEG7_0_D1;
output wire	LED0;
output wire	LED1;
output wire	LED2;





assign	SEG7_0_D0 =  ~sw_0;

assign	SEG7_0_D1 =  ~sw_1;

assign	SEG7_0_D3 =  ~sw_3;

assign	SEG7_0_D2 =  ~sw_2;

assign	SEG7_0_D4 =  ~sw_4;

assign	SEG7_0_D5 =  ~sw_5;

assign	SEG7_0_D6 =  ~sw_6;

assign	LED0 =  ~Botton_0;

assign	LED1 =  ~Botton_1;

assign	LED2 =  ~Botton_2;


endmodule
