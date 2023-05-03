#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, num; // num은 0이 아닌 원소의 개수
double avrg = 0.0;
vector< vector<int> > disk;

void spin(int x, int d, int k) {
	if (d) { // counter-clockwise
		rotate(disk[x].begin(), disk[x].begin() + k, disk[x].end());
	}
	else { // clockwise
		rotate(disk[x].begin(), disk[x].end() - k, disk[x].end());
	}
}

bool near() {
	avrg = 0.0;
	vector<pair<int, int>> same;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (disk[i][j]) {
				avrg += disk[i][j];
				// 인접하면서 수가 같은 것 구하기
				if (j + 1 < m && disk[i][j] == disk[i][j + 1]) { // 오른쪽 원소와 비교
					same.push_back({ i,j });
					same.push_back({ i,j + 1 });
				}
				else if (j + 1 == m && disk[i][j] == disk[i][0]) { // 해당 행의 마지막 열의 원소인 경우, 첫번째 열의 원소와 비교 
					same.push_back({ i,j });
					same.push_back({ i,0 });
				}
				if (i + 1 <= n && disk[i][j] == disk[i + 1][j]) { // 아래쪽 원소와 비교
					same.push_back({ i,j });
					same.push_back({ i + 1,j });
				}
			}
		}
	}
	if (same.empty()) return 0;
	else {
		for (pair<int, int> p : same) {
			if (disk[p.first][p.second]) { // 원판에서 인접하면서 같은 수를 모두 지움(0으로 만듦)
				num--; // 0이 아닌 원소의 개수 1 감소
				disk[p.first][p.second] = 0;
			}
		}
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t;
	disk.resize(n + 1, vector<int>(m));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> disk[i][j];
		}
	}

	int x, d, k, times = 0;
	num = n * m;
	while (times < t && num != 0) { // t번 회전했거나 0이 아닌 원소의 개수가 없을 경우(원판에 수가 남아있지 않으면) while문 종료
		cin >> x >> d >> k;
		for (int i = 1; i <= n; i++) {
			if (i % x == 0) spin(i, d, k); // 번호가 x의 배수인 원판을 d방향으로 k칸 회전
		}

		if (!near()) { // 인접하면서 수가 같은 것이 없을 경우
			avrg /= num; // 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더함
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (disk[i][j]) {
						if (disk[i][j] > avrg) disk[i][j]--;
						else if (disk[i][j] < avrg) disk[i][j]++;
					}
				}
			}
		}
		times++;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			sum += disk[i][j];
		}
	}
	cout << sum;
}