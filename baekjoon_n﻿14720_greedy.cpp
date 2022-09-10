#include <iostream>
using namespace std;

int main() {
	int n, milk, cnt = 0; // cnt는 ﻿영학이가 마실 수 있는 우유의 최대 개수
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> milk; // 현재 우유 가게
		if (cnt % 3 == milk) cnt++; // cnt % 3은 영학이가 지금 마실 수 있는 우유
	}
	cout << cnt;
}