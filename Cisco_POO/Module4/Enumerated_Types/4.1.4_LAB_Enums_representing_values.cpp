#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Calendar {
public:
    Calendar(int day, int month, int year) : day(day), month(month), year(year) {
        if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
            throw invalid_argument("invalid date.");
        if (year < 1970)
            throw invalid_argument("the date is earlier than 1st January 1970.");
    }

    void print() const {
        // enums para representar meses y dias, combinados con tablas de strings
        enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
                     AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
        enum Weekday { THURSDAY, FRIDAY, SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY };

        const string monthNames[] = { "january", "february", "march", "april", "may", "june", "july",
                                      "august", "september", "october", "november", "december" };
        const string dayNames[] = { "Thursday", "Friday", "Saturday", "Sunday",
                                    "Monday", "Tuesday", "Wednesday" };

        int days = daysSince1970();
        Month m = Month(month - 1);
        Weekday w = Weekday(days % 7);     // 1 de enero de 1970 fue jueves (0)

        cout << day << " " << monthNames[m] << " " << year << " - "
             << dayNames[w] << " - " << days << " days since 1st January 1970" << endl;
    }

private:
    int day, month, year;

    static bool isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    static int daysInMonth(int m, int y) {
        const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (m == 2 && isLeap(y)) ? 29 : days[m - 1];
    }

    int daysSince1970() const {
        int total = 0;
        for (int y = 1970; y < year; y++)
            total += isLeap(y) ? 366 : 365;
        for (int m = 1; m < month; m++)
            total += daysInMonth(m, year);
        return total + day - 1;
    }
};

int main(void) {
    int day, month, year;
    cin >> day >> month >> year;
    try {
        Calendar date(day, month, year);
        date.print();
    }
    catch (invalid_argument &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
