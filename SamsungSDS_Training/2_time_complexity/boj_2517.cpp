#include <iostream>
#include <vector>
#include <algorithm>

/* 달리기 */
using namespace std;
typedef pair<int, int> pii;

int n;
pii player[500000];

bool comp(pii p1, pii p2){
    return p1.second > p2.second;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int power;
        cin >> power;
        player[i].first = i;
        player[i].second = power;
    }
    // sort 
    sort(player, player+n, comp);

    for(int i = 0; i < n ;i++) cout << "sorted :: " << player;

}