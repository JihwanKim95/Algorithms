#include <iostream>
#include <vector>

/* 집합의 표현 */
using namespace std;

int p[1000001];

int find(int n){
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

int uni(int a, int b, int bond){
    int c = find(a);
    int d = find(b);
    if(c == d) return 1;
    if(bond) p[c] = d;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 기본적으로 자기 자신에게 연결
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            uni(u, v, 1);
        }
        else{
            cout << ( uni(u, v, 0) ? "YES" : "NO") << '\n'; 
        }
    }
    
}