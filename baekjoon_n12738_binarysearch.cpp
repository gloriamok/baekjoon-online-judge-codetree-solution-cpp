#include <iostream>
using namespace std;

int n, arr[1000000], lis[1000000];

int binary_search(int target, int start, int end) { // ﻿lis 배열에서 target의 적당한 위치를 찾아 반환
    while (start < end) {
        int mid = (start + end) / 2;
        if (lis[mid] < target) start = mid + 1;
        else end = mid;
    }
    return end;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    lis[0] = arr[0];
    int last = 0, idx; // last는 ﻿ lis의 마지막 원소의 위치를 나타냄

    for (int i = 1; i < n; i++) {
        if (lis[last] < arr[i]) { // ﻿arr의 원소가 lis 배열의 마지막 원소보다 더 크다면
            lis[last + 1] = arr[i];
            last++;
        }
        else { // ﻿arr의 원소가 lis 배열의 마지막 원소보다 작거나 같다면
            idx = binary_search(arr[i], 0, last); // 이분 탐색 함수 실행
            lis[idx] = arr[i]; // ﻿idx 위치의 lis 배열에 arr의 원소를 넣음
        }
    }
    cout << last + 1;
}