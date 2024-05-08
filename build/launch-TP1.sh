#!/bin/sh
bindir=$(pwd)
cd /mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1 
	else
		"/mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1"  
	fi
else
	"/mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1"  
fi
