//============================================================================
// Name        : Compact.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
void compact(T arr[], int start, int end, int& len)
{
	int i=start;
	int j=end+1;
	for(;i<=end;i++,j++)
	{
		arr[i]=arr[j];
	}
	len=len-(end-start+1);
}
template <class T>
void display(T arr[], int len)
{
	for(int i=0;i<len;i++)
		cout<<arr[i]<<"\t";
}
int main()
{
	int a[10], n, start, end;
	n=10;
	srand(time(NULL)); //Seeding rand function
	for(int i=0; i<n; i++)
	{
		a[i]=rand()%100; //Storing random numbers in the array from 0 to 100
	}
	display(a, n);
	cout<<"\nEnter start and end position for compaction";
	cin>>start>>end;
	compact(a, start, end, n);
	display(a, n);


}
