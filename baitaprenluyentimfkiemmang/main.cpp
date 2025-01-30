#include <iostream>

using namespace std;
void nhapMang(float F[],int n);
void xuatMang(float F[],int n);
int searchMang(float F[],int n,float x);
float searchSoChan(float F[],int n);
int main()
{
    int n;
    float x;
    cout<<"Nhap so luong phan tu:";
    cin>>n;
    float F[n];
    nhapMang(F,n);
    cout<<"Mnag sau khi nhap la:"<<endl;
    xuatMang(F,n);
    cout<<"\nNhap so can tim trong mang :";
    cin>>x;
    int kq = searchMang(F,n,x);
    cout<<"So lan "<<x<<" xuat hien trong mang la:"<<kq<<endl;
    float kq2 = searchSoChan(F,n);
    if(kq2 == -99999)
        cout<<"Trong mang khong co phan tu chan nao."<<endl;
    else
        cout<<"Phan tu chan lon nhat trong mang la :"<<kq2<<endl;
    return 0;
}
void nhapMang(float F[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap gia tri cua phan tu thu "<<i<<":";
        cin>>F[i];
    }
}
void xuatMang(float F[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<F[i]<<"\t";
    }
}
int searchMang(float F[],int n,float x)
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(F[i]==x)
            d++;
    }
    return d;
}
float searchSoChan(float F[],int n)
{
    float max1=-99999;
    for(int i=0;i<n;i++)
    {
        int f2 =(int) F[i];
        if(f2 == F[i])
            if(F[i]>max1 && f2 % 2 ==0)
                return max1;
    }
}
