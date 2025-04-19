#include <iostream>
using namespace std;

class Shipment{
    protected:
    string trackingNumber;
    double weight;
    public:
    Shipment(string t, double w) : trackingNumber(t), weight(w) {}
    virtual void showDetails() =0;
    virtual void estimateDeliveryTime() =0;
};

class AirFreight: public Shipment{
    public:
    AirFreight(string t, double w): Shipment(t,w){}
    void showDetails(){
        cout<<"AirFreight Tracking number:"<<trackingNumber<<"\nWeight: "<<weight<<"tonnes"<<endl;
    }
    void estimateDeliveryTime() {
        cout<<"Estimating Delivery time for AirFreight "<<trackingNumber<<endl;
    }
};

class GroundShipment: public Shipment{
    public:
    GroundShipment(string t, double w): Shipment(t,w){}
    void showDetails(){
        cout<<"GroundShipment Tracking number:"<<trackingNumber<<"\nWeight: "<<weight<<"kg"<<endl;
    }
    void estimateDeliveryTime() {
        cout<<"Estimating Delivery time for GroundShipment "<<trackingNumber<<endl;
    }
};

int main(){
    AirFreight a1("Pk101", 150);
    AirFreight a2("SA804", 45);
    GroundShipment g("SSL004", 200);
    a1.estimateDeliveryTime(); a2.estimateDeliveryTime(); g.estimateDeliveryTime();
    a1.showDetails(); a2.showDetails(); g.showDetails();
    return 0;
}
