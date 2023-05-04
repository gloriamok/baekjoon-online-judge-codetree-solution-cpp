#include <iostream>
#include <algorithm>
using namespace std;

int r, c, t, home[50][50]{};
int u, d;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void diffusion() {
	int newHome[50][50]{};
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (home[i][j] > 0) {
				int diffDust = home[i][j] / 5; // 확산되는 미세먼지 양
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c && home[nx][ny] != -1) { // 인접한 방향에 칸이 있고, 공기청정기가 없다면 확산
						newHome[nx][ny] += diffDust;
						newHome[i][j] -= diffDust;
					}
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			home[i][j] += newHome[i][j];
		}
	}
}

void clean() {
	int temp[50][50]{};
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) temp[i][j] = home[i][j];

	// 반시계 방향
	// 오른쪽 (→)
	for (int j = 1; j <= c - 1; j++) home[u][j] = temp[u][j - 1];
	// 위 (↑)
	for (int i = 0; i <= u - 1; i++) home[i][c - 1] = temp[i + 1][c - 1];
	// 왼쪽 (←)
	for (int j = 0; j <= c - 2; j++) home[0][j] = temp[0][j + 1];
	// 아래 (↓)
	for (int i = 1; i <= u; i++) home[i][0] = temp[i - 1][0];

	//시계방향
	// 오른쪽 (→)
	for (int j = 1; j <= c - 1; j++) home[d][j] = temp[d][j - 1];
	// 아래 (↓)
	for (int i = d + 1; i <= r - 1; i++) home[i][c - 1] = temp[i - 1][c - 1];
	// 왼쪽 (←)
	for (int j = 0; j <= c - 2; j++) home[r - 1][j] = temp[r - 1][j + 1];
	// 위 (↑)
	for (int i = d; i <= r - 2; i++) home[i][0] = temp[i + 1][0];

	// 공기청정기 오른쪽에 있는 칸은 바람이 분 뒤 미세먼지가 없어짐
	home[u][1] = 0;
	home[d][1] = 0;
	// 공기청정기로 들어간 미세먼지는 모두 정화됨
	home[u][0] = -1;
	home[d][0] = -1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> home[i][j];
			if (home[i][j] == -1) d = i;
		}
	}
	u = d - 1;
	int time = 0;
	while (time < t) {
		diffusion();
		clean();
		time++;
	}

	int totalDust = 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			totalDust += home[i][j];
		}
	}
	cout << totalDust;
}