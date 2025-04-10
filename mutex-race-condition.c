/* ***********Race Condition*******************************
 * Problem: 
 * Race Condition: A situation where the outcome of a program depends on the unpredictable timing of concurrent operations, leading to incorrect or unexpected result.
 * * Critical Section: A Code segement that accesses shared resource ( data, files etc.) that must be protected from concurrent access to prevent race conditions.
 * Mutual Exclusion: A mechanism that ensures that only one thread/process can access a critical section at any given time.
 *
 * Solution:"using Mutex"
 * Steps:
 * 1.)Declare a MUtex
 * 2.) Initialize the mutex
 * 3.) Protect the critical section
 * 4.) Destroy the mutex (when no longer needed)
 *
 */
#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 2

int shared_counter = 0; //SHARED RESOURCE
pthread_mutex_t mutex; //MUTEX FOR MUTUAL EXCLUSION
void *thread_func(void *thread_id){
	int i = *(int*)thread_id;
	for(int j=0;j<1000;j++){
		pthread_mutex_lock(&mutex);//ACQUIRE THE LOCK
		shared_counter++;//ACCESS THE SHARED RESOURCE (CRITICAL SECTION)
		pthread_mutex_unlock(&mutex);//RELEASE THE LOCK
		}
	pthread_exit(NULL);
}
int main(){
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	pthread_mutex_init(&mutex, NULL);//INITIALIZE THE MUTEX
	for(int i=0;i<NUM_THREADS;i++){
		thread_ids[i] = i;
		pthread_create(&threads[i],NULL,thread_func, (void*)&thread_ids[i]);
		for(int i=0;i<NUM_THREADS;i++){
			pthread_join(threads[i],NULL);
		}
		printf("Final value of shared_counter: %d\n",shared_counter);
		pthread_mutex_destroy(&mutex);//DESTROY THE MUTEX
		
	}
	return 0;
}
