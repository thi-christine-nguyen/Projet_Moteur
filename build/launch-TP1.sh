#!/bin/sh
bindir=$(pwd)
cd /home/e20190003297/Documents/M1/S8/HAI819I/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/e20190003297/Documents/M1/S8/HAI819I/Projet_Moteur/build/TP1 
	else
		"/home/e20190003297/Documents/M1/S8/HAI819I/Projet_Moteur/build/TP1"  
	fi
else
	"/home/e20190003297/Documents/M1/S8/HAI819I/Projet_Moteur/build/TP1"  
fi
