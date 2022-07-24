#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) { // 내림차순으로 정렬
    return x > y;
}

int main() {
    int n, t[100000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    sort(t, t+n, cmp); // 내림차순으로 정렬
    for (int i=0; i<n; i++) {
        t[i] += i+1;
    }
    sort(t, t+n, cmp); // 제일 긴 시간를 구하기 위해 다시 내림차순으로 정렬
    cout << t[0]+1; // ﻿마지막 나무가 다 자란 다음날 이장님을 초대하므로 1을 더해줌
    
}