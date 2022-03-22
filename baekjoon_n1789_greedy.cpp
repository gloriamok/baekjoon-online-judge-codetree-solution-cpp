#include <iostream>
using namespace std;

int main() {
    long long int s, n = 1, c = 0; // 서로 다른 c개의 자연수의 합 = s, 더해지는 자연수 n은 1부터 시작
    cin >> s;
    while (s != 0 && s - n >= 0) { // s가 0이거나 s가 n보다 작다면 더 이상 뺄 수 없으므로 while문을 빠져나옴
            s -= n++; // s에서 n을 빼주고 그 후 n에 1을 더해줌
            c++; // 빼기 완료했으므로 c에도 1 더해줌
    }
    cout << c << endl; // c 출력
}