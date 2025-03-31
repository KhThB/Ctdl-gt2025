#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

#define INPUT_FILE "CapSo.INP"
#define OUTPUT_FILE "CapSo.OUT"

using namespace std;

void findPairs() {
    FILE* fi = fopen(INPUT_FILE, "rt");
    if (fi == NULL) {
        cout << "Không thể đọc file " << INPUT_FILE << endl;
        return;
    }

    int n, k;
    fscanf(fi, "%d %d", &n, &k); // Đọc n và k

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &a[i]); // Đọc dãy số
    }
    fclose(fi);

    unordered_set<int> seen; // Tập hợp để kiểm tra nhanh
    vector<pair<int, int>> result; // Lưu kết quả cặp số

    for (int i = 0; i < n; i++) {
        int complement = k - a[i]; // Tìm số cần để tạo tổng k
        if (seen.count(complement)) {
            result.push_back({ complement, a[i] });
        }
        seen.insert(a[i]); // Thêm số hiện tại vào tập hợp
    }

    FILE* fo = fopen(OUTPUT_FILE, "wt");
    if (fo == NULL) {
        cout << "Không thể ghi file " << OUTPUT_FILE << endl;
        return;
    }

    if (result.empty()) {
        fprintf(fo, "0\n"); // Không tìm thấy cặp số nào
    }
    else {
        for (auto& p : result) {
            fprintf(fo, "%d %d\n", p.first, p.second);
        }
    }

    fclose(fo);
}

int main() {
    findPairs();
    cout << "Đã xử lý xong. Kiểm tra kết quả trong file CapSo.OUT" << endl;
    return 0;
}
