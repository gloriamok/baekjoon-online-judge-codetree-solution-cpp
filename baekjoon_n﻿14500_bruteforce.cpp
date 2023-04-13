#include <iostream>
using namespace std;

int n, m, arr[500][500]{}; // n 세로 m 가로
bool visited[500][500]{};
int maxValue = 0; // 테트로미노가 놓인 칸의 합의 최댓값
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int depth, int value) {
	if (depth == 4) { // 테트로미노 완성
		if (value > maxValue) maxValue = value;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
			visited[nx][ny] = 1;
			dfs(nx, ny, depth + 1, value + arr[nx][ny]);
			visited[nx][ny] = 0;
			if (depth == 2) { // ㅗ ㅜ ㅓ ㅏ 모양 테트로미노 만들기
				for (int l = k + 1; l < 4; l++) {
					int nnx = x + dx[l];
					int nny = y + dy[l];
					if (nnx >= 0 && nnx < n && nny >= 0 && nny < m && !visited[nnx][nny]) {
						dfs(nnx, nny, depth + 2, value + arr[nx][ny] + arr[nnx][nny]);
					}
				}
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
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i,j, 1, arr[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << maxValue;
}