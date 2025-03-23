#include "iostream"
using namespace std;

class Device{
    public:
    int deviceID;
    string deviceName;
    bool status;
    string location;
    Device(int id, string name, string l): deviceID(id), deviceName(name), location(l){
        status = false;
    }
    virtual void turnON(){
        status = true;
        cout<<"ON";
    }
    virtual void turnOFF(){
        status = false;
        cout<<"OFF";
    }
    virtual bool getStatus(){
        return status;
    }
    virtual void displayInfo(){
        cout << "Device ID: " << deviceID << ", Name: " << deviceName << ", Status: " << status << ", Location: " << location << endl;
    }
};
class Light : public Device{
    public:
    string brightnessLevel;
    string colorMode;
    Light(int id, string name, string l, string b, string c): Device(id, name, l),brightnessLevel(b), colorMode(c){}
    void displayInfo(){
        Device::displayInfo();
        cout << ", Brightness Level: " << brightnessLevel << ", Color Mode: " << colorMode << endl;
    }
};
class Thermostat : public Device{
    public:
    float temperature;
    string mode;
    float targetTemperature;
    Thermostat(int id, string name, string l, float t, string m, float tt): Device(id, name, l), temperature(t), mode(m), targetTemperature(tt){}
    bool getStatus(){
        cout<<"Temperature:"<<temperature<<endl;
    }
};
class SecurityCamera : public Device{
    public:
    int resolution;
    bool recordingStatus;
    bool nightVisonEnabled;
    SecurityCamera(int id, string name, string l, int r, bool rs, bool nv): Device(id, name, l), resolution(r), recordingStatus(rs), nightVisonEnabled(nv){}
    void turnON(){
        recordingStatus = true;
        cout<<"Recording ON";
    }
};
class SmartPlug : public Device{
    public:
    float PowerConsumption;
    string timerSetting;
    SmartPlug(int id, string name, string l, float p, string t): Device(id, name, l), PowerConsumption(p), timerSetting(t){}
    void turnOFF(){
        cout << "Power Consumption: " << PowerConsumption << " kWh logged." << endl;
    }
    void displayInfo(){
        Device::displayInfo();
        cout << ", Power Consumption: " << PowerConsumption << ", Timer Setting: " << timerSetting << endl;
    }
};

int main() {
    Light light(101, "Torch Light", "Living Room", "High", "Warm White");
    Thermostat t(102, "Smart Thermostat", "Bedroom", 22.5, "Heating", 24.0);
    SecurityCamera camera(103, "CCTV Camera", "Front Door", 1080, false, true);
    SmartPlug plug(104, "Kitchen Plug", "Kitchen", 1.2, "2 hours");
    light.turnON();
    light.displayInfo();

    t.turnON();
    t.getStatus();

    camera.turnON();
    camera.displayInfo();

    plug.turnON();
    plug.turnOFF();
    plug.displayInfo();

    return 0;
}
