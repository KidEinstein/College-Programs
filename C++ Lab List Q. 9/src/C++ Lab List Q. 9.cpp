//============================================================================
// Name        : .cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class number;
number operator + (number m, number n);
class number
{
	int data;
public:
	number()
{

}
	number(int n)
{
		data=n;
}
	void read()
	{
		cin>>data;
	}
	void display()
	{
		cout<<data<<endl;
	}
	number operator ++ ()
		{
		return number(++data);
		}
	number operator ++ (int x)
		{
		return number(data++);
		}
	number operator - (number n)
	{
		number temp;
		temp.data=data-n.data;
		return temp;
	}
	number operator = (number n)
	{
		data=n.data;
	}
	friend number operator + (number m, number n);

};
number operator + (number m, number n)
{
	number temp;
	temp.data=m.data+n.data;
	return temp;
}

int main()
{
	number a,b,c,d,e,f,g;
	a.read();
	b.read();
	c=a++;
	d=++b;
	e=a-b;
	f=a+b;
	g=a;
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();

}
