#include <iostream>
using namespace std;

int main() {
    int n, sum, money[10] = {};
    cin >> n >> sum;
    for (int i = 0; i < n; i++) {
        cin >> money[i]; // 동전의 가치를 배열로 받음
    }
    int d = n - 1, count = 0; // 동전의 가치 배열의 인덱스를 바꾸기 위한 변수 d 설정;
                              //이 문제에서는 n을 이후에 사용하지 않으므로 d를 초기화하는 대신 n--를 써도 좋다
    while (sum != 0) { // // 동전의 가치의 합 sum이 0이 될 때까지 while문 반복
        if (sum - money[d] >= 0) { // 만약 sum이 동전의 가치보다 크거나 같다면 sum에서 동전의 가치 빼준 뒤 필요한 동전 개수 count에 1 더해줌
            sum -= money[d];
            count++;
        }
        else d--; // 만약 sum이 동전의 가치보다 작다면 인덱스 d에 1 빼기
    }
    cout << count; // count 출력
}
