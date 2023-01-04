#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char code[2];
    double real;
    double img;
} Complex;

double rad_to_deg(double x);

double deg_to_rad(double x);

void str_to_double_a(Complex * cp, const char ** argv);

void str_to_double_p(Complex * cp, const char ** argv);

void str_to_double_v(Complex * cp, const char ** argv);

#endif // __COMPLEX_H__