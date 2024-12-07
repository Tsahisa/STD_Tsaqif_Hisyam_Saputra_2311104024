#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string returnDate;
    Book* next;
};

struct Member {
    string name;
    string id;
    Book* bookHead;
    Member* next;
};

class LibraryManager {
private:
    Member* head;

public:
    LibraryManager() : head(nullptr) {}

    void addMember(const string& name, const string& id) {
        Member* newMember = new Member{name, id, nullptr, head};
        head = newMember;
    }

    void addBookToMember(const string& memberId, const string& title, const string& returnDate) {
        Member* member = findMember(memberId);
        if (member) {
            Book* newBook = new Book{title, returnDate, member->bookHead};
            member->bookHead = newBook;
        } else {
            cout << "Member with ID " << memberId << " not found.\n";
        }
    }

    void removeMember(const string& memberId) {
        Member* prev = nullptr;
        Member* current = head;
        while (current) {
            if (current->id == memberId) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                Book* book = current->bookHead;
                while (book) {
                    Book* temp = book;
                    book = book->next;
                    delete temp;
                }

                delete current;
                cout << "Member with ID " << memberId << " and their books removed.\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Member with ID " << memberId << " not found.\n";
    }

    void clearBooks(Book* bookHead) {
    while (bookHead) {
        Book* temp = bookHead;
        bookHead = bookHead->next;
        delete temp;
    }
}


    void displayAll() {
        Member* member = head;
        while (member) {
            cout << "Member Name: " << member->name << ", ID: " << member->id << "\n";
            Book* book = member->bookHead;
            if (book) {
                cout << "  Borrowed Books:\n";
                while (book) {
                    cout << "    - " << book->title << " (Return Date: " << book->returnDate << ")\n";
                    book = book->next;
                }
            } else {
                cout << "  No borrowed books.\n";
            }
            member = member->next;
        }
    }

private:
    Member* findMember(const string& id) {
        Member* current = head;
        while (current) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() {
    LibraryManager library;

    // Adding members
    library.addMember("Rani", "A001");
    library.addMember("Dito", "A002");
    library.addMember("Vina", "A003");

    // Adding borrowed books
    library.addBookToMember("A001", "Pemrograman C++", "01/12/2024");
    library.addBookToMember("A002", "Algoritma Pemrograman", "15/12/2024");

    // Adding a new book to Rani
    library.addBookToMember("A001", "Struktur Data", "10/12/2024");

    // Removing member Dito and their books
    library.removeMember("A002");

    // Display all members and their borrowed books
    library.displayAll();

    return 0;
}
