/*
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1

Output 
4
9
*/
#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int paint[501][501];
int vis[501][501];

queue<pair<int, int> > Q; 

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    // up, right, down, left 
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m, max = 0, area = 0, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> paint[i][j];
        }
    }

    // find painted and not visited 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(paint[i][j] == 1 && vis[i][j] == 0){
                //bfs 
                Q.push({i, j});
                vis[i][j] = 1; 
                cnt++; area++;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(ny < 1 || ny > 500 || nx < 1 || nx > 500) continue;
                        if(paint[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        Q.push(make_pair(nx, ny));
                        vis[nx][ny] = 1;
                        area++;
                    }
                }
                if(area > max) max = area; 
                area = 0;
            }
        }
    }

    cout << cnt << endl << max;

    return 0;
}