#include<iostream>

/* 1, 2, 3 더하기 */ 
using namespace std;

int go(int sum, int goal){
    if(sum > goal){
        return 0;
    }
    if(sum == goal) {
        return 1;
    }
    
    int now = 0;
    for(int i = 1; i <= 3; i++){
        now += go(sum + i, goal);
    }
    return now;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../../input.txt", "r", stdin);
    int T; 
    int n;
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n;
        cout << go(0, n) << '\n';
    }

    return 0;
}