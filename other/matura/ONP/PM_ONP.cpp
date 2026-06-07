#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int n; cin >> n;
		string a; cin >> a;
		stack<ll> s;
		for(int i = 0; i < n; i++)
		{
			char c = a[i];
			if(c >= '0')
			{
				ll curr = a[i] - '0';
				s.push(curr);
				continue;
			}
			if(s.size() == 0 || s.size() == 1)
			{
				s.push(0); s.push(0); s.push(0);
				break;
			}
			ll first = s.top(); s.pop();
			ll second = s.top(); s.pop();
			if(c == '+') s.push(first + second);
			else if(c == '-') s.push(second - first);
			else if(c == '*') s.push(second * first);
			else if(c == '/')
			{
				if(first == 0)
				{ 
					s.push(0); s.push(0); s.push(0);
					break;
				}
				s.push(second / first);	
			}
		}
		if(s.size() == 1)
			cout << s.top() << '\n';
		else
			cout << "BRAK\n";
	}
	return 0;
}