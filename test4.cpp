#include "test.hpp"


#include <iostream>

using namespace std;

#include <iostream>
#include <limits>

using namespace std;
class MyPID {
public:
    MyPID() {}

    void Init(double init_v, double goal_v, double p, double i, double d) {
        initval = init_v;
        goal    = goal_v;
        p_coe   = p;
        i_coe   = i;
        d_coe   = d;
        err     = goal - initval;
    }

    void UpdateErr(double cte) {
        if (step == 1) {
            p_err = cte;
        }
        i_err += cte;
        d_err = cte - p_err;
        p_err = cte;

        ++step;
    }

    double TotalErr() { return p_coe * p_err + i_coe * i_err + d_coe * d_err; }
    ~MyPID() {}

public:
    double initval = 1;
    double goal    = 1;
    double err     = 0;
    int step       = 1;
    double p_coe = 1, i_coe = 1, d_coe = 1;
    double p_err = 0, i_err = 0, d_err = 0;
};
int main() {
    MyPID Pid;
    double ini = 7, goal = 8, p = 0.3345, i = 0.0011011, d = 0.662;

    Pid.Init(ini, goal, p, i, d);

    for (int i = 0; i < 20; ++i) {
        double cte = goal - ini;
        Pid.UpdateErr(cte);
        cte = Pid.TotalErr();
        ini += cte;
        cout << cte << endl;
    }
}