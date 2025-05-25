#pragma once
#include <vector>
#include "conference_entry.h"

std::vector<ConferenceEntry> filterByAuthor(const std::vector<ConferenceEntry>& entries);
std::vector<ConferenceEntry> filterByDurationOver15(const std::vector<ConferenceEntry>& entries);

