#include<iostream>
#include<string.h>
using namespace std;
void stradd(char *s1, char *s2)
{
    strcat(s1, s2);
}
void stradd(char *s1, int i)
{
    char z[2]={char((int)'0'+i),'\0'};
    strcat(s1, z);
}
int main()
{
    char s1[20],s2[20];
    int n;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    stradd(s1,s2);
    cout<<"Resulting string: "<<s1;
    cout<<"\nEnter a string and an integer: ";
    cin>>s1>>n;
    stradd(s1, n);
    cout<<"Resulting string: "<<s1;
}
