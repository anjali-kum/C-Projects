#include<iostream>
using namespace std;
int main(){
	int arr[]={10,20,20,40,60};
	int n;
	cin>>n;
	cout<<"Number is:"<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i] ;
	}
	return 0;

}
/*
 * The c++ language does not define any statements to do input or output(IO).
 * instead, C++ includes an extensive standard library that provides IO (and many other facilities).
 * For the purpose of input & Output we will make use of the iostream library.
 * IOSTREAM(input Output Stream).
 * cin-->standard input
 * cout-->standard output
 * cerr-->standard error
 * clog-->general information
 */


