#include <iostream>
#include <string>

using namespace std;
void sort(string*& lis, int size);


void main()
{
	int nam;
	string *list;
	cout<<"How many names you want to enter?";
	cin>>nam;
	list = new string [nam];
	for(int i = 0; i < nam; i++)
	{
		cin>>list[i];
	}

	sort(list,nam);

	for(int i = 0; i < nam; i++)
	{
		cout<<endl<<list[i];
	}
}

void sort(string*& lis, int size)
{
	string temp;
	int flag = 1;
	for(int i = 0; i < size && flag; i++)
	{
		flag = 0;
		for(int j = 0;j < (size -1); j++)
		{
			if(lis[j]>lis[j+1])
			{
				temp = lis[j];
				lis[j] = lis[j+1];
				lis[j+1] = temp;
				flag = 1;
			}
		}
	}
}