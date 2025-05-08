#include "Library.h"
#include <iostream>
#include <algorithm>


using namespace std;
// Default constructor initializes book details
Book::Book() : name(""), circulation_start(0, 0, 0), last_pass_date(0, 0, 0), archived(false) {}


Book::Book(string name, Date start)
    : name(name), circulation_start(start), last_pass_date(start), archived(false) {}

void Library::add_book(string book_name) {
    books[book_name] = Book(book_name, Date(0, 0, 0));
}

void Library::add_employee(string employee_name) {
    employees[employee_name] = Employee(employee_name);
}

void Library::circulate_book(string book_name, Date start_date) {
    if (books.find(book_name) == books.end()) return;

    Book& book = books[book_name];
    book.circulation_start = start_date;
    book.last_pass_date = start_date;

    // Build initial employee queue sorted by priority = waiting - retaining time
    vector<pair<int, string>> priority_list;
    for (auto& [name, emp] : employees) {
        int priority = emp.waiting_time - emp.retaining_time;
        priority_list.emplace_back(-priority, name);  // -priority for max-heap-like behavior
    }
    // Sort the priority list of books before archiving
    sort(priority_list.begin(), priority_list.end());
    for (auto& [_, name] : priority_list) {
        book.employee_queue.push(name);
    }
}

void Library::pass_on(string book_name, Date pass_date) {
    if (books.find(book_name) == books.end()) return;
    Book& book = books[book_name];
    if (book.employee_queue.empty()) return;

    string current = book.employee_queue.front();
    book.employee_queue.pop();

    int days_retained = pass_date - book.last_pass_date;
    employees[current].retaining_time += days_retained;

    if (!book.employee_queue.empty()) {
        string next = book.employee_queue.front();
        employees[next].waiting_time += pass_date - book.circulation_start;
        book.last_pass_date = pass_date;
    } else {
        book.archived = true;
        book.last_pass_date = pass_date;
        cout << "Book \"" << book.name << "\" has been archived on " << pass_date.to_string() << ".\n";
    }
}
