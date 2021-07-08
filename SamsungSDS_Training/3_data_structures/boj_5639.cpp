#include <iostream>
#include <vector>

// 이진검색트리 
using namespace std;

int idx = 0, tree[10000];


void recur (int s, int e){
    // a[s] == 전위순회에서는 root 
    if(s == e){
        cout << tree[s];
    }
    else if (s > e){
        return;
    }
    else {
        int where = s + 1;
        while(where <= e){
            if(tree[where] > a[s]) break;
            else where++;
        }
        // left 
        
        // right 
        
    }

}

int main(){
    freopen("../../input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin.eof() != true){
        cin >> tree[idx];
        idx++;
    } 




    
}
