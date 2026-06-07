#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() 
{
    string a;
    cin>>a;
    sort(a.begin(),a.end());
    long long o=0;
    for(int z=0;z<a.size();z++)
    {
        if(a[z]=='0')
        {
            o++;
        }
        else
        {
            break;
        }
    }

    if(o>0)
    {
       
       string temp = a.substr(0, o);  
       a.erase(0, o);
       char pierwszy=a[0];
       a.erase(0, 1);
       string result = pierwszy+temp+a;
       cout<<result;
       return 0;
    }
    cout<<a;

        return 0;
}
