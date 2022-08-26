#include <iostream>
using namespace std;

int main() {
	int n, cupholder = 1, flag = 0; // flag는 현재 입력받은 ﻿커플석 좌석 수를 세서 ﻿입력받은 커플석이 왼쪽 커플석인지 오른쪽 커플석인지 알 수 있게 함
	cin >> n;
	char seat;
	for (int i = 0; i < n; i++) {
		cin >> seat;
		if (seat == 'S') cupholder++; // ﻿일반좌석(S)일 경우 컵홀더 추가
		else if (seat == 'L' && flag % 2 == 1) { // ﻿오른쪽 커플석(L)일 경우 컵홀더 추가
			cupholder++;
			flag++; // 현재 커플석 좌석 수 1 증가
		}
		else flag++; // 왼쪽 커플석(L)일 경우 컵홀더 추가 안함
	}
	if (cupholder > n) cout << n; // ﻿컵홀더가 좌석보다 많을 때는 좌석의 수(n)를 출력﻿
	else cout << cupholder;
}