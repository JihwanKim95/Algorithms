#include <iostream>
#include <queue>
#include <algorithm>

/* 암호만들기 */
using namespace std;

int L, C;
char arr[100], ans[4];

bool check(){
    int countMoeum = 0, countJaeum = 0; 
    bool isMoeum[128] = {0, };
    isMoeum['a'] = true;
    isMoeum['e'] = true;
    isMoeum['i'] = true;
    isMoeum['o'] = true;
    isMoeum['u'] = true;
    for(int i = 0; i < L; i++){
        if(isMoeum[ans[i]]) countMoeum++;
        else countJaeum++;
    }
    return (countMoeum >= 1 && countJaeum >= 2);
}

// from 은 어디서부터 볼 건지
void recur (int where, int from){
    // final 
    if(where == L){  // 원하는 깊이(L)만큼 들어갔다면 
        if(check()){   // check and print answer :: string conversion used 
            cout << (string) ans << '\n'; 
        }
        return;
    }
    // looped recursion : C개의 수 안에서 모두 시도
    for(int i = from; i < C ; i++){
        ans[where] = arr[i];
        recur(where + 1, i + 1);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // 입력과 정렬
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr, arr+C); 

    recur(0,0);
    
    return 0;
} // S
