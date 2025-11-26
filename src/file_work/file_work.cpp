//
// Created by п on 26.11.2025.
//

#include "file_work.h"
#include "../Structs/structs.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

bool file_read(const string& filename,vector <key>& data ,int N) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout<<"Ошибка открытия файла!";
        return false;  // Если не удалось открыть — возвращаем false
    }

    for (int i = 0; i < N; i++) {
        file >> data[i].data.day >> data[i].data.month >> data[i].data.year >> data[i].fio.F >> data[i].fio.I >> data[i].fio.O;
        data[i].num_str = i;
    }
    return true;
}

bool writeFile(const std::string &filename, const vector <key> &data, int N, chrono::milliseconds duration) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    for(int i = 0; i < N; i++){
        file << data[i].data.day << "." << data[i].data.month << "." << data[i].data.year << " "
        << data[i].fio.F << " " << data[i].fio.I << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }
    file << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;
    return true;
}
