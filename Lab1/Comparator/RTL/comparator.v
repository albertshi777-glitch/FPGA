module comparator(
	input wire A,
	input wire B,
	output wire L1,
	output wire L2,
	output wire L3
);

assign L1=A|(~B);

assign L2=A^B;

assign L3=~A|B;

endmodule