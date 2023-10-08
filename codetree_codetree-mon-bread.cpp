#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, pplRemaining, t=0;
vector<pair<int,int>> store, ppl;
bool grid[16][16]{}, visited[16][16]{}, arrived[30]{};

void move() {
    int dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};
    for(int i=0;i<ppl.size();i++) {
        if(!arrived[i]) {
            bool tempVisited[16][16]{};
            tempVisited[store[i].first][store[i].second] = 1;
            queue<pair<int,int>> q;
            q.push({store[i].first, store[i].second});
            bool flag = 0;
            while(!q.empty() && !flag) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int k=3;k>=0;k--) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx > 0 && nx <= n && ny > 0 && ny <= n && !tempVisited[nx][ny]) {
                        if (nx == ppl[i].first && ny == ppl[i].second) {
                            ppl[i].first = x;
                            ppl[i].second = y;
                            flag = 1;
                            break;
                        }
                        else if (!visited[nx][ny]) {
                            tempVisited[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
}

void checkifArrived() {
    for(int i=0;i<ppl.size();i++) {
        if(!arrived[i] && ppl[i].first == store[i].first && ppl[i].second == store[i].second) {
            arrived[i] = 1;
            visited[ppl[i].first][ppl[i].second] = 1;
            pplRemaining--;
        }
    }
}

void baseCamp() {
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    int tempVisited[16][16]{};
    tempVisited[store[t-1].first][store[t-1].second] = 1;
    queue<pair<int,int>> q;
    q.push({store[t-1].first, store[t-1].second});
    vector<pair<int,int>> candidates;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx > 0 && nx <= n && ny > 0 && ny <= n && !visited[nx][ny] && !tempVisited[nx][ny]) {
                if (grid[nx][ny]) candidates.push_back({nx,ny});
                tempVisited[nx][ny] = tempVisited[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    int distance = 10000, nx = 20, ny = 20;
    for(int i=0;i<candidates.size();i++) {
        int x = candidates[i].first, y = candidates[i].second;
        if (tempVisited[x][y] < distance) {
            distance = tempVisited[x][y];
            nx = x;
            ny = y;
        }
        else if (tempVisited[x][y] == distance) {
            if (x < nx) {
                nx = x;
                ny = y;
            }
            else if (x == nx && y < ny) ny = y; 
        }
    }
    ppl.push_back({nx,ny});
    visited[nx][ny] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    pplRemaining = m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> grid[i][j];
    for(int i=1;i<=m;i++) {
        int x, y;
        cin >> x >> y;
        store.push_back({x,y});
    }
    while(pplRemaining > 0) {
        t++;
        move();
        checkifArrived();
        if (t <= m) baseCamp();
    }
    cout << t;
    return 0;
}