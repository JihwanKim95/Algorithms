#include <iostream>
#include <queue>
#include <algorithm>

/* 주사위 게임 */ 
using namespace std;
int board[1000]; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);

    int N, M; 
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> board[i];
    }
    int pos = 1;
    int cnt = 0;
    for(int i = 1; i <= M; i++){
        int tmp;
        cin >> tmp;  // throw dice 
        cnt++;
        pos = pos + tmp;
        int dx = board[pos];
        pos = pos + dx;
        
        if(pos >= N) break;
    }

    cout << cnt;
}