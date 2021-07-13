#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100000

using namespace std;

int in[MAX];
vector<int> t[MAX];

int main(){
    //m: 간선   n: 노드 수
    int m, n, a, b;

    cin >> m >> n;
    for(int i = 0 ; i < m; i++){
        cin >> a >> b; 
    }
    queue<int> q;
    for(int i = 0; i <= m; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int node : t[v]){
            if((in[node] -= 1) == 0){
                cout << node;
                q.push(node);
            }
            
        }

    }

}