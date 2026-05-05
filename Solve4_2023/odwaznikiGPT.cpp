#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

// Rozszerzony algorytm Euklidesa
tuple<int, int, int> extended_gcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [gcd, x1, y1] = extended_gcd(b, a % b);
    return {gcd, y1, x1 - (a / b) * y1};
}

int main() {
    int A, B, N;
    cin >> A >> B >> N;

    // Znajdujemy gcd(A, B) oraz jedno rozwiązanie równania diofantycznego
    auto [g, x0, y0] = extended_gcd(A, B);

    // Sprawdzamy czy gcd(A, B) dzieli N
    if (N % g != 0) {
        cout << "NIE" << endl;
        return 0;
    }

    // Przeskalowanie rozwiązania dla równania A*x + B*y = N
    int k = N / g;
    x0 *= k;
    y0 *= k;

    // Bierzemy A/g oraz B/g
    int A_g = A / g;
    int B_g = B / g;

    // Znajdźmy t, które minimalizuje |x| + |y|
    // Zasadniczo, musimy rozwiązać t tak, by wartość x0 + t * (B/g) i y0 - t * (A/g) dawała minimalną liczbę odważników
    // Wykorzystamy do tego dzielenie całkowite


    int t_min = (int) ceil(-1.0 * x0 / B_g);
    int t_max = (int) floor(1.0 * y0 / A_g);

    int best_t = t_min;
    int best_result = abs(x0 + t_min * B_g) + abs(y0 - t_min * A_g);

    for (int t = t_min; t <= t_max; ++t) {
        int x = x0 + t * B_g;
        int y = y0 - t * A_g;
        int current_result = abs(x) + abs(y);
        if (current_result < best_result) {
            best_result = current_result;
            best_t = t;
        }
    }

    // Wypisanie minimalnej liczby odważników
    int x = x0 + best_t * B_g;
    int y = y0 - best_t * A_g;

    cout << abs(x) + abs(y) << endl;

    return 0;
}
