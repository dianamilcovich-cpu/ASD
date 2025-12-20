#include<vector>
#include<string>
#include"work_file/work_file.h"
#include"Barriers/barriers.h"
#include"Search/search.h"
#include"Sort/sort.h"
#include"Structs/structs.h"
using namespace std;
int main() {
    vector<Record> records;
    int n = 100000;
    int key = 47930;
    if (!readFile("../LAB_3/Static/inpur_1000000.txt", n, records)) {
        writeFile("../Static/output",-1,0);
        return 0;
    }
    ShellSort(records);
    addBarriers(records);

    int steps = 0;
    int pos = InterpolationSearch(records, key, steps);

    int res = -1;
    if (pos > 0)
        res = records[pos].StrokeNumber;
    writeFile("../LAB_3/Static/output",res,steps);
    return 0;
}
