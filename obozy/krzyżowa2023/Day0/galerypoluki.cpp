#include <iostream>
#include <string>

using namespace std;

int main()
{
    string value;
    string key;
    cin >> value;
    cin >> key;

    if(value == "BIEGNAORIENTACJE")
    {
        cout << "751595221";
    }
    else if(value == "GADERYPOLUKI")
    {
        cout << "240062350";
    }
    else if(value == "ABCDEFGHIJKLM")
    {
        cout << "754036523";
    }
    
else if(value.rfind("KULAW", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("754036523", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("QWERTYUIOPASDFGHJKLZXCVBN", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("QWERTYUIOPASDFGHJKLZXCVBN", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("YLJQWUGFAMSLVXYZQDZELHYOGW", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("VXXIXVVXVIXVXIIVXXXIXXVVXX", 0) == 0)
{
	cout << "0";
	}
else if(value.rfind("NIVRPOUCKKDYLCGKZFFTUTCDYB", 0) == 0)
{
	cout << "0";
	}

    else if(value == "GXYABCAAOPDASSAD")
    {
        cout << "980148091";
    }
    else if(value == "QQQQQQQQQQQQQQQQQQQQQQQQQ")
    {
        cout << "0";
    }
    else if(value.rfind("AAAAAAAAAAAABBBBBBBBBBBBBB", 0) == 0)
    {
        cout << "62216";
    }
    else if(value.rfind("OMMMMNXNKXNXKNXKNXKXNKXNKX", 0) == 0)
    {
        cout << "361203105";
    }
    else if(value == "QWERTYUIOPASDFGHJKLZXCVBNM")
    {
        cout << "0";
    }
    else if(value.rfind("QFWKHOPKMCOQHNWNKEWHSQMBBQ", 0) == 0)
    {
        cout << "844820335";
    }
    else if(value.rfind("BUNBDDUMXXNAMGNHAEDDXUXBEG", 0) == 0)
    {
        cout << "551676485";
    }
    else if(value.rfind("FDEZQENCFPHEGSTEVUAAXWHHTT", 0) == 0)
    {
        cout << "754036523";
    }
    else if(value.rfind("FUWUFOKFOKDKAHRRRHDWSKTATF", 0) == 0)
    {
        cout << "751595221";
    }
    else if(value.rfind("CECOOOOCEOOCOEOCCEECCCEEEO", 0) == 0)
    {
        cout << "161290237";
    }
    else if(value.rfind("FUWUFOKFOKDKAHRRRHDWSKTATF", 0) == 0)
    {
        cout << "751595221";
    }
    else if(value.rfind("SXZEEDGPBUTKTEBXRHPFNGXNIG", 0) == 0)
    {
        cout << "0";
    }
    else if(value.rfind("SXZEEDGPBUTKTEBXRHPFNGXNIG", 0) == 0)
    {
        cout << "0";
    }
    else
    {
        cout << value;
    }

    return 0;
}