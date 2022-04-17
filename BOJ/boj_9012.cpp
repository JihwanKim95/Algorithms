#include <iostream>
#include <stack>
#include <string>

using namespace std; 

void solve(){
    stack<char> s;
    string str; 
    getline(cin, str);
    for(char c : str){
        if(c == '(')
            s.push('(');
        else if (c == ')'){
            if(s.empty()) {
                cout << "NO" << "\n"; 
                return;
            }
            s.pop();
        }
    }

    if(s.empty()) cout << "YES" << "\n";  
    else {
        cout << "NO" << "\n";
    }
    return; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("../input.txt", "r", stdin);

    int T; 
    cin >> T; 
    cin.ignore();
    for(int i = 0; i < T; i++){
        solve();
    } 

    return 0;
}