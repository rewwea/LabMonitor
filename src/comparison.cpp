#include <fstream>
#include <string>
#include <iostream>
#include "comparison.h"

using namespace std;

bool compareFiles(const filesystem::path& file1, const filesystem::path& file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cerr << "Ошибка открытия файлов для сравнения" << endl;
        return false;
    }

    string line1, line2;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    return true;
}

void showChanges(const filesystem::path& file1, const filesystem::path& file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    string line1, line2;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Изменен файл: " << extractFileName(line1) << endl;
        }
    }
}

string extractFileName(const string& line) {
    size_t pos = line.find("File: ");
    if (pos != string::npos) {
        return line.substr(pos + 6);
    }
    return "";
}