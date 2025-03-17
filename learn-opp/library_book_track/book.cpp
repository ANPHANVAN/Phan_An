#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    private:
        // title, author, ISBN, and availability isAvailable
        string title;
        string author;
        string ISBN;
        bool isAvailable = true; // true is availerble

    public:
        Book(string title,string author, string ISBN){
            this->title = title;
            this->author = author;
            this->ISBN = ISBN;
        };

        string get_title(){return title;};
        string get_author(){return author;};
        string get_ISBN(){return ISBN;};
        bool get_isAvailable(){return isAvailable;};
        void set_isAvailable(bool isAvailable){ this->isAvailable = isAvailable;};

        friend class Library;
};

class Library {
    private: 
        vector <Book> books;

    public:
        Library(){
            cout << "create a library" << endl;
        };

        void addBook(string title, string author, string ISBN) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].get_ISBN() == ISBN) {
                    cout << "A book with ISBN " << ISBN << " already exists!\n";
                    return;
                }
            }
            books.emplace_back(title, author, ISBN);
            cout << "Add book succeeded\n";
        }

        void displayAllbook() {
            if (books.empty()) {
                cout << "No books in the library.\n";
                return;
            }
            cout << "Library Books:\n";
            for (int i = 0; i < books.size(); i++) {
                cout << "Title: " << books[i].get_title()
                    << " | Author: " << books[i].get_author()
                    << " | ISBN: " << books[i].get_ISBN()
                    << " | isAvailable: " << (books[i].get_isAvailable() ? "Available" : "Checked Out") << "\n";
            }
        }

        void checkOut(string ISBN){
            for (int  i = 0; i < books.size(); i++)
            {
                if (books[i].get_ISBN()==ISBN)
                {
                    if (books[i].get_isAvailable())
                    {
                        books[i].set_isAvailable(false);
                        cout << "you just borrow a book with title: " <<books[i].get_title() << endl;
                        return;
                    }
                    else {
                        cout << "this book borrowed by another person" << endl;
                        return;
                    }
                }
            }
            cout << "dont have this book in library" <<endl;
            return;
        }

        void returnBook(string ISBN) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].get_ISBN() == ISBN) {
                    if (!books[i].get_isAvailable()) {
                        books[i].set_isAvailable(true);
                        cout << "You just returned a book with title: " << books[i].get_title() << endl;
                    } else {
                        cout << "Book with ISBN " << ISBN << " is already available.\n";
                    }
                    return;
                }
            }
            cout << "Book with ISBN " << ISBN << " not found.\n";
        }
        
        void findBook(string ISBN){
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].get_ISBN()==ISBN)
                {
                    cout << "found book: "<<endl;
                    cout << "title: " << books[i].get_title();
                    cout << " | author: " << books[i].get_author();
                    cout << " | ISBN: " << books[i].get_ISBN();
                    cout << " | isAvailable: " << (books[i].get_isAvailable() ? "Available" : "Checked Out") << "\n";
                    cout << endl;
                    return;
                }
            };
            cout << "dont found this book"<<endl;
        }
};

int main (){
    Library libraries;

    libraries.addBook("title2","author2","9841");
    libraries.addBook("title3","author3","9842");
    libraries.addBook("title4","author4","9843");
    libraries.addBook("title5","author5","9844");

    libraries.displayAllbook();

    libraries.findBook("9843");
    libraries.checkOut("9843");

    libraries.displayAllbook();

    libraries.returnBook("9843");
    libraries.displayAllbook();
}