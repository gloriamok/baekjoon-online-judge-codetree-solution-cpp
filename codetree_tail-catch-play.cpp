#include <iostream>
#include <queue>
using namespace std;
int n, m, k, rnd = 0, info[20][20]{}, dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0}, pnt = 0;

void move() {
    int newInfo[20][20]{};
    bool visited[20][20]{};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // move 1
            if(info[i][j] == 1) {
                bool flag = 0;
                // find 4
                for(int l=0;l<4;l++) {
                    int nx = i + dx[l], ny = j + dy[l];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && info[nx][ny] == 4) {
                        flag = 1;
                        newInfo[nx][ny] = 1;
                    }
                }
                // if there's no 4 around 1, find 3
                if(!flag) {
                    for(int l=0;l<4;l++) {
                        int nx = i + dx[l], ny = j + dy[l];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && info[nx][ny] == 3) {
                            newInfo[nx][ny] = 1;
                        }
                    }
                }
                // move 2 and 3
                visited[i][j] = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                int x, y;
                while(!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for(int l=0;l<4;l++) {
                        int nx = x + dx[l], ny = y + dy[l];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && info[nx][ny] == 2 && !visited[nx][ny]) {
                            newInfo[x][y] = info[nx][ny];
                            visited[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                for(int l=0;l<4;l++) {
                    int nx = x + dx[l], ny = y + dy[l];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && info[nx][ny] == 3 && !visited[nx][ny]) {
                        newInfo[x][y] = info[nx][ny];
                        visited[nx][ny] = 1;
                        if (!newInfo[nx][ny]) {
                            newInfo[nx][ny] = 4;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (newInfo[i][j]) info[i][j] = newInfo[i][j];
        }
    }
}

void switchHeadAndTail(int i, int j) {
    bool headFlag = 0, tailFlag = 0;
    pair<int,int> head, tail;
    if (info[i][j] == 1) {
        headFlag = 1;
        head = {i,j};
    }
    else if (info[i][j] == 3) {
        tailFlag = 1;
        tail = {i,j};
    }
    bool visited[20][20]{};
    visited[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty() && !(headFlag && tailFlag)) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int l=0;l<4;l++) {
            int nx = x + dx[l], ny = y + dy[l];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && info[nx][ny] && info[nx][ny] != 4 && !visited[nx][ny]) {
                if (info[nx][ny] == 1) {
                    headFlag = 1;
                    head = {nx,ny};
                }
                else if (info[nx][ny] == 3) {
                    tailFlag = 1;
                    tail = {nx,ny};
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    info[head.first][head.second] = 3;
    info[tail.first][tail.second] = 1;
}

void scorePnt(int i, int j) {
    if (info[i][j]==1) {
        pnt+=1;
    }
    else if (info[i][j]==3) {
        int order = 1;
        bool visited[20][20]{};
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int l=0;l<4;l++) {
                int nx = x + dx[l], ny = y + dy[l];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && (info[nx][ny] == 1 || info[nx][ny] == 2) && !visited[nx][ny]) {
                    order++;
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        pnt+=(order*order);
    }
    else {
        int order, visited[20][20]{};
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int l=0;l<4;l++) {
                int nx = x + dx[l], ny = y + dy[l];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && (info[nx][ny] == 2 || info[nx][ny] == 1) && !visited[nx][ny]) {
                    if (info[nx][ny] == 1) {
                        order = visited[x][y] + 1;
                    }
                    else {
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        pnt+=(order*order);
    }
    switchHeadAndTail(i,j);
}

void ball() {
    int d = (rnd/n)%4;
    int first = rnd%n;
    int x, y;
    switch(d) {
        case 0:
            x = first;
            y = 0;
            break;
        case 1:
            x = n-1;
            y = first;
            break;
        case 2:
            x = n-first-1;
            y = n-1;
            break;
        case 3:
            x = 0;
            y = n-first-1;
            break;
    }
    int nx = x, ny = y;
    bool flag = 0;
    while(nx >= 0 && nx < n && ny >= 0 && ny < n && !flag) {
        if (info[nx][ny] && info[nx][ny] != 4) {
            flag = 1;
            scorePnt(nx,ny);
        }
        x = nx;
        y = ny;
        nx = x + dx[d];
        ny = y + dy[d];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> info[i][j];
    while(rnd < k) {
        move();
        ball();
        rnd++;
    }
    cout << pnt;
    return 0;
}