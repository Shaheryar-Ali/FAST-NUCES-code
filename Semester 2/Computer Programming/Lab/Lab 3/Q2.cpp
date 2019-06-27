#include <iostream>
#include<string.h>
using namespace std;
bool isPalindrome(char *a);

 void main()
 {
	 char sent [50];
	 bool x;
	 cout<<"Enter string";
	 cin>>sent;
	 x = isPalindrome( &sent[0]);
	 if (x)
	 {
		 cout<<"True";
	 }
	 else
	 {
		 cout<<"false";
	 }
 }

 bool isPalindrome(char *a)
 {
	 int q = strlen(a) - 1;
	 int w = 0;
	 bool test = true;
	 while (q != w && w < q)
	 {
		 if (a[w] != a[q])
		 {
			 test = false;
			 break;
		 }
		 q--;
		 w++;
	 }

	 
	 return test;
 }