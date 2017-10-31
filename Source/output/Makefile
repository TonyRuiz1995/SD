SOURCE =output.c
SOURCE_O =output.o
TEST_SOURCE =test.c
TEST_SOURCE_O =test.o
TEST_PROGRAM =test
LOG_FILE=../log
LOG_SOURCE_O =${LOG_FILE}/log.o
QSOLVE_FILE=../qsolve
QSOLVE_SOURCE_O =${QSOLVE_FILE}/qsolve.o
CFLAGS =-Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM}

${TEST_PROGRAM}: ${SOURCE_O} ${TEST_SOURCE_O}
	gcc -o ${TEST_PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O} ${QSOLVE_SOURCE_O} ${LOG_SOURCE_O} -lcunit -lm

${SOURCE_O}: ${SOURCE}
	cd ${LOG_FILE}; make
	gcc ${CFLAGS} -c ${SOURCE}

${TEST_SOURCE_O}: ${TEST_SOURCE}
	cd ./${QSOLVE_FILE}; make
	gcc ${CFLAGS} -c ${TEST_SOURCE}	

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM} log.txt
