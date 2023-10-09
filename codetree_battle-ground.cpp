#include <iostream>
#include <vector>
using namespace std;

struct Gun{
    int x,y,power;
};

struct Player{
    int x,y,d,s,power,gunIdx,point;
};

int n, m, k, gun[21][21]{}, player[21][21]{}, dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
Player p[30];
vector<Gun> g;

void move(int idx) {
    int x = p[idx].x, y = p[idx].y, d = p[idx].d;
    int nx = x + dx[d], ny = y + dy[d];
    if(!(nx > 0 && nx <= n && ny > 0 && ny <= n)) {
        p[idx].d = (d+2)%4;
        d = p[idx].d;
        nx = x + dx[d];
        ny = y + dy[d];
    }
    p[idx].x = nx;
    p[idx].y = ny;
    player[x][y]--;
    player[nx][ny]++;
}

void getGun(int idx) {
    int x = p[idx].x, y = p[idx].y;
    if (gun[x][y]) {
        int maxPower = 0, maxGunIdx;
        int gunNum = gun[x][y];
        for(int i=0;i<g.size() && gunNum;i++) {
            if (g[i].x == x && g[i].y == y) {
                gunNum--;
                if (g[i].power > maxPower) {
                    maxPower = g[i].power;
                    maxGunIdx = i;
                }
            }
        }
        if (p[idx].power) {
            if (maxPower > p[idx].power) {
                int tempGunIdx = p[idx].gunIdx;
                p[idx].power = maxPower;
                p[idx].gunIdx = maxGunIdx;
                g[maxGunIdx].x = 0;
                g[maxGunIdx].y = 0;
                g[tempGunIdx].x = x;
                g[tempGunIdx].y = y;
            }
        }
        else {
            gun[x][y]--;
            p[idx].power = maxPower;
            p[idx].gunIdx = maxGunIdx;
            g[maxGunIdx].x = 0;
            g[maxGunIdx].y = 0;
        }
    }
}

void lostPlayer(int idx) {
    int x = p[idx].x, y = p[idx].y, d = p[idx].d;
    if (p[idx].power) {
        gun[x][y]++;
        p[idx].power = 0;
        g[p[idx].gunIdx].x = x;
        g[p[idx].gunIdx].y = y;
    }
    int nx = x + dx[d], ny = y + dy[d];
    while(!(nx > 0 && nx <= n && ny > 0 && ny <= n && !player[nx][ny])) {
        p[idx].d = (d+1)%4;
        d = p[idx].d;
        nx = x + dx[d];
        ny = y + dy[d];
    }
    p[idx].x = nx;
    p[idx].y = ny;
    player[x][y]--;
    player[nx][ny]++;
    getGun(idx);
}

void getOrFight(int idx) {
    int x = p[idx].x, y = p[idx].y;
    if (player[x][y] == 1) {
        getGun(idx);
    }
    else {
        int idx2;
        for(int i=0;i<m;i++) {
            if (i != idx && p[i].x == x && p[i].y == y) {
                idx2 = i;
                break;
            }
        }
        int lose, win;
        if (p[idx].s + p[idx].power > p[idx2].s + p[idx2].power) {
            win = idx;
            lose = idx2;
        }
        else if (p[idx].s + p[idx].power == p[idx2].s + p[idx2].power) {
            if (p[idx].s > p[idx2].s) {
                win = idx;
                lose = idx2;
            }
            else {
                win = idx2;
                lose = idx;
            }
        }
        else {
            win = idx2;
            lose = idx;
        }
        p[win].point += (p[win].s + p[win].power - p[lose].s - p[lose].power);
        lostPlayer(lose);
        getGun(win);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int power;
            cin >> power;
            if (power) {
            g.push_back({i,j,power});
            gun[i][j]++;
            }
        }
    }
    for(int i=0;i<m;i++) {
        int x,y,d,s;
        cin >> x >> y >> d >> s;
        p[i] = {x,y,d,s,0,0,0};
        player[x][y]++;
    }
    while(k > 0) {
        k--;
        for(int i=0;i<m;i++) {
            move(i);
            getOrFight(i);
        }
    }
    for(int i=0;i<m;i++) cout << p[i].point << " ";
    return 0;
}