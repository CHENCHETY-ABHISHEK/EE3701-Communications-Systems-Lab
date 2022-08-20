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
    // Reversing the sequence y
    double temp;
    for (int i = 0; i < y_size / 2; i++)
    {
        temp = y[i];
        y[i] = y[y_size - i - 1];
        y[y_size - i - 1] = temp;
    }

    // * Convolving the Reversed y and x to get correlation
    double product;

    int R_size = x_size + y_size;
    // * Running a loop for evaluating sequence R[n]
    for (int n = 0; n < R_size; n++)
    {
        // * initialising the product = 0, before evaluating the value of R[n]
        product = 0;

        // * Calculating the \sigma of x[k] \times y[n-k]
        for (int k = 0; k < x_size; k++)
        {
            if ((n - k) < y_size && (n - k) >= 0) // ? if n-k > h_size (memory unaccessable)
            {
                product += x[k] * y[n - k];
            }
        }
        //* updating value of R[n] by the \sigma obtained in prev loop
        R[n] = product;
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