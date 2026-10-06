#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <cstddef>

#if defined(_WIN32)
    #ifdef ARRAYLIB_BUILD
        #define ARRAYLIB_API __declspec(dllexport)
    #else
        #define ARRAYLIB_API __declspec(dllimport)
    #endif
#else
    #define ARRAYLIB_API
#endif

// --- Объявления функций ---
ARRAYLIB_API size_t count_if_less(const int* arr, std::size_t n, int threshold);
ARRAYLIB_API int arr_sum(const int* arr, std::size_t n);
ARRAYLIB_API int arr_max(const int* arr, std::size_t n);
ARRAYLIB_API int arr_min(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_positive(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_negative(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_zero(const int* arr, std::size_t n);
ARRAYLIB_API long long arr_product(const int* arr, std::size_t n); // long long, чтобы реже было переполнение
ARRAYLIB_API double arr_average(const int* arr, std::size_t n);
ARRAYLIB_API double arr_median(int* arr, std::size_t n);          // median может менять порядок, поэтому не const

#endif // ARRAYLIB_H
