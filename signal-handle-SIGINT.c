/******Gracefully sutdown a long-running server instead of crashing it.***/

#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void sig_handler(int signum){
	printf("Caught signal %d, exiting gracefully...\n",signum);
	_exit(0);
}
int main(){
	signal(SIGINT,sig_handler);//ctrl+c
	while(1){
		printf("Running...Press Ctrl+c to stop\n");
		sleep(1);
	}
}

