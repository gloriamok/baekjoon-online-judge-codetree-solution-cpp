#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l, h[1000];
    cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    sort(h,h+n); // 오름차순 정렬
    int maxHeight = l;
    for (int i=0; i<n; i++) {
        if (maxHeight >= h[i]) maxHeight++; // ﻿스네이크버드의 길이 1 증가
    }
    cout << maxHeight;
}