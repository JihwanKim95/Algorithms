#include <iostream>
#include <vector>
#include <algorithm>
#define PIV (1 << 4)

/* 구간 합 구하기 */
using namespace std;
int tree[PIV * 2];


void update(int n, int v){
    n += PIV;
    tree[n] = v;

    while(n >>= 1)  // reaching ancestor 
        tree[n] = tree[n*2] + tree[n*2+1];

        
}

int main(){

}


