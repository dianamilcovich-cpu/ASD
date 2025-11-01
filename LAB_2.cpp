#include<iostream>
#include<fstream>
#include<chrono>
#include<string>
#include<sstream>
using namespace std;

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
};
void sort_data(key* data,int n) {
    int left = 0;
    int right = n - 1;
    while(left < right){
        for(int i = left; i < right; i++) {
            if (data[i].data.year > data[i+1].data.year || (data[i].data.year == data[i+1].data.year && data[i].data.month>data[i+1].data.month) || (data[i].data.year ==data[i+1].data.year && data[i].data.month ==data[i+1].data.month && data[i].data.day > data[i+1].data.day)){
                swap(data[i], data[i+1]);

            }
        }
        right--;


        for(int i = right; i > left; i--){
            if (data[i-1].data.year > data[i].data.year || (data[i-1].data.year == data[i].data.year && data[i-1].data.month > data[i].data.month) || (data[i-1].data.year == data[i].data.year && data[i-1].data.month == data[i].data.month && data[i-1].data.day > data[i].data.day)) {
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
void sort_Shella(key* data, int n) {


}

int main(){
    system("chcp 65001");
    int N = 6;
    key* mas =new key[N];
    ifstream file("data");

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

    }
    for (int i = 0; i <N; i++) {
        cout << mas[i].data.day << '.'<< mas[i].data.month << '.'<< mas[i].data.year << ' '<< mas[i].fio.F << ' '<< mas[i].fio.I << ' '<< mas[i].fio.O << endl;
    }

    sort_data(mas, N);
    cout << "\nПосле сортировки по дате (возрастание):\n";
    for (int i = 0; i < N; i++) {
        cout << mas[i].data.day << '.' << mas[i].data.month << '.' << mas[i].data.year << ' '
             << mas[i].fio.F << ' ' << mas[i].fio.I << ' ' << mas[i].fio.O << '\n';
    }

    
    sort_name(mas, N);
    cout << "\nПосле сортировки по ФИО (убывание):\n";
    for (int i = 0; i < N; i++) {
        cout << mas[i].data.day << '.' << mas[i].data.month << '.' << mas[i].data.year << ' '
             << mas[i].fio.F << ' ' << mas[i].fio.I << ' ' << mas[i].fio.O << '\n';
    }
    delete[] mas;
    file.close();
}
