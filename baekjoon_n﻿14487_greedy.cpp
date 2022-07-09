#include <iostream>
using namespace std;

int main() {
    int n, x, max, sum = 0;
    cin >> n >> max;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        if (x > max) {
            sum += max;
            max = x;
        }
        else sum += x;
    }
    cout << sum;
}