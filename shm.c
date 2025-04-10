#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int shmid = shmget(IPC_PRIVATE,1024,0666 | IPC_CREAT);
	char *str = (char*)shmat(shmid,NULL,0);
	if(fork() == 0){
		sprintf(str,"Hello from shared memory");
		shmdt(str);
	}
	else{
		wait(NULL);
		printf("Data read from shared Memory:%s\n",str);
		shmdt(str);
		shmctl(shmid,IPC_RMID,NULL);
	}
	return 0;
}


