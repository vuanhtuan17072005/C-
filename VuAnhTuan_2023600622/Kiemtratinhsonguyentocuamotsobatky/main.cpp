#include <bits/stdc++.h>
using namespace std;

// Khai báo nguyên mẫu hàm trước
void timkq(int p, int &k, int &q);
long long mod_pow(long long a, long long b, long long m);

void kiemtratinhnguyento(int P, int a) {
    // Xử lý trường hợp P = 2
    if (P == 2) {
        cout << P << " la so nguyen to" << endl;
        return;
    }
    if (P < 2 || P % 2 == 0) {
        cout << P << " khong phai so nguyen to" << endl;
        return;
    }

    int k, q;
    timkq(P, k, q);

    // Kiểm tra điều kiện 1: a^q ≡ 1 mod P
    if (mod_pow(a, q, P) == 1) {
        cout << P << " co the la so nguyen to" << endl;
        return;
    }

    // Kiểm tra điều kiện 2: a^(2^j *q) ≡ -1 mod P
    for (int j = 0; j < k; j++) {
        long long exponent = q * pow(2,j);
        if (mod_pow(a, exponent, P) == P - 1) {
            cout << P << " co the la so nguyen to" << endl;
            return;
        }
    }

    cout << P << " khong phai so nguyen to" << endl;
}

void timkq(int p, int &k, int &q) {
    k = 0;
    q = p - 1;
    while (q % 2 == 0) {
        q /= 2;
        k++;
    }
}

// Hàm tính (a^b) mod m hiệu quả
long long mod_pow(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b / 2;
    }
    return res;
}

int main() {
    int p, a;
    cout << "Nhap so can kiem tra: ";
    cin >> p;
    cout << "Nhap so a (2 <= a <= " << p-1 << "): ";
    cin >> a;
    while (a < 2 || a >= p) {
        cout << "Nhap lai a: ";
        cin >> a;
    }

    kiemtratinhnguyento(p, a);
    return 0;
}
