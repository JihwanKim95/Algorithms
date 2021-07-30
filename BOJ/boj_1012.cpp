#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 55
#define X first
#define Y second

/* 유기농 배추 */
using namespace std;
typedef pair<int, int> pii;
int T, m, n, k;
int board[MAX][MAX];
int vis[MAX][MAX];
queue<pii> q;

// n e s w 
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 

void solve(){
    int cnt = 0;
    // m : hor length, n : ver length 
    cin >> m >> n >> k;
    // input 
    for(int b = 0; b < k; b++){
        int x, y;
        cin >> y >> x;
        board[x][y] = 1;
    }
    // bfs in loop 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                q.push({i, j});
                vis[i][j] = 1;
                cnt++;
            }
            while(!q.empty()){
                pii cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);

    cin >> T;
    for(int i = 0; i < T; i++){
        fill(&board[0][0], &board[MAX-1][MAX], 0);
        fill(&vis[0][0], &vis[MAX-1][MAX], 0);
        solve();
    }
} // S