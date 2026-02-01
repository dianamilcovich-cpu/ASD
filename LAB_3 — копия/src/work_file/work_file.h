#ifndef WORK_FILE_H
#define WORK_FILE_H
using namespace std;

#include <vector>;
#include <string>;
#include "../Structs/structs.h"

bool readFile(const string& inputFile, int n, vector<Record>& records );
void writeFile(const string& outputFile, int Index, int steps);

#endif //WORK_FILE_H
