//
// Created by kus on 2/12/18.
//

#include <cassert>
#include "Bond.h"

Bond::Bond(double T, double F, double c, int freq) {
    Face = F;
    assert(Face >= 0);
    cpn_freq = freq;
    assert(cpn_freq >= 1);
    num_coupons = int(cpn_freq * T + tol);
    assert(num_coupons >= 0);
    T_maturity = num_coupons / cpn_freq;
    if (num_coupons > 0) {
        coupons.resize(num_coupons, c);
    }
}

Bond::~Bond() = default;

int Bond::yield(double B_target, double tol, int max_iter, double t0, double &y, int &num_iter) const {
    return 0;
}

int Bond::FV_duration(double t0, double y, double &B, double &Macaulay_duration, double &modified_duration) const {
    return 0;
}

double Bond::FairValue(double t0, double y) const {
    return 0;
}

double Bond::maturity() const {
    return T_maturity;
}
