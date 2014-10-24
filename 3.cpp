#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,lvl[200]={0},l,c,creq=0;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>c>>l;
            lvl[l]+=c;
        }
        for(int i=0; i<m; i++)
        {
            cin>>c>>l;
            lvl[l]-=c;

        }
        for(int i=0; i<100; i++)
        {
            if(lvl[i]<0)
            creq+=abs(lvl[i]);
        }
        cout<<creq<<endl;




    }

}
