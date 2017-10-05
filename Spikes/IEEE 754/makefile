SOURCE = program.c
PROGRAM = program
#CFLAGS = -Wall - pedantic -stde=
#CFLAGS = -Wall -d

main: ${SOURCE}
	gcc ${SOURCE} -o ${PROGRAM}
	#gcc ${FILENAME} -c 
	#gcc ${FILENAME} ${CFLAGS} -o ${PROGRAM}

run: ${PROGRAM}
	./${PROGRAM}

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