#include<iostream>
using namespace std;
bool isDone(int e[], int i, int eincn, int einc[])
{
    for(int i=0; i<eincn; i++)
    {
        if(e[0]==einc[i] || e[1]==einc[i])
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,e[10000][2],n1=0,pairs[10000],pairsn=0,einc[10000],eincn=0;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>e[i][0]>>e[i][1];
        }
        pairs[0]=m-1;
        pairsn++;
        einc[0]=e[m-1][0];
        einc[1]=e[m-1][1];
        eincn=2;
        for(int i=m-2;i>=0;i--)
        {
            if(isDone(e[i], i, eincn, einc))
            {
                continue;
            }
            else
            {
                einc[eincn]=e[i][0];
                eincn++;
                einc[eincn]=e[i][1];
                eincn++;
                pairs[pairsn]=i;
                pairsn++;
            }
        }
        for(int i=pairsn-1; i>=0; i--)
        {
            cout<<pairs[i]<<" ";
        }
        cout<<endl;
    }
}

