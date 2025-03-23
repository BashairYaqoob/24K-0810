#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    string contactNumber;
    string address;
    Person(string n, int a, string c, string ad):name(n), age(a), contactNumber(c), address(ad){}
    virtual void displayInfo(){
        cout<<"\nName: "<<name<<"\nAge: "<<age<<"\nContact Number: "<<contactNumber<<"\nAddress: "<<address<<endl;
    }
    virtual void updateInfo(string c, string ad){
        cout<<"\n Information Updated! "<<endl;
    }
};

class Patient: public Person{
    public:
    int patientID;
    string medicalHistory;
    string doctorAssigned;
    Patient(string n, int a, string c, string ad, int id, string mh, string d): Person(n, a, c, ad), patientID(id), medicalHistory(mh), doctorAssigned(d){}
    void displayInfo()override{
        Person::displayInfo();
        cout<<"\nPatient ID: "<<patientID<<"\nMedical History: "<<medicalHistory<<"\nDoctor Assigned: "<<doctorAssigned<<endl;
    }
};

class Doctor: public Person{
    public:
    string specialization;
    double consultationFee;
    string PatientList[10];
    int patientcount;
    Doctor(string n, int a, string c, string ad, string s, double cf): Person(n, a, c, ad), specialization(s), consultationFee(cf), patientcount(0){}
    void addPatient(string patientName) {
        if (patientcount < 10) {
            PatientList[patientcount] = patientName;
            patientcount++;
        } else {
            cout << "Cannot add more patients. Maximum limit reached.\n";
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout<<"\nSpecialization: "<<specialization<<"\nConsultation Fee: Rs"<<consultationFee<<"\nPatient List: ";
        for (int i = 0; i < patientcount; i++) {
            cout << PatientList[i];
            if (i < patientcount - 1) cout << ", ";
        }
        cout << endl;
    }
};

class Nurse : public Person{
    public:
    string assignedWard;
    string shiftTimings;
    Nurse(string n, int a, string c, string ad, string w, string st): Person(n, a, c, ad), assignedWard(w), shiftTimings(st){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"\nAssigned Ward: "<<assignedWard<<"\nShift Timings: "<<shiftTimings<<endl;
    }
};

class Administrator : public Person{
    public:
    string department;
    double salary;
    Administrator(string n, int a, string c, string ad, string d, double s): Person(n, a, c, ad), department(d), salary(s){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"\nDepartment: "<<department<<"\nSalary: Rs"<<salary<<endl;
    }
    void updateInfo(string c, double s){
        contactNumber = c;
        salary=s;
        cout<<"\nInformation Updated! "<<endl;
    }
};

int main(){
    Patient p1("Ali Khan", 40, "0312-3456789", "Lahore, Pakistan", 101, "Diabetes, Hypertension", "Dr. Sara Malik");
    Patient p2("Usman Raza", 35, "0300-5678912", "Faisalabad, Pakistan", 102, "Asthma", "Dr. Sara Malik");

    Doctor d1("Dr. Sara Malik", 45, "0301-9876543", "Islamabad, Pakistan", "Cardiology", 5000);
    d1.addPatient(p1.name);
    d1.addPatient(p2.name);

    Nurse n1("Ayesha Ahmed", 32, "0302-2345678", "Karachi, Pakistan", "ICU", "Night Shift");

    Administrator admin1("Zainab Malik", 50, "0304-5678901", "Rawalpindi, Pakistan", "HR", 90000);


    cout << "\n--- Hospital Management System ---\n";
    cout << "\n--- Patient Details ---";
    p1.displayInfo();
    p2.displayInfo();
    cout << "\n--- Doctor Details ---";
    d1.displayInfo();
    cout << "\n--- Nurse Details ---";
    n1.displayInfo();
    cout << "\n--- Administrator Details ---";
    admin1.displayInfo();

    cout << "\n--- Updating Contact & Salary for Administrator ---";
    admin1.updateInfo("0305-7654321", 95000);
    return 0;
}
