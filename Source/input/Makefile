SOURCE = input.c
#PROGRAM = input
TEST_SOURCE = ${SOURCE} test.c
TEST_PROGRAM = test
CFLAGS = -Wall

main: ${TEST_SOURCE} 
	#gcc ${SOURCE} -c 
	#gcc ${SOURCE} ${CFLAGS} -o ${PROGRAM}

	#gcc ${TEST_SOURCE} -c 
	gcc ${TEST_SOURCE} ${CFLAGS} -o ${TEST_PROGRAM}

#run: ${PROGRAM}
#	./${PROGRAM}

run:
	./${TEST_PROGRAM} < in.txt

clean: 
	rm -rf *.o *.out ${PROGRAM} ${TEST_PROGRAM}

clear:
	clear
	clear