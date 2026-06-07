#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void calculateGrid(vector<vector<ll>>& sum, vector<vector<ll>>& grid, ll wiersz, ll kolumna, ll N, ll M)
{
    ll smallestValue = 1e18;
    for(ll i = -1; i <= 1; i++)
    {
        if(wiersz + i < 0 || wiersz + i >= N)
            continue;

        ll value = sum[wiersz + i][kolumna - 1];
        if(value <= smallestValue)
            smallestValue = value;
    }

    if(wiersz > 0)
        smallestValue = min(smallestValue, sum[wiersz - 1][kolumna]);
    sum[wiersz][kolumna] = grid[wiersz][kolumna] + smallestValue;
}

void inputGrid(vector<vector<ll>>& grid, ll N, ll M)
{
    for(ll i = 0; i < N; i++)
    {
        for(ll j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
}

int main()
{

        ll N, M;
        cin >> N >> M;
        vector<vector<ll>> grid(N, vector<ll>(M));

        vector<vector<ll>> sum(N, vector<ll>(M, 0));
        inputGrid(grid, N, M);

        for(ll j = 0; j < M; j++)
        {
            for(ll i = 0; i < N; i++)
            {
                if(j == 0)
                {
                    sum[i][j] = grid[i][j];
                }
                else
                {
                    calculateGrid(sum, grid, i, j, N, M);
                }
            }
            for(ll i = N-2; i >= 0; i--)
            {
                sum[i][j] = min(sum[i][j], grid[i][j] + sum[i + 1][j]);
            }
        }

        ll lastIndex = M - 1;
        ll smallestValue = 1e18;
        for(ll y = 0; y < N; y++)
        {
            ll value = sum[y][lastIndex];
            if(value <= smallestValue)
                smallestValue = value;
        }
            cout << smallestValue << '\n';
    return 0;
}
