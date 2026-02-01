#include "../../struct/struct.h"
#include <vector>
#include <string>

using namespace std;

bool rk_exact_count(const string& text, const string& pattern, int requiredCount) {

    int m = static_cast<int>(pattern.length());
    int n = static_cast<int>(text.length());

    if (n < m)
        return false;

    const int d = 256;
    const int q = 1000000000;

    long long h = 1;
    for (int i = 0; i < m - 1; ++i)
        h = (h * d) % q;

    long long p = 0;
    long long t = 0;

    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    int foundCount = 0;

    for (int i = 0; i <= n - m; ++i) {

        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                ++j;

            if (j == m) {
                foundCount++;

                if (foundCount > requiredCount)
                    return false;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h % q) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    return foundCount == requiredCount;
}

vector<int> rk_search_persons(const vector<person>& data, const vector<string>& pattern_m, int requiredCount) {
    vector<int> result(data.size());
    int k = 0;
    int flag = 0;

    for (const person &p: data) {

        string fioStr = p.fio.surname + " " + p.fio.name + " " + p.fio.patronymic;

        for (const string &pattern: pattern_m) {
            bool descMatch = false;

            bool fioMatch = rk_exact_count(fioStr, pattern, requiredCount);
            if (!fioMatch) {
                descMatch = rk_exact_count(p.description, pattern, requiredCount);
            }

            if (fioMatch || descMatch) {
                result[k] = p.stroke;
                flag = 1;
                ++k;
            }
        }

    }
    if (flag == 0) {
        k = 1;
        result[0] = -1;
    }

    result.resize(k);
    return result;
}