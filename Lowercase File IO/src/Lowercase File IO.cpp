//============================================================================
// Name        : Lowercase.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
	char str[100];
	cout<<"Enter a sentence\n";
	cin.getline(str, 100);
	ofstream f("FIRST.TXT");
	f<<str;
	f.close();
	ifstream fr("FIRST.TXT");
	ofstream s("SECOND.TXT");
	char word[20];
	while(true)
	{
		fr>>word;

		if(islower(word[0]))
		{
			s<<word<<" ";
		}
		if(fr.eof())
			break;

	}
	fr.close();
	s.close();


}
