#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// starting from 12, clockwise 
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int map[10][10];


struct Loc {
	int x;
	int y;

	Loc(int m, int n) {
		x = m;
		y = n;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	
	int cnt = 0;
	queue<Loc> q;

	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> map[i][j];
		}
	}

	// bfs 
	q.push(Loc(1, 1));
	while (!q.empty()) {
		int xpop = q.front().x;
		int ypop = q.front().y;
		cnt = map[xpop][ypop];
		if (xpop == 7 && ypop == 7) {
			cout << cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xx = xpop + dx[i];
			int yy = ypop + dy[i];
			if (xx < 1 || xx > 7 || yy < 1 || yy > 7) continue;
			if (map[xx][yy] == 0) {
				q.push(Loc(xx, yy));
				map[xx][yy] = map[xpop][ypop] + 1;
			}
		}
		
		q.pop();
	}

	if (q.empty()) cout << -1;

	return 0;

}