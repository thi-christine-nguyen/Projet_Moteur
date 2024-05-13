#!/bin/sh
bindir=$(pwd)
cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1 
	else
		"/mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1"  
	fi
else
	"/mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1"  
fi
