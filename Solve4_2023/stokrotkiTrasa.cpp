#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void calculateGrid(vector<vector<ll>>& sum, vector<vector<ll>>& grid, vector<vector<ll>>& path, ll wiersz, ll kolumna, ll N, ll M)
{
    ll smallestValue = 1e18;
    ll smallestIndex = -1;
    for(ll i = -1; i <= 1; i++)
    {
        if(wiersz + i < 0 || wiersz + i >= N)
            continue;

        ll value = sum[wiersz + i][kolumna - 1];
        if(value < smallestValue)
        {
            smallestValue = value;
            smallestIndex = wiersz + i;
        }
    }
    sum[wiersz][kolumna] = grid[wiersz][kolumna] + smallestValue;
    path[wiersz][kolumna] = smallestIndex;
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
    vector<vector<ll>> path(N, vector<ll>(M, -1));

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
                calculateGrid(sum, grid, path, i, j, N, M);
            }
        }
    }

    ll lastIndex = M - 1;
    ll smallestValue = 1e18;
    ll smallestIndex = -1;
    for(ll y = 0; y < N; y++)
    {
        ll value = sum[y][lastIndex];
        if(value < smallestValue)
        {
            smallestValue = value;
            smallestIndex = y;
        }
    }

    vector<ll> result(M);
    for(ll i = M - 1; i >= 0; i--)
    {
        result[i] = smallestIndex;
        smallestIndex = path[smallestIndex][i];
    }

    for(ll i = 0; i < M; i++)
    {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}
