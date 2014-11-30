//============================================================================
// Name        : UG.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define N 3 //Number of students
#include <iostream>
using namespace std;

class Student
{
protected:
	char usn[11];
	char name[20];
	int age;
public:
	Student()
{
		cout<<"Enter USN: ";
		cin>>usn;
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter age: ";
		cin>>age;
}
	void display()
	{
		cout<<"USN: "<<usn;
		cout<<"Name: "<<name;
		cout<<"Age: "<<age;
	}
	int getAge()
	{
		return age;
	}

};

class PGStudent : public Student
{
protected:
	int sem;
	int fee;
	int stipend;
public:
	PGStudent()
{
		cout<<"Enter sem: ";
		cin>>sem;
		cout<<"Enter fee: ";
		cin>>fee;
		cout<<"Enter stipend";
		cin>>stipend;
}
	void display()
	{
		Student::display();
		cout<<"Sem: "<<sem;
		cout<<"Fee: "<<fee;
		cout<<"Stipend: "<<stipend<<endl;


	}
	int getSem()
	{
			return sem;
	}


};
class UGStudent : public Student
{
protected:
	int sem;
	int fee;
public:
	UGStudent()
{
		cout<<"Enter sem: ";
		cin>>sem;
		cout<<"Enter fee: ";
		cin>>fee;
}
	void display()
	{
		Student::display();
		cout<<"Sem: "<<sem;
		cout<<"Fee: "<<fee<<endl;

	}
	int getSem()
	{
			return sem;
	}

};

int main()
{

	int age_sum[8]={0};
	int age_avg[8]={0};
	int count[8]={0};
	UGStudent ugs[N];
	for(int i=0; i<N ;i++)
	{
		ugs[i].display();
	}

	cout<<"UG Students: "<<endl;
	for(int i=0; i<N ; i++)
	{
		int sem;
		sem=ugs[i].getSem()-1;
		age_sum[sem]+=ugs[i].getAge();
		count[sem]++;
	}
	for(int j=0; j<8; j++)
	{
		if(count[j])
		{
			age_avg[j]=age_sum[j]/count[j];
			cout<<"Semester "<<j+1<<" age average "<<age_avg[j]<<endl;
		}

	}
	PGStudent pgs[N];
	for(int i=0; i<N; i++)
	{
			ugs[i].display();
	}
	cout<<"PG Students: "<<endl;
	for(int i=0; i<8 ; i++)
	{
		age_sum[i]=0;
		age_avg[i]=0;
	}
	for(int i=0; i<N ; i++)
	{
		int sem;
		sem=pgs[i].getSem();
		age_sum[sem]+=pgs[i].getAge();
		count[sem]++;
	}
	for(int j=0; j<8; j++)
	{
		if(count[j])
		{
			age_avg[j]=age_sum[j]/count[j];
			cout<<"Semester "<<j+1<<" age average "<<age_avg[j]<<endl;
		}

	}




}

