#include <iostream>
using namespace std;

int main() {
    int product, money[6] = { 500, 100, 50, 10, 5, 1 }, mIndex = 0, count = 0;
    cin >> product;
    int changes = 1000 - product; // 거스름돈
    
    while (changes != 0) { // 거스름돈이 0이 될 때까지 while문 반복
        if (changes - money[mIndex] < 0) // 거스름돈이 잔돈보다 작을 경우 잔돈의 인덱스++
            mIndex++;
        else {
            changes -= money[mIndex]; // 거스름돈이 잔돈보다 클 경우 거스름돈에서 잔돈을 빼고, 잔돈의 개수++
            count++;
        }
    }
    cout << count;
}