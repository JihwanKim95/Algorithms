#include <iostream>

/* X보다 작은 수 */
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        int tmp; 
        cin >> tmp;
        if(tmp < x) cout << tmp << ' ';
    }

    return 0;
}