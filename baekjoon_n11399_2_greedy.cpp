#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, atm[1000], time = 0, mid = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> atm[i];
	sort(atm, atm + n);
	for (int i = 0; i < n; i++) {
		time += mid + atm[i];
		mid += atm[i];
	}
	cout << time;
}