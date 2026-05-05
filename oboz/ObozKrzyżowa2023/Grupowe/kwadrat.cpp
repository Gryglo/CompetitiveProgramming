#include <iostream>
#include <string>
#define ll unsigned long long
using namespace std;
int main() 
{
   ll liczba;
   cin>>liczba;
    string napis;
    for (int i=0; i<liczba - 1; i++)
    {
        napis += "9";
    }
    napis += "8";
    for (int i=0; i<liczba - 1; i++)
    {
        napis += "0";
    }
    napis += "1";
    cout<<napis;
    return 0;
}
