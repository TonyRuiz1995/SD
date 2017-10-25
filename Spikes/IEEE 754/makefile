SOURCE = program.c
SOURCE_O = program.o
PROGRAM = program
CFLAGS = -Wall -pedantic -std=c11

#all: ${PROGRAM} ${TEST_PROGRAM}
#${TEST_PROGRAM}: ${TEST_SOURCE}

run: ${PROGRAM}
	./${PROGRAM}

${PROGRAM}: ${SOURCE_O}
	gcc -o ${PROGRAM} ${SOURCE_O}

${SOURCE_O}: ${SOURCE}
	gcc ${CFLAGS} -c ${SOURCE}

clean: 
	rm -rf *.o *.out ${PROGRAM}