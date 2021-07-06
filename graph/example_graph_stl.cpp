#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
public: 
    int nV, nE;
    vector<int> *edges; 

    void Init(const char * _filename)
    {
        FILE *input = fopen(_filename, "r");
        fscanf(input, "%d", &nV);
        fscanf(input, "%d", &nE);
        edges = new vector<int>[nV];
        for(int i=0; i<nE; i++)
        {
            char a, b;
            fscanf(input, "%c %c", &a, &b); 
            int x, y;
            x = a - 'A';
            y = b - 'A';
            edges[x].push_back(y);
        }
        fclose(input);
    }

};

void BFS(Graph &_g, int _stIdx=0)
{
    // visit flag made for all node 
    bool *visit = new bool [_g.nV];

    for(int  i = 0; i < _g.nV; i++)
    {
        visit[i] = false;
    }

    queue<int> q;
    q.push(_stIdx);
    visit[_stIdx] = true;

    while(!q.empty()) 
    {
         int x = q.front();
         q.pop(); 
         printf("%c", x + 'A');

         for(int i=0; i<_g.edges[x].size(); i++)
         {
             if(!visit[_g.edges[x][i]])
             {
                 q.push(_g.edges[x][i]);
                 visit[_g.edges[x][i]] = true;
             }
         }
    }
    delete [] visit; 
}

int main(int argc, char ** argv)
{
    // printf("%s || %s || %s ||\n", argv[0], argv[1], argv[2]);
    Graph g;
    g.Init(argv[1]);
    printf("\n");
    BFS(g);
    printf("\n");

    return 0;
}