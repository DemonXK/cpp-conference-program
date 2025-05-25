#pragma once
#include <vector>
#include "conference_entry.h"

using CompareFunc = int (*)(const ConferenceEntry*, const ConferenceEntry*);

// ����������
void heapSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp);
void mergeSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp);

// �����������
int compareByDurationDesc(const ConferenceEntry* a, const ConferenceEntry* b);
int compareByAuthorThenTopic(const ConferenceEntry* a, const ConferenceEntry* b);
