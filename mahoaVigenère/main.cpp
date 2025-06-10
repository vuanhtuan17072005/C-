#include <bits/stdc++.h>

using namespace std;
// chuyen do dai bang chuoi
/*
string newkey(string text , string key)
{
    string newkey = key;
    while(newkey.length() < text.length())
    {
        newkey += key;
    }
    return newkey.substr(0,text.length());
}
string mahoa(string text , string key)
{
    string newtext ="";
    string newkey1 = newkey(text,key);
    for(int i=0;i<text.length();i++)
    {
        if(isalpha(text[i]))
        {
        char base = isupper(text[i]) ? 'A' : 'a';
        char basekey = isupper(newkey1[i]) ? 'A' : 'a';
        char mintext = (text[i] - base + (newkey1[i] - basekey)) % 26 + base;
        newtext += mintext;
        }
        else
        {
            newtext += text[i];
        }
    }
    return newtext;
}
*/string newkey (string text,string key)
{
    string newkey = key;
    while(newkey.length() < text.length())
    {
        newkey += key;
    }
    return newkey.substr(0,text.length());
}
string mahoa(string text,string key)
{
    string newtext ="";
    string newkey1 = newkey(text,key);
    for(int i=0;i< text.length();i++)
    {
        if(isalpha(text[i]))
        {
        char base = isupper(text[i]) ? 'A' : 'a';
        char basekey = isupper(newkey1[i]) ? 'A' : 'a';
        char c = (text[i] - base + (newkey1[i] - basekey)) % 26 + base;
        newtext +=c;
        }
        else
            newtext += text[i];
    }
    return newtext;
}
int main()
{
    string text,key;
    cout<<"Van ban: ";
    getline(cin,text);
    cout<<"khoa bi mat:";
    getline(cin,key);
    cout<<mahoa(text,key);
    return 0;
}
