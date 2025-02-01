//Matrix multiplication using DMA

#include <iostream>
using namespace std;

int main()
{
    int row, col, row2, col2;
    cout << "Enter number of rows in Matrix 1: ";
    cin >> row;
    cout << "Enter number of columns in Matrix 1: ";
    cin >> col;
    cout << "Enter number of rows in Matrix 2: ";
    cin >> row2;
    cout << "Enter number of columns in Matrix 2: ";
    cin >> col2;
    if (col != row2)
    {
        cout << "Multiplation is not possible!" << endl;
        return 1;
    }

    int **ptr1 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr1[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element for Matrix 1, Row " << i + 1 << " Col " << j + 1 << ": ";
            cin >> *(*(ptr1 + i) + j);
        }
    }
    int **ptr2 = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        ptr2[i] = new int[col2];
    }

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "Enter element for Matrix 2, Row " << i + 1 << " Col " << j + 1 << ": ";
            cin >> *(*(ptr2 + i) + j);
        }
    }
    int **ptr3 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr3[i] = new int[col2];
    }

    cout << "Multiplication of input matrices" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "|";
        for (int j = 0; j < col2; j++)
        {
            ptr3[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
            }
            cout << ptr3[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] ptr1[i];
        delete[] ptr3[i];
    }
    for (int i = 0; i < row2; i++)
    {
        delete[] ptr2[i];
    }
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;

    return 0;
}
