#include "iostream"
using namespace std;

class Device{
    public:
    int deviceID;
    string deviceName;
    bool status;
    string location;
    Device(int id, string name, string l): deviceID(id), deviceName(name), location(l){
        status = (getStatus()? "ON" : "OFF");
    }
    virtual void turnON(){
        status = true;
        cout<<;
    }
    void turnOFF(){
        status = false;
        return status;
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
    bool turnON(){

    }
};
