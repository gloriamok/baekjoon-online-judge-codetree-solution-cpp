#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, numCardPack;
	priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선순위 큐
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numCardPack;
		pq.push(numCardPack);
	}

	int a, b, compareTimes = 0;
	while (pq.size() > 1) { // 큐의 원소가 한 개가 될 때까지 반복
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop(); // 제일 작은 두 개의 원소 a, b를 큐에서 꺼냄 
		compareTimes += a + b; // 비교한 횟수에 넣어줌
		pq.push(a+b); // a+b를 큐에 넣어줌
	}
	cout << compareTimes; // 최소 비교 횟수 출력
}