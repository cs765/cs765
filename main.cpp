#include <iostream>
#include <cmath>

double future_value(double F0, double t0, double t1, double r) {
    double r_decimal = 0.01 * r;
    double F1 = F0 * exp(r_decimal * (t1 - t0));
    return F1;
}

int main() {
    double initial_value = 100.0;
    double initial_time = 0.0;
    double future_time = 5.0;
    double continuously_compounded_interest_rate = 10.0;
    std::cout
            << "We calculate the future value of $"
            << initial_value
            << ", "
            << future_time
            << " years from today at a continuously compounded interest rate of "
            << continuously_compounded_interest_rate
            << "%." << std::endl;
    std::cout << "The expected future value is: "
              << "$" << future_value(initial_value, initial_time, future_time, continuously_compounded_interest_rate)
              << std::endl;
    return 0;
}