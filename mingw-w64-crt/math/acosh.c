/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <errno.h>
#include "fastmath.h"

/* acosh(x) = log (x + sqrt(x * x - 1)) */
double acosh (double x)
{
  if (isnan (x)) 
    return x;

  if (x < 1.0)
    {
      errno = EDOM;
      return nan("");
    }

  if (x > 0x1p32)
    /*  Avoid overflow (and unnecessary calculation when
        sqrt (x * x - 1) == x). GCC optimizes by replacing
        the long double M_LN2 const with a fldln2 insn.  */ 
    return __fast_log (x) + 6.9314718055994530941723E-1L;

  /* Since  x >= 1, the arg to log will always be greater than
     the fyl2xp1 limit (approx 0.29) so just use logl. */ 
  return __fast_log (x + __fast_sqrt((x + 1.0) * (x - 1.0)));
}
