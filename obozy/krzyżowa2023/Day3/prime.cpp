// C++ program to find the
// prime numbers between a
// given interval
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int a, b, i, j, flag;
	a = 0;
    b = 1'000'000;

	// Print display message

	// Traverse each number in the interval
	// with the help of for loop
	for (i = a; i <= b; i++) {
		// Skip 0 and 1 as they are
		// neither prime nor composite
		if (i == 1 || i == 0)
			continue;

		// flag variable to tell
		// if i is prime or not
		flag = 1;

		for (j = 2; j <= i / 2; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}

		// flag = 1 means i is prime
		// and flag = 0 means i is not prime
	    if (flag == 1)
			cout << "1, ";
        else
            cout << "0, ";
	}

	return 0;
}
