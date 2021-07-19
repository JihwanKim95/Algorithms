#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/* 불! */ 
using namespace std;
#define X first
#define Y second

string map[1005];
int dist_j[1005][1005], dist_f[1005][1005];
int r, c;
// n e s w
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("../../../input.txt", "r", stdin);
    queue<pair<int, int> > fireQ;
    queue<pair<int, int> > jQ; 

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> map[i];
    }
    for(int i = 0; i < r; i++){  //*** setting -1 to cover larger area 
        for(int j = 0; j < c; j++){
            dist_f[i][j] = -1;
            dist_j[i][j] = -1;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == 'F') {
                dist_f[i][j] = 0;
                fireQ.push({i,j});
            }
            if(map[i][j] == 'J') {
                dist_j[i][j] = 0;
                jQ.push({i,j});
            }
        }
    } // input 확인

    // fire bfs 
    while(!fireQ.empty()){
        auto cur = fireQ.front(); fireQ.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 불의 과거 이동과 겹치지 않고 벽을 피함 
            if(dist_f[nx][ny] != -1 || map[nx][ny] == '#') continue;
            dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1; // visit 
            fireQ.push({nx, ny}); 
        }
    }

    // jihoon bfs 
    while(!jQ.empty()){
        auto cur = jQ.front(); jQ.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // esc
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << dist_j[cur.X][cur.Y] + 1;
                return 0;
            }
            // 지훈의 과거 이동과 겹치지 않고 벽을 피함 
            if(dist_j[nx][ny] >= 0 || map[nx][ny] == '#') continue;
            // 칸에 불이 퍼진 것이 사람이 방문하기 이전이었다면
            if(dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_j[cur.X][cur.Y]+1) continue;
            dist_j[nx][ny] = dist_j[cur.X][cur.Y] + 1; // visit 
            jQ.push({nx, ny});
 
        }
    }
    cout << "IMPOSSIBLE";
} // S