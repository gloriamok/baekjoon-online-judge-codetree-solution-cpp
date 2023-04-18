#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct house {
	int chickenNo;
	int chickenDistance;
}house;

bool cmp(house a, house b) {
	return a.chickenDistance < b.chickenDistance;
}

int n, m, city[51][51]{}, minCityChickenDistance = 99999; // 도시의 치킨거리의 최솟값
bool choose[13]{};
vector<pair<int, int>> chicken;
vector < vector<house> > h;

int sumChickenDistance() { // 도시의 치킨거리 구하기
	int CityChickenDistance = 0;
	for (int i = 0; i < h.size(); i++) {
		for (int j = 0; j < h[i].size(); j++) {
			int n = h[i][j].chickenNo;
			if (choose[n]) { // 선택된 치킨집이라면 치킨집과의 거리를 도시의 치킨거리에 더해줌
				CityChickenDistance += h[i][j].chickenDistance;
				break;
			}
		}
	}
	return CityChickenDistance;
}

void dfs(int chickenNo, int chosedNum) { // m개의 치킨집 고르기
	if (chosedNum == m) { // 치킨집 m개를 다 골랐다면
		int CityChickenDistance = sumChickenDistance(); // 도시의 치킨거리 구하기
		if (CityChickenDistance < minCityChickenDistance)
			minCityChickenDistance = CityChickenDistance;
	}

	for (int k = chickenNo + 1; k < chicken.size(); k++) {
		choose[k] = 1;
		dfs(k, chosedNum+1);
		choose[k] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	int houseNum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) chicken.push_back({ i,j }); // 치킨집 좌표 미리 저장
			else if (city[i][j] == 1) houseNum++; // 집의 수 저장
		}
	}
	h.resize(houseNum, vector<house>(chicken.size())); // h[집의 수][치킨집의 수]
	houseNum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == 1) {
				for (int k = 0; k < chicken.size(); k++) {
					int d = abs(i - chicken[k].first) + abs(j - chicken[k].second);
					h[houseNum][k] = { k,d }; // 치킨집의 번호, 치킨집과의 거리 저장
				}
				sort(h[houseNum].begin(), h[houseNum].end(), cmp); // 치킨집과의 거리 기준 오름차순으로 정렬 
				houseNum++;
			}
		}
	}
	dfs(-1, 0);
	cout << minCityChickenDistance;
}