#include <iostream>

using namespace std;

// Hàm ki?m tra tính ch?n l? xen k?
bool xenke(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2) == (arr[i - 1] % 2)) {
            return false;
        }
    }
    return true;
}

// Hàm ki?m tra dãy có toàn s? ch?n không
bool chan(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            return false;
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

    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> arr[i];
    }

    if (xenke(arr, n)) {
        cout << "+ Day co tinh chat chan le\n";
    }
    else {
        cout << "+ Day khong co tinh chat chan le\n";
    }

    if (chan(arr, n)) {
        cout << "+ Day co tinh chat toan chan\n";
    }
    else {
        cout << "+ Day khong co tinh chat toan chan\n";
    }

    return 0;
}
