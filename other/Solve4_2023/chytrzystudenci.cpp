#include <iostream>
using namespace std;

long long profit(long long n) {
    long long result = 0;
    long long max_result=0;
    if (n & 1) {
        max_result = n+1;
    }
    
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (n & 1) {
                
                result +=d;
            }
            long long d2 = n / d;
            if (n & 1) {
                result +=d2;
            }
            max_result=max(max_result,result);
            result=0;
        }
    }
    return max_result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long w;
        cin >> w;
        cout << profit(w) << " ";
    }

    return 0;
}