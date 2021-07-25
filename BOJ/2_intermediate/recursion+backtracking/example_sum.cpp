#include <iostream>

using namespace std;

int recur(int n){
    if(n == 1) return 1;
    return n + recur(n - 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    cout << recur(N);
}