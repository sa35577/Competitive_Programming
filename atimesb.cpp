#include <bits/stdc++.h>
using namespace std;
/*
PROCESS OF FFT
Write X and Y as base 10 expansions
Compute the Fourier Transform X* of size 2n of the sequence of coeff of x (xj):
    X* = (x0*,x1*,...,x(2n-1)*), congruent to F2n(x0,x1,...,xn-1,0,...,0)
Same for the coefficients of Y (yj):
    Y* = (y0*,y1*,...,y(2n-1)*), congruent to F2n(y0,y1,...,yn-1,0,...,0)
Compute the product term by term of X* by Y* in X*
    Z* = (z0*,z1*,...,z(2n-1)*), where zi* is congruent to xi*,yi*
Compute the inverse Fourier transform Z of Z* (with the conjugate FFT process)
    Z = (z0,z1,...,z(2n-1)), congruent to (1/2n)*conguate(F_2n (Z*))
Then after regarrangement of the coefficents z_i,the number
    Z is in base representation form, in which the digits are combined.
*/