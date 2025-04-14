//src/main.c
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "parser.h"
#include "executor.h"

#define MAX_INPUT 1024

int main(){
	char input[MAX_INPUT];
	char *args[64];
	while(1){
		printf("myshell> ");
		fflush(stdout);
		if(!fgets(input,MAX_INPUT,stdin)) break;
		parse_input(input,args);
		if(args[0] == NULL) continue;

		if(strcmp(args[0],"exit") == 0){
			int status = (args[1] != NULL) ? atoi(args[1]) : 0;
			exit(status);
		}else if(strcmp(args[0], "cd")==0){
			const char *path = args[1] ? args[1] : getenv("Home");
			if(chdir(path) != 0){
				perror("cd failed");
			}
			continue;
}
execute_command(args);
}

return 0;
}

