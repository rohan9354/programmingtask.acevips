#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;

    Book(string t, string a) {
        title = t;
        author = a;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string t, a;
        cout << "Enter book title: ";
        getline(cin, t);
        cout << "Enter book author: ";
        getline(cin, a);
        Book newBook(t, a);
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void searchBook() {
        string t;
        cout << "Enter title to search: ";
        getline(cin, t);
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].title == t) {
                cout << "Book Found: " << books[i].title << " by " << books[i].author << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found!\n";
        }
    }

    void showAllBooks() {
        if (books.empty()) {
            cout << "No books in library.\n";
        } else {
            cout << "All Books in Library:\n";
            for (size_t i = 0; i < books.size(); i++) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << "\n";
            }
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book by Title\n";
        cout << "3. Show All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            lib.addBook();
        } else if (choice == 2) {
            lib.searchBook();
        } else if (choice == 3) {
            lib.showAllBooks();
        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
