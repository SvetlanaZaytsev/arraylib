#include "arraylib.h"
#include <algorithm>
#include <vector>

int arr_sum(const int* arr, std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i)
        s += arr[i];
    return s;
}

int arr_max(const int* arr, std::size_t n) {
    if (n == 0) return 0; // защита от пустого массива
    int m = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int arr_min(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int m = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

double arr_average(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    long long sum = 0;
    for (std::size_t i = 0; i < n; ++i)
        sum += arr[i];
    return static_cast<double>(sum) / static_cast<double>(n);
}

int arr_count_positive(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > 0) ++c;
    return c;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] < 0) ++c;
    return c;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] == 0) ++c;
    return c;
}

long long arr_product(const int* arr, std::size_t n) {
    if (n == 0) return 1;
    long long p = 1;
    for (std::size_t i = 0; i < n; ++i)
        p *= arr[i];
    return static_cast<int>(p);
}

double arr_median(int* arr, std::size_t n) {
    if (n == 0) return 0.0;

    // Копируем массив, чтобы не менять исходный
    int* temp = new int[n];
    for (std::size_t i = 0; i < n; ++i) {
        temp[i] = arr[i];
    }

    // Сортируем копию
    std::sort(temp, temp + n);

    double result;
    if (n % 2 == 1) {
        // Нечётное количество — берём центральный элемент
        result = static_cast<double>(temp[n / 2]);
    } else {
        // Чётное — среднее двух центральных
        result = (static_cast<double>(temp[n / 2 - 1]) + static_cast<double>(temp[n / 2])) / 2.0;
    }

    delete[] temp;
    return result;
}


size_t count_if_less(const int* arr, std::size_t n, int threshold) {
    size_t cnt = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < static_cast<int>(threshold)) {
            ++cnt;
        }
    }
    return cnt;
}
