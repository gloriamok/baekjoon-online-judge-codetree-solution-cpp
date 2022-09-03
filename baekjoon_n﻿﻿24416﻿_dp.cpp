#include <iostream>
using namespace std;

int main() {
	int n, cntCode1[41]{};
	cin >> n;
	cntCode1[1] = 1;
	cntCode1[2] = 1;
	for (int i = 3; i <= n; i++) {
		cntCode1[i] = cntCode1[i - 2] + cntCode1[i - 1];
	}
	cout << cntCode1[n] << " " << n - 2;
}