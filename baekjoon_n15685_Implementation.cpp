#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 }; // 0오른쪽 1위 2왼쪽 3아래
bool visited[101][101]{};

void dragoncurve(int x, int y, int d, int g) {
	// 0세대
	vector<int> direction;
	direction.push_back(d);
	visited[x][y] = 1;
	x += dx[d]; // (x,y)는 드래곤커브의 끝점
	y += dy[d];
	visited[x][y] = 1;
	// g가 0일 경우, while문 돌지 않음
	// g가 1 이상일 경우, while문에서 1~g세대를 돌림
	while (g--) {
		int last = direction.size() - 1;
		for (int i = last; i >= 0; i--) {
			int nd = (direction[i] + 1) % 4; // 시계방향으로 90도 회전, 오른쪽 -> 위 -> 왼쪽 -> 아래
			x += dx[nd]; // 드래곤커브의 끝점 업데이트
			y += dy[nd];
			visited[x][y] = 1;
			direction.push_back(nd);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragoncurve(x, y, d, g);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) cnt++; // 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부라면
	cout << cnt;
}