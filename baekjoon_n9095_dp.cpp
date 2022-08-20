#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p[11]{};
	p[1] = 1;
	p[2] = 2;
	p[3] = 4;
	for (int i = 4; i <= 10; i++) { // ﻿Fn = Fn-1 + Fn-2 + Fn-3 (n ≥ 4)﻿
		p[i] = p[i - 3] + p[i - 2] + p[i - 1];
	}

	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << p[n] << "\n";
	}
}