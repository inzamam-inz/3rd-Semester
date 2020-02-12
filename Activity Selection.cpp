#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int > PII;
vector <PII> V;

bool cmp(PII A, PII B)
{
    return A.second < B.second;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int s, f;
        cin >> s >> f;
        V.push_back(PII(s, f));
    }

    sort(V.begin(), V.end(), cmp);

    cout << "(" << V[0].first << ", " <<V[0].second << ") ";
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (V[j].first >= V[i].second)
        {
            cout << ", (" << V[j].first << ", " << V[j].second << ") ";
            i = j;
        }
    }

    return 0;
}
