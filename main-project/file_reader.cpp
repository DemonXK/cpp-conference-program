#include "file_reader.h"
#include <fstream>
#include <sstream>

std::vector<ConferenceEntry> readDataFromFile(const std::string& filename) {
    std::vector<ConferenceEntry> entries;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        ConferenceEntry entry;

        std::string start, end;
        iss >> start >> end >> entry.lastName >> entry.firstName >> entry.middleName;
        std::getline(iss >> std::ws, entry.topic); // ќстаток строки Ч тема

        sscanf_s(start.c_str(), "%d:%d", &entry.startHour, &entry.startMinute);
        sscanf_s(end.c_str(), "%d:%d", &entry.endHour, &entry.endMinute);

        entries.push_back(entry);
    }

    return entries;
}
