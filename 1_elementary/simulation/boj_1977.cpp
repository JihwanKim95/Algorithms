#include <iostream>

/* 완전제곱수 */
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int min = 2147000000;
    int sum = 0;
    bool found = false;

    for(int i = m; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            if(j*j == i) {
                found = true;
                if (i < min) min = i;
                sum += i;
            }
        }
    }

    if(found == false) cout << -1;
    else cout << sum << endl << min;
}