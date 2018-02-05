#include <iostream>
#include <cmath>
#include <cassert>

//double future_value(double F0, double t0, double t1, double r) {
//    double r_decimal = 0.01 * r;
//    double F1 = F0 * exp(r_decimal * (t1 - t0));
//    return F1;
//}

// F0 is today's cash flow
// F1 is future cash flow
// t0 is today's time
// t1 is future time
// df is discount factor
// r is continuously compounded interest rate
int df_and_r(double F0, double F1, double t0, double t1, double &df, double &r) {
    if (t1 == t0) {
        df = 0;
        r = 0;
        return -1;
    }
    if (F0 <= 0 || F1 <= 0) {
        df = 0;
        r = 0;
        return -2;
    }
    df = F0 / F1;
    r = (-log(df) / (t1 - t0)) * 100;
    return 0;
}

int main() {
    double today_cash_flow = 100.0;
    double future_cash_flow = 110.517;
    double today_time = 0.0;
    double future_time = 1.0;
    double df;
    double r;
    int result = df_and_r(today_cash_flow, future_cash_flow, today_time, future_time, df, r);
    assert(result == 0);
    std::cout << df << " " << r << std::endl;
    return 0;
}