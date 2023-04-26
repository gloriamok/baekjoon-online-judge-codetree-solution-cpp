#include <iostream>
using namespace std;

int main() {
	int n, m, r, c, d, room[50][50]{};
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }; // 북(0), 동(1), 남(2), 서(3) 순
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];

	bool move = 1, visited[50][50]{}; // 청소한 칸이면 1, 청소 안한 칸이면 0
	int cleanArea = 0; // 청소한 영역의 개수
	while (move) {
		if (!visited[r][c]) { // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소
			visited[r][c] = 1;
			cleanArea++;
		}
		bool clean = 0;
		for (int k = 0; k < 4; k++) { // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸(=벽이 아니고, 방문하지 않은 빈 칸)이 있는지 확인
			int nx = r + dx[k], ny = c + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !room[nx][ny] && !visited[nx][ny])
				clean = 1;
		}
		if (clean) { // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
			d = (d + 3) % 4; // 반시계 방향으로 90도 회전
			int nx = r + dx[d], ny = c + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !room[nx][ny] && !visited[nx][ny])
				r += dx[d], c += dy[d]; // 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
		}
		else { // 없는 경우
			int bd = (d + 2) % 4; // 후진 방향
			int nx = r + dx[bd], ny = c + dy[bd];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !room[nx][ny])
				r += dx[bd], c += dy[bd]; // 한 칸 후진할 수 있다면 한 칸 후진
			else move = 0; // 후진할 수 없다면 작동을 멈춤
		}
	}
	cout << cleanArea;
}