#include <iostream>
using namespace std;

int n, l, numPath = 0;

void findNumPath(int map[100][100]) {
	for (int i = 0; i < n; i++) {
		int s = 0, e = 0;
		bool path = 1;
		while (path && e < n) { // 한 행씩 보기
			e++;
			if (!(e < n && map[i][s] == map[i][e])) { // e가 n 이상이거나 i번째 행에서 s번째와 e번째 열의 map의 값이 같지 않을 경우
				if (s - 1 >= 0 && map[i][s - 1] > map[i][s] && e < n && map[i][e - 1] < map[i][e]) { // 양쪽 둘 다 나보다 높을 경우
					if (map[i][s - 1] > map[i][s] + 1 || map[i][e - 1] + 1 < map[i][e]) path = 0; // 차이가 1보다 크면 지나갈 수 없음
					else if (e - s < l * 2) path = 0;
					else s = e;
				}
				else if ((s - 1 >= 0 && map[i][s - 1] > map[i][s]) || (e < n && map[i][e - 1] < map[i][e])) { // 한쪽만 나보다 높을 경우
					if (s - 1 >= 0 && map[i][s - 1] > map[i][s] + 1) path = 0;
					else if (e < n && map[i][e - 1] + 1 < map[i][e]) path = 0;
					else if (e - s < l) path = 0;
					else s = e;
					//cout << "row " << i << " map[i][s] = " << map[i][s] << endl;
				}
				else s = e; // 둘 다 나보다 낮을 경우
			}
		}
		if (path) numPath++;
		cout << "row " << i << " numPath " << numPath << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int map1[100][100]{}, map2[100][100]{};
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
			map2[j][i] = map1[i][j]; // 행과 열을 교환 (전치)
		}
	findNumPath(map1);
	findNumPath(map2);
	
	cout << numPath;
}