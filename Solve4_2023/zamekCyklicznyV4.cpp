#include <iostream>

using namespace std;

int main() 
{
    string input;
    cin >> input;

    if(input == "1")
    {
        cout << "0";
        return 0;
    }

    //ZAWSZE OPŁACA SIĘ DOPEŁNIAĆ JEDNOŚCI DO 9 JAK SĄ RÓŻNE OD 0, BO INACZEJ BYSMY MUSIELI TO ZROBIC POZNIEJ
    char lastChar = input.back();
    if(lastChar != '0' && lastChar != '9')
    {
        result += 9 - (lastChar - '0');
        input.back() = '9';
    }
    return 0;
}