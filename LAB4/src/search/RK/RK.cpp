#include "../../struct/struct.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> build_lps(const string &pattern) {
    int pattern_length = static_cast<int>(pattern.length());
    vector<int> lps(pattern_length, 0);

    int len = 0;
    int i = 1;

    while (i < pattern_length) {//aba
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


int rk_exact_count(const string& text, const string& pattern, int requiredCount) {

    int m = static_cast<int>(pattern.length());
    int n = static_cast<int>(text.length());

    if (n < m)
        return false;

    const int d = 256;
    const int q = 1000000007;

    long long h = 1;
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }


    long long p = 0;
    long long t = 0;

    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;//хеш паттерна
        t = (d * t + text[i]) % q;//хеш начального текста, где стоит паттерн
    }

    //-----------------------------------


    cout << "паттерн: ";
    for(int i = 0; i < m; i++){
        cout << pattern[i];
    }

    cout << " - Хеш: " << p << endl;

    cout << "Окно текста, где стоит паттерн: ";

    for(int i = 0; i < m; i++){
        cout << text[i];
    }

    cout << "- Начальный хеш: " << t << endl;

    //------------------------------------------

    int foundCount = 0;

    for (int i = 0; i <= n - m; ++i) {

        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                ++j;

            if (j == m) {
                foundCount++;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h % q) + text[i + m]) % q;//хеш для смещения на 1(h - это степень d)
            if (t < 0)
                t += q;
        }
        cout << "Новое окно текста, где стоит паттерн: ";
        //для вывода
        int start = i;
        int end = i + m;
        //
        for(start; start < end; start++){
            cout << text[start];
        }

        cout << " - Новый хеш: " << t << endl;

    }




    return foundCount;
}

vector<int> rk_search_persons(const vector<person>& data, const vector<string>& pattern_m, int requiredCount) {
    vector<int> result(data.size());
    int k = 0;
    int flag = 0;

    for (const person &p: data) {

        string fioStr = p.fio.surname + " " + p.fio.name + " " + p.fio.patronymic;

        for (const string &pattern: pattern_m) {

            int fioMatch;
            int descMatch;

            cout << "==========" << "Номер строки:" << p.stroke << "==============" << endl;
            cout << "==========" << "Для ФИО" << "==============" << endl;
            fioMatch = rk_exact_count(fioStr, pattern, requiredCount);

            if(fioMatch != requiredCount){
                cout << "==========" << "Для ОПИСАНИЯ" << "==============" << endl;
                descMatch = rk_exact_count(p.description, pattern, requiredCount);
                fioMatch += descMatch;
            }

            if (fioMatch >= requiredCount) {
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