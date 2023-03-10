#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, paper[100][100]{}, visited[100][100]{}, area; // area는 직사각형 내부를 제외한 나머지 부분에서 분리된 영역의 넓이
vector<int> totalArea;

void DFS(int y, int x) {
	visited[y][x]++;
	area++;
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	for (int k = 0; k <= 3; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !paper[ny][nx] && !visited[ny][nx]) DFS(ny, nx);
	}
}

int main() {
	int k, x1, x2, y1, y2, cnt = 0; // cnt는 직사각형 내부를 제외한 나머지 부분에서 분리된 영역의 개수
	cin >> m >> n >> k; // m*n 크기의 모눈종이, k개의 직사각형
	for (int i=1;i<=k;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++) paper[i][j]++; // 직사각형의 좌표를 넣음
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!paper[i][j] && !visited[i][j]) { // 직사각형 내부를 제외한 나머지 부분일 때 & 방문한 곳이 아닐 때
				cnt++;
				area = 0;
				DFS(i, j);
				totalArea.push_back(area); // DFS를 통해 나온 area를 totalArea에 넣음
			}
	cout << cnt << "\n";
	sort(totalArea.begin(), totalArea.end()); // ﻿각 영역의 넓이를 오름차순으로 정렬
	for (int k = 0; k < totalArea.size(); k++) cout << totalArea.at(k) << " ";
}
