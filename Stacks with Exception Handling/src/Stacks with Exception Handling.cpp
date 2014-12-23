//============================================================================
// Name        : Stacks.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class stack
{
	int *a,top,size;
public:
	stack(int size)
{
		this->size=size;
		a = new int[size];
		top=-1;
}
	int pop()
	{
		if(top<0)
			throw "Stack Empty";
		return a[top--];
	}
	void push(int data)
	{
		if(top==size-1)
			throw "Stack Full";
		a[++top]=data;
	}
	void display()
	{
		for(int i=0; i<=top; i++)
		{
			cout<<a[i]<<"\t";
		}
		cout<<endl;
	}

};
int main() {
	int size,choice;
	cout<<"Enter size of stack";
	cin>>size;
	stack s(size);
	while(true)
	{
		cout<<" 1. Push\n 2. Pop\n 3. Display\n";
		cin>>choice;
		try{
			switch(choice)
			{
			case 1:
				int data;
				cout<<"Enter data: ";
				cin>>data;
				s.push(data);
				break;
			case 2:
				cout<<"Data popped: "<<s.pop()<<endl;
				break;
			case 3:
				s.display();
				break;
			}
		}
		catch(const char* err)
		{
			cout<<"Error occurred: "<<err<<endl;
		}

	}
}
