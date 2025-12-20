#include "work_file.h"
#include "../Structs/structs.h"
#include<fstream>
#include <iostream>
using namespace std;
bool readFile(const string& inputFile, int n, vector<Record>& records ) {
    ifstream file(inputFile);
    if (!file)
        return false;
    records.resize(n);
    Record temp;
    for (int i = 0; i < n; i++) {
        file>>temp.date.day>>temp.date.month>>temp.date.year>>
        temp.fio.f>>temp.fio.i>>temp.fio.o>>
        temp.Number;
        temp.StrokeNumber = i +1;
        records[i] = temp;
    }
    file.close();
    return true;
}
void writeFile(const string& outputFile, int Index, int steps) {
    ofstream file_out(outputFile);
    if (!file_out)
        return;
    if (Index == -1)
        file_out<<"Ключ не найден\n";
    else
        file_out<<"Номер строки файла"<<Index<<"\n";
    file_out<<"Количество шагов поиска:"<<steps<<"\n";
    file_out.close();
}