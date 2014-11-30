//============================================================================
// Name        : Overloading.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if(a==0)
		return b;
	return gcd(b%a , a);
}
int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}
class rational
{
	int num,den;
public:
	void read()
	{
		cout<<"Enter numerator and denominator";
		cin>>num>>den;
	}
	void display()
	{
		cout<<num<<" / "<<den<<endl;
	}
	rational operator + (rational r)
	{
		rational temp;
		int l=lcm(den,r.den);
		temp.num=num*l/den + r.num * l/r.den;
		temp.den=l;
		return temp;
	}
	rational operator * (rational r)
	{
		rational temp;
		temp.num = num * r.num;
		temp.den = den * r.den;
		return temp;
	}
	void toSimpleFraction()
	{
		int g = gcd(num, den);
		num/=g;
		den/=g;
	}
};

int main()
{
	rational a,b,c,d;
	a.read();
	b.read();

	a.display();
	b.display();
	a.toSimpleFraction();
	b.toSimpleFraction();
	a.display();
	b.display();
	c=a+b;
	d=a*b;
	c.display();
	d.display();
	c.toSimpleFraction();
	d.toSimpleFraction();
	c.display();
	d.display();

}


