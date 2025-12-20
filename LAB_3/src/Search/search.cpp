#include "search.h"
int InterpolationSearch(vector<Record>& a, int key, int& steps) {
    int left = 0;
    int right = a.size() - 1;
    steps = 0;
    while (true) {
        int pos;
        pos = left + (double)(key - a[left].Number)*(right - left)/(a[right].Number - a[left].Number );
        if (a[pos].Number < key)
            left = pos + 1;
        else if (a[pos].Number > key)
            right = pos - 1;
        else {
            while (pos>1 && a[pos-1].Number == key) {
                pos --;
                steps++;
            }
            return pos;
        }

    }
}
