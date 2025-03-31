#include<iostream>
using namespace std;

struct node {
    int info;
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

NODE* NhoNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pLeft)
        lc = lc->pLeft;
    return lc;
}

NODE* LonNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pRight)
        lc = lc->pRight;
    return lc;
}

int main() {
    TREE Root;
    Init(Root);
    int arr[] = { 10, 5, 15, 3, 7, 9, 12, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        Insert(Root, arr[i]);
    }

    cout << "Cay: ";
    InOrder(Root);
    cout << endl;

    NODE* minNode = NhoNhat(Root);
    NODE* maxNode = LonNhat(Root);

    if (minNode) cout << "Phan tu nho nhat: " << minNode->info << endl;
    if (maxNode) cout << "Phan tu lon nhat: " << maxNode->info << endl;

    return 0;
}
