#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while(q--)
	{
		string a, b; cin >> a >> b;
		string x = b + '$' + a + a;
		vector<int> pi(x.size());
		for(int i = 1; i < x.size(); i++)
		{
			int j = pi[i - 1];
			while(j > 0 && x[i] != x[j]) j = pi[j - 1];
			if(x[j] == x[i]) j++;
			pi[i] = j;
		}
		bool valid = false;
		for(int i = 0; i < x.size(); i++)
			if(pi[i] >= b.size()) { valid = true; break; }
		if(valid) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}