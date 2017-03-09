#include "reciprocal.hpp"
#include "cassert"

double reciprocal(int i)
{
    assert( i != 0);
    return 1.0 / i;
}
