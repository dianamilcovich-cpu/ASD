#include <vector>
#include "sorts.h"
#include "../Structs/structs.h"

using namespace std;


void sort_shaker(vector <key>& data, int n) {
    int left = 0;
    int right = n - 1;
    while(left < right){
        for(int i = left; i < right; i++) {
            int flag = 0;

            // Дата по ВОЗРАСТАНИЮ
            if (data[i].data.year > data[i+1].data.year
                || (data[i].data.year == data[i+1].data.year && data[i].data.month > data[i+1].data.month)
                || (data[i].data.year == data[i+1].data.year && data[i].data.month == data[i+1].data.month && data[i].data.day > data[i+1].data.day)) {
                flag = 1;
            }
            // Если даты равны, ФИО по УБЫВАНИЮ
            else if (data[i].data.year == data[i+1].data.year
                     && data[i].data.month == data[i+1].data.month
                     && data[i].data.day == data[i+1].data.day) {
                if (data[i].fio.F < data[i+1].fio.F ||
                   (data[i].fio.F == data[i+1].fio.F && data[i].fio.I < data[i+1].fio.I) ||
                   (data[i].fio.F == data[i+1].fio.F && data[i].fio.I == data[i+1].fio.I && data[i].fio.O < data[i+1].fio.O)) {
                    flag = 1;
                }
            }

            if (flag == 1) {
                key temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
        right--;

        for(int i = right; i > left; i--){
            int swap_flag = 0;

            // Дата по ВОЗРАСТАНИЮ
            if (data[i-1].data.year > data[i].data.year
                || (data[i-1].data.year == data[i].data.year && data[i-1].data.month > data[i].data.month)
                || (data[i-1].data.year == data[i].data.year && data[i-1].data.month == data[i].data.month && data[i-1].data.day > data[i].data.day)) {
                swap_flag = 1;
            }
            // Если даты равны, ФИО по УБЫВАНИЮ
            else if (data[i-1].data.year == data[i].data.year
                     && data[i-1].data.month == data[i].data.month
                     && data[i-1].data.day == data[i].data.day) {
                if (data[i-1].fio.F < data[i].fio.F ||  // ЗНАК < для убывания
                   (data[i-1].fio.F == data[i].fio.F && data[i-1].fio.I < data[i].fio.I) ||
                   (data[i-1].fio.F == data[i].fio.F && data[i-1].fio.I == data[i].fio.I && data[i-1].fio.O < data[i].fio.O)) {
                    swap_flag = 1;
                }
            }

            if (swap_flag == 1) {
                key temp = data[i-1];
                data[i-1] = data[i];
                data[i] = temp;
            }
        }
        left++;
    }
}
void sort_Shella(vector <key>& data, int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j >= gap) {

                if (data[j].data.year < data[j - gap].data.year ||
                    (data[j].data.year == data[j - gap].data.year &&
                     data[j].data.month < data[j - gap].data.month) ||
                    (data[j].data.year == data[j - gap].data.year &&
                     data[j].data.month == data[j - gap].data.month &&
                     data[j].data.day < data[j - gap].data.day)) {


                    key temp = data[j];
                    data[j] = data[j - gap];
                    data[j - gap] = temp;
                    j -= gap;
                     }

                else if (data[j].data.year == data[j - gap].data.year &&
                         data[j].data.month == data[j - gap].data.month &&
                         data[j].data.day == data[j - gap].data.day &&
                         (data[j - gap].fio.F > data[j].fio.F ||
                          (data[j - gap].fio.F == data[j].fio.F && data[j - gap].fio.I > data[j].fio.I) ||
                          (data[j - gap].fio.F == data[j].fio.F && data[j - gap].fio.I == data[j].fio.I && data[j - gap].fio.O > data[j].fio.O))) {


                    key temp = data[j];
                    data[j] = data[j - gap];
                    data[j - gap] = temp;
                    j -= gap;
                          }
                else {
                    break;
                }
            }
        }
        gap /= 2;
    }
}
