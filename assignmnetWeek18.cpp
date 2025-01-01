#include <iostream>

using namespace std;

const int MAX = 100;

int adjMatrix[MAX][MAX];
int n;

int adjList[MAX][MAX];
int listSize[MAX];

void inputAdjMatrix() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
}

void inputAdjList() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v, index = 0;
        while (true) {
            cin >> v;
            if (v == -1) break;
            adjList[i][index++] = v;
        }
        listSize[i] = index;
    }
}

void BFSMatrix(int start) {
    bool visited[MAX] = { false };
    int queue[MAX], front = 0, back = 0;

    cout << "BFS (Ma tran lan can): ";
    queue[back++] = start;
    visited[start] = true;

    while (front < back) {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] && !visited[v]) {
                queue[back++] = v;
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

void DFSMatrix(int start) {
    bool visited[MAX] = { false };
    int stack[MAX], top = -1;

    cout << "DFS (Ma tran lan can): ";
    stack[++top] = start;

    while (top >= 0) {
        int u = stack[top--];

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }

        for (int v = n - 1; v >= 0; --v) {
            if (adjMatrix[u][v] && !visited[v]) {
                stack[++top] = v;
            }
        }
    }
    cout << endl;
}

void BFSList(int start) {
    bool visited[MAX] = { false };
    int queue[MAX], front = 0, back = 0;

    cout << "BFS (Danh sach lan can): ";
    queue[back++] = start;
    visited[start] = true;

    while (front < back) {
        int u = queue[front++];
        cout << u << " ";

        for (int i = 0; i < listSize[u]; ++i) {
            int v = adjList[u][i];
            if (!visited[v]) {
                queue[back++] = v;
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

void DFSList(int start) {
    bool visited[MAX] = { false };
    int stack[MAX], top = -1;

    cout << "DFS (Danh sach lan can): ";
    stack[++top] = start;

    while (top >= 0) {
        int u = stack[top--];

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }

        for (int i = listSize[u] - 1; i >= 0; --i) {
            int v = adjList[u][i];
            if (!visited[v]) {
                stack[++top] = v;
            }
        }
    }
    cout << endl;
}

int main() {
    int choice;
    cin >> choice;

    if (choice == 1) {
        inputAdjMatrix();
        int start;
        cin >> start;
        BFSMatrix(start);
        DFSMatrix(start);
    }
    else if (choice == 2) {
        inputAdjList();
        int start;
        cin >> start;
        BFSList(start);
        DFSList(start);
    }
    else {
        cout << "Lua chon khong hop le!\n";
    }

    return 0;
}