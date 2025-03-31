#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef struct {
    int top; // dinh ngan xep
    int count; // so phan tu
    int size; // kich thuoc toi da
    int* arr; // chua du lieu
} Stack;

void Init(Stack& s, int size) {
    s.top = -1;
    s.count = 0;
    s.size = size;
    s.arr = new int[s.size];
}

void Delete(Stack& s) {
    s.top = -1;
    s.count = 0;
    s.size = 0;
    delete[] s.arr;
}

bool IsEmpty(Stack& s) {
    return s.top == -1;
}

bool IsFull(Stack& s) {
    return s.top == s.size - 1;
}

void Push(Stack& s, int x) {
    if (IsFull(s)) {
        cout << "Stack bi tran (stack overflow)" << endl;
        return;
    }
    s.arr[++s.top] = x;
    s.count++;
}

int Pop(Stack& s) {
    if (IsEmpty(s)) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    int x = s.arr[s.top--];
    s.count--;
    return x;
}

int PeekStack(Stack& s) {
    if (IsEmpty(s)) return -1;
    return s.arr[s.top];
}

void Clear(Stack& s) {
    s.top = -1;
    s.count = 0;
}

// (b) Dao so nguyen
int DaoSo(int so) {
    bool isNegative = so < 0;
    if (isNegative) so = -so; // Lam viec voi gia tri tuyet doi

    Stack nganXep;
    Init(nganXep, 10);
    while (so > 0) {
        Push(nganXep, so % 10);
        so /= 10;
    }

    int soDao = 0, heSo = 1;
    while (!IsEmpty(nganXep)) {
        soDao += Pop(nganXep) * heSo;
        heSo *= 10;
    }
    Delete(nganXep);

    return isNegative ? -soDao : soDao; // Neu la so am, them lai dau "-"
}


// (c) Kiem tra xau doi xung
bool KiemTraDoiXung(string xau) {
    Stack nganXep;
    Init(nganXep, xau.length());
    for (char c : xau) Push(nganXep, c);
    for (char c : xau) {
        if (c != Pop(nganXep)) {
            Delete(nganXep);
            return false;
        }
    }
    Delete(nganXep);
    return true;
}

// (d) Chuyen doi so thap phan sang nhi phan
string ThapPhanSangNhiPhan(int so) {
    Stack nganXep;
    Init(nganXep, 32);
    while (so > 0) {
        Push(nganXep, so % 2);
        so /= 2;
    }
    string nhiPhan = "";
    while (!IsEmpty(nganXep)) {
        nhiPhan += to_string(Pop(nganXep));
    }
    Delete(nganXep);
    return nhiPhan;
}

int main() {
    Stack s;
    Init(s, 5);
    cout << "Dao so -12345: " << DaoSo(-12345) << endl;
    cout << "Dao so 67890: " << DaoSo(67890) << endl;
	cout << "Dao so 0: " << DaoSo(0) << endl;
    cout << "Kiem tra xau 'madam' co doi xung: ";
	if (KiemTraDoiXung("madam")) cout << "Co" << endl;
	else cout << "Khong" << endl;
	cout << "Kiem tra xau 'hello' co doi xung: ";
	if (KiemTraDoiXung("hello")) cout << "Co" << endl;
	else cout << "Khong" << endl;
    cout << "So 25 sang nhi phan: " << ThapPhanSangNhiPhan(25) << endl;
    Delete(s);
    return 0;
}
