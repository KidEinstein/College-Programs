//============================================================================
// Name        : File.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n;
	ofstream invOut("INVENTORY.TXT");
	char name[20];
	int code;
	int cost;
	cout<<"Enter number of items";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter name, code and cost"<<endl;
		cin>>name>>code>>cost;
		invOut<<name<<" "<<code<<" "<<cost<<endl;
	}
	invOut.close();

	ifstream invIn("INVENTORY.TXT");
	ofstream out("OUT.TXT");

	while(true)
	{
		invIn>>name>>code>>cost;
		if(!invIn.eof())
		{
			out<<name<<" "<<code<<" "<<cost<<endl;
			cout<<name<<endl<<code<<endl<<cost<<endl;
		}
		else
			break;
	}

	invIn.close();
	out.close();

}
