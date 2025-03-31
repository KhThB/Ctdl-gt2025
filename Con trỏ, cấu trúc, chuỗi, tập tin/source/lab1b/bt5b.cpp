#include <iostream>

using namespace std;

int main() {
    int n;

    // Nhập số lượng phần tử của dãy a
    cout << "+ Day so a" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    int a[100], b[100], c[100]; // a: dãy gốc, b: dãy số chẵn, c: dãy số lẻ
    int bSize = 0, cSize = 0;   // Số phần tử thực tế của b và c

    // Nhập dãy số nguyên a
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];

        // Phân loại số chẵn và số lẻ
        if (a[i] % 2 == 0) {
            b[bSize++] = a[i]; // Thêm vào dãy số chẵn
        }
        else {
            c[cSize++] = a[i]; // Thêm vào dãy số lẻ
        }
    }

    // Xuất dãy số chẵn b
    cout << "+ Day so b chua so chan" << endl;
    if (bSize == 0) {
        cout << "Khong co so chan." << endl;
    }
    else {
        cout << "Day so co " << bSize << " phan tu: ";
        for (int i = 0; i < bSize; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    // Xuất dãy số lẻ c
    cout << "+ Day so c chua so le" << endl;
    if (cSize == 0) {
        cout << "Khong co so le." << endl;
    }
    else {
        cout << "Day so co " << cSize << " phan tu: ";
        for (int i = 0; i < cSize; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
