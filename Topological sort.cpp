#include <iostream>
#include <stack>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100];
int color[100], d[100], f[100], prev[100];
int time=0;
stack <int> s;


void DFS_visit(int u, int n) {
    time++;
    d[u]=time;
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
    s.push(u);
}

void DFS(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        if(color[u]==WHITE)
            DFS_visit(u,n);
    }
}


int main() {
    int n, e, u, v;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        cout << "Enter edges:";
        cin >> u >> v;
        G[u][v]=1;
    }


    DFS(n);

    while (!s.empty())
    {
        cout << s.top() << '\t' ;
        s.pop();
    }
    cout << '\n';

    return 0;
}
