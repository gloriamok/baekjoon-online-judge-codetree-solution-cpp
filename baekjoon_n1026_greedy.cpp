#include <iostream>
#include <algorithm>
using namespace std;

struct Treasure { // 구조체 생성
    int number;
    int order;
};

bool cmpNumberUp(Treasure x, Treasure y) { // 숫자(number)를 오름차순으로 정렬
    return x.number < y.number;
}

bool cmpNumberDown(Treasure x, Treasure y) { // 숫자(number)를 내림차순으로 정렬
    return x.number > y.number;
}

bool cmpOrderUp(Treasure x, Treasure y) { // 순서(order)를 오름차순으로 정렬
    return x.order < y.order;
}

int main() {
    Treasure a[51], b[51];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].number; // A에 숫자(number) 입력
    for (int i = 1; i <= n; i++) { // B에 숫자(number)와 순서(order) 입력
        cin >> b[i].number;
        b[i].order = i;
    }

    sort(a + 1, a + n + 1, cmpNumberUp); // A의 숫자(number) 오름차순으로 정렬
    sort(b + 1, b + n + 1, cmpNumberDown); // B의 숫자(number) 내림차순으로 정렬

    for (int i = 1; i <= n; i++) { // B의 순서(order)를 A의 순서(order)에 복사
        a[i].order = b[i].order;
    }

    sort(a + 1, a + n + 1, cmpOrderUp); // B의 순서(order)대로 A의 순서(order) 정렬
    sort(b + 1, b + n + 1, cmpOrderUp); // B 원상복귀

    int sum = 0;
    for (int i = 1; i <= n; i++) { // A와 B의 number 원소 각각 곱해서 sum에 저장
        sum += a[i].number * b[i].number;
    }

    cout << sum;
}