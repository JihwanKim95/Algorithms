#include <iostream>
#include <algorithm>

/* 일곱난쟁이 */
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a[9];
    int sum = 0;
    const int n = 9;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+9);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(sum - a[i] - a[j] == 100){
                for(int k = 0; k < n; k++){
                    if(i == k || j == k) continue;
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }

    
}