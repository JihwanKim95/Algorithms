#include <iostream>

int n, k;

/* 이항 계수 1 */
using namespace std;
 
int fact(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    int p = 1;
    for(int i = n; i > n - k; i--){
        p *= i;
    }
    cout << (p / fact(k));
} // S

