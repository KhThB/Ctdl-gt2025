#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Cấu trúc loại hoa
struct LoaiHoa {
    char Ten[30];   // Tên loại hoa
    int SoLuong;    // Số lượng tồn kho
    char DVT[10];   // Đơn vị tính
    double DonGia;  // Đơn giá bán
};

// Cấu trúc danh sách loại hoa
struct DanhSachLoaiHoa {
    LoaiHoa dsHoa[20]; // Tối đa 20 loại hoa
    int SoLuong;       // Số loại hoa hiện có trong cửa hàng
};

// Hàm nhập danh sách loại hoa
void NhapDanhSach(DanhSachLoaiHoa& ds) {
    cout << "Nhap so loai hoa: ";
    cin >> ds.SoLuong;

    if (ds.SoLuong <= 0 || ds.SoLuong > 20) {
        cout << "So luong khong hop le!" << endl;
        return;
    }

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "\nNhap thong tin loai hoa " << i + 1 << ":" << endl;

        cout << "Ten loai: ";
        cin >> ws; // Loại bỏ khoảng trắng thừa
        cin.getline(ds.dsHoa[i].Ten, 30);

        cout << "So luong: ";
        cin >> ds.dsHoa[i].SoLuong;

        cout << "Don vi tinh: ";
        cin >> ws;
        cin.getline(ds.dsHoa[i].DVT, 10);

        cout << "Don gia: ";
        cin >> ds.dsHoa[i].DonGia;
    }
}

// Hàm xuất danh sách loại hoa
void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "\nDanh sach loai hoa trong cua hang:\n";
    cout << left << setw(25) << "Ten loai"
        << setw(12) << "So luong"
        << setw(12) << "DVT"
        << setw(10) << "Don gia" << endl;

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << left << setw(25) << ds.dsHoa[i].Ten
            << setw(12) << ds.dsHoa[i].SoLuong
            << setw(12) << ds.dsHoa[i].DVT
            << setw(10) << ds.dsHoa[i].DonGia << endl;
    }
}

// Hàm tìm loại hoa theo tên, trả về vị trí nếu có, -1 nếu không
int TimLoaiHoa(DanhSachLoaiHoa ds, char* tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.dsHoa[i].Ten, tenloai) == 0) {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm xử lý bán hoa
void XuLyBanHoa(DanhSachLoaiHoa& ds, char* tenloai, int soluong) {
    int index = TimLoaiHoa(ds, tenloai);

    if (index == -1) {
        cout << "Loai hoa \"" << tenloai << "\" khong ton tai trong cua hang." << endl;
        return;
    }

    if (ds.dsHoa[index].SoLuong < soluong) {
        cout << "Khong du so luong \"" << tenloai << "\" de ban." << endl;
    }
    else {
        double tongtien = soluong * ds.dsHoa[index].DonGia;
        ds.dsHoa[index].SoLuong -= soluong; // Cập nhật lại số lượng tồn kho
        cout << "Ban thanh cong " << soluong << " " << ds.dsHoa[index].DVT << " \""
            << tenloai << "\" voi gia: " << tongtien << " VND" << endl;
    }
}

// Hàm main
int main() {
    DanhSachLoaiHoa ds;
    char tenloai[30];
    int soluong;

    // Nhập danh sách hoa
    NhapDanhSach(ds);

    // Xuất danh sách hoa
    XuatDanhSach(ds);

    // Xử lý bán hoa
    cout << "\nNhap ten loai hoa can mua: ";
    cin >> ws;
    cin.getline(tenloai, 30);

    cout << "Nhap so luong can mua: ";
    cin >> soluong;

    XuLyBanHoa(ds, tenloai, soluong);

    // Xuất lại danh sách sau khi bán
    XuatDanhSach(ds);

    return 0;
}
