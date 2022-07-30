#include <iostream>
#include <set>
using namespace std;

int numpad[5][5];
set<int> num;

void DFS(int x, int y, int result, int cnt) { // 재귀함수
   if (cnt==6) { // 6자리 수가 되면 num set에 insert
        num.insert(result);
        return;
   }
    if (x+1<5) { // 오른쪽, 왼쪽, 위, 아래 네 방향으로 이동
         DFS(x+1, y, result * 10 + numpad[x+1][y], cnt + 1); // 원래 값에 10을 곱하고 이동한 값을 더해줌
    }
    if (x-1>=0) {
         DFS(x-1, y, result * 10 + numpad[x-1][y], cnt + 1);
    }
    if (y+1<5) {
         DFS(x, y+1, result * 10 + numpad[x][y+1], cnt + 1);
    }
    if (y-1>=0) {
         DFS(x, y-1, result * 10 + numpad[x][y-1], cnt + 1);
    }
}

int main() {
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            cin >> numpad[i][j];
   
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            DFS(i, j, numpad[i][j], 1); // 배열의 모든 원소의 위치에서 함수를 시작
    
    cout << num.size(); // num에 저장된 값들의 개수를 출력

}
