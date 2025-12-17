#pragma once

#include "simplemath_global.h"

namespace SimpleMath {
    class Calculator
    {
    public:
        Calculator();

        //1. Base arithmetics
        double add(double a, double b);
        double sub(double a, double b);
        double mult(double a, double b);
        double div(double a, double b);

        //3 Specials
        double percentage(double base, double percentage);
        double changeSign(double value);

        //4. State Check
        double getLastResult() const;
        void reset();
    private:
        double lastResult;
        void updateLastResult(double result);
    };
} // namespace SimpleMath