#include <iostream>
#include <vector>
#include <assert.h>

class Bond {
public:
    Bond(double T, double F, double c = 0, int freq = 2) {
        Face = F;
        cpn_freq = freq;
        assert(cpn_freq >= 1);
        const double tol = 1.0e-6;
        num_coupons = int(cpn_freq * T + tol);
        T_maturity = num_coupons / cpn_freq;
        if (num_coupons > 0) {
            coupons.resize(num_coupons, c);
        }
    }

    ~Bond() {
        coupons.clear();
        num_coupons = 0;
    }

    // public methods
    int set_coupons(std::vector<double> &c);

    int FV_duration(double t0, double y, double &B, double &Macaulay_duration, double &modified_duration) const;

    int yield(double B_target, double tol, int max_iter, double t0, double &y, double &num_iter) const;

    double FairValue(double t0, double y) const;

    double maturity() const { return T_maturity; }

private:
    // data
    double Face;
    double T_maturity;
    int cpn_freq;
    int num_coupons;
    std::vector<double> coupons;
};

int main() {
    std::cout << "hello, world" << std::endl;
    return 0;
}
