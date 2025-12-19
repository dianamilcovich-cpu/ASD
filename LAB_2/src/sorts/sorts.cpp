#include <vector>
#include "sorts.h"
#include "../Structs/structs.h"

using namespace std;

// Перегрузка операторов сравнения для struct key
bool operator>(const key& a, const key& b) {
    // Сравнение по дате (возрастание)
    if (a.data.year != b.data.year)
        return a.data.year > b.data.year;
    if (a.data.month != b.data.month)
        return a.data.month > b.data.month;
    if (a.data.day != b.data.day)
        return a.data.day > b.data.day;

    // Даты равны - сравнение по ФИО (убывание)
    if (a.fio.F != b.fio.F)
        return a.fio.F < b.fio.F;
    if (a.fio.I != b.fio.I)
        return a.fio.I < b.fio.I;
    return a.fio.O < b.fio.O;
}

bool operator<(const key& a, const key& b) {
    // Сравнение по дате (возрастание)
    if (a.data.year != b.data.year)
        return a.data.year < b.data.year;
    if (a.data.month != b.data.month)
        return a.data.month < b.data.month;
    if (a.data.day != b.data.day)
        return a.data.day < b.data.day;

    // Даты равны - сравнение по ФИО (убывание)
    if (a.fio.F != b.fio.F)
        return a.fio.F > b.fio.F;
    if (a.fio.I != b.fio.I)
        return a.fio.I > b.fio.I;
    return a.fio.O > b.fio.O;
}

void sort_shaker(vector<key>& data, int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (data[i] > data[i + 1]) {
                key temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (data[i - 1] > data[i]) {
                key temp = data[i - 1];
                data[i - 1] = data[i];
                data[i] = temp;
            }
        }
        left++;
    }
}

void sort_Shella(vector<key>& data, int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            key temp = data[i];
            int j = i;

            // Сдвигаем элементы, пока не найдём правильную позицию
            while (j >= gap && temp < data[j - gap]) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
        gap /= 2;
    }
}