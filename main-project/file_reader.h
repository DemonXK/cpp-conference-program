#pragma once
#include <vector>
#include <string>
#include "conference_entry.h"

std::vector<ConferenceEntry> readDataFromFile(const std::string& filename);
