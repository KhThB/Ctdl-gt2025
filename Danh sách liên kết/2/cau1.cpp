#include <iostream>
using namespace std;

typedef struct Node { //Tạo con trỏ
    int info;    
    Node* next;
} Node;

struct ListInt { //Tạo danh sách liên kết
    Node* pHead;
    // Khởi tạo danh sách rỗng
    ListInt() { pHead = NULL; }
    // Thêm số nguyên vào cuối danh sách
    void themSo(int x) {
        Node* p = new Node;
        p->info = x;
        p->next = NULL;

        if (pHead == NULL) {
            pHead = p;
        }
        else {
            Node* q = pHead;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    // Xuất danh sách số nguyên
    void xuatDanhSach() {
        Node* p = pHead;
        while (p) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
    // Xóa một số k trong danh sách
    void xoaSo(int k) {
        while (pHead && pHead->info == k) {
            Node* p = pHead;
            pHead = pHead->next;
            delete p;
        }
        Node* p = pHead;
        while (p && p->next) {
            if (p->next->info == k) {
                Node* nodeCanXoa = p->next;
                p->next = p->next->next;
                delete nodeCanXoa;
            }
            else {
                p = p->next;
            }
        }
    }
    // Thêm một danh sách khác vào danh sách hiện tại
    void themDanhSach(ListInt& dsKhac) {
        if (dsKhac.pHead == NULL) return;

        if (pHead == NULL) {
            pHead = dsKhac.pHead;
        }
        else {
            Node* p = pHead;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = dsKhac.pHead;
        }
        dsKhac.pHead = NULL; // Tránh trùng lặp vùng nhớ
    }
    // Giải phóng bộ nhớ danh sách
    void xoaDanhSach() {
        while (pHead) {
            Node* p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
};
int main() {
    ListInt danhSach1, danhSach2;
    int so, k;
    // Nhập 10 số nguyên vào danh sách 1
    cout << "Nhap 10 so nguyen: ";
    for (int i = 0; i < 10; i++) {
        cin >> so;
        danhSach1.themSo(so);
    }
    // Xuất danh sách 1
    cout << "Danh sach vua nhap: ";
    danhSach1.xuatDanhSach();
    // Nhập một số k và xóa khỏi danh sách
    cout << "Nhap so can xoa: ";
    cin >> k;
    danhSach1.xoaSo(k);
    // Xuất danh sách sau khi xóa
    cout << "Danh sach sau khi xoa " << k << ": ";
    danhSach1.xuatDanhSach();
    // Nhập 5 số nguyên vào danh sách 2
    cout << "Nhap 5 so nguyen cho danh sach 2: ";
    for (int i = 0; i < 5; i++) {
        cin >> so;
        danhSach2.themSo(so);
    }
    // Thêm danh sách 2 vào danh sách 1
    danhSach1.themDanhSach(danhSach2);
    // Xuất danh sách sau khi ghép
    cout << "Danh sach sau khi them danh sach 2: ";
    danhSach1.xuatDanhSach();
    danhSach1.xoaDanhSach();//Giải phóng bộ nhớ
    danhSach2.xoaDanhSach();
    return 0;
}
