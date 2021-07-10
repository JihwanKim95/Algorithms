#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int min = 2147000000;
    bool foundOdd = false;

    for(int i = 0; i < 7; i++){
        int tmp;
        cin >> tmp;
        if(tmp % 2 != 0) {
            foundOdd = true;
            sum += tmp;
            if(tmp < min) min = tmp;
        }
    }
    if (foundOdd == false) cout << -1;
    else cout << sum << endl << min;
}