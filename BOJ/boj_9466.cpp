#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/* 텀 프로젝트 */ 
using namespace std;
int a[100005], state[100005];
int T, n;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3; 

void run(int x){
    int cur = x;
    while(true){
        state[cur] = VISITED; 
        cur = a[cur];
        // 방문한곳이 이미 사이클이거나, 사이클이 아니라는 것이 확인됨  
        if(state[cur] == NOT_CYCLE_IN || state[cur] == CYCLE_IN){
            cur = x;  // 다시 시작점으로 되돌려놓고
            while(state[cur] == VISITED){
                state[cur] = NOT_CYCLE_IN;
                cur = a[cur];
            }
            return;
        }
        // 방문했던 적 있는 노드이며, 시작점이 아님
        if(state[cur] == VISITED && cur != x){
            while(state[cur] != CYCLE_IN){  // 사이클 안쪽 모두 CYCLE_IN 표시 
                state[cur] = CYCLE_IN;
                cur = a[cur];
            }
            cur = x;
            while(state[cur] != CYCLE_IN){  // 시작점부터 사이클까지 NOT_CYCLE_IN
                state[cur] = NOT_CYCLE_IN;
                cur = a[cur];
            }
            return;
        } 
        // 방문했던 노드이며, 시작점이기 때문에 사이클 형성 
        if(state[cur] == VISITED && cur == x){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = a[cur];
            }
            return;
        }
    }
}

void solve(){
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; 
        cin >> tmp;
        a[i] = tmp;
    }
    for(int i = 0; i < n; i++){
        run(a[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);
    cin >> T;
    while(T--){
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] == NOT_CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
} // S 