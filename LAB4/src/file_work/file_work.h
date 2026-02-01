#ifndef ASD_FILE_WORK_HPP
#define ASD_FILE_WORK_HPP

#include <vector>
#include <string>
#include "../struct/struct.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

bool file_read(vector <person>& data, int n, const string& filename);

bool write_file(vector <person>& data, vector <int>& id, int n, const string& filename, milliseconds duration);

#endif //ASD_FILE_WORK_HPP
