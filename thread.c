#include<pthread.h>
#include<stdio.h>
void *thread_func(void *arg){
	printf("Hello from the thread !\n");
	return NULL;
}
int main(){
	pthread_t thread;
	pthread_create(&thread,NULL,thread_func,NULL);
	pthread_join(thread,NULL);// waits for the thread to finish
	return 0;
}

