#include <iostream>

/* Z */ 
using namespace std;


/* 
N, r, c 가 주어진다. 

1. 함수 정의 
divide()

2. Base Condition 

3. 재귀 식 
(r,c) 가 어느 사각형에 있는지에 따라 식이 달라진다. 

*/

int func(int n, int r, int c){
    if(n == 0) return 0;
    int half = 1<<(n-1); // 2^(n-1)

    if(r < half && c < half) return func(n-1, r, c);  // 1번 사각형 
    if(r < half && c >= half) return half*half + func(n-1, r, c-half);  // 2번 사각형 
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);  // 3번 사각형 
    return 3*half*half + func(n-1, r-half, c-half);  // 4번 사각형
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}

