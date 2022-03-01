#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, sum = 0, time[1000] = {};
    cin >> n;
    int a = n;
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time, time+n);
    for (int i = 0; i < n; i++) {
        sum += time[i] * a--;
    }
    cout << sum;
}