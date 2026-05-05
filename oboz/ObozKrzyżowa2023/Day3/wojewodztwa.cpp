#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long

using namespace std;

struct Wojewodztwo
{
    int numer;
    ll liczbaMieszkancow;
    
    Wojewodztwo(int numer, ll liczbaMieszkancow)
    {
        this->numer = numer;
        this->liczbaMieszkancow = liczbaMieszkancow;
    }
};

bool sortWojewodztwa(Wojewodztwo a, Wojewodztwo b)
{
    return a.liczbaMieszkancow < b.liczbaMieszkancow;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    bool end = false;
    vector<Wojewodztwo> wojewodztwa;
    wojewodztwa.reserve(N + 1);
    int size = N + 1;
    wojewodztwa.emplace_back(0, 0);

    for(int i = 0; i < N; i++)
    {
        ll value;
        cin >> value;
        wojewodztwa.emplace_back(i + 1, value);
    }

    sort(wojewodztwa.begin(), wojewodztwa.end(), sortWojewodztwa);
    vector<int> answears;
    answears.reserve(N);
    //answears.push_back(wojewodztwa[N].numer);

    ll previousSum = wojewodztwa[0].liczbaMieszkancow;

    for(int x = 1; x < size; x++)
    {
        if(end)
            break;
        previousSum += wojewodztwa[x].liczbaMieszkancow;
        ll suma = previousSum;
        int index = x + 1;

        while(index < size)
        {
            if(suma >= wojewodztwa[index].liczbaMieszkancow)
            {
                suma += wojewodztwa[index].liczbaMieszkancow;
                if(index == N)
                {
                    answears.push_back(wojewodztwa[x].numer);
                    for(int i = x + 1; i < size; i++)
                    {
                        answears.push_back(wojewodztwa[i].numer);
                        end = true;
                    }
                    break;
                }
            }
            index++;
        }
    }

    sort(answears.begin(), answears.end());
    for(const int& value : answears)
    {
        cout << value << " ";
    }

    return 0;
}
