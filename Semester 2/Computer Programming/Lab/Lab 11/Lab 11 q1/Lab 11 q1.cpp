#include<iostream>
#include<string>
#include"Ship.h"
#include"CruiseShip.h"
#include"CargoShip.h"

using namespace std;

void main()
{
	string temp;
	int temp1;
	Ship **arr = new Ship *[3];
	Ship S;
	CruiseShip Cr;
	CargoShip Co;
	arr[0] = &S;				
	arr[1] = &Cr;
	arr[2] = &Co;
	
	cout << "For Ship Object \n";
	cout << "Enter Name : ";
	cin >> temp;
	arr[0]->SetName(temp);
	cout << "Enter year of build : ";
	cin >> temp;
	arr[0]->SetYear(temp);
	arr[0]->print();

	cout << "\nFor CruiseShip Object \n";
	cout << "Enter Name : ";
	cin >> temp;
	arr[1]->SetName(temp);
	cout << "Enter year of build : ";
	cin >> temp;
	arr[1]->SetYear(temp);
	cout << "Enter Capacity of Passengers : ";
	cin >> temp1;
	Cr.SetCapacity(temp1);
	arr[1]->print();

	cout << "\nFor CargoShip Object \n";
	cout << "Enter Name : ";
	cin >> temp;
	arr[2]->SetName(temp);
	cout << "Enter year of build : ";
	cin >> temp;
	arr[2]->SetYear(temp);
	cout << "Enter Capacity of Passengers : ";
	cin >> temp1;
	Co.SetCapacity(temp1);
	arr[2]->print();
}