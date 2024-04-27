#!/bin/sh
bindir=$(pwd)
cd /home/mat/Documents/M1/Moteur/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/mat/Documents/M1/Moteur/Projet_Moteur/build/TP1 
	else
		"/home/mat/Documents/M1/Moteur/Projet_Moteur/build/TP1"  
	fi
else
	"/home/mat/Documents/M1/Moteur/Projet_Moteur/build/TP1"  
fi
