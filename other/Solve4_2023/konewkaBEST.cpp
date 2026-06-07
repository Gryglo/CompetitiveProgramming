#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int MAXN = 300100;
const int B = 300;
const int MAXB = MAXN / B + 2;

int T_now[MAXN];
int B_color[MAXB];
int B_summary[MAXB];
vector<priority_queue<int>> B_max(MAXB);

int n, k, q; 

//Oproznianie B_lazy dla danego bucketa
void push_down(int bucket_index)
{
    if (B_color[bucket_index] == 0) return;
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
        T_now[i] += B_color[bucket_index];
    B_color[bucket_index] = 0;
}

//Przeliczamy cały bucket na nowo
void recompute_bucket(int bucket_index)
{
    push_down(bucket_index);
    B_summary[bucket_index] = 0;
    B_max[bucket_index] = priority_queue<int>();
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
        if(T_now[i] >= k)
            B_summary[bucket_index]++;
        else
            B_max[bucket_index].push(T_now[i]);
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
    {
        B_color[i]++;
        
        while(B_max[i].top() + B_color[i] >= k)
        {
            B_max[i].pop();
            B_summary[i]++;
        }
        
    }
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
        /*
        priority_queue<int> temp = B_max[i];
        while(temp.top() + B_lazy[i] >= k)
        {
            temp.pop();
            B_summary[i]++;
        }
        */
        result += B_summary[i];
    }

    for(int i = to_bucket * B; i < to_index + 1; i++)
        if(T_now[i] >= k)
            result++;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> q;

    for(int i = 0; i < n; i++)
    {
        cin >> T_now[i];
    }
    for(int b = 0; b < MAXB; b++)
    {
        B_summary[b] = 0;
        B_color[b] = 0;
        int start = b * B;
        int end = min((b + 1) * B, n);
        for(int i = start; i < end; i++)
        {
            if(T_now[i] >= k)
                B_summary[b]++;
            else
                B_max[b].push(T_now[i]);
        }
    }

    bool isFirstQuery = true;
    bool isPrevQueryEven = false;
    int counterLine = 0;
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