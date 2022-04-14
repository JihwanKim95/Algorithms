#include <iostream>
#include <stack>
#include <string>

using namespace std; 



void solve(){
    // put each letter in word into a stack before space
    // until the end of sentence 
    stack<char> s;
    string str;
    getline(cin, str);
    str += '\n'; 
    for(char ch : str){
        if(ch == ' ' || ch == '\n'){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << ch;
        } else {
            s.push(ch);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    freopen("../input.txt", "r", stdin);

    int T; 
    cin >> T; 
    cin.ignore();
    while(T--) solve();

    return 0; 
}