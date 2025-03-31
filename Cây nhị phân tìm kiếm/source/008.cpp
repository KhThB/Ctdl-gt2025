#include<iostream>
#include<fstream>
using namespace std;

struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
TREE root = NULL;

void Init(TREE& Root) {
    Root = NULL;
}

NODE* CreateNode(float x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Insert(TREE& p, float theKey) {
    if (p == NULL) {
        p = CreateNode(theKey);
    }
    else if (p->info > theKey) {
        Insert(p->pLeft, theKey);
    }
    else if (p->info < theKey) {
        Insert(p->pRight, theKey);
    }
}

void InOrder(TREE Root) {
    if (Root != NULL) {
        InOrder(Root->pLeft);
        cout << Root->info << " ";
        InOrder(Root->pRight);
    }
}

void LNR(TREE t, FILE* fp) {
    if (t == NULL)
        return;
    LNR(t->pLeft, fp);
    fwrite(&t->info, sizeof(float), 1, fp);
    LNR(t->pRight, fp);
}

int Xuat(const char* filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
        return 0;
    LNR(t, fp);
    fclose(fp);
    return 1;
}

void DocFile(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    float value;
    cout << "Cac gia tri trong file: ";
    while (fread(&value, sizeof(float), 1, fp)) {
        cout << value << " ";
    }
    cout << endl;
    fclose(fp);
}

int main() {
    TREE Root;
    Init(Root);
    float arr[] = { 10.5, 5.2, 15.8, 3.1, 7.4, 9.6, 12.3, 18.9, 20.0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        Insert(Root, arr[i]);
    }

    cout << "Cay: ";
    InOrder(Root);
    cout << endl;

    if (Xuat("data.out", Root)) {
        cout << "Da xuat cay vao file data.out thanh cong!" << endl;
    }
    else {
        cout << "Xuat file that bai!" << endl;
    }

    DocFile("data.out");

    return 0;
}