#!/bin/sh
bindir=$(pwd)
cd /home/e20210001937/Documents/Master1/M1/S2/Moteur de jeux/TP5/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/e20210001937/Documents/Master1/M1/S2/Moteur\ de\ jeux/TP5/build/TP1 
	else
		"/home/e20210001937/Documents/Master1/M1/S2/Moteur\ de\ jeux/TP5/build/TP1"  
	fi
else
	"/home/e20210001937/Documents/Master1/M1/S2/Moteur\ de\ jeux/TP5/build/TP1"  
fi
