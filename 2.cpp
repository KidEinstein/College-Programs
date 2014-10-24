#include<iostream>
using namespace std;
struct train
{
    int x,l,f;
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,total_time=0;
        cin>>n;
        train t[n];

        for(int i=0; i<n; i++)
        {
            cin>>t[i].x>>t[i].l>>t[i].f;
            if(t[i].x>total_time)
                total_time=t[i].x;
            else
            {
                    //total_time+=(t[i].x-(total_time%t[i].f)+t[i].f)%t[i].f;
                    //total_time+=(((total_time-t[i].x)/t[i].f)+1)*t[i].f-(total_time-t[i].x);
                int n=0;
                while(1)
                    {
                        if(total_time-((t[i].x)+n*t[i].f)>0);
                        else break;
                        n++;


                    }
                total_time+=t[i].x+n*t[i].f-total_time;
            }
            total_time+=t[i].l;
        }
        cout<<total_time<<endl;

    }
    return 0;
}
