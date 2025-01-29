/*Task 1: Weekly Air Quality Index (AQI) Tracker 
Write a program to record the AQI for 4 cities over 7 days using a 2D array. Input the AQI values for each city and each day.
Calculate and display the average AQI for each city over the week. 
Identify the city with the worst air quality (highest average AQI). 
Task 2: Identify Critical Pollution Days
Add functionality to identify days where the AQI exceeded 150 for any city (critical pollution days). Display these days for each city.
Task 3: Data Visualization 
Generate a visual representation of AQI levels for each city over the week. For example, display * symbols where each * represents an AQI increment of 50.
*/
#include <iostream>
using namespace std;

int main()
{
    int arr[4][7];
    int i, j;
    cout << "--AQI FOR 4 CITIES FOR A WEEK!--" << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 7; j++)
        {
            cout << "Enter AQI for City " << i + 1 << " Day " << j + 1 << " ";
            cin >> arr[i][j];
        }
    }
    int arr1[4] = {0};
    int sum;
    for (i = 0; i < 4; i++)
    {
        sum = 0;
        for (j = 0; j < 7; j++)
        {
            sum += arr[i][j];
        }
        arr1[i] = sum / 7;
    }
    cout << endl;
    for (i = 0; i < 4; i++)
    {
        cout << "Average AQI for City " << i + 1 << " " << arr1[i] << endl;
    }
    int max = arr1[0];
    int index = 0;
    for (i = 1; i < 4; i++)
    {
        if (arr1[i] > max)
        {
            max = arr1[i];
            index = i;
        }
    }
    cout << "--Worst Air quality is " << max << " in City " << index + 1<<"--"<<endl;
    cout<<"--Critical pollution days(AQI above 50)--";
    for ( i = 0; i < 4; i++)
    {
        cout<<"\nCity "<<i+1;
        bool critical=false;
        for ( j = 0; j < 7; j++)
        {
            if(arr[i][j]>150){
                critical=true;
                cout<<" ~Day "<<j+1;
            }
        }
        if(!critical){
            cout<<" None";
        }
        
    }
    cout<<"\n--AQI Visualization (*=50)--"<<endl;
    for (i = 0; i < 4; i++)
    {
        cout<<"City "<<i+1<<endl;
        for (j = 0; j < 7; j++)
        {
            int stars=arr[i][j]/50;
            cout<<"\n("<<arr[i][j]<<")  ";
            for (int k = 0; k < stars; k++)
            {
                cout<<"*";
            }
            
        }
        cout<<endl;
    }
    return 0;
}
