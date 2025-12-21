#include<vector>
#include<string>
#include <iostream>
#include"work_file/work_file.h"
#include"Barriers/barriers.h"
#include"Search/search.h"
#include"Sort/sort.h"
#include"Structs/structs.h"
using namespace std;
int main() {
    system("chcp 65001");
    int n = 1000000;
    vector<Record> records(n);
    int key = 287191;
    if (!readFile("../LAB_3/Static/input_100000.txt", n, records)) {
        writeFile("../Static/output.txt",-1,0);
        return 0;
    }
    if (records.size() != n) {
        cout << "Прочитано " << records.size() << " записей вместо " << n << endl;
    }
    ShellSort(records);
    addBarriers(records);

    int steps = 0;
    int pos = InterpolationSearch(records, key, steps);

    int res = -1;
    if (pos != -1)
        res = records[pos].StrokeNumber;
    writeFile("../LAB_3/Static/output.txt",res,steps);
    return 0;
}
