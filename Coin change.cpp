#include <bits/stdc++.h>
using namespace std;

int coins[9] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
int coinlist[100];

int coin_list(int n)
{

    int i = 0;
    while(n != 0){
        for(int j=8; j>=0; j--){
            if(n>=coins[j]){
                n -= coins[j];
                coinlist[i++] = coins[j];
                break;
            }
        }
    }

    return i;
}

int main()
{
    int n;
    cin >> n;
    int i = coin_list(n);
    for(int j=0; j<i; j++)
        cout << coinlist[j] << " ";

    return 0;
}
