/* TEST INPUT 
6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/
#define _CRT_SECURE_NO_WARNINGS

/* TEST INPUT
6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second 

int board[1000][1000];
queue<pair<int, int> > Q;
// up ,right, down, left
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    // n = column , m = row 
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if (tmp == 1) Q.push(make_pair(i, j));
        }
    }

    //bfs 
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != 0) continue;
            
            Q.push(make_pair(nx, ny));
            board[nx][ny] = board[cur.X][cur.Y] + 1;
        }
    }
    //check
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (board[i][j] > result) result = board[i][j];
        }
    }
    cout << result - 1;
    return 0;
}