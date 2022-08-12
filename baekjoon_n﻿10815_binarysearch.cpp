#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, m, card, unknown;
	vector<int> numCards;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		numCards.push_back(card);
	}
	sort(numCards.begin(), numCards.end()); // 이분탐색을 위해 먼저 벡터를 정렬해줌
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> unknown;
		cout << binary_search(numCards.begin(), numCards.end(), unknown) << " "; // 이분탐색으로 정수가 numCards에 포함되어있는지 확인
	}
}