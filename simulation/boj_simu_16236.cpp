
// baby shark 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;


typedef struct shark {
    pair<int, int> position;
    int size = 2;
    int eat = 0;
    int moved = 0;
    void sizeup(){
        if(eat == size){
            size++;
            eat = 0;
        }
    }

    bool operator < (const shark &t) const {

    }
} shark;

int n;
int board[21][21];
int vis[21][21];
queue<pair<int, int> > Q;
//up left right down 
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
shark bs;

int bfs(void);

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            //initial position
            if(board[i][j] == 9) bs.position = make_pair(i,j);
            vis[i][j] = 1;
        }
    }

    while(1){
        //clean Q
        while(!Q.empty()) Q.pop();
        //clean visit 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                vis[i][j] = -1;

        // bfs
        Q.push(bs.position);
        vis[bs.position.X][bs.position.Y] = 0;
        int tmp = bfs();
        if(tmp == -1) break;
    }

    cout << bs.moved;
    return 0;
}

int bfs(void){
    // spread
    auto cur = Q.front(); Q.pop();
    while(!Q.empty()){
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;  // out of boundary 
            if(board[nx][ny] > bs.size || vis[nx][ny] != -1) continue;  // bigger shark or already visited 
            Q.push(make_pair(nx,ny));
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;

            if(board[nx][ny] < bs.size){
                bs.moved += vis[nx][ny];
                bs.position = make_pair(nx, ny);
                board[nx][ny] = 0;
                bs.eat++;
                bs.sizeup();                
                return 0;
            }
        }
    }
    // Q empty, no result 
    return -1;
}

