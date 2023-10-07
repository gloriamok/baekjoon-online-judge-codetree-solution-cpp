#include <iostream>
#include <vector>
using namespace std;

int N, M, K, numOfRemainingP, maze[10][10]{}, ex, ey;
bool exitP[10]{};
vector<pair<int,int>> p;
int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1}, numOfPMoved = 0;

void Move() {
    for(int idx=0;idx<p.size();idx++) {
        if (!exitP[idx]) {
            int i = p[idx].first, j = p[idx].second;
            int minDistance = abs(ex - i) + abs(ey - j), mini = i, minj = j;
            for(int k=0;k<4;k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && !maze[ni][nj] && (abs(ex - ni) + abs(ey - nj)) < minDistance) {
                    minDistance = abs(ex - ni) + abs(ey - nj);
                    mini = ni;
                    minj = nj;
                }
            }
            if (!(mini == i && minj == j)) {
                numOfPMoved++;
                p[idx].first = mini;
                p[idx].second = minj;
            }
            if (minDistance == 0) {
                numOfRemainingP--;
                exitP[idx] = 1;
            }
        }
    }
}

void Rotate(int minSquare, int minr, int minc) {
    int newMaze[10][10]{}, rotatedMaze[10][10]{};
    bool visitedP[10]{}, visitedE = 0;
    for(int i=minr;i<minr+minSquare+1;i++){
        for(int j=minc;j<minc+minSquare+1;j++) {
            newMaze[i-minr][j-minc] = maze[i][j];
            maze[i][j] = 0;
            for(int idx=0;idx<p.size();idx++) {
                if (!exitP[idx] && !visitedP[idx] && p[idx].first == i && p[idx].second == j) {
                    visitedP[idx] = 1;
                    int newX = i-minr, newY = j-minc;
                    int tempX = newX;
                    newX = newY;
                    newY = minSquare-tempX;
                    p[idx].first = newX + minr;
                    p[idx].second = newY + minc;
                }
            }
            if (!visitedE && ex == i && ey == j) {
                visitedE = 1;
                int newEX = i-minr, newEY = j-minc;
                int tempEX = newEX;
                newEX = newEY;
                newEY = minSquare-tempEX;
                ex = newEX + minr;
                ey = newEY + minc;
            }
        }
    }
    for(int i=0;i<minSquare+1;i++) {
        for(int j=0;j<minSquare+1;j++) {
            if (newMaze[i][j]) {
                rotatedMaze[j][minSquare-i] = newMaze[i][j] - 1;
            }
        }
    }
    for(int i=0;i<minSquare+1;i++) {
        for(int j=0;j<minSquare+1;j++) {
            maze[i+minr][j+minc] = rotatedMaze[i][j];
        }
    }
}

void ChooseSquare() {
    if (numOfRemainingP > 0) {
        int minSquare = 11, minr = 11, minc = 11;
        for(int idx=0;idx<p.size();idx++) {
            if (!exitP[idx]) {
                int i = p[idx].first, j = p[idx].second;
                int square = max(abs(ex - i),abs(ey - j)), r, c;
                if (abs(ex - i) == square) r = min(ex,i);
                else {
                    r = min(ex,i) - (square - abs(ex - i));
                    if (r < 0) r = 0;
                }
                if (abs(ey - j) == square) c = min(ey,j);
                else {
                    c = min(ey,j) - (square - abs(ey - j));
                    if (c < 0) c = 0;
                }
                if (square < minSquare) {
                    minSquare = square;
                    minr = r;
                    minc = c;
                }
                else if (square == minSquare) {
                    if (r < minr) {
                        minr = r;
                        minc = c;
                    }
                    else if (r == minr && c < minc) {
                        minc = c;
                    }
                }
            }
        }
        Rotate(minSquare, minr, minc);
    }
}

int main() {
    cin >> N >> M >> K;
    numOfRemainingP = M;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> maze[i][j];
    for(int i=1;i<=M;i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x-1,y-1});
    }
    cin >> ex >> ey;
    ex--;
    ey--;
    while(K > 0 && numOfRemainingP > 0) {
        K--;
        Move();
        ChooseSquare();
    }
    cout << numOfPMoved << "\n" << ex + 1 << " " << ey + 1;
    return 0;
}