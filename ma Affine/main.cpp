#include <bits/stdc++.h>

using namespace std;
int timnghichdao(int a,int n)
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
        if(b3==0) return 0;
        else
            if(b3 == 1) return (b2 + n)%n;
        q = a3 / b3;
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
// ax +b
string mahoa(string text,int a, int b)
{
    string newtext ="";
    for(char c : text)
    {
        if(isalpha(c))
        {
        char base = isupper(c) ? 'A' : 'a';
        char d = (a*(c - base) +b) % 26 + base;
        newtext += d;
        }
        else
            newtext += c;
    }
    return newtext;
}
 // y= a^-1 * (y - b)
string giaima(string text,int a,int b)
{
    int newa = timnghichdao(a,26);
    string newtext = "";
    for(char c : text)
    {
        if(isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int decoded = (newa * ((c - base - b + 26) % 26)) % 26;
            newtext += decoded + base;

        }
        else
            newtext += c;
    }
    return newtext;
}

string giaima(string text, int a, int b) {
    int newa = timnghichdao(a, 26);
    if (newa == -1) {
        return "Khong co nghich dao cua a, giai ma that bai.";
    }

    string newtext = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int decoded = (newa * ((c - base - b + 26) % 26)) % 26;
            char d = decoded + base;
            newtext += d;
        } else {
            newtext += c;
        }
    }
    return newtext;
}

int main() {
    int a, b;
    int x = timnghichdao(7,26);
    cout<<x<<endl;
    string text;
    cin >> a >> b;
    cin.ignore();
    cout << "nhap van ban:";
    getline(cin, text);
    cout << giaima(text, a, b);
    return 0;
}
