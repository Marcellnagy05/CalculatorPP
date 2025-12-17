#pragma once

#include "basicmath_global.h"
#include "constants.h"

namespace BasicMath {
    class BasicCalculator
    {
    public:
        BasicCalculator();

        //Power and Sqrt
        double pow(double base, double exp);
        double sqrt(double base, double exp);

        //logarithm
        double log(double logBase, double exponent);
        double ln();
        double lg();
    private:
        double lastResult;
    };
}