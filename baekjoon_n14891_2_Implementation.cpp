// rotate 함수 사용

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector < vector <int> > gear(5, vector<int>(8));


void rotation(int gearNo, int direction) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> rotatingGear;
	bool visited[5]{};
	q.push({ gearNo, direction });
	rotatingGear.push_back({ gearNo, direction });
	visited[gearNo] = 1;
	while (!q.empty()) {
		int gearNo = q.front().first, direction = q.front().second;
		q.pop();
		int left = gearNo - 1, right = gearNo + 1;
		if (left != 0 && !visited[left]) { // 왼쪽 톱니바퀴
			int leftGear = gear[left][2];
			int rightGear = gear[gearNo][6];
			if (leftGear != rightGear) {
				q.push({ left, direction * -1 });
				rotatingGear.push_back({ left, direction * -1 });
				visited[left] = 1;
			}
		}
		if (right != 5 && !visited[right]) { // 오른쪽 톱니바퀴
			int leftGear = gear[gearNo][2];
			int rightGear = gear[right][6];
			if (leftGear != rightGear) {
				q.push({ right, direction * -1 });
				rotatingGear.push_back({ right, direction * -1 });
				visited[right] = 1;
			}
		}
	}
	for (pair<int, int> g : rotatingGear) {
		if (g.second == 1) {
			rotate(gear[g.first].begin(), gear[g.first].end() - 1, gear[g.first].end());
		}
		else rotate(gear[g.first].begin(), gear[g.first].begin() + 1, gear[g.first].end());
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
		rotation(gearNo, direction);
	}
	int score = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0]) { // S극이면
			score += (int)pow(2,i-1);
		}
	}
	cout << score;
}