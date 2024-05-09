#!/bin/sh
bindir=$(pwd)
cd /mnt/c/Users/Deurveilher J.Louis/Documents/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /mnt/c/Users/Deurveilher\ J.Louis/Documents/Projet_Moteur/build/TP1 
	else
		"/mnt/c/Users/Deurveilher\ J.Louis/Documents/Projet_Moteur/build/TP1"  
	fi
else
	"/mnt/c/Users/Deurveilher\ J.Louis/Documents/Projet_Moteur/build/TP1"  
fi
