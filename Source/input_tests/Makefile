SOURCE = input.c
SOURCE_O = input.o
TEST_SOURCE = test.c
TEST_SOURCE_O = test.o
TEST_PROGRAM = test
CFLAGS = -Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM} < in.txt

${TEST_PROGRAM}: ${SOURCE_O} ${TEST_SOURCE_O}
	gcc -o ${TEST_PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O}

${SOURCE_O}: ${SOURCE}
	gcc ${CFLAGS} -c ${SOURCE}

${TEST_SOURCE_O}: ${TEST_SOURCE}
	gcc ${CFLAGS} -c ${TEST_SOURCE}	

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM}