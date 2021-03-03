#include <iostream>

using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, tmp, max = -2147000000, min = 2147000000;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp > max) max = tmp;
        if(tmp < min) min = tmp;
    }
    cout << min << " " << max;
}