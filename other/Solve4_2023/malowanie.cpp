#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000000;
const int B = 1000;
const int MAXB = MAXN / B + 2;

int T_now[MAXB][B];
int B_color[MAXB];
bool B_isMoreColors[MAXB];
int B_summary[MAXB];

bool isColorPresent[MAXN];

int n, m;

void update(int from_index, int to_index, int color)
{
    //Zaokraglane w dol bo int
    int from_bucket = from_index / B;
    int to_bucket = to_index / B;

    //Iteracja do to_index + 1 lub do pierwszego elementu nastepnego bucketa
    for(int i = from_index % B; i < ((from_bucket == to_bucket) ? to_index % B + 1 : B); i++)
        T_now[from_bucket][i] = color;
    B_isMoreColors[from_bucket] = true;

    if(from_bucket == to_bucket) return;

    for(int i = from_bucket + 1; i < to_bucket; i++)
    {
        B_color[i] = color;
        if(B_isMoreColors[from_bucket])
            memset(T_now[i], 0, sizeof(T_now[i]));
        B_isMoreColors[from_bucket] = false;
    }

    for(int i = 0; i < to_index % B + 1; i++)
        T_now[to_bucket][i] = color;
}
int main()
{
    cin >> n >> m;
    while(m--)
    {
        int from, to, color;
        cin >> from >> to >> color;
        color++;
        update(from, to, color);
    }

    int result = 0;
    for (int bucket_index = 0; bucket_index < (n / B) + 1; bucket_index++)
{
    if (!B_isMoreColors[bucket_index] && B_color[bucket_index] > 0)
    {
        if (!isColorPresent[B_color[bucket_index]])
        {
            result++;
            isColorPresent[B_color[bucket_index]] = true;
        }
    }
    else
    {
        for (int i = 0; i < B; i++)
        {
            int color = T_now[bucket_index][i] == 0 ? B_color[bucket_index] : T_now[bucket_index][i];
            if (color != 0 && !isColorPresent[color])
            {
                result++;
                isColorPresent[color] = true;
            }
        }
    }
}


    cout << result;
    return 0;
}

