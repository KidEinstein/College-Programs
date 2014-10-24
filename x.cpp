#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        int l=1;
        while(m--)
        {
            int x;
            cin>>x;
            l=lcm(l, x);
        }
        cout<<n/l<<endl;
    }
}
