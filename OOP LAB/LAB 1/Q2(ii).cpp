/*
Task 4: Monthly AQI Comparison
Extend the program to include data for an entire month (28 days).
Calculate the overall monthly average AQI for each city.
Identify the city with the most improved air quality (largest drop in weekly averages between the first and last weeks).
Task 5: Generate a Report
Summarize the findings in a detailed report. Include:
Weekly averages for each city.
Critical pollution days for each city.
A comparison of the highest and lowest AQI values recorded during the month.
*/


#include <iostream>
using namespace std;

int i, j, k;

void input(int arr[4][28])
{
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 28; j++)
        {
            cout << "Enter AQI for City " << i + 1 << ", Day " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}
void weekavg(int arr[4][28], int week[4][4])
{
    for (i = 0; i < 4; i++)
    {
        for (k = 0; k < 4; k++)
        {
            int sum = 0;
            for (j = k * 7; j < (k + 1) * 7; j++)
            {
                sum += arr[i][j];
            }
            week[i][k] = sum / 7;
        }
    }
}
void monthavg(int arr[4][28], int month[4])
{
    for (i = 0; i < 4; i++)
    {
        int sum = 0;
        for (j = 0; j < 28; j++)
        {
            sum += arr[i][j];
        }
        month[i] = sum / 28;
    }
}
void drop(int week[4][4])
{
    int drop[4] = {0};
    int max = drop[0];
    int c = 1;
    for (i = 0; i < 4; i++)
    {
        drop[i] = week[i][0] - week[i][3];
        if (drop[i] > max)
        {
            max = drop[i];
            c = i + 1;
        }
    }
    cout << " City with most improved Air quality: " << c << endl;
}
void cp(int arr[4][28])
{
    cout << "--Critical pollution days(AQI above 50)--" << endl;
    for (i = 0; i < 4; i++)
    {
        cout << "City " << i + 1;
        bool critical = false;
        for (j = 0; j < 28; j++)
        {
            if (arr[i][j] > 150)
            {
                critical = true;
                cout << " ~Day " << j + 1;
            }
        }
        if (!critical)
        {
            cout << " None";
        }
        cout << endl;
    }
}
void compare(int arr[4][28])
{
    for (int i = 0; i < 4; i++)
    {
        int high=0;
        int low=10000;
        for (int j = 0; j < 28; j++)
        {
            if (arr[i][j] > high)
            {
                high = arr[i][j];
            }
            if (arr[i][j] < low)
            {
                low = arr[i][j];
            }
        }
        cout<<"\nCity "<<i+1<<"Highest AQI= "<<high<<" Lowest AQI= "<<low<<endl;
    }
}

int main()
{
    int arr[4][28];
    int week[4][4] = {0};
    int month[4] = {0};
    input(arr);
    weekavg(arr, week);
    monthavg(arr, month);
    drop(week);
    cout << "--REPORT--" << endl;
    for (i = 0; i < 4; i++)
    {
        cout << "Weekly Average for City " << i + 1 << endl;
        for (j = 0; j < 4; j++)
        {
            cout << week[i][j] << " ";
        }
        cout << endl;
    }
    cp(arr);
    compare(arr);
    return 0;
}
