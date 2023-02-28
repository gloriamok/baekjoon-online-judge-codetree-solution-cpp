#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, d = 0, t[100000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];
	sort(t, t + n, greater<>());
	for (int i = 0; i < n; i++) if (d < i + 2 + t[i]) d = i + 2 + t[i]; // 1 + i + 1 + t[i]
	cout << d;
}