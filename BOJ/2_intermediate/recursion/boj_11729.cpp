#include <iostream>

/* 하노이 탑 이동 순서 */ 
using namespace std; 
int cnt = 0; 
// 1 + 2 + 3 = 6 

void move(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    move(a, 6-a-b, n-1);  // n - 1 개의 원판을 기둥 a에서 6-a-b로 옮김 
    cout << a << ' ' << b << '\n';  // n 번 원판을 기둥 a에서 기둥 b로 옮김 
    move(6-a-b, b, n-1);  // n - 1 개의 원판을 기둥 2에서 기둥 3으로 옮김 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    cout << (1 << N) - 1 << '\n';  // 일반항은 2^k - 1
    move(1, 3, N);

    return 0;
}