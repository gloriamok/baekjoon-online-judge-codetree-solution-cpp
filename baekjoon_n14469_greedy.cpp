#include <iostream>
#include <algorithm>
using namespace std;

struct Cow {
    int arriveTime; // 도착시각
    int checkTime; // 검문시간
    int totalTime; // 도착시각 + 검문시간
};

bool cmp(Cow x, Cow y) { // 도착시간 기준 오름차순 정렬
    return x.arriveTime < y.arriveTime;
}

int main() {
    Cow cow[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cow[i].arriveTime >> cow[i].checkTime;
        cow[i].totalTime = cow[i].arriveTime + cow[i].checkTime;
    }
    sort(cow, cow + n, cmp); // 오름차순 정렬
    
    int minTime = cow[0].totalTime; // ﻿모든 소가 농장에 입장하는 데 걸리는 최소 시간
    for (int i=0; i<n-1; i++) {
        if (minTime > cow[i+1].arriveTime)
            minTime += cow[i+1].checkTime;
        else minTime = cow[i+1].totalTime;
    }  
    cout << minTime; 
}