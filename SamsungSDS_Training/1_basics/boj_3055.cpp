#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int r, c;
char forest[51][51];

pii bieber, ddg;
vector<pii> water;
int water_vt[51][51], ddg_vt[51][51];
queue<pii> ddg_q, water_q;
int ans;

// 상 우 하 좌 
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


bool check_rc(int param_r, int param_c) {
	return 0 <= param_r && param_r < r && 0 <= param_c && param_c < c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("../../../input.txt", "r", stdin);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> forest[i];
	}
	// 위치구분 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (forest[i][j] == '*') water.push_back(pii(i, j));
			if (forest[i][j] == 'D') bieber = pii(i, j);
			if (forest[i][j] == 'S') ddg = pii(i, j); 
		}
	}
	// debug 출력 
	//cout << "ddg : " << ddg.first << ddg.second << '\n';
	//cout << "bieber : " << bieber.first << ',' << bieber.second << '\n';
	//cout << "water : " << water.front().first << ','  << water.front().second << '\n';
	
	for (int i = 0; i < water.size(); i++) {
		pii cur_water = water[i];
		water_q.push(cur_water);
		water_vt[cur_water.first][cur_water.second] = 1;
	}
	ddg_q.push(ddg);
	ddg_vt[ddg.first][ddg.second] = 1;
	// bfs 
	while (!ddg_q.empty()) {
		// 물 이동 : q에서 하나 꺼내고 상 하 좌 우 이동, 비버와 돌 접근 불가  
		int water_qsz = water_q.size();
		for (int i = 0; i < water_qsz; i++) {
			pii cur_water = water_q.front();
			water_q.pop();
			for (int j = 0; j < 4; j++) {
				int nx, ny;
				nx = cur_water.first + dx[j];
				ny = cur_water.second + dy[j];
				if (!check_rc(nx, ny)) continue;
				if (forest[nx][ny] == 'D' || forest[nx][ny] == 'X' || water_vt[nx][ny] != 0) continue;
				water_vt[nx][ny] = water_vt[cur_water.first][cur_water.second] + 1;
				water_q.push(pii(nx, ny));
			}
		}
		// 두더지 이동 : q에서 하나 꺼내고 상 하 좌 우 이동
		int ddg_qsz = ddg_q.size();
		for (int i = 0; i < ddg_qsz; i++) {
			pii cur_ddg = ddg_q.front();
			ddg_q.pop();
			for (int j = 0; j < 4; j++) {
				int nx, ny;
				nx = cur_ddg.first + dx[j];
				ny = cur_ddg.second + dy[j];
				if (!check_rc(nx, ny))continue;
				if (forest[nx][ny] == 'X' || water_vt[nx][ny] != 0 || ddg_vt[nx][ny] != 0) continue;
				if (forest[nx][ny] == 'D') {
					ans = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
					ans--;
					printf("%d", ans);
					return 0;
				}
				else {
					ddg_vt[nx][ny] = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
					ddg_q.push(pii(nx, ny));
				}
			}
		}
	}
	// 답을 출력 
	printf("KAKTUS");
}