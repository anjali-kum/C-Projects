#include<pthread.h>
#include<stdio.h>
int counter =0;
pthread_mutex_t lock;
void *increment(void *arg){
	pthread_mutex_lock(&lock);//lock the mutex
	counter++;
	printf("Counter: %d\n",counter);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&thread1,NULL,increment,NULL);
	pthread_create(&thread2,NULL,increment,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}

