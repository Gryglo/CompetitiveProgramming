#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T, N, M;
const ll INF = LLONG_MAX;

vector<vector<ll>> dp;
vector<vector<ll>> grid; // Nasza ukryta plansza
bool error_found = false;
int queries = 0;

ll ask(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
        return INF;
    if(dp[x][y] != 0) return dp[x][y];
    
    queries++;
    // Pobieramy wynik z wygenerowanej planszy (indeksujemy od 0)
    ll res = grid[x-1][y-1]; 
    dp[x][y] = res;
    return res;
}

void print_ans(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M) {
        cout << "BLAD: Podano wspolrzedne poza plansza! (! " << x << " " << y << ")\n";
        error_found = true;
        return;
    }

    ll val = grid[x-1][y-1];
    ll up = (x > 1) ? grid[x-2][y-1] : INF;
    ll down = (x < N) ? grid[x][y-1] : INF;
    ll left = (y > 1) ? grid[x-1][y-2] : INF;
    ll right = (y < M) ? grid[x-1][y] : INF;

    if (val < up && val < down && val < left && val < right) {
        // Wszystko OK, znaleziono lokalne minimum
    } else {
        cout << ">>> BLAD: Znaleziono kontrprzyklad! <<<\n";
        cout << "Twoj program odpowiedzial: ! " << x << " " << y << "\n";
        cout << "Wartosc w tym polu to: " << val << "\n";
        cout << "To NIE jest lokalne minimum (ktoryst z sasiadow jest mniejszy lub rowny).\n\n";
        
        cout << "Plansza " << N << "x" << M << " (wiersze x kolumny):\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cout << setw(3) << grid[i][j] << " ";
            }
            cout << "\n";
        }
        error_found = true;
    }
}

// Twoja glowna logika
void solve()
{
    dp.assign(N + 5, vector<ll>(M + 5, 0));
    
    int l_x = 1, r_x = N;
    int l_y = 1, r_y = M;
    ll globalMin = INF;
    pii globalMinPos = {0, 0};
    
    while(l_x <= r_x && l_y <= r_y)
    {
        if((r_x - l_x) >= (r_y - l_y)) //row
        {
            int m_x = (l_x + r_x) / 2;
            ll currMin = INF;
            ll minPos = 0;
            for(int y = l_y; y <= r_y; y++)
            {
                ll curr = ask(m_x, y);
                if(curr < currMin)
                {
                    currMin = curr; minPos = y;
                }
            }
            ll up_val = ask(m_x - 1, minPos);
            ll down_val = ask(m_x + 1, minPos);
            if(currMin < up_val && currMin < down_val)
            {
                print_ans(m_x, minPos);
                return;
            }

            if(up_val < globalMin)
            {
                globalMin = up_val;
                globalMinPos = {m_x - 1, minPos};
            }
            if(down_val < globalMin)
            {
                globalMin = down_val;
                globalMinPos = {m_x + 1, minPos};
            }
            if(globalMinPos.f < m_x)
                r_x = m_x - 1;
            else
                l_x = m_x + 1;
        }
        else
        {
            int m_y = (l_y + r_y) / 2;
            ll currMin = INF;
            ll minPos = 0;
            for(int x = l_x; x <= r_x; x++)
            {
                ll curr = ask(x, m_y);
                if(curr < currMin)
                {
                    currMin = curr; minPos = x;
                }
            }
            ll left_val = ask(minPos, m_y - 1);
            ll right_val = ask(minPos, m_y + 1);
            if(currMin < left_val && currMin < right_val)
            {
                print_ans(minPos, m_y);
                return;
            }

            if(left_val < globalMin)
            {
                globalMin = left_val;
                globalMinPos = {minPos, m_y - 1};
            }
            if(right_val < globalMin)
            {
                globalMin = right_val;
                globalMinPos = {minPos, m_y + 1};
            }
            if(globalMinPos.s < m_y)
                r_y = m_y - 1;
            else
                l_y = m_y + 1;   
        }
    }
    print_ans(globalMinPos.f, globalMinPos.s);
}

int32_t main()
{
    srand(time(NULL));
    int tests = 0;
    
    while(true) {
        tests++;
        // Losujemy male wymiary, zeby dalo sie to przeanalizowac recznie
        N = rand() % 4 + 3; // 3 do 6
        M = rand() % 4 + 3; // 3 do 6
        
        grid.assign(N, vector<ll>(M, 0));
        
        // Wypelniamy unikalnymi wartosciami i tasujemy, zeby nie bylo rownych sasiadow
        vector<ll> vals;
        for(int i = 1; i <= N * M; i++) vals.push_back(i);
        random_shuffle(vals.begin(), vals.end());
        
        int idx = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                grid[i][j] = vals[idx++];
            }
        }
        
        queries = 0;
        error_found = false;
        
        solve();
        
        if(error_found) {
            cout << "Zatrzymano na tescie nr: " << tests << "\n";
            break;
        }
        
        if(tests % 1000 == 0) {
            cout << "Przejdziono " << tests << " testow...\n";
        }
    }
    return 0;
}