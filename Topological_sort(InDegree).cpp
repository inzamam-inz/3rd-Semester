#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack <int> s;
    int n, e, u, v;
    cout << "Enter number of nodes: ";
    scanf("%d",&n);
    cout << "Enter number of edges: ";
    scanf("%d",&e);
    int G[n][n];
    int inDegree[n] = {0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        cout << "Enter edges: ";
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        inDegree[v]++;
    }

    for(int i=0; i<n; i++){
        if(inDegree[i] == 0)
            s.push(i); break;
    }

    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout << node << " -> ";
        for(int i=0; i<n; i++){
            if(G[node][i] == 1){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    s.push(i);
                }
            }
        }
    }

    return 0;
}
