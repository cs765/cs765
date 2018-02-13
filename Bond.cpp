//
// Created by kus on 2/12/18.
//

#include "Bond.h"

Bond::Bond(double T, double F, double c, int freq) {

}

Bond::~Bond() {

}

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
