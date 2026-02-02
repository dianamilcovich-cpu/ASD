#ifndef ASD_SEARCH_HPP
#define ASD_SEARCH_HPP

#include <vector>
#include "../../struct/struct.h"
#include <string>

using namespace std;

vector<int> rk_search_persons(const vector<person>& data, const vector<string>& pattern_m, int requiredCount);
bool rk_exact_count(const string& text, const string& pattern, int requiredCount);
vector<int> build_lps(const string &pattern);
#endif //ASD_SEARCH_HPP
