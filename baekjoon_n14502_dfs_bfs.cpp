#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, lab[8][8]{};
int maxSafePlace = 0; // 안전 영역의 최대 크기
int zero = 0; // 빈 칸의 수
vector<pair<int, int>> virus; // 바이러스 위치
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int bfs() {
	int safePlace = zero;
	bool visited[8][8]{};
	queue<pair<int, int>> q;
	for (pair<int, int> v : virus) {
		q.push(v); // 큐에 바이러스 위치 저장
		visited[v.first][v.second] = 1;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) { // 상하좌우로 바이러스 퍼트림
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && lab[nx][ny] == 0) {
				safePlace--; // 바이러스에 노출된 빈 칸
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	return safePlace;
}

void dfs(int x, int y, int wall) { // 나머지 2개 벽 세우기
	if (wall == 3) { // 벽 3개 세웠다면
		int safePlace = bfs(); // 안전 영역 크기 구하기
		if (safePlace > maxSafePlace) maxSafePlace = safePlace; // 최대 안전 영역 크기 구하기
		return;
	}
	for (int i = x; i < n; i++) { // 2번째, 3번째 벽은 이전에 세운 벽보다 더 우측, 더 밑에 있는 곳에 세움 
		int j;
		if (i == x) j = y + 1;
		else j = 0;
		for (j; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				dfs(i, j, wall + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virus.push_back({ i,j }); // 바이러스의 위치 미리 저장
			else if (lab[i][j] == 0) zero++; // 빈 칸의 개수 저장
		}
	}
	zero -= 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				dfs(i, j, 1); // 벽 하나 세운 뒤 DFS로 나머지 2개 벽 세우기
				lab[i][j] = 0;
			}
		}
	}
	cout << maxSafePlace;
}
