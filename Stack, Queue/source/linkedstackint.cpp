#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;
    int count;
};

void Init(LinkedStack& s) {
    s.top = nullptr;
    s.count = 0;
}

void Delete(LinkedStack& s) {
    while (s.top) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
    s.count = 0;
}

bool IsEmpty(LinkedStack& s) {
    return s.top == nullptr;
}

void Push(LinkedStack& s, int x) {
    Node* newNode = new Node{ x, s.top };
    s.top = newNode;
    s.count++;
}

int Pop(LinkedStack& s) {
    if (IsEmpty(s)) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    int x = s.top->data;
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.count--;
    return x;
}

int PeekStack(LinkedStack& s) {
    if (IsEmpty(s)) return -1;
    return s.top->data;
}

void Clear(LinkedStack& s) {
    Delete(s);
}

// (b) Dao so nguyen
int DaoSo(int so) {
    bool isNegative = so < 0;
    if (isNegative) so = -so;

    LinkedStack nganXep;
    Init(nganXep);
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

    return isNegative ? -soDao : soDao;
}

// (c) Kiem tra xau doi xung
bool KiemTraDoiXung(string xau) {
    LinkedStack nganXep;
    Init(nganXep);
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
    LinkedStack nganXep;
    Init(nganXep);
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
    LinkedStack s;
    Init(s);
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
