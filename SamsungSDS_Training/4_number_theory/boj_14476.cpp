#include <iostream>

/* 최대공약수 하나 빼기 */
using namespace std;

int n, answer = -1, sub_num; 
int A[1000001], leftgcd[1000001], rightgcd[1000001];
bool ans_found = false;

// a : next number     b : current number 
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    for(int i = 1; i < n; i++){  // 왼쪽부터 계산한 GCD 
        leftgcd[i] = gcd(leftgcd[i-1], A[i]);  
    }
    for(int i = n; i >= 1; i--){ // 오른쪽부터 계산한 GCD
        rightgcd[i] = gcd(rightgcd[i+1], A[i]);  
    }
    for(int i = 1; i <= n; i++){  
        int curGcd = gcd(leftgcd[i-1], rightgcd[i+1]);  // i 번째 수를 뺀 gcd 연산
        if(A[i] % curGcd == 0) continue; 
        if(answer < curGcd) { 
            answer = curGcd;
            sub_num = A[i];
            ans_found = true;
        }
    }
    cout << answer << ' '; 
    if(ans_found)  cout << sub_num;

} // S