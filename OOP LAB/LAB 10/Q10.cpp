#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("data_records.txt", ios::in);
    if(!in){
        cerr<<"Error: can't open file!";
        return 1;
    }
    in.seekg(20, ios::beg); // 9 bytes per line including '\n'

    string record;
    getline(in, record);
    cout << "Third record: " << record << endl;
    in.close();
    return 0;
