#include <iostream>

/* 사전 */ 
using namespace std;

int n, m, k;
long cache[101][101];
char answer;

int getAZ(int a, int z){
    if(a == 0 || z == 0){
        return 1;
    }
    if(cache[a][z] != -1){
        return cache[a][z];
    }

    return cache[a][z] = getAZ(a - 1, z) + getAZ(a, z - 1); 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < 101; i++){
        for(int i = 0; i < 101; i++){
            cache[i][j] = 1; 
        }
    }


    // to-do
    // 가장 앞에 있는 문자열부터 채워나간다
    int countA = n, countZ = m;  // 앞으로 사용할 수 있는 문자 
    for(int i = 0; i < n+m; i++){
        // i 번째 문자열이 a라면 
        
        // i 번째 문자열이 z라면 

    }




}