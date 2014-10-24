#include<iostream>
using namespace std;
class sal
{
    int eno, ename, basic, it, da, hra, net_sal, gross_salary;
    public:
    void read()
    {
        cout<<"Enter basic salary: ";
        cin>>basic;
    }
    void compute()
    {
        da=0.7*basic;
        hra=0.2*basic;
        gross_salary=basic+da+hra;
        if(gross_salary>200000)
        {
            it=0.1*gross_salary;
        }
        else
            it=0;
        net_sal=gross_salary-it;
    }
    void print()
    {
        cout<<"Basic Salary: "<<basic<<endl;
        cout<<"DA: "<<da<<endl;
        cout<<"HRA: "<<hra<<endl;
        cout<<"Income Tax: "<<it<<endl;
        cout<<"Gross salary: "<<gross_salary<<endl;
        cout<<"Net salary: "<<net_sal<<endl;
    }

};
int main()
{
    sal e1;
    e1.read();
    e1.compute();
    e1.print();
}
