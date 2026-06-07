#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() 
{
    long long N;
    cin >> N;
    vector<long long> a(N);
    
    for (long long i = 0; i < N; i++) 
    {
        cin >> a[i];
    }

    vector<long long> left(N), right(N);
    stack<long long> s;

    for (long long i = 0; i < N; i++) 
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (long long i = N - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();
        right[i] = s.empty() ? N : s.top();
        s.push(i);
    }

    double expected_value = 0.0;

    for (long long i = 0; i < N; i++) 
    {
        long long left_count = i - left[i];  
        long long right_count = right[i] - i;  
        expected_value += (double)a[i] * left_count * right_count;
    }

    expected_value /= (N * (N + 1)) / 2.0;
    printf("%.6f\n", expected_value);

    return 0;
}
