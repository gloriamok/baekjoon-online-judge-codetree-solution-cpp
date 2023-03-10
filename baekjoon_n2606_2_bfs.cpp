#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> virus[101]{};

int BFS(int w) {
	int visited[101]{}, cnt = 0;
	queue<int> q;
	visited[w]++;
	q.push(w);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int a : virus[f])
			if (!visited[a]) {
				q.push(a);
				visited[a]++;
				cnt++;
			}
	}
	return cnt;
}

int main() {
	int n, m, u ,v;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		virus[u].push_back(v);
		virus[v].push_back(u);
	}
	cout << BFS(1);
}
