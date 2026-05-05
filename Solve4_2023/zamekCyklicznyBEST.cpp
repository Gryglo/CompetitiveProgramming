#include <iostream>
#include <vector>
#define ll unsigned long long

using namespace std;

const int MAXN = 1000100;

pair<char, int> stackedNumber[MAXN];
ll result = 0;
int endIdx = -1;

void addPacket(pair<char, int> packet)
{
    endIdx++;
    stackedNumber[endIdx] = packet;
}

void checkAddingOption()
{
    ll maxDiff = 0;
    ll diff = 9999999;
    ll currNum = 0;
    ll multiplier = 1;
    ll additionalOperations = 1;
    ll addedNum = 0;

    //SPRAWDZAMY 6 OSTATNICH CYFR BO LICZBA PODANA NA WEJSCIU MOZE MIEC MAKSYMALNIE 1000000 CYFR 
    //CO OZNACZA ŻE JAK BEDZIE WIECEJ LICZB NA POCZATKU ROZNYCH OD 9 TO JUZ WIEMY ZE SKOKI BEDA JEDNAK BARDZIEJ OPTYMALNE
    for(int i = 0; i < 7; i++)
    {
        if(endIdx - i < 0)
            return;
        pair<char, int> currPacket = stackedNumber[endIdx - i];
        for(int x = 0; x < currPacket.second; x++)
        {
            if(addedNum >= 7)
            {
                //cout << "NIE OPLACA SIE\n";
                return;
            }

            currNum += (ll)(currPacket.first - '0') * (ll)multiplier;
            multiplier *= 10;
            maxDiff *= 10;
            maxDiff += 9;
            diff = maxDiff - currNum;
            if(currPacket.first != '0')
                additionalOperations += (9 - (currPacket.first - '0')) + 1;   
            addedNum++;
        }

        //JEŻELI INDEX NASTĘPNEGO PAKIETU WYCHODZI POZA TABLICĘ
        if(endIdx - (i + 1) < 0)
            break;
        pair<char, int> nextPacket = stackedNumber[endIdx - (i + 1)];
        //JEŻELI NAPOTKAMY "ŚCIANĘ" 9, KTÓREJ SUMA LICZBY CYFR W TEJ SCIANIE I DODATKOWE OPERACJE DOPEŁNIENIA KAŻDEJ 
        //Z WCZESNIEJSZYCH LICZB DO 9 (W PRZYPADKU SKOKOW), BĘDĄ WIĘKSZE OD RÓŻNICY W PRZYPADKU DODAWANIA, OPŁACA SIĘ DODAWAĆ
        if(nextPacket.first == '9' && nextPacket.second + additionalOperations > diff)
        {
            //cout << "Oplaca sie" << " " << diff << '\n';
            endIdx = endIdx - (i + 1);
            result += diff;
            return;
        }
    }
    //cout << "NIE OPLACA SIE\n";
}

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
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
        result += (ll)(9 - (lastChar - '0'));
        input.back() = '9';
    }

    //POMYSŁ POLEGAJĄCY NA GRUPOWANIU POWTARZAJĄCYCH SIĘ LICZB W JEDEN PAKIET
    //UŁATWIA TO POTEM SPRAWDZANIE ISTNIENIA ZBYT DUZEJ "SCIANY" 9
    addPacket({ input[0], 1 });
    for(long unsigned int i = 1; i < input.size(); i++)
    {
        if(input[i - 1] == input[i])
            stackedNumber[endIdx] = { input[i], stackedNumber[endIdx].second + 1 };
        else
            addPacket({ input[i], 1 });
    }

    //WARUNKI DLA KTORYCH JUZ ZNAMY ODPOWIEDZ
    if(endIdx == 0 && stackedNumber[0].first == '9')
    {
        cout << result + 2;
        return 0;
    }
    else if(endIdx == 1 && stackedNumber[0].first == '1' && stackedNumber[0].second == 1 && stackedNumber[1].first == '0')
    {
        cout << result + 1;
        return 0;
    }

    checkAddingOption();
    
    //PROSTA LOGIKA SKOKOW
    for(int i = 0; i <= endIdx; i++)
    {
    	pair<char, int> currPacket = stackedNumber[i];
    	
        //BY NIE PRZESKOCZYC DODATKOWO TEJ OSTATNIEJ SCIANY CYFR 9
    	if(i == endIdx && currPacket.first == '9')
    		break;
    	
        //USUWANIE ZER WIODACYCH
    	if(currPacket.first == '0')
    		continue;
        //DODAWANIE ODPOWIEDNIEJ ILOSCI OPERACJI DO WYNIKU
    	result += (ll)currPacket.second +  (ll)(9 - (currPacket.first - '0')) * (ll)currPacket.second;
	}
    //PRZY STANIE SAMYCH 9, WYSTARCZY WYKONAC 2 OPERACJE BY UZYSKAC WYNIK
    cout << result + 2;
    return 0;
}