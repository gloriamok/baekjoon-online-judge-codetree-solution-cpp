#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n;
	int* numPack = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numPack[i];
	}
	sort(numPack, numPack + n); // 이분탐색을 위해 먼저 배열 정렬
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << binary_search(numPack, numPack + n, x) << "\n"; // 이분탐색으로 ﻿해당 숫자가 존재하는 지 확인하고 존재 여부를 출력
	}
}