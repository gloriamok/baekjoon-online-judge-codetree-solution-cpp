#include <iostream>
using namespace std;

struct problem {
    int sub1;
    int sub2;
    bool solvedp = false; // 푼 문제이면 true
};

int main() {
    int n, l, k, solvedn = 0, score = 0; // solvedn은 푼 문제의 수, score은 문제를 풀어서 얻은 점수
    problem p[100];
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i].sub1 >> p[i].sub2;
        if (p[i].sub2 <= l && solvedn < k) { // 현정이의 sub2 도전
            solvedn++;
            p[i].solvedp = true; // 해당 문제를 풀었다는 것을 표시
            score += 140; // sub2 풀었으므로 140점 얻음
        }
    }
    for (int i = 0; i < n && solvedn < k; i++) {
        if (p[i].sub1 <= l && !p[i].solvedp) { // 현정이의 sub1 도전
            solvedn++;
            score += 100; // sub1 풀었으므로 100점 얻음
        }
    }
    cout << score;
}