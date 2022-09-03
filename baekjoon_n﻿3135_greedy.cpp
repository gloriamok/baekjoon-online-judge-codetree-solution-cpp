#include <iostream>
using namespace std;

int main() {
	int a, b, n, x, flag = 0;
	cin >> a >> b >> n;
	int minButtonDistance = abs(b - a); // 첫번째, 두번째 버튼만 사용
	for (int i = 1; i<=n;i++) {
		cin >> x;
		if (minButtonDistance > abs(b - x)) {
			flag = 1; // 즐겨찾기 기능 사용해 X 주파수로 이동할 때 버튼 한 번 누름
			minButtonDistance = abs(b - x);
		}
	}
	cout << minButtonDistance + flag; // ﻿주파수 A에서 B로 갈 때 눌러야 하는 버튼수의 최솟값 출력
}