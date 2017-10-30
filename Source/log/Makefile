SOURCE = log.c
SOURCE_O = log.o
CFLAGS = -Wall -pedantic -std=c11
LOG_FILE = "log.txt"
LOG_OPTIONS = -D LOG -D LOG_FILE='${LOG_FILE}'


${SOURCE_O}: ${SOURCE}
	# NOTE: "make silent" to compile with log off
	gcc ${CFLAGS} ${LOG_OPTIONS} -c ${SOURCE}

silent: ${SOURCE}
	gcc ${CFLAGS} -c ${SOURCE}

clean: 
	rm -rf *.o *.out ${LOG_FILE} test test.o