#include <iostream>

/* 30 */
using namespace std;

char input[100001];
int sum = 0, cnt[128];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> input;
    // 자리수 카운트 & 자리수의 합 
    for(int i = 0; input[i]; i++){
        sum += input[i] - '0'; 
        cnt[input[i]]++;
    }
    // 자리수의 합 -> 3의 배수 되기위한 조건
    if(sum % 3 != 0 || cnt['0'] == 0){
        cout << "-1";
        return 0; 
    }
    // 
    for(int i = '9'; i >= '0'; i--){
        for (int j = 0; j < cnt[i]; j++){
            cout << (char) i;
        }
    }



} 