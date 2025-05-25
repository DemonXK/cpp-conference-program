#include "sort.h"
#include <algorithm>

int compareByDurationDesc(const ConferenceEntry* a, const ConferenceEntry* b) {
    return b->getDuration() - a->getDuration(); // убывание
}

int compareByAuthorThenTopic(const ConferenceEntry* a, const ConferenceEntry* b) {
    if (a->lastName != b->lastName)
        return a->lastName < b->lastName ? -1 : 1;
    return a->topic < b->topic ? -1 : (a->topic > b->topic ? 1 : 0);
}
void heapify(std::vector<ConferenceEntry*>& arr, int n, int i, CompareFunc cmp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(arr[l], arr[largest]) > 0)
        largest = l;
    if (r < n && cmp(arr[r], arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

void heapSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, cmp);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}
void merge(std::vector<ConferenceEntry*>& arr, int left, int mid, int right, CompareFunc cmp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<ConferenceEntry*> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<ConferenceEntry*> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j]) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(std::vector<ConferenceEntry*>& arr, int left, int right, CompareFunc cmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid, cmp);
        mergeSortRec(arr, mid + 1, right, cmp);
        merge(arr, left, mid, right, cmp);
    }
}

void mergeSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp) {
    mergeSortRec(arr, 0, arr.size() - 1, cmp);
}
