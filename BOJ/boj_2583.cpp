#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/* 영역 구하기 */  
using namespace std;
#define Y first 
#define X second 
#define pii pair<int, int>

int board[105][105];
int vis[105][105];
queue<pii> q;
vector<int> ans; 

// n e s w 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool compare(int a, int b){
    return a < b;
}

void draw(pii down, pii up) {
    for(int i = down.Y; i <= up.Y - 1; i++){
        for(int j = down.X; j <= up.X - 1; j++){
            board[i][j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../../input.txt", "r", stdin);

    int M, N, K; 
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++){
        int x_down, y_down, x_up, y_up;
        cin >> x_down >> y_down; 
        cin >> x_up >> y_up;
        draw({y_down, x_down}, {y_up, x_up});
    }

    // bfs 
    int area = 0, cnt = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            area = 0;
            if(board[i][j] == 0) {  // i = y   j = x 
                q.push({i,j});             
                board[i][j] = 1;
                area++;
                cnt++;
            }
            while(!q.empty()){
                pii cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(board[ny][nx] == 1) continue;
                    q.push({ny, nx}); 
                    board[ny][nx] = 1; area++;
                }
            }
            if(area != 0) ans.push_back(area);
        }
    }

    // sort 
    sort(ans.begin(), ans.end(), compare);
    cout << cnt << '\n';
    for(int i : ans) cout << i << ' ';
    
    return 0;
}