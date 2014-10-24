#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,rem,y=33102,x=103993;
        cin>>k;
        cout<<3;
        if(k>0){
            cout<<'.';
            x=x%y*10;
            for(int i=0; i<k; i++)
            {
//                while(x<y) //wrong because would print 00 even when output should end with one zero
//                {
//                    cout<<0;
//                    x*=10;
//                    i++;
//                }
                cout<<x/y;
                x=x%y*10;
            }

        }
        cout<<endl;

    }
}
