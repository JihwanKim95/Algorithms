#include <iostream>

/* computing 'n'th fibonacci number */
using namespace std;

int d[100];

int dp(int x){
    cout << x << ' ';

    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x];

    return d[x] = dp(x - 1) + dp(x - 2);
}
 
int main(){
    int n;
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    
    cout << endl << "Fibonacci number of " << n << " is " << dp(n);
}