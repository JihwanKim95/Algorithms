#include <iostream>
#include <algorithm>

/* 게임 */
using namespace std;
typedef long long LL; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long X, Y, Z;
    cin >> X >> Y;

    Z = Y * 100 / X;
    if(Z == 100 || Z == 99){
        cout << -1;
        return 0;
    }
    
    LL bottom = 1, top = 1000000000, mid;
    LL answer = 1000000000;
    while (bottom <= top){   
        // mid represents the chosen value 
        mid = (bottom + top) / 2; 
        long nZ = (Y + mid) * 100 / (X + mid);
        if(Z < nZ) {
            if(mid < answer){
                answer = mid;
            }
            top = mid - 1;
        }
        else {
            bottom = mid + 1;
        }

        //cout << answer << endl;
    }
    cout << answer;
}