#include <iostream>

using namespace std;

// Hàm kiểm tra ký tự có phải nguyên âm không
bool nguyenam(char c) {
    c = tolower(c); // Chuyển về chữ thường để kiểm tra
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
bool fullnguyenam(char* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (!nguyenam(arr[i])) {
            return false; // Nếu gặp ký tự không phải nguyên âm, trả về false
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    char a[100], b[100]; // Mảng a chứa dãy gốc, b chứa nguyên âm
    int bSize = 0; // Kích thước thực tế của mảng b

    // Nhập dãy ký tự
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];

        // Nếu là nguyên âm, thêm vào dãy b
        if (nguyenam(a[i])) {
            b[bSize++] = a[i];
        }
    }

    // Xuất dãy ký tự nguyên âm
    cout << "Day ky tu nguyen am: ";
    if (bSize == 0) {
        cout << "Khong co ky tu nguyen am." << endl;
    }
    else {
        for (int i = 0; i < bSize; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    if (fullnguyenam(a, n)) {
        cout << "Day co tinh chat hoan toan nguyen am" << endl;
    }
    else {
        cout << "Day khong co tinh chat hoan toan nguyen am" << endl;
    }
    return 0;
}
