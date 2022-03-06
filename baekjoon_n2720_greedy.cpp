#include <iostream>
using namespace std;

int main() {
    int t, c, money[4] = { 25, 10, 5, 1 }; // ﻿ 쿼터(25센트), 다임(10센트), 니켈(5센트), 페니(1센트)
    cin >> t; // 테스트케이스의 개수
    for (int i = 1; i <= t; i++) { // t개의 테스트케이스 = for문 t번 반복
        cin >> c; // 거스름돈
        int count[4] = { 0 }, idx = 0; // count와 idx 초기화
        while (c != 0) { // 거스름돈이 0이 아니면 while문 반복
            if (c - money[idx] < 0) idx++; // c가 동전보다 작다면 idx값 1 더해서 동전의 가치 바꿈 (낮춤)
            else {
                c -= money[idx]; // c가 동전보다 크거나 같다면 c에서 동전 값을 빼줌
                count[idx]++; // 그 동전의 개수에 1 더함
            }
        }
        for (int j = 0; j < 4; j++) {
            cout << count[j] << " "; // 각 동전의 개수 출력
        }
    }
}