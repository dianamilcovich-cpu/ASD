#include "src/search/BMX/BMX.hpp"
#include "src/struct/struct.h"
#include "src/file_work/file_work.h"
#include "src/search/BMX/BMX.hpp"
#include "src/search/RK/RK.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;


using namespace std;

int main(){
    system("chcp 65001");

    int n = 3;
    vector <person> data(n);
    vector <int> id(n);
    vector <string> pattern = {"Laq"};

    file_read(data, n, "../LAB4/static/input/input_file1.txt");


    auto start = high_resolution_clock::now();
    id = bmh_search_persons(data, pattern, 2);
    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);

    write_file(data, id, n, "../LAB4/static/output/output_bmh.txt", duration);

    start = high_resolution_clock::now();
    id = rk_search_persons(data, pattern, 2);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    write_file(data, id, n, "../LAB4/static/output/output_RK.txt", duration);

    for(const string& pattern1 : pattern){
        cout << "ТАБЛИЦА КМП:" << endl;
        vector <int> lps_kmp = build_lps(pattern1);
        for(int i = 0; i < lps_kmp.size(); i++){
            cout << " " << pattern1[i] << " ";
        }

        cout << endl;

        for(int i = 0; i < lps_kmp.size(); i++){
            cout << " " << lps_kmp[i] << " ";
        }

    }

}