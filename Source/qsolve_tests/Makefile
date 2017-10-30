SOURCE = qsolve.c
SOURCE_O = qsolve.o
TEST_SOURCE = test.c
TEST_SOURCE_O = test.o
TEST_PROGRAM = test
CFLAGS = -Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM}

${TEST_PROGRAM}: ${SOURCE_O} ${TEST_SOURCE_O}
	gcc -o ${TEST_PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O} -lcunit -lm

${SOURCE_O}: ${SOURCE}
	gcc ${CFLAGS} -c ${SOURCE}

${TEST_SOURCE_O}: ${TEST_SOURCE}
	gcc ${CFLAGS} -c ${TEST_SOURCE}	

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM}
