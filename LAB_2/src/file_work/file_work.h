

#ifndef FILE_WORK_H
#define FILE_WORK_H
#include <string>
#include <vector>
#include <chrono>
#include "../Structs/structs.h"

using namespace std;


bool file_read(const string& filename, vector <key>& data,int N);
bool writeFile(const std::string &filename, const vector <key> &data, int N, chrono::milliseconds duration);


#endif //FILE_WORK_H
