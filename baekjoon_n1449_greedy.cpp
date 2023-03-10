#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, l, point, cnt = 0;
	set<int> pipe;
	cin >> n >> l; // 물이 새는 곳의 개수 n과 테이프의 길이 l
	for (int i = 1; i <= n; i++) {
		cin >> point; // 물이 새는 곳의 위치
		pipe.insert(point);
	}
	/* pipe set의 원소 출력
	for (auto i = pipe.begin(); i != pipe.end(); i++) {
		cout << *i << ' ';
	}
	*/
	while (!pipe.empty()) {
		int l2 = *pipe.begin() + l; // 물이 새는 곳의 첫 위치 + 테이프의 길이
		while(!pipe.empty() && *pipe.begin() < l2) pipe.erase(*pipe.begin()); // 테이프로 물이 새는 곳을 최대한 막는다
		cnt++;
	}
	cout << cnt;
}