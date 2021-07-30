#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1005
#define X first 
#define Y second

struct loc {
    int x, y, w;
};

/* 벽 부수고 이동하기 */
using namespace std;
char board[MAX][MAX];
int vis[MAX][MAX][2]; 

int N, M;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int bfs(){
    queue<loc> q;
    q.push({0,0,0}); 
    vis[0][0][0] = 1;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, w = q.Bfront().w; q.pop();
        if(x == N-1 && y == M-1) return vis[x][y][w];
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny][w]) continue;
            // 갈 수 있는 길이라면 경로에 추가
            if(board[nx][ny] == '0'){
                vis[nx][ny][w] = vis[x][y][w] + 1;
                q.push({nx,ny,w});
            }
            // 벽이 있다면 벽을 부수고 flag 1로 세팅
            if(board[nx][ny] == '1' && w == 0){
                vis[nx][ny][1] = vis[x][y][w] + 1;
                q.push({nx,ny,1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../../input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];
    cout << bfs();
    return 0; 
}