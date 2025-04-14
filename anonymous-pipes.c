/*************Implementing a job queue between a producer and consumer********/

#include<unistd.h>
#include<stdio.h>

int main(){
	int fd[2];
	pipe(fd);

	if(fork() == 0){
		close(fd[1]);//close write
		char buffer[100];
		read(fd[0],buffer,sizeof(buffer));
		printf("Child got: %s\n",buffer);
	}
	else{
		close(fd[0]);//close read
		write(fd[1],"Hello from parent",18);
	}
	return 0;
}

