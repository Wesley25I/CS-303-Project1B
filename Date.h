#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

enum class DateFormat { US };

class Date {
public:
    int year, month, day;
    Date(int year, int month, int day, DateFormat format = DateFormat::US);

    int operator-(const Date& other) const;
    string to_string() const;
};

#endif
