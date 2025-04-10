/*Practice on c*/
//Add Two Number a and b.
/*
#include<stdio.h>
int main(){
	int a=20;
	int b=30;
	int sum = a+b;
	printf("sum of a and b is %d",sum);
	return 0;
}
*/
/*sum of Two number and b using bitwise operator
#include<stdio.h>
int main(){
int a,b,sum,carry;
printf("Enter two numbers:");
scanf("%d %d",&a,&b);
while(b){
	carry = a&b;
	a=a^b;
	b = carry << 1;
}
printf("Sum = %d\n",a);
return 0;
}
*/

//Write a Program to swap the values of two variables.
/*
#include<stdio.h>
int main(){
	int a=20,b=30;
	a=a+b;
	b=a-b;
	a=a-b;
	printf("a is %d and b is %d",a,b);
	return 0;
}
*/
/*
//Write a program to swap the values of two value using pointer
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int*b){
	*a = (*a) +(*b);
	*b = (*a) -(*b);
	*a =(*a)-(*b);
}
int main(){
	int a=20,b=30;
	printf("before swap a is %d and b is %d\n",a,b);
	swap(&a,&b);
	printf("After swap a is %d and b is %d\n",a,b);
	return 0;
}
*/
/*
//Write a program to check if the given number is even or odd.
#include<stdio.h>
#include<stdlib.h>
int main(){
	int num;
	printf("Enter the Number ");
	scanf("%d",&num);
	if( num & 1){
		printf("Number is odd %d ",num);
	}
	else{
	printf("Number is even %d ",num);
	}
return 0;
}
*/
/* find the largest number of three of them
#include<stdio.h>
int main(){
	int a = 11, b=2,c=9;
	if(a >= b && a >= c)
		printf("%d is the largest number.",a);
	else if(b >=a && b >=c)
		printf("%d is the largest number.",b);
	else("%d is the largest number.",c);
	return 0;
}
*/
/*
//write a Program to find the factorial of a given number
#include<stdio.h>
#include<stdlib.h>
	unsigned long long fact(int num){
		if(num == 0 || num == 1)
			return 1;
		return num * fact(num - 1);
	}
int main(){
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("%lld",fact(num));
	return 0;
}
*/

// Fiboncci series using recursion
#include<stdio.h>
#include<stdlib.h>
void fibonacci(int num, int first, int second, int third){
int num=0;
	while(num !=0){
		third = first+second;
		printf("%d",third);
		first = second;
		second = third;
		fibonacci(num-1,first,second,third);
	}
}
int main(){
	int num;
	printf("%d %d ",0,1);
	fibonacci(num-2,0,1,0);
			return 0;

}


