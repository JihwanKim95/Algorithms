#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    
    // string input 
    string str;
    int n;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if (i % 10 == 0 && i != 0) cout << '\n';
        cout << str[i];
    }

}