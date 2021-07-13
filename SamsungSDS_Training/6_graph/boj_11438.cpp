#include <iostream> 
#include <queue>
#include <vector>
#define MAX 100005
#define PIV 17

vector<int> con[MAX];
int dep[MAX];
int par[PIV][MAX];

/* LCA */
using namespace std;


int lca(int a, int b){
    int tmp;
    if(dep[b] < dep[a]) tmp = a, a = b, b = tmp;
    tmp = dep[b] - dep[a];
    for(int i = 0  i < PIV; i++){
        if(tmp & (1 << i))
            b = par[i][b];
    }

}


void bfs(){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;   
        con[a].push_back(b);
        con[b].push_back(a);
        dep[i] = 0;
    }

    queue<int> q; 
    q.push(1);
    q.push(1);  // depth 
    int depth = 0;
    while(!q.empty()){
        int val = q.front(); q.pop();  // value 먼저 빼고 
        depth = q.front(); q.pop();    // depth 이후에 뺀다 
        

    }


}