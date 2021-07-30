#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 305
#define X first
#define Y second
#define pii pair<int, int>

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2 ,-2, -1};

/* 나이트의 이동 */ 
using namespace std;
int board[MAX][MAX];
queue<pii> q;

void solve(){
	int L, x_start, y_start, x_end, y_end;
	cin >> L;
	cin >> x_start >> y_start;
	cin >> x_end >> y_end;
	if(x_start == x_end && y_start == y_end) {
		cout << 0 << '\n';
		return;
	}
	board[x_start][y_start] = 1;
	q.push({x_start,y_start});
	//bfs 
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int dir = 0; dir < 8; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
			if(board[nx][ny] != 0) continue;
			q.push({nx,ny});
			board[nx][ny] = board[cur.X][cur.Y] + 1;
			if(nx == x_end && ny == y_end) {
				cout << board[nx][ny] - 1 << '\n';
				return;	
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int T, length;
	//freopen("../../../input.txt", "r", stdin);
	cin >> T;
	while(T--){
		// initialize 
		fill(&board[0][0], &board[MAX-1][MAX], 0);
		while(!q.empty()) q.pop();
		solve();
	}

}