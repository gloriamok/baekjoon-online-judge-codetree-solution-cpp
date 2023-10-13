#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 4;
int numOfM, t, px, py, monsters[MAX_N+1][MAX_N+1]{}, deadMonsters[MAX_N+1][MAX_N+1]{}, dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,-1,-1,-1,0,1,1,1}, maxValue;
vector<pair<int,int>> maxOrder;

struct Monster{
    int x,y,d;
    bool dead;
};

struct Egg{
    int x,y,d;
};

vector<Monster> m;
vector<Egg> e;

void LayEggs() {
    for(int i=0;i<m.size();i++) {
        if (!m[i].dead) {
            e.push_back({m[i].x,m[i].y,m[i].d});
        }
    }
}

void MoveMonsters() {
    for(int i=0;i<m.size();i++) {
        if (!m[i].dead) {
            int x = m[i].x, y = m[i].y, d = m[i].d;
            int nx = x + dx[d], ny = y + dy[d];
            bool flag = 0;
            while(!(nx > 0 && nx <= MAX_N && ny > 0 && ny <= MAX_N && !deadMonsters[nx][ny] && !(nx == px && ny == py))) {
                d = (d+1)%8;
                nx = x + dx[d];
                ny = y + dy[d];
                if (d == m[i].d) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                m[i].x = nx;
                m[i].y = ny;
                m[i].d = d;
                monsters[x][y]--;
                monsters[nx][ny]++;
            }
        }
    }
}

void FindDirections(int x, int y, int kan, int value, vector<pair<int,int>> order) {
    if (kan == 3) {
        if (value > maxValue) {
            maxValue = value;
            maxOrder = order;
        }
        return;
    }
    for(int k=0;k<8;k=k+2) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx > 0 && nx <= MAX_N && ny > 0 && ny <= MAX_N) {
            bool flag = 0;
            for(int i=0;i<order.size() && !flag;i++) {
                if (nx == order[i].first && ny == order[i].second) flag = 1;
            }
            order.push_back({nx,ny});
            if (flag) FindDirections(nx, ny, kan+1, value, order);
            else FindDirections(nx, ny, kan+1, value + monsters[nx][ny], order);
            order.pop_back();
        }
    }
}

void EatMonsters() {
    for(int i=0;i<m.size()&&monsters[px][py];i++) {
        if (!m[i].dead && m[i].x == px && m[i].y == py) {
            m[i].dead = 1;
            monsters[px][py]--;
        }
    }
}

void MovePacman() {
    maxValue = -1;
    vector<pair<int,int>> order;
    FindDirections(px,py,0,0,order);
    for(int i=0;i<maxOrder.size();i++) {
        px = maxOrder[i].first;
        py = maxOrder[i].second;
        if (monsters[px][py]) {
            deadMonsters[px][py] = 1;
            EatMonsters();
        }
    }
}

void EraseDeadMonsters() {
    for(int i=1;i<=MAX_N;i++) {
        for(int j=1;j<=MAX_N;j++) {
            if (deadMonsters[i][j]) {
                if (deadMonsters[i][j] == 3) deadMonsters[i][j] = 0;
                else deadMonsters[i][j]++;
            }
        }
    }
}

void EggsToMonsters() {
    for(int i=0;i<e.size();i++) {
        m.push_back({e[i].x,e[i].y,e[i].d,0});
        monsters[e[i].x][e[i].y]++;
    }
    e.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> numOfM >> t >> px >> py;
    for(int i=1;i<=numOfM;i++) {
        int x, y, d;
        cin >> x >> y >> d;
        d--;
        m.push_back({x,y,d,0});
        monsters[x][y]++;
    }
    while(t) {
        t--;
        LayEggs();
        MoveMonsters();
        MovePacman();
        EraseDeadMonsters();
        EggsToMonsters();
    }
    int remainingMonsters = 0;
    for(int i=1;i<=MAX_N;i++)
        for(int j=1;j<=MAX_N;j++)
            remainingMonsters += monsters[i][j];
    cout << remainingMonsters;
    return 0;
}