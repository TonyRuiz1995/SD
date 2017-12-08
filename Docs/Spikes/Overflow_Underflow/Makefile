SOURCE = under_over.c
SOURCE_O = under_over.o
PROGRAM = under_over
CFLAGS = -Wall -pedantic -std=c11

run: ${PROGRAM}
	./${PROGRAM}

${PROGRAM}: ${SOURCE_O}
	gcc -o ${PROGRAM} ${SOURCE_O} -lm

${SOURCE_O}: ${SOURCE}
	gcc ${CFLAGS} -c ${SOURCE}

clean: 
	rm -rf *.o *.out ${PROGRAM}
