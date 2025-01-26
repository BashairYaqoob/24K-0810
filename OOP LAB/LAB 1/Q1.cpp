/*Register Event Participants
Write a program to collect the names of participants for two events. Each event can have a maximum of 5 participants. Store the names in two separate arrays.
2. Task 2: Attendance Checker
Add functionality to check if a particular participant is registered in either of the two events. Prompt the user to enter a name and display the result.
3. Task 3: Calculate Total Donations
Each participant donates a fixed amount of $10 to attend the event. Write a program to calculate the total donation amount collected from both events.
4. Task 4: Display Participant Names in Reverse
Display the names of participants in reverse order (for each event separately).
5. Task 5: Event Popularity Bar Chart
Create a simple bar chart to visualize the number of participants for each event. Use * for each participant.
  */
#include <iostream>
#include <string.h>
using namespace std;

void participant(char arr1[5][20], char arr2[5][20], int *ev1, int *ev2)
{
    int c;
    cout << "Press 1 to add in event 1 or 2 to add in event 2: ";
    cin >> c;
    if (c == 1)
    {
        if (*ev1 < 5)
        {
            cin >> arr1[*ev1];
            (*ev1)++;
        }
        else
        {
            cout << "Registration full!";
        }
    }
    else if (c == 2)
    {
        if (*ev2 < 5)
        {
            cin >> arr2[*ev2];
            (*ev2)++;
        }
        else
        {
            cout << "Registration full!";
        }
    }
    else
    {
        cout << "invalid entry" << endl;
    }
}
void check(char arr1[5][20], char arr2[5][20], int *ev1, int *ev2)
{
    cout << "Enter a name to check whether a person is present: ";
    char name[20];
    int found = 0;
    cin >> name;
    for (int i = 0; i < *ev1; i++)
    {
        if (strcmp(name, arr1[i]) == 0)
        {
            cout << "Present in event 1"<<endl;
            found = 1;
            break;
        }
    }
    for (int i = 0; i < *ev2; i++)
    {
        if (strcmp(name, arr2[i]) == 0)
        {
            cout << "Present in event 2"<<endl;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "entry not found!" << endl;
    }
}
void donations(int ev1, int ev2)
{
    cout << "Total donations=" << ev1 * 10 + ev2 * 10 << endl;
}
void reverseString(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        swap(str[i], str[len - i - 1]);
    }
}

void rev(char arr1[][20], char arr2[][20], int ev1, int ev2)
{
    cout << "Event 1 (Reversed Names):" << endl;
    for (int i = 0; i < ev1; i++)
    {
        reverseString(arr1[i]);
        cout << arr1[i] << endl;
    }

    cout << "Event 2 (Reversed Names):" << endl;
    for (int i = 0; i < ev2; i++)
    {
        reverseString(arr2[i]);
        cout << arr2[i] << endl;
    }
}

void bar(int ev1, int ev2)
{
    cout << "event 1 ";
    for (int i = 0; i < ev1; i++)
    {
        cout << "*";
    }
    cout << "\nevent 2 ";
    for (int i = 0; i < ev2; i++)
    {
        cout << "*";
    }
}
int main()
{
    char arr1[5][20], arr2[5][20];
    int ev1 = 0, ev2 = 0;
    int c;
    while (1)
    {
        cout << "\nMenu\n 1-Register event Participants\n 2-Attendance Checker\n 3-Total Donations\n 4-Reversed Names\n 5-Statistics \n 6-Exit\n Enter a number(1-6)" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            participant(arr1, arr2, &ev1, &ev2);
            break;
        case 2:
            check(arr1, arr2, &ev1, &ev2);
            break;
        case 3:
            donations(ev1, ev2);
            break;
        case 4:
            rev(arr1, arr2, ev1, ev2);
            break;
        case 5:
            bar(ev1, ev2);
            break;
        case 6:
            return 0;
        default:
            cout << "Enter correct number" << endl;
            break;
        }
    }
    return 0;
}
