#include "log.h"

void log_start(char* runName, char* file)
{
	#ifdef LOG
	FILE* logFile;
	logFile = fopen(LOG_FILE, "w+");
	fprintf(logFile, "%s %s\n", runName, file);
	fflush(logFile);
	fclose(logFile);
	#endif
}

void myLog(char* file, char* method, char* parameters)
{
	#ifdef LOG
	FILE* logFile;
	logFile = fopen(LOG_FILE, "a+");
	fprintf(logFile, "%s %s %s\n", file, method, parameters);
	fflush(logFile);
	fclose(logFile);
	#endif
}

void log_err(char* file, char* method, char* parameters, char* error)
{
	#ifdef LOG
	FILE* logFile;
	logFile = fopen(LOG_FILE, "a+");
	fprintf(logFile, "%s %s %s ERRR=%s\n", file, method, parameters, error);
	fclose(logFile);
	#endif
}
