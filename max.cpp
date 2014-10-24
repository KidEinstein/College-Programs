#include<iostream>
using namespace std;
inline int max_num(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    cout<<"Enter two numbers";
    int a,b;
    cin>>a>>b;
    cout<<"Largest number is "<<max_num(a,b);
}
