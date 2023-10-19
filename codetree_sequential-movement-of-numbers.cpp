#include <iostream>
using namespace std;
int n, m, grid[20][20]{}, x, y, dx[8] = {0,0,1,-1,1,1,-1,-1}, dy[8] = {1,-1,0,0,1,-1,1,-1};

void find(int num) {
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if (grid[i][j] == num) {
        x = i;
        y = j;
        return;
    }
}

void switchNum() {
    int maxNum = 0, maxd;
    for(int k=0;k<8;k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] > maxNum) {
            maxNum = grid[nx][ny];
            maxd = k;
        }
    }
    int nx = x + dx[maxd], ny = y + dy[maxd];
    int tempNum = grid[x][y];
    grid[x][y] = grid[nx][ny];
    grid[nx][ny] = tempNum;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> grid[i][j];
    while(m > 0) {
        m--;
        for(int num=1;num<=n*n;num++) {
            find(num);
            switchNum();
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << grid[i][j] << " ";
        cout << "\n";
    }
    return 0;
}