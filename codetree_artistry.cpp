#include <iostream>
#include <queue>
using namespace std;
int n, colors[29][29]{}, groups[29][29]{}, dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
long int points = 0;
vector<int> numOfKan;

struct Harmony{
    // 그룹 b의 GroupIdx, 그룹 b를 이루고 있는 숫자 값, 서로 맞닿아 있는 변의 수
    int idx, color, lines;
};

void FindGroupIdx() {
    int idx = 0, num;
    bool visited[29][29]{};
    numOfKan.clear();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (!visited[i][j]) {
                groups[i][j] = idx;
                num = 1;
                visited[i][j]=1;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && colors[x][y] == colors[nx][ny]) {
                            groups[nx][ny] = idx;
                            num++;
                            visited[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                idx++;
                numOfKan.push_back(num);
            }
        }
    }
}

void GetPoints() {
    bool visited[29][29]{};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (!visited[i][j]) {
                visited[i][j]=1;
                queue<pair<int,int>> q;
                q.push({i,j});
                vector<Harmony> h;
                while(!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                            if (colors[x][y] == colors[nx][ny]) {
                                visited[nx][ny] = 1;
                                q.push({nx,ny});
                            }
                            else {
                                bool flag = 0;
                                for(int i=0;i<h.size() && !flag;i++) {
                                    if (h[i].idx == groups[nx][ny]) {
                                        h[i].lines++;
                                        flag = 1;
                                    }
                                }
                                if (!flag) h.push_back({groups[nx][ny], colors[nx][ny], 1});
                            }
                        }
                    }
                }
                int aIdx = groups[i][j];
                for(int idx=0;idx<h.size();idx++) {
                    int bIdx = h[idx].idx;
                    points += (numOfKan[aIdx] + numOfKan[bIdx]) * colors[i][j] * h[idx].color * h[idx].lines;
                }
            }
        }
    }
}

void RotateCross() {
    int newColors[29][29]{};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (i == (n - 1) / 2 || j == (n - 1) / 2) newColors[n - 1 - j][i] = colors[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (newColors[i][j]) colors[i][j] = newColors[i][j];
        }
    }
}

void Rotate(int x1, int x2, int y1, int y2) {
    int newColors[14][14]{}, tempColors[14][14]{};
    for(int i=0;i<(n-1)/2;i++) {
        for(int j=0;j<(n-1)/2;j++) {
            newColors[i][j] = colors[i+x1][j+y1];
        }
    }
    for(int i=0;i<(n-1)/2;i++) {
        for(int j=0;j<(n-1)/2;j++) {
            tempColors[j][(n-1)/2-1-i] = newColors[i][j];
        }
    }
    for(int i=0;i<(n-1)/2;i++) {
        for(int j=0;j<(n-1)/2;j++) {
            newColors[i][j] = tempColors[i][j];
        }
    }
    for(int i=0;i<(n-1)/2;i++) {
        for(int j=0;j<(n-1)/2;j++) {
            colors[i+x1][j+y1] = newColors[i][j];
        }
    }
}

void RotateSquares() {
    Rotate(0,(n-1)/2,0,(n-1)/2);
    Rotate(0,(n-1)/2,(n+1)/2,n);
    Rotate((n+1)/2,n,0,(n-1)/2);
    Rotate((n+1)/2,n,(n+1)/2,n);
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> colors[i][j];
        }
    }
    FindGroupIdx();
    GetPoints();
    for(int t=1;t<=3;t++) {
        RotateCross();
        RotateSquares();
        FindGroupIdx();
        GetPoints();
    }
    cout << points;
    return 0;
}