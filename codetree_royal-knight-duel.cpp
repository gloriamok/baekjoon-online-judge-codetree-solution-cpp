#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_L = 40;
int L, N, Q, chess[MAX_L+1][MAX_L+1]{}, knights[MAX_L+1][MAX_L+1]{};
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

struct Knight{
    int x,y,h,w,k,damaged;
    bool removed;
};
vector<Knight> kn;
vector<pair<int,int>> command;
vector<int> v;

void Move(int idx, int d) {
    if (kn[idx].removed) return;
    int ix = kn[idx].x, iy = kn[idx].y, ih = kn[idx].h, iw = kn[idx].w;
    bool visited[MAX_L+1][MAX_L+1]{};
    queue<pair<int,int>> q;
    for(int i=ix;i<=ix+ih-1;i++) {
        for(int j=iy;j<=iy+iw-1;j++) {
            visited[i][j] = 1;
            q.push({i,j});
        }
    }
    bool flag = 0;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int nx = x + dx[d], ny = y + dy[d];
        // 벽이 아니라면
        if (nx > 0 && nx <= L && ny > 0 && ny <= L && chess[nx][ny] != 2) {
            // 방문하지 않았다면, 다른 로봇이거나 빈칸
            if (!visited[nx][ny]) {
                // 다른 로봇이라면
                if (knights[nx][ny]) {
                    int pIdx = knights[nx][ny];
                    v.push_back(pIdx);
                    int px = kn[pIdx].x, py = kn[pIdx].y, ph = kn[pIdx].h, pw = kn[pIdx].w;
                    for(int i=px;i<=px+ph-1;i++) {
                        for(int j=py;j<=py+pw-1;j++) {
                            visited[i][j] = 1;
                            q.push({i,j});
                        }
                    }
                }
            }
        }
        // 벽이라면
        else {
            flag = 1;
            v.clear();
            break;
        }
    }
    // 벽이 있다면
    if (flag) return;

    int newKnights[MAX_L+1][MAX_L+1]{};

    // 명령을 받은 기사 이동
    for(int i=ix;i<=ix+ih-1;i++) {
        for(int j=iy;j<=iy+iw-1;j++) {
            knights[i][j] = 0;
            int ni = i + dx[d], nj = j + dy[d];
            newKnights[ni][nj] = idx;
        }
    }
    kn[idx].x += dx[d];
    kn[idx].y += dy[d];

    // 밀려난 기사 이동
    for(int idx=0;idx<v.size();idx++) {
        int pIdx = v[idx];
        int px = kn[pIdx].x, py = kn[pIdx].y, ph = kn[pIdx].h, pw = kn[pIdx].w;
        for(int i=px;i<=px+ph-1;i++) {
            for(int j=py;j<=py+pw-1;j++) {
                knights[i][j] = 0;
                int ni = i + dx[d], nj = j + dy[d];
                newKnights[ni][nj] = pIdx;
            }
        }
        kn[pIdx].x += dx[d];
        kn[pIdx].y += dy[d];
    }
    for(int i=1;i<=L;i++) {
        for(int j=1;j<=L;j++) {
            if (newKnights[i][j]) knights[i][j] = newKnights[i][j];
        }
    }
}

void Damage() {
    for(int idx=0;idx<v.size();idx++) {
        int pIdx = v[idx];
        int px = kn[pIdx].x, py = kn[pIdx].y, ph = kn[pIdx].h, pw = kn[pIdx].w;
        for(int i=px;i<=px+ph-1;i++) {
            for(int j=py;j<=py+pw-1;j++) {
                if (chess[i][j] == 1) kn[pIdx].damaged++;
            }
        }
        if (kn[pIdx].k <= kn[pIdx].damaged) {
            kn[pIdx].removed = 1;
            for(int i=px;i<=px+ph-1;i++) {
                for(int j=py;j<=py+pw-1;j++) {
                    knights[i][j] = 0;
                }
            }
        }
    }
    v.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> N >> Q;
    for(int i=1;i<=L;i++) {
        for(int j=1;j<=L;j++) {
            cin >> chess[i][j];
        }
    }
    kn.push_back({0,0,0,0,0,0,1});
    for(int idx=1;idx<=N;idx++) {
        int x,y,h,w,k;
        cin >> x >> y >> h >> w >> k;
        kn.push_back({x,y,h,w,k,0,0});
        for(int i=x;i<=x+h-1;i++) {
            for(int j=y;j<=y+w-1;j++) {
                knights[i][j] = idx;
            }
        }
    }
    for(int i=1;i<=Q;i++) {
        int idx, d;
        cin >> idx >> d;
        command.push_back({idx,d});
    }
    for(int i=0;i<Q;i++) {
        Move(command[i].first, command[i].second);
        Damage();
    }
    int totalDamage = 0;
    for(int idx=1;idx<=N;idx++) {
        if (!kn[idx].removed) totalDamage += kn[idx].damaged;
    }
    cout << totalDamage;
    return 0;
}