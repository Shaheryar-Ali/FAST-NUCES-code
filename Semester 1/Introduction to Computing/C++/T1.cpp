#include<iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	int pre_space_a, space_a,star_a, height_a;			//Prespace is space before triangle, space is space in triangle
	int length, width;

	if(argc!= 3)
		cout << "Inaccurate parameters\n";
	else if(atoi(argv[1])%2 == 0 || atoi(argv[2])%2 == 0)
		cout << "Both length and width should be odd\n";
	else
	{
	
		pre_space_a = (atoi(argv[1])+1)/2;		//argv1 is length
		height_a = (atoi(argv[2])+1)/2;			//argv2 is width
		space_a = atoi(argv[2])/2;
		star_a = 1;

		length = atoi(argv[1]);
		width = atoi(argv[2]);

		for(int a=1; a<= height_a; a++)
		{
			for(int a2= 0; a2 < pre_space_a; a2++)
				cout << " ";
			cout << "  ";
			for(int a3= 0; a3 < space_a; a3++)
				cout << " ";
			for(int a4 = 0; a4 < star_a;a4++)
				cout << "*";
			cout << endl;
			space_a--;
			star_a+=2;
		}
		cout << endl;

		int pre_space_b, star_b1, star_b2;
		pre_space_b = length/2;
		star_b1 = 1;
		star_b2 = width;

		for(int b_top = 1; b_top <= (length+1)/2; b_top++)
		{
			for(int b1 = 0; b1 < pre_space_b; b1++)
				cout << " ";
			for(int b2 = 0; b2 < star_b1; b2++)
				cout << "*";
			cout << "  ";
			for(int b3 = 0; b3 < star_b2; b3++)
				cout << "*";
			cout << "  ";
			for(int b2 = 0; b2 < star_b1; b2++)
				cout << "*";		
			cout<< endl;
			star_b1++;
			pre_space_b--;	
		}  		 

		pre_space_b = 1;
		star_b1 = length/2;

		for(int b_bot = 1; b_bot <= length/2; b_bot++)
		{
			for(int b1 = 0; b1 < pre_space_b; b1++)
				cout << " ";
			for(int b2 = 0; b2 < star_b1; b2++)
				cout << "*";
			cout << "  ";
			for(int b3 = 0; b3 < star_b2; b3++)
				cout << "*";
			cout << "  ";
			for(int b2 = 0; b2 < star_b1; b2++)
				cout << "*";		
			cout<< endl;
			star_b1--;
			pre_space_b++;	
		}  	

		cout << endl;
		int star_d, space_d;
		star_d = width;
		space_d = 0;
		

		for(int d=1; d<= height_a; d++)
		{
			for(int d2= 0; d2 < pre_space_a; d2++)
				cout << " ";
			cout << "  ";
			for(int a4 = 0; a4 < space_d;a4++)
				cout << " ";
			for(int a3= 0; a3 < star_d; a3++)
				cout << "*";

			cout << endl;
			space_d++;
			star_d -= 2;
		}

			 
		
	}
		
	cout << endl;
	return 0;

}
