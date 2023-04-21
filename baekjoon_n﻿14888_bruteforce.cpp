#include <iostream>
using namespace std;

int n, A[11]{}, op[4]{}, minResult = 1000000000, maxResult = -1000000000;

int operation(int opNo, int nNo, int result) {
	if (opNo == 0) result += A[nNo];
	else if (opNo == 1) result -= A[nNo];
	else if (opNo == 2) result *= A[nNo];
	else result /= A[nNo];
	return result;
}

void dfs(int nNo, int result) {
	if (nNo == n) { // 모든 수를 연산했다면
		if (result < minResult) minResult = result;
		if (result > maxResult) maxResult = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i]--;
			int result2 = operation(i, nNo, result); // nNo번째 연산 결과를 result2에 저장
			dfs(nNo+1,result2);
			op[i]++;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	int result = A[0];
	dfs(1, result);
	cout << maxResult << "\n" << minResult;
}