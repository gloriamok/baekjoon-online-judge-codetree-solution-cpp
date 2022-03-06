#include <iostream>
using namespace std;

int main() {
    int n, abc[3] = {300, 60, 10}, count[3] = {0}, idx = 0;
    cin >> n;
    if (n % 10 != 0) { // 요리시간이 10의 배수가 아니어서 시간을 정확히 맞출 수 없는 경우
      cout << -1; // ﻿ 음수 -1 출력
      return 0; // 프로그램 종료
    }
    while (n != 0) { // 주어진 요리시간 n이 0이 될 때까지 반복
      if (n - abc[idx] >= 0) { // n이 버튼에 저장된 시간보다 크거나 같을 경우 
         n -= abc[idx]; // n에서 버튼에 저장된 시간을 빼주고
         count[idx]++; // 눌린 버튼의 누른 횟수에 1을 더해줌
      }
      else idx++; // n이 버튼시간보다 작을 경우 인덱스에 1을 더해줘서 그 다음 버튼시간으로 이동
    }
    for (int i = 0; i < 3; i++) cout << count[i] << " "; // 버튼 A,B,C를 누른 횟수 출력
    return 0;
}