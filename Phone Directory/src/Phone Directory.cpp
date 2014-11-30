//============================================================================
// Name        : Phone.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class dir;
istream& operator >> (istream& in, dir& d);
ostream& operator << (ostream& out, dir d);
class dir
{
	int area_code;
	int prefix;
	int number;
	char name[20];
public:
	friend istream& operator >> (istream& in, dir& d);
	friend ostream& operator << (ostream& out, dir d);


};
istream& operator >> (istream& in, dir& d)
{
	cout<<"Enter area code";
	in>>d.area_code;
	cout<<"Enter prefix";
	in>>d.prefix;
	cout<<"Enter number";
	in>>d.number;
	cout<<"Enter name";
	in>>d.name;
	return in;
}
ostream& operator << (ostream& out, dir d)
{
	out<<"Area code: "<<d.area_code<<endl;
	out<<"Prefix: "<<d.prefix<<endl;
	out<<"Number: "<<d.number<<endl;
	out<<"Name: "<<d.name<<endl;
	return out;
}

int main()
{
	dir d;
	cin>>d;
	cout<<d;

}
