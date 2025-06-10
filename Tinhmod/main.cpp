#include <bits/stdc++.h>

using namespace std;
int tinhmod(int a,int b,int n)
{
    int f =1;
    while(b>0)
    {
        if(b % 2 ==1)
            f = (f*a) % n;
        a = (a*a) % n;
        b = b/2;
    }
    return f;
}

int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int f = tinhmod(a,b,n);
    cout<<"Ket qua la :"<<f;
    return 0;
}
