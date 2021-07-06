
#include <iostream>
#include <queue>    
#include <vector>

using namespace std;
#define X first
#define Y second

// up right down left
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;
int a[100][100];
int b[100][100];
int vis[100][100];

int n, m;

int bfs(void){
    // initial push to Q     
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = a[i][j];
            int tmp = b[i][j];
            if(tmp == 2) {
                Q.push(make_pair(i,j));
            }
        }
    }
    // spread
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(b[nx][ny] != 0) continue;
            Q.push(make_pair(nx, ny));
            b[nx][ny] = 2;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = 0;
            if(b[i][j] == 0) cnt++;
        }
    }

    return cnt;
}



int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int result = 0;
    for(int x1 = 0; x1 < n; x1++){  // wall 1
        for(int x2 = 0; x2 < m; x2++){
            if(a[x1][x2] != 0) continue;
            for(int y1 = 0; y1 < n; y1++){  // wall 2
                for(int y2 = 0; y2 < m; y2++){
                    if(a[y1][y2] != 0) continue;
                    for(int z1 = 0; z1 < n; z1++){  // wall 3
                        for(int z2 = 0; z2 < m; z2++){  
                            if(a[z1][z2] != 0) continue;
                            if(x1 == y1 && x2 == y2) continue;
                            if(x1 == z1 && x2 == z2) continue;
                            if(y1 == z1 && y2 == z2) continue;
                            a[x1][x2] = 1;
                            a[y1][y2] = 1;
                            a[z1][z2] = 1; 
                            int tmp = bfs();
                            if(tmp > result) result = tmp;
                            a[x1][x2] = 0;
                            a[y1][y2] = 0;
                            a[z1][z2] = 0;    
                        }
                    }
                }
            }
        }
    }

    cout << result;

    return 0;
}