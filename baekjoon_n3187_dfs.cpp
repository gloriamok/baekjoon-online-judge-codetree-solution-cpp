#include <iostream>
using namespace std;

int r, c, sheep = 0, wolf = 0;
char yard[250][250]{};
bool yardVisit[250][250]{}; // 방문했는지 알려주는 배열 (true이면 방문한 칸)

bool dfs(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) return false;

	if (!yardVisit[x][y] && yard[x][y] != '#') { // 방문한 칸이 아니고 그 칸이 울타리가 아닐 경우
		yardVisit[x][y] = true; // 해당 칸 방문했다고 표시

		if (yard[x][y] == 'k') sheep++;
		else if (yard[x][y] == 'v') wolf++;

		dfs(x - 1, y); // 상하좌우로 dfs 함수 실행
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> yard[i][j];
	int sheepTotal = 0, wolfTotal = 0; // ﻿아침까지 살아있는 총 양과 늑대의 수
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (dfs(i, j)) {
				if (sheep > wolf) sheepTotal += sheep; // 해당 영역에 양이 늑대보다 많다면 양이 이김
				else wolfTotal += wolf;
				sheep = 0; // 다른 영역을 위해 양, 늑대의 수 초기화
				wolf = 0;
			}
	cout << sheepTotal << " " << wolfTotal;
}