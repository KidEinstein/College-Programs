//============================================================================
// Name        : FeetToInches.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class convert
{
protected:
	int a,b;
public:
	virtual void compute()=0;
	void display()
	{
		cout<<"a: "<<a<<" b: "<<b<<endl;
	}
	void read()
	{
		cout<<"Enter value: ";
		cin>>a;
	}


};
class FtoC : public convert
{
public:
	void compute()
	{
		b=((float)5/9)*(a-32);
	}
};

class FtoI : public convert
{
public:
	void compute()
	{
		b=a*12;
	}
};
int main()
{
	FtoC a;
	a.read();
	a.compute();
	a.display();
	FtoI b;
	b.read();
	b.compute();
	b.display();
}

