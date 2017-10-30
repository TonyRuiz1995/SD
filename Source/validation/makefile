PS: validate.c
	gcc validate.c -o validate -g -lm -Wall 
	
SOURCE = validate.c
PROGRAM = validate
CFLAGS = -g -lm -Wall -pedantic


main: ${SOURCE}
	gcc ${SOURCE} -o ${PROGRAM} ${CFLAGS}
	
run: ${PROGRAM}
	./${PROGRAM} ${INPUT} > ../output.txt

open:
	#open -a Sublime\ Text program.c makefile
	open ${SOURCE} makefile README.md

clean: 
	rm -rf *.o *.out ${PROGRAM}

clear:
	clear
	clear

help:
	#commands main, run, open, clean, clear, help
#files program.c makefile README.md
