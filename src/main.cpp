#include <iostream>
#include <filesystem>
#include "../src/include/file_operations.h"
#include "../src/include/comparison.h"

using namespace std;

int main() {
    filesystem::path source = filesystem::current_path().parent_path();

    createControlFile(source);

    // Создаем временный файл temp.txt
    createTempFile(source);

    // Сравниваем control.txt и temp.txt
    if (!compareFiles(source / "control.txt", source / "temp.txt")) {
        cout << "В текущем каталоге произошли изменения!" << endl;

        // Выводим информацию о файлах, которые изменились
        showChanges(source / "control.txt", source / "temp.txt");
    }

    // Переписываем содержимое temp.txt в control.txt и удаляем temp.txt
    finalize(source);

    return 0;
}