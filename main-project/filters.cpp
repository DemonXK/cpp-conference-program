#include "filters.h"

std::vector<ConferenceEntry> filterByAuthor(const std::vector<ConferenceEntry>& entries) {
    std::vector<ConferenceEntry> result;
    for (const auto& e : entries) {
        if (e.lastName == "������" && e.firstName == "����" && e.middleName == "��������") {
            result.push_back(e);
        }
    }
    return result;
}

std::vector<ConferenceEntry> filterByDurationOver15(const std::vector<ConferenceEntry>& entries) {
    std::vector<ConferenceEntry> result;
    for (const auto& e : entries) {
        if (e.getDuration() > 15) {
            result.push_back(e);
        }
    }
    return result;
}
