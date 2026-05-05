#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
const int B = 550;
const int MAXB = MAXN / B + 2;

int T_now[MAXN];
int B_lazy[MAXB];
int B_summary[MAXB];

//Oproznianie B_lazy dla danego bucketa
void push_down(int bucket_index)
{
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
        T_now[i] += B_lazy[bucket_index];
    B_lazy[bucket_index] = 0;
}

//Przeliczamy cały bucket na nowo
void recompute_bucket(int bucket_index)
{
    push_down(bucket_index);
    B_summary[bucket_index] = 0;
    //Iteracja po kazdym elemencie, do pierwszego elementu nastepnego bucketa
    for(int i = bucket_index * B; i < (bucket_index + 1) * B; i++)
        B_summary[bucket_index] += T_now[i];
}

void update(int from_index, int to_index, int v)
{
    //Zaokraglane w dol bo int
    int from_bucket = from_index / B;
    int to_bucket = to_index / B;

    //Iteracja do to_index + 1 lub do pierwszego elementu nastepnego bucketa
    for(int i = from_index; i < min(to_index + 1, (from_bucket + 1) * B); i++)
        T_now[i] += v;
    //Jak updatujemy juz jakies elementy ktore w jakiejs czesci tylko sa w jakims bucket, musimy juz przeliczyc caly bucket na nowo
    recompute_bucket(from_bucket);
    //Jeżeli cały przedział znajdował się w jednym bucket, wszystko już przeliczyliśmy
    if(from_bucket == to_bucket) return;

    for(int i = from_bucket + 1; i < to_bucket; i++)
    {
        //To jest ogolnie wartosc ile zalegamy z dodaniem dla kazdego pojedynczego elementu w bucket
        B_lazy[i] += v;
        //To jest odrazu suma tego bucket
        B_summary[i] += v * B;
    }
    //Jak jeszcze cos jest poza przedziałem z prawej strony, tez trzeba to zalatwic
    for(int i = to_bucket * B; i < to_index + 1; i++)
        T_now[i] += v;
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
        result += T_now[i];
    if(from_bucket == to_bucket) return result;
    for(int i = from_bucket + 1; i < to_bucket; i++)
        result += B_summary[i];
    for(int i = to_bucket * B; i < to_index + 1; i++)
        result += T_now[i];
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    while(n--)
    {
        string op; 
        cin >> op;
        if(op == "update")
        {
             int from, to, v;
            cin >> from >> to >> v;
            update(from, to, v);
        }
        else if(op == "query")
        {
            int from, to;
            cin >> from >> to;
            cout << query(from, to) << '\n';
        }

    }
    return 0;
}