#include <cmath>
#include <iostream>

double get_bond_price(double face, double yield, double coupon, double number_of_coupons) {
    double running_total = 0;
    for (int counter = 1; counter <= number_of_coupons; counter++) {
        running_total += 0.5 * coupon / pow(1 + 0.5 * yield, counter);
    }
    running_total += (face / pow(1 + 0.5 * yield, number_of_coupons));
    return running_total;
}

int main() {
    int yields[5] = {0, 2, 4, 6, 8};
    for (int yield : yields) {
        std::cout << get_bond_price(100, yield / 100, 4, 4) << std::endl;
    }
    return 0;
}