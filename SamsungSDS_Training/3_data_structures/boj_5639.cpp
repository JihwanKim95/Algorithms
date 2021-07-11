#include <iostream>
#include <vector>

/* 이진 검색 트리 */
using namespace std;

int sz = 0, A[10000]; 

void recur (int s, int e){        
    // final condition 
    // a[s] == 전위순회에서는 root 
    // 후위순회에서는 가장 마지막에 출력되어야 함
    if(s == e){   // leaf
        cout << A[s] << '\n';
        return;
    }
    else if (s > e){
        return;
    }

    // use the property of binary tree
    else { 
        int where = s + 1;
        while(where <= e){
            if(A[where] > A[s]) break;
            else where++;
        }
        // left
        recur(s + 1, where - 1);
        // right 
        recur(where, e);
        // root 출력
        cout << A[s] << '\n';
    }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> A[sz]){
        sz++;
    }
    
    recur(0, sz - 1);
}
