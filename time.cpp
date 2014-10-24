#include<iostream>
using namespace std;
class tim
{
    int h, m, s;
    public:
    tim(){}
    tim(int hours, int minutes, int seconds)
    {
        h=hours;
        m=minutes;
        s=seconds;
    }
    void display()
    {
        cout<<"Time :"<<h<<":"<<m<<":"<<s<<endl;
    }
    void add(tim t1, tim t2)
    {
        h=t1.h+t2.h;
        m=t1.m+t2.m;
        s=t1.s+t2.s;
        if(s>60)
        {
            m+=s/60;
            s=s%60;
        }
        if(m>60)
        {
            h+=m/60;
            m=m%60;
        }
    }
};
int main()
{
    tim t1(10,20,30),t2(3,55,49),t3;
    t1.display();
    t2.display();
    t3.add(t1,t2);
    t3.display();
}
