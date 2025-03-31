#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa QueueInt (hàng đợi dùng mảng)
struct QueueInt {
    int front, rear, count, size;
    string* arr;

    // Hàm khởi tạo hàng đợi
    void Init(int sz = 100) {
        front = rear = -1;
        count = 0;
        size = sz;
        arr = new string[size];
    }

    // Kiểm tra hàng đợi rỗng
    bool IsEmpty() { return count == 0; }

    // Kiểm tra hàng đợi đầy
    bool IsFull() { return count == size; }

    // Thêm phần tử vào hàng đợi
    void Enqueue(string value) {
        if (IsFull()) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
    }

    // Lấy phần tử ra khỏi hàng đợi
    string Dequeue() {
        if (IsEmpty()) return "";
        string value = arr[front];
        front = (front + 1) % size;
        count--;
        if (count == 0) front = rear = -1;
        return value;
    }

    // Hiển thị hàng đợi
    void Show(string label) {
        cout << label << ": ";
        for (int i = front, j = 0; j < count; j++, i = (i + 1) % size)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Xếp lịch cặp múa nam/nữ
void FormLines(QueueInt& male, QueueInt& female) {
    string dancers[] = {
        "F Trang", "M Truc", "M Thien", "M Bao", "F Thu",
        "M Tien", "F Thuy", "M Nghia", "F Thao", "M Phuoc",
        "M Hung", "F Vy"
    };
    int n = 12;

    for (int i = 0; i < n; i++) {
        if (dancers[i][0] == 'M')
            male.Enqueue(dancers[i].substr(2)); // Bỏ "M "
        else
            female.Enqueue(dancers[i].substr(2)); // Bỏ "F "
    }
}

// Ghép cặp vũ công
void StartDancing(QueueInt& male, QueueInt& female) {
    cout << "Cac cap dien vien:\n";
    int pairs = 4; // Số cặp có thể nhảy đồng thời

    for (int i = 0; i < pairs; i++) {
        if (!male.IsEmpty() && !female.IsEmpty())
            cout << male.Dequeue() << " - " << female.Dequeue() << endl;
        else
            break;
    }
}

// Hiển thị người tiếp theo
void HeadOfLine(QueueInt& male, QueueInt& female) {
    if (!male.IsEmpty() && !female.IsEmpty())
        cout << "Cap dien vien ke tiep: " << male.arr[male.front] << " - " << female.arr[female.front] << endl;
    else if (!male.IsEmpty())
        cout << "Dien vien nam ke tiep: " << male.arr[male.front] << endl;
    else if (!female.IsEmpty())
        cout << "Dien vien nu ke tiep: " << female.arr[female.front] << endl;
}

// Định nghĩa QueueInt cho Radix Sort (hàng đợi số nguyên)
struct RadixQueue {
    int front, rear, count, size;
    int* arr;

    // Khởi tạo hàng đợi
    void Init(int sz = 100) {
        front = rear = -1;
        count = 0;
        size = sz;
        arr = new int[size];
    }

    bool IsEmpty() { return count == 0; }

    void Enqueue(int value) {
        if (count == size) return;
        rear = (rear + 1) % size;
        arr[rear] = value;
        if (front == -1) front = 0;
        count++;
    }

    int Dequeue() {
        if (IsEmpty()) return -1;
        int value = arr[front];
        front = (front + 1) % size;
        count--;
        return value;
    }
};

// Thuật toán Radix Sort
void RadixSort(vector<int>& arr) {
    RadixQueue buckets[10]; // 10 hàng đợi (0-9)
    for (int i = 0; i < 10; i++) buckets[i].Init(arr.size());

    int maxValue = *max_element(arr.begin(), arr.end());
    int exp = 1;

    while (maxValue / exp > 0) {
        for (int num : arr) {
            int bucketIndex = (num / exp) % 10;
            buckets[bucketIndex].Enqueue(num);
        }

        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!buckets[i].IsEmpty())
                arr[index++] = buckets[i].Dequeue();
        }
        exp *= 10;
    }
}

// Chương trình chính
int main() {
    // **Bài toán xếp lịch cặp múa nam/nữ**
    cout << "\n=== Bai toan xep lich cap mua nam/nu ===\n";
    QueueInt males, females;
    males.Init(10);
    females.Init(10);

    FormLines(males, females);

    males.Show("Danh sach dien vien nam");
    females.Show("Danh sach dien vien nu");

    StartDancing(males, females);

    if (!males.IsEmpty() || !females.IsEmpty()) {
        HeadOfLine(males, females);
        StartDancing(males, females);
    }

    // **Bài toán Radix Sort**
    cout << "\n=== Bai toan Radix Sort ===\n";
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    cout << "Mang truoc khi sap xep: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    RadixSort(arr);

    cout << "Mang sau khi sap xep: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
