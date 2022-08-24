#include <iostream>
#include <algorithm>
using namespace std;

int lowerBound(int arr[], int start, int end, int target) { // 이진탐색으로 배열의 중복원소 중 첫번째 있는 원소의 인덱스 구하기
	while (start < end) {
		int mid = (start + end) / 2;
		if (target <= arr[mid]) end = mid;
		else start = mid + 1;
	}
	return start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, unknown, card, cardIdx, idx;
	cin >> n;
	int* numCards = new int[n]{}; // 상근이가 갖고 있는 n개의 숫자 카드를 저장할 배열
	int* numSameCards = new int[n]{}; // 상근이가 갖고 있는 중복카드의 수를 저장할 배열
	for (int i = 0; i < n; i++) {
		cin >> numCards[i];
	}
	sort(numCards, numCards + n); // 배열의 중복원소를 찾고 카운트하기 위해 (그리고 나중에 할 이분탐색을 위해) 정렬

	card = numCards[0];
	cardIdx = 0; // numCards 배열에서 중복 원소가 처음 나타난 인덱스
	numSameCards[0]++;
	for (int i = 1; i < n; i++) {
		if (card == numCards[i]) numSameCards[cardIdx]++; // 중복원소라면 cardIdx를 사용해 numSameCards 배열에서 원소 1 증가시킴 
		else {
			card = numCards[i]; // 중복원소가 아니라면 검사할 card를 새로운 카드 숫자로 바꿔줌
			cardIdx = i;
			numSameCards[i]++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> unknown;
		if (binary_search(numCards, numCards+n, unknown)) { // unknown 카드가 상근이에게 있는지 확인
			idx = lowerBound(numCards, 0, n, unknown); // unknown이 있는 배열 원소의 첫번째 인덱스
			cout << numSameCards[idx] << " "; // 찾은 인덱스를 numSameCards에 사용해서 해당 숫자 카드가 몇 개 있는지 출력
		}
		else cout << "0 "; // unknown 카드가 없다면 0 출력
	}
}