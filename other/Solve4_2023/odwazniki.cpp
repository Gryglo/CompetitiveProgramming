#include <iostream>
#include <cmath>

#define ll long long
using namespace std;
pair<ll, ll> ext_gcd(ll a, ll b)
{
	if(b == 0)
		return {1, 0};
	pair<ll, ll> r = ext_gcd(b, a % b);
	return {r.second, r.first - (a/b) * r.second};
}

ll calculateGcd(ll a, ll b)
{
    return b == 0 ? a : calculateGcd(b, a % b);   
}

int main() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll gcd = calculateGcd(a, b);

    if (n % gcd != 0) 
    {
        cout << "NIE";
        return 0;
    }

    ll k = n / gcd;
    pair<ll, ll> solutionXY = ext_gcd(a, b);
    solutionXY.first  *= k;
    solutionXY.second *= k;

/*
    cout << a << " * " << solutionXY.first << " + " 
         << b << " * " << solutionXY.second << " = " 
         << a * solutionXY.first + b * solutionXY.second;
         */

    ll b_gcd = b / gcd;
    ll a_gcd = a / gcd;


    //l >= -firstX/b_gcd
    //l <= firstY/a_gcd


    //ll minT = (ll) ceil((double)(-solutionXY.first) / b_gcd);
    //ll maxT = (ll) floor((double)(solutionXY.second) / a_gcd);

    ll minT = (ll) -solutionXY.first / b_gcd;
    ll maxT = (ll) solutionXY.second / a_gcd;

    ll offset = 1000000; 

    minT -= offset;
    maxT += offset;

    ll currBestT = minT;
    ll bestResult = abs(solutionXY.first + currBestT * b_gcd) + abs(solutionXY.second - currBestT * a_gcd);

    for (ll i = minT; i <= maxT; i++) 
    {
        ll x = solutionXY.first + i * b_gcd;
        ll y = solutionXY.second - i * a_gcd;

        ll currResult = abs(x) + abs(y);
        if (currResult < bestResult) 
        {
            bestResult = currResult;
            currBestT = i;
        }
    }

    cout << bestResult;
    return 0;
}
