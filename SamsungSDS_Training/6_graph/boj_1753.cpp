#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 20005 // == 그래프 일렬로 늘어졌을 때의 최악시간복잡도

struct Node{
    int to, w;
};
bool operator<(Node a, Node b){
    return a.w > b.w;
}

/* 최단경로 */
using namespace std;
vector<Node> g[MAX];
vector<int> v[MAX];
int d[MAX];
int cnt; 
int ans; 

int main(){
    int V, E, S; 
    cin >> V >> E >> S;
    for(int i = 1; i <= E; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<Node> pQ; 
    pQ.push({S, 0});
    memset(d, 0x3f, sizeof(d));  // fill memory : INF value 
    d[S] = 0;
    while(!pQ.empty()){
        Node n = pQ.top(); pQ.pop();
        for(Node next : g[n.to]){
            if(d[next.to] > n.w + next.w){  // 다음까지의 distance 확인, 갱신 
                d[next.to] = n.w + next.w;
                pQ.push({next.to, d[next.to]});
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(d[i] == d[MAX - 1])
            cout << "INF\n";
        else 
            cout << d[i] << "\n"; 
    }


} // S


