#include <iostream>
using namespace std;

int dice[4][3]{}; // 주사위 각 면에 쓰여 있는 수를 원소로 저장
// 주사위 윗면 dice[1][1], 주사위 바닥면 dice[3][1]

void roll(int com) {
	int temp[4]{}, u, idx, r;
	if (com == 3 || com == 4) { // Roll Up(North) and Down(South)
		if (com == 3) u = 1;
		else u = 3;
		for (int i = 0; i < 4; i++) {
			temp[i] = dice[i][1];
		}
		for (int i = 0; i < 4; i++) {
			dice[i][1] = temp[(i + u) % 4]; // +3
		}
	}
	else { // Roll Left(West) and Right(East)
		if (com == 2) idx = 0, r = 1;
		else idx = 2, r = 2;
		temp[0] = dice[3][1];
		dice[3][1] = dice[1][idx]; // 주사위 바닥면과 주사위 옆면의 원소 바꾸기
		dice[1][idx] = temp[0];

		for (int j = 0; j < 3; j++) {
			temp[j] = dice[1][j];
		}
		for (int j = 0; j < 3; j++) {
			dice[1][j] = temp[(j + r) % 3];
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y, k, map[20][20]{};
	int command, dx[] = { 0,0,0,-1,1 }, dy[] = { 0,1,-1,0,0 };
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> command;
		int nx = x + dx[command], ny = y + dy[command];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) { // 지도의 범위 안에 있다면
			x = nx;
			y = ny;
			roll(command); // 주사위 굴리기
			if (!map[x][y]) map[x][y] = dice[3][1]; // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수를 칸에 복사
			else { // 0이 아닌 경우에는 칸에 쓰여 있는 수를 주사위의 바닥면으로 복사,
				dice[3][1] = map[x][y];
				map[x][y] = 0; // 칸에 쓰여 있는 수는 0이 됨
			}
			cout << dice[1][1] << "\n"; // 주사위 윗면의 수 출력
		}
	}
}