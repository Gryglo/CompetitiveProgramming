#include <iostream>

struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Funkcja do obliczania różnicy czasu
void calculateTimeDifference(const DateTime& start, const DateTime& end, DateTime& difference) {
    // Konwertuj daty na sekundy
    time_t startTime = mktime(&tm{start.second, start.minute, start.hour, start.day, start.month - 1, start.year - 1900, 0, 0, 0});
    time_t endTime = mktime(&tm{end.second, end.minute, end.hour, end.day, end.month - 1, end.year - 1900, 0, 0, 0});

    // Oblicz różnicę w sekundach
    time_t timeDiff = endTime - startTime;

    // Konwertuj różnicę z powrotem na strukturę DateTime
    difference.second = timeDiff % 60;
    timeDiff /= 60;
    difference.minute = timeDiff % 60;
    timeDiff /= 60;
    difference.hour = timeDiff % 24;
    timeDiff /= 24;
    difference.day = timeDiff;
}

int main() {
    DateTime start, end, difference;

    // Wczytaj dane wejściowe
    std::cout << "Podaj datę początkową (YYYY MM DD HH MM SS): ";
    std::cin >> start.year >> start.month >> start.day >> start.hour >> start.minute >> start.second;

    std::cout << "Podaj datę końcową (YYYY MM DD HH MM SS): ";
    std::cin >> end.year >> end.month >> end.day >> end.hour >> end.minute >> end.second;

    // Oblicz różnicę czasu
    calculateTimeDifference(start, end, difference);

    // Wyświetl wynik
    std::cout << "Różnica czasu: " << difference.day << " dni " << difference.hour << " godzin " << difference.minute << " minut " << difference.second << " sekund\n";

    return 0;
}
