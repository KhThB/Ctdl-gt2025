#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;

    // Nhập chuỗi và vị trí cần xóa
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;
    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Kiểm tra nếu vị trí k hợp lệ
    if (k >= 0 && k < s.length()) {
        // Xóa ký tự tại vị trí k
        s.erase(k, 1);
        cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    }
    else {
        cout << "Vi tri khong hop le!" << endl;
    }

    return 0;
}
