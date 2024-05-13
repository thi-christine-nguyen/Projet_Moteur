#!/bin/sh
bindir=$(pwd)
<<<<<<< HEAD
cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/
=======
cd /mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/TP1/
>>>>>>> origin/mouv
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
<<<<<<< HEAD
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1 
	else
		"/mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1"  
	fi
else
	"/mnt/c/Users/snsdt/Desktop/Projet_Moteur/build/TP1"  
=======
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1 
	else
		"/mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1"  
	fi
else
	"/mnt/c/Users/matle/Documents/Info/Master/Moteur/Projet_Moteur/build/TP1"  
>>>>>>> origin/mouv
fi
