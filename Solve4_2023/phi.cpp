#include <iostream>

#define ll long long
using namespace std;

int main()
{
	ll input;
	cin >> input;

    int wynik = input; 

	for(ll pierwsza = 2; pierwsza * pierwsza <= input; ++pierwsza)
	{
		
		if (input % pierwsza == 0) 
		{
			
			while (input % pierwsza == 0)
            {
                input = input / pierwsza;
            }
				
			wynik -= wynik / pierwsza;
		}
	}

	if (input > 1)
    {
        wynik -= wynik / input;
    }

    cout << wynik;
	return 0;
}
