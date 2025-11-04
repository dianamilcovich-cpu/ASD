#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

struct Data {
    int day;
    int month;
    int year;
};
struct FIO {
    string F;
    string I;
    string O;
};
struct key {
    Data data;
    FIO fio;
    int num_str;
};

void print(key* data, int N){
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << data[i].data.day << "." << data[i].data.month << "." << data[i].data.year << " "
             << data[i].fio.F << " " << data[i].fio.I << " " << data[i].fio.O << "\n";
    }
}

void sort_data(key* data,int n) {
    int left = 0;
    int right = n - 1;
    while(left < right){
        for(int i = left; i < right; i++) {
            if (data[i].data.year > data[i+1].data.year
                || (data[i].data.year == data[i+1].data.year && data[i].data.month>data[i+1].data.month)
                || (data[i].data.year ==data[i+1].data.year && data[i].data.month ==data[i+1].data.month && data[i].data.day > data[i+1].data.day)){
                swap(data[i], data[i+1]);

            }
        }
        right--;


        for(int i = right; i > left; i--){
            if (data[i-1].data.year > data[i].data.year ||
                (data[i-1].data.year == data[i].data.year && data[i-1].data.month > data[i].data.month) ||
                (data[i-1].data.year == data[i].data.year && data[i-1].data.month == data[i].data.month && data[i-1].data.day > data[i].data.day)) {
                swap(data[i-1], data[i]);

            }

        }
        left++;

    }
}
void sort_name(key* data, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (data[i].fio.F < data[i+1].fio.F ||
                (data[i].fio.F == data[i+1].fio.F && data[i].fio.I < data[i+1].fio.I) ||
                (data[i].fio.F == data[i+1].fio.F && data[i].fio.I == data[i+1].fio.I && data[i].fio.O < data[i+1].fio.O) ) {
                swap(data[i], data[i+1]);
            }
        }
        right --;
        for (int i = right; i > left; i--) {
            if (data[i - 1].fio.F < data[i].fio.F ||
                (data[i - 1].fio.F == data[i].fio.F && data[i - 1].fio.I < data[i].fio.I) ||
                (data[i - 1].fio.F == data[i].fio.F && data[i - 1].fio.I == data[i].fio.I && data[i - 1].fio.O < data[i].fio.O)) {
                swap(data[i - 1], data[i]);
                }
        }
        left++;
    }
}
void sort_Shella_date(key* data, int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i< n; i++) {
            int j = i;
            while (j >= gap &&
                (data[j].data.year < data[j - gap].data.year ||
                    (data[j].data.year == data[j - gap].data.year &&
                     data[j].data.month < data[j - gap].data.month) ||
                    (data[j].data.year == data[j - gap].data.year &&
                     data[j].data.month == data[j - gap].data.month &&
                     data[j].data.day < data[j - gap].data.day))
                 ){
                swap(data[j], data[j - gap]);
                j -= gap;
                 }

        }
        gap /= 2;
    }



}
void sort_Shella_fio(key* data, int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j >= gap &&
                  (data[j - gap].fio.F > data[j].fio.F ||
                  (data[j - gap].fio.F == data[j].fio.F && data[j - gap].fio.I > data[j].fio.I) ||
                  (data[j - gap].fio.F == data[j].fio.F && data[j - gap].fio.I == data[j].fio.I && data[j - gap].fio.O > data[j].fio.O))) {
                swap(data[j - gap], data[j]);
                j -= gap;
                  }
        }
        gap /= 2;
    }
}


int main(){
    system("chcp 65001");
    int N = 6;
    key* mas =new key[N];
    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        delete[] mas;
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

    ofstream out_file_shaker("out_data_shaker");
    auto start = high_resolution_clock::now();
    sort_data(mas, N);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    out_file_shaker << "СОРТИРОВКА ПО ДАТЕ\n";
    for(int i = 0; i < N; i++){
        out_file_shaker << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shaker << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;

    start = high_resolution_clock::now();
    sort_name(mas, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_shaker << "CОРТИРОВКА ПО ФИО\n";
    for(int i = 0; i < N; i++){
        out_file_shaker << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shaker << "Время, затраченное на сортировку: " << duration.count() << " мс";
    out_file_shaker.close();

    //ВЫВОД БЫСТРОЙ СОРТИРОВКИ В ФАЙЛ
    ofstream out_file_shell("out_data_shell");
    start = high_resolution_clock::now();
    sort_Shella_date(mas, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_shell << "CОРТИРОВКА ПО ДАТЕ\n";
    for(int i = 0; i < N; i++){
        out_file_shell << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shell << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;

    start = high_resolution_clock::now();
    sort_Shella_fio(mas, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_shell << "CОРТИРОВКА ПО ФИО\n";
    for(int i = 0; i < N; i++){
        out_file_shell << mas[i].data.day << "." << mas[i].data.month << "." << mas[i].data.year << " "
        << mas[i].fio.F << " " << mas[i].fio.I << " " << mas[i].fio.O << " " << mas[i].num_str << endl;
    }
    out_file_shell << "Время, затраченное на сортировку: " << duration.count() << " мс";
    out_file_shell.close();

    delete[] mas;
    file.close();
}
