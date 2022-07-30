#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[100001];
queue<int> numqueue;

void BFS(int n, int r) {
    int order = 1; // 방문 순서에 1을 넣어줌
    int visited[100001]{}; // 0으로 초기화
    visited[r] = order++; // r을 방문 후 해당 배열 원소에 방문순서 order를 넣고 order에 1 더해줌 (﻿시작 정점의 방문 순서는 1)
    numqueue.push(r);
    while (!numqueue.empty()) {
        int front = numqueue.front();
        numqueue.pop();

        for (int v : edge[front]) {
            if (visited[v] == 0) { v를 방문하지 않았다면
                numqueue.push(v);
                visited[v] = order++; v를 방문 후 방문순서를 넣음
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << visited[i] << "\n"; // 노드의 방문순서 출력
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, u, v;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edge[u].push_back(v); // 양방향이므로 ﻿간선 정보를 정점 u에만 추가하는 것이 아니라 v에도 추가
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (!edge[i].empty())
            sort(edge[i].begin(), edge[i].end(), greater<>());

    BFS(n, r);
}
