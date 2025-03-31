#include <iostream>
#include <stack>

using namespace std;

// (a) Fibonacci bang de quy
int fibonacciDeQuy(int n) {
    if (n <= 1) return n;
    return fibonacciDeQuy(n - 1) + fibonacciDeQuy(n - 2);
}

// Fibonacci khong de quy (dung stack)
int fibonacciStack(int n) {
    if (n <= 1) return n;
    stack<int> s;
    s.push(n);
    int a = 0, b = 1;
    while (!s.empty()) {
        int num = s.top(); s.pop();
        if (num == 1) return b;
        if (num == 0) return a;
        s.push(num - 1);
        s.push(num - 2);
    }
    return 0;
}

// (b) Dao nguoc so bang de quy
int daoNguocSoDeQuy(int n, int rev = 0) {
    if (n == 0) return rev;
    return daoNguocSoDeQuy(n / 10, rev * 10 + n % 10);
}

// Dao nguoc so khong de quy (dung stack)
int daoNguocSoStack(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int reversed = 0, factor = 1;
    while (!s.empty()) {
        reversed += s.top() * factor;
        s.pop();
        factor *= 10;
    }
    return reversed;
}

// (c) Thap Ha Noi bang de quy
void hanoiDeQuy(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoiDeQuy(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoiDeQuy(n - 1, aux, to, from);
}

int main() {
    int n = 5;
    cout << "Fibonacci (de quy) cua " << n << ": " << fibonacciDeQuy(n) << endl;
    cout << "Fibonacci (stack) cua " << n << ": " << fibonacciStack(n) << endl;

    int num = 1234;
    cout << "Dao nguoc (de quy) cua " << num << ": " << daoNguocSoDeQuy(num) << endl;
    cout << "Dao nguoc (stack) cua " << num << ": " << daoNguocSoStack(num) << endl;

    int disks = 3;
    cout << "Thap Ha Noi (de quy) voi " << disks << " dia:" << endl;
    hanoiDeQuy(disks, 'A', 'C', 'B');

    return 0;
}
