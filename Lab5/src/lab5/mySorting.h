#ifndef MYSORTING_H
#define MYSORTING_H

#include "mylist.h"

template <class T>
void mySort(T& array)
{
    int len = std::size(array);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (array[j] > array[j + 1]) {
               std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template <typename T>
void mySort(MyList<T>& array)
{
    int len = array.size();
    if (len == 0 or len == 1) return;

    for (int i = 0; i < len; i++) {
        auto next = array.begin();
        next++;
        for (auto iter = array.begin(); next != array.end(); ++iter) {
            if (*iter > *next) {
                std::swap(*iter, *next);
            }
            next++;
        }
    }
}

template <int p, int q>
void mySort(char(&array)[p][q])
{
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p - 1; j++) {
            char str1[q], str2[q];
            snprintf(str1, p + 1, "%s", array[j]);
            snprintf(str2, p + 1, "%s", array[j + 1]);
            for (int i = 0; i < q + 1; i++) {
                str1[i] = ::toupper(str1[i]);
                str2[i] = ::toupper(str2[i]);
            }
            if (strcmp(str1, str2) > 0) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

#endif // MYSORTING_H
