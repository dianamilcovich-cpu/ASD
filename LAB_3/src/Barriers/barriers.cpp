#include "barriers.h"
#include "../Structs/structs.h"
#include <iostream>
#include <climits>

using namespace std;

void addBarriers(vector<Record>& a) {
    if (a.empty()) return;

    int n = a.size();

    // Добавляем место для двух барьеров
    a.resize(n + 2);

    // Сдвигаем все элементы на 1 вправо
    for (int i = n - 1; i >= 0; i--) {
        a[i + 1] = a[i];
    }

    // Левый барьер
    a[0].Number = INT_MIN;
    a[0].StrokeNumber = -1;

    // Правый барьер
    a[n + 1].Number = INT_MAX;
    a[n + 1].StrokeNumber = -1;
}