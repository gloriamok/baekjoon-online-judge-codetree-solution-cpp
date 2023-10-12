#include <iostream>
#include <vector> // stack도 가능
using namespace std;

int n, m, maxNums[20][20]{}, numToMove[100]{}, dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};
vector<int> st[20][20]{};
pair<int,int> numIdx[401]{};

void move(int idx) {
    // 인접한 칸들 중 가장 큰 값과 위치 찾기
    int x = numIdx[idx].first, y = numIdx[idx].second, maxNum = 0;
    pair<int,int> maxIdx;
    for(int k=0;k<8;k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && maxNums[nx][ny] > maxNum) {
            maxNum = maxNums[nx][ny];
            maxIdx = {nx,ny};
        }
    }
    // 옮길 값들 이동 전 위치의 벡터에서 빼고 temp 벡터에 저장
    vector<int> v; // temp 벡터
    if (maxNum) {
        bool flag = 0;
        while(!flag) {
            int f = st[x][y].back();
            st[x][y].pop_back();
            v.push_back(f);
            if (f == idx) flag = 1;
        }
    }
    // 이동 전 위치의 최댓값 업데이트
    maxNums[x][y] = 0;
    for(int i : st[x][y]) if (i > maxNums[x][y]) maxNums[x][y] = i;
    // 옮길 값들 temp 벡터에서 빼고 옮길 위치에 저장
    int nx = maxIdx.first, ny = maxIdx.second;
    while(!v.empty()) {
        int b = v.back();
        // 숫자의 위치 업데이트
        numIdx[b] = {nx,ny};
        // 이동 후 위치의 최댓값 업데이트
        if (b > maxNums[nx][ny]) maxNums[nx][ny] = b;
        st[nx][ny].push_back(b);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin >> maxNums[i][j];
        st[i][j].push_back(maxNums[i][j]);
        numIdx[maxNums[i][j]] = {i,j};
    }
    for(int i=0;i<m;i++) cin >> numToMove[i];
    for(int i=0;i<m;i++) {
        move(numToMove[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (!st[i][j].empty()) {
                while(!st[i][j].empty()) {
                    cout << st[i][j].back() << " ";
                    st[i][j].pop_back();
                }
            }
            else cout << "None";
            cout << "\n";
        }
    }
    return 0;
}