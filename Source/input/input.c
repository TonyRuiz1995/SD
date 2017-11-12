#include "input.h"

void input(char buff[])
{
	char params[3300];
	sprintf(params, "buff='%s'", buff);
	myLog("input.c", "input", params);

	scanf("%2999[^\n]", buff);
}
