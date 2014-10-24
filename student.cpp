#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
using namespace std;
class student
{
    char usn[10];
    char name[30];
    int marks[3];
    int avg;
    public:
    student(char u[], char n[], int m1, int m2, int m3)
    {
        strcpy(usn,u);
        strcpy(name, n);
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
    }
    void average()
    {
        int mini;
        for(int i=0; i<3;i++)
        {
            if(marks[i]<mini)
            {
                mini=marks[i];
            }
        }
        avg=(marks[0]+marks[1]+marks[2]-mini)/2;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"USN: "<<usn<<endl;
        cout<<"Average: "<<avg<<endl;
    }

};
int main()
{
    cout<<"Enter name: ";
    char name[30];
    gets(name);
    cout<<"Enter USN: ";
    char usn[10];
    cin>>usn;
    int marks[3];
    cout<<"Enter 3 marks: ";
    for(int i=0; i<3; i++)
    {
        cin>>marks[i];
    }
    student s(usn, name, marks[0], marks[1], marks[2]);
    s.average();
    s.display();


}
