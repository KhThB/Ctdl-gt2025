#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Hàm sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần
void SapXepChuoi(char s[]) {
    int length = strlen(s);
    sort(s, s + length); // Sắp xếp ký tự trong chuỗi
}

int main() {
    char s[1001]; // Giới hạn tối đa 1000 ký tự

    // Nhập chuỗi từ bàn phím
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);

    // Sắp xếp chuỗi
    SapXepChuoi(s);

    // Xuất kết quả
    cout << "Chuoi sau khi sap xep: " << s << endl;

    return 0;
}
