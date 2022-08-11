#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 4 || n == 7) { // 만약 n이 4나 7이라면 5와 3으로 정확하게 만들 수 없기 때문에
        cout << -1; // -1을 출력하고
        return 0; // 프로그램 종료
    }
    switch (n % 5) {
        case 0: // n이 5로 나누어 떨어진다면
            cout << n / 5; // 봉지의 최소 개수는 n 나누기 5
            break;
        case 1: // n을 5로 나누었을 때 나머지가 1이라면
            cout << 2 + (n-6) / 5; // 봉지의 개수는 2(3kg 2봉지) + (n-6(3kg 2봉지)) 나누기 5
            break;
        case 2:
            cout << 4 + (n-12) / 5; // 봉지의 개수는 4(3kg 4봉지) + (n-12(3kg 4봉지)) 나누기 5
            break;
        case 3:
            cout << 1 + (n-3) / 5; // 봉지의 개수는 1(3kg 1봉지) + (n-3(3kg 1봉지)) 나누기 5
            break;
        case 4:
            cout << 3 + (n-9) / 5; // 봉지의 개수는 3(3kg 3봉지) + (n-9(3kg 3봉지)) 나누기 5
            break;
    }

    return 0;
}
