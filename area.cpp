#include<iostream>
using namespace std;
int area(int l, int b)
{
    return l*b;
}
float area(int s)
{
   return s*s;
}
float area(float r)
{
    return 3.14*r*r;
}
int main()
{
    int choice,l,b,s;
    float r,ar;
    cout<<"1. Circle\n2. Rectangle\n3.Square\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter radius: ";
        cin>>r;
        ar=area(r);
        break;
    case 2:
        cout<<"Enter length and breadth: ";
        cin>>l>>b;
        ar=area(l,b);
        break;
    case 3:
        cout<<"Enter side: ";
        cin>>s;
        ar=area(s);
        break;
    }
    cout<<"Area is "<<ar;
}
