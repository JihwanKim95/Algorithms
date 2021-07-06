#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first 
#define Y second

int n;
pair<int, int> s;
pair<int, int> e;
pair<int, int> cur;
int d[300][300];

const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs() {
	queue<pair<int, int> > q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front().X, y = q.front().Y; q.pop();
		if (x == e.X && y == e.Y) {
			printf("%d\n", d[x][y]);
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (d[nx][ny]) continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx, ny });
		}
	}

}


int main() {
	
	int t;
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	cin >> s.X >> s.Y;
	cin >> e.X >> e.Y;

	bfs();
	
	return 0;
}