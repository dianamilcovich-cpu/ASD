#include <string>
#ifndef STRUCTS_H
#define STRUCTS_H
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
    int num_str;
};



#endif //STRUCTS_H
