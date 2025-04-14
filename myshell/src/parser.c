//src/parser.c
#include<string.h>
#include<stdlib.h>
#include "parser.h"

void parse_input(char *input, char **args){
	for(int i=0;i<64;i++){
		args[i] = strsep(&input, " \t\n");
		if(!args[i]) break;
		if(strlen(args[i]) == 0) 
			i--;//skip empty
			    }
}

