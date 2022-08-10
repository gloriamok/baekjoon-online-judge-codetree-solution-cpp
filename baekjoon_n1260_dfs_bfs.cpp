#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[1001];
queue<int> numqueue;

bool visited_dfs[1001]{}; // false로 초기화됨

void DFS(int x) {
    visited_dfs[x] = true; // 정점 x를 방문 후 방문했다고 표시
    cout << x << " "; // 방문된 점 출력
    for (int i = 0; i < edge[x].size(); i++) {
        int y = edge[x].at(i);
        if (!visited_dfs[y]) DFS(y); // y를 방문하지 않았다면 재귀
    }
}

void BFS(int v) {
    bool visited[1001]{}; // false로 초기화됨
    visited[v] = true; // 시작 정점 v를 방문 후 방문했다고 표시
    numqueue.push(v);
    cout << v << " "; // 방문된 점 출력

    while (!numqueue.empty()) {
        int front = numqueue.front();
        numqueue.pop();

        for (int r : edge[front]) {
            if (!visited[r]) { // r을 방문하지 않았다면
                numqueue.push(r);
                visited[r] = true; // r을 방문 후 방문했다고 표시
                cout << r << " "; // 방문된 점 출력
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v, x, y;
    cin >> n >> m >> v;

    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x); // 양방향이므로 ﻿간선 정보를 정점 x에만 추가하는 것이 아니라 y에도 추가
    }

    for (int i = 1; i <= n; i++)
        if (!edge[i].empty())
            sort(edge[i].begin(), edge[i].end()); // 정점 번호가 작은 것을 먼저 방문

    DFS(v);
    cout << "\n";
    BFS(v);
}