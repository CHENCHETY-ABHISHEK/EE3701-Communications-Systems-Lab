#include "common_functions.h"
#include <stdlib.h>
#include <stdio.h>
void Convolution(double *x, double *h, double *y, int x_size, int h_size, int y_size)
{
    // * declaring a variable to store the product
    double product;

    // * Running a loop for evaluating sequence y[n]
    for (int n = 0; n < y_size; n++)
    {
        // * initialising the product = 0, before evaluating the value of y[n]
        product = 0;

        // * Calculating the \sigma of x[k] \times h[n-k]
        for (int k = 0; k < x_size; k++)
        {
            if ((n - k) < h_size) // ? if n-k > h_size (memory unaccessable)
            {
                product += x[k] * h[n - k];
            }
        }
        //* updating value of y[n] by the \sigma obtained in prev loop
        y[n] = product;
    }
}
void Correlation(double *x, double *y, double *R, int x_size, int y_size)
{
    // * declaring a variable to store the product
    double product;

    // * Running a loop for evaluating sequence R_xy[n]
    for (int k = 0; k < x_size; k++)
    {
        // * initialising the product = 0, before evaluating the value of R_xy[k]
        R[k] = 0;

        for (int n = 0; n < x_size; n++)
        {
            if ((n - k) < y_size)
            {
                //* updating \sigma of R_xy[k] by the value obtained
                R[k] += x[n] * y[n - k];
            }
        }
    }
}
void Downsample(double *x, double *y, int y_size, int factor)
{
    for (int i = 0; i < y_size; i++)
    {
        y[i] = x[factor * i];
    }
}
void Upsample(double *x, double *y, int y_size, int factor)
{
    for (int i = 0; i < y_size; i++)
    {
        if (i % factor == 0)
        {
            y[i] = x[i / factor];
        }
        else
        {
            y[i] = 0;
        }
    }
}