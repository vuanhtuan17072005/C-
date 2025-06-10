#include <bits/stdc++.h>

using namespace std;
/*
int UCLN(int a, int b)
{
   int r;
    while(true)
    {
       if(b==0) return a;
        r = a % b;
        a=b;
        b=r;
    }
}
int main()
{
   int a,b;
    cin>>a>>b;
    int r=UCLN(a,b);
    cout<<r;
    return 0;
}
*/
int UCLN(int a,int b)
{
   int r;
   while(true)
   {
       if(b==0) return a;
       r = a %b;
       a = b ;
       b = r;
   }
}
