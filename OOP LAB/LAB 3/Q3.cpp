//library

#include <iostream>
#include <string>
using namespace std;

class Library
{
private:
    string booklist[10];
    int count;
    bool borrowedbooks[10];

public:
    Library()
    {
        count = 0;
    }
    void addbook(string name)
    {
        if (count < 10)
        {
            booklist[count] = name;
            borrowedbooks[count] = false;
            count++;
            cout << "Book added successfully.\n";
        }
        else
        {
            cout << "Library is full! Cannot add more books.\n";
        }
    }

    void borrow(string bookname)
    {
        for (int i = 0; i < count; i++)
        {
            if (booklist[i] == bookname) {
                if (!borrowedbooks[i]) {
                    borrowedbooks[i] = true;
                    cout << "Book borrowed: " << bookname << endl;
                    return;
                } else {
                    cout << "Book is already borrowed: " << bookname << endl;
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }
    void returnbook(string name)
    {
        for (int i = 0; i < count; i++)
        {
            if (booklist[i] == name && borrowedbooks[i] == true)
            {
                borrowedbooks[i] = false;
                cout << "Return Successful!\n";
                return;
            }
        }
        cout << "Book not found in Library!\n";
    }
    void displaybooks()
    {
        if (count == 0)
        {
            cout << "No books added in Library!\n";
            return;
        }
        cout << "Available Books: " << endl;
        for (int i = 0; i < count; i++)
        {
            if (!borrowedbooks[i])
            {
                cout << booklist[i] << endl;
            }
        }
    }
};

int main()
{
    Library myLibrary;

    myLibrary.addbook("Naunihal");
    myLibrary.addbook("Red Riding Hood");
    myLibrary.addbook("Charlie and the Chocolate Factory");

    myLibrary.displaybooks();

    myLibrary.borrow("Railway Children");
    myLibrary.borrow("Naunihal");

    myLibrary.displaybooks();

    myLibrary.returnbook("Naunihal");

    myLibrary.displaybooks();
    return 0;
}
