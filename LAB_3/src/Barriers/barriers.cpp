#include "barriers.h"
#include "../Structs/structs.h"
using namespace std;
void addBarriers(vector<Record>& a) {
    int n = a.size();
    a.resize(n+2);
    for (int i = n-1; i >= 0; i--) {
        a[i+1] = a[i];
    }
    //левый барьер
    a[0].Number = -10000000000;
    a[0].StrokeNumber = 0;

    //правый барьер
    a[n + 1].Number = 10000000000;
    a[n +1].StrokeNumber = 0;

}