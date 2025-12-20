#include "sort.h"
#include "../Structs/structs.h"
using namespace std;
void ShellSort(vector<Record>& a) {
    int n = a.size();
    for (int gap = n/2; gap > 0; gap /=2) {
        for (int i = gap; i < n; i++) {
            Record temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap].Number > temp.Number) {
                a[j] = a[j -gap];
                j-=gap;
            }
            a[j] = temp;
        }
    }
}
