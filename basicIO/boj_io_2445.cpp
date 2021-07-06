#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        for (int j = 1; j <= i; j++)
            cout << "*";
        for (int k = (n*2)-(i*2); k >= 1; k--)
            cout << " ";
        for (int m = 1; m <= i; m++)
            cout << "*";            
        cout << '\n';
    }
    // middle 
    for (int i = 1; i <= n * 2; i++)
        cout << "*";
    cout << '\n';
    // down
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++)
            cout << "*";
        for(int k = 1; k <= 2*i; k++)
            cout << " ";
        for(int m = i; m < n; m++)
            cout << "*";
        cout << '\n';
    }
}