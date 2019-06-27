#include <iostream>
#include <fstream>
#include <string>

using namespace  std;

int main(int argc, char *arg[])
{
ifstream myf;
string n;
myf.open(arg[1]);
myf >> n;

cout << n;

return 0;

}