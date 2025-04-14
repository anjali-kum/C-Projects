/***************Use fork() to create child, exec() to replace it with another process*************************/

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		//child process
	execlp("ls", "ls","-l",NULL);
	perror("exec failed");
	}
	else{
		//Parent waits
	wait(NULL);
	printf("Child process finished\n");
	}
	return 0;
}


