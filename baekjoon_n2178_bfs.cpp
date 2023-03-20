#include <iostream>
#include <queue>
using namespace std;

int n, m, maze[100][100]{};
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
	queue<pair <int, int> > q;
	q.push({x, y});
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1) {
				q.push({ nx, ny });
				maze[nx][ny] = maze[x][y] + 1; // 이동한 칸의 수 표시, 이전 칸 + 1
			}
		}
	}
	return maze[n - 1][m - 1];
}

int main() {
	char c;
	cin >> n >> m;
	for (int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> c;
			maze[i][j] = c - '0'; // char을 int로 바꾼다 '0' -> 0
		}
	cout << bfs(0, 0);
}