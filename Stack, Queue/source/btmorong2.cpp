#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y;
    Node* next;
};

struct Stack {
    Node* top = nullptr;
    void push(int x, int y) {
        Node* newNode = new Node{ x, y, top };
        top = newNode;
    }
    void pop(int& x, int& y) {
        if (!top) {
            x = -1; y = -1;
            return;
        }
        Node* temp = top;
        x = temp->x;
        y = temp->y;
        top = top->next;
        delete temp;
    }
    bool empty() { return top == nullptr; }
};

struct Queue {
    Node* front = nullptr, * rear = nullptr;
    void push(int x, int y) {
        Node* newNode = new Node{ x, y, nullptr };
        if (!rear) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void pop(int& x, int& y) {
        if (!front) {
            x = -1; y = -1;
            return;
        }
        Node* temp = front;
        x = temp->x;
        y = temp->y;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    bool empty() { return front == nullptr; }
};

void inMeCung(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << (cell ? "# " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool bfsMeCung(vector<vector<int>>& maze, int N, int M, int x0, int y0, int x1, int y1) {
    Queue q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> parentX(N, vector<int>(M, -1));
    vector<vector<int>> parentY(N, vector<int>(M, -1));
    q.push(x0, y0);
    visited[x0][y0] = true;
    int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
    while (!q.empty()) {
        int x, y;
        q.pop(x, y);
        if (x == x1 && y == y1) {
            vector<int> pathX, pathY;
            while (x != -1 && y != -1) {
                pathX.push_back(x);
                pathY.push_back(y);
                int px = parentX[x][y];
                int py = parentY[x][y];
                x = px;
                y = py;
            }
            cout << "Duong di BFS:\n";
            for (int i = pathX.size() - 1; i >= 0; i--) {
                cout << pathX[i] << " " << pathY[i] << endl;
            }
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parentX[nx][ny] = x;
                parentY[nx][ny] = y;
                q.push(nx, ny);
            }
        }
    }
    return false;
}

bool dfsMeCung(vector<vector<int>>& maze, int N, int M, int x0, int y0, int x1, int y1) {
    Stack s;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> parentX(N, vector<int>(M, -1));
    vector<vector<int>> parentY(N, vector<int>(M, -1));
    s.push(x0, y0);
    visited[x0][y0] = true;
    int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
    while (!s.empty()) {
        int x, y;
        s.pop(x, y);
        if (x == x1 && y == y1) {
            vector<int> pathX, pathY;
            while (x != -1 && y != -1) {
                pathX.push_back(x);
                pathY.push_back(y);
                int px = parentX[x][y];
                int py = parentY[x][y];
                x = px;
                y = py;
            }
            cout << "Duong di DFS:\n";
            for (int i = pathX.size() - 1; i >= 0; i--) {
                cout << pathX[i] << " " << pathY[i] << endl;
            }
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parentX[nx][ny] = x;
                parentY[nx][ny] = y;
                s.push(nx, ny);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };
    int N = 4, M = 4, x0 = 0, y0 = 0, x1 = 3, y1 = 3;

    cout << "Me cung ban dau:\n";
    inMeCung(maze);

    if (!bfsMeCung(maze, N, M, x0, y0, x1, y1)) {
        cout << "Khong co duong di BFS" << endl;
    }

    if (!dfsMeCung(maze, N, M, x0, y0, x1, y1)) {
        cout << "Khong co duong di DFS" << endl;
    }

    return 0;
}