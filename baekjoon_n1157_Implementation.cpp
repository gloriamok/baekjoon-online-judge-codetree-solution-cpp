#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string line;
	cin >> line; // 알파벳 대소문자로 된 단어가 입력됨
	int count[26]{}; // 26개 알파벳, a나 A의 개수는 count[0]에,..., z나 Z의 개수는 count[25]에 저장
	for (int i = 0; i < line.size(); i++) { // 아스키코드: 소문자 a~z는 97~122, 대문자 A~Z는 65~90
		int letter = line[i];
		if (letter >= 97) count[letter - 97]++; // 소문자라면 -97
		else count[letter - 65]++; // 대문자라면 원래 문자의 아스키코드에 -65한 index 사용해 count++
	}
	int max = 0,  maxIdx = 0;
	for (int i = 0; i < 26; i++) { // 가장 많이 사용된 알파벳 찾기
		if (count[i] > max) {
			max = count[i];
			maxIdx = i;
		}
	}
	sort(count, count + 26, greater<>()); // 내림차순으로 정렬
	if (count[0] == count[1]) // 가장 많이 사용된 알파벳이 중복되는지 (두 개 이상인지) 검사
		cout << '?'; // 중복된다면 ? 출력
	else cout << char(maxIdx + 65); // 중복되지 않는다면 가장 많이 사용된 알파벳(대문자) 출력
}
