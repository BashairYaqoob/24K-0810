#include <iostream>
#include <string>
using namespace std;

class Car {
    string brand;
    string model;
    float rentalPrice;
    int days;
    bool availabilityStatus;

public:
    // Parameterized constructor
    Car(string b, string m, float r, int d, bool avail) 
        : brand(b), model(m), rentalPrice(r), days(d), availabilityStatus(avail) {}

    // Copy constructor
    Car(const Car &obj) {
        brand = obj.brand;
        model = obj.model;
        rentalPrice = obj.rentalPrice;
        days = obj.days;
        availabilityStatus = obj.availabilityStatus;
        cout << "Copy Constructor: A copy of the car has been created.\n";
    }

    // Destructor
    ~Car() {
        cout << "Destructor: Car object (" << brand << " " << model << ") is being deleted.\n";
    }

    // Check availability
    bool isAvailable() {
        return availabilityStatus;
    }

    // Rent a car
    void rent() {
        if (availabilityStatus) {
            applyDiscount();
            availabilityStatus = false;
            cout << "Car is Rented. Final Rental Price: $" << rentalPrice << endl;
        } else {
            cout << "Car not Available!\n";
        }
    }

    // Apply discount based on rental days
    void applyDiscount() {
        if (days > 5 && days <= 10) {
            rentalPrice *= 0.95;  // 5% discount
        } else if (days > 10) {
            rentalPrice *= 0.90;  // 10% discount
        }
    }

    // Update car details
    void update(string newBrand, string newModel, float newRentalPrice, int newDays) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newRentalPrice;
        days = newDays;
    }

    // Display car details
    void display() {
        cout << "Car: " << brand << " " << model 
             << " | Rental Price: $" << rentalPrice 
             << " | Days: " << days 
             << " | Available: " << (availabilityStatus ? "Yes" : "No") << endl;
    }
};

int main() {
    // Create a car object
    Car c1("Toyota", "Corolla", 500.5, 7, true);
    cout << "Original Car:\n";
    c1.display();

    // Create a copy using the copy constructor
    Car c2(c1);
    cout << "\nCopied Car:\n";
    c2.display();

    // Modify the original car
    c1.update("Toyota", "Corolla 12", 600.0, 10);
    cout << "\nAfter modifying the original car:\n";
    c1.display();
    c2.display(); // The copied car should remain unchanged

    // Rent the copied car
    cout << "\nRenting the copied car:\n";
    c2.rent();

    return 0;
}
