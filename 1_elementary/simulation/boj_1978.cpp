#include <iostream>

/* 소수 찾기 */
using namespace std;

int cnt = 0;

void check(int num){
    bool isPrime = true;
    if(num == 1) return; 
    if(num == 2) {
        cnt++;
        return;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0) {  // not prime
            isPrime = false;
            break;
        }
    }

    if(isPrime == true) cnt++;
}



int main(){
    int n = 0;
    cin >> n;

    for(int i = 1; i <= n; i++){
        bool isPrime = true;
        int tmp;
        cin >> tmp;
        check(tmp);        
    }
    cout << cnt;
} // S