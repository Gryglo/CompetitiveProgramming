#include <bits/stdc++.h>
#include "ckollib.c"
//#include "ckollib.h"
using namespace std;

const int BASE = 45000;
int res_num_bits[2][BASE];

void xor_with_res(int x)
{
    int bit = 0;
    while(x > 0)
    {
        int mod = x % BASE;
        res_num_bits[bit][mod]++;
        x /= BASE;
        bit++;
    }
}

int pick_card()
{
    int card = karta();
    if(card != 0)
        xor_with_res(card);
    return card;
}

int find_bit(int bit_idx, int mod)
{
    int resBit = 0;
    for(int i = 0; i < BASE; i++)
    {
        if((res_num_bits[bit_idx][i] % mod) != 0)
        {
            resBit = i;
            break;
        }
    }
    return resBit;
}

int main()
{    
    //zakładam ze w tali jest przynajmniej jedna karta
    int fCard = pick_card();
    int fCardCnt = 1;
    int sCard = pick_card();
    int sCardCnt = 1;
    while(fCard == sCard)
    {
        fCardCnt++;
        sCard = pick_card();
    }

    //szczegolny przypadek
    if(sCard == 0)
    {
        odpowiedz(fCard);
        return 0;
    }

    int curr = pick_card();
    while(curr != 0)
    {
        if(curr == fCard)
            fCardCnt++;
        else if(curr == sCard)
            sCardCnt++;
        curr = pick_card();
    }

    if(fCardCnt < sCardCnt)
        odpowiedz(fCard);
    else if(sCardCnt > fCardCnt)
        odpowiedz(sCard);
    else
    {
        int fBit = find_bit(0, fCardCnt);
        int sBit = find_bit(1, fCardCnt);
        int ans = fBit + sBit * BASE;
        odpowiedz(ans);
    }
    return 0;
}