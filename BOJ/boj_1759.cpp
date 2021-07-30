#include <iostream>
#include <vector>
#include <algorithm>

/* 암호 만들기 */ 
using namespace std; 


bool check(string &password){
    int ja = 0, mo = 0;
    for(char x : password){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') mo++;
        else ja++;
    }

    return mo >= 1 && ja >= 2;
}

void go(int n, vector<char> &alpha, string password, int i){
    // answer case
    if(password.length() == n){
        if(check(password) == true) {
            cout << password << '\n'; 
        }
        return;
    }
    // impossible case 
    if(i >= alpha.size()) return;

    // next state
    go(n, alpha, password + alpha[i], i+1); 
    go(n, alpha, password, i+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<char> alpha;
    string password;
    int L, C;   

    cin >> L >> C;
    
    for(int i = 0; i < C; i++){
        char tmp;
        cin >> tmp;
        alpha.push_back(tmp);
    }
    sort(alpha.begin(), alpha.end());
    
    go(L, alpha, password, 0);

    return 0;
}