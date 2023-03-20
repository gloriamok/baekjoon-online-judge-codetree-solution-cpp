#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0, num = 0, minus = 0; // minus는 마이너스 기호가 나왔는지 알려준다 (flag 역할)
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != '+' && s.at(i) != '-') num = num * 10 + (s.at(i) - '0');
		else {
			if (minus) sum -= num;
			else sum += num;
			num = 0;
		}
		if (s.at(i) == '-') minus = 1;
	}
	if (minus) sum -= num; // 맨 마지막 숫자 연산
	else sum += num;
	cout << sum;
}