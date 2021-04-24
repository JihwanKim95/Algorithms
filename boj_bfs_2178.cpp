#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second

//up right down left
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
string board[101];
int dis[101][101];
queue<pair<int, int> > Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    // fill distance with -1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = -1;
        }
    }

    Q.push(make_pair(0,0));
    dis[0][0] = 1;
    while(!Q.empty()){
        auto cur = Q.front();  Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' || dis[nx][ny] != -1) continue;
            Q.push(make_pair(nx,ny));
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }

    cout << dis[n-1][m-1];
}