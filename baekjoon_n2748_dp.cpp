#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    unsigned long long int f[91]{}; // 모두 0으로 초기화, 0번째 피보나치 수는 0
    cin >> n;
    f[1] = 1; // 1번째 피보나치 수는 1
    for (int i = 2; i <= n; i++) { // 2번째 피보나치 수부터 계산 (﻿Fn = Fn-1 + Fn-2 (n ≥ 2)﻿)
        f[i] = f[i - 2] + f[i - 1]; // 이전 원소의 값을 이용하여 계산
    }
    cout << f[n];
}