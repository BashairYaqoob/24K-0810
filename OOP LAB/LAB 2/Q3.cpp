//Structure of salary of employees using dma

#include <iostream>
#include <string>
using namespace std;

struct employee
{
    string name;
    float hoursworked;
    float hourlyrate;
};

int main()
{
    int n;
    cout << "Enter the number of employees you want to enter: ";
    cin >> n;
    cin.ignore();
    employee *employees = new employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Employee " << i + 1 << " name: ";
        getline(cin, employees[i].name);
        cout << "Enter the Employee " << i + 1 << " Hours worked: ";
        cin >> employees[i].hoursworked;
        cout << "Enter the Employee " << i + 1 << " Hourly rate: ";
        cin >> employees[i].hourlyrate;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Salary of employee " << employees[i].name << ": " << employees[i].hourlyrate * employees[i].hoursworked << endl;
    }
    delete[] employees;
    return 0;
}
