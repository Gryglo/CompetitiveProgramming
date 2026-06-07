#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

// Funkcja obliczająca powierzchnię wycinka od środka do wysokości h
double area(double h, double R) {
    double theta = acos(h / R);
    return (R * R / 2) * (theta - sin(theta));
}

int main() {
    int N;
    double R;
    
    // Wczytanie liczby osób oraz promienia pizzy
    cin >> N >> R;
    
    // Powierzchnia każdego kawałka pizzy
    double sliceArea = (PI * R * R) / N;

    // Tablica przechowująca wyniki
    double heights[N - 1];
    
    // Obliczanie wysokości cięć
    for (int i = 1; i < N; i++) {
        double targetArea = i * sliceArea;
        double low = -R, high = R, mid;
        
        // Binary search, aby znaleźć odpowiednią wysokość
        for (int j = 0; j < 100; j++) {  // Dokładność do 100 iteracji
            mid = (low + high) / 2;
            if (area(mid, R) < targetArea) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        heights[i - 1] = mid;
    }
    
    // Wypisywanie wyników
    cout << fixed << setprecision(15);
    for (int i = N - 2; i >= 0; i--) {
        cout << heights[i] << endl;
    }
    
    return 0;
}