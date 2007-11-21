/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   casinhl.c
   Contributed by Danny Smith
   2005-01-04
*/

#include <math.h>
#include <complex.h>

/* casinh (z) = -I casin (I * z) */

long double complex casinhl (long double complex Z)
{
  long double complex Tmp;
  long double complex Res;

  __real__ Tmp = - __imag__ Z;
  __imag__ Tmp =   __real__ Z;
  Tmp = casinl (Tmp);
  __real__ Res =   __imag__ Tmp;
  __imag__ Res = - __real__ Tmp;
  return Res;
}
