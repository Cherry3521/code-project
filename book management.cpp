#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    // Constructor to initialize the book details
    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
    }

    // Function to display book details
    void displayDetails() const {
        cout << "Book Title: " << title << endl
             << "Author: " << author << endl
             << "Price: " << price << " USD" << endl;
    }

    // Function to update the price of the book
    void updatePrice(float newPrice) {
        price = newPrice;
        cout << "Price updated to: " << price << " USD" << endl;
    }

    // Function to change the book title
    void changeTitle(string newTitle) {
        title = newTitle;
        cout << "Title changed to: " << title << endl;
    }
};

int main() {
    // Create book objects with initial values
    Book book1("C++ Programming", "Bjarne Stroustrup", 50.0);
    Book book2("pride and prejudice", "Jane Austin", 30.0);

    // Display book details
    cout << "Book 1 Details:" << endl;
    book1.displayDetails();
    cout << endl;

    cout << "Book 2 Details:" << endl;
    book2.displayDetails();
    cout << endl;

    // Update price of book1
    cout << "Updating price of Book 1..." << endl;
    book1.updatePrice(55.0);
    cout << endl;

    // Change the title of book2
    cout << "Changing title of Book 2..." << endl;
    book2.changeTitle("The Great Gatsby - New Edition");
    cout << endl;

    // Display updated book details
    cout << "Updated Book 1 Details:" << endl;
    book1.displayDetails();
    cout << endl;

    cout << "Updated Book 2 Details:" << endl;
    book2.displayDetails();
    cout << endl;

    return 0;
}

