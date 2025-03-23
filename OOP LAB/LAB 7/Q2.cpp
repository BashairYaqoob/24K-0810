#include "iostream"
using namespace std;

class Product{
    public:
    int productID;
    string productName;
    double price;
    int quantity;
    Product(int id, string name, double p, int q): productID(id), productName(name), price(p), quantity(q){}
    virtual void applyDiscount(){
        price *= 0.9; //10% discount
    }
    virtual double TotalPrice(int quantity){
        return price * quantity;
    }
    virtual void displayProductInfo(){
        cout << "\nProduct ID: " << productID << "\nName: " << productName << "\nPrice: Rs" << price << "\nQuantity: " << quantity << endl;
    }
};

class Electronics: public Product{
    public:
    int warrantyPeriod;
    string brand;
    Electronics(int id, string name, double p, int q, int w, string b): Product(id, name, p, q), warrantyPeriod(w), brand(b){}
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout << "\nWarranty Period: " << warrantyPeriod << " years \nBrand: " << brand << endl;
    }
};

class Clothing: public Product{
    public:
    string size;
    string color;
    string fabricMaterial;
    Clothing(int id, string name, double p, int q, string s, string c, string f): Product(id, name, p, q), size(s), color(c), fabricMaterial(f){}
    void applyDiscount()override{
        price *= 0.8;
    }
};

class FoodItem: public Product{
    public:
    string expirationDate;
    int calories;
    FoodItem(int id, string name, double p, int q, string d, int c): Product(id, name, p, q), expirationDate(d), calories(c){}
    double TotalPrice(int quantity)override{
        price = price * quantity;
        if (quantity >= 5) {
            price *= 0.85;
        }
        return price;
    }
};
class Book : public Product{
    public:
    string author;
    string genre;
    Book(int id, string name, double p, int q, string a, string g): Product(id, name, p, q), author(a), genre(g){}
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout << "\nAuthor: " << author << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics laptop(101, "Gaming Laptop", 500.0, 10, 2, "HP");
    Clothing tshirt(102, "Cricket Jersey", 100.0, 50, "L", "Black", "Cotton");
    FoodItem pizza(103, "Tikka Pizza", 10.0, 20, "2025-06-15", 300);
    Book novel(104, "The Alchemist", 15.0, 30, "Paulo Coelho", "Fiction");

    tshirt.applyDiscount();
    laptop.applyDiscount();
    novel.TotalPrice(7);
    
    cout << "\n--- Product Details ---\n";
    laptop.displayProductInfo();
    tshirt.displayProductInfo();
    pizza.TotalPrice(3);
    pizza.displayProductInfo();
    novel.displayProductInfo();
    return 0;
}
