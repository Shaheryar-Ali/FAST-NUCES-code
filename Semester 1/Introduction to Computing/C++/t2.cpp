#include<iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int Acc_No, min, curr, old;
	char Acc_T;

	cout << "Enter Account Number: ";
	cin >> Acc_No;
	cout << "Enter Account Type ('s' for saving: 'c' for current): ";
	cin >> Acc_T;
	cout << "Enter Minimum Balance: ";
	cin >> min;
	cout << "Enter Current Balance: ";
	cin >> curr;

	old = curr;

	if(Acc_T == 's')
	{
		if(min>curr)
		{
			curr = curr - 10;
			cout << "Your balance was "<< old << " it has been deducted to " << curr;
		}
		else
		{
			curr = curr + (curr*4)/100;
			cout << "Your balance was "<< old << " it has been increased to " << curr;
		} 
		
	}

	if(Acc_T == 'c')
	{
		if(min>curr)
		{
			curr = curr - 25;
			cout << "Your balance was "<< old << " it has been deducted to " << curr;
		}
		else
		{
			if(curr>5000+min)
			{
				curr = curr + (curr*3)/100;
				cout << "Your balance was "<< old << " it has been increased to " << curr;
			}
			else
			{
				curr = curr + (curr*5)/100;
				cout << "Your balance was "<< old << " it has been increased to " << curr;
			}
		} 
		
	}


	cout << endl;
	return 0;

}
