#include <bits/stdc++.h>

using namespace std;
/*
string maCaesar(string text, int k)
{
    string newtext = "";
    for(char c : text)
    {
        if(isupper(c))
            newtext += char(int((c - 'A' + k + 26 )%26 + 'A'));
        else if(islower(c))
            newtext += char(int((c - 'a' + k + 26 )%26 + 'a'));
        else
            newtext += c;
    }
    return newtext;
}
*/
string maCaesar(string text, int k)
{
    string newtext = "";
    for(char c : text)
    {
        if(isupper(c))
            newtext += char(int((c - 'A' + k + 26) %26 +'A'));
        else if(islower(c))
            newtext += char(int((c -'a' + k + 26) % 26 + 'a'));
        else
            newtext += c;
    }
    return newtext;
}
int main()
{
    string text ;
    int k;
    cout<<"Moi ban nhap chuoi ky tu:";
    getline(cin,text);
    cout<<"Ban muon nhay buoc bao nhieu:";
    cin>>k;
    string newtext = maCaesar(text,k);
    cout<<"Ma hoa:"<<newtext;
    return 0;
}
