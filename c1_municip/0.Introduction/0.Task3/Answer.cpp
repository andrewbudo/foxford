#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main1()
{
	int n, k;
	cin >> n >> k;
	vector <vector<int> > bets(k, vector<int>(4));
	for (int i = 0; i < k; ++i)
		cin >> bets[i][0] >> bets[i][1] >> bets[i][2] >> bets[i][3];
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		p[i] = i + 1;
	do
	{
		int j;
		for (j = 0; j < k; ++j)
		{
			int a = bets[j][0];
			int b = bets[j][1];
			int c = bets[j][2];
			int d = bets[j][3];
			if ((find(p.begin(), p.end(), a) < find(p.begin(), p.end(), b)) +
				(find(p.begin(), p.end(), c) < find(p.begin(), p.end(), d)) != 1)
				break;
		}
		if (j == k)
		{
			for (auto x : p)
				cout << x << " ";
			cout << endl;
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << 0 << endl;
	return 0;
}