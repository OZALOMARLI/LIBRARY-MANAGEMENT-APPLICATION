#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string category;

    Book(string t, string c) : title(t), category(c) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& category) {
        books.push_back(Book(title, category));
        cout << "Book added: " << title << " - " << category << endl;
    }

    void searchBook(const string& title) {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found: " << book.title << " - Category: " << book.category << endl;
                return;
            }
        }
        cout << "No matching results for your search." << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "There are no books in the library." << endl;
            return;
        }
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            cout << book.title << " - " << book.category << endl;
        }
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nWelcome to the Library!" << endl;
        cout << "1. Reader" << endl;
        cout << "2. Management Team" << endl;
        cout << "3. Exit" << endl;
        cout << "Please make a choice (1, 2, or 3): ";
        cin >> choice;

        if (choice == 1) {
            // Reader
            string bookTitle;
            cout << "Enter the title of the book you want to search for: ";
            cin.ignore(); // Clear the newline left in the input buffer
            getline(cin, bookTitle);
            library.searchBook(bookTitle);
        } else if (choice == 2) {
            // Management Team
            string bookTitle, category;

            cout << "Enter the title of the book you want to add: ";
            cin.ignore(); // Clear the newline left in the input buffer
            getline(cin, bookTitle);
            
            cout << "Enter the book category (Children, Historical, Religious, Textbook): ";
            getline(cin, category);
            
            library.addBook(bookTitle, category);
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break; // Exit the program
        } else {
            cout << "Invalid choice!" << endl;
        }

        // Display all books
        library.displayBooks();
    }

    return 0;
}