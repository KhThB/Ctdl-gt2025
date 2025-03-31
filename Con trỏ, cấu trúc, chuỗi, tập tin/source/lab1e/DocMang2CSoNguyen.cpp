#include <iostream>
#include <cstdio> // Thư viện C cho FILE*
#define FI "MangSo.inp"

using namespace std;

void InputMatrix(int& n, int& m, int a[100][100]) {
    FILE* fi = fopen(FI, "rt"); // Mở file để đọc
    if (fi == NULL) {
        cout << "Không thể đọc file" << endl;
        return;
    }

    fscanf(fi, "%d %d", &n, &m); // Đọc số dòng và số cột

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fi, "%d", &a[i][j]); // Đọc từng số nguyên vào mảng
        }
    }

    fclose(fi); // Đóng file
}

void OutputMatrix(int n, int m, int a[100][100]) {
    cout << "Ma trận " << n << "x" << m << " từ file:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int a[100][100]; // Mảng tối đa 100x100 phần tử

    InputMatrix(n, m, a);
    OutputMatrix(n, m, a);

    return 0;
}
