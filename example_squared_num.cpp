#include <iostream>

using namespace std;

int main(){
    int n;
    int result = 0;
    cin >> n;

    for(int i=0; i*i<n; i++){
        if(i*i==n) {
            result=1;
            break;
        }
    }

    cout << (result);
}