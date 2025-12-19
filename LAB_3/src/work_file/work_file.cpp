#include "work_file.h"
#include "../Structs/structs.h"
#include<fstream>
#include <iostream>
using namespace std;
bool readFile(const string& filename, int n, vector<Record>& records) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout<<"Ошибка открытия файла!";
        return false;
    }
    records.clear();
    records.reserve(n);
    Record temp;
    int i = 0;
    for (; i < n; i++) {
        if (!(fin >> temp.date.day >> temp.date.month >> temp. date.year
        >>temp.fio.f >> temp.fio.i >> temp.fio.o >>temp.requestNumber)) {
            break;
        }
        temp.StrokeNumber = i+1;
        records[i] = temp;
    }
    if (i < n) {
        records.resize(i);
    }
    fin.close();
    return true;
}