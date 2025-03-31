#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Cấu trúc nhân viên
struct NhanVien {
    char MaSo[11];  // Mã số (tối đa 10 ký tự)
    char Ho[11];    // Họ lót (tối đa 10 ký tự)
    char Ten[51];   // Tên (tối đa 50 ký tự)
    int Phai;       // 0: Nữ, 1: Nam
    int ThamNien;   // Số năm làm việc (≥ 0)
};

// Cấu trúc phòng ban
struct PhongBan {
    NhanVien aNhanVien[100]; // Danh sách nhân viên
    int SoLuong;             // Số lượng nhân viên
};

// Hàm nhập danh sách nhân viên
void NhapPhongBan(PhongBan& pb) {
    cout << "Nhap so luong nhan vien: ";
    cin >> pb.SoLuong;

    if (pb.SoLuong <= 0 || pb.SoLuong > 100) {
        cout << "So luong khong hop le!" << endl;
        return;
    }

    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "\nNhap thong tin nhan vien " << i + 1 << ":" << endl;

        cout << "Ma so: ";
        cin >> ws; // Loại bỏ khoảng trắng thừa
        cin.getline(pb.aNhanVien[i].MaSo, 11);

        cout << "Ho lot: ";
        cin.getline(pb.aNhanVien[i].Ho, 11);

        cout << "Ten: ";
        cin.getline(pb.aNhanVien[i].Ten, 51);

        do {
            cout << "Phai (0 - Nu, 1 - Nam): ";
            cin >> pb.aNhanVien[i].Phai;
        } while (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1);

        do {
            cout << "So nam lam viec: ";
            cin >> pb.aNhanVien[i].ThamNien;
        } while (pb.aNhanVien[i].ThamNien < 0);
    }
}

// Hàm xuất danh sách nhân viên
void XuatPhongBan(PhongBan pb) {
    cout << "\nDanh sach nhan vien trong phong ban:\n";
    cout << left << setw(12) << "Ma So"
        << setw(12) << "Ho"
        << setw(15) << "Ten"
        << setw(8) << "Phai"
        << setw(10) << "Tham Nien" << endl;

    for (int i = 0; i < pb.SoLuong; i++) {
        cout << left << setw(12) << pb.aNhanVien[i].MaSo
            << setw(12) << pb.aNhanVien[i].Ho
            << setw(15) << pb.aNhanVien[i].Ten
            << setw(8) << (pb.aNhanVien[i].Phai == 1 ? "Nam" : "Nu")
            << setw(10) << pb.aNhanVien[i].ThamNien << endl;
    }
}

// Hàm đếm sĩ số nam, nữ
void DemSiSo(PhongBan pb, int& sonam, int& sonu) {
    sonam = 0;
    sonu = 0;
    for (int i = 0; i < pb.SoLuong; i++) {
        if (pb.aNhanVien[i].Phai == 1) {
            sonam++;
        }
        else {
            sonu++;
        }
    }
}

// Hàm sắp xếp danh sách nhân viên tăng dần theo thâm niên
void SapXepTangTheoThamNien(PhongBan& pb) {
    for (int i = 0; i < pb.SoLuong - 1; i++) {
        for (int j = i + 1; j < pb.SoLuong; j++) {
            if (pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
                swap(pb.aNhanVien[i], pb.aNhanVien[j]);
            }
        }
    }
}

// Hàm main
int main() {
    PhongBan pb;
    int sonam, sonu;

    // Nhập danh sách nhân viên
    NhapPhongBan(pb);

    // Xuất danh sách nhân viên
    XuatPhongBan(pb);

    // Đếm sĩ số nam, nữ
    DemSiSo(pb, sonam, sonu);
    cout << "\nSi so nhan vien: " << endl;
    cout << "- Nam: " << sonam << endl;
    cout << "- Nu: " << sonu << endl;

    // Sắp xếp danh sách theo thâm niên
    SapXepTangTheoThamNien(pb);
    cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo tham nien:\n";
    XuatPhongBan(pb);

    return 0;
}
