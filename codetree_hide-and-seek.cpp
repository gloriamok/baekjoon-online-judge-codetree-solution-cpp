#include <iostream>
#include <vector>
using namespace std;

int n, m, h, k, t = 0, l = 0, lengthIdx = 0, pnt = 0, runners[100][100]{}, length[197]{};
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
bool cw = 1, trees[100][100]{};

struct Runner{
    int x, y, d;
    bool caught;
};
vector<Runner> r;

struct Catcher{
    int x, y, d;
};
Catcher c;

void MoveRunners() {
    for(int i=0;i<r.size();i++) {
        if (!r[i].caught && (abs(c.x-r[i].x)+abs(c.y-r[i].y)<=3)) {
            int x = r[i].x, y = r[i].y, d = r[i].d;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                if (!(nx == c.x && ny == c.y)) {
                    r[i].x = nx;
                    r[i].y = ny;
                    runners[x][y]--;
                    runners[nx][ny]++;
                }
            }
            else {
                r[i].d = (r[i].d+2)%4;
                d = r[i].d;
                nx = x + dx[d];
                ny = y + dy[d];
                if (!(nx == c.x && ny == c.y)) {
                    r[i].x = nx;
                    r[i].y = ny;
                    runners[x][y]--;
                    runners[nx][ny]++;
                }
            }
        }
    }
}

void CatchRunners() {
    int nx = c.x, ny = c.y, kan = 0, numRunners = 0;
    while(nx > 0 && nx <= n && ny > 0 && ny <= n && kan < 3) {
        if (runners[nx][ny] && !trees[nx][ny]) {
            numRunners += runners[nx][ny];
            for(int i=0,j=0;i<r.size() && j<runners[nx][ny];i++) {
                if (!r[i].caught && nx == r[i].x && ny == r[i].y) {
                    j++;
                    r[i].caught = 1;
                }
            }
            runners[nx][ny] = 0;
        }
        nx += dx[c.d];
        ny += dy[c.d];
        kan++;
    }
    pnt += (t*numRunners);
}

void MoveCatcher() {
    c.x = c.x + dx[c.d];
    c.y = c.y + dy[c.d];
    l++;
    if (l == length[lengthIdx]) {
        if (cw) c.d = (c.d+1)%4;
        else c.d = (c.d-1+4)%4;
        CatchRunners();
        if ((c.x == 1 && c.y == 1) || (c.x == (n+1)/2 && c.y == (n+1)/2)) {
            if (cw) c.d = (c.d+1)%4;
            else c.d = (c.d-1+4)%4;
            cw = !cw;
        }
        else {
            if (cw) lengthIdx++;
            else lengthIdx--;
        }
        l = 0;
    }
    else CatchRunners();
}

int main() {
    cin >> n >> m >> h >> k;
    for(int i=1;i<=m;i++) {
        int x, y, d;
        cin >> x >> y >> d;
        r.push_back({x,y,d,0});
        runners[x][y] = 1;
    }
    for(int i=1;i<=h;i++) {
        int x, y;
        cin >> x >> y;
        trees[x][y] = 1;
    }
    c = {(n+1)/2,(n+1)/2,0};
    for(int i=0,j=0;i<(n*2)-1;i++) {
        if (i%2==0) j++;
        length[i] = j;
    }
    length[(n*2)-2] = n-1;
    while(t < k) {
        t++;
        MoveRunners();
        
        MoveCatcher();
    }
    cout << pnt;
    return 0;
}