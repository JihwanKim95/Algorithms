#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

struct Node {
    int a, b, c;  // a 에서 b로 가는데 비용 c가 든다
};

/* 네트워크 연결 */
using namespace std;
vector<pair<int, int> > t[1005];
int v[1005], p[1005];
Node e[100005];

bool operator<(Node a, Node b){
    return a.c < b.c;
}

int find(int n){
    if (p[n] == n) return n;
    return (p[n] = find(p[n]));
}
int uni(int a, int b, int bond){
    int c = find(a), d = find(b);
    if(c == d) return 1;
    if(bond) p[c] = d;
    return 0;
}

int main(){
    int n, m; // n 노드 // n 간선 
    cin >> n >> m;
    for(int i=1; i<n; i++){
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    sort(e, e+m);
    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        if(!uni(e[i].a, e[i].b, 1) == 1){
            ans += e[i].c;
            cnt++;
        }
        if(cnt == n-1) break;
    }

    cout << ans;
} // S

