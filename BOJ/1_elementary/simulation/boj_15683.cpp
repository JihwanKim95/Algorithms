#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
#define X first
#define Y second

/* 감시 */ 
using namespace std;

int N, M;
int board[10][10];
queue<pii> q;

// n e s w 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int count_blind_spot(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int count_available(int x, int y, int dir, int cnt){
    if(x < 0 || x >= N || y < 0 || y >= M) return cnt - 1;
    if(board[x][y] == 6) return cnt;

    if(board[x][y]) count_available(x + dx[dir], y + dy[dir], dir, cnt);
    else count_available(x + dx[dir], y + dy[dir], dir, cnt + 1);
}

void cover(int x, int y, int dir){
    if(x < 0 || x >= N || y < 0 || y >= M) return;
    if(board[x][y] == 6) return;

    board[x][y] = 9;
    cover(x + dx[dir], y + dy[dir], dir);
}

void solve(pii coord, int type){
    int x = coord.X, y = coord.Y; 
    // check possible spots 
    int maxi = 0, mini = 2147000000, max_dir, min_dir;
    int avail_count[4] = {0,};
    for(int dir = 0; dir < 4; dir++){
        avail_count[dir] = count_available(x + dx[dir], y + dy[dir], dir, 0);
        if(avail_count[dir] > maxi){
            maxi = avail_count[dir];
            max_dir = dir;
        }
        if(avail_count[dir] < mini){
            mini = avail_count[dir];
            min_dir = dir;
        }
    }

    // choose max from option  
    if(type == 1){
        cover(x, y, max_dir);
    }
    else if(type == 2){
        if(avail_count[UP] + avail_count[DOWN] > avail_count[LEFT] + avail_count[RIGHT]){
            cover(x, y, UP);
            cover(x, y, DOWN);    
        }
        else {
            cover(x, y, LEFT);
            cover(x, y, RIGHT);
        }
    }
    else if(type == 3){
        int option1 = avail_count[UP] + avail_count[RIGHT];
        int option2 = avail_count[RIGHT] + avail_count[DOWN];
        int option3 = avail_count[DOWN] + avail_count[LEFT];
        int option4 = avail_count[LEFT] + avail_count[UP];
    }
    else if(type == 4){
        // exclude 
        for(int dir = 0; dir < 4; dir++){
            if(dir == min_dir) continue;
            cover(x, y, dir);
        }
    }
    else if(type == 5){
        cover(x, y, UP);
        cover(x, y, DOWN);
        cover(x, y, LEFT);
        cover(x, y, RIGHT);
    }

}


int main(){
    cin >> N >> M;  // N : vertical length    M : horizontal length 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] <= 1 && board[i][j] <= 5) q.push({i,j});
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        switch(board[cur.X][cur.Y]){
            case 1:
                solve(cur, 1);
                break;
            case 2:
                solve(cur, 2);
                break;
            case 3: 
                solve(cur, 3);
                break;
            case 4: 
                solve(cur, 4);
                break;
            case 5:
                solve(cur, 5);
                break;
            default:
                break;
        }
    }
    cout << count_blind_spot();
    return 0;
}