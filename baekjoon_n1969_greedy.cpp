#include <iostream>
using namespace std;

int main() {
	int n, m;
	char dna;
	int arr[50][4]{};
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> dna;
			if (dna == 'A') arr[j][0]++;
			else if (dna == 'C') arr[j][1]++;
			else if (dna == 'G') arr[j][2]++;
			else if (dna == 'T') arr[j][3]++;
		}
	int hamDistance = 0;
	for (int j = 0; j < m; j++) {
		int max = 0, maxDna = 0;
		for (int k = 0; k < 4; k++) {
			if (max < arr[j][k]) {
				max = arr[j][k];
				maxDna = k;
			}
		}
		if (maxDna == 0) cout << 'A';
		else if (maxDna == 1) cout << 'C';
		else if (maxDna == 2) cout << 'G';
		else if (maxDna == 3) cout << 'T';
		for (int k = 0; k < 4; k++)
			if (k != maxDna) hamDistance += arr[j][k];
	}
	cout << "\n" << hamDistance;
}