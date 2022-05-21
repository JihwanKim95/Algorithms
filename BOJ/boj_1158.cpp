#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k; 
    queue<int> q;
    vector<int> v;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(!q.empty()){
        // 1 ... k - 1
        for(int i = 1; i < k; i++){
            int cur = q.front();
            q.pop();
            q.push(cur);
        }
        // k
        v.push_back(q.front());
        q.pop();
    }

    cout << '<';
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i == v.size() - 1) continue;
        cout << ", ";
    }
    cout << '>';

    return 0;
}