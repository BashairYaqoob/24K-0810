//FUEL REFILL

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(string b, string m, double fc)
    {
        brand = b;
        model = m;
        fuelCapacity = fc;
        currentFuelLevel = fc;
    }
    void cardriven(double fuelused)
    {
        if (currentFuelLevel >= fuelused)
        {
            currentFuelLevel -= fuelused;
        }
        else
        {
            cout << "Not enough fuel to drive. Bharwalo Bhikari.\n";
        }
    }
    void refuel(double refueled)
    {
        if (refueled > 0 && (refueled + currentFuelLevel) <= fuelCapacity)
        {
            currentFuelLevel += refueled;
        }
        else
        {
            cout << "Cannot refuel beyond tank capacity!\n";
        }
    }
    void fuelStatus()
    {
        cout << "Current fuel Level: " << currentFuelLevel << endl;
        if (currentFuelLevel < (0.15 * fuelCapacity)) {
            cout << "Warning! FUEL BHARWAOOO.\n";
        }
    }
};

int main()
{
    Car zoya("Toyota", "Corolla", 50);
    zoya.cardriven(10);
    zoya.cardriven(40);
    zoya.refuel(2);
    zoya.fuelStatus();
    return 0;
}
