// Reads input from the command line
#include "input.h"

// Reads input from the command line onto a buffer
	// buff: (out) buffer to read command line into
void input(char buff[])
{
	char params[3300];
	sprintf(params, "buff='%s'", buff);
	my_log("input.c", "input", params);

	scanf("%2999[^\n]", buff);
}
