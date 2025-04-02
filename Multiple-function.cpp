/*
 * Sorting (Bubble Sort)
 * Searching(Binary Search)
 * Prime Number Check
 * Palindrome Check
 * Factorial Calculation(Recursion)
 * Fibonacci Series(Recursion)
 */
#include<iostream>
#include<vector>
using namespace std;

// Function to sort an array using Bubble sort
 void bubbleSort(vector<int>& arr){
	 int n = arr.size();
	 for(int i =0;i<n-1;i++){
		 for(int j=0;j<n-i-1;j++){
			 if(arr[j] > arr[j+1]){
				 swap(arr[j], arr[j+1]);
			 }
		 }
	 }
 }
//Binary Search function
int binarySearch(const vector<int>& arr,int key){
	int left =0,right = arr.size()-1;
	while(left <= right) {
		int mid = left + (right - left)/2;
		if(arr[mid] == key) return mid;
		else if (arr[mid] < key) left = mid+1;
		else right = mid-1;
	}
	return -1;
}

// Function to check if a number is prime
bool isPrime(int num){
	if(num <= 1) return false;
	for(int i=2;i*i <= num; i++){
		if(num % i == 0) return false;
	}
	return true;
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str){
	int left=0,right=str.size() -1;
	while(left < right){
		if(str[left] != str[right]) return false;
		left++,right--;
	}
	return true;
}
// Function to calculate  factorial using recursion
int factorial(int n){
	if(n == 0 || n == 1) return 1;
	return n * factorial(n -1);
}

//Function to generate Fibonacci series using recursion
int fibonacci(int n){
	if(n <= 1) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	//Sorting and Searching
	vector<int> arr = {5,2,9,1,5,6};
	bubbleSort(arr);
	cout<<"Sorted array: ";
	for(int num : arr)
		cout << num << " ";
	cout<<endl;

	int key = 5;
	int index = binarySearch(arr,key);
	if(index != -1)
		cout<< "Element "<< key <<"found at index "<< index <<endl;
	else
		cout<< "Element "<< key <<"not found\n";

	// Prime check
	int num = 29;
	cout<< num<<(isPrime(num) ?" is a prime number\n":"is not a prime number\n");
	//palindrome check
	string word = "madam";
	cout<<word<<(isPalindrome(word) ? " is a palindrome\n" : " is not a palindrome\n");
	//Fibonacci Series
	int fibTerm = 6;
	cout<< "Fibonacci sequence up to "<< fibTerm << " terms: ";
	for(int i =0;i<fibTerm;i++){
	cout<<fibonacci(i) <<" ";
	}
	cout<<endl;
	return 0;
	}

