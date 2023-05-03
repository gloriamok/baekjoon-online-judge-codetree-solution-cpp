#include <iostream>
using namespace std;

struct Consult {
	int t; // 상담을 완료하는데 걸리는 기간
	int p; // 상담을 했을 때 받을 수 있는 금액
};

int n, maxP = 0; // 최대 수익
Consult cst[16]{};

void dfs(int day, int currentP) {
	if (currentP > maxP) maxP = currentP;
	for (int i = day; i <= n; i++) {
		if(i + cst[i].t <= n + 1) { // 기간이 퇴사하기 전까지라면
		dfs(i + cst[i].t, currentP + cst[i].p);
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> cst[i].t >> cst[i].p;
	}
	dfs(1, 0);
	cout << maxP;
}