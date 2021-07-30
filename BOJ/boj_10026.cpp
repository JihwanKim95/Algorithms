#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first 
#define Y second 
#define pii pair<int, int>

/* 적록색약 */ 
using namespace std; 
char board1[105][105];
char board2[105][105];
int N;
queue<pii> q;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NORMAL = 1;
const int COLOR_BLIND = 2;

// use board 1
void bfs(char board[105][105], int status){

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char current_char;
            if(board[i][j] != '1'){
                q.push({i,j});
                current_char = board[i][j];
                board[i][j] = '1';
                cnt++;
            }
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(board[nx][ny] == '1') continue;

                    if(status == COLOR_BLIND){
                        if(current_char == 'R' || current_char == 'G'){
                            if(board[nx][ny] == 'G' || board[nx][ny] == 'R') {
                                q.push({nx, ny});   
                                board[nx][ny] = '1';
                            }
                        }
                    }
                    else if(status == NORMAL){
                        if(current_char == 'R'){
                            if(board[nx][ny] == 'R'){
                                q.push({nx,ny});
                                board[nx][ny] = '1';
                            }
                        }
                        if(current_char == 'G'){
                            if(board[nx][ny] == 'G'){
                                q.push({nx,ny});
                                board[nx][ny] = '1';
                            }
                        }
                    }
                    if(current_char == 'B'){
                        if(board[nx][ny] == 'B'){
                            q.push({nx,ny});
                            board[nx][ny] = '1';
                        }
                    }
                }
            }
        }
    }

    cout << cnt << ' ';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board1[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board2[i][j] = board1[i][j];
        }
    }
    bfs(board1, NORMAL);
    while(!q.empty()) q.pop();
    bfs(board2, COLOR_BLIND);
}