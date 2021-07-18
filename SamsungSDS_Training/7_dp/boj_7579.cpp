#include <iostream>

/* 앱 */ 
using namespace std;

// a[i][0] : i 번째 앱을 지웠을 때 얻을 수 있는 메모리의 총 합 <- 최대화 필요 
// a[i][1] : i 번째 앱을 다시 실행해야 할 때 비용의 총 합 <- 최소화 필요 
int a[105][2]; 
                
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, m, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> a[i][0];
    }

    

}
