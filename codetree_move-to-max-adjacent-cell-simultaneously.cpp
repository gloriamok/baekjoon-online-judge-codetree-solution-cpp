#include <iostream>
using namespace std;
int n, m, t, grid[21][21]{}, ball[21][21]{}, di[4] = {-1,1,0,0}, dj[4] = {0,0,-1,1};

void move() {
    int newBall[21][21]{};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (ball[i][j]) {
                int maxValue = 0, maxd;
                for(int k=0;k<4;k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni > 0 && ni <= n && nj > 0 && nj <= n && grid[ni][nj] > maxValue) {
                        maxValue = grid[ni][nj];
                        maxd = k;
                    }
                }
                int ni = i + di[maxd], nj = j + dj[maxd];
                ball[i][j]--;
                newBall[ni][nj]++;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ball[i][j] = newBall[i][j];       
}

void findSame() {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (ball[i][j] >= 2) {
                ball[i][j] = 0;
            }
}

int main() {
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> grid[i][j];
    for(int i=1;i<=m;i++) {
        int r, c;
        cin >> r >> c;
        ball[r][c]++;
    }
    while(t > 0) {
        t--;
        move();
        findSame();
    }
    int ballNum = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(ball[i][j]) ballNum++;
    cout << ballNum;
    return 0;
}