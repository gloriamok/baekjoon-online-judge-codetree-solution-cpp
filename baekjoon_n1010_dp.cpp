#include <iostream>
using namespace std;

void comb(int n, int r) {
	int factorial[30]{};
	for (int i = r + 1; i <= n; i++) factorial[i]++; // fact(n) ﻿÷ fact(r)
	for (int i = 2; i <= n - r; i++) factorial[i]--; // ÷ fact(n-r)
	long long int combination = 1;
	for (int i = n; i >= 2; i--) {
		if (factorial[i] > 0) combination *= i;
		else if (factorial[i] < 0) combination /= i;
	}
	cout << combination << "\n";
}

int main() {
	int t, n, r;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> n;
		comb(n, r);
	}
}