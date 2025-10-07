transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/FPGA/Avoid_latch/Avoid_latch_self1/RTL {D:/FPGA/Avoid_latch/Avoid_latch_self1/RTL/Avoid_latch_self1.v}

vlog -vlog01compat -work work +incdir+D:/FPGA/Avoid_latch/Avoid_latch_self1/Quartus_prj/../Sim {D:/FPGA/Avoid_latch/Avoid_latch_self1/Quartus_prj/../Sim/tb_Avoid_latch_self1.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_Avoid_latch_self1

add wave *
view structure
view signals
run 1 ns
