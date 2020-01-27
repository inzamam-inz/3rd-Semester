#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100], Gt[100][100];
int cou = 1;
int color[100], d[100], f[100], prev[100];
stack <int> f1;
int times=0, SCC[100];

void print_path(int s, int v) {
    if(s==v) {
        printf("%d->",s);
    }
    else if(prev[v]==-1) {
        printf("No Path");
    }
    else {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
}

void DFS_visit(int u, int n) {
    times++;
    d[u]=times;
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
    times++;
    f[u]=times;
    f1.push(u);
    color[u]=BLACK;
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


void DFS_visitT(int u, int n, int pos) {
    times++;
    d[u]=times;
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(Gt[u][v]==1) {

            if(color[v]==WHITE)
            {

                prev[v]=u;
                DFS_visitT(v,n, pos);
            }
        }
    }
    times++;
    f[u]=times;
    color[u]=BLACK;
    SCC[u] = pos;
}

void DFSt(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }



    while(!f1.empty()) {
        if(color[f1.top()]==WHITE){
            DFS_visitT(f1.top(),n, cou);
            cou++;
        }
        f1.pop();
    }
}

int main() {
    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
            Gt[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        Gt[v][u]=1;
    }


    DFS(n);
    DFSt(n);

    for(int i=1; i<cou; i++){
        for(int k=0; k<n; k++){
            if(SCC[k] == i){
                cout << k << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
