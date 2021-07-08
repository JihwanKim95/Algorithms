#include <iostream>
#include <vector>

/* 수들의 합 2 */ 
using namespace std;

int n, m, arr[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../input.txt", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int front = 0;
    int sum = arr[front];
    for(int back = 1; back < n; back++){
        sum += arr[back];
        if(sum > m) {
            sum = sum - arr[front];
            front++;
        }
        else if(sum == m){
            cout << "found\n";
            ans++;
            sum = sum - arr[front];
            front++;
        }
    }

    cout << ans;
}