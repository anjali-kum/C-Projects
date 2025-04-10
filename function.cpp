#include<iostream>
using namespace std;
int add(int a, int b);//function declearation
int add(int a, int b)//function defination
{
	int sum= a+b;
	return sum;
}
int main(){
	int a,b;
	cout<<"Enter a and b:";
	cin>>a>>b;
	cout<<"sum of a and b is: "<<add(a,b)<<endl;
	return 0;
}

