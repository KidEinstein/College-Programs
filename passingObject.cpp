#include<iostream>
using namespace std;
class rectangle
{
    int l,b;
    public:
    rectangle(int x, int y)
    {
        cout<<"Constructor called"<<endl;
        l=x;
        b=y;
    }
    ~rectangle()
    {
        cout<<"Destructor called"<<endl;
    }
    int get_area()
    {
        return l*b;
    }
};
void area(rectangle r)
{
    cout<<"Area is: "<<r.get_area()<<endl;
}
int main()
{
    rectangle rec(10,20);
    area(rec);


}
