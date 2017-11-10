#include "input.h"

void input(char buff[])
{
	char params[3300];
	sprintf(params, "buff='%s'", buff);
	myLog("input.c", "input", params);

	scanf("%2999[^\n]", buff);
}
/*int main(int argc, char **argv){
	
	char buff[1000] = {};
	for(int i = 1; i < argc; i++){
		strcat(buff, argv[i]);
		strcat(buff, " ");
	}
	printf("%s\n",buff);
}
*/