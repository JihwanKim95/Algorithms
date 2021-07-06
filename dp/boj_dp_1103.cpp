#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, limit;
int max_count[50][51];
char board[50][51];

void dfs(int x, int y, int cnt) {
	if (ans < cnt) ans = cnt;
	if (ans > limit) return;
	// exception handle 
	if (x < 0 || n <= x || y < 0 || m <= y || board[x][y] == -1) return;
	if (cnt <= max_count[x][y]) return;
	max_count[x][y] = cnt;
	int mul = board[x][y];  
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i] * mul, y + dy[i] * mul, cnt + 1);
	}
}

// 최대로 뛸 수 있는 것보다 많이 뛰면 루프라고 생각 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	limit = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			max_count[i][j] = -1;
		}
	}
	// 정수 배열로 변환 
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'H') board[i][j] = -1;
			else board[i][j] -= '0';
		}
	}
	dfs(0, 0, 0);
	if (ans > limit) ans = -1;
	cout << ans;
}