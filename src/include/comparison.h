#pragma once

#include <filesystem>
#include <string>
using namespace std;

bool compareFiles(const std::filesystem::path& file1, const std::filesystem::path& file2);
void showChanges(const std::filesystem::path& file1, const std::filesystem::path& file2);
string extractFileName(const std::string& line);