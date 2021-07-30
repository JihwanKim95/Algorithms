#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define X first
#define Y second

/* 단지번호붙이기 */ 
using namespace std;

int N; 
string board[30];
int danji = 0;
queue<pii> q;
vector<int> v_house;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool compare(int a, int b){
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);
    cin >> N;
    //input 
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int house_count = 0;
            if(board[i][j] == '1') {
                q.push({i, j});
                board[i][j] = '-';
                danji++;
                house_count++;
            }
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(board[nx][ny] != '1') continue;
                    q.push({nx, ny});
                    board[nx][ny] = '-';
                    house_count++; 
                }
            }
            if(house_count > 0) v_house.push_back(house_count);
        }
    }

    // sort 
    sort(v_house.begin(), v_house.end(), compare); 

    cout << danji << '\n';
    for(int element : v_house) cout << element << '\n'; 
}