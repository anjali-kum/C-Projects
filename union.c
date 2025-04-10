#include<stdio.h>
#include<string.h>
#include<stdlib.h>
union node{
	int x;
	char name[9];
	float f;
};
int main(){
	union node node1;
	node1.x = 10;
	strcpy(node1.name ,"anjali");
	node1.f = 20.1;
	printf("size of integer is %d\n",sizeof(node1.x));
	printf("size of character is %d\n",sizeof(node1.name));
	printf("size of floating is %d\n",sizeof(node1.f));
	printf("sizeof of union is %d\n",sizeof(node1));
	return 0;
}


