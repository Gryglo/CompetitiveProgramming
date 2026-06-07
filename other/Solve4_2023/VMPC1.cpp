#include <iostream>

using namespace std;

int n;
int g[20];
int f[20];
bool used[20];

bool go(int index)
{
    if(index == n)
    {
        for(int i = 0; i < n; i++)
            if(f[(f[f[i]] + 1) % n] != g[i])
                return false;
        return true;
    }

    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            f[index] = i;
            used[i] = true;

            if(go(index + 1))
                return true;
            
            used[i] = false;
        }
    }

    return false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> g[i];
    
    for(int i = 0; i < n; i++)
        f[i] = -1;

    if (go(0)) 
    {
        cout << "TAK" << '\n';
        for (int i = 0; i < n; ++i)
            cout << f[i] << " ";

        /*
        cout << "\nTeraz z powrotem: \n";
        for(int i = 0; i < N; i++)
        {
            cout << g[(g[g[i]] + 1) % N] << " ";
        }   
        */

    } 
    else 
        cout << "NIE";
    

    return 0;
}