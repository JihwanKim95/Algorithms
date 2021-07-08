#include <iostream>
#include <queue>
#include <algorithm>

/* 암호만들기 */
using namespace std;

int L, C;
char arr[100], ans[100];

bool check(){
    int countMoeum = 0, countJaeum = 0; 
    bool isMoeum[128] = {0, };
    isMoeum['a'] = true;
    isMoeum['e'] = true;
    isMoeum['i'] = true;
    isMoeum['o'] = true;
    isMoeum['u'] = true;
    for(int i = 0; i < C; i++){
        if(isMoeum[ans[i]]) countMoeum++;
        else countJaeum++;
    }
    if(countMoeum >= 1 && countJaeum >= 2) return true;
}

void recur (int where, int from){
    if(where == L){
        if(check()){
            cout << ans;    
        }
    }
}

int main(){
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr, arr+C);

    for(int i = 0; i < C; i++){
        cout << arr[i];
    }
    


}