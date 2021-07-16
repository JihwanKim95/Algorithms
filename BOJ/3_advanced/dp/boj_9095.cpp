#include <iostream>

/* 1, 2, 3 더하기 */ 
using namespace std;

int d[13] = { 0, 1, 2, 4 , };
int n[13] = {0 , };

int main(){
    
    for(int i = 4; i < 12; i++){
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];        
    }

    int T; 
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> n[t];
    }

    for(int t = 0; t < T; t++){
        cout << d[n[t]] << '\n';
    }

    return 0;
}  // S