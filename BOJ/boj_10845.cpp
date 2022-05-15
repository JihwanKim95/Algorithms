#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int q[100001] = {0,};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../input.txt", "r", stdin);
    int begin = 0, end = 0;
    int cnt, val; 
    string cmd; 
    cin >> cnt;
    while(cnt--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> val;
            q[end] = val;
            end+=1;
        } 
        else if(cmd == "pop"){
            if(end == begin){
                cout << "-1\n";
            }
            else{
                cout << q[begin] << "\n";
                q[begin] = 0;
                begin+=1;
            }
        }
        else if(cmd == "size"){
            cout << end-begin << "\n";
        }
        else if(cmd == "empty"){
            if(begin == end){
                cout << "1\n";
            } 
            else{
                cout << "0\n";
            } 
        }
        else if(cmd == "front"){
            if(begin == end) cout << "-1\n";
            else cout << q[begin] << "\n";
        }
        else if(cmd == "back"){
            if(begin == end) cout << "-1\n";
            else cout << q[end-1] << "\n";
        }
    }
    return 0;
}
