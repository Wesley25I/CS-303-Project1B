#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include "Date.h"

using namespace std;

// Represents an employee who may borrow books
struct Employee {
    string name;
    int waiting_time = 0;
    int retaining_time = 0;

    Employee() = default;
    Employee(string name) : name(name) {}
};

// Represents a book in the library
struct Book {
    string name;
    Date circulation_start;
    Date last_pass_date;
    bool archived;
    queue<string> employee_queue;

    Book();
    Book(string name, Date start);
};

// Manages books and employees in the library system
class Library {
private:
    unordered_map<string, Book> books;
    unordered_map<string, Employee> employees;

public:
    void add_book(string book_name);
    void add_employee(string employee_name);
    void circulate_book(string book_name, Date start_date);
    void pass_on(string book_name, Date pass_date);
};

#endif
