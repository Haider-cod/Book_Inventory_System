#include <iostream>
using namespace std;

const int Maxbooks = 30;

class book {
private:
    string author, title, publisher;
    double price;
    int stock;

public:
	//assinging all data member to zero.
    book() : price(0), stock(0), title(""), author(""), publisher("") {}
    
    //Inialize constuctor through parameter.
    book(const string& art, const string& tit, const string& pub, double pr, int st) {
        author = art;
        title = tit;
        publisher = pub;
        price = pr;
        stock = st;
    }
   //declaring functions
    void get_values();
    void show_values();
    bool search_book(const string& tit, const string& art);
    void copies(int n);
};
//Input from user
void book::get_values() {
    cin.ignore();
    cout << "Enter Book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter publisher name: ";
    getline(cin, publisher);
    cout << "Enter price of book: ";
    cin >> price;
    cout << "Enter stock position: ";
    cin >> stock;
    cout << endl;
}
//Show the data
void book::show_values() {
    cout << "Title of Book: " << title << endl;
    cout << "Author of Book: " << author << endl;
    cout << "Publisher of Book: " << publisher << endl;
    cout << "Price of Book: " << price << endl;
    cout << "Stock Position of Book: " << stock << endl << "\n";
}
//for serching book
bool book::search_book(const string& tit, const string& art) {
    return (title == tit && author == art);
}

//for stock position
void book::copies(int n) {
    if (stock >= n) {
        cout << "Book is available." << endl;
        cout << "Cost of " << n << " book(s) is " << (price * n) << " Rs.\n" << endl;
    } else {
        cout << "Required copies not in stock.\n" << endl;
    }
}

int main() {
    const int ShowInventory = 1;
    const int InsertBook = 2;
    const int DisplayBook = 3;
    const int SearchBook = 4;
    const int ExitProgram = 5;

    book books[Maxbooks];
    int bookCount = 4;
    string author, title;
    //Book inventory
    books[0] = book("Jon", "English", "Alifkhana", 150, 15);
    books[1] = book("Arfa", "OOP", "IT series", 355, 10);
    books[2] = book("F. Saqib", "Linear Algebra", "Scribner", 140, 10);
    books[3] = book("Harry", "Accounting", "Royalbooks", 385, 8);

    int choice, numBooks, k = 0, copy;

    do {
        cout << "1. Show book Inventory" << endl;
        cout << "2. Insert book details" << endl;
        cout << "3. Display book" << endl;
        cout << "4. Search book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case ShowInventory:
                for (int i = 0; i < bookCount; i++) {
                    books[i].show_values();
                }
                break;

            case InsertBook:
                cout << "How many books do you want to enter? ";
                cin >> numBooks;
                for (int i = 0; i < numBooks; i++) {
                    if (bookCount < Maxbooks) {
                        books[bookCount].get_values();
                        bookCount++;
                    } else {
                        cout << "Maximum number of books reached." << endl;
                        break;
                    }
                }
                break;

            case DisplayBook:
                cout << "\nDisplaying book data:\n";
                for (int i = 0; i < bookCount; i++) {
                    books[i].show_values();
                }
                break;

            case SearchBook:
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter the author of the book: ";
                getline(cin, author);
                cout<<endl;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].search_book(title, author)) {
                        books[i].show_values();
                        k = i;
                        break;
                    }
                }

                if (k != 0) {
                    cout << "Book is available." << endl;
                    cout << "Enter the required number of copies: ";
                    cin >> copy;
                    books[k].copies(copy);
                } else {
                    cout << "Book is not available.\n" << endl;
                }
                break;

            case ExitProgram:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Wrong choice. Please try again." << endl;
                break;
        }
    } while (choice != ExitProgram);

    return 0;
}

