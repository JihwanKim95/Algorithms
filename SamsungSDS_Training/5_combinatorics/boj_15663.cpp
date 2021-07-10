#include <iostream>
#include <algorithm>

/* N과 M */ 
using namespace std;
int n, m, a[10], answer[10];
bool used[10];   

void recur(int k){
    if(k == m){ 
        for(int i = 0; i < m; i++){
            cout << answer[i] << ' ';
        }
        cout << "\n"; 
        return; 
    }
    int prev = 0;
    for (int i = 0; i < n; i++){
        if(used[i]) continue;  // omit duplication 
        if(prev != a[i]){  
            used[i] = true;
            answer[k] = a[i]; 
            prev = a[i];
            recur(k + 1);
            used[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("../input.txt", "r", stdin);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    sort(a, a + n);
    recur(0);

    return 0;
} // S