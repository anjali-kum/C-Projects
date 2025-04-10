/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int x;
        char name[10];
	char ch;
	float f;
};
int main(){
	struct node node1;
	strcpy(node1.name,"anjali");
	node1.x = 34;
	node1.ch ='a';
	node1.f = 20.1;
printf("x is : %d size of x is :%d\n",node1.x,sizeof(node1.x));
printf("name is: %s size of name is: %d\n",node1.name,sizeof(node1.name));
printf("char is : %c size of char is: %d\n",node1.ch,sizeof(node1.ch));
printf("float is :%f size of float is :%d\n",node1.f,sizeof(node1.f));
printf("size of the structure is : %d\n",sizeof(node1));
return 0;
}

*//*******************Bit Field*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
        int x:2;
        char name[10];
        char ch:1;
        float f;
};
int main(){
        struct node node1;
        strcpy(node1.name,"anjali");
        node1.x = 34;
        node1.ch ='a';
        node1.f = 20.1;
printf("x is : %d\n",node1.x);
printf("name is: %s\n",node1.name);
printf("char is : %c\n",node1.ch);
printf("float is :%f\n",node1.f);
printf("size of the structure is : %d\n",sizeof(node1));
return 0;
}


