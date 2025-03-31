#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define INPUT_FILE "NT.INP"
#define OUTPUT_FILE "NT.OUT"

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đọc dữ liệu từ file và tìm số nguyên tố
void findPrimes() {
    FILE* fi = fopen(INPUT_FILE, "rt");
    if (fi == NULL) {
        cout << "Không thể đọc file " << INPUT_FILE << endl;
        return;
    }

    int n;
    fscanf(fi, "%d", &n); // Đọc số phần tử

    vector<int> primes;
    int num;

    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &num);
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
    fclose(fi);

    // Sắp xếp số nguyên tố theo thứ tự tăng dần
    sort(primes.begin(), primes.end());

    // Ghi kết quả ra file
    FILE* fo = fopen(OUTPUT_FILE, "wt");
    if (fo == NULL) {
        cout << "Không thể ghi file " << OUTPUT_FILE << endl;
        return;
    }

    fprintf(fo, "%d\n", (int)primes.size()); // Ghi số lượng số nguyên tố
    for (int prime : primes) {
        fprintf(fo, "%d ", prime); // Ghi từng số nguyên tố
    }
    fclose(fo);
}

int main() {
    findPrimes();
    cout << "Đã xử lý xong. Kiểm tra kết quả trong file NT.OUT" << endl;
    return 0;
}
