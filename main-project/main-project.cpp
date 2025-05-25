
#include <iostream>
#include <vector>
#include "conference_entry.h"
#include "file_reader.h"
#include "filters.h"


void printEntry(const ConferenceEntry& entry) {
    printf("%02d:%02d - %02d:%02d | %s %s %s | %s\n",
        entry.startHour, entry.startMinute,
        entry.endHour, entry.endMinute,
        entry.lastName.c_str(),
        entry.firstName.c_str(),
        entry.middleName.c_str(),
        entry.topic.c_str());
}

void showAll(const std::vector<ConferenceEntry>& data) {
    for (const auto& entry : data) {
        printEntry(entry);
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<ConferenceEntry> data = readDataFromFile("data.txt");

    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Показать все доклады\n";
        std::cout << "2. Фильтрация (Иванов Иван Иванович)\n";
        std::cout << "3. Фильтрация (доклады > 15 минут)\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showAll(data);
            break;
        case 2: {
            auto filtered = filterByAuthor(data);
            showAll(filtered);
            break;
        }
        case 3: {
            auto filtered = filterByDurationOver15(data);
            showAll(filtered);
            break;
        }

        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный ввод\n";
        }
    } while (choice != 0);

    return 0;
}
