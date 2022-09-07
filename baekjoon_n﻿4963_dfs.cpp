#include <iostream>
using namespace std;

int map[50][50]{};
bool islandVisit[50][50]{}; // 방문했는지 알려주는 배열 (true이면 방문한 땅)
int w, h;

bool dfs(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) return false;

	if (!islandVisit[x][y] && map[x][y] == 1) { // 방문하지 않은 땅일 경우
		islandVisit[x][y] = true; // 방문했다고 표시
		dfs(x - 1, y); // 상하좌우 재귀
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x + 1, y + 1); // 대각선 재귀
		dfs(x - 1, y - 1);
		dfs(x + 1, y - 1);
		dfs(x - 1, y + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> w >> h;
	while (!(w == 0 && h == 0)) { // w와 h가 둘 다 0이라면 while문 종료
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				islandVisit[i][j] = false; // 테스트 케이스마다 islandVisit 배열 초기화

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		int island = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (dfs(i, j)) island++;

		cout << island << "\n";
		cin >> w >> h;
	}
}