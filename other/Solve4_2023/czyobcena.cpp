#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

bool isFinden(const vector<ll>& array, ll left, ll right, ll target)
{
    while (left <= right) 
    {
        ll middle = left + (right - left) / 2;

        if (array[middle] == target)
            return true;
 
        if (array[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

	ll size;
	cin >> size;
	
	vector<ll> ciag(size);
	for(ll i = 0; i < size; i++)
	{
		cin >> ciag[i];	
	}
	
	ll requests;
	cin >> requests;
    
	sort(ciag.begin(), ciag.end());

	for(ll i = 0; i < requests; i++)
	{
		ll value;
		cin >> value;

		if(isFinden(ciag, 0, size - 1, value))
		{
		    cout << "TAK" << "\n";
		}
		else
		{
		    cout << "NIE" << "\n";
		}
	}
    return 0;
}