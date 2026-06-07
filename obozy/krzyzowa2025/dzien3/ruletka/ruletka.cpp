#include <bits/stdc++.h>
using namespace std;

int x = 192;

int ask(vector<int>& query)
{
    cout << "? " << query.size() << " ";
    for(int v : query)
        cout << v << ' ';
    cout << endl;
    int d; cin >> d;
    return d;
}



int main()
{
    vector<int> rightSide(128);
    for(int i = 1; i <= 128; i++)
        rightSide[i - 1] = i;
    vector<int> leftSide(128);
    for(int i = 1; i <= 128; i++)
        leftSide[i - 1] = i + 128;
    vector<int> upSide(128);
    for(int i = 0; i < 128; i++)
    {
        upSide[i] = (i + 192) % 257;
        if(i + 192 > 256) upSide[i]++;
    }
    vector<int> downSide(128);
    for(int i = 0; i < 128; i++)
        downSide[i] = i + 64;
    
    bool left = true;
    int d = ask(rightSide);
    if(d == 0)
    {
        d = ask(leftSide);
        left = false;
    }

    if(d == 64)
    {    
        if(left)
        {
            //128 i 1
            //niewiadomo czy to 192 czy 193
            vector<int> tUp;
            for(int i = 193; i <= 256; i++)
                tUp.push_back(i);
            for(int i = 1; i <= 65; i++)
                tUp.push_back(i);
            if(ask(tUp) == 0)
                cout << "! " << 193 << endl;
            else
                cout << "! " << 192 << endl;
        }
        else
        {
            //niewiadomo czy to 64 czy 65
            vector<int> tUp;
            for(int i = 65; i <= 256; i++)
                tUp.push_back(i);
            if(ask(tUp) == 0)
                cout << "! " << 65 << endl;
            else
                cout << "! " << 64 << endl;

        }
        return 0;
    }

    int d2 = ask(downSide);
    if(d2 == 0) //dol
    {
        if(left)
        {
            //czyli jest w lewym dolnym
            //czyli prawy ostatni
            cout << "! " << 128 + d << endl;
        }
        else
        {
            //czyli jest w prawym dolnym 
            cout << "! " << 129 - d << endl;
        }
    }
    else//gora
    {
        if(left) 
        {
            //czyli jest w lewym gornym
            cout << "! " << 256 - (d - 1) << endl;
        }
        else
        {
            //czyli jest w prawym gornym 
            cout << "! " << 1 + (d - 1) << endl;
        }
    }

    return 0;
}