#include <iostream>
using namespace std;

int main() {
    int n, sum, money[10] = {};
    cin >> n >> sum;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
    int d = n - 1, count = 0;
    while (sum != 0) {
        if (sum - money[d] >= 0) {
            sum -= money[d];
            count++;
        }
        else d--;
    }
    cout << count;
}