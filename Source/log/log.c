// This file contains basic functionality
#include "log.h"

// Starts the log
	// Notes which function called it and from where
	// runName: name of program running it
	// file: source code of program running it
void log_start(char* run_name, char* file)
{
	#ifdef LOG
	FILE* log_file;
	log_file = fopen(LOG_FILE, "w+");
	fprintf(log_file, "%s %s\n", run_name, file);
	fflush(log_file);
	fclose(log_file);
	#endif
}

// Logs function call
	// file: source code file
	// method: function that's invoking log
	// parameters: parameters to note
void my_log(char* file, char* method, char* parameters)
{
	#ifdef LOG
	FILE* log_file;
	log_file = fopen(LOG_FILE, "a+");
	fprintf(log_file, "%s %s %s\n", file, method, parameters);
	fflush(log_file);
	fclose(log_file);
	#endif
}

// Logs errors
	// file: source code file
	// method: function that's invoking log
	// parameters: parameters to note
	// error: error notes
void log_err(char* file, char* method, char* parameters, char* error)
{
	#ifdef LOG
	FILE* log_file;
	log_file = fopen(LOG_FILE, "a+");
	fprintf(log_file, "%s %s %s ERRR=%s\n", file, method, parameters, error);
	fclose(log_file);
	#endif
}
