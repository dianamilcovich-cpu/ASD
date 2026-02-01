#include "search.h"
int InterpolationSearch(vector<Record>& a, int key, int& steps) {
    steps = 0;

    if (a.empty()) return -1;

    int left = 0;
    int right = a.size() - 1;

    // Предварительные проверки
    if (key < a[left].Number || key > a[right].Number) {
        return -1;
    }

    while (left <= right) {
        steps++;

        // Интерполяция
        int pos = left + ((double)(key - a[left].Number) * (right - left)) /
                  (a[right].Number - a[left].Number);

        // Защита от некорректной позиции
        if (pos < left) pos = left;
        if (pos > right) pos = right;

        if (a[pos].Number < key) {
            left = pos + 1;
        }
        else if (a[pos].Number > key) {
            right = pos - 1;
        }
        else {
            // Нашли - ищем первое вхождение
            // ВАЖНО: исправлено pos>0 вместо pos>1
            while (pos > 0 && a[pos - 1].Number == key) {
                pos--;
                steps++;
            }
            return pos;
        }
    }

    return -1;
}