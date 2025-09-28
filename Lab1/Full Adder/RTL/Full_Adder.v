module Full_Adder(
	input wire addend,
	input wire augend,
	input wire carry1,
	output wire sum,
	output wire carry2
);

assign sum = (addend~^augend~^carry1);


assign carry2=(addend&augend)|(addend&carry1)|(augend&carry1);

endmodule