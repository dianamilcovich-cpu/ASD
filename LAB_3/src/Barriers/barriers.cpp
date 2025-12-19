#include "barriers.h"
#include "../Structs/structs.h"
using namespace std;
void addBarriers(vector<Record>& records) {
    int n = records.size();
    records.resize(n+2);
    for (int i = n-1; i >= 0; i--) {
        records[i+1] = records[i];
    }
    //левый барьер
    records[0].requestNumber = -10000000000;
    records[0].StrokeNumber = 0;

    //правый барьер
    records[n + 1].requestNumber = 10000000000;
    records[n +1].StrokeNumber = 0;

}