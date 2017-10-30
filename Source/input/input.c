
#include<stdio.h>
#include<string.h>
int main(int argc, char **argv){
	
	char buff[1000] = {};
	for(int i = 1; i < argc; i++){
		strcat(buff, argv[i]);
		strcat(buff, " ");
	}
	printf("%s\n",buff);
	
	
}
