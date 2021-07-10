#include <iostream>

/* 이항 계수 2 */
using namespace std;

int cache[1001][1001]; 

int nCr(int n, int r){
    // final
    if(r==0) return 1;
    if(n < r) return 0;
    if(n < 0 || 1000 < n || r < 0 || 1000 < r) return 0;
    
    if(cache[n][r] != -1){
        return cache[n][r];
    }

    return cache[n][r] = (nCr(n-1, r-1) + nCr(n-1, r)) % 10007;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            cache[i][j] = -1;
        }
    }

    int n, k;
    cin >> n >> k;

    cout << nCr(n, k);
} // S
