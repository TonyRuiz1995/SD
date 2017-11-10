SOURCE =main.c
SOURCE_O =main.o
PROGRAM =main
LOG_FILE=../log
LOG_SOURCE_O =${LOG_FILE}/log.o
OTHER_SOURCE_O=../input/input.o ../validation/validate.o ../qsolve/qsolve.o ../output/output.o
CFLAGS =-Wall -pedantic -std=c11

${PROGRAM}: ${SOURCE_O}
	gcc -o ${PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O} ${OTHER_SOURCE_O} ${LOG_SOURCE_O} -lcunit -lm

run: ${PROGRAM}
	./${PROGRAM}

${SOURCE_O}: ${TEST_SOURCE}
	cd ${LOG_FILE}; make
	cd ../input; make
	cd ../validation; make
	cd ../qsolve; make
	cd ../output; make
	gcc ${CFLAGS} -c ${SOURCE}

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM} log.txt

clean_all: 
	make clean
	cd ../log; make clean
	cd ../output; make clean
	cd ../qsolve; make clean
	cd ../validation; make clean
	cd ../input; make clean