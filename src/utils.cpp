#include <filesystem>
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "../src/include/utils.h"

using namespace std;

string getFileDetails(const filesystem::path& filePath) {
    string result;
    result += "File: " + filePath.filename().string() + "\n";
    result += "Size: " + to_string(filesystem::file_size(filePath)) + " bytes\n";

    // Преобразуем время последнего изменения в читаемый формат
    auto lastWriteTime = filesystem::last_write_time(filePath);
    auto timeSinceEpoch = lastWriteTime.time_since_epoch();
    auto secondsSinceEpoch = chrono::duration_cast<chrono::seconds>(timeSinceEpoch).count();

    // Преобразуем в локальное время
    time_t rawTime = static_cast<time_t>(secondsSinceEpoch);

    // Создаем копию структуры tm для потокобезопасности
    tm localTimeStruct;
    if (const tm* localTime = std::localtime(&rawTime)) {
        localTimeStruct = *localTime; // Копируем данные
    } else {
        cerr << "Ошибка преобразования времени" << endl;
        return "";
    }

    // Форматируем дату и время
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTimeStruct);
    result += "Date: " + string(buffer) + "\n";

    result += string("Type: ") + (filesystem::is_regular_file(filePath) ? "File" : "Directory") + "\n";
    return result;
}