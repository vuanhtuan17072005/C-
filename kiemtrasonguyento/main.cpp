#include <bits/stdc++.h>

using namespace std;
int tinhmod(int a,int b, int n)
{
    int f =1;
    while(b>0)
    {
        if(b % 2 == 1)
            f = (f * a) % n;
        a = (a*a)%n;
        b = b/2;
    }
    return f;
}
void checknguyento(int p, int a)
{
    if(p<3 || p % 2 ==0)
    {
        cout<<p<<" khong phai la so nguyen to";
        return;
    }
    int k = 0;
    int q = p-1;
    while( q % 2 == 0)
    {
        q = q /2;
        k++;
    }
    if(tinhmod(a,q,p) == 1)
    {
        cout<<p<<" co the la so nguyen to.";
        return;
    }
    for(int j=0; j < k ; j++)
    {
        if(tinhmod(a,(1<<j)*q,p)== 1)
        {
            cout<<p<<" co the la so nguyen to.";
            return;
        }
    }
    cout<<p<<" khong phai la so nguyen to.";
}
int main()
{
    int p,a;
    cin>>p>>a;
    while(a<= 1 || a >= (p-1))
    {
        cout<<"Moi ban nhap lai a:";
        cin>>a;
    }
    checknguyento(p,a);
    return 0;
}
