#include <iostream>
using namespace std;

class WeatherSensor{
    public:
    WeatherSensor(){}
    virtual void readData() =0;
    virtual void displayReport() =0;
};

class Thermometer: public WeatherSensor{
    public:
    Thermometer(){}
    void readData(){
        cout<<"Reading Temperature.."<<endl;
    }
    void displayReport() {
        cout<<"Displaying report of temperature.."<<endl;
    }
};

class Barometer: public WeatherSensor{
    public:
    Barometer(){}
    void readData(){
        cout<<"Reading Pressure.."<<endl;
    }
    void displayReport() {
        cout<<"Displaying report of pressure.."<<endl;
    }
};

int main(){
    Thermometer t;
    Barometer b;
    t.readData(); b.readData();
    t.displayReport(); b.displayReport();
    
    return 0;
}
