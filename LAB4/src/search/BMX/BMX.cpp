#include "../../struct/struct.h"
#include <vector>
#include <string>


using namespace std;



bool bmh_exact_count(const std::string& text, const std::string& pattern, int requiredCount) {

    int m = static_cast<int>(pattern.length());
    int n = static_cast<int>(text.length());

    if (n < m)
        return false;

    int skip[256];

    for (int c = 0; c < 256; ++c)
        skip[c] = m;

    for (int i = 0; i < m - 1; ++i)
        skip[(unsigned char)pattern[i]] = m - 1 - i;

    int i = 0;
    int foundCount = 0;

    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0) {
            if (text[i + j] == pattern[j])
                --j;
            else
                break;
        }

        if (j < 0) {
            foundCount++;

            if (foundCount > requiredCount)
                return false;

            i += 1;
        } else {
            i += skip[(unsigned char)text[i + m - 1]];
        }
    }

    return foundCount == requiredCount;
}

vector<int> bmh_search_persons(const vector<person>& data, const vector<string>& pattern_m, int requiredCount) {
    vector<int> result(data.size());
    int k = 0;
    int flag = 0;

    for (const person& p : data) {

        string fioStr = p.fio.surname + " " + p.fio.name + " " + p.fio.patronymic;

        for(const string& pattern : pattern_m){

            bool descMatch = false;

            bool fioMatch = bmh_exact_count(fioStr, pattern, requiredCount);
            if(!fioMatch){
                descMatch = bmh_exact_count(p.description, pattern, requiredCount);
            }

            if (fioMatch || descMatch) {
                result[k] = p.stroke;
                flag = 1;
                ++k;
            }
        }
    }
    if(flag == 0){
        k = 1;
        result[0] = -1;
    }
    result.resize(k);

    return result;
}




