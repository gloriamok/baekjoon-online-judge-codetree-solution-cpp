#include <iostream>
#include <set>
using namespace std;

int numpad[5][5];
set<int> s;

void Dfs(int n, int x, int y, int d) {
	if (n == 6) {
		s.insert(d);
		return;
	}
	int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx <= 4 && nx >= 0 && ny <= 4 && ny >= 0) Dfs(n + 1, nx, ny, d * 10 + numpad[nx][ny]);
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> numpad[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			Dfs(1, i, j, numpad[i][j]);
	cout << s.size();
}