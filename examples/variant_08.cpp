#include <iostream>
#include "arraylib.h"
#include <vector>
#include <iomanip>

int main() {
    std::vector<int> brightness = {
        18, 45, 73, 99, 128, 156, 180, 203, 227, 255,
        30, 60, 85, 110, 140, 170, 210, 240, 50, 90
    };

    const int* arr = brightness.data();
    std::size_t n = brightness.size();

    int min_val = arr_min(arr, n);
    int max_val = arr_max(arr, n);
    double avg_val = arr_average(arr, n);
    double med_val = arr_median(arr, n);

    int threshold = 80;
    size_t dark_count = count_if_less(arr, n, threshold);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Минимальная яркость: " << min_val << "\n";
    std::cout << "Максимальная яркость: " << max_val << "\n";
    std::cout << "Средняя яркость: " << avg_val << "\n";
    std::cout << "Медиана яркости: " << med_val << "\n";
    std::cout << "Количество тёмных пикселей (яркость < " << threshold << "): " << dark_count << "\n";

    return 0;
}
