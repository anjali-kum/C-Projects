/* PROBLEM: EVEN ODD MUTEX SYNC
 * PROBLEM DESCRIPTION:
 * 1.) two threads print even and odd numbers alternatively using shared memory
 * 2.) Even thread: prints even numbers when the flag is 0.
 * 3.) Odd thread: prints odd numbers when the flag is 1.
 */
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#define MAX 10
int flag = 0;	//flag to switch between even and odd threads
pthread_mutex_t m1; // mutex to nsure mutual exclusion
//function for the even number printing thread
void *even_thread(void *arg){
	int *shm = (int*)arg; //pointer to shared memory
	while(*shm < MAX){
		pthread_mutex_lock(&m1); //lock the mutex
		if(flag == 0 && (*shm) % 2 == 0){ // check if it the even thread's turn
		printf("even %d\n",*shm);
		(*shm)++; //increment the shared value

		flag = 1;	//switch the flag to odd
		}
		pthread_mutex_unlock(&m1);	//unlock the mutex
		usleep(100);	//small delay to preven busy waiting
	}
	return NULL;
}
//Function for the odd number printing thread
void *odd_thread(void *arg)
{
	int *shm = (int*)arg; //pointing to shared memory
	while(*shm <MAX)
	{
		pthread_mutex_lock(&m1);
		if(flag == 1 && (*shm) % 2 != 0)
		{	//check if the number's turn
		printf("odd:%d\n",*shm);
		(*shm)++;
		flag =0;	//switch the flag to even
		}
		pthread_mutex_unlock(&m1);
		usleep(100);
		}
		return NULL;
	}
int main(){
	int shmid;
	int *shm;
	//create shared memory to store an integer
	shmid = shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT | 0666);
	if(shmid == -1){
		perror("Shmget failed");
		return 1;
	}
	//Attach shared memory to the process
	shm = (int*)shmat(shmid,NULL,0);
	if(shm == (void*)-1){
		perror("shmat failed");
		return 1;
	}
	*shm = 0;	//Initialize memory value to 0
	pthread_t p1,p2;
	//create the even number pointing thread
	pthread_create(&p1,NULL,even_thread,(void*)shm);
	//create the odd number printing thread
	pthread_create(&p2,NULL,odd_thread,(void*)shm);
	//wait for both threads to finish
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_mutex_destroy(&m1); //Destroy the mutex 
	shmdt(shm);		//Detach shared memory
	shmctl(shmid,IPC_RMID,NULL);//Remove shared memory segment
	return 0;
}

