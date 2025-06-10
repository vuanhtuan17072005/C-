#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Tính định thức của ma trận 2x2
int determinant(int matrix[2][2]) {
    return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]) % 26;
}

// Tìm nghịch đảo modulo của số a theo mod m
int modInverse(int a, int m) {
    a = a % m;
    for(int x = 1; x < m; x++) {
        if((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Tính ma trận nghịch đảo modulo 26 của ma trận 2x2
bool inverseMatrix(int key[2][2], int inverse[2][2]) {
    int det = determinant(key);
    if (det < 0) det += 26;
    int invDet = modInverse(det, 26);
    if (invDet == -1) return false;

    inverse[0][0] = ( key[1][1] * invDet) % 26;
    inverse[0][1] = (-key[0][1] * invDet + 26) % 26;
    inverse[1][0] = (-key[1][0] * invDet + 26) % 26;
    inverse[1][1] = ( key[0][0] * invDet) % 26;

    return true;
}

// Chuyển ký tự về số: A = 0, B = 1, ...
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Chuyển số về ký tự
char intToChar(int n) {
    return (n % 26 + 26) % 26 + 'A';
}

// Mã hóa Hill Cipher
string hillEncrypt(string plaintext, int key[2][2]) {
    string result = "";
    if (plaintext.length() % 2 != 0) plaintext += 'X'; // Padding

    for (size_t i = 0; i < plaintext.length(); i += 2) {
        int a = charToInt(plaintext[i]);
        int b = charToInt(plaintext[i+1]);

        int x = (key[0][0]*a + key[0][1]*b) % 26;
        int y = (key[1][0]*a + key[1][1]*b) % 26;

        result += intToChar(x);
        result += intToChar(y);
    }
    return result;
}

// Giải mã Hill Cipher
string hillDecrypt(string ciphertext, int key[2][2]) {
    string result = "";
    int invKey[2][2];

    if (!inverseMatrix(key, invKey)) {
        return "Khong ton tai ma tran nghich dao.";
    }

    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        int a = charToInt(ciphertext[i]);
        int b = charToInt(ciphertext[i+1]);

        int x = (invKey[0][0]*a + invKey[0][1]*b) % 26;
        int y = (invKey[1][0]*a + invKey[1][1]*b) % 26;

        result += intToChar(x);
        result += intToChar(y);
    }
    return result;
}

int main() {
    int key[2][2] = {{3, 3}, {2, 5}}; // Ma trận khóa ví dụ
    string plaintext, ciphertext;

    cout << "Nhap chuoi can ma hoa (chi chu cai): ";
    getline(cin, plaintext);

    ciphertext = hillEncrypt(plaintext, key);
    cout << "Ma hoa: " << ciphertext << endl;

    string decrypted = hillDecrypt(ciphertext, key);
    cout << "Giai ma: " << decrypted << endl;

    return 0;
}
