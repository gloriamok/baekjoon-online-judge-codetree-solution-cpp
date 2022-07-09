#include <iostream>
using namespace std;

int main() {
    int x, a, arr[2] = { 0 };
    for (int i = 0; i < 2; i++) {
        int max = 0, min = 0, s = 1;
        cin >> x;
        while (x != 0) {
            a = x % 10;
            if (a == 5 || a == 6) {
                max += 6 * s;
                min += 5 * s;
            }
            else {
                max += a * s;
                min += a * s;
            }
            x /= 10;
            s *= 10;
        }
        arr[0] += min;
        arr[1] += max;
    }
    cout << arr[0] << " " << arr[1];
}