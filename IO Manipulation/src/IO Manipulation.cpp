//============================================================================
// Name        : IO.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

istream& getpass(istream& in)
{
	cout<<"Enter password: \a";

	return in;
}
int main() {
	double n=1.37654;
	int a=10995;
	string pass;
	cout<<"Normal: "<<endl<<n<<endl;

	cout<<"Width 10: "<<endl<<setw(10)<<n<<endl;

	cout<<"Precision 3: "<<endl<<setprecision(3)<<n<<endl;

	cout.copyfmt(ios(NULL));

	cout<<"Hexadecimal: "<<endl<<hex<<a<<endl;

	cout.copyfmt(ios(NULL));

	cout<<"Fill x:"<<endl<<setfill('x')<<setw(10)<<n<<endl;

	cin>>getpass>>pass;
	cout<<"Password: "<<pass;


}
