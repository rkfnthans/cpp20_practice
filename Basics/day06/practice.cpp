#include <iostream>
#include <cmath>
#include <cassert>

double meter2yard(double meter)
{
    return meter/0.9144;
}

double yard2meter(double yard)
{
    return yard*0.9144;
}
int main()
{
    const double epsilon{1e-12};

    assert(std::abs(meter2yard(0.9144)-1.0)<epsilon);

    assert(std::abs(yard2meter(1.0)-0.9144)<epsilon);

    assert(std::abs(meter2yard(yard2meter(10.0))-10.0)<epsilon);

    return 0;
}
