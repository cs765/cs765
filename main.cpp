#include "Bond.cpp"

int main() {
    double face = 100.0;
    double time = 4.0;
    double coupons = 4.0;
    int frequency = 2;
    Bond bond = Bond(time, face, coupons, frequency);
    return 0;
}
