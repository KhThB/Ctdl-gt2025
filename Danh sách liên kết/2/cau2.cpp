#include <iostream>
#include <cstring>
using namespace std;
typedef struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
} SinhVien;
struct ListSV {
    SinhVien* head;
    // Khởi tạo danh sách rỗng
    ListSV() { head = NULL; }
    // Hàm nhập một sinh viên
    void nhapSV(SinhVien& sv) {
        cout << "Nhap ho ten: ";
        cin.getline(sv.hoTen, 50);
        cout << "\nNhap dia chi: ";
        cin.getline(sv.diaChi, 70);
        cout << "\nNhap lop: ";
        cin.getline(sv.lop, 10);
        cout << "\nNhap khoa: ";
        cin >> sv.khoa;
    }
    // Hàm xuất một sinh viên
    void xuatSV(SinhVien* sv) {
        cout << "\nHo ten: " << sv->hoTen << " Dia chi: " << sv->diaChi
            << " Lop: " << sv->lop << " Khoa: " << sv->khoa << endl;
    }
    // Thêm sinh viên vào danh sách
    void themSV(const char* ten, const char* diachi, const char* lop, int khoa) {
        SinhVien* p = new SinhVien;
		strcpy(p->hoTen, ten); //Hàm sao chép chuỗi
        strcpy(p->diaChi, diachi);
        strcpy(p->lop, lop);
        p->khoa = khoa;
        p->next = NULL;
        if (head == NULL) {
            head = p;
        }
        else {
            SinhVien* q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    // Xuất danh sách sinh viên
    void xuatDanhSach() {
        SinhVien* p = head;
        while (p) {
            xuatSV(p);
            p = p->next;
        }
        cout << endl;
    }
    // Xóa sinh viên theo tên
    void xoaSVTheoTen(const char* ten) {
        while (head && strcmp(head->hoTen, ten) == 0) {
            SinhVien* p = head;
            head = head->next;
            delete p;
        }
        SinhVien* p = head;
        while (p && p->next) {
            if (strcmp(p->next->hoTen, ten) == 0) {
                SinhVien* nodeCanXoa = p->next;
                p->next = p->next->next;
                delete nodeCanXoa;
            }
            else {
                p = p->next;
            }
        }
    }
    // Xóa sinh viên theo địa chỉ
    void xoaSVTheoDiaChi(const char* diachi) {
        while (head && strcmp(head->diaChi, diachi) == 0) {
            SinhVien* p = head;
            head = head->next;
            delete p;
        }
        SinhVien* p = head;
        while (p && p->next) {
            if (strcmp(p->next->diaChi, diachi) == 0) {
                SinhVien* nodeCanXoa = p->next;
                p->next = p->next->next;
                delete nodeCanXoa;
            }
            else {
                p = p->next;
            }
        }
    }
    // Hàm so sánh theo tên
    bool soSanhTheoTen(SinhVien* a, SinhVien* b) {
        return strcmp(a->hoTen, b->hoTen) < 0;
    }
    // Hàm so sánh theo địa chỉ
    bool soSanhTheoDiaChi(SinhVien* a, SinhVien* b) {
        return strcmp(a->diaChi, b->diaChi) < 0;
    }
    // Hàm so sánh theo lớp
    bool soSanhTheoLop(SinhVien* a, SinhVien* b) {
        return strcmp(a->lop, b->lop) < 0;
    }
    // Hàm so sánh theo khóa
    bool soSanhTheoKhoa(SinhVien* a, SinhVien* b) {
        return a->khoa < b->khoa;
    }
    // Sắp xếp danh sách bằng selection sort
    void sapXep(bool (ListSV::* cmp)(SinhVien*, SinhVien*)) {
        for (SinhVien* p = head; p != NULL; p = p->next) {
            SinhVien* min = p;
            for (SinhVien* q = p->next; q != NULL; q = q->next) {
                if ((this->*cmp)(q, min)) {
                    min = q;
                }
            }
            if (min != p) {
                swap(*p, *min);
                swap(p->next, min->next);  // Giữ nguyên liên kết
            }
        }
    }
    // Giải phóng bộ nhớ danh sách
    void xoaDanhSach() {
        while (head) {
            SinhVien* p = head;
            head = head->next;
            delete p;
        }
    }
};
    int main() {
        ListSV danhSach;
        // Thêm 10 sinh viên vào danh sách
        danhSach.themSV("Nguyen Van A", "Nguyen Van Cu", "DCTC1", 2020);
        danhSach.themSV("Nguyen Van Teo", "Le Loi", "DCTC2", 2021);
        danhSach.themSV("Tran Thi B", "Nguyen Van Cu", "DCTC3", 2019);
        danhSach.themSV("Le Thi C", "Tran Hung Dao", "DCTC6", 2022);
        danhSach.themSV("Pham Van D", "Hai Ba Trung", "DCTC4", 2023);
        danhSach.themSV("Bui Van E", "Hoang Dieu", "DCTC8", 2018);
        danhSach.themSV("Nguyen Van F", "Vo Thi Sau", "DCTC9", 2017);
        danhSach.themSV("Nguyen Van G", "Bach Dang", "DCTC5", 2016);
        danhSach.themSV("Tran Van H", "Nguyen Trai", "DCTC0", 2015);
        danhSach.themSV("Le Van I", "Le Lai", "DCTC7", 2014);
        // Xuất danh sách sinh viên
        cout << "Danh sach sinh vien ban dau:\n";
        danhSach.xuatDanhSach();
		cout << "Xoa sinh vien theo ten va dia chi\n";
        danhSach.xoaSVTheoTen("Nguyen Van Teo");
        danhSach.xoaSVTheoDiaChi("Nguyen Van Cu");
        danhSach.xuatDanhSach();
		cout << "Them sinh vien\n";
        danhSach.themSV("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009);
        cout << "Danh sach sau khi them sinh vien moi:\n";
        danhSach.xuatDanhSach();
        // Sắp xếp danh sách theo tên
		cout << "Sap xep theo ten:\n";
        danhSach.sapXep(&ListSV::soSanhTheoTen);
        danhSach.xuatDanhSach();
        // Giải phóng bộ nhớ
        danhSach.xoaDanhSach();
        return 0;
    }
