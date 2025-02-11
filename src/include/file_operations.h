#pragma once

#include <filesystem>

void createControlFile(const std::filesystem::path& dir);
void createTempFile(const std::filesystem::path& dir);
void finalize(const std::filesystem::path& dir);