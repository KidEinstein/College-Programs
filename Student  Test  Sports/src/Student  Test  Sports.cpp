//============================================================================
// Name        : Student.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Student
{
protected:
	int usn;
	char name[20];
public:
	Student()
{
		cout<<"Enter USN and Name"<<endl;
		cin>>usn>>name;
}
};
class Test:virtual public Student
{
protected:
	int marks;
public:
	Test()
	{
		cout<<"Enter marks obtained: ";
		cin>>marks;
	}
};
class Sports:virtual public Student
{
protected:
	char sport[20];
public:
	Sports()
{
		cout<<"Enter sports played: ";
		cin>>sport;
}
};
class Result:virtual public Test, virtual public Sports
{
public:
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"USN: "<<usn<<endl;
		cout<<"Marks Obtained: "<<marks<<endl;
		cout<<"Sport Played: "<<sport<<endl;
	}

};
int main()
{
	Result r;
	r.display();
}
