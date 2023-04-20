#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < vector <int> > gear(5, vector<int>(8)); // 톱니바퀴 상태 저장 벡터
vector<int> point12(5), point3(5, 2), point9(5, 6); // 12시방향, 3시방향, 9시방향의 gear 벡터 인덱스를 저장하는 벡터
bool visited[5]{};

void rotate(int gearNo, int direction) {
	if (direction == 1) { // 시계방향
		if (point12[gearNo] == 0) point12[gearNo] = 7;
		else point12[gearNo]--;
	}
	else if (direction == -1) { // 반시계방향
		point12[gearNo] = (point12[gearNo] + 1) % 8;
	}
}

void leftrightGear(int gearNo, int direction) {
	int left = gearNo - 1, right = gearNo + 1;
	if (left != 0 && !visited[left]) { // 왼쪽 톱니바퀴
		int leftGear = gear[left][point3[left]]; // 왼쪽 톱니바퀴의 3시방향의 극
		int rightGear = gear[gearNo][point9[gearNo]]; // 나의 톱니바퀴의 9시방향의 극
		if (leftGear != rightGear) { // 극이 같지 않다면
			rotate(left, direction * -1); // 반대방향으로 회전
			visited[left] = 1;
			leftrightGear(left, direction * -1);
			visited[left] = 0;

		}
	}
	if (right != 5 && !visited[right]) { // 오른쪽 톱니바퀴
		int leftGear = gear[gearNo][point3[gearNo]]; // 나의 톱니바퀴의 3시방향의 극
		int rightGear = gear[right][point9[right]]; // 오른쪽 톱니바퀴의 9시방향의 극
		if (leftGear != rightGear) { // 극이 같지 않다면
			rotate(right, direction * -1); // 반대방향으로 회전
			visited[right] = 1;
			leftrightGear(right, direction * -1);
			visited[right] = 0;
		}
	}
}

void rearrange() {
	for (int i = 1; i <= 4; i++) {
		point3[i] = (point12[i] + 2) % 8;
		point9[i] = (point12[i] + 6) % 8;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			gear[i][j] = c - '0';
		}
	}

	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int gearNo, direction;
		cin >> gearNo >> direction;
		rotate(gearNo, direction); // point12 업데이트
		visited[gearNo] = 1;
		leftrightGear(gearNo, direction); // DFS
		visited[gearNo] = 0;
		rearrange(); // 업데이트된 point12를 기준으로 point3, point9를 업데이트
	}
	int score = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][point12[i]]) { // S극이면
			score += (int)pow(2,i-1);
		}
	}
	cout << score;
}