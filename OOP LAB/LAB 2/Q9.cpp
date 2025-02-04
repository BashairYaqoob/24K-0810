//Structure of Product inventory using dma

#include <iostream>
#include <string>
using namespace std;

struct inventory
{
    int productID;
    string name;
    int quantity;
    float price;
};

int main()
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    inventory *products = new inventory[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Product ID:";
        cin>>products[i].productID;        
        cin.ignore();
        cout << "Enter the Product name: ";
        getline(cin, products[i].name);
        cout << "Enter the quantity of product required: ";
        cin >> products[i].quantity;
        cout << "Enter the price: ";
        cin >> products[i].price;
    }

    float sum=0;
    for (int i = 0; i < n; i++)
    {
        cout << "Cost of " << products[i].name << ": " << products[i].quantity * products[i].price << endl;
        sum+=products[i].quantity * products[i].price;
    }
    cout<<"\n---TOTAL VALUE = "<<sum<<"---"; 
    delete[] products;
    return 0;
}
