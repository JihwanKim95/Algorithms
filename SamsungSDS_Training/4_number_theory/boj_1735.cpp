#include <iostream>
#include <vector>

// 귀류법 증명 필요, 암기
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

/* 분수의 합 */
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d, p, q;

    cin >> a >> b >> c >> d; 

    p = a * d + b * c;
    q = b * d;

    int g = gcd(p, q);
    cout <<  p/g << ' ' << q/g;

    return 0;
} // S
