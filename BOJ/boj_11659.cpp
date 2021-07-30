#include <iostream>

/* 구간 합 구하기 4 */
using namespace std;

int a[100000], d[100000];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen("../../../input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    // 초기값과 전체 값
    cin >> d[1];
    for(int i = 2; i <= n; i++){
        int tmp;
        cin >> tmp;
        d[i] = d[i-1] + tmp;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        cout << d[v] - d[u-1] << '\n';
    }

    
} // S