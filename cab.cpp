#include<iostream>
using namespace std;
class cab
{
    int miles;
    public:
    void read()
    {
        cout<<"Enter distance covered in miles: ";
        cin>>miles;
    }
    friend float fare(cab);
};
float fare(cab c)
{
    return c.miles>100?(c.miles-100)*0.15+100*0.25:c.miles*0.25;
}
int main()
{
    cab c;
    c.read();
    cout<<"Total fare: $"<<fare(c);
}

