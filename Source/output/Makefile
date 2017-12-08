SOURCE =output.c
SOURCE_O =output.o
TEST_SOURCE =test.c
TEST_SOURCE_O =test.o
TEST_PROGRAM =test
OTHER_SOURCE_O=../qsolve/qsolve.o ../validation/validate.o
CFLAGS =-Wall -pedantic -std=c11

run_test: ${TEST_PROGRAM}
	./${TEST_PROGRAM}

${TEST_PROGRAM}: ${SOURCE_O} ${TEST_SOURCE_O}
	gcc -o ${TEST_PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O} ${OTHER_SOURCE_O} ../log/log.o -lcunit -lm

${SOURCE_O}: ${SOURCE}
	cd ../log; make
	gcc ${CFLAGS} -c ${SOURCE}

${TEST_SOURCE_O}: ${TEST_SOURCE}
	cd ../log; make
	cd ../qsolve; make
	cd ../validation; make
	gcc ${CFLAGS} -c ${TEST_SOURCE}

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM} log.txt
