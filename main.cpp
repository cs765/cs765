#include <cmath>
#include <iostream>

double get_bond_price(double face, double yield, double coupon1, double coupon2, double coupon3, double coupon4) {
    double running_total = 0.0;
    // one
    running_total += (0.5 * coupon1) / (1 + 0.5 * yield);
    std::cout << running_total << std::endl;
    running_total += (0.5 * coupon2) / pow(1 + 0.5 * yield, 2);
    std::cout << running_total << std::endl;
    running_total += (0.5 * coupon3) / pow(1 + 0.5 * yield, 3);
    std::cout << running_total << std::endl;
    running_total += (face + 0.5 * coupon4) / pow(1 + 0.5 * yield, 4);
    std::cout << running_total << std::endl;

    return running_total;
}

int main() {
    std::cout << get_bond_price(100.0, 8.0 / 100.0, 4.0, 4.0, 4.0, 4.0) << std::endl;
    return 0;
}