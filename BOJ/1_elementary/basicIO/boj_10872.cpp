#include <iostream>

/* 팩토리얼 */
using namespace std;

int main(){
    int n;
    cin >> n;

    int fac = 1;
    for(int i = 1; i <= n; i++){
        fac *= i;
    }

    cout << fac;

    return 0;
}