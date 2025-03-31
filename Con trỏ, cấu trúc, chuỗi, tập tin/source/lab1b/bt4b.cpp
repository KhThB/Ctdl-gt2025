#include <iostream>

using namespace std;

// Hàm trộn hai mảng tăng dần thành mảng tăng dần mới
void merge(double* a, int n, double* b, int m, double* c, int& sizeC) {
    int i = 0, j = 0, k = 0;

    // Trộn hai mảng theo thứ tự tăng dần
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }

    // Sao chép phần còn lại của mảng a (nếu có)
    while (i < n) {
        c[k++] = a[i++];
    }

    // Sao chép phần còn lại của mảng b (nếu có)
    while (j < m) {
        c[k++] = b[j++];
    }

    sizeC = k; // Gán kích thước thực tế của mảng c
}

int main() {
    int n, m;

    // Nhập dãy số a
    cout << "+ Day so a" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    double a[100];
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }

    // Nhập dãy số b
    cout << "+ Day so b" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> m;

    if (m <= 0 || m > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    double b[100];
    for (int i = 0; i < m; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> b[i];
    }

    // Tạo dãy số c từ a và b sao cho tăng dần
    double c[200]; // Mảng kết quả, tối đa 200 phần tử
    int sizeC = 0;
    merge(a, n, b, m, c, sizeC);

    // Xuất dãy số c
    cout << "+ Day so c" << endl;
    cout << "Day so co " << sizeC << " phan tu: ";
    for (int i = 0; i < sizeC; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
