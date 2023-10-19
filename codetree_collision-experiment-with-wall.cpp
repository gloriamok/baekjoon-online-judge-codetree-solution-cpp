#include <iostream>
using namespace std;
int T, N, M, ball[51][51]{}, dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}, ballNum;

struct Ball{
    int x, y, d;
};
Ball b[2500]{};
bool removed[2500]{};

void move() {
    for(int i=0;i<M;i++) {
        if (!removed[i]) {
            int x = b[i].x, y = b[i].y, d = b[i].d;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                ball[x][y]--;
                ball[nx][ny]++;
                b[i].x = nx;
                b[i].y = ny;
            }
            else {
                b[i].d = (d+2)%4;
                d = b[i].d;
            }
        }
    }
}

void removeSame(int x, int y) {
    for(int i=0;i<M;i++)
        if (!removed[i] && x == b[i].x && y == b[i].y)
            removed[i] = 1;
}

void findSame() {
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if (ball[i][j] >= 2) {
                ballNum -= ball[i][j];
                ball[i][j] = 0;
                removeSame(i,j);
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int tc = 1;tc<=T;tc++) {
        cin >> N >> M;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                ball[i][j] = 0;
        for(int i=0;i<M;i++) removed[i] = 0;
        ballNum = M;
        for(int i=0;i<M;i++) {
            int x, y, intd;
            char d;
            cin >> x >> y >> d;
            switch(d) {
                case 'U':
                    intd = 0;
                    break;
                case 'D':
                    intd = 2;
                    break;
                case 'R':
                    intd = 3;
                    break;
                case 'L':
                    intd = 1;
                    break;
            }
            b[i] = {x,y,intd};
            ball[x][y]++;
        }
        int t = 110;
        while(t && ballNum) {
            t--;
            move();
            findSame();
        }
        cout << ballNum << "\n";
    }
    return 0;
}