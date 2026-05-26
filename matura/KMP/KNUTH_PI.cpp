#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while(q--)
	{
		string a; cin >> a;
		int n = a.size();
		vector<int> pi(n);
		for(int i = 1; i < n; i++)
		{
			int j = pi[i - 1];
			while(j > 0 && a[i] != a[j]) j = pi[j - 1];
			if(a[j] == a[i]) j++;
			pi[i] = j;
		}
		for(int i = 0; i < n; i++) cout << pi[i] << ' ';
		cout << '\n';	
	}
	return 0;
}