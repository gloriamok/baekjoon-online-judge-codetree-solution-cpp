#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2) cout << "SK"; // n % 2 == 1일 때 (돌이 홀수개일 때)
    else cout << "CY";
}