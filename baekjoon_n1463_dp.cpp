#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* dp = new int[n + 1]{};
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[n];
}

/*
입력값을 받아서 그 값을 가지고 경우의 수를 돌려서 연산을 하는 것이 아니라
2부터 시작해서 (1은 최소연산횟수가 0이므로) 입력값까지의 최소연산횟수를 계산한다!
입력값의 최소연산횟수는 이전 최소연산횟수에 1을 더한 것과 같으므로!
1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.
이 3개의 연산 중 제일 적은 연산횟수(min)를 채택한다!
*/