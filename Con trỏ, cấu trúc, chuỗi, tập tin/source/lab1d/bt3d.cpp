#include <iostream>
#include <string>
using namespace std;

// Hàm chèn ký tự vào chuỗi tại vị trí k
void chenKyTu(string& s, int k, char c) {
    // Chèn ký tự c vào chuỗi s tại vị trí k
    s.insert(k, 1, c);
}

int main() {
    string s;
    int k;
    char c;

    // Nhập chuỗi, vị trí cần chèn và ký tự cần chèn
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;

    // Kiểm tra vị trí k hợp lệ
    if (k >= 0 && k <= s.length()) {
        chenKyTu(s, k, c);
        cout << "Chuoi sau khi chen ky tu \"" << c << "\" vao vi tri " << k << ": " << s << endl;
    }
    else {
        cout << "Vi tri khong hop le!" << endl;
    }

    return 0;
}
