#include <iostream>
#include <algorithm>

/* RGB 거리 */ 
using namespace std; 

int n, s[1005][4], d[1005][4];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> s[i][j];
        }
    }

    // initial value 
    d[1][0] = s[1][0];  // r
    d[1][1] = s[1][1];  // g
    d[1][2] = s[1][2];  // b

    // dp
    // d[i][0] : i 번째 집까지 칠할 때의 최소값, 단 i번째는 빨간색
    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + s[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + s[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + s[i][2];
    }

    cout << min({d[n][0], d[n][1], d[n][2]});
} // S