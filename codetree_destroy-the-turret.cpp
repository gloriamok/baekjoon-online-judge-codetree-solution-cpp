#include <iostream>
#include <queue>
using namespace std;
int N, M, K, turret[10][10]{}, recent[10][10]{}, numOfTurret = 0;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0}, dx8[8]={0,0,1,-1,1,1,-1,-1},dy8[8]={1,-1,0,0,1,-1,1,-1};

int main() {
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> turret[i][j];
        if(turret[i][j] > 0) numOfTurret++;
    }
    for(int turn=1;turn<=K && numOfTurret>1;turn++) {
        bool attack[10][10]{};
        // find minPowerTurret and maxPowerTurret
        int minPower = 10000, maxPower = 0;
        pair<int,int> minPowerTurret = {-1,-1}, maxPowerTurret = {10,10};
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if (turret[i][j] > 0) {
                    if (turret[i][j] < minPower) {
                        minPower = turret[i][j];
                        minPowerTurret = {i,j};
                    }
                    else if (turret[i][j] == minPower) {
                        if(recent[i][j] > recent[minPowerTurret.first][minPowerTurret.second])
                            minPowerTurret = {i,j};
                        else if(recent[i][j] == recent[minPowerTurret.first][minPowerTurret.second]) {
                            if(i + j > minPowerTurret.first + minPowerTurret.second)
                                minPowerTurret = {i,j};
                            else if(i + j == minPowerTurret.first + minPowerTurret.second && j > minPowerTurret.second)
                                minPowerTurret = {i,j};
                        }
                    }
                    if (turret[i][j] > maxPower) {
                        maxPower = turret[i][j];
                        maxPowerTurret = {i,j};
                    }
                    else if (turret[i][j] == maxPower) {
                        if(recent[i][j] < recent[maxPowerTurret.first][maxPowerTurret.second])
                            maxPowerTurret = {i,j};
                        else if(recent[i][j] == recent[maxPowerTurret.first][maxPowerTurret.second]) {
                            if(i + j < maxPowerTurret.first + maxPowerTurret.second)
                                maxPowerTurret = {i,j};
                            else if(i + j == maxPowerTurret.first + maxPowerTurret.second && j < maxPowerTurret.second)
                                maxPowerTurret = {i,j};
                        }
                    }
                }
            }
        }
        recent[minPowerTurret.first][minPowerTurret.second] = turn;
        turret[minPowerTurret.first][minPowerTurret.second] += (N + M);
        attack[minPowerTurret.first][minPowerTurret.second] = 1;
        attack[maxPowerTurret.first][maxPowerTurret.second] = 1;
        // 레이저 공격
        bool visited[10][10]{};
        pair<int,int> laser[10][10]{};
        queue<pair<int,int>> q;
        q.push({minPowerTurret.first, minPowerTurret.second});
        bool flag = 0;
        while(!q.empty() && !flag) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0) nx += N;
                else if (nx >= N) nx -= N;
                if (ny < 0) ny += M;
                else if (ny >= M) ny -= M;
                if (turret[nx][ny] > 0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    laser[nx][ny] = {x,y};
                    q.push({nx,ny});
                    if (nx == maxPowerTurret.first && ny == maxPowerTurret.second) flag = 1;
                }
            }
        }
        int x = maxPowerTurret.first, y = maxPowerTurret.second;
        turret[x][y] -= turret[minPowerTurret.first][minPowerTurret.second];
        if(turret[x][y] <= 0) {
            turret[x][y] = 0;
            numOfTurret--;
        }
        if (flag) {
            while(!(laser[x][y].first==minPowerTurret.first&&laser[x][y].second==minPowerTurret.second)) {
                int nx = laser[x][y].first, ny = laser[x][y].second;
                turret[nx][ny] -= (turret[minPowerTurret.first][minPowerTurret.second]/2);
                if(turret[nx][ny] <= 0) {
                    turret[nx][ny] = 0;
                    numOfTurret--;
                }
                attack[nx][ny] = 1;
                x = nx;
                y = ny;
            }
        }
        // 포탄 공격
        else {
            for(int k=0;k<8;k++) {
                int nx = x + dx8[k], ny = y + dy8[k];
                if (nx < 0) nx += N;
                else if (nx >= N) nx -= N;
                if (ny < 0) ny += M;
                else if (ny >= M) ny -= M;
                if (turret[nx][ny] > 0 && !(nx==minPowerTurret.first&&ny==minPowerTurret.second)) {
                    turret[nx][ny] -= (turret[minPowerTurret.first][minPowerTurret.second]/2);
                    if(turret[nx][ny] <= 0) {
                        turret[nx][ny] = 0;
                        numOfTurret--;
                    }
                    attack[nx][ny] = 1;
                }
            }
        }
        // 포탑 정비
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(turret[i][j] > 0 && !attack[i][j]) turret[i][j]++;
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(turret[i][j] > ans) ans = turret[i][j];
    cout << ans;
    return 0;
}