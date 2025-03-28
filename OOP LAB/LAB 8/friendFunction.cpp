#include "iostream"
using namespace std;

class Book{
    private:
    string title;
    double price;
    public:
    Book(string t, double p): title(t), price(p){}

    friend class Librarian;
};

class Librarian{
    public:
    void displayBookDetails(const Book& book){
        cout << "Title: " << book.title << ", Price: $" << book.price << endl;
    }
    void discount(Book& book, double amount){
        book.price -= amount;
        cout << "Discounted price: $" << book.price << endl;
    }
};

int main(){
    Book b("C++ Programming", 49.99);
    Librarian l;
    l.displayBookDetails(b);
    l.discount(b, 10.00);
    return 0;
}
