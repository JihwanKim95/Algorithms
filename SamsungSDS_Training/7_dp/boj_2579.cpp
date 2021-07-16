#include <iostream>
#include <memory.h>

/* 계단오르기 */ 
using namespace std;

// d[i] = i 번째 계단에 올라섰을 때 점수의 최대 
// i 계단 번째 수 
int s[305], d[305][3];
int score;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> s[i]; 
    }

    if (n == 1) {
        cout << s[1];   
        return 0; 
    } 

    // d[k][1] : k번째 계단을 가기 위해 한 칸을 연속해 밟은 경우 점수합의 최대값 
    // d[k][2] : 두 칸 연속해 밟은 경우 점수합의 최대값 
    // 초기값 선정 
    d[1][1] = s[1], d[1][2] = 0;
    d[2][1] = s[2], d[2][2] = s[1] + s[2];
    for(int k = 3; k <= n; k++){
        // 누적 한 칸을 연속해 밟았으면 이전 칸은 밟지 않은 것  
        d[k][1] = max(d[k-2][1], d[k-2][2]) + s[k];  
        // 누적 두 칸을 밟았으면 이전 계단을 밟았으며, 이전에 누적 한 계단을 밟은 이력만 존재  
        d[k][2] = d[k-1][1] + s[k];  
    }

    cout << max(d[n][1], d[n][2]); 
    return 0;
}