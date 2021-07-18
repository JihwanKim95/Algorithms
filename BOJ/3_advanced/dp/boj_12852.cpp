#include <iostream>
#include <stack>

/*1로 만들기 2*/
using namespace std;

int n;
int d[1000005], pre[1000005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    int cnt = 1;
    // d[i] = 숫자 i를 1로 만들기 위한 연산 활용 횟수의 최솟값
    d[1] = 0;  // 1은 목표값이므로 연산이 필요없다
    for(int i = 2; i <= n; i++){
        d[i] = d[i - 1] + 1;
        pre[i] = i-1;
        if(i % 2 == 0 && d[i] > d[i/2] + 1){  // d[i/2] + 1 의 연산횟수가 더 작을 때만
            d[i] = min(d[i], d[i/2] + 1);
            pre[i] = i/2;
        }
        if(i % 3 == 0 && d[i] > d[i/3] + 1){  // d[i/3] + 1 의 연산횟수가 더 작을 때만
            d[i] = min(d[i], d[i/3] + 1);
            pre[i] = i/3;
        }
    }

    cout << d[n] << '\n';
    // path finding 
    int cur = n;
    while(1){
        if(cur == 0) break;
        cout << cur << ' ';
        cur = pre[cur];
    }

    return 0;
} // S 