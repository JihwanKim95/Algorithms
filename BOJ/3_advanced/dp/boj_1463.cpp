#include <iostream>

/* 1로 만들기 */ 
using namespace std;
int d[1000000];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    d[1] = 0;
    for(int i = 2; i <= n; i++){
        d[i] = d[i - 1] + 1;
        if(i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if(i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1); 
    }

    cout << d[n];
}
