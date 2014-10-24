#include<iostream>
using namespace std;
class data1;
class data2;
class data1
{
    int a,b;
    public:
    void read1()
    {
        cout<<"Enter value of a and b: ";
        cin>>a>>b;
    }
    friend void add(data1, data2);

};
class data2
{
    int c,d;
    public:
    void read2()
    {
        cout<<"Enter value of c and d: ";
        cin>>c>>d;
    }
    friend void add(data1, data2);

};
void add(data1 d1, data2 d2)
{
    cout<<"a+c = "<<d1.a+d2.c<<endl;
    cout<<"b+d = "<<d1.b+d2.d<<endl;
}
int main()
{
    data1 d1;
    data2 d2;
    d1.read1();
    d2.read2();
    add(d1,d2);
}
