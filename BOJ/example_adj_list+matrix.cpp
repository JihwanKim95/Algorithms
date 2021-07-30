#include <iostream>
#include <vector>
using namespace std;

/* Adjacency List */
int main(){
    vector<int> adj[10];
    int v, e;

    // directed graph 
    for(int i = 0 ; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // undirected graph
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

/* Adjacency Matrix */ 
int main(){
    int adj_matrix[10][10] = {};
    int v, e;

    // directed graph    
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }

    // undirected graph 
    cin >> v >> e;
    for(int i = 0; i < e; i ++){
        int u, v;
        cin >> v >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
}
