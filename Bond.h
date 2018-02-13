//
// Created by kus on 2/12/18.
//

#ifndef INC_765_BOND_H
#define INC_765_BOND_H


#include <vector>

class Bond {
private:
    double Face;
    double T_maturity;
    int cpn_freq;
    int num_coupons;
    std::vector<double> coupons;

public:
    Bond(double T, double F, double c = 0, int freq = 2);

    ~Bond();

    int FV_duration(double t0, double y, double &B, double &Macaulay_duration, double &modified_duration) const;

    int yield(double B_target, double tol, int max_iter, double t0, double &y, int &num_iter) const;

    double FairValue(double t0, double y) const;

    double maturity() const;

    const double tol = 1.0e-6;
};


#endif //INC_765_BOND_H
