#include <iostream>
using namespace std;

int main() {
	int n, r1, g1, b1, r2, g2, b2;
	cin >> n >> r1 >> g1 >> b1;
	for (int i = 2; i <= n; i++) {
		cin >> r2 >> g2 >> b2;
		r2 += min(g1, b1); // ﻿i번째 집을 빨강으로 칠했을 때 + i-1번째 집을 초록으로 칠했을 때나 파랑으로 칠했을 때 중 더 적은 비용
		g2 += min(r1, b1); // ﻿i번째 집을 초록으로 칠했을 때 + i-1번째 집을 빨강으로 칠했을 때나 파랑으로 칠했을 때 중 더 적은 비용
		b2 += min(r1, g1); // ﻿i번째 집을 파랑으로 칠했을 때 + i-1번째 집을 빨강으로 칠했을 때나 초록으로 칠했을 때 중 더 적은 비용
		r1 = r2;
		g1 = g2;
		b1 = b2;
	}
	cout << min(min(r1, g1), b1);
}