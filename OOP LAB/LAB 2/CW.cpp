//fucntion for DMA
//array input
//display array
// release array
#include "iostream"
using namespace std;



int** dma(int rows, int cols){
    int **ptr = new int*[rows];
    for(int i=0; i<rows; i++){
        ptr[i] = new int[cols];
    }
    return ptr;
}

void input(int **ptr, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<"Enter element for Row "<<i+1<<" Column "<<j+1<<":";
            cin>>*(*(ptr+i)+j);
        }
    }
}

void display(int **ptr, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        cout<<"|";
        for (int j = 0; j < cols; j++)
        {
            cout<<*(*(ptr+i)+j)<<" | ";
        }
        cout<<endl;
    }
}
void releasememory(int **ptr, int rows){
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main(){
    int rows, cols;
    cout << "Enter number of rows: " << endl;
    cin >> rows;
    cout << "Enter number of columns: "  << endl;
    cin >> cols;
    int **ptr = dma(rows, cols);
    input(ptr, rows, cols);
    display(ptr, rows, cols);
    releasememory(ptr, rows);
    return 0;
}
