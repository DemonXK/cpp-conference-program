#pragma once
#include <string>

struct ConferenceEntry {
    int startHour, startMinute;
    int endHour, endMinute;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string topic;

    int getDuration() const {
        return (endHour * 60 + endMinute) - (startHour * 60 + startMinute);
    }
};

