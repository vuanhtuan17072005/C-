#include <bits/stdc++.h>

using namespace std;
/*int timnghichdao(int n,int a)
{
    int a1 = 1;
    int a2 = 0;
    int a3 = n;
    int b1 = 0;
    int b2 = 1;
    int b3 = a;
    int q ;
    int r1,r2,r3;
    while(true)
    {
        if(b3 == 0) return 0;
        else if(b3 == 1) return b2;
        q = a3/b3;
        r1 = a1 - q * b1;
        r2 = a2 - q * b2;
        r3 = a3 - q * b3;
        a1 = b1;
        a2 = b2;
        a3 = b3;
        b1 = r1;
        b2 = r2;
        b3 = r3;
    }
}
*/
int timnghichdao(int n , int a)
{
    int a1 = 1;
    int a2 = 0;
    int a3 = n;
    int b1 = 0;
    int b2 = 1;
    int b3 = a;
    int q;
    int r1,r2,r3;
    while(true)
    {
        if(b3 == 0) return 0;
        else if(b3 == 1) return b2;
        q = a3 / b3;
        r1 = a1 - q * b1;
        r2 = a2 - q * b2;
        r3 = a3 - q * b3;
        a1 = b1 ;
        a2 = b2;
        a3 = b3;
        b1 = r1;
        b2 = r2;
        b3 = r3;
    }
}
int main()
{
    int n , a;
    cin>>n>>a;
    int test = timnghichdao(n,a);
    if(test == 0)
        cout<<"Khong tim thay so nghich dao";
    else
        cout<<"So nghich dao :"<<test;
    return 0;
}
