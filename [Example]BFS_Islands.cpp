#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, cnt = 0;
int map[30][30];

// 12시부터 시계방향
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

queue<pair<int, int> > q;

void BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// push to queue
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));

				while(!q.empty()) {  // runs until a whole island is searched 
					// push surrounding
					for (int k = 0; k < 8; k++) {
						int tmpx = q.front().first + dx[k];
						int tmpy = q.front().second + dy[k];
						if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n && map[tmpx][tmpy] == 1) {
							q.push(make_pair(tmpx, tmpy));
						}
					}
					//pop
					map[q.front().first][q.front().second] = 0;
					q.pop();
				}
				cnt++; 
			}

		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	BFS();
	cout << cnt;
	
	return 0;
}