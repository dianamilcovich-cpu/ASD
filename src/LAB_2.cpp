#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include<vector>
#include <ctime>
#include <iomanip>
#include "../src/sorts/sorts.h"
#include "../src/Structs/structs.h"
using namespace std;
using namespace std::chrono;


int main(){
    system("chcp 65001");
    int N = 6;
    vector <key> mas(N);
    ifstream file("../static/in/data.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }
    string line;
    for (int i = 0; i<N;i++) {
        getline(file, line);
        stringstream potoc(line);
        string part;
        getline(potoc, part,'.');
        mas[i].data.day = stoi(part);

        getline(potoc, part,'.');
        mas[i].data.month = stoi(part);

        getline(potoc, part,' ');
        mas[i].data.year = stoi(part);

        potoc>>mas[i].fio.F>>mas[i].fio.I>>mas[i].fio.O;
        mas[i].num_str = i;
    }

    ofstream out_file_shaker("../src/static/out/out_data_shaker");
    auto start = high_resolution_clock::now();
    sort_shaker(mas, N);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    out_file_shaker << "СОРТИРОВКА ПО ДАТЕ\n";
    for(int i = 0; i < N; i++){
        out_file_shaker << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shaker << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;



    ofstream out_file_shell("../src/static/out/out_data_shaker");
    start = high_resolution_clock::now();
    sort_Shella(mas, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_shell << "CОРТИРОВКА\n";
    for(int i = 0; i < N; i++){
        out_file_shell << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shell << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;

    file.close();
}
