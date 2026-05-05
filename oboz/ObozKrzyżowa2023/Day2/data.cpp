#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

struct TimeDifference {
    int days;
    int hours;
    int minutes;
    int seconds;
};

TimeDifference calculateTimeDifference(const string& startTime, const string& endTime) {
    struct tm startTm = {}, endTm = {};
    stringstream startStream(startTime), endStream(endTime);

    startStream >> get_time(&startTm, "%Y-%m-%d %H:%M:%S");
    endStream >> get_time(&endTm, "%Y-%m-%d %H:%M:%S");

    time_t start = mktime(&startTm);
    time_t end = mktime(&endTm);

    int difference = static_cast<int>(difftime(end, start));

    TimeDifference timeDiff;
    timeDiff.days = difference / (24 * 3600);
    timeDiff.hours = (difference % (24 * 3600)) / 3600;
    timeDiff.minutes = (difference % 3600) / 60;
    timeDiff.seconds = difference % 60;

    return timeDiff;
}

int main() {
    string startTime, endTime;
    int subtask;

    getline(cin, startTime);
    getline(cin, endTime);
    cin >> subtask;

    TimeDifference timeDiff = calculateTimeDifference(startTime, endTime);
    switch (subtask) {
        case 1:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        case 2:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        case 3:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        case 4:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        case 5:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        case 6:
            cout << timeDiff.days << " dni " << timeDiff.hours << " godzin " << timeDiff.minutes << " minut " << timeDiff.seconds << " sekunda";
            break;
        default:
            cerr << "Nieprawidłowy numer podzadania" << endl;
            return 1;
    }

    return 0;
}
