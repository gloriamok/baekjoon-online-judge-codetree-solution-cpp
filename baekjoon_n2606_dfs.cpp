#include <iostream>
#include <vector>
using namespace std;

vector<int> virus[101]{};
int visited[101]{}, cnt = 0;

void DFS(int w) {
	for (int a : virus[w])
		if (!visited[a]) {
			visited[a]++;
			cnt++;
			DFS(a);
		}
}

int main() {
	int n, m, u ,v;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		virus[u].push_back(v);
		virus[v].push_back(u);
	}
	visited[1]++;
	DFS(1);
	cout << cnt;
}