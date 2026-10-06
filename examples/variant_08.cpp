#include "arraylib.h"
#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    int brightness[] = {
        34, 128, 255, 76, 192,
        18, 144, 220, 96, 61,
        173, 245
    };

    const std::size_t n = sizeof(brightness) / sizeof(brightness[0]);

    std::cout << "Количество элементов: " << n << '\n';

    std::cout << "Исходные данные: ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << brightness[i] << " ";
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Минимальная яркость: " << arr_min(brightness, n) << '\n';
    std::cout << "Максимальная яркость: " << arr_max(brightness, n) << '\n';
    std::cout << "Средняя яркость: " << arr_average(brightness, n) << '\n';
    std::cout << "Медиана яркости: " << arr_median(brightness, n) << '\n';
    std::cout << "Тёмных пикселей (< 80): " << count_if_less(brightness, n, 80) << '\n';

    return 0;
}
