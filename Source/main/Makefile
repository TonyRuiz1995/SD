SOURCE =main.c
SOURCE_O =main.o
PROGRAM =main
OTHER_SOURCE_O=../input/input.o ../validation/validate.o ../qsolve/qsolve.o ../output/output.o
CFLAGS =-Wall -pedantic -std=c11

${PROGRAM}: ${SOURCE_O}
	gcc -o ${PROGRAM} ${SOURCE_O} ${TEST_SOURCE_O} ${OTHER_SOURCE_O} ../log/log.o -lm
# -lcunit

silent: 
	make silent_source
	make ${PROGRAM}


run: ${PROGRAM}
	./${PROGRAM}

# Make Object Files
#With Logging Off
silent_source: 
	cd ../log; make clean; make silent;
	cd ../input; make
	cd ../validation; make
	cd ../qsolve; make
	cd ../output; make
	gcc ${CFLAGS} -c ${SOURCE}


# With Logging On
${SOURCE_O}: ${SOURCE}
	cd ../log; make clean; make
	cd ../input; make
	cd ../validation; make
	cd ../qsolve; make
	cd ../output; make
	gcc ${CFLAGS} -c ${SOURCE}


# CLEAN
clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM} log.txt

clean_all: 
	make clean
	cd ../log; make clean
	cd ../output; make clean
	cd ../qsolve; make clean
	cd ../validation; make clean
	cd ../input; make clean