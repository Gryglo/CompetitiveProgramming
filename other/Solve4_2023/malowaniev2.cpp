#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000000;
const int B = 2200;
const int MAXB = MAXN / B + 2;

int* T_now = new int[MAXN];
int* B_color = new int[MAXB];
bool* B_isMoreColors = new bool[MAXB];
int* B_summary = new int[MAXB];

bool* isColorPresent = new bool[MAXN];

int n, m;

void update(int from_index, int to_index, int color)
{
    //Zaokraglane w dol bo int
    int from_bucket = from_index / B;
    int to_bucket = to_index / B;

    //Iteracja do to_index + 1 lub do pierwszego elementu nastepnego bucketa
    for(int i = from_index; i < min(to_index + 1, (from_bucket + 1) * B); i++)
        T_now[i] = color;
    B_isMoreColors[from_bucket] = true;

    if(from_bucket == to_bucket) return;

    for(int bucket_index = from_bucket + 1; bucket_index < to_bucket; bucket_index++)
    {
        B_color[bucket_index] = color;
        if(B_isMoreColors[from_bucket])
        {
            for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
                T_now[i] = 0;
        }
        B_isMoreColors[from_bucket] = false;
    }

    for(int i = to_bucket * B; i < to_index + 1; i++)
        T_now[i] = color;
    B_isMoreColors[to_bucket] = true;
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
    for(int bucket_index = 0; bucket_index < (n / B) + 1; bucket_index++)
    {
        if(!B_isMoreColors[bucket_index] && B_color[bucket_index] > 0)
        {
            if(!isColorPresent[B_color[bucket_index]])
            {
                result++;
                isColorPresent[B_color[bucket_index]] = true;
            }
        }
        else
        {
            for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
            {
                if(T_now[i] == 0)
                {
                    if(B_color[bucket_index] == 0)
                        continue;
                    if(!isColorPresent[B_color[bucket_index]])
                    {
                        result++;
                        isColorPresent[B_color[bucket_index]] = true;
                    }
                }
                else if(!isColorPresent[T_now[i]])
                {
                    result++;
                    isColorPresent[T_now[i]] = true;
                }
            }
        }
    }
    cout << result;
    return 0;
}

