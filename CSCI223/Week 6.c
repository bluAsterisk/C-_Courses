//
//  Week 6.c
//  CSCI 223
//
//  Created by ケビン・ファン on 3/8/16.
//
//

#include <stdio.h>

// Shell Scripts
// _____________
// * A shell script is a text file that contains a set of commands to execute.
// ex:
// build.sh
#!/bin/bash // <-- "hash-bang", bash is "born again shell"
// gcc -c main.c
// gcc -c disphex.c
// gcc -c dispoct.c
// gcc main.o disphex.o dispoct.o
// To run: ./build.sh
// But first, you must change the "permission bits"; to do that, use the "chmod" command (change mode).
// ex:
// ls -l build.sh (gives you a long list of build.sh)
// (first bit will be d if its a directory)
// -rw-r--r--r 1 sedwards users 186 May 8 2016 build.sh
// ^^^ permission bits
// r = read, w = write, x = excecute
//  r   w   x | r   w   x | r   w   x
//|___________|___________|___________
//| 1 | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 1 |
//   owner   group    other
// since these are in 3 bits, they are octal values
// ex: chmod 751 build.sh
// gcc *.c (the * is a wildcard)
// * matches any set of chars
// ? match a single char
// if you use gcc *.c it will compile all the .c files in the directory


// The "make" Utility
// __________________
// * used to manage multi-module projects.
// * Write a "makefile" that defines file dependencies and commands.
// Syntax for a target:
// <target>:   <dependency list>
//             <commands block>
// * To run make: make
// * Can specify a target on the command line:
//      make dispoct.o
// * To split dependency list across lines, use the line continuation character: \
// * To create comments, precede a line with '#'
// ex:
// makefile (this is the default name for a makefile)
// SEMESTER = Spring 2016 // these are
// VERSION = 03           // user defined macros
//
// (must use tabs between the target and dependency list)
// a.out:       main.o disphex.o dispoct.o \ <-- this can be used as a line continuation for files
//              gcc main.o disphex.o dispoct.o
// (this blank line is needed to separate the command blocks)
// main.o:      main.c disphex.h dispoct.h
//
// disphex.o:   disphec.c disphex.h
//              gcc -c disphex.c
//
// dispoct.o:   dispoct.c dispoct.h
//              gcc -c dispoct.c
//
// clean :      (target with no dependencies)
//              rm -f *.o a.out
//
// save :
//              tar cvzf DispInts_$(SEMESTER)_v$(VERSION).tar.gz (must explicitly expand user macros)
//              main.c disphex.c \
//              makefile

// since a.out isn't created yet, the dependency list and run the command block for the target that is read in the dependecy list.
// all the makefile does is check the files' time stamps and updates the files to be compiled.

// The following command is like using a zip file in windows
// tar cvzf foo.tar.gz foo.c foo.h
// tar = tape archive
// x = extract, can be used instead of c
// c = create
// v = verboes
// z = gzip compression
// f = filename