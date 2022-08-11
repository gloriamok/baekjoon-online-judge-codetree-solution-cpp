#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c[100001]{}, minPrice = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1, greater<>()); // 내림차순으로 정렬
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0) minPrice += c[i]; // 2+1이므로 꾸러미에서 제일 저렴한 세번째 제품의 값은 더하지 않는다 
    }
    cout << minPrice;
}