#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define MAX 105
#define X first 
#define Y second

/* 안전구역 */ 
using namespace std;
int board[MAX][MAX];
int vis[MAX][MAX];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

queue<pii> q;
int N;

int bfs(int h){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] > h && !vis[i][j]){
                q.push({i,j}); 
                vis[i][j] = 1;
                cnt++;
            }
            while(!q.empty()){
                int x = q.front().X, y = q.front().Y; q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
                    if(vis[nx][ny] || board[nx][ny] <= h) continue;
                    q.push({nx,ny});  /* 실수 잦은 부분 :: 변수 i, j 가 아닌 nx ny 를 사용해야 한다 */ 
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);
    int mini = 2147000000, maxi = -1;
    int maximum_area = 0;
    cin >> N; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] < mini) mini = board[i][j];
            if(board[i][j] > maxi) maxi = board[i][j];
        }
    }

    int prev = -1;
    for(int h = mini; h < maxi; h++){
        fill(&vis[0][0], &vis[MAX-1][MAX], 0); 
        int res = bfs(h);
        if(res > maximum_area) maximum_area = res;
    }
    if (maximum_area == 0){
        cout << 1;
        return 0;
    }
    cout << maximum_area;
}