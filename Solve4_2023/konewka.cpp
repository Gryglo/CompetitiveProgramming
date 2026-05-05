#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
const int B = 550;
const int MAXB = MAXN / B + 2;

int T_now[MAXN];
int B_lazy[MAXB];
int B_summary[MAXB];
vector<vector<int>> B_sorted(MAXB);

int n, k, q; 

int count_greater_than_x(int bucket_index, int x) 
{
    return B_sorted[bucket_index].end() - lower_bound(B_sorted[bucket_index].begin(), B_sorted[bucket_index].end(), x);
}

//Oproznianie B_lazy dla danego bucketa
void push_down(int bucket_index)
{
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    B_sorted[bucket_index].clear();
    for(int i = bucket_index * B; i < min((bucket_index + 1) * B, n); i++)
    {
        T_now[i] += B_lazy[bucket_index];
        B_sorted[bucket_index].push_back(T_now[i]);
    }
    sort(B_sorted[bucket_index].begin(), B_sorted[bucket_index].end());
    B_lazy[bucket_index] = 0;
}

//Przeliczamy cały bucket na nowo
void recompute_bucket(int bucket_index)
{
    push_down(bucket_index);
    B_summary[bucket_index] = 0;
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    for(int i = bucket_index * B; i < min((bucket_index + 1) * B, n); i++)
        if(T_now[i] >= k)
            B_summary[bucket_index]++;
}

void update(int from_index, int to_index)
{
    //Zaokraglane w dol bo int
    int from_bucket = from_index / B;
    int to_bucket = to_index / B;

    //Iteracja do to_index + 1 lub do pierwszego elementu nastepnego bucketa
    for(int i = from_index; i < min(to_index + 1, (from_bucket + 1) * B); i++)
        T_now[i]++;

    //Jak updatujemy juz jakies elementy ktore w jakiejs czesci tylko sa w jakims bucket, musimy juz przeliczyc caly bucket na nowo
    recompute_bucket(from_bucket);
    //Jeżeli cały przedział znajdował się w jednym bucket, wszystko już przeliczyliśmy
    if(from_bucket == to_bucket) return;

    for(int i = from_bucket + 1; i < to_bucket; i++)
        B_lazy[i]++;
    //Jak jeszcze cos jest poza przedziałem z prawej strony, tez trzeba to zalatwic
    for(int i = to_bucket * B; i < to_index + 1; i++)
        T_now[i]++;
    recompute_bucket(to_bucket);
}

int query(int from_index, int to_index)
{
    int from_bucket = from_index / B;
    int to_bucket = to_index / B;
    push_down(from_bucket);
    push_down(to_bucket);
    
    int result = 0; 
    for(int i = from_index; i < min(to_index + 1, (from_bucket + 1) * B); i++)
        if(T_now[i] >= k)
            result++;

    if(from_bucket == to_bucket) return result;

    //TUTAJ BŁĄD!
    for(int i = from_bucket + 1; i < to_bucket; i++)
    {
        int greater = count_greater_than_x(i, k - B_lazy[i]) - B_summary[i];
        if(greater > 0)
            B_summary[i] += greater;
        result += B_summary[i];
    }

    for(int i = to_bucket * B; i < to_index + 1; i++)
        if(T_now[i] >= k)
            result++;
    return result;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k >> q;

    for(int i = 0; i < n; i++)
    {
        cin >> T_now[i];
    }
    for(int b = 0; b < MAXB; b++)
    {
        B_summary[b] = 0;
        B_lazy[b] = 0;
        int start = b * B;
        int end = min((b + 1) * B, n);
        for(int i = start; i < end; i++)
        {
            B_sorted[b].push_back(T_now[i]);
            if(T_now[i] >= k)
                B_summary[b]++;
        }
        sort(B_sorted[b].begin(), B_sorted[b].end());
    }

    bool isFirstQuery = true;
    bool isPrevQueryEven = false;
    while(q--)
    {
        char operation;
        cin >> operation; 
        if(operation == '0') //update
        {
            int from, to; 
            cin >> from >> to; 
            
            update(from, to);
        }
        else if(operation == '1') //query 
        {
            int fromEven, toEven, fromOdd, toOdd;
            cin >> fromEven >> toEven >> fromOdd >> toOdd;
            
            int from, to;
            if(isFirstQuery || isPrevQueryEven) 
            { from = fromEven; to = toEven; }
            else 
            { from = fromOdd; to = toOdd; }

            int result = query(from, to);
            cout << result << '\n';
            if(result & 1)
                isPrevQueryEven = false;
            else 
                isPrevQueryEven = true;

            if(isFirstQuery)
                isFirstQuery = false;
        }

    }
    return 0;
}