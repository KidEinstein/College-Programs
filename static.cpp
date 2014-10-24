#include<iostream>
using namespace std;
class example
{
    static int count;
    public:
    example()
    {
        cout<<"Object created"<<endl;
        cout<<"Objects alive: "<<++count<<endl;

    }
    ~example()
    {
        cout<<"Object destroyed"<<endl;
        cout<<"Objects remaining: "<<--count<<endl;
    }
};
int example::count=0;
void func()
{
    example ob;
}
int main()
{
    example ob1, ob2;
    func();
    example ob3;
}
