#include <iostream>

/* 2 X n 타일링 */ 
using namespace std;

int n;
int d[1005]; 
// table def : d[i] = 2 * i 개의 블록이 있을 때 채우는 방법의 수

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../../input.txt", "r", stdin);

    cin >> n;
    d[1] = 1, d[2] = 2;

    for(int i = 3; i <= n; i++){
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }

    cout << d[n];
} // S