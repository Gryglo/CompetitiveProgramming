#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcja generuje losową cyfrę (bez zera dla pierwszej pozycji)
char random_digit(bool allow_zero) {
    if (allow_zero) return '0' + (rand() % 10);
    return '1' + (rand() % 9);
}

// Bardziej zaawansowana metoda generująca dużą, losową liczbę (do 10^1000)
string generate_large_number(int length) {
    string result;
    result += random_digit(false);  // Pierwsza cyfra niezerowa

    int zero_sequence_probability = 20; // Szansa na pojawienie się sekwencji zer (w %)
    int zero_sequence_length = 5;       // Maksymalna długość sekwencji zer

    for (int i = 1; i < length; ++i) {
        // Wybierz losowo czy generujemy sekwencję zer czy losową cyfrę
        if ((rand() % 100) < zero_sequence_probability) {
            int num_zeros = rand() % zero_sequence_length + 1; // długość sekwencji zer
            if (i + num_zeros >= length) num_zeros = length - i - 1; // Upewniamy się, że nie przekroczy granicy
            result.append(num_zeros, '0');
            i += num_zeros - 1; // Przeskakujemy dodane zera
        } else {
            result += random_digit(true);  // Losowa cyfra (może być zero)
        }
    }
    return result;
}

int main() {
    srand(time(0));

    cout << generate_large_number(500);

    return 0;
}
