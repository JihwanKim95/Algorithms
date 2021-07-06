#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    // top
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n-i; j++)
            cout << ' ';
        for(int k = 1; k <= i; k++)
            cout << '*';
        cout << '\n';
    }
    //middle
    for(int i = 1; i <= n; i++)
        cout << '*';
    cout << '\n';
    //bottom 
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++)
            cout << ' ';
        for(int k = n-i; k >= 1; k--)
            cout << '*';
        cout << '\n';
    }
}