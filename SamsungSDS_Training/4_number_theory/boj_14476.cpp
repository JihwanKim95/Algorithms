#include <iostream>

/* 최대공약수 빼기 하나 */
using namespace std;

int n, a[10000], leftgcd[10000], rightgcd[10000];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        leftgcd[i] = gcd(leftgcd[i-1], a[i]);
    }
    for(int i = n; i >= 1; i--){
        rightgcd[i] = gcd(leftgcd[i+1], a[i]);
    }
    for(int i = 1; i <= n; i++){
        int curGcd = gcd(leftgcd[i-1], rightgcd[i+1]);
        if(a[i] % curGcd == 0)
    }

}