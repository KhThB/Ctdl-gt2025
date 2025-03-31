#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc Node cho danh sách liên kết
struct Node {
    string data;
    Node* next;
};

// Cấu trúc LinkedQueueInt (hàng đợi sử dụng danh sách liên kết)
struct LinkedQueueInt {
    Node* front;
    Node* rear;
    int count;

    // Khởi tạo hàng đợi
    void Init() {
        front = rear = nullptr;
        count = 0;
    }

    // Kiểm tra hàng đợi rỗng
    bool IsEmpty() {
        return count == 0;
    }

    // Thêm phần tử vào hàng đợi
    void Enqueue(string value) {
        Node* newNode = new Node{ value, nullptr };
        if (IsEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Lấy phần tử ra khỏi hàng đợi
    string Dequeue() {
        if (IsEmpty()) return "";
        Node* temp = front;
        string value = front->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        count--;
        return value;
    }

    // Hiển thị hàng đợi
    void Show(string label) {
        cout << label << ": ";
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Xếp lịch cặp múa nam/nữ
void FormLines(LinkedQueueInt& male, LinkedQueueInt& female) {
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
void StartDancing(LinkedQueueInt& male, LinkedQueueInt& female) {
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
void HeadOfLine(LinkedQueueInt& male, LinkedQueueInt& female) {
    if (!male.IsEmpty() && !female.IsEmpty())
        cout << "Cap dien vien ke tiep: " << male.front->data << " - " << female.front->data << endl;
    else if (!male.IsEmpty())
        cout << "Dien vien nam ke tiep: " << male.front->data << endl;
    else if (!female.IsEmpty())
        cout << "Dien vien nu ke tiep: " << female.front->data << endl;
}

// Cấu trúc LinkedQueueInt cho Radix Sort (hàng đợi số nguyên)
struct RadixQueue {
    struct IntNode {
        int data;
        IntNode* next;
    };

    IntNode* front;
    IntNode* rear;
    int count;

    void Init() {
        front = rear = nullptr;
        count = 0;
    }

    bool IsEmpty() { return count == 0; }

    void Enqueue(int value) {
        IntNode* newNode = new IntNode{ value, nullptr };
        if (IsEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int Dequeue() {
        if (IsEmpty()) return -1;
        IntNode* temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        count--;
        return value;
    }
};

// Thuật toán Radix Sort sử dụng hàng đợi liên kết
void RadixSort(vector<int>& arr) {
    RadixQueue buckets[10]; // 10 hàng đợi (0-9)
    for (int i = 0; i < 10; i++) buckets[i].Init();

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
    LinkedQueueInt males, females;
    males.Init();
    females.Init();

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
