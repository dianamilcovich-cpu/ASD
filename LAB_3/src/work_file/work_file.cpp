#include "work_file.h"
#include "../Structs/structs.h"
#include<fstream>
#include <iostream>
using namespace std;
bool readFile(const string& inputFile, const int n, vector<Record>& records) {
    ifstream file(inputFile);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << inputFile << endl;
        return false;
    }

    for (int i = 0; i < n; i++) {
        file >> records[i].date.day >> records[i].date.month >> records[i].date.year
        >> records[i].fio.f >> records[i].fio.i >> records[i].fio.o >> records[i].Number;
        records[i].StrokeNumber = i + 1;
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