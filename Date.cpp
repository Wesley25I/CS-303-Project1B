#include "Date.h"
#include <sstream>

using namespace std;

Date::Date(int y, int m, int d, DateFormat format) : year(y), month(m), day(d) {}

int Date::operator-(const Date& other) const {
    // Simplified: assumes 30 days/month for this context.
    return (year - other.year) * 360 + (month - other.month) * 30 + (day - other.day);
}

string Date::to_string() const {
    ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}
