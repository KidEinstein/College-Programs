#include<iostream>
using namespace std;
class sample
{
    int a,b,c;
    public:
    void set_data(int x, int y, int z)
    {
        a=x;
        b=y;
        c=z;
    }
    void print()
    {
        cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl;
    }
};
sample func()
{
    int a,b,c;
    cout<<"Enter values of a, b and c: ";
    cin>>a>>b>>c;
    sample s;
    s.set_data(a,b,c);
    return s;
}
int main()
{
    sample s1;
    s1=func();
    s1.print();
}
