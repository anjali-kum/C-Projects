/*
You are simulating a bank account system where multiple threads are transferring money into or out of an account. However, if two threads are trying to update the account balance at the same time, it may lead to a race condition, resulting in an incorrect final balance.

Write a program where two threads repeatedly deposit and withdraw money from the same account. You need to use a **mutex** to prevent the race condition from corrupting the balance.
 */
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;
int balance = 1000;

// Function to simulate deposit
void* deposit(void *arg){
	for(int i=0;i<1000;i++){
		pthread_mutex_lock(&mutex);//LOCKING THE CRITICAL SECTION
		balance += 10; //Deposit $10
		pthread_mutex_unlock(&mutex); //UNLOCKING THE CRITICAL SECTION 
		}
	pthread_exit(NULL);
}
//Function to simulate withdrawal
void *withdraw(void * arg){
	for(int i =0;i<1000;i++){
		pthread_mutex_lock(&mutex); //LOCKING THE CRITICAL SECTION
		balance -= 10; //withdraw $10
		pthread_mutex_unlock(&mutex); //UNLOCKING THE CRITICAL SECTION
			}
	pthread_exit(NULL);
}
int main(){
	pthread_t threads[2];
	pthread_mutex_init(&mutex,NULL); //Initialize mutex
	pthread_create(&threads[0], NULL, deposit,NULL);//Create deposit thread
	pthread_create(&threads[1],NULL, withdraw,NULL);//Create withdraw thread
	//wait for threads to finish
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);

	printf("Final Balance: $%d\n",balance);
	pthread_mutex_destroy(&mutex);//Destroy mutex
	return 0;
}


