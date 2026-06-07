#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	string a, b;
	cin >> n >> a >> m >> b;
	string x = a + '$' + b;
	vector<int> pi(x.size());
	for(int i = 1; i < x.size(); i++)
	{
		int j = pi[i - 1];
		while(j > 0 && x[i] != x[j]) j = pi[j - 1];
		if(x[j] == x[i]) j++;
		pi[i] = j;
	}
	for(int i = 0; i < x.size(); i++)
		if(pi[i] >= n) { cout << "TAK"; return 0; }
	cout << "NIE";
	return 0;
}