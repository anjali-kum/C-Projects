#include<iostream>
using namespace std;
int main(){
	int ival =1024,uval=12;
	int &refVal=ival;
	cout<<"ival="<<ival<<endl<<"refval="<<refVal;
	refVal=1000;
	cout<<endl<<"New ival="<<ival<<endl<<"New refval="<<refVal;
	return 0;
}

