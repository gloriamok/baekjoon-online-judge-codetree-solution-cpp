#include <iostream>
using namespace std;

int main() {
    int a, b, count = 1, flag = false; // ﻿A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력해야하므로 연산 횟수 count를 1로 초기화
    cin >> a >> b;
    while (a < b && !flag) { // a가 b보다 작고 flag가 false일 때 while문 반복
        if (b % 2 == 0) { // b가 짝수라면
            b /= 2; // b에 나누기 2를 함 
            count++; // 연산 횟수에 1 더함
        }
        else if (b % 10 == 1) { // ﻿b가 홀수고, B의 마지막 수(맨 오른쪽 숫자 (digit))가 1이라면
            b /= 10; // b에 나누기 10을 함 (정수(int)이므로 버리기 효과 203/10=20)
            count++; // 연산 횟수에 1 더함
        }
        else flag = true; // b가 ﻿홀수인데 마지막 수가 1이 아니면 flag를 true로 바꿈
    }
    if (a == b) cout << count; // ﻿A와 B가 동일한 지 확인
    else cout << -1;
}
