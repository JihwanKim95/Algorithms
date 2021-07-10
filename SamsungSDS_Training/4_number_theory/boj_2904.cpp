#include <iostream>
#include <vector>

/* 수학은 너무 쉬워 */
using namespace std;

bool che[10000001];
int n, a[100];
vector<int> prime;


int main(){
    for(int i = 2; i <= 1000000; i++){
        if(che[i]) continue;
        for(int j = i * 2; j <= 1000000; j+=i){
            che[j] = true;
        }
    }
    for(int i = 2; i <= 1000000; i++){
        if(!che[i]){
            prime.push_back(i);
        }
    }
    cout << prime.size();


}hj