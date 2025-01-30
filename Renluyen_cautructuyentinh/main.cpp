#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct SinhVien
{
        char ma[10];
        char ten[150];
        bool gioitinh;
};
void nhapDanhSach(SinhVien dsSV[],int siSo);
void xuatDanhSach(SinhVien dsSV[],int siSo);
SinhVien *timKiemTheoMa(SinhVien dsSV[],int siSo,char masv[]);
void timKiemTheogioitinh(SinhVien dsSV[],int siSo,bool gtct);
int main()
{
    int siSo;
    cout<<"So luong nhan vien ma ban muon nhap la:";
    cin>>siSo;
    cin.ignore();
    SinhVien dsSV[siSo];
    cout<<"Moi ban nhap danh sach sinh vien:"<<endl;
    nhapDanhSach(dsSV,siSo);
    cout<<"Danh sach sinh vien la :"<<endl;
    xuatDanhSach(dsSV,siSo);
    char masv[15];
    cout<<"Moi ban nhap ma sinh vien can tim kiem la: ";
    gets(masv);
    SinhVien *sv = timKiemTheoMa(dsSV,siSo,masv);
    if(sv==NULL)
        cout<<"Khong tim thay sinh vien can tim."<<endl;
    else
    {
        cout<<"Sinh vien ban can tim co trong danh sach :"<<endl;
        cout<<sv->ma<<"\t"<<sv->ten<<"\t"<<(sv->gioitinh==true?"Nam":"Nu")<<endl;
    }
    char gt[3];
    cout<<"Moi ban nhap gioi tinh can tim (m/f) la :";
    gets(gt);
    bool gtct = false; //nam
    if(stricmp(gt,"f"))
        gtct = true;//nu
    timKiemTheogioitinh(dsSV,siSo,gtct);
    return 0;
}
void nhapDanhSach(SinhVien dsSV[],int siSo)
{
    for(int i=0;i<siSo;i++)
    {
        cout<<"Sinh vien thu "<<i<<" la :"<<endl;
        cout<<"Ma :";
        gets(dsSV[i].ma);
        cout<<"Ten :";
        gets(dsSV[i].ten);
        char gt[2];
        cout<<"Gioi tinh (m/f) :";
        gets(gt);
        if(strcmp(gt,"f")==0)
            dsSV[i].gioitinh=false;
        else
            dsSV[i].gioitinh=true;
    }
}
void xuatDanhSach(SinhVien dsSV[],int siSo)
{
    for(int i=0;i<siSo;i++)
    {
        cout<<dsSV[i].ma<<"\t"<<dsSV[i].ten<<"\t"<<(dsSV[i].gioitinh==true?"Nam":"Nu")<<endl;
    }
}
SinhVien *timKiemTheoMa(SinhVien dsSV[],int siSo,char masv[])
{
    for(int i=0;i<siSo;i++)
    {
        if(stricmp(dsSV[i].ma,masv)==0)
            return &dsSV[i];
    }
    return NULL;
}
void timKiemTheogioitinh(SinhVien dsSV[],int siSo,bool gtct)
{
    for(int i=0;i<siSo;i++)
    {
        if(dsSV[i].gioitinh == gtct)
            cout<<dsSV[i].ma<<"\t"<<dsSV[i].ten<<"\t"<<(dsSV[i].gioitinh==true?"Nam":"Nu")<<endl;
    }
}
