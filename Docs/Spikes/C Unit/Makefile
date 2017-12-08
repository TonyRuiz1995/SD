TEST_SOURCE = test.c
TEST_PROGRAM = test
CFLAGS = -Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM}

${TEST_PROGRAM}: ${TEST_SOURCE}
	gcc -o ${TEST_PROGRAM} ${TEST_SOURCE} -lcunit

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM}