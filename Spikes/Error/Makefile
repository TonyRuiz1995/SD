TEST_SOURCE = abs-prec.c
TEST_PROGRAM = testS
CFLAGS = -Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM}

${TEST_PROGRAM}: ${TEST_SOURCE}
	gcc -o ${TEST_PROGRAM} ${TEST_SOURCE} -lcunit

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM}
