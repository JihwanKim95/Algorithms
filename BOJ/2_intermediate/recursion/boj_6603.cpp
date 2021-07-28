#include <iostream>

/* 로또 */ 
using namespace std;
int k, a[55], res[6];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../../../input.txt", "r", stdin);

    while(1){
        fill(&a[0], &a[55], 0);
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++){
            int tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        
    }

}