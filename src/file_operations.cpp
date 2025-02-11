#include <filesystem>
#include <fstream>
#include <iostream>
#include "file_operations.h"
#include "utils.h"

using namespace std;

void createControlFile(const filesystem::path& dir) {
    ofstream controlFile(dir / "control.txt");
    if (!controlFile) {
        cerr << "Ошибка создания файла control.txt" << endl;
        return;
    }

    for (const auto& entry : filesystem::recursive_directory_iterator(dir)) {
        if (entry.path().filename() != "control.txt" && entry.is_regular_file()) {
            controlFile << getFileDetails(entry.path()) << endl;
        }
    }
}

void createTempFile(const filesystem::path& dir) {
    ofstream tempFile(dir / "temp.txt");
    if (!tempFile) {
        cerr << "Ошибка создания файла temp.txt" << endl;
        return;
    }

    for (const auto& entry : filesystem::recursive_directory_iterator(dir)) {
        if (entry.path().filename() != "temp.txt" && entry.is_regular_file()) {
            tempFile << getFileDetails(entry.path()) << endl;
        }
    }
}

void finalize(const filesystem::path& dir) {
    filesystem::rename(dir / "temp.txt", dir / "control.txt");
    cout << "Файл temp.txt успешно переписан в control.txt" << endl;
}