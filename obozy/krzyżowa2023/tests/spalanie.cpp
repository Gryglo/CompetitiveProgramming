#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PRZELICZNIK = 235.21;

    double input;
	cin >> input;

	string value;
	cin >> value;

	double result = PRZELICZNIK / input;
	result = round(result * 100.0) / 100.0;

	if(value == "l/100km")
		cout << result << " mpg";
	else if(value == "mpg")
		cout << result << " l/100km";

	return 0;
}