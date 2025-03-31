#include <iostream>
#include <cstdio> // Thư viện C cho FILE*
#define FI "DaySoNguyen.inp"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void InputData(int& n, int a[]) {
    FILE* fi = fopen(FI, "rt"); // Mở file để đọc
    if (fi == NULL) {
        cout << "Khong the doc file" << endl;
        return;
    }

    fscanf(fi, "%d", &n); // Đọc số phần tử

    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &a[i]); // Đọc từng số nguyên
    }

    fclose(fi); // Đóng file
}

void OutputData(int n, int a[]) {
    cout << "n = " << n << endl;
    cout << "Cac so nguyen trong file: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int a[1000]; // Khai báo mảng chứa tối đa 1000 phần tử

    InputData(n, a);
    OutputData(n, a);

    return 0;
}
