#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, arr[1000]{}, length[1000]{};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                length[i] = max(length[i], length[j] + 1);
    }
    cout << *max_element(length, length + n);
}