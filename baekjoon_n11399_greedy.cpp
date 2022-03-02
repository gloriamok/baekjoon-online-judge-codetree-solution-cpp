#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, sum = 0, time[1000] = {}; // sum은 각 사람이 돈을 인출하는데 필요한 시간의 합
    cin >> n;
    int a = n;
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time, time+n); // 돈을 인출하는데 걸리는 시간 오름차순으로 정렬
    for (int i = 0; i < n; i++) {
        sum += time[i] * a--; // time의 첫 원소부터 a와 곱해서 sum에 더함, 첫 원소와 곱해지는 a 값은 N과 같다. a는 더한 후에 1씩 감소해서 다음에 적용
    }
    cout << sum;
}
