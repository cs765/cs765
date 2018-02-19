#include <cmath>
#include <cassert>

bool are_same(double a, double b) {
    double EPSILON = pow(1.0, -4);
    return fabs(a - b) < EPSILON;
}

double get_bond_price(double face, double yield, double coupon1, double coupon2, double coupon3, double coupon4,
                      double coupon5, double coupon6, double coupon7, double coupon8, double coupon9, double coupon10) {
    double running_total = 0.0;
    running_total += (0.5 * coupon1) / (1 + 0.5 * yield);
    running_total += (0.5 * coupon2) / pow(1 + 0.5 * yield, 2);
    running_total += (0.5 * coupon3) / pow(1 + 0.5 * yield, 3);
    running_total += (0.5 * coupon4) / pow(1 + 0.5 * yield, 4);
    running_total += (0.5 * coupon5) / pow(1 + 0.5 * yield, 5);
    running_total += (0.5 * coupon6) / pow(1 + 0.5 * yield, 6);
    running_total += (0.5 * coupon7) / pow(1 + 0.5 * yield, 7);
    running_total += (0.5 * coupon8) / pow(1 + 0.5 * yield, 8);
    running_total += (0.5 * coupon9) / pow(1 + 0.5 * yield, 9);
    running_total += (face + 0.5 * coupon10) / pow(1 + 0.5 * yield, 10);
    return running_total;
}

double get_bond_price_from_yield(double F, double c, double y, int n) {
    double B = 0.0;
    if ((F <= 0.0) || (c < 0.0) || (y < 0.0) || (n <= 0.0)) {
        return B;
    }
    double temp1 = 1.0 + (0.01 * y) / 2.0;
    double temp2 = temp1;
    for (int i = 1; i < n; ++i) {
        B = B + (0.5 * c) / temp2;
        temp2 = temp2 * temp1;
        if (i == n - 1) {
            B = B + (F + 0.5 * c) / temp2;
        }
    }
    return B;
}

int main() {
    int my_array[100];
    double yields[100];
    for (int i = 0; i < 100; ++i) {
        my_array[i] = i;
        yields[i] = (double) i;
    }
    for (double yield:yields) {
        assert(are_same(get_bond_price(101.2152, yield / 100.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0),
                        get_bond_price_from_yield(101.2152, 4.0, yield, 10)));
    }
    return 0;
}
