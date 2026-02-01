#include "../struct/struct.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

bool file_read(vector <person>& data, int n, const string& filename){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл\n";
        return false;
    }

    for(int i = 0; i < n; i++){
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year
        >> data[i].fio.surname >> data[i].fio.name >> data[i].fio.patronymic >> data[i].application >> data[i].description;
        data[i].stroke = i;
    }
    return true;
}

bool write_file(vector <person>& data, vector <int>& id, int n, const string& filename, milliseconds duration){
    ofstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл\n";
        return false;
    }

    for(int i:id){
        file << "Номер строки: " << i << " | ";
        file << data[i].date.day << " " << data[i].date.month<< " " << data[i].date.year
        << " " <<data[i].fio.surname << " " << data[i].fio.name << " " << data[i].fio.patronymic
        << " " << data[i].application << " " << data[i].description << endl;
    }

    file << duration;
    return true;
}
