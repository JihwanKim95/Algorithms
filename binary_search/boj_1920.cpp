#include <iostream>
#include <vector>
#include <algorithm>

/* 수 찾기 */
using namespace std;

int N, M; 
int A[100001];
int Q[100001];

// return 1 if exists 
int binary_search(int key){
    int left, right, mid;
    left = 0;
    right = N - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(A[mid] == key) return 1;
        else if (key < A[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return 0;
}

int main(){
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> Q[i];
    }

    // sorting 
    sort(A, A+N);
    
    // binary search
    for(int i = 0; i < M; i++){
        cout << binary_search(Q[i]) << "\n";
    }

}