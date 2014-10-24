#include<iostream>
using namespace std;
class comp
{
    int r,i;
    public:
    comp(){}
    comp(int real, int img)
    {
        r=real;
        i=img;
    }
    void add(comp c)
    {
        r+=c.r;
        i+=c.i;
    }
    void display()
    {
        if(i>=0)
        {
            cout<<r<<"+"<<i<<"i"<<endl;

        }
        else
            cout<<r<<i<<"i"<<endl;
    }
};
int main()
{

    cout<<"Enter real part: ";
    int r;
    cin>>r;
    cout<<"Enter imaginary part: ";
    int i;
    cin>>i;
    comp c1(r,i);
    cout<<"Enter real part: ";

    cin>>r;
    cout<<"Enter imaginary part: ";

    cin>>i;
    comp c2(r,i);
    c1.display();
    c2.display();
    cout<<"Sum: ";
    c1.add(c2);
    c1.display();


}
