#include <iostream>
using namespace std;

struct RGB {
	char normal; // 적록색약이 아닌 사람
	char colorweak; // 적록색약인 사람
	bool normalVisit;
	bool colorweakVisit;
};

RGB grid[100][100]{};
int n;

bool dfs(int x, int y, char color, bool flag) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	if (flag) { // if flag == true, normal rgb (적록색약이 아닌 사람)
		if (!grid[x][y].normalVisit && grid[x][y].normal == color) { // 방문 여부 확인
			grid[x][y].normalVisit = true;
			dfs(x - 1, y, grid[x][y].normal, true); // 상하좌우 방문
			dfs(x, y - 1, grid[x][y].normal, true);
			dfs(x + 1, y, grid[x][y].normal, true);
			dfs(x, y + 1, grid[x][y].normal, true);
			return true;
		}
	}
	else {
		if (!grid[x][y].colorweakVisit && grid[x][y].colorweak == color) {
			grid[x][y].colorweakVisit = true;
			dfs(x - 1, y, grid[x][y].colorweak, false);
			dfs(x, y - 1, grid[x][y].colorweak, false);
			dfs(x + 1, y, grid[x][y].colorweak, false);
			dfs(x, y + 1, grid[x][y].colorweak, false);
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j].normal; // 적록색약이 아닌 사람은 적색과 녹색을 구분 가능함
			if (grid[i][j].normal == 'B') grid[i][j].colorweak = 'B';
			else grid[i][j].colorweak = 'R'; // 적록색약인 사람은 적색과 녹색을 구분하지 못함
		}
	}

	int normalArea = 0, colorweakArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j, grid[i][j].normal, true)) normalArea++;
			if (dfs(i, j, grid[i][j].colorweak, false)) colorweakArea++;
		}
	}
	cout << normalArea << " " << colorweakArea; // ﻿적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 출력
}