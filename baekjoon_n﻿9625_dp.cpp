#include <iostream>
using namespace std;

int main() {
	int k, countA = 1, countB = 0, temp;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		temp = countB;
		countB += countA; // ﻿countB_{N+1} = countA_N + countB_N
		countA = temp; // ﻿countA_{N+1} = countB_N
	}
	cout << countA << " " << countB;
}