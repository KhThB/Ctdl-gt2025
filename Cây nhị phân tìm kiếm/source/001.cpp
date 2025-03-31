#include<iostream>
using namespace std;

struct node {
    int info;
    int count;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
TREE root = NULL;

void Init(TREE& Root) {
    Root = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->count = 1;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Insert(TREE& p, int theKey) {
    if (p == NULL) {
        p = CreateNode(theKey);
    }
    else if (p->info > theKey) {
        Insert(p->pLeft, theKey);
    }
    else if (p->info == theKey) {
        p->count = p->count + 1;
    }
    else {
        Insert(p->pRight, theKey);
    }
}

int DemNode(TREE Root) {
    if (Root == NULL) return 0;
    int a = DemNode(Root->pLeft);
    int b = DemNode(Root->pRight);
    return (a + b + 1);
}

int TongNode(TREE Root) {
    if (Root == NULL) return 0;
    int a = TongNode(Root->pLeft);
    int b = TongNode(Root->pRight);
    return (a + b + Root->info);
}

float TrungBinhCong(TREE Root) {
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if (dem == 0) return 0;
    return (float)s / dem;
}

int DemDuong(TREE Root) {
    if (Root == NULL) return 0;
    int a = DemDuong(Root->pLeft);
    int b = DemDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + 1);
    return (a + b);
}

int TongDuong(TREE Root) {
    if (Root == NULL) return 0;
    int a = TongDuong(Root->pLeft);
    int b = TongDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + Root->info);
    return (a + b);
}

float TrungBinhDuong(TREE Root) {
    int s = TongDuong(Root);
    int dem = DemDuong(Root);
    if (dem == 0) return 0;
    return (float)s / dem;
}

int TongAm(TREE Root) {
    if (Root == NULL) return 0;
    int a = TongAm(Root->pLeft);
    int b = TongAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + Root->info);
    return (a + b);
}

int DemAm(TREE Root) {
    if (Root == NULL) return 0;
    int a = DemAm(Root->pLeft);
    int b = DemAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + 1);
    return (a + b);
}

float TrungBinhCongAm(TREE Root) {
    int s = TongAm(Root);
    int dem = DemAm(Root);
    if (dem == 0) return 0;
    return (float)s / dem;
}

float TinhTySo(TREE Root) {
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if (b == 0) return 0;
    return (float)a / b;
}

int main() {
    TREE Root;
    Init(Root);
    int arr[] = { 10, -5, 15, -10, 0, 20, -3, 7, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        Insert(Root, arr[i]);
    }

    cout << "Trung binh cong cac nut: " << TrungBinhCong(Root) << endl;
    cout << "Trung binh cong cac nut duong: " << TrungBinhDuong(Root) << endl;
    cout << "Trung binh cong cac nut am: " << TrungBinhCongAm(Root) << endl;
    cout << "Ti so R = a / b: " << TinhTySo(Root) << endl;

    return 0;
}
