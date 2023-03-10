#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[101];
queue<int> q;

void BFS(int r) {
	bool visited[101]{}; // 모든 원소를 false로 초기화
	q.push(r); // 시작정점 r을 queue에 넣음
	visited[r] = true; // c이 바이러스에 걸렸다고 표시
	int count = 0, front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int c : edge[front]) {
			if (!visited[c]) { // c를 방문하지 않았다면
				q.push(c);
				visited[c] = true; // c가 이미 바이러스에 걸렸다고 표시
				count++; // ﻿바이러스에 걸린 컴퓨터의 개수를 증가시킴
			}
		}
	}
	cout << count;
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u); // 양방향 그래프이므로 간선 정보를 정점 v에도 넣어줘야 함
	}

	BFS(1); // ﻿1번 컴퓨터부터 바이러스가 시작됨
}
