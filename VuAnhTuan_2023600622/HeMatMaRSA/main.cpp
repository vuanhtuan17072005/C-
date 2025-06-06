#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long a, long long b, long long m);
// Hàm kiểm tra số nguyên tố (Miller-Rabin)
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    int k = 0, q = n - 1;
    while (q % 2 == 0) {
        q /= 2;
        k++;
    }

    // Kiểm tra với a = 2, 3, 5, 7 (đủ mạnh cho số nhỏ)
    for (int a : {2, 3, 5, 7}) {
        if (a >= n) continue;

        long long x = pow_mod(a, q, n);
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int j = 0; j < k - 1; j++) {
            x = pow_mod(x, 2, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// Hàm tính lũy thừa modulo
long long pow_mod(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

// Hàm tính gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm tìm nghịch đảo modulo
int modInverse(int e, int phi) {
    e = e % phi;
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1; // Không tồn tại
}

// Hàm tạo khóa RSA
void generateRSAKeys(int p, int q, int &e, int &d, int &n) {
    n = p * q;
    int phi = (p - 1) * (q - 1);

    // Chọn e (thường là 65537)
    e = 65537;
    while (gcd(e, phi) != 1) {
        e--;
    }

    // Tính d
    d = modInverse(e, phi);
}

int main() {
    int p, q;

    // Nhập và kiểm tra p, q là số nguyên tố
    do {
        cout << "Nhap so nguyen to p: ";
        cin >> p;
    } while (!isPrime(p));

    do {
        cout << "Nhap so nguyen to q (khac p): ";
        cin >> q;
    } while (!isPrime(q) || q == p);

    int e, d, n;
    generateRSAKeys(p, q, e, d, n);

    cout << "\nKhóa công khai (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Khóa bí mật (d, n): (" << d << ", " << n << ")" << endl;

    // Mã hóa và giải mã
    int M;
    cout << "\nNhap thong diep M (0 < M < " << n << "): ";
    cin >> M;

    // Mã hóa
    long long C = pow_mod(M, e, n);
    cout << "Ban ma C = " << C << endl;

    // Giải mã
    long long D = pow_mod(C, d, n);
    cout << "Giai ma D = " << D << endl;

    return 0;
}
