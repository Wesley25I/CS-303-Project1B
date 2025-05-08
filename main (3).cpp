#include "Library.h"
#include <iostream>

using namespace std;

int main() {
    Library library;
  
  // Create book objects with their names and circulation start dates
    library.add_book("Data Structures");
    library.add_book("Operating Systems");

    library.add_employee("Alice");
    library.add_employee("Bob");
    library.add_employee("Charlie");

    library.circulate_book("Data Structures", Date(2025, 1, 10, DateFormat::US));
    library.circulate_book("Operating Systems", Date(2025, 2, 1, DateFormat::US));

    library.pass_on("Data Structures", Date(2025, 1, 15, DateFormat::US));
    library.pass_on("Data Structures", Date(2025, 1, 20, DateFormat::US));
    library.pass_on("Data Structures", Date(2025, 1, 30, DateFormat::US));

    library.pass_on("Operating Systems", Date(2025, 2, 5, DateFormat::US));
    library.pass_on("Operating Systems", Date(2025, 2, 12, DateFormat::US));
    library.pass_on("Operating Systems", Date(2025, 2, 25, DateFormat::US));

    return 0;
}
