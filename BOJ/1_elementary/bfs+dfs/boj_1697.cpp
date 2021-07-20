#include <iostream>
#include <queue>
#include <algorithm>

/* 숨바꼭질 */ 
using namespace std; 

int d[200005];
int n, k;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    fill(d, d + 200005, -1);
    q.push(n);
    d[n] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int na[3] = {cur + 1, cur - 1, cur * 2};
        for(int i = 0; i < 3; i++){
            // cur 값에서 +1 -1 *2 가 되므로 d[na[i]] != -1 에 걸리지 않음 
            if(na[i] < 0 || na[i] >= 200001 || d[na[i]] != -1) continue;
            d[na[i]] = d[cur] + 1;
            q.push(na[i]);
        }
    }
    cout << d[k];
} // S 