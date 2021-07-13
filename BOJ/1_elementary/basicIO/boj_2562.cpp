#include <iostream>

using namespace std;

int main(){
    int arr[9];
    int max = -2147000000;
    int max_idx = -1;
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 9; i++){
        if(arr[i] > max) {
            max = arr[i];
            max_idx = i + 1;
        }
    }

    cout << max << endl << max_idx;

}