#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	char num[100]{};
	for (int i = 0; i < n; i++) { // 0~9의 아스키코드는 48~57
		cin >> num[i];
		// cout << int(num[i])-48 << " ";
		sum += int(num[i]) - 48;
	}
	cout << sum;
}
