#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* 바이러스 */
using namespace std; 

queue<int> q;
vector<int> com[105];
int vis[105];

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	
	// n = number of computers
	// m = number of connections
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}	
	q.push(1);
	vis[1] = 1;
	int infected = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int dir = 0; dir < com[cur].size(); dir++) {
			int nx = com[cur][dir];
			if (vis[nx]) continue;
			q.push(nx);
			vis[nx] = 1;
			infected++;
		}
	}
	cout << infected << '\n';
	return 0;
}