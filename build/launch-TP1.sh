#!/bin/sh
bindir=$(pwd)
cd /home/narraxas/Documents/Master1/M1/S2/Moteur de jeux/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/narraxas/Documents/Master1/M1/S2/Moteur\ de\ jeux/Projet_Moteur/build/TP1 
	else
		"/home/narraxas/Documents/Master1/M1/S2/Moteur\ de\ jeux/Projet_Moteur/build/TP1"  
	fi
else
	"/home/narraxas/Documents/Master1/M1/S2/Moteur\ de\ jeux/Projet_Moteur/build/TP1"  
fi
