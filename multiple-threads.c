/*    2. Shared Counter with Multiple Threads (Increasing Threads).
 *    Problem: Problem:
Modify your current program where you have two threads. Now, change the number of threads to **10** or more, each of them incrementing the `shared_counter` by 1,000 times.

**Steps**:
- Create **10 threads** (or more).
- Each thread should increment the shared counter by 1000 times.
- Use a **mutex** to protect the critical section where the `shared_counter` is updated.
- Print the final value of `shared_counter` and ensure it is the correct value (`10000` if 10 threads, each incrementing 1000 times).
*/
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex;
int shared_counter = 0;

void * thread_func(void *arg){
	for(int i =0;i<1000;i++){
		pthread_mutex_lock(&mutex);
		shared_counter++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
int main(){
	pthread_t threads[10]; // 10 threads
	pthread_mutex_init(&mutex,NULL);
	for(int i=0;i<10;i++){
		pthread_create(&threads[i] ,NULL,thread_func, NULL);
	}
	for(int i=0;i<10;i++){
		pthread_join(threads[i],NULL);
	}
	printf("Final shared_counter value: %d\n",shared_counter);
	pthread_mutex_destroy(&mutex);
	return 0;
}


