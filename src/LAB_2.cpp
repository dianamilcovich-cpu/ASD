#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include<vector>
#include <ctime>
#include <iomanip>
#include "../src/sorts/sorts.h"
#include "../src/Structs/structs.h"
#include "file_work/file_work.h"
using namespace std;
using namespace std::chrono;


int main(){
    system("chcp 65001");
    int N = 6;
    vector <key> mas(N);

    file_read("../static/in/input_10000.txt", mas ,N);
    auto start = high_resolution_clock::now();
    sort_shaker(mas, N);
    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);
    writeFile("../static/out/out_data_shaker", mas, N, duration);


    file_read("../static/in/input_100000.txt", mas ,N);
    start = high_resolution_clock::now();
    sort_Shella(mas, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    writeFile("../static/out/out_data_shell", mas, N, duration);

}
