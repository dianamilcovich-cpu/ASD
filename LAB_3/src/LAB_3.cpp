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
    setlocale(LC_ALL, "rus");

    int n = 123456;
    vector<Record> records(n);
    int key = 999;
    if (!readFile("../LAB_3/Static/input_10.txt", n, records)) {
        writeFile("../Static/output.txt",-1,0);
        return 0;
    }

    for (int i{}; i < static_cast<int>(records.size()); ++i){
        std::cout << records[i].fio.f << std::endl;
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
    writeFile("../LAB_3/Static/output2.txt",res,steps);
    return 0;
}
