#include<stdio.h>
#include<unistd.h>
int main(){
	int fd[2];
	pipe(fd); //create a pipe
	if(fork() == 0){
		close(fd[0]);//close unused read end
		write(fd[1],"Hello from child",17);
		close(fd[1]);
	}
	else{
		char buffer[20];
		close(fd[1]); //close unused write end
		read(fd[0],buffer,17);
		close(fd[0]);
	}
	return 0;
} 
//fd[0] --> reading
//fd[1] --> writing

/*
 * pipe(fd) --> create a pipe
 * fork() --> create a new process.The child process write to pipe, and the parent process reads from it.
 *
 */
