#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <utility>

typedef pair<int, int> PII;

vector<PII> V;

bool cmp(PII A, PII B)
{
	return A.second * B.first > A.first* B.second;
}

int main()
{
	int n, W;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int weight, price;
		cin >> weight >> price;
		V.push_back(PII(weight, price));
	}

	sort(V.begin(), V.end(), cmp);

	cin >> W;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int z = min(W, V[i].first);
		W -= z;
		ans += z * V[i].second;
	}

	cout << "Maximum Cost: " << ans;

	return 0;
}
