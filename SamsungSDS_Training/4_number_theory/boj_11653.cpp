#include <iostream>
#include <vector>

/* 소인수분해 */
/* 
에라토스테네스의 체 활용 
sqrt(10,000,000) == 3162.27

*/
using namespace std;

bool che[3200];
vector <int> prime;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    // filtering prime numbers
    for(int i = 2; i < 3200; i++){
        if(che[i]) continue;
        for(int j = i + i; j < 3200; j += i){
            che[j] = true;
        }
    }
    // pushing prime numbers back into a list 
    for (int i = 2; i < 3200; i++){
        if(!che[i]){
            prime.push_back(i);
        }
    }

    if(n == 1){
        return 0;
    }
    for(int i = 0; i < prime.size(); i++){
        while(n % prime[i] == 0) {
            cout << prime[i] << '\n';
            n /= prime[i];
        }
    }
    // prime numbers that are out of [0, 3200] range 
    if(n > 1){
        cout << n << '\n';
    }
        
} // S