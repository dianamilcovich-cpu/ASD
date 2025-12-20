#ifndef STRUCTS_H
#define STRUCTS_H
#include<string>
using namespace std;
struct Date {
    int day;
    int month;
    int year;
};
struct FIO {
    string f;
    string i;
    string o;
};
struct Record {
    Date date;
    FIO fio;
    int Number;
    int StrokeNumber;
};
#endif //STRUCTS_H
