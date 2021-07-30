#include <iostream>
#include <queue>
#include <algorithm>

/* 토마토 */
using namespace std;

// donw, up, left, right, front, back 
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};
// m: 가로 칸, n: 세로 칸, h: 상자의 수  
int m, n, h;
int board[101][101][101];

struct Coord {
    int x, y, z;
};
queue<Coord> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);
    cin >> m >> n >> h;
    // input 
    bool found = false;
    int res = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int tmp;
                cin >> tmp;
                board[i][j][k] = tmp;     
                if(tmp == 1) {
                    q.push({j, k, i});
                    res = 1;
                }
                if(board[i][j][k] == 0) found = true;            
            }
        }
    }
    if(found == false) {
        cout << 0;
        return 0;
    }
    // bfs 
    while(!q.empty()){
        Coord cur = q.front(); q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];
            // check boundary and condition
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(board[nz][nx][ny] == -1 || board[nz][nx][ny] >= 1) continue;
            q.push({nx, ny, nz});
            board[nz][nx][ny] = board[cur.z][cur.x][cur.y] + 1;
            if(board[nz][nx][ny] > res) res = board[nz][nx][ny];
        }
    }

    for(int i = 0; i < h; i++){  // h : stacked boxes  -> z
        for(int j = 0; j < n; j++){  // n : row  -> x
            for(int k = 0; k < m; k++){  // m : column -> y 
                if(board[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << res - 1;
    return 0;
} //S
